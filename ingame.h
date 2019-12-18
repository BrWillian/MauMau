#ifndef INGAME_H
#define INGAME_H
#include "node.h"
#include "cartas.h"
#include "insere.h"
#include "listadecir.h"
#include "listec.h"
#include "node.h"
#include "stack.h"
#include <bits/stdc++.h>
using namespace std;

class InGame
{
public:
    int jogadores;
    int partidas;
    Stack<Cartas> Monte, Lixo;
    ListaDECir<ListEC<Cartas> > B;



    Cartas maior(Node<ListEC<Cartas> > * P, int naipe)
    {
        Cartas aux;
        Node<Cartas> * aux1;
        if(naipe == -1)
        {
            if(B.Head->D.Head_P)
            {
                aux = B.Head->D.Head_P->D;

                P->D.EraseMaior(&(B.Head->D.Head_P));
            }
            else
            {
                if(B.Head->D.Head_C)
                {
                    aux = B.Head->D.Head_C->D;
                    P->D.EraseMaior(&(B.Head->D.Head_C));
                }
                else
                {
                    if(B.Head->D.Head_E)
                    {
                        aux = B.Head->D.Head_E->D;
                        P->D.EraseMaior(&(B.Head->D.Head_E));
                    }
                    else
                    {
                        if(B.Head->D.Head_O)
                        {
                            aux = B.Head->D.Head_O->D;
                            P->D.EraseMaior(&(B.Head->D.Head_O));
                        }
                    }
                }
            }

        }
        else
        {

            if(naipe == 0)
            {
                if(B.Head->D.Head_P)
                {
                    aux = B.Head->D.Head_P->D;

                    P->D.EraseMaior(&(B.Head->D.Head_P));
                }
                else
                    aux.naipe = -10;
            }
            if(naipe == 1)
            {
                if(B.Head->D.Head_C)
                {
                    aux = B.Head->D.Head_C->D;

                    P->D.EraseMaior(&(B.Head->D.Head_C));
                }
                else
                    aux.naipe = -10;
            }
            if(naipe == 2)
            {
                if(B.Head->D.Head_E)
                {
                    aux = B.Head->D.Head_E->D;

                    P->D.EraseMaior(&(B.Head->D.Head_E));
                }
                else
                    aux.naipe = -10;
            }
            if(naipe == 3)
            {
                if(B.Head->D.Head_O)
                {
                    aux = B.Head->D.Head_O->D;

                    P->D.EraseMaior(&(B.Head->D.Head_O));
                }
                else
                    aux.naipe = -10;
            }

        }
        return aux;
    }

    bool igual(Node<ListEC<Cartas> > * P,Cartas Cart, Cartas* mao)
    {
        int flag = 1;
        int aux123;
        while(flag != 5)
        {
            if(P->D.Head_P && flag == 1)
            {

                flag = 2;

                Node<Cartas>* aux = NULL;
                Node<Cartas>* aux1 = P->D.Head_P;
                while(aux1 && Cart.valor != aux1->D.valor)
                {
                    aux = aux1;
                    aux1 = aux1->Next;
                }
                if(!aux1){}
                else
                {
                    if(aux)
                    {
                        aux->Next = aux1->Next;
                    }
                    else
                    {
                        P->D.Head_P = aux1->Next;
                    }
                    aux123 = aux1->D.valor;
                    Node<Cartas>::desmontanode(mao,aux1);

                     P->D.score -= (aux123 - 64);
                     P->D.ScoreP -= (aux123 - 64);
                     P->D.qtdP--;
                    return true;
                }


            }
            else
            {
                flag = 2;
            }
            if(P->D.Head_C && flag == 2)
            {
                flag = 3;
                Node<Cartas>* aux = NULL;
                Node<Cartas>* aux1 = P->D.Head_C;
                while(aux1 && Cart.valor != aux1->D.valor)
                {
                    aux = aux1;
                    aux1 = aux1->Next;
                }
                if(!aux1){}
                else
                {
                    if(aux)
                    {
                        aux->Next = aux1->Next;
                    }
                    else
                    {
                        P->D.Head_C = aux1->Next;
                    }
                    aux123 = aux1->D.valor;
                    Node<Cartas>::desmontanode(mao,aux1);

                     P->D.score -= (aux123 - 64);
                     P->D.ScoreC -= (aux123 - 64);
                     P->D.qtdC--;
                    return true;
                }
            }
            else
            {
                flag = 3;
            }
            if(P->D.Head_E && flag == 3)
            {
                flag = 4;
                Node<Cartas>* aux = NULL;
                Node<Cartas>* aux1 = P->D.Head_E;
                while(aux1 && Cart.valor != aux1->D.valor)
                {
                    aux = aux1;
                    aux1 = aux1->Next;
                }
                if(!aux1){}
                else
                {
                    if(aux)
                    {
                        aux->Next = aux1->Next;
                    }
                    else
                    {
                        P->D.Head_E = aux1->Next;
                    }
                    aux123 = aux1->D.valor;
                    Node<Cartas>::desmontanode(mao,aux1);

                     P->D.score -= (aux123 - 64);
                     P->D.ScoreE -= (aux123 - 64);
                     P->D.qtdE--;
                    return true;
                }
            }
            else
            {
                flag = 4;
            }
            if(P->D.Head_O && flag == 4)
            {
                flag = 5;
                Node<Cartas>* aux = NULL;
                Node<Cartas>* aux1 = P->D.Head_O;
                while(aux1 && Cart.valor != aux1->D.valor)
                {
                    aux = aux1;
                    aux1 = aux1->Next;
                }
                if(!aux1){}
                else
                {
                    if(aux)
                    {
                        aux->Next = aux1->Next;
                    }
                    else
                    {
                        P->D.Head_O = aux1->Next;
                    }
                    aux123 = aux1->D.valor;
                    Node<Cartas>::desmontanode(mao,aux1);

                     P->D.score -= (aux123 - 64);
                     P->D.ScoreO -= (aux123 - 64);
                     P->D.qtdO--;
                    return true;
                }
            }
            else
            {
                flag = 5;
            }
        }
        return false;
    }






    bool verifi()
    {
        return B.NumdeJogadores() == 1 ? true : false;
    }
    void compraCarta(ListEC<Cartas>* p1,int x1)
    {

        if(Monte.Topo().valor == Lixo.Topo().valor && !x1)
        {
            Lixo.push(Monte.Topo());
            /*cout<<"Jogador "<<B.Head->D.identiJogador<<" Descartou no Lixo a carta "<<
                  Lixo.Topo().valor<<Lixo.Topo().naipe<<endl;*/
            punir(Monte.Topo());
            Monte.pop();
            B.Proximo();
        }
        else
        {
            if(Monte.Topo().naipe == Lixo.Topo().naipe && !x1)
            {
                Lixo.push(Monte.Topo());
                /*cout<<"Jogador "<<B.Head->D.identiJogador<<" Descartou no Lixo a carta "<<
                      Lixo.Topo().valor<<Lixo.Topo().naipe<<endl;*/
                punir(Monte.Topo());
                Monte.pop();
                B.Proximo();
            }
            else
            {
                int aux = 0;
                if(Monte.Topo().naipe==0)
                {
                    aux = Monte.Topo().valor;
                    p1->InsertCompra(&p1->Head_P,Monte.Topo());
                    p1->score += (aux - 64);
                    p1->ScoreP += (aux - 64);
                    p1->qtdP++;
                }
                if(Monte.Topo().naipe==1)
                {
                    aux = Monte.Topo().valor;
                    p1->InsertCompra(&p1->Head_C,Monte.Topo());
                    p1->score += (aux - 64);
                    p1->ScoreC += (aux - 64);
                    p1->qtdC++;
                }
                if(Monte.Topo().naipe==2)
                {
                    aux = Monte.Topo().valor;
                    p1->InsertCompra(&p1->Head_E,Monte.Topo());
                    p1->score += (aux - 64);
                    p1->ScoreE += (aux - 64);
                    p1->qtdE++;
                }
                if(Monte.Topo().naipe==3)
                {
                    aux = Monte.Topo().valor;
                    p1->InsertCompra(&p1->Head_O,Monte.Topo());
                    p1->score += (aux - 64);
                    p1->ScoreO += (aux - 64);
                    p1->qtdO++;
                }
                //se e carta castigo/estado/neutra
                //

                //punir(Monte.Topo());

                //cout<<" "<<Monte.Topo().valor<<Monte.Topo().naipe<<" ";
                Monte.pop();


            }
        }

    }

    bool punir(Cartas U)
    {
        if(U.valor == 'L' || U.valor == 'A' || U.valor == 'G' || U.valor == 'I')
        {

            if(U.valor == 'L')
            {
                B.MudaSentido();
                //cout<<"Mudou O sentido de ";
                if(B.sentido)
                {
                    //cout<<" Horario to Anti-Horario "<<endl;
                }
                else
                {
                    //cout<<" Anti-Horario to Horario "<<endl;
                }
            }
            else
            {
                if(U.valor == 'A')
                {
                    B.pulaJog();
                    if(B.sentido)
                    {
                        //cout<<"Jogador "<<B.Head->Prev->D.identiJogador<<" foi pulado "<<endl;
                    }
                    else
                    {
                        //cout<<"Jogador "<<B.Head->Next->D.identiJogador<<" foi pulado "<<endl;
                    }

                }
                else
                {
                    if(U.valor == 'G')
                    {
                        //cout<<"Proximo Jogador (Jogador " <<B.Head->Next->D.identiJogador<<" Recebeu +2 Cartas) -> ( "<<endl;
                        if(B.sentido==1)
                        {
                            compraCarta(&B.Head->Prev->D,1);
                            compraCarta(&B.Head->Prev->D,1);
                        }
                        else
                        {
                            compraCarta(&B.Head->Next->D,1);
                            compraCarta(&B.Head->Next->D,1);
                        }
                        //cout<<" )";
                    }
                    else
                    {
                        //cout<<"Jogador Anterior (Jogador " <<B.Head->Next->D.identiJogador<<" Recebeu +3 Cartas) -> (  "<<endl;
                        if(B.sentido==1)
                        {
                            compraCarta(&B.Head->Next->D,1);
                            compraCarta(&B.Head->Next->D,1);
                            compraCarta(&B.Head->Next->D,1);
                        }
                        else
                        {
                            compraCarta(&B.Head->Prev->D,1);
                            compraCarta(&B.Head->Prev->D,1);
                            compraCarta(&B.Head->Prev->D,1);
                        }
                        //cout<<" )";
                    }
                }
            }
            return true;
        }
        return false;
    }



    int getjogadores()
    {
        return B.NumdeJogadores();
    }
    void emJogo()
    {
        int i=1;
        while(B.Head->D.score)
        {
            //cout<<i<<endl;
            i++;
            if(Lixo.isEmpty())
            {

                Lixo.push(maior(B.Head, -1));
                /*cout<<"Jogador "<<B.Head->D.identiJogador<<" Descartou no Lixo a carta "<<
                      Lixo.Topo().valor<<Lixo.Topo().naipe<<endl;*/

                if(!B.Head->D.score)
                    break;
                punir(Lixo.Topo());
                B.Proximo();
            }
            else
            {
                if(Monte.isEmpty())
                {

                    Cartas auxma = Lixo.Topo();
                    Lixo.pop();
                    while(!Lixo.isEmpty())
                    {
                        Monte.push(Lixo.Topo());
                        Lixo.pop();
                    }
                    Lixo.push(auxma);
                }
                Cartas Mao;
                ListaDECir<ListEC<Cartas> > *descart;
                
                

                if(igual(B.Head,Lixo.Topo(),&Mao))
                {
                    // tem uma carta x do naipe n
                    Lixo.push(Mao);
                    if(!B.Head->D.score)
                        break;
                    /*cout<<"Jogador "<<B.Head->D.identiJogador<<" Descartou no Lixo a carta "<<
                          Lixo.Topo().valor<<Lixo.Topo().naipe<<endl;*/
                    punir(Mao);
                    B.Proximo();
                }
                else
                {
                    Mao = maior(B.Head,Lixo.Topo().naipe);

                    if(Mao.naipe!=-10)
                    {
                        //tem uma carta "maior" do mesmo naipe
                        Lixo.push(Mao);

                        /*cout<<"Jogador "<<B.Head->D.identiJogador<<" Descartou no Lixo a carta "<<
                              Lixo.Topo().valor<<Lixo.Topo().naipe<<endl;*/

                        if(!B.Head->D.score)
                            break;
                        punir(Mao);
                        B.Proximo();
                    }
                    else
                    {
                        //compra carta
                        //cout<<"Jogador "<<B.Head->D.identiJogador<<" Comprou 1 carta ( ";
                        compraCarta(&B.Head->D,0);
                        //cout<<" )"<<endl;
                        B.Proximo();
                    }
                }
                
            }
        }

        cout<<"Jogador "<<B.Head->D.identiJogador<<" : Score "<<B.Head->D.score<<" Ganhou a Rodada "<<endl;


    }




    void findMaior()
    {
        int aux=-99999,indenti;
        Node<ListEC<Cartas> > * P = B.Head;
        for(int i=0;i<B.numdeJogadores;i++)
        {
            if(P->D.score > aux)
            {
                aux = P->D.score;
                indenti = P->D.identiJogador;
            }
            P = P->Next;
        }
        ListEC<Cartas> auxxxxxxx;
        cout<<"----------- Inicio Saida de Jogador -----------"<<endl;
        cout<<"Jogador "<<indenti<<" saiu desta Rodada "<<endl;
        cout<<"----------- Fim Saida de Jogador -----------"<<endl;
        B.Erase(&auxxxxxxx,indenti);
    }
    void findMenor()
    {
        int indenti=9999999;
        Node<ListEC<Cartas> > * P = B.Head;
        for(int i=0;i<B.numdeJogadores;i++)
        {
            if(P->D.identiJogador < indenti)
            {
                indenti = P->D.identiJogador;
            }
            P = P->Next;
        }
        B.ordena(indenti);
    }
    void limpa()
    {
        Node<ListEC<Cartas> > ** P = &(B.Head);
        for(int i=0;i<B.numdeJogadores;i++)
        {
            (*P)->D.Limpa();
            P = &((*P)->Next);
        }
    }

};

#endif // INGAME_H
