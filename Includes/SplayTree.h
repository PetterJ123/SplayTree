#ifndef SPLAYTREE_H
#define SPLAYTREE_H

#include <stdexcept>

template <class T>
class SplayTree {
private:
    class Node {
    public:
        T value;
        Node *leftChild;
        Node *rightChild;

        Node() {
            value = -1;
            leftChild = nullptr;
            rightChild = nullptr;
        }
    };

    Node *root;
    size_t numOfElements;

public:
    SplayTree();
    void insert(T element);
    void remove(T element);
    bool find(T element);
    size_t size();
};

/**
 *  Constructor for tree
 *  @params; none
 */
template <typename T>
SplayTree<T>::SplayTree() {
    this->root = nullptr;
    numOfElements = 0;
}

/**
 * Insert's a given element into the tree
 * @param element; The value to be inserted into the tree
 * @return; void
 */
template <typename T>
void SplayTree<T>::insert(T element) {
    Node *newNode = nullptr;

    // creates a new node
    if(newNode == nullptr) {
        newNode = new Node();
        newNode->value = element;
    }

    // if root-node is null; populate it with @param element
    if (root == nullptr) {
        root->leftChild = nullptr;
        root->rightChild = nullptr;
        root = newNode;
        numOfElements++;
    } else {
        // comparing incoming value with what's already in the tree and placing the value accordingly
        // splay() goes here
        if (root->value > element) {
            newNode->leftChild = root->leftChild;
            newNode->rightChild = root;
            root->leftChild = nullptr;
            root = newNode;
            numOfElements++;
        } else if (root->value < element) {
            newNode->rightChild = root->rightChild;
            newNode->leftChild = root;
            root->rightChild = nullptr;
            numOfElements++;
        } else {
            throw std::logic_error("Logic error");
        }
    }
    newNode = nullptr;
}

/**
 * Removes a given element from the tree
 * @param element; The value to be removed from the tree
 * @return; void
 */
template <typename T>
void SplayTree<T>::remove(T element) {
    Node *newTree;
    // splay() goes here
    if (root->value != element) {
        return; // Parameter passed to function wasn't found
    }

    if(root->leftChild == nullptr) {
        newTree = root->rightChild;
    } else {
        newTree = root->leftChild;
        // splay() goes here
        newTree->rightChild = root->rightChild;
    }
    delete root;
    root = newTree;
}

template <typename T>
bool SplayTree<T>::find(T element) {
    if(root == nullptr) {
        throw std::out_of_range("Out_of_range error; tree is empty");
    }
    // splay() goes here
    if(root->value != element) {
        return false; // item doesn't exists in tree
    }

    return true; // item does exist in tree
}

template <typename T>
size_t SplayTree<T>::size() {
    return this->numOfElements;
}

#endif