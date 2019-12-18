#include <bits/stdc++.h>
#include "listadecir.h"
#include "listec.h"
#include "stack.h"
#include "cartas.h"
#include "ingame.h"
using namespace std;

void leia(InGame* Partidas1,int p, int jogadores)
{



    char aux1;
    int aux2;

    ListEC<Cartas> aux;

    for(int i=1,j=1, jog=1;i<=104;i++,j++)
    {
        cin>>aux1;
        cin>>aux2;
        Cartas aux3;
        if(i<=(jogadores*5))
        {

            if(j<=5)
            {

                    aux3.naipe=aux2;
                    aux3.valor=aux1;
                    aux.Insert(aux3);

            }
            if(j==5)
            {
                aux.identiJogador = jog;
                jog++;
                Partidas1->B.Insert(&aux);
                j = 0;
                aux.Limpa();
            }
        }
        else
        {
            aux3.naipe=aux2;
            aux3.valor=aux1;
            Partidas1->Monte.push(aux3);
        }


    }
}
void leia1(InGame* Partidas1, int jogadores)
{



    char aux1;
    int aux2;

    for(int i=1,j=1, jog=1;i<=104;i++,j++)
    {
        cin>>aux1;
        cin>>aux2;
        Cartas aux3;
        if(i<=(jogadores*5))
        {

            if(j<=5)
            {

                    aux3.naipe=aux2;
                    aux3.valor=aux1;
                    Partidas1->B.Head->D.Insert(aux3);

            }
            if(j==5)
            {
                jog++;
                Partidas1->B.Head= Partidas1->B.Head->Next;
                j = 0;
            }
        }
        else
        {
            aux3.naipe=aux2;
            aux3.valor=aux1;
            Partidas1->Monte.push(aux3);
        }


    }
}

int main()
{

    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    int partidas;
    cin>>partidas;
    int cont = 1;
    while(partidas--)
    {
        cout<<"-------- INICIO DA PARTIDA "<<cont<<" ---------"<<endl<<endl<<endl<<endl
              <<endl<<endl<<endl;
        int jogadores;
        cin>>jogadores;


        InGame Partidas;
        leia(&Partidas,1,jogadores);
        Partidas.partidas = partidas;
        Partidas.jogadores = jogadores;
        Partidas.B.Head= Partidas.B.Head->Prev;
        while(Partidas.B.numdeJogadores != 1)
        {
            Partidas.emJogo();
            Partidas.findMaior();
            Partidas.findMenor();
            Partidas.limpa();
            if(Partidas.B.numdeJogadores>1)
                leia1(&Partidas,Partidas.B.numdeJogadores);

        }
        cout<<endl<<endl<<"Jogador "<<Partidas.B.Head->D.identiJogador<<" Ganhou! a Partida!"<<endl<<endl<<endl;
        cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"-------- FINAL DA PARTIDA "
           <<cont<<" ---------"; cont++;

    }
}
