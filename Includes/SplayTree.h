#ifndef SPLAYTREE_H
#define SPLAYTREE_H

#include <stdexcept>
#include <vector>

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

    Node* splay(Node *node, T element) {
        Node N, *le, *ri, *c;
        if(node == nullptr) {
            return nullptr;
        }

        N.leftChild = N.rightChild = nullptr;
        le = ri = &N;

        for(;;) {
            if(node->value > element) {

                if(node->leftChild == nullptr) {
                    break;
                }

                if(node->leftChild->value > element) {
                    c = node->leftChild;
                    node->leftChild = c->rightChild;
                    c->rightChild = node;
                    node = c;

                    if(node->leftChild == nullptr) {
                        break;
                    }
                }
                ri->leftChild = node;
                ri = node;
                node = node->leftChild;
            }
            else if(node->value < element)
            {
                if(node->rightChild == nullptr) {
                    break;
                }

                if(node->rightChild->value < element) {
                    c = node->rightChild;
                    node->rightChild = c->leftChild;
                    c->leftChild = node;
                    node = c;

                    if(node->rightChild == nullptr) {
                        break;
                    }
                }
                le->rightChild = node;
                le = node;
                node = node->rightChild;
            }
            else
            {
                break;
            }
        }

        le->rightChild = node->leftChild;
        ri->leftChild = node->rightChild;
        node->leftChild = N.rightChild;
        node->rightChild = N.leftChild;

        return node;
    }

    /**
     * Search-function that is used in removeRecursive function to find the node
     * requested for deleteion
     * @param Node* node; root node in this object
     * @param T element; template variable being the value requested to find
     * @return Node*; Returns a pointer to the node from removeRecursive
     */
    Node* search(Node* node, T element) {
        if(node == nullptr || node->value == element) {
            return node;
        }

        if(node->value > element) {
            return search(node->leftChild, element);
        } else {
            return search(node->rightChild, element);
        }
    }

    // Node* splay(Node *node, T element);
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
    // std::vector<T> preOrderWalk() const;
    // std::vector<T> inOrderWalk() const;
    // std::vector<T> postOrderWalk() const;
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
    root = splay(root, element);
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
    } else if(nodeTrv->value < element) {
        if(nodeTrv->rightChild != nullptr) {
            insertRecursive(element, nodeTrv->rightChild);
        } else {
            nodeTrv->rightChild = initNode(element);
            numOfElements++;
        }
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
    root = splay(root, element);
}

template <typename T>
void SplayTree<T>::removeRecursive(T element, Node *ptr) {
    Node* node;

    if(ptr == nullptr) {
        throw std::out_of_range("Tree seems to be empty!");
    }

    if(search(ptr, element) == nullptr) {
        throw std::out_of_range("Value doesn't seem to exist! Can't remove item that doesn't exist!");
    }

    ptr = splay(ptr, element);

    if(ptr->leftChild != nullptr) {
        node = splay(ptr->leftChild, element);
        node->rightChild = ptr->rightChild;
    } else {
        node = ptr->rightChild;
    }

    delete ptr;
}

/**
 * Will look for a match to the passed parameter
 * @param T element; template variable being the value that is looked for
 * @return bool; returns true if the value have been found, otherwise false
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
 * rotating the last accessed node to the root.
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