#ifndef SPLAYTREE_H
#define SPLAYTREE_H

#include <stdexcept>
#include <iostream>

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

    Node* initNode(T element) {
        Node* node = new Node();
        node->value = element;

        return node;
    }

    void insertRecursive(T element, Node *ptr);
    void removeRecursive(T element, Node *ptr);

public:
    SplayTree();
    void insert(T element);     // Inserts an element [DONE]
    void remove(T element);     // Removes an element
    bool find(T element);       // Finds an element
    size_t size();              // Returns number of elements [DONE]
    T getMin();                 // Gets the minimum value in tree [DONE]
    T getMax();                 // Gets the maximum value in the tree [DONE]
    T getRoot();                // Gets the root node [DONE]
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
    insertRecursive(element, root);
}

/**
 * Recursive insert function that will go through
 * the tree and insert a new value at the right place
 * @param elemnt; The value to be inserted into the tree
 * @param nodeTrv; Node pointer used to traverse the tree recursivly
 * @return; void
 */
template <typename T>
void SplayTree<T>::insertRecursive(T element, Node *nodeTrv) {
    if(root == nullptr) {
        root = initNode(element);
        numOfElements++;
    } else if(nodeTrv->value > element) {
        if(nodeTrv->leftChild != nullptr) {
            insertRecursive(element, nodeTrv->leftChild);
        } else {
            nodeTrv->leftChild = initNode(element);
            numOfElements++;
        }
            // splay(element, nodeTrv->leftChild);
    } else if(nodeTrv->value < element) {
        if(nodeTrv->rightChild != nullptr) {
            insertRecursive(element, nodeTrv->rightChild);
        } else {
            nodeTrv->rightChild = initNode(element);
            numOfElements++;
        }
            // splay(element, nodeTrv->rightChild);
    }
}

/**
 * Removes a given element from the tree
 * @param element; The value to be removed from the tree
 * @return; void
 */
template <typename T>
void SplayTree<T>::remove(T element) {
    removeRecursive(element, root);
}

template <typename T>
void SplayTree<T>::removeRecursive(T element, Node *ptr) {
    if(root == nullptr) {
        std::out_of_range("Out_of_range error; tree is empty!");
    } else if(ptr->value > element) {
        if(ptr->leftChild != nullptr) {
            removeRecursive(element, ptr->leftChild);
        } else {
            // remove node
            numOfElements--;
        }
        // splay();
    } else if(ptr->value < element) {
        if(ptr->rightChild != nullptr) {
            removeRecursive(element, ptr->rightChild);
        } else {
            // remove node
            numOfElements--;
        }
        // splay();
    }
}

/**
 * Will look for a match to the passed parameter
 *  @param T element; template variable being the value that is looked for
 *  @return bool; returns true if the value have been found, otherwise false
 */
template <typename T>
bool SplayTree<T>::find(T element) {
    Node *nodePtr = root;
    while(nodePtr != nullptr) {
        if(nodePtr->value == element) {
            return true;
        } else if(element < nodePtr->value) {
            nodePtr = nodePtr->leftChild;
        } else if(element > nodePtr->value) {
            nodePtr = nodePtr->rightChild;
        } else {
            return false;
        }
    }
    return false;
}

/**
 *  Function that returns the num of elements in the tree
 *  @param; none
 *  @return size_t; number of elements in the tree
 */
template <typename T>
size_t SplayTree<T>::size() {
    return numOfElements;
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


/** [DONE!]
 * Function that gets the smallest value in the tree
 * @param; void
 * @return; template variable
 */
template <typename T>
T SplayTree<T>::getMin() {
    Node *treeTrav = root;

    while(treeTrav->leftChild != nullptr) {
        treeTrav = treeTrav->leftChild;
    }
    // splay(treeTrav->value, treeTrav);

    return treeTrav->value;
}

/** [DONE!]
 * Function that gets the highest value in the tree
 * @param; void
 * @return; template variable
 */
template <typename T>
T SplayTree<T>::getMax() {
    Node *treeTrav = root;

    while(treeTrav->rightChild != nullptr) {
        treeTrav = treeTrav->rightChild;
    }
    // splay(treeTrav->value, treeTrav);

    return treeTrav->value;
}

/** [DONE!] (ish, root node doesn't match, but not this functions fault)
 * Function the returns the root node in the tree
 * @param; void
 * @return; template variable
 */
template <typename T>
T SplayTree<T>::getRoot() {
    return root->value;
}

#endif