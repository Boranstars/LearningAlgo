#include <vector>
#include <string>
#include <climits>
namespace MyBinaryTree
{   
    using std::vector;
    using std::string, std::string_view;
    struct TreeNode
    {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(nullptr), right(nullptr){};
    };

    class ArrayBinaryTree
    {
    private:
        vector<int> tree;

        void dfs(int i, string_view order, vector<int> &res)
        {
            if (this->val(i) == INT_MAX)
            {
                return;
            }
            if (order == "pre")
            {
                res.push_back(this->val(i));
            }

            dfs(this->left(i), order, res);
            if (order == "in")
            {
                res.push_back(this->val(i));
            }
            dfs(this->right(i), order, res);
            if (order == "post")
            {
                res.push_back(this->val(i));
            }
        }

    public:
        ArrayBinaryTree(vector<int> arr) : tree(arr){};
        ~ArrayBinaryTree(){};

        int size()
        {
            return this->tree.size();
        }

        int val(int i)
        {
            if (i < 0 || i >= this->size())
            {
                return INT_MAX;
            }
            return this->tree[i];
        }

        int left(int i)
        {
            return 2 * i + 1;
        }

        int right(int i)
        {
            return 2 * i + 2;
        }

        int parent(int i)
        {
            return (i - 1) / 2;
        }
        
        vector<int> preOrder()
        {
            vector<int> res;
            dfs(0, "pre", res);
            return res;
        }

        vector<int> inOrder()
        {
            vector<int> res;
            dfs(0, "in", res);
            return res;
        }

        vector<int> postOrder()
        {
            vector<int> res;
            dfs(0, "post", res);
            return res;

        }
    };
} // namespace MyBinaryTree
