#ifndef TREE_H
#define TREE_H
#include "iostream"
#include "treenode.h"
using namespace std;

template<class T>
class Tree
{
public:
    Tree();
    Tree(Tree &obj);
    ~Tree();
    void operator=(Tree &obj);

    bool add(T t);
    void clear();
    bool contains(T t);
    T first();
    TreeNode<T>* getNode(T t);
    bool isEmpty();
    T last();
    bool remove(T t);
    int size();
    string traversal();

private:
    TreeNode<T>* root;

    int size_of(TreeNode<T>* t);
    string string_of(TreeNode<T>* t);
};

/* Default constructor
 */
template<class T>
Tree<T>::Tree() {
    root = nullptr;
}

/* Copy constructor
 * @param obj - object to copy
 */
template<class T>
Tree<T>::Tree(Tree &obj) {
    root = obj.root;
}

/* Default destructor
 */
template<class T>
Tree<T>::~Tree() {
    delete root;
}

/* Assignment operator
 * @param obj - object to copy
 */
template<class T>
void Tree<T>::operator=(Tree &obj) {
    root = obj.root;
}

/* Adds new node to tree
 * @param t - value to add
 * @return true if successfully added, false otherwise
 */
template<class T>
bool Tree<T>::add(T t) {
    if(contains(t)) //Returns false if element is already in tree
        return false;
    if(root == nullptr) {
        root = new TreeNode<T>(t); //Sets root if not set already
        return true;
    }
    TreeNode<T>* curNode = root;
    while(curNode != nullptr) {
        if(t < curNode->getData()) {
            if(curNode->getLeft() == nullptr) { //Finds leaf to add to
                curNode->setLeft(new TreeNode<T>(t));
                return true;
            } else { //Moves down a level in tree
                curNode = curNode->getLeft();
            }
        } else {
            if(curNode->getRight() == nullptr) { //Finds leaf to add to
                curNode->setRight(new TreeNode<T>(t));
                return true;
            } else { //Moves down a level in tree
                curNode = curNode->getRight();
            }
        }
    }
    return false;
}

/* Empties tree
 */
template<class T>
void Tree<T>::clear() {
    if(root != nullptr) {
        delete root->getLeft();
        delete root->getRight();
    }
    root = nullptr;
}

/* Finds out if element is in tree
 * @param t - element to find
 * @return true if found, false otherwise
 */
template<class T>
bool Tree<T>::contains(T t) {
    TreeNode<T>* curNode = root;
    while(curNode != nullptr) {
        if(t == curNode->getData())
            return true; //Data is found
        else if(t < curNode->getData())
            curNode = curNode->getLeft(); //Move down level
        else
            curNode = curNode->getRight(); //Move down level
    }
    return false;
}

/* Gets first element in tree
 * @return lowest element
 */
template<class T>
T Tree<T>::first() {
    TreeNode<T>* curNode = root;
    while(curNode != nullptr) { //Moves down left children until found
        if(curNode->getLeft() == nullptr)
            return curNode->getData();
        else
            curNode = curNode->getLeft();
    }
    return NULL;
}

/* Gets node with given value
 * @param t - element to find
 * @return node with that value
 */
template<class T>
TreeNode<T>* Tree<T>::getNode(T t) {
    TreeNode<T>* curNode = root;
    while(curNode != nullptr) {
        if(t == curNode->getData())
            return curNode; //Node found
        else if(t < curNode->getData()) //Move down levels
            curNode = curNode->getLeft();
        else
            curNode = curNode->getRight();
    }
    return nullptr;
}

/* Finds out if tree is empty or not
 * @return true if tree is empty, false otherwise
 */
template<class T>
bool Tree<T>::isEmpty() {
    if(root == nullptr)
        return true;
    else
        return false;
}

/* Gets last element in tree
 * @return last element
 */
template<class T>
T Tree<T>::last() {
    TreeNode<T>* curNode = root;
    while(curNode != nullptr) { //Moves down right children until found
        if(curNode->getRight() == nullptr)
            return curNode->getData();
        else
            curNode = curNode->getRight();
    }
    return NULL;
}

/* Removes element with given value
 * @param t - element to remove
 * @return true if removed, false otherwise
 */
template<class T>
bool Tree<T>::remove(T t) {
    if(!contains(t)) //Return false if element isn't in tree
        return false;
    TreeNode<T>* curNode = root;
    while(curNode != nullptr) {
        if(t == curNode->getData()) { //Root is to be deleted
            if(root->getLeft() != nullptr) { //Try to move left branch first
                TreeNode<T>* lc = root->getLeft();
                //Move left child's right branch to other side of tree
                if(lc->getRight() != nullptr) {
                    TreeNode<T>* otherNode = root->getRight();
                    while(otherNode != nullptr) {
                        if(otherNode->getLeft() == nullptr)
                            break;
                        else
                            otherNode = otherNode->getLeft();
                    }
                    otherNode->setLeft(lc->getRight());
                    lc->setRight(root->getRight());
                    root = lc;
                } else { //Set left branch as root
                    lc->setRight(root->getRight());
                    root = lc;
                }
            } else if(root->getRight() != nullptr) {
                root = root->getRight(); //Shifts root if no left branch
            } else {
                root = nullptr; //Bye bye tree
            }
            return true;
        } else if(t < curNode->getData()) { //If element is somewhere left
            if(curNode->getLeft() != nullptr && //If left child is target
                    curNode->getLeft()->getData() == t) {
                if(curNode->getLeft()->getRight() == nullptr) {
                    curNode->setLeft(curNode->getLeft()->getLeft());
                    return true; //Move left grandchild up if only grandchild
                }
                TreeNode<T>* lc = curNode->getLeft();
                TreeNode<T>* otherNode = lc->getLeft();
                if(otherNode != nullptr) {
                    while(otherNode != nullptr) {
                        if(otherNode->getRight() == nullptr)
                            break; //Break when end of line is found
                        else //Find right grandchild of target to get branch
                            otherNode = otherNode->getRight();
                    }
                    //Move right child of target and move the left child up
                    otherNode->setRight(lc->getRight());
                    curNode->setLeft(lc->getLeft());
                    lc->setRight(nullptr);
                } else { //No grandchildren to move, so left is empty
                    curNode->setLeft(nullptr);
                }
                return true;
            } else { //Move down through tree
                curNode = curNode->getLeft();
            }
        } else {//If element is somewhere right
            if(curNode->getRight() != nullptr && //If right child is target
                    curNode->getRight()->getData() == t) {
                if(curNode->getRight()->getLeft() == nullptr) {
                    curNode->setRight(curNode->getRight()->getRight());
                    return true; //Move right grandchild up if only grandchild
                }
                TreeNode<T>* lc = curNode->getRight()->getLeft();
                TreeNode<T>* rc = curNode->getRight()->getRight();

                TreeNode<T>* otherNode = rc;
                if(otherNode != nullptr) {
                    while(otherNode != nullptr) {
                        if(otherNode->getLeft() == nullptr)
                            break; //Break when end of line is found
                        else //Find left grandchild of target to get branch
                            otherNode = otherNode->getLeft();
                    }
                    //Move left child of target and move the right child up
                    otherNode->setLeft(lc->getRight());
                    curNode->setRight(lc);
                    lc->setRight(rc);
                } else { //No grandchildren to move, so left grandchild is up
                    curNode->setRight(lc);
                }
                return true;
            } else { //Move down through tree
                curNode = curNode->getRight();
            }
        }
    }
    return false;
}

/* Gets size of tree
 * @return size of the tree
 */
template<class T>
int Tree<T>::size() {
    return size_of(root);
}

/* Recursive method to gather size
 * @param t - current node
 * @return size of its subtree
 */
template<class T>
int Tree<T>::size_of(TreeNode<T>* t) {
    if(t == nullptr)
        return 0;
    else
        return size_of(t->getLeft()) + 1 + size_of(t->getRight());
}

/* Returns in order traversal of tree
 * @return string traversal of tree
 */
template<class T>
string Tree<T>::traversal() {
    return "In Order Traversal: " + string_of(root);
}

/* Recursive method to gather traversal
 * @param t - current node
 * @return traversal of subtree
 */
template<class T>
string Tree<T>::string_of(TreeNode<T>* t) {
    if(t == nullptr)
        return "";
    else
        return string_of(t->getLeft()) + to_string(t->getData()) + ", " + string_of(t->getRight());
}

#endif // TREE_H
