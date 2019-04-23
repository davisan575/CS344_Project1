#include <iostream>
#include <vector>
#include <string>

template <class T>
struct map_element {
    int k;
    T e;
};

template <class T>
class HashTable
{
    public:
        
        HashTable() : size_(0), m_(1), hash_table_ (1) {}
        
        bool empty() { return (size_ == 0) ? true: false; }
        
        int size() { return size_; }
        
        T * find(int key);
        
        bool insert(int key, T element);
        
        int m_;
        
    private:
        std::vector<std::vector<map_element<T>>> hash_table_ ;
        int size_; //n
        //int m_;
        
        void rehash();
     
};

template <class T>
T * HashTable<T>::find(int key) {
    int index = key % m_;
    for (int i = 0; i < hash_table_[index].size(); ++i) {
        if (hash_table_[index][i].k == key) {
            return &hash_table_[index][i].e;
        }
    }
    return nullptr;
}

template <class T>
bool HashTable<T>::insert(int key, T element) {
    if (find(key) != nullptr) {
        return false;
    } else {
        map_element<T> new_e = { key, element };
        int index = key % m_;
        hash_table_[index].push_back(new_e);
        size_++;
        rehash();
        return true;
    }
}

template <class T>
void HashTable<T>::rehash() {
    if (m_ <= size_) {
        int new_m = 2*m_+1;
        std::vector<std::vector<map_element<T>>> new_hash(new_m);
        for ( int i = 0; i < m_; ++i ) {
            for ( int j = 0; j < hash_table_[i].size(); ++j ) {
                int index = hash_table_[i][j].k % new_m;
                new_hash[index].push_back(hash_table_[i][j]);
            }
        }
        m_ = new_m;
        hash_table_ = new_hash;
    }
}


int main()
{
    HashTable<std::string> hashtest;
    std::cout << hashtest.empty() << std::endl;
    std::cout << hashtest.size() << std::endl;
    
    if (hashtest.find(5) == nullptr) {
        std::cout << "Nullptr returned" << std::endl;
    }
    
    std::string s = "the";
    bool insert_test = hashtest.insert(5, s);
    std::cout << "Insert test: " << insert_test << std::endl;
    
    if (hashtest.find(5) == nullptr) {
        std::cout << "Nullptr returned" << std::endl;
    } else {
        std::cout << "At key 5: " << *hashtest.find(5) << std::endl;
    }
    
    std::cout << "Hash table size: " << hashtest.size() << " Hash table m_: " << hashtest.m_ << std::endl;
    
    s = "tree";
    insert_test = hashtest.insert(8, s);
    std::cout << "Insert test -tree- : " << insert_test << std::endl;
    
    s = "is";
    insert_test = hashtest.insert(1, s);
    std::cout << "Insert test -is- : " << insert_test << std::endl;
    
    s = "big";
    insert_test = hashtest.insert(3, s);
    std::cout << "Insert test -big- : " << insert_test << std::endl;
    
    s = "repeated";
    insert_test = hashtest.insert(5, s);
    std::cout << "Insert test repeated element: " << insert_test << std::endl;
    
    std::cout << "Hash table size: " << hashtest.size() << " Hash table m_: " << hashtest.m_ << std::endl;

        
    return 0;
}