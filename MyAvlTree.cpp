#include <algorithm>
#include <initializer_list>
#include <iomanip>
#include <vector>
#include <iostream>
template <class T> class TreeNode {
public:
    explicit TreeNode(T value) : val(value){};
    TreeNode() = default;
    TreeNode(TreeNode &&) = default;
    TreeNode(const TreeNode &) = default;
    TreeNode &operator=(TreeNode &&) = default;
    TreeNode &operator=(const TreeNode &) = default;
    ~TreeNode() = default;

public:
    T val{};
    int height = 0;
    TreeNode<T> *left{};
    TreeNode<T> *right{};

private:
};

template <class T> class AVlTree {
public:
    AVlTree() = default;
    /**
     * @brief Construct a new AVlTree object
     * 
     * @param list 
     */
    AVlTree(std::initializer_list<T> list) {
        for (auto &val : list) {
            insert(val);
        }
    }   
    AVlTree(AVlTree &&) = default;
    AVlTree(const AVlTree &) = default;
    AVlTree &operator=(AVlTree &&) = default;
    AVlTree &operator=(const AVlTree &) = default;
    ~AVlTree() {
        if (root != nullptr) {
            delete root;
        }
    }

private:
    TreeNode<T> *root{nullptr};

public:
    void insert(const T &val) { root = _insert(root, val); }

    void remove(const T &val) { root = _remove(root, val); }

    void inOrder(TreeNode<T> *node, std::vector<T> &result) {

        if (node == nullptr) {
            return;
        }
        inOrder(node->left, result);
        result.push_back(node->val);
        inOrder(node->right, result);
    }

    TreeNode<T> *getRoot() { return root; }

    
private:
    int height(TreeNode<T> *node) {
        return node != nullptr ? node->height : -1; // 空节点高度为0,叶节点为-1
    }

    void updateHeight(TreeNode<T> *node) {
        node->height = std::max(height(node->left), height(node->right)) + 1;
    }

    int getBalanceFactor(TreeNode<T> *node) {

        // 空节点为0
        if (node == nullptr) {
            return 0;
        }
        // 平衡因子为左节点高度减右节点高度
        return height(node->left) - height(node->right);
    }

    TreeNode<T> *rotatedRight(TreeNode<T> *node) {
        // node 为失衡节点，且为LL形，则以左子节点为转轴，向右旋转
        TreeNode<T> *pivot = node->left;
        // 要被转移到右侧的节点，也就是转轴的右节点
        TreeNode<T> *transfer = pivot->right;

        pivot->right = node;   // 右旋
        node->left = transfer; // 转移

        // 更新高度
        updateHeight(node);
        updateHeight(pivot);

        // 此时转轴成为新的根节点。
        return pivot;
    }

    TreeNode<T> *rotatedLeft(TreeNode<T> *node) {
        // node 为失衡节点，且为RR形，则以右子节点为转轴，向左旋转
        TreeNode<T> *pivot = node->right;
        // 要被转移到左侧的节点，也就是转轴的左节点
        TreeNode<T> *transfer = pivot->left;

        pivot->left = node;     // 左旋
        node->right = transfer; // 转移

        // 更新高度
        updateHeight(node);
        updateHeight(pivot);

        // 此时转轴成为新的根节点。
        return pivot;
    }

    TreeNode<T> *rotate(TreeNode<T> *node) {
        int balanceFactor = getBalanceFactor(node);

        // 这里对LL,LR,RL,RR情况选择对于的旋转方式，取决于平衡因子
        // 左偏树
        if (balanceFactor > 1) {
            if (getBalanceFactor(node->left) >= 0) {
                // LL,右旋
                return rotatedRight(node);
            } else {
                // LR情况，先对子树进行左旋转化为LL，
                node->left = rotatedLeft(node->left);
                // 然后对节点右旋即可
                return rotatedRight(node);
            }
        }

        // 右偏树
        if (balanceFactor < -1) {
            if (getBalanceFactor(node->right) <= 0) {
                // RR,左旋。
                return rotatedLeft(node);
            } else {
                // RL情况，先对子树进行右旋转化为RR
                node->right = rotatedRight(node->right);
                // 然后对节点左旋即可
                return rotatedLeft(node);
            }
        }

        // 平衡树,不需要旋转
        return node;
    }

    TreeNode<T> *_insert(TreeNode<T> *node, const T &val) {

        // 判空
        if (node == nullptr) {
            return new TreeNode<T>(val);
        }

        if (val < node->val) {
            node->left = _insert(node->left, val);
        } else if (val > node->val) {
            node->right = _insert(node->right, val);
        } else {
            // std::cerr << "The value "<< val <<" is already in the tree." << std::endl;
            return node; // 这里我们不允许重复值。
        }

        updateHeight(node);  // 更新高度
        node = rotate(node); // 旋转使符合平衡

        return node;
    }

    TreeNode<T> *_remove(TreeNode<T> *node, const T &val) {

        if (node == nullptr) {
            return nullptr;
        }

        if (val < node->val) {
            node->left = _remove(node->left, val);
        } else if (val > node->val) {
            node->right = _remove(node->right, val);

        } else {
            // 找到这个节点了,根据子节点数量确定删除方式
            if (node->left == nullptr || node->right == nullptr) {
                TreeNode<T> *child = node->left ? node->left : node->right;
                if (child == nullptr) {
                    // 子节点数量为0,即叶节点，直接删除
                    delete node;
                    return nullptr;
                } 
                    delete node;
                    node = child; // 子节点数量为1，用子节点替代

                
            } else {
                TreeNode<T> *successor = node->right;
                while (successor->left != nullptr) {
                    successor =
                        successor
                            ->left; // 寻找需被删除节点的中序遍历后继节点，由二叉搜索树的性质，也就是右子树最小值。
                }
                T tempVal = successor->val; // 保存这个值。

                // 使用其中序遍历的后继节点来替代被删除的节点
                node->right = _remove(node->right, successor->val);
                node->val = tempVal;
            }
        }

        updateHeight(node); // 更新高度

        node = rotate(node); // 旋转
        return node;
    }
};
