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
    
    bool empty() const { return (size_ == 0) ? true: false; }
    
    int size() const { return size_; }
    
    bool erase(int key);
    
    T * find(int key);
    
    const T * find(int key) const;
    
    bool insert(int key, T element);
    
    void print_all() const;
    
    void clear();
    
    T & operator[](int key);
    
    const T & operator[](int key) const;
    
    
private:
    std::vector<std::vector<map_element<T>>> hash_table_ ;
    int size_; // n
    int m_;
    
    void rehash();
    
};

template <class T>
T * HashTable<T>::find(int key) {
    int index = key % m_;
    for (auto i = hash_table_[index].begin(); i < hash_table_[index].end(); ++i) {
        if (i->k == key) {
            return &(i->e);
        }
    }
    return nullptr;
}

template <class T>
const T * HashTable<T>::find(int key) const {
    int index = key % m_;
    for (auto i = hash_table_[index].begin(); i < hash_table_[index].end(); ++i) {
        if (i->k == key) {
            return &(i->e);
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
        for ( auto i = hash_table_.begin(); i < hash_table_.end(); ++i ) {
            for ( auto j = (*i).begin(); j < (*i).end(); ++j ) {
                int index = (j->k) % new_m;
                new_hash[index].push_back(*j);
            }
        }
        m_ = new_m;
        hash_table_ = new_hash;
    }
}

template <class T>
bool HashTable<T>::erase(int key) {
     int index = key % m_;
     for (auto i = hash_table_[index].begin(); i < hash_table_[index].end(); ++i) {
         if (i->k == key) {
             hash_table_[index].erase(i);
             return true;
         }
     }
    return false;
}

template <class T>
void HashTable<T>::print_all() const {
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
    hash_table_.clear();
    size_ = 0;
}

template <class T>
T & HashTable<T>::operator[](int key){
    if (find(key) == nullptr)
    {
        insert(key,T());
    }
    return *(find(key));
}

//this is not tested in main (not positive how to test it really)
template <class T>
const T & HashTable<T>::operator[](int key) const {
    if (find(key) == nullptr)
    {
        
    }
    std::cout << "constant one was used. " << std::endl;
    return *(find(key));
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
    
    
    std::cout << "Hash test of key: 8 is " << hashtest[8] << std::endl;
    
    std::cout << "Testing indexing operator: big = " << hashtest[3] << std::endl;
    hashtest[7] = "and";
    hashtest[20] = "green";
    hashtest[44];
    hashtest.print_all();
    
    
    const HashTable<std::string> hashtestconstant = hashtest;
    std::cout << "testing constant method: " << hashtestconstant[8] << std::endl;
    
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
