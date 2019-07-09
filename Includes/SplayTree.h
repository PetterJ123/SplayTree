#ifndef SPLAYTREE_H
#define SPLAYTREE_H

#include <stdexcept>
#include <vector>

template <class T>
class SplayTree {
private:
    class Node {    // Nested class declaraing a node
    public:
        T value;
        Node *leftChild;
        Node *rightChild;

        Node() {
            value = -1;
            leftChild = nullptr;
            rightChild = nullptr;
        }

        Node(T value, Node* lc, Node* rc) {
            this->value = value;
            this->leftChild = lc;
            this->rightChild = rc;
        }
    };

    Node *root;
    size_t numOfElements;
    mutable std::vector<T> preOrderElements;
    mutable std::vector<T> inOrderElements;
    mutable std::vector<T> postOrderElements;

    /**
     * Function that is used to rotate the @param subRoot to the root node in the tree
     * @param Node* subRoot; Pointer to the node that is rotated to the root node
     * @param T element; template variable being each node's value
     */
    Node* splay(Node* subRoot, T element) {
        Node header, *ltm, *rtm, *current;
        if(subRoot == nullptr) {
            return nullptr;
        }

        header.leftChild = header.rightChild = nullptr;
        ltm = rtm = &header;

        for(;;) {
            if(subRoot->value > element) {

                if(subRoot->leftChild == nullptr) {
                    break;
                }

                if(subRoot->leftChild->value > element) {
                    current = subRoot->leftChild;
                    subRoot->leftChild = current->rightChild;
                    current->rightChild = subRoot;
                    subRoot = current;

                    if(subRoot->leftChild == nullptr) {
                        break;
                    }
                }
                rtm->leftChild = subRoot;
                rtm = subRoot;
                subRoot = subRoot->leftChild;
            }
            else if(subRoot->value < element)
            {
                if(subRoot->rightChild == nullptr) {
                    break;
                }

                if(subRoot->rightChild->value < element) {
                    current = subRoot->rightChild;
                    subRoot->rightChild = current->leftChild;
                    current->leftChild = subRoot;
                    subRoot = current;

                    if(subRoot->rightChild == nullptr) {
                        break;
                    }
                }
                ltm->rightChild = subRoot;
                ltm = subRoot;
                subRoot = subRoot->rightChild;
            }
            else
            {
                break;
            }
        }

        ltm->rightChild = subRoot->leftChild;
        rtm->leftChild = subRoot->rightChild;
        subRoot->leftChild = header.rightChild;
        subRoot->rightChild = header.leftChild;

        return subRoot;
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
    * @param element; The value to be inserted into the tree
    * @param nodeTrv; Node pointer used to traverse the tree recursivly
    * @return; void
    */
    void insertRecursive(T element, Node *nodeTrv) {
        if(root == nullptr) {
            root = new Node(element, nullptr, nullptr);
            numOfElements++;
        } else if(nodeTrv->value > element) {
            if(nodeTrv->leftChild != nullptr) {
                insertRecursive(element, nodeTrv->leftChild);
            } else {
                nodeTrv->leftChild = new Node(element, nullptr, nullptr);
                numOfElements++;
            }
        } else if(nodeTrv->value < element) {
            if(nodeTrv->rightChild != nullptr) {
                insertRecursive(element, nodeTrv->rightChild);
            } else {
                nodeTrv->rightChild = new Node(element, nullptr, nullptr);
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
            return;
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

    void preOrder(Node* rp) const {
        if(rp != nullptr) {
            this->preOrderElements.push_back(rp->value);
            preOrder(rp->leftChild);
            preOrder(rp->rightChild);
        }
    }

    void inOrder(Node* rp) const {
        if(rp != nullptr) {
            inOrder(rp->leftChild);
            this->inOrderElements.push_back(rp->value);
            inOrder(rp->rightChild);
        }
    }

    void postOrder(Node* rp) const {
        if(rp != nullptr) {
            postOrder(rp->leftChild);
            postOrder(rp->rightChild);
            this->postOrderElements.push_back(rp->value);
        }
    }

    void clearTree(Node* root) {
        if(root != nullptr) {
            clearTree(root->leftChild);
            clearTree(root->rightChild);
            delete root;
        }
        root = nullptr;
    }

public:
    /**
     * Class SplayTree constructor
     */
    SplayTree() {
        this->root = new Node();
        this->root->leftChild = nullptr;
        this->root->rightChild = nullptr;
        this->root->value = -1;
        this->numOfElements = 0;
    }

    ~SplayTree() {
        clearTree(this->root);
    }

    /**
     * Insert's a given element into the tree
     * @param element; The value to be inserted into the tree
     * @return; void
     */
    void insert(T element) {
        insertRecursive(element, root);
        this->root = splay(this->root, element);
    }

    /**
    * Removes a given element from the tree
    * @param element; The value to be removed from the tree
    * @return; void
    */
    void remove(T element) {
        removeRecursive(element, root);
        this->root = splay(this->root, element);
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
                // nodePtr = splay(nodePtr, element);
                return true;
            } else if(element < nodePtr->value) {
                nodePtr = nodePtr->leftChild;
            } else if(element > nodePtr->value) {
                nodePtr = nodePtr->rightChild;
            } else {
                return false;
                // nodePtr = splay(nodePtr, element);
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
        return numOfElements;
    }

    /**
    * Function that gets the smallest value in the tree
    * @param; void
    * @return; template variable
    */
    T getMin() {
        if(root == nullptr) {
            throw std::underflow_error("Tree is empty");
        } else {
            Node *treeTrav = root;

            while(treeTrav->leftChild != nullptr) {
                treeTrav = treeTrav->leftChild;
            }
            treeTrav = splay(treeTrav, treeTrav->value);

            return treeTrav->value;
        }
    }

    /**
    * Function that gets the highest value in the tree
    * @param; void
    * @return; template variable
    */
    T getMax() {
        if(root == nullptr) {
            throw std::underflow_error("Tree is empty");
        } else {
            Node *treeTrav = root;

            while(treeTrav->rightChild != nullptr) {
                treeTrav = treeTrav->rightChild;
            }
            treeTrav = splay(treeTrav, treeTrav->value);

            return treeTrav->value;
        }
    }

    /**
    * Function the returns the root node in the tree
    * @param; void
    * @return; template variable
    */
    T getRoot() {
        if(root == nullptr) {
            throw std::underflow_error("Tree is empty");
        } else {
            return this->root->value;
        }
    }

    /**
     * Function inserting a tree´s values into a vector
     * @param; void
     * @return std::vector<T>; a vector containing the tree´s values according to pre-order principles
     */
    std::vector<T> preOrderWalk() const {
        if(root == nullptr) {
            std::underflow_error("Tree is empty");
        } else {
            preOrder(root);
        }

        return this->preOrderElements;
    }

    /**
     * Function inserting a tree´s values into a vector
     * @param; void
     * @return std::vector<T>; a vector containing the tree´s values according to in-order principles
     */
    std::vector<T> inOrderWalk() const {
        if(root == nullptr) {
            std::underflow_error("Tree is empty!");
        } else {
            inOrder(root);
        }

        return this->inOrderElements;
    }

    /**
     * Function inserting a tree´s values into a vector
     * @param; void
     * @return std::vector<T>; a vector containing the tree´s values according to post-order principles
     */
    std::vector<T> postOrderWalk() const {
        if(root == nullptr) {
            throw std::underflow_error("Tree is empty");
        } else {
            postOrder(root);
        }

        return this->postOrderElements;
    }
};

#endif