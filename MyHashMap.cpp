#include <string>
#include <vector>
#include <sstream>
struct Pair
{
    int key;
    std::string val;
    Pair(int key, std::string val): key(key), val(val) {}
};

namespace MyHashMap
{
    class ArrayHashMap
    {
    private:
        std::vector<Pair *> buckets;
    public:
        ArrayHashMap() :buckets(std::vector<Pair*>(100)) {};
        ~ArrayHashMap()
        {
            for(const auto &bucket : buckets)
            {
                delete bucket;
            }
            buckets.clear();
        }

        int hashFunc(int key) 
        {
            int index = key % 11451;
            return index;
            
        }

        const std::string getVal(int key) 
        {
            int index = this->hashFunc(key);
            Pair *pair = this->buckets[index];
            if (pair == nullptr)
            {
                return "";
            }
            return pair->val;
            
        }

        void put(int key, std::string val)
        {
            Pair *pair = new Pair(key, val);
            int index = hashFunc(key);
            this->buckets[index] = pair;
        }

        void remove(int key)
        {
            int index = hashFunc(key);
            delete buckets[index];
            buckets[index] = nullptr;
        }

        /**
         * 获取所有键值对
         */
        std::vector<Pair *> getPairSet()
        {
            std::vector<Pair *> pairSet;
            for(auto pair : this->buckets)
            {
                if (pair != nullptr)
                {
                    pairSet.push_back(pair);
                }
                   
            }

            return pairSet;
        }

        /**
         * 获取所有键
         */
        std::vector<int> getKeySet()
        {
            std::vector<int> keySet;
            for(auto pair : this->buckets)
            {
                if (pair != nullptr)
                {
                    keySet.push_back(pair->key);
                }
                
            }
            return keySet;
        }

        std::vector<std::string> getValSet()
        {
            std::vector<std::string> valSet;
            for(auto pair : this->buckets)
            {
                if (pair != nullptr)
                {
                    valSet.push_back(pair->val);
                }
                
            }
            return valSet;
        }
            
        operator std::string() 
        {
            std::stringstream hashStr;
            for(auto kv : this->getPairSet())
            {
                hashStr << kv->key << "->" << kv->val;
            }

            return hashStr.str();
        }

        

    };
    
    
    
        



} // namespace MyHashMap
