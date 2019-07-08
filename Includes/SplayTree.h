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
    mutable std::vector<T> inOrderElements;

    Node* initNode(T element) {
        Node* node = new Node();
        node->value = element;

        return node;
    }

    Node* splay(Node *node, T element) {
        Node N, *ltm, *rtm, *c;
        if(node == nullptr) {
            return nullptr;
        }

        N.leftChild = N.rightChild = nullptr;
        ltm = rtm = &N;

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
                rtm->leftChild = node;
                rtm = node;
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
                ltm->rightChild = node;
                ltm = node;
                node = node->rightChild;
            }
            else
            {
                break;
            }
        }

        ltm->rightChild = node->leftChild;
        rtm->leftChild = node->rightChild;
        node->leftChild = N.rightChild;
        node->rightChild = N.leftChild;

        return node;
    }

    /**
     * Search-function that is used in removeRecursive function to find the node
     * requested for deletion
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

    /**
    * Recursive insert function that will go through
    * the tree and insert a new value at the right place
    * @param elemnt; The value to be inserted into the tree
    * @param nodeTrv; Node pointer used to traverse the tree recursivly
    * @return; void
    */
    void insertRecursive(T element, Node *nodeTrv) {
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
     * Recursive remove function that traverses the tree and deletes
     * the requested node.
     * @param T element; The value to be deleted
     * @param Node* ptr; Traverser node
     * @return; void
     */
    void removeRecursive(T element, Node *ptr) {
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

    void inOrderWalk(Node* rp) const {
        std::vector<T> vec;

        if(rp != nullptr) {
            inOrderWalk(rp->leftChild);
            vec.push_back(rp->value);
            inOrderWalk(rp->rightChild);
        }

        this->inOrderElements = vec;
    }

    // std::vector<T> inorderRecursive(Node* ptr) {
    //     if(rootPtr == nullptr) {
    //         std::out_of_range("Tree is empty");
    //     }

    //     std::vector<T> r, x;

    //     if(rootPtr->leftChild != nullptr) {
    //         x = inorderRecursive(rootPtr->leftChild);
    //         r.insert(r.end(), x.begin(), x.end());
    //     }

    //     r.push_back(rootPtr->value);

    //     if(root->rightChild != nullptr) {
    //         x = inorderRecursive(rootPtr->rightChild);
    //         r.insert(r.end(), x.begin(), x.end());
    //     }

    //     return r;
    // }

public:
    /**
     * Class SplayTree constructor
     */
    SplayTree() {
        this->root = nullptr;
        numOfElements = 0;
    }

    /**
     * Insert's a given element into the tree
     * @param element; The value to be inserted into the tree
     * @return; void
     */
    void insert(T element) {
        insertRecursive(element, root);
        root = splay(root, element);
    }

    /**
    * Removes a given element from the tree
    * @param element; The value to be removed from the tree
    * @return; void
    */
    void remove(T element) {
        removeRecursive(element, root);
        root = splay(root, element);
    }

    /**
    * Will look for a match to the passed parameter
    * @param T element; template variable being the value that is looked for
    * @return bool; returns true if the value have been found, otherwise false
    */
    bool find(T element) {
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
    size_t size() {
        return this->numOfElements;
    }

    /**
    * Function that gets the smallest value in the tree
    * @param; void
    * @return; template variable
    */
    T getMin() {
        Node *treeTrav = root;

        while(treeTrav->leftChild != nullptr) {
            treeTrav = treeTrav->leftChild;
        }
        // splay(treeTrav->value, treeTrav);

        return treeTrav->value;
    }

    /**
    * Function that gets the highest value in the tree
    * @param; void
    * @return; template variable
    */
    T getMax() {
        Node *treeTrav = root;

        while(treeTrav->rightChild != nullptr) {
            treeTrav = treeTrav->rightChild;
        }
        // splay(treeTrav->value, treeTrav);

        return treeTrav->value;
    }

    /**
    * Function the returns the root node in the tree
    * @param; void
    * @return; template variable
    */
    T getRoot() {
        return this->root->value;
    }

    /**
     * Function inserting a tree´s values according to in-order principles
     * @param; void
     * @return std::vector<T>; returns a vector containing values according to in-order principles
     */
    std::vector<T> inOrderWalk() const {
        if(root == nullptr) {
            std::out_of_range("Tree is empty!");
        } else {
            inOrderWalk(root);
        }

        return this->inOrderElements;
    }
};

#endif