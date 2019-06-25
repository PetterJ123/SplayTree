#ifndef SPLAYTREE_H
#define SPLAYTREE_H

#include <stdexcept>

template <class T>
class SplayTree {
private:
    /** Node class representing each node containing a reference to left and right children  and also a value that the node holds onto
     */
    
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
    void insert(T element);     // Inserts an element
    void remove(T element);     // Removes an element
    bool find(T element);       // Finds an element
    size_t size();              // Returns number of elements
    T getMin() const;           // Gets the minimum value in tree
    //T getMax() const;         // Gets the maximum value in the tree
    //T getRoot() const;        // Gets the root node

    void splay(T element, Node *node) const;
    void rotateLeftChild(Node *node2) const;
    void rotateRightChild(Node *node1) const;
};

/**
 *  Constructor for tree
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
    newNode = nullptr;  // 
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

/**
 * Will look for a match to the passed parameter
 *  @param T element; template variable being the value that is looked for
 *  @return bool; returns true if the value have been found, otherwise false
 */
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

/**
 *  Function that returns the num of elements in the tree
 *  @param; none
 *  @return size_t; number of elements in the tree
 */
template <typename T>
size_t SplayTree<T>::size() {
    return this->numOfElements;
}

// ================Helper functions ===========

/**
 * Function that will be executed after every access that have been done in the tree;
 *  rotating the last accessed node to the root.
 *  @param T element; Template variable representing the variable that the splay-
 * function needs to rotate the element to the root-node
 * @param Node *node; Node object being a placeholder object for traversing the tree
 * @return; void
 */

template <typename T>
void SplayTree<T>::splay(T element, Node *node) const {
    Node *leftTreeMax, *rightTreeMin;
    static Node header;

    header.leftChild = header.rightChild = nullptr;
    leftTreeMax = rightTreeMin = &header;

    Node *emptyNode = new Node();
    emptyNode->leftChild = nullptr;
    emptyNode->rightChild = nullptr;
    emptyNode->value = element;

    for( ; ; ) {
        if (element < node->value) {
            if (element < node->leftChild->value) {
                //rotateWithLeftChild(node);
            }
            if (node->leftChild == nullptr) {
                break;
            }
            rightTreeMin->leftChild = node;
            rightTreeMin = node;
            node = node->leftChild;
        } else if (node->value < element) {
            if (node->rightChild->value < element) {
                // rotateWithRightChild(node);
            }
            if (node->rightChild == nullptr) {
                break;
            }
            leftTreeMax->rightChild = node;
            leftTreeMax = node;
            node = node->rightChild;
        } else {
            break;
        }

        leftTreeMax->rightChild = node->leftChild;
        rightTreeMin->leftChild = node->rightChild;
        node->rightChild = header.leftChild;
    }
}

/**
 * Function that rotates a parent-node with its left child
 * @param node2; pointer to the node that is suppoesed to be rotated
 * @retun; void
 */
template <typename T>
void SplayTree<T>::rotateLeftChild(Node *node2) const {
    Node *node1 = node2->leftChild;
    node2->leftChild = node1->rightChild;
    node1->rightChild = node2;
    node2 = node1;
}

/**
 * Function that rotates a parent-node with it's right child
 * @param node1; pointer to the child node that is supposed to be rotated
 * @return; void
 */
template <typename T>
void SplayTree<T>::rotateRightChild(Node *node1) const {
    Node *node2 = node1->rightChild;
    node1->rightChild = node2->leftChild;
    node2->leftChild = node1;
    node1 = node2;
}

template <typename T>
T SplayTree<T>::getMin() const {
    Node *rptr = root;

    while(rptr->leftChild != nullptr) {
        rptr = rptr->leftChild;
    }
    splay(rptr->value, root);
    return rptr->value;
}

#endif