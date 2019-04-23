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
    
    bool erase(int key);
    
    T * find(int key);
    
    bool insert(int key, T element);
    
    void print_all();
    
    void clear();
    
private:
    std::vector<std::vector<map_element<T>>> hash_table_ ;
    int size_; // n
    int m_;
    
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

template <class T>
bool HashTable<T>::erase(int key) {
    
    // if element is found- copy the chain to new chain w/o element
    int index = key % m_;
        if (hash_table_[index].size() > 0) {
        std::vector<map_element<T>> new_vector(hash_table_[index].size()-1);
        
        int j = 0;
        int i = 0;
        for (i = 0; i < hash_table_[index].size(); ++i) {
            if ((hash_table_[index][i].k) != key) {
                new_vector[j] = hash_table_[index][i];
                j++;
            }
        }
        
        if (i != j) { // if an erase occured
            hash_table_[index] = new_vector;
            size_--;
            return true;
        }
    }
    
    return false;
    
    
    /*
    int index = key % m_;
    for (int i = 0; i < hash_table_[index].size(); ++i) {
        if (hash_table_[index][i].k == key) {
            hash_table_[index].erase(i);
            return true;
        }
    }
    */
    return false;
}

template <class T>
void HashTable<T>::print_all() {
    for (int i = 0; i < m_; ++i) {
        for (int j = 0; j < hash_table_[i].size(); j++) {
            std::cout << "key: " << hash_table_[i][j].k;
            std::cout << "; element: " << hash_table_[i][j].e;
            std::cout << "; index: " << hash_table_[i][j].k % m_ << std::endl;
        }
    }
}

template <class T>
void HashTable<T>::clear() {
    std::vector<map_element<T>> empty_vector;
    for (int i = 0; i < m_; ++i) {
        hash_table_[i] = empty_vector;
    }
    size_ = 0;
}


int main()
{
    // Testing
    HashTable<std::string> hashtest;
    std::cout << "Testing starting emptiness: " << hashtest.empty();
    std::cout << ". Testing starting size: " << hashtest.size() << std::endl;
    
    if (hashtest.find(5) == nullptr) {
        std::cout << "Attempting to find key 5 in empty hash table: nullptr" << std::endl;
    } else {
        std::cout << "Attempting to find key 5 in empty hash table. At key 5: " << *hashtest.find(5) << std::endl;
    }
    
    std::string s = "the";
    bool insert_test = hashtest.insert(5, s);
    std::cout << "Insert -the- with key 5: " << insert_test << std::endl;
    
    s = "tree";
    insert_test = hashtest.insert(8, s);
    std::cout << "Insert -tree- with key 8: " << insert_test << std::endl;
    
    s = "is";
    insert_test = hashtest.insert(1, s);
    std::cout << "Insert -is- with key 1: " << insert_test << std::endl;
    
    s = "big";
    insert_test = hashtest.insert(3, s);
    std::cout << "Insert -big- with key 3: " << insert_test << std::endl;
    
    s = "and";
    insert_test = hashtest.insert(5, s);
    std::cout << "Insert -and- with repeated key 5: " << insert_test << std::endl;
    
    hashtest.print_all();
    
    bool erase_test = hashtest.erase(5);

    std::cout << "Erase -the-: " << erase_test << std::endl;
    std::cout << "Erase with invalid key: " << hashtest.erase(4) << std::endl;

    if (hashtest.find(5) == nullptr) {
        std::cout << "Finding key 5 after erase: nullptr" << std::endl;
    } else {
        std::cout << "Finding key 5 after erase. At key 5: " << *hashtest.find(5) << std::endl;
    }
    
    
    hashtest.print_all();
    
    std::cout << "Testing emptiness before clear: " << hashtest.empty();
    std::cout << ". Testing final size before clear: " << hashtest.size() << std::endl;
    
    hashtest.clear();
    
    std::cout << "Testing emptiness after clear: " << hashtest.empty();
    std::cout << ". Testing final size after clear: " << hashtest.size() << std::endl;
    
    hashtest.print_all();
    
    return 0;
}
