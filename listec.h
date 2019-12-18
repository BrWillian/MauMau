#ifndef LISTEC_H
#define LISTEC_H
#include "node.h"
#include "cartas.h"

#include <bits/stdc++.h>

using namespace std;

template <class tipo>
class ListEC
{
    static void insere(Node<tipo>** L, Node<tipo>* Dat)
    {
        if(!*L)
        {
            Dat->Next = *L;
            *L = Dat;
        }
        else
        {
            while((*L) and ((*L)->D).valor > (Dat->D).valor)
            {
                L=&((*L)->Next);
            }
            Dat->Next = *L;
            *L = Dat;
        }
    }

public:
    int score;
    int NumeroDoJogador;
    int identiJogador;
    Node<tipo>* Head_P;
    Node<tipo>* Head_C;
    Node<tipo>* Head_E;
    Node<tipo>* Head_O;
    int ScoreP, ScoreC, ScoreE,ScoreO;
    int qtdP,   qtdC,   qtdE,  qtdO;
    ListEC()
    {
        Head_P = 0;
        Head_C = 0;
        Head_E = 0;
        Head_O = 0;
        ScoreP = 0;
        ScoreC = 0;
        ScoreE = 0;
        ScoreO = 0;
        NumeroDoJogador = 0;
        score = 0;
        qtdP = qtdC = qtdE = qtdO = 0;
        identiJogador=0;

    }

    bool Empty()
    {
        return !score;
    }
    int Score();
    bool Insert(tipo Dat)
    {
        int aux;
        Node<tipo>* P = Node<tipo>::montanode(&Dat);
        if(!P) return P;

        aux = Dat.valor;

        if(Dat.naipe==0)
        {
            insere(&Head_P,P);
            score += (aux - 64);
            ScoreP += (aux - 64);
            qtdP++;
        }
        if(Dat.naipe==1)
        {
            insere(&Head_C,P);
            score += (aux - 64);
            ScoreC += (aux - 64);
            qtdC++;
        }
        if(Dat.naipe==2)
        {
            insere(&Head_E,P);
            score += (aux - 64);
            ScoreE += (aux - 64);
            qtdE++;
        }
        if(Dat.naipe==3)
        {
            insere(&Head_O,P);
            score += (aux - 64);
            ScoreO += (aux - 64);
            qtdO++;
        }
        return true;
    }
    void Limpa()
    {
        Head_P = 0;
        Head_C = 0;
        Head_E = 0;
        Head_O = 0;
        ScoreP = 0;
        ScoreC = 0;
        ScoreE = 0;
        ScoreO = 0;
        NumeroDoJogador = 0;
        score = 0;
        qtdP = qtdC = qtdE = qtdO = 0;

    }
    void EraseMaior(Node<tipo>** P)
    {

            int aux = (*P)->D.valor;
            Node<tipo> * aux1 = *P;

            
            if((*P)->D.naipe==0)
            {
                score -= (aux - 64);
                ScoreP -= (aux - 64);
                qtdP--;
            }
            if((*P)->D.naipe==1)
            {
                score -= (aux - 64);
                ScoreC -= (aux - 64);
                qtdC--;
            }
            if((*P)->D.naipe==2)
            {
                score -= (aux - 64);
                ScoreE -= (aux - 64);
                qtdE--;
            }
            if((*P)->D.naipe==3)
            {
                score -= (aux - 64);
                ScoreO -= (aux - 64);
                qtdO--;
            }
            (*P) = (*P)->Next;
            tipo aux2;
            Node<tipo>::desmontanode(&aux2,aux1);

    }

    
    void EraseIgual(Node<tipo>* P, Node<tipo>* P1,Node<Cartas> ** P2)
    {
        if(!P1)
        {
            P1 = P->Next;
            *P2 = P1;
        }
        else
        {
            P1 = P->Next;
        }
        tipo aux2;
        Node<tipo>::desmontanode(&aux2,P);
    }

    bool InsertCompra(Node<tipo>** ListCirc, tipo Dat)
    {
        Node<tipo>* P = Node<tipo>::montanode(&Dat);
        if(!P) return P;
        insere(ListCirc,P);
    }

};
#endif // LISTEC_H
