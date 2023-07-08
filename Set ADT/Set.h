
#ifndef SET_H
#define SET_H

#include <list>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

/**
 * Abstract class to represent the Set ADT
 */
class Set {
public:
    /**
     * Return the number of elements in this Set
     *
     * @return number of elements inside the set
     */
    virtual unsigned int size() = 0;

    /**
     * Insert s into this Set. If the element is 
     * already in this Set, do not
     * make any changes to this Set.
     *
     * @param s string to be inserted into the set
     */
    virtual void insert(string s) = 0;

    /**
     * Remove s from this Set. If the element does 
     * not exist in this Set, do
     * not make any changes to this Set.
     *
     * @param s string to be removed from the set
     */
    virtual void erase(const string &s) = 0;

    /**
     * Check to see if a string exists in the set or not.
     *
     * @param s string to look for in the set
     * @return true if s exists in this Set, otherwise false
     */
    virtual bool contains(const string &s) = 0;
};

/**
 * Class to implement the Set ADT using an Array List (C++ vector class)
 */
class ArrayListSet : public Set {
protected:
    /**
     * C++ vector (which is an Array List) to use behind-the-scenes
     */
    vector<string> arr;

public:
    /**
     * Return number of elements in array list Set
     *
     * @return number of elements in array list set
     */
    unsigned int size();
    /**
     * Insert s into this Set. If the element is 
     * already in this Set, do not
     * make any changes to array list Set.
     *
     * @param s string to be inserted into ALset
     */
    void insert(string s);

    /**
     * Remove s from this Set. If the element does 
     * not exist in this Set, do
     * not make any changes to array list Set.
     *
     * @param s string to be removed from ALset
     */
    void erase(const string &s);

    /**
     * Check to see if a string exists in the set or not.
     *
     * @param s string to look for in the array list set
     * @return true if s exists in ALSet, otherwise false
     */
    bool contains(const string &s);
};

/**
 * Class to implement the Set ADT using a Hash Table (C++ unordered_set class)
 */
class HashTableSet : public Set {
protected:
    /**
     * C++ unordered_set (which is a Hash Table) to use behind-the-scenes
     */
    unordered_set<string> ht;

public:
    /**
    * Return number of elements in HTset
    *
    * @return number of elements in HTset
    */
    unsigned int size();

    /**
     * Insert s into this Set. If the element is 
     * already in this Set, do not
     * make any changes to Hash table Set.
     *
     * @param s string to be inserted into HTset
     */
    void insert(string s);

    /**
     * Remove s from this Set. If the element does 
     * not exist in this Set, do
     * not make any changes to Hash table Set.
     *
     * @param s string to be removed from HTset
     */
    void erase(const string &s);

    /**
     * Check to see if a string exists in the set or not.
     *
     * @param s string to look for in the Hash table set
     * @return true if s exists in HTSet, otherwise false
     */
    bool contains(const string &s);
};

/**
 * Class to implement the Set ADT using a Linked List (C++ list class)
 */
class LinkedListSet : public Set {
protected:
    /**
     * C++ list (which is a Linked List) to use behind-the-scenes
     */
    list<string> linked;

public:
    /**
    * Return number of elements in LLset
    *
    * @return number of elements in LLset
    */
    unsigned int size();

    /**
     * Insert s into this Set. If the element is 
     * already in this Set, do not
     * make any changes to linked list Set.
     *
     * @param s string to be inserted into LLset
     */
    void insert(string s);

    /**
     * Remove s from this Set. If the element does 
     * not exist in this Set, do
     * not make any changes to linked list Set.
     *
     * @param s string to be removed from LLset
     */
    void erase(const string &s);

    /**
     * Check to see if a string exists in Linked 
     * list set or not.
     *
     * @param s string to look for in Linked list set
     * @return true if s exists in LLSet, otherwise false
     */
    bool contains(const string &s);
};

/**
 * Class to implement the Set ADT using a Red-Black Tree (C++ set class)
 */
class RedBlackTreeSet : public Set {
protected:
    /**
     * C++ set (which is a Red-Black Tree) to use behind-the-scenes
     */
    set<string> rbt;

public:
    /**
    * Return number of elements in RBTSet
    *
    * @return number of elements in RBTSet
    */
    unsigned int size();

    /**
     * Insert s into this Set. If the element is 
     * already in this Set, do not
     * make any changes to red black tree Set.
     *
     * @param s string to be inserted into RBTset
     */
    void insert(string s);

    /**
     * Remove s from this Set. If the element does 
     * not exist in this Set, do
     * not make any changes to Red black tree Set.
     *
     * @param s string to be removed from RBTset
     */
    void erase(const string &s);

    /**
     * Check to see if a string exists in Red Black  
     * tree set or not.
     *
     * @param s string to look for in RBTset
     * @return true if s exists in RBTSet, otherwise false
     */
    bool contains(const string &s);
};

/**
 * Class to implement the Set ADT using a Multiway Trie
 */
class MultiwayTrieSet : public Set {
public:
    /**
     * Nested helper Node class
     */
    class Node {
    public:
        /**
         * Boolean to keep track of if this is a "word" node
         */
        bool isWord;

        /**
         * Child pointers, where keys are letters and values are Node*
         */
        unordered_map<char, Node *> children;

        /**
         * Node constructor, which initializes everything
         */
        Node() : isWord(false) {}
    };

    /**
     * MultiwayTrieSet Constructor, which should initialize an empty MWT
     */
    MultiwayTrieSet();

    /**
     * MultiwayTrieSet Destructor, which should deallocate anything dynamic
     */
    ~MultiwayTrieSet();

    /**
    * Return number of elements in MTWSet
    *
    * @return number of elements in MTWSet
    */
    unsigned int size();

    /**
     * Insert s into this Set. If the element is 
     * already in this Set, do not
     * make any changes to multiway trie Set.
     *
     * @param s string to be inserted into MWTset
     */
    void insert(string s);

    /**
     * Remove s from this Set. If the element does 
     * not exist in this Set, do
     * not make any changes to multiway trie Set.
     *
     * @param s string to be removed from MWTset
     */
    void erase(const string &s);
    

    /**
     * Check to see if a string exists in Multiway  
     * trie set or not.
     *
     * @param s string to look for in MWTset
     * @return true if s exists in MWTSet, otherwise false
     */
    bool contains(const string &s);
    
private:
    /**
     * Recursively locate the elemet to remove 
     * and Remove s from this Set 
     *
     * @param Ndelete node to iterate with 
     * @param s string to be removed from MWTset
     * @param height the current level of trie 
     */
    bool deleteS(Node* Ndelete, const string& s, int height);
    /**
     * Helper method for MultiwayTrieSet 
     * Destructor, which should delete the 
     * whole MWT set and deallocate anything
     * dynamic
     *
     * @param nodeR the node to start with 
     */
    void clear(Node* nodeR);

protected:
    /**
     * Pointer to the root node of this MWT
     */
    Node *root;

    /**
     * Total number of elements currently in the MWT
     */
    unsigned int numElements;
};

#endif