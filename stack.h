#ifndef STACK_H
#define STACK_H

#include <node.h>
template <class tipo>
class Stack
{
    int Size;
    Node<tipo>* TOP;
public:
    Stack()
    {
        Size = 0;
        TOP = 0;
    }
    bool push(tipo DAT)
    {
        Node<tipo>* P = Node<tipo>::montanode(&DAT);
        if(!P)
        {
            return P;
        }
        P->Next = TOP;
        TOP = P;
        Size++;
        return true;
    }
    bool isEmpty()
    {
        return !TOP;
    }
    bool pop()
    {
        tipo DAT;
        if(!TOP)
        {
            return 0;
        }
        Node<tipo>* P = TOP;
        TOP=TOP->Next;
        Node<tipo>::desmontanode(&DAT,P);
        Size--;
        return true;
    }
    int SIZE()
    {
        return Size;
    }
    tipo Topo()
    {
        return TOP->D;
    }

};

#endif // STACK_H
