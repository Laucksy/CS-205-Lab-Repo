#ifndef STACKNODE_H
#define STACKNODE_H

#endif // STACKNODE_H

template<class T>
class StackNode
{
public:
    StackNode();
    StackNode(T value);
    StackNode(T value, StackNode *next);
    StackNode(StackNode &obj);
    ~StackNode();
    T getvalue();
    StackNode* getNext();
    void setNext(StackNode* next);
private:
    T value;
    StackNode *next;
};

template<class T>
StackNode<T>::StackNode()
{
    value = NULL;
    next = nullptr;
}

template<class T>
StackNode<T>::StackNode(T value)
{
    this->value = value;
}

template<class T>
StackNode<T>::StackNode(T value, StackNode* next)
{
    this->value = value;
    this->next = next;
}

template<class T>
StackNode<T>::StackNode(StackNode &obj)
{
    this->value = obj.value;
    this->next = obj.next;
}

template<class T>
StackNode<T>::~StackNode()
{
   // delete value;
}

template<class T>
T StackNode<T>::getvalue()
{
    return value;
}

template<class T>
StackNode<T>* StackNode<T>::getNext()
{
    return next;
}

template<class T>
void StackNode<T>::setNext(StackNode* next)
{
    this->next = next;
}
