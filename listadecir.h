#ifndef LISTADECIR_H
#define LISTADECIR_H
#include "node.h"
#include "listec.h"
#include "cartas.h"

template <class tipo>
class ListaDECir
{

public:
    Node<tipo>* Head;
    int numdeJogadores;
    int sentido;
    int contadorProx;

    ListaDECir()
    {
        Head = 0;
        numdeJogadores = 0;
        sentido = 1; // 1 = sentido Horario : 0 = sentido Anti-Horario
        contadorProx=1;
    }
    bool Empty()
    {
        return !Head;
    }
    bool NumdeJogadores()
    {
        return numdeJogadores;
    }
    void pulaJog()
    {
        contadorProx++;
    }
    void Proximo()
    {
        for(int i=0;i<contadorProx;i++)
        {
            if(!sentido)
                Head = Head->Next;
            else
                Head = Head->Prev;
        }
        contadorProx=1;
    }
    void MudaSentido()
    {
        if(!sentido)
        {
            sentido = 1;
        }
        else
        {
            sentido = 0;
        }
    }
    bool Insert(tipo *dat)
    {
        Node<tipo> *P = Node<tipo>::montanode(dat);
        if(!P)
            return false;
        if(!Head)
        {
            Head = P->Next = P->Prev = P;
        }
        else
        {
            P->Next = Head;
            P->Prev = Head->Prev;
            (P->Prev)->Next = P;
            Head->Prev = P;
            Head = P;
        }
        numdeJogadores++;
        return true;
    }

    void ordena(int order1)
    {
        while(Head->D.identiJogador != order1)
        {
            Head = Head->Next;
        }
    }

    bool Erase(tipo* Dat, int K)
        {
            if(!Head) return false;
            Node<tipo>* P = Head;
            while(P->Next!=Head and (P->D).identiJogador != K)
            {
                P = P->Next;
            }
            if((P->D).identiJogador==K)
            {
                if(numdeJogadores==1)
                {
                    Head = NULL;
                }
                else
                {
                    (P->Next)->Prev=(P->Prev);
                    (P->Prev)->Next=(P->Next);
                    if(Head == P)
                    {
                        Head = P->Next;
                    }
                }
                Node<tipo>::desmontanode(Dat,P);
                numdeJogadores--;
                return true;
            }
            return false;
        }


};

#endif // LISTADECIR_H
