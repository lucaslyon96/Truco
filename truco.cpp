#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
int main(){
    //ouro={0,1,2,3,4,5,6,7,8,9}espada={10,11,12,13,14,15,16,17,18,19}copas={20,21,22,23,24,25,26,27,28,29} jogador%10
    int jogada_do_jogador1=0,jogada_do_jogador2=0,pontos_jogador1=0,pontos_jogador2=0,jogador1[3],jogador2[3],cartas[40],game_jogador1=0,game_jogador2=0,manilha1,manilha2,manilha3,manilha4,vira;
    srand(time(NULL));
    for(int i=0;i<40;i++){
        cartas[i]=i;
    }
    while(game_jogador1!=12&&game_jogador2!=12){//contando o jogo
        //distribui as casrtas e embaralha
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                jogador1[i]=cartas[rand()%40];
                jogador2[i]=cartas[rand()%40];
                while(jogador1[i]==jogador2[j]){//evita cartas repetidas
                    jogador2[j]=cartas[rand()%40];
                }
            }

        }
        //puxando a manilha e o while evita que seja uma carta ja puxada para um dos jogadores
                vira=cartas[rand()%40];
                for(int i=0;i<3;i++){
                    while(vira==jogador1[i]||vira==jogador2[i]){
                        vira=cartas[rand()%40];
                    }
                }
                //declarando a manilha sendo manilha 4 o zap
                    manilha1=vira%10;//use 4 manilhas para o codigo lembrando que o resto da divisao de vira dara a maninha em ouros e somado com dez da em espada e assim sucessivamente
                    manilha2=manilha1+=10;
                    manilha3=manilha2+=10;
                    manilha4=manilha3+=10;
                int cont=0;

                //rodada
                while(pontos_jogador1<2||pontos_jogador2<2||(pontos_jogador1==0&&pontos_jogador2==0)){
                 //escreve a manilha na mesa
                    cout<<"carta vira > ";
                    if(vira<10){
                        if(vira%10==0){
                            cout<<"4 de ouro "<<endl;
                        }
                        else if (vira%10==1){
                            cout<< "5 de ouro "<<endl;
                        }
                        else if (vira%10==2){
                            cout<< "6 de ouro "<<endl;
                        }
                        else if (vira%10==3){
                            cout<< "7 de ouro "<<endl;
                        }
                        else if (vira%10==4){
                            cout<< "dama de ouro "<<endl;
                        }
                        else if (vira%10==5){
                            cout<< "valete de ouro "<<endl;
                        }
                        else if (vira%10==6){
                            cout<< "rei de ouro "<<endl;
                        }
                        else if (vira%10==7){
                            cout<< "As de ouro "<<endl;
                        }
                        else if (vira%10==8){
                            cout<< "2 de ouro "<<endl;
                        }
                        else {
                            cout<< "3 de ouro"<<endl;
                        }
                    }
                    else if(vira>=10&&vira<20){
                        if(vira%10==0){
                            cout<<"4 de espada "<<endl;
                        }
                        else if (vira%10==1){
                            cout<< "5 de espada "<<endl;
                        }
                        else if (vira%10==2){
                            cout<< "6 de espada "<<endl;
                        }
                        else if (vira%10==3){
                            cout<< "7 de espada "<<endl;
                        }
                        else if (vira%10==4){
                            cout<< "dama de espada "<<endl;
                        }
                        else if (vira%10==5){
                            cout<< "valete de espada "<<endl;
                        }
                        else if (vira%10==6){
                            cout<< "rei de espada"<<endl;
                        }
                        else if (vira%10==7){
                            cout<< "As de espada"<<endl;
                        }
                        else if (vira%10==8){
                            cout<< "2 de espada "<<endl;
                        }
                        else {
                            cout<< "3 de espada"<<endl;
                        }
                    }
                    if(vira>=20&&vira<30){
                        if(vira%10==0){
                            cout<< "4 de copa "<<endl;
                        }
                        else if (vira%10==1){
                            cout<< "5 de copa "<<endl;
                        }
                        else if (vira%10==2){
                            cout<< "6 de copa "<<endl;
                        }
                        else if (vira%10==3){
                            cout<< "7 de copa "<<endl;
                        }
                        else if (vira%10==4){
                            cout<< "dama de copa "<<endl;
                        }
                        else if (vira%10==5){
                            cout<< "valete de copa "<<endl;
                        }
                        else if (vira%10==6){
                            cout<< "rei de copa"<<endl;
                        }
                        else if (vira%10==7){
                            cout<< "As de copa"<<endl;
                        }
                        else if (vira%10==8){
                            cout<< "2 de copa "<<endl;
                        }
                        else {
                            cout<< "3 de copa"<<endl;
                        }
                    }
                      if(vira>30){
                        if(vira%10==0){
                            cout<<"4 de paus "<<endl;
                        }
                        else if (vira%10==1){
                            cout<< "5 de paus "<<endl;
                        }
                        else if (vira%10==2){
                            cout<< "6 de paus "<<endl;
                        }
                        else if (vira%10==3){
                            cout<< "7 de paus "<<endl;
                        }
                        else if (vira%10==4){
                            cout<< "dama de paus "<<endl;
                        }
                        else if (vira%10==5){
                            cout<< "valete de paus "<<endl;
                        }
                        else if (vira%10==6){
                            cout<< "rei de paus "<<endl;
                        }
                        else if (vira%10==7){
                            cout<< "As de paus "<<endl;
                        }
                        else if (vira%10==8){
                            cout<< "2 de paus "<<endl;
                        }
                        else {
                            cout<< "3 de paus "<<endl;
                        }
                    }

                cout<< "vez do jogador 1"<<endl;
                cout<< "escolha a carta e digite 1 para a primeira,2 para a segunda e 3 para a terceira"<<endl;

              if(jogada_do_jogador1==0){
                 for(int i=0;i<3;i++){
                    if(jogador1[i]<10){
                        if(jogador1[i]%10==0){
                            cout<<"4 de ouro "<<endl;
                        }
                        else if (jogador1[i]%10==1){
                            cout<< "5 de ouro "<<endl;
                        }
                        else if (jogador1[i]%10==2){
                            cout<< "6 de ouro "<<endl;
                        }
                        else if (jogador1[i]%10==3){
                            cout<< "7 de ouro "<<endl;
                        }
                        else if (jogador1[i]%10==4){
                            cout<< "dama de ouro "<<endl;
                        }
                        else if (jogador1[i]%10==5){
                            cout<< "valete de ouro "<<endl;
                        }
                        else if (jogador1[i]%10==6){
                            cout<< "rei de ouro "<<endl;
                        }
                        else if (jogador1[i]%10==7){
                            cout<< "As de ouro "<<endl;
                        }
                        else if (jogador1[i]%10==8){
                            cout<< "2 de ouro "<<endl;
                        }
                        else {
                            cout<< "3 de ouro"<<endl;
                        }
                    }
                    else if(jogador1[i]>=10&&jogador1[i]<20){
                        if(jogador1[i]%10==0){
                            cout<<"4 de espada "<<endl;
                        }
                        else if (jogador1[i]%10==1){
                            cout<< "5 de espada "<<endl;
                        }
                        else if (jogador1[i]%10==2){
                            cout<< "6 de espada "<<endl;
                        }
                        else if (jogador1[i]%10==3){
                            cout<< "7 de espada "<<endl;
                        }
                        else if (jogador1[i]%10==4){
                            cout<< "dama de espada "<<endl;
                        }
                        else if (jogador1[i]%10==5){
                            cout<< "valete de espada "<<endl;
                        }
                        else if (jogador1[i]%10==6){
                            cout<< "rei de espada"<<endl;
                        }
                        else if (jogador1[i]%10==7){
                            cout<< "As de espada"<<endl;
                        }
                        else if (jogador1[i]%10==8){
                            cout<< "2 de espada "<<endl;
                        }
                        else {
                            cout<< "3 de espada"<<endl;
                        }
                    }
                    if(jogador1[i]>=20&&jogador1[i]<30){
                        if(jogador1[i]%10==0){
                            cout<< "4 de copa "<<endl;
                        }
                        else if (jogador1[i]%10==1){
                            cout<< "5 de copa "<<endl;
                        }
                        else if (jogador1[i]%10==2){
                            cout<< "6 de copa "<<endl;
                        }
                        else if (jogador1[i]%10==3){
                            cout<< "7 de copa "<<endl;
                        }
                        else if (jogador1[i]%10==4){
                            cout<< "dama de copa "<<endl;
                        }
                        else if (jogador1[i]%10==5){
                            cout<< "valete de copa "<<endl;
                        }
                        else if (jogador1[i]%10==6){
                            cout<< "rei de copa"<<endl;
                        }
                        else if (jogador1[i]%10==7){
                            cout<< "As de copa"<<endl;
                        }
                        else if (jogador1[i]%10==8){
                            cout<< "2 de copa "<<endl;
                        }
                        else {
                            cout<< "3 de copa"<<endl;
                        }
                    }
                      if(jogador1[i]>30){
                        if(jogador1[i]%10==0){
                            cout<<"4 de paus "<<endl;
                        }
                        else if (jogador1[i]%10==1){
                            cout<< "5 de paus "<<endl;
                        }
                        else if (jogador1[i]%10==2){
                            cout<< "6 de paus "<<endl;
                        }
                        else if (jogador1[i]%10==3){
                            cout<< "7 de paus "<<endl;
                        }
                        else if (jogador1[i]%10==4){
                            cout<< "dama de paus "<<endl;
                        }
                        else if (jogador1[i]%10==5){
                            cout<< "valete de paus "<<endl;
                        }
                        else if (jogador1[i]%10==6){
                            cout<< "rei de paus "<<endl;
                        }
                        else if (jogador1[i]%10==7){
                            cout<< "As de paus "<<endl;
                        }
                        else if (jogador1[i]%10==8){
                            cout<< "2 de paus "<<endl;
                        }
                        else {
                            cout<< "3 de paus "<<endl;
                        }
                    }
               //}
              }
            }
            if(jogada_do_jogador1==1){
                if(cont==0){
                    aux=3;
                }
                else if(cont==1)
                 for(int i=1;i<aux;i++){
                    if(jogador1[i]<10){
                        if(jogador1[i]%10==0){
                            cout<<"4 de ouro "<<endl;
                        }
                        else if (jogador1[i]%10==1){
                            cout<< "5 de ouro "<<endl;
                        }
                        else if (jogador1[i]%10==2){
                            cout<< "6 de ouro "<<endl;
                        }
                        else if (jogador1[i]%10==3){
                            cout<< "7 de ouro "<<endl;
                        }
                        else if (jogador1[i]%10==4){
                            cout<< "dama de ouro "<<endl;
                        }
                        else if (jogador1[i]%10==5){
                            cout<< "valete de ouro "<<endl;
                        }
                        else if (jogador1[i]%10==6){
                            cout<< "rei de ouro "<<endl;
                        }
                        else if (jogador1[i]%10==7){
                            cout<< "As de ouro "<<endl;
                        }
                        else if (jogador1[i]%10==8){
                            cout<< "2 de ouro "<<endl;
                        }
                        else {
                            cout<< "3 de ouro"<<endl;
                        }
                    }
                    else if(jogador1[i]>=10&&jogador1[i]<20){
                        if(jogador1[i]%10==0){
                            cout<<"4 de espada "<<endl;
                        }
                        else if (jogador1[i]%10==1){
                            cout<< "5 de espada "<<endl;
                        }
                        else if (jogador1[i]%10==2){
                            cout<< "6 de espada "<<endl;
                        }
                        else if (jogador1[i]%10==3){
                            cout<< "7 de espada "<<endl;
                        }
                        else if (jogador1[i]%10==4){
                            cout<< "dama de espada "<<endl;
                        }
                        else if (jogador1[i]%10==5){
                            cout<< "valete de espada "<<endl;
                        }
                        else if (jogador1[i]%10==6){
                            cout<< "rei de espada"<<endl;
                        }
                        else if (jogador1[i]%10==7){
                            cout<< "As de espada"<<endl;
                        }
                        else if (jogador1[i]%10==8){
                            cout<< "2 de espada "<<endl;
                        }
                        else {
                            cout<< "3 de espada"<<endl;
                        }
                    }
                    if(jogador1[i]>=20&&jogador1[i]<30){
                        if(jogador1[i]%10==0){
                            cout<< "4 de copa "<<endl;
                        }
                        else if (jogador1[i]%10==1){
                            cout<< "5 de copa "<<endl;
                        }
                        else if (jogador1[i]%10==2){
                            cout<< "6 de copa "<<endl;
                        }
                        else if (jogador1[i]%10==3){
                            cout<< "7 de copa "<<endl;
                        }
                        else if (jogador1[i]%10==4){
                            cout<< "dama de copa "<<endl;
                        }
                        else if (jogador1[i]%10==5){
                            cout<< "valete de copa "<<endl;
                        }
                        else if (jogador1[i]%10==6){
                            cout<< "rei de copa"<<endl;
                        }
                        else if (jogador1[i]%10==7){
                            cout<< "As de copa"<<endl;
                        }
                        else if (jogador1[i]%10==8){
                            cout<< "2 de copa "<<endl;
                        }
                        else {
                            cout<< "3 de copa"<<endl;
                        }
                    }
                      if(jogador1[i]>30){
                        if(jogador1[i]%10==0){
                            cout<<"4 de paus "<<endl;
                        }
                        else if (jogador1[i]%10==1){
                            cout<< "5 de paus "<<endl;
                        }
                        else if (jogador1[i]%10==2){
                            cout<< "6 de paus "<<endl;
                        }
                        else if (jogador1[i]%10==3){
                            cout<< "7 de paus "<<endl;
                        }
                        else if (jogador1[i]%10==4){
                            cout<< "dama de paus "<<endl;
                        }
                        else if (jogador1[i]%10==5){
                            cout<< "valete de paus "<<endl;
                        }
                        else if (jogador1[i]%10==6){
                            cout<< "rei de paus "<<endl;
                        }
                        else if (jogador1[i]%10==7){
                            cout<< "As de paus "<<endl;
                        }
                        else if (jogador1[i]%10==8){
                            cout<< "2 de paus "<<endl;
                        }
                        else {
                            cout<< "3 de paus "<<endl;
                        }
                    }
               //}
              }
            }


                //mostra a carta jogada na mesa
                cin>>jogada_do_jogador1;

                while (jogada_do_jogador1>3){
                    cout<<"jogada invalida jogue novamente"<<endl;
                    cin>>jogada_do_jogador1;
                }
                 system("cls");
                int i=jogada_do_jogador1-1;//coloca a carta escolida na mesa
                    if(jogador1[i]<10){
                        if(jogador1[i]%10==0){
                            cout<<"4 de ouro "<<endl;
                        }
                        else if (jogador1[i]%10==1){
                            cout<< "5 de ouro "<<endl;
                        }
                        else if (jogador1[i]%10==2){
                            cout<< "6 de ouro "<<endl;
                        }
                        else if (jogador1[i]%10==3){
                            cout<< "7 de ouro "<<endl;
                        }
                        else if (jogador1[i]%10==4){
                            cout<< "dama de ouro "<<endl;
                        }
                        else if (jogador1[i]%10==5){
                            cout<< "valete de ouro "<<endl;
                        }
                        else if (jogador1[i]%10==6){
                            cout<< "rei de ouro "<<endl;
                        }
                        else if (jogador1[i]%10==7){
                            cout<< "As de ouro "<<endl;
                        }
                        else if (jogador1[i]%10==8){
                            cout<< "2 de ouro "<<endl;
                        }
                        else {
                            cout<< "3 de ouro"<<endl;
                        }
                    }
                    else if(jogador1[i]>=10&&jogador1[i]<20){
                        if(jogador1[i]%10==0){
                            cout<<"4 de espada "<<endl;
                        }
                        else if (jogador1[i]%10==1){
                            cout<< "5 de espada "<<endl;
                        }
                        else if (jogador1[i]%10==2){
                            cout<< "6 de espada "<<endl;
                        }
                        else if (jogador1[i]%10==3){
                            cout<< "7 de espada "<<endl;
                        }
                        else if (jogador1[i]%10==4){
                            cout<< "dama de espada "<<endl;
                        }
                        else if (jogador1[i]%10==5){
                            cout<< "valete de espada "<<endl;
                        }
                        else if (jogador1[i]%10==6){
                            cout<< "rei de espada"<<endl;
                        }
                        else if (jogador1[i]%10==7){
                            cout<< "As de espada"<<endl;
                        }
                        else if (jogador1[i]%10==8){
                            cout<< "2 de espada "<<endl;
                        }
                        else {
                            cout<< "3 de espada"<<endl;
                        }
                    }
                    if(jogador1[i]>=20&&jogador1[i]<30){
                        if(jogador1[i]%10==0){
                            cout<< "4 de copa "<<endl;
                        }
                        else if (jogador1[i]%10==1){
                            cout<< "5 de copa "<<endl;
                        }
                        else if (jogador1[i]%10==2){
                            cout<< "6 de copa "<<endl;
                        }
                        else if (jogador1[i]%10==3){
                            cout<< "7 de copa "<<endl;
                        }
                        else if (jogador1[i]%10==4){
                            cout<< "dama de copa "<<endl;
                        }
                        else if (jogador1[i]%10==5){
                            cout<< "valete de copa "<<endl;
                        }
                        else if (jogador1[i]%10==6){
                            cout<< "rei de copa"<<endl;
                        }
                        else if (jogador1[i]%10==7){
                            cout<< "As de copa"<<endl;
                        }
                        else if (jogador1[i]%10==8){
                            cout<< "2 de copa "<<endl;
                        }
                        else {
                            cout<< "3 de copa"<<endl;
                        }
                    }
                      if(jogador1[i]>30){
                        if(jogador1[i]%10==0){
                            cout<<"4 de paus "<<endl;
                        }
                        else if (jogador1[i]%10==1){
                            cout<< "5 de paus "<<endl;
                        }
                        else if (jogador1[i]%10==2){
                            cout<< "6 de paus "<<endl;
                        }
                        else if (jogador1[i]%10==3){
                            cout<< "7 de paus "<<endl;
                        }
                        else if (jogador1[i]%10==4){
                            cout<< "dama de paus "<<endl;
                        }
                        else if (jogador1[i]%10==5){
                            cout<< "valete de paus "<<endl;
                        }
                        else if (jogador1[i]%10==6){
                            cout<< "rei de paus "<<endl;
                        }
                        else if (jogador1[i]%10==7){
                            cout<< "As de paus "<<endl;
                        }
                        else if (jogador1[i]%10==8){
                            cout<< "2 de paus "<<endl;
                        }
                        else {
                            cout<< "3 de paus "<<endl;
                        }
                    }
                 //escreve a manilha na mesa
                    cout<< "carta vira > ";
                    if(vira<10){
                        if(vira%10==0){
                            cout<<"4 de ouro "<<endl;
                        }
                        else if (vira%10==1){
                            cout<< "5 de ouro "<<endl;
                        }
                        else if (vira%10==2){
                            cout<< "6 de ouro "<<endl;
                        }
                        else if (vira%10==3){
                            cout<< "7 de ouro "<<endl;
                        }
                        else if (vira%10==4){
                            cout<< "dama de ouro "<<endl;
                        }
                        else if (vira%10==5){
                            cout<< "valete de ouro "<<endl;
                        }
                        else if (vira%10==6){
                            cout<< "rei de ouro "<<endl;
                        }
                        else if (vira%10==7){
                            cout<< "As de ouro "<<endl;
                        }
                        else if (vira%10==8){
                            cout<< "2 de ouro "<<endl;
                        }
                        else {
                            cout<< "3 de ouro"<<endl;
                        }
                    }
                    else if(vira>=10&&vira<20){
                        if(vira%10==0){
                            cout<<"4 de espada "<<endl;
                        }
                        else if (vira%10==1){
                            cout<< "5 de espada "<<endl;
                        }
                        else if (vira%10==2){
                            cout<< "6 de espada "<<endl;
                        }
                        else if (vira%10==3){
                            cout<< "7 de espada "<<endl;
                        }
                        else if (vira%10==4){
                            cout<< "dama de espada "<<endl;
                        }
                        else if (vira%10==5){
                            cout<< "valete de espada "<<endl;
                        }
                        else if (vira%10==6){
                            cout<< "rei de espada"<<endl;
                        }
                        else if (vira%10==7){
                            cout<< "As de espada"<<endl;
                        }
                        else if (vira%10==8){
                            cout<< "2 de espada "<<endl;
                        }
                        else {
                            cout<< "3 de espada"<<endl;
                        }
                    }
                    if(vira>=20&&vira<30){
                        if(vira%10==0){
                            cout<< "4 de copa "<<endl;
                        }
                        else if (vira%10==1){
                            cout<< "5 de copa "<<endl;
                        }
                        else if (vira%10==2){
                            cout<< "6 de copa "<<endl;
                        }
                        else if (vira%10==3){
                            cout<< "7 de copa "<<endl;
                        }
                        else if (vira%10==4){
                            cout<< "dama de copa "<<endl;
                        }
                        else if (vira%10==5){
                            cout<< "valete de copa "<<endl;
                        }
                        else if (vira%10==6){
                            cout<< "rei de copa"<<endl;
                        }
                        else if (vira%10==7){
                            cout<< "As de copa"<<endl;
                        }
                        else if (vira%10==8){
                            cout<< "2 de copa "<<endl;
                        }
                        else {
                            cout<< "3 de copa"<<endl;
                        }
                    }
                      if(vira>30){
                        if(vira%10==0){
                            cout<<"4 de paus "<<endl;
                        }
                        else if (vira%10==1){
                            cout<< "5 de paus "<<endl;
                        }
                        else if (vira%10==2){
                            cout<< "6 de paus "<<endl;
                        }
                        else if (vira%10==3){
                            cout<< "7 de paus "<<endl;
                        }
                        else if (vira%10==4){
                            cout<< "dama de paus "<<endl;
                        }
                        else if (vira%10==5){
                            cout<< "valete de paus "<<endl;
                        }
                        else if (vira%10==6){
                            cout<< "rei de paus "<<endl;
                        }
                        else if (vira%10==7){
                            cout<< "As de paus "<<endl;
                        }
                        else if (vira%10==8){
                            cout<< "2 de paus "<<endl;
                        }
                        else {
                            cout<< "3 de paus "<<endl;
                        }
                    }

                cout<< "vez do jogador 2"<<endl;
                cout<< "escolha a carta e digite 1 para a primeira,2 para a segunda e 3 para a terceira"<<endl;
                for(int i=0;i<3;i++){


                    if(jogador2[i]<10){
                        if(jogador2[i]%10==0){
                            cout<<"4 de ouro "<<endl;
                        }
                        else if (jogador2[i]%10==1){
                            cout<< "5 de ouro "<<endl;
                        }
                        else if (jogador2[i]%10==2){
                            cout<< "6 de ouro "<<endl;
                        }
                        else if (jogador2[i]%10==3){
                            cout<< "7 de ouro "<<endl;
                        }
                        else if (jogador2[i]%10==4){
                            cout<< "dama de ouro "<<endl;
                        }
                        else if (jogador2[i]%10==5){
                            cout<< "valete de ouro "<<endl;
                        }
                        else if (jogador2[i]%10==6){
                            cout<< "rei de ouro "<<endl;
                        }
                        else if (jogador2[i]%10==7){
                            cout<< "As de ouro "<<endl;
                        }
                        else if (jogador2[i]%10==8){
                            cout<< "2 de ouro "<<endl;
                        }
                        else {
                            cout<< "3 de ouro"<<endl;
                        }
                    }
                    else if(jogador2[i]>=10&&jogador2[i]<20){
                        if(jogador2[i]%10==0){
                            cout<<"4 de espada "<<endl;
                        }
                        else if (jogador2[i]%10==1){
                            cout<< "5 de espada "<<endl;
                        }
                        else if (jogador2[i]%10==2){
                            cout<< "6 de espada "<<endl;
                        }
                        else if (jogador2[i]%10==3){
                            cout<< "7 de espada "<<endl;
                        }
                        else if (jogador2[i]%10==4){
                            cout<< "dama de espada "<<endl;
                        }
                        else if (jogador2[i]%10==5){
                            cout<< "valete de espada "<<endl;
                        }
                        else if (jogador2[i]%10==6){
                            cout<< "rei de espada"<<endl;
                        }
                        else if (jogador2[i]%10==7){
                            cout<< "As de espada"<<endl;
                        }
                        else if (jogador2[i]%10==8){
                            cout<< "2 de espada "<<endl;
                        }
                        else {
                            cout<< "3 de espada"<<endl;
                        }
                    }
                    if(jogador2[i]>=20&&jogador2[i]<30){
                        if(jogador2[i]%10==0){
                            cout<< "4 de copa "<<endl;
                        }
                        else if (jogador2[i]%10==1){
                            cout<< "5 de copa "<<endl;
                        }
                        else if (jogador2[i]%10==2){
                            cout<< "6 de copa "<<endl;
                        }
                        else if (jogador2[i]%10==3){
                            cout<< "7 de copa "<<endl;
                        }
                        else if (jogador2[i]%10==4){
                            cout<< "dama de copa "<<endl;
                        }
                        else if (jogador2[i]%10==5){
                            cout<< "valete de copa "<<endl;
                        }
                        else if (jogador2[i]%10==6){
                            cout<< "rei de copa"<<endl;
                        }
                        else if (jogador2[i]%10==7){
                            cout<< "As de copa"<<endl;
                        }
                        else if (jogador2[i]%10==8){
                            cout<< "2 de copa "<<endl;
                        }
                        else {
                            cout<< "3 de copa"<<endl;
                        }
                    }
                      if(jogador1[i]>30){
                        if(jogador2[i]%10==0){
                            cout<<"4 de paus "<<endl;
                        }
                        else if (jogador2[i]%10==1){
                            cout<< "5 de paus "<<endl;
                        }
                        else if (jogador2[i]%10==2){
                            cout<< "6 de paus "<<endl;
                        }
                        else if (jogador2[i]%10==3){
                            cout<< "7 de paus "<<endl;
                        }
                        else if (jogador2[i]%10==4){
                            cout<< "dama de paus "<<endl;
                        }
                        else if (jogador2[i]%10==5){
                            cout<< "valete de paus "<<endl;
                        }
                        else if (jogador2[i]%10==6){
                            cout<< "rei de paus "<<endl;
                        }
                        else if (jogador2[i]%10==7){
                            cout<< "As de paus "<<endl;
                        }
                        else if (jogador2[i]%10==8){
                            cout<< "2 de paus "<<endl;
                        }
                        else {
                            cout<< "3 de paus "<<endl;
                        }
                    }
               }
                }
                //mostra a carta jogada na mesa
                cin>>jogada_do_jogador2;
                system("cls");
                 while (jogada_do_jogador2>3){
                    cout<<"jogada invalida jogue novamente"<<endl;
                    cin>>jogada_do_jogador2;
                }
               int  i=jogada_do_jogador2-1;
                    if(jogador2[i]<10){
                        if(jogador2[i]%10==0){
                            cout<<"4 de ouro "<<endl;
                        }
                        else if (jogador2[i]%10==1){
                            cout<< "5 de ouro "<<endl;
                        }
                        else if (jogador2[i]%10==2){
                            cout<< "6 de ouro "<<endl;
                        }
                        else if (jogador2[i]%10==3){
                            cout<< "7 de ouro "<<endl;
                        }
                        else if (jogador2[i]%10==4){
                            cout<< "dama de ouro "<<endl;
                        }
                        else if (jogador2[i]%10==5){
                            cout<< "valete de ouro "<<endl;
                        }
                        else if (jogador2[i]%10==6){
                            cout<< "rei de ouro "<<endl;
                        }
                        else if (jogador2[i]%10==7){
                            cout<< "As de ouro "<<endl;
                        }
                        else if (jogador2[i]%10==8){
                            cout<< "2 de ouro "<<endl;
                        }
                        else {
                            cout<< "3 de ouro"<<endl;
                        }
                    }
                    else if(jogador2[i]>=10&&jogador2[i]<20){
                        if(jogador2[i]%10==0){
                            cout<<"4 de espada "<<endl;
                        }
                        else if (jogador2[i]%10==1){
                            cout<< "5 de espada "<<endl;
                        }
                        else if (jogador2[i]%10==2){
                            cout<< "6 de espada "<<endl;
                        }
                        else if (jogador2[i]%10==3){
                            cout<< "7 de espada "<<endl;
                        }
                        else if (jogador2[i]%10==4){
                            cout<< "dama de espada "<<endl;
                        }
                        else if (jogador2[i]%10==5){
                            cout<< "valete de espada "<<endl;
                        }
                        else if (jogador2[i]%10==6){
                            cout<< "rei de espada"<<endl;
                        }
                        else if (jogador2[i]%10==7){
                            cout<< "As de espada"<<endl;
                        }
                        else if (jogador2[i]%10==8){
                            cout<< "2 de espada "<<endl;
                        }
                        else {
                            cout<< "3 de espada"<<endl;
                        }
                    }
                    if(jogador2[i]>=20&&jogador2[i]<30){
                        if(jogador2[i]%10==0){
                            cout<< "4 de copa "<<endl;
                        }
                        else if (jogador2[i]%10==1){
                            cout<< "5 de copa "<<endl;
                        }
                        else if (jogador2[i]%10==2){
                            cout<< "6 de copa "<<endl;
                        }
                        else if (jogador2[i]%10==3){
                            cout<< "7 de copa "<<endl;
                        }
                        else if (jogador2[i]%10==4){
                            cout<< "dama de copa "<<endl;
                        }
                        else if (jogador2[i]%10==5){
                            cout<< "valete de copa "<<endl;
                        }
                        else if (jogador2[i]%10==6){
                            cout<< "rei de copa"<<endl;
                        }
                        else if (jogador2[i]%10==7){
                            cout<< "As de copa"<<endl;
                        }
                        else if (jogador2[i]%10==8){
                            cout<< "2 de copa "<<endl;
                        }
                        else {
                            cout<< "3 de copa"<<endl;
                        }
                    }
                    if(jogador2[i]>30){
                        if(jogador2[i]%10==0){
                            cout<<"4 de paus "<<endl;
                        }
                        else if (jogador2[i]%10==1){
                            cout<< "5 de paus "<<endl;
                        }
                        else if (jogador2[i]%10==2){
                            cout<< "6 de paus "<<endl;
                        }
                        else if (jogador2[i]%10==3){
                            cout<< "7 de paus "<<endl;
                        }
                        else if (jogador2[i]%10==4){
                            cout<< "dama de paus "<<endl;
                        }
                        else if (jogador2[i]%10==5){
                            cout<< "valete de paus "<<endl;
                        }
                        else if (jogador2[i]%10==6){
                            cout<< "rei de paus "<<endl;
                        }
                        else if (jogador2[i]%10==7){
                            cout<< "As de paus "<<endl;
                        }
                        else if (jogador2[i]%10==8){
                            cout<< "2 de paus "<<endl;
                        }
                        else {
                            cout<< "3 de paus "<<endl;
                        }
                    }
                    int flag=0,mao_jogador1=0,mao_jogador2=0;
                    if((jogador1[i]%10)>(jogador2[i]%10)){
                        mao_jogador1+=1;
                        cout<< "jogador 1 ganhou essa mao"<<endl;
                    }
                    else if(jogador1[i]%10==jogador2[i]%10){
                        cout<<"melo"<<endl;
                        flag++;
                    }
                    else{
                        mao_jogador2+=1;
                        cout<< "jogador 2 ganhou essa mao"<<endl;
                    }
                    if(flag==1||flag==2){
                        if(mao_jogador1==1){
                            mao_jogador1=2;
                        }
                        else if(mao_jogador2==1){
                            mao_jogador2=2;
                        }


                    }
                    else if (flag==3){
                        cout<< "jogo empatado,ninguem ganha ponto"<<endl;
                    }
                    if (mao_jogador1==2){
                        cout<<"jogador 1 ganhou um ponto "<<endl;
                        pontos_jogador1+=1;
                    }
                    else if (mao_jogador2==2){
                        cout<< "jogador 2 ganhou um ponto "<<endl;
                        pontos_jogador2+=1;
                    }


                }//while da rodada

                game_jogador1+=pontos_jogador1;
                game_jogador2+=pontos_jogador2;
                pontos_jogador1=0;
                pontos_jogador2=0;


    }



