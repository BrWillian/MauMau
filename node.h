#ifndef NODE_H
#define NODE_H
#include <bits/stdc++.h>
template <class temp>
class Node
{
public:
   temp D;
   Node <temp> *Next;
   Node <temp> *Prev;
   static Node <temp> *montanode(temp *dat)
   {
       Node <temp> *P = new Node<temp>;
       if(P)
       {
           P->D = *dat;
           P->Next = P->Prev = NULL;
       }
       return P;
   }

   static void desmontanode(temp *dat, Node<temp> *P)
   {
       if(P)
       {
           *dat = P->D;
           delete P;
       }
   }

};



#endif // NODE_H
