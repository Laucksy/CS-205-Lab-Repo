#ifndef TREENODE_H
#define TREENODE_H
#include "iostream"
using namespace std;

template<class T>
class TreeNode
{
public:
    TreeNode();
    TreeNode(T t);
    TreeNode(TreeNode &obj);
    ~TreeNode();
    void operator=(TreeNode &obj);

    T getData();
    void setData(T t);
    TreeNode* getLeft();
    void setLeft(TreeNode* n);
    TreeNode* getRight();
    void setRight(TreeNode* n);

private:
    T data;
    TreeNode *left;
    TreeNode *right;
};

/* Default constructor
 */
template<class T>
TreeNode<T>::TreeNode() {
    data = NULL;
    left = nullptr;
    right = nullptr;
}

/* Overloaded constructor
 * @param t - value for node
 */
template<class T>
TreeNode<T>::TreeNode(T t) {
    data = t;
    left = nullptr;
    right = nullptr;
}

/* Copy constructor
 * @param obj - object to copy
 */
template<class T>
TreeNode<T>::TreeNode(TreeNode<T> &obj) {
    data = obj.data;
    left = obj.left;
    right = obj.right;
}

/* Default destructor
 */
template<class T>
TreeNode<T>::~TreeNode() {
    delete left;
    delete right;
}

/* Assignment operator
 * @param obj - object to copy
 */
template<class T>
void TreeNode<T>::operator=(TreeNode<T> &obj) {
    data = obj.data;
    left = obj.left;
    right = obj.right;
}

/* Gets the value of the node
 * @return value in node
 */
template<class T>
T TreeNode<T>::getData() {
    return data;
}

/* Sets the value of the node
 * @param v - new value
 */
template<class T>
void TreeNode<T>::setData(T t) {
    data = t;
}

/* Gets the left child of the node
 * @return left child node
 */
template<class T>
TreeNode<T>* TreeNode<T>::getLeft() {
    return left;
}

/* Sets the left child of the node
 * @param n - new node
 */
template<class T>
void TreeNode<T>::setLeft(TreeNode<T>* n) {
    left = n;
}

/* Gets the right child of the node
 * @return right child node
 */
template<class T>
TreeNode<T>* TreeNode<T>::getRight() {
    return right;
}

/* Sets the right child of the node
 * @param n - new node
 */
template<class T>
void TreeNode<T>::setRight(TreeNode<T>* n) {
    right = n;
}

#endif // TREENODE_H
