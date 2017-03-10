#ifndef STACK_H
#define STACK_H

#include "stacknode.h"

template<class T>
class Stack
{
public:
    Stack();
    Stack(Stack &obj);
    ~Stack();

    int getSize();

    StackNode<T>* peek();
    StackNode<T>* pop();
    void push(StackNode<T> *node);
    void push(T value);

private:
    int size;
    StackNode<T>* topNode;
};

template<class T>
Stack<T>::Stack()
{
    size = 0;
}

template<class T>
Stack<T>::Stack(Stack &obj)
{
    this->size = obj.size;
    this->topNode = obj.topNode;
}

template<class T>
Stack<T>::~Stack()
{

}

template<class T>
StackNode<T>* Stack<T>::peek()
{
    if(size == 0)
    {
        return nullptr;
    }
    return topNode;
}

template<class T>
StackNode<T>* Stack<T>::pop()
{
    if(size == 0)
    {
      return nullptr;
    }else{
        size -= 1;
        StackNode<T>* top = new StackNode<T>(*topNode);
        topNode = topNode->getNext();
        return top;
    }
}

template<class T>
void Stack<T>::push(StackNode<T>* node)
{
    size += 1;
    node->setNext(topNode);
    topNode = node;
}

template<class T>
void Stack<T>::push(T value)
{
    size += 1;
    //StackNode<T> node = new StackNode<T>(value, &topNode);
    topNode = new StackNode<T>(value, topNode);
    //topNode = node;
}

template<class T>
int Stack<T>::getSize()
{
    return size;
}

#endif // STACK_H
