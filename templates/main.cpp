#include "iostream"
#include "tree.h"
#include "stack.h"

using namespace std;

void tree_tests();
void stack_tests();

int main(int argc, char *argv[])
{
    stack_tests();
    //tree_tests();
    return 0;
}

void stack_tests(){
    Stack<int> *stack = new Stack<int>();
    StackNode<int> *testNode;
    StackNode<int> *test2Node;

    //Test base nodes
    testNode = new StackNode<int>(6);
    test2Node = new StackNode<int>(5, testNode);
    cout << test2Node->getvalue() << "\n";
    cout << test2Node->getNext()->getvalue() << "\n";
    delete testNode;
    delete test2Node;

    //Test adding existing node to stack
    stack = new Stack<int>();
    testNode = new StackNode<int>(6);
    stack->push(testNode);
    cout << stack->peek()->getvalue() << "\n";

    //Test adding value to stack
    stack = new Stack<int>();
    stack->push(5);
    stack->push(7);
    cout << stack->peek()->getvalue() << "\n"; // peek at top (7)
    cout << stack->pop()->getvalue() << "\n"; // pop top (7)
    cout << stack->pop()->getvalue() << "\n"; // pop top (5)

}

void tree_tests() {
    Tree<int> *tree = new Tree<int>();

    //Test empty cases
    cout << "TEST EMPTY CASES" << endl;
    tree->clear();
    cout << "Contains 4 - " << tree->contains(4) << endl;
    cout << "First - " << tree->first() << endl;
    cout << "Get Node 4 - " << tree->getNode(4) << endl;
    cout << "Is Empty - " << tree->isEmpty() << endl;
    cout << "Last - " << tree->last() << endl;
    cout << "Remove 4 - " << tree->remove(4) << endl;
    cout << "Size - " << tree->size() << endl;
    cout << tree->traversal() << endl;

    cout << endl << endl << endl;

    //Test only root cases
    cout << "TEST ONLY ROOT CASES" << endl;
    cout << "Add 4 - " <<  tree->add(4) << endl;
    cout << "Contains 4 - " << tree->contains(4) << endl;
    cout << "First - " << tree->first() << endl;
    cout << "Get Node 4 - " << tree->getNode(4) << endl;
    cout << "Is Empty - " << tree->isEmpty() << endl;
    cout << "Last - " << tree->last() << endl;
    cout << "Size - " << tree->size() << endl;
    cout << tree->traversal() << endl;
    cout << "Remove 4 - " << tree->remove(4) << endl;
    cout << "Size after removal - " << tree->size() << endl;

    cout << endl << endl << endl;

    //Test miscellaneous cases
    cout << "TEST MISCELLANEOUS CASES" << endl;
    cout << "Add 4 - " <<  tree->add(4) << endl;
    cout << "Contains 4 - " << tree->contains(4) << endl;
    cout << "Add 4 again - " <<  tree->add(4) << endl;
    cout << "Contains 4 - " << tree->contains(4) << endl;
    cout << "Add -1 - " <<  tree->add(-1) << endl;
    cout << "Contains -1 - " << tree->contains(-1) << endl;
    cout << "Contains 5 - " << tree->contains(5) << endl;
    cout << "Get Node 5 - " << tree->getNode(5) << endl;
    cout << "Remove 5 - " << tree->remove(5) << endl;
    cout << "Size - " << tree->size() << endl;
    cout << tree->traversal() << endl;
    tree->clear();
    cout << "Size after clear - " << tree->size() << endl;
    cout << "Is Empty - " << tree->isEmpty() << endl;

    cout << endl << endl << endl;

    //Test cases with medium trees
    cout << "TEST CASES WITH MEDIUM TREES" << endl;
    cout << "Add 4 - " <<  tree->add(4) << endl;
    cout << "Add 2 - " <<  tree->add(2) << endl;
    cout << "First - " << tree->first() << endl;

    cout << tree->traversal() << endl;
    cout << "Remove 2 - " << tree->remove(2) << endl;
    cout << tree->traversal() << endl;
    cout << "Add 6 - " <<  tree->add(6) << endl;
    cout << "Last - " << tree->last() << endl;

    cout << "Add 2 - " <<  tree->add(2) << endl;
    cout << "Add 1 - " <<  tree->add(1) << endl;
    cout << "Add 3 - " <<  tree->add(3) << endl;
    cout << "Add 5 - " <<  tree->add(5) << endl;
    cout << "Add 7 - " <<  tree->add(7) << endl;
    cout << "Add 6 - " <<  tree->add(6) << endl;
    cout << "Contains 3 - " << tree->contains(3) << endl;
    cout << "First - " << tree->first() << endl;
    cout << "Last - " << tree->last() << endl;
    cout << "Size - " << tree->size() << endl;
    cout << "Is Empty - " << tree->isEmpty() << endl;
    cout << tree->traversal() << endl;
    tree->clear();
    cout << "Size after clear - " << tree->size() << endl;
    cout << "Is Empty - " << tree->isEmpty() << endl;

    cout << endl << endl << endl;

    //Test cases for big trees
    cout << "TEST CASES FOR BIG TREES" << endl;
    cout << "Add 8 - " <<  tree->add(8) << endl;
    cout << "Add 4 - " <<  tree->add(4) << endl;
    cout << "Add 12 - " <<  tree->add(12) << endl;
    cout << "Add 2 - " <<  tree->add(2) << endl;
    cout << "Add 6 - " <<  tree->add(6) << endl;
    cout << "Add 10 - " <<  tree->add(10) << endl;
    cout << "Add 14 - " <<  tree->add(14) << endl;
    cout << "Add 1 - " <<  tree->add(1) << endl;
    cout << "Add 3 - " <<  tree->add(3) << endl;
    cout << "Add 5 - " <<  tree->add(5) << endl;
    cout << "Add 7 - " <<  tree->add(7) << endl;
    cout << "Add 9 - " <<  tree->add(9) << endl;
    cout << "Add 11 - " <<  tree->add(11) << endl;
    cout << "Add 13 - " <<  tree->add(13) << endl;
    cout << "Add 15 - " <<  tree->add(15) << endl;
    cout << tree->traversal() << endl;
    cout << "Remove 8 - " << tree->remove(8) << endl;
    cout << tree->traversal() << endl;
    cout << "Remove 12 - " << tree->remove(12) << endl;
    cout << tree->traversal() << endl;
    cout << "Remove 3 - " << tree->remove(5) << endl;
    cout << tree->traversal() << endl;
    cout << "Remove 5 - " << tree->remove(3) << endl;
    cout << tree->traversal() << endl;
    cout << "Remove 4 - " << tree->remove(4) << endl;
    cout << tree->traversal() << endl;
    cout << "Remove 1 - " << tree->remove(1) << endl;
    cout << tree->traversal() << endl;
    cout << "Remove 2 - " << tree->remove(2) << endl;
    cout << tree->traversal() << endl;
    cout << "Remove 10 - " << tree->remove(10) << endl;
    cout << tree->traversal() << endl;
    cout << "Remove 13 - " << tree->remove(13) << endl;
    cout << tree->traversal() << endl;
    cout << "Remove 7 - " << tree->remove(7) << endl;
    cout << tree->traversal() << endl;
    cout << "Remove 14 - " << tree->remove(14) << endl;
    cout << tree->traversal() << endl;
    cout << "Remove 11 - " << tree->remove(11) << endl;
    cout << tree->traversal() << endl;
    cout << "Remove 9 - " << tree->remove(9) << endl;
    cout << tree->traversal() << endl;
    cout << "Remove 6 - " << tree->remove(6) << endl;
    cout << tree->traversal() << endl;
    cout << "Remove 15 - " << tree->remove(15) << endl;
    cout << tree->traversal() << endl;
}
