#include <iostream>

using namespace std;

template <typename T>
struct Node
{
    string key;
    T value;
    Node<T> *next;

    Node(string key, T value)
        : key(key), value(value), next(nullptr) {}
    ~Node()
    {
        if (next)
            delete next;
    }
};

template <class T>
class Hashtable
{
    Node<T> **table;
    int currentSize;
    int tableSize;
    int hashFn(string key);
    void rehash();

public:
    Hashtable(int ts);
    void insert(string key, T value);
    T *search(string key);
    void print();
    void erase(string key);
    T& operator[](string key)
    {
        T *f = search(key);
        if(!f)
        {
            T garbage;
            insert(key, garbage);
            f = search(key);
        }
        return *f;
    }
};

template <class T>
Hashtable<T>::Hashtable(int ts)
{
    tableSize = ts;
    table = new Node<T> *[tableSize];
    currentSize = 0;
    for (int i = 0; i < tableSize; i++)
        table[i] = nullptr;
}

template <class T>
int Hashtable<T>::hashFn(string key)
{
    int idx = 0;
    int p = 1;
    for (int i = 0; i < key.length(); i++)
    {
        idx = idx + (key[i] * p) % tableSize;
        idx = idx % tableSize;
        p = (p * 27) % tableSize;
    }
    return idx;
}
template <class T>
void Hashtable<T>::rehash()
{
    Node<T> **oldTable = table;
    int oldTableSize = tableSize;
    tableSize = 2 * tableSize;

    table = new Node<T> *[tableSize];

    for (int i = 0; i < tableSize; i++)
        table[i] = nullptr;

    currentSize = 0;
    for (int i = 0; i < oldTableSize; i++)
    {
        Node<T> *temp = oldTable[i];
        while (temp)
        {
            insert(temp->key, temp->value);
            temp = temp->next;
        }
        if (oldTable[i] != nullptr)
        {
            delete oldTable[i];
        }
    }
    delete[] oldTable;
}
template <class T>
void Hashtable<T>::insert(string key, T value)
{
    int idx = hashFn(key);
    Node<T> *n = new Node<T>(key, value);

    n->next = table[idx];
    table[idx] = n;
    currentSize++;

    float loadFactor = currentSize / (1.0 * tableSize);
    if (loadFactor > 0.7)
    {
        rehash();
    }
}
template <class T>
T *Hashtable<T>::search(string key)
{
    int idx = hashFn(key);
    Node<T> *temp = table[idx];

    while (temp)
    {
        if (temp->key == key)
            return &temp->value;

        temp = temp->next;
    }
    return nullptr;
}

template <class T>
void Hashtable<T>::print()
{
    for (int i = 0; i < tableSize; i++)
    {
        Node<T> *temp = table[i];
        cout << "Bucket : " << i << "->";
        while (temp)
        {
            cout << "( " << temp->key << ", " << temp->value << " )"
                 << "->";
            temp = temp->next;
        }
        cout << endl;
    }
}
template <class T>
void Hashtable<T>::erase(string key)
{
    T *f = search(key);
    if (f)
    {
        int idx = hashFn(key);
        Node<T> *temp = table[idx];

        Node<T> *prev = nullptr;
        while (temp->key != key)
        {
            prev = temp;
            temp = temp->next;
        }
        if (prev)
        {
            prev->next = temp->next;
        }
        else
        {
            table[idx] = temp->next;
        }
        temp->next = nullptr;
        delete temp;
    }
}
int main()
{
    Hashtable<int> h(7);
    h.insert("Burger", 120);
    h.insert("Pepsi", 20);
    h.insert("BurgerPizza", 120);
    h.insert("Noodles", 25);
    h.insert("Coke", 40);
    h["Dosa"] = 70;
    h["Dosa"] += 10;
    h.print();
    cout << h["Burger"] << endl;
    h.erase("Burger");
    cout << endl;
    h.print();
    return 0;
}