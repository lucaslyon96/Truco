#include<iostream>
#include<ctime>
#include<cstdlib>
#include<unistd.h>
using namespace std;
int main()
{
    char inicia,truco1,truco2,continua,testesenha1[10],senha1[10],senha2[10],testesenha2[10],escreve[7],valor[40]= {'4','5','6','7','Q','J','K','A','2','3','4','5','6','7','Q','J','K','A','2','3','4','5','6','7','Q','J','K','A','2','3','4','5','6','7','Q','J','K','A','2','3'},naipe[40]= {'O','O','O','O','O','O','O','O','O','O','E','E','E','E','E','E','E','E','E','E','C','C','C','C','C','C','C','C','C','C','P','P','P','P','P','P','P','P','P','P'};
    //  0   1   2   3   4   5   6   7   8   9   10  11  12  13  14  15  16  17  18  19  20  21  22  23  24  25  26  27  28  29  30  31  32  33  34  35  36  37  38  39          //  0   1   2   3   4   5   6   7   8   9   10  11  12  13  14  15  16  17  18  19  20  21  22  23  24  25  26  27  28  29  30  31  32  33  34  35  36  37  38  39
    srand(time(NULL));
    int soma=0,flagtruco=0,jatrucado=0,contvitoria=0,vitoria1=0,truco=0,verifica1=0,verifica2=0,tamanho1=0,tamanho2=0, vez=0,empate=0,jogada1,cartas_jogador1[3],cartas_jogador2[3],jogada2,vira,manilha[4],pontos_jogador1=0,pontos_jogador2=0,mao1=0,mao2=0;
    cout<<"     BEM VINDO AO "<<endl;
    cout<<".------..------..------..------..------."<<endl;
    cout<<"|T.--. ||R.--. ||U.--. ||C.--. ||O.--. |"<<endl;
    cout<<"| :/\\: || :(): || (\\/) || :/\\: || :/\\: |"<<endl;
    cout<<"| (__) || ()() || :\\/: || :\\/: || :\\/: |"<<endl;
    cout<<"| '--'T|| '--'R|| '--'U|| '--'C|| '--'O|"<<endl;
    cout<<"`------'`------'`------'`------'`------'"<<endl;

    cout<<"         PARA INICIAR O JOGO DIGITE QUALQUER CARACTERE OU 'm' PARA JOGAR CONTRA A MAQUINA "<<endl;

    cin>>inicia;
    if (inicia=='m')
    {
        cout<<"jogador 2 agora eh uma maquina "<<endl;
    }


    system("clear");


    while(pontos_jogador1<12&&pontos_jogador2<12)
    {
        int teste[40]= {0};
        vira=rand()%40;
        teste[vira]=1;
        cout<<vira<<endl;
        //distribuicao
        for(int i=0; i<3; i++)
        {
            cartas_jogador1[i]=rand()%40;
            while(teste[cartas_jogador1[i]]!=0)
            {
                cartas_jogador1[i]=rand()%40;
            }
            teste[cartas_jogador1[i]]=1;

            cartas_jogador2[i]=rand()%40;
            while(teste[cartas_jogador2[i]]!=0)
            {
                cartas_jogador2[i]=rand()%40;
            }
            teste[cartas_jogador2[i]]=1;
        }

        manilha[0]=(vira+1)%10;
        manilha[1]=manilha[0]+10;
        manilha[2]=manilha[1]+10;
        manilha[3]=manilha[2]+10;
        mao1=0;
        mao2=0;
        empate=0;
        system("clear");
        truco=0;
        flagtruco=0;
        jatrucado=0;

        while(mao1<2&&mao2<2||empate==2)
        {
            cout<< "PLACAR :"<<endl;
            cout<<"jogador 1 = "<<pontos_jogador1<<"   jogador 2 = "<<pontos_jogador2<<endl;
            cout<<"\tcarta vira :"<<endl;
            if(naipe[vira]=='P')
            {
                escreve[0]='P';
                escreve[1]='a';
                escreve[2]='u';
                escreve[3]='s';
                escreve[4]='\0';

                cout<<"\t-----------"<<endl;
                cout<<"\t|"<<valor[vira]<<"\t  |"<<endl;
                cout<<"\t|   \t  |"<<endl;
                cout<<"\t|  "<<escreve<<"   |"<<endl;
                cout<<"\t|   \t  |"<<endl;
                cout<<"\t|\t"<<valor[vira]<<" |"<<endl;
                cout<<"\t-----------"<<endl;
            }
            else if(naipe[vira]=='C')
            {
                escreve[0]='C';
                escreve[1]='o';
                escreve[2]='p';
                escreve[3]='a';
                escreve[4]='s';
                escreve[5]='\0';
                cout<<"\t-----------"<<endl;
                cout<<"\t|"<<valor[vira]<<"\t  |"<<endl;
                cout<<"\t|   \t  |"<<endl;
                cout<<"\t|  "<<escreve<<"  |"<<endl;
                cout<<"\t|   \t  |"<<endl;
                cout<<"\t|\t"<<valor[vira]<<" |"<<endl;
                cout<<"\t-----------"<<endl;
            }

            else if(naipe[vira]=='O')
            {
                escreve[0]='O';
                escreve[1]='u';
                escreve[2]='r';
                escreve[3]='o';
                escreve[4]='\0';
                cout<<"\t-----------"<<endl;
                cout<<"\t|"<<valor[vira]<<"\t  |"<<endl;
                cout<<"\t|   \t  |"<<endl;
                cout<<"\t|  "<<escreve<<"   |"<<endl;
                cout<<"\t|   \t  |"<<endl;
                cout<<"\t|\t"<<valor[vira]<<" |"<<endl;
                cout<<"\t-----------"<<endl;
            }
            else
            {
                escreve[0]='E';
                escreve[1]='s';
                escreve[2]='p';
                escreve[3]='a';
                escreve[4]='d';
                escreve[5]='a';
                escreve[6]='\0';
                cout<<"\t-----------"<<endl;
                cout<<"\t|"<<valor[vira]<<"\t  |"<<endl;
                cout<<"\t|   \t  |"<<endl;
                cout<<"\t| "<<escreve<<"  |"<<endl;
                cout<<"\t|   \t  |"<<endl;
                cout<<"\t|\t"<<valor[vira]<<" |"<<endl;
                cout<<"\t-----------"<<endl;
            }
            //cartas jogador 1

            if (vez==0)
            {
                cout<< "    VEZ DO JOGADOR 1 !!"<<endl;
                cout<< "digite qualquer CARACTERE para ver suas cartas"<<endl;
                cin>>continua;

                for(int i=0; i<3; i++)
                {
                    if(cartas_jogador1[i]!=-1)
                    {
                        cout<< "para jogar essa carta digite "<<i+1<<endl;
                        if(naipe[cartas_jogador1[i]]=='P')
                        {
                            escreve[0]='P';
                            escreve[1]='a';
                            escreve[2]='u';
                            escreve[3]='s';
                            escreve[4]='\0';

                            cout<<"-----------"<<endl;
                            cout<<"|"<<valor[cartas_jogador1[i]]<<"\t  |"<<endl;
                            cout<<"|   \t  |"<<endl;
                            cout<<"|  "<<escreve<<"   |"<<endl;
                            cout<<"|   \t  |"<<endl;
                            cout<<"|\t"<<valor[cartas_jogador1[i]]<<" |"<<endl;
                            cout<<"-----------"<<endl;
                        }
                        else if(naipe[cartas_jogador1[i]]=='C')
                        {
                            escreve[0]='C';
                            escreve[1]='o';
                            escreve[2]='p';
                            escreve[3]='a';
                            escreve[4]='s';
                            escreve[5]='\0';
                            cout<<"-----------"<<endl;
                            cout<<"|"<<valor[cartas_jogador1[i]]<<"\t  |"<<endl;
                            cout<<"|   \t  |"<<endl;
                            cout<<"|  "<<escreve<<"  |"<<endl;
                            cout<<"|   \t  |"<<endl;
                            cout<<"|\t"<<valor[cartas_jogador1[i]]<<" |"<<endl;
                            cout<<"-----------"<<endl;
                        }

                        else if(naipe[cartas_jogador1[i]]=='O')
                        {
                            escreve[0]='O';
                            escreve[1]='u';
                            escreve[2]='r';
                            escreve[3]='o';
                            escreve[4]='\0';
                            cout<<"-----------"<<endl;
                            cout<<"|"<<valor[cartas_jogador1[i]]<<"\t  |"<<endl;
                            cout<<"|   \t  |"<<endl;
                            cout<<"|  "<<escreve<<"   |"<<endl;
                            cout<<"|   \t  |"<<endl;
                            cout<<"|\t"<<valor[cartas_jogador1[i]]<<" |"<<endl;
                            cout<<"-----------"<<endl;
                        }
                        else
                        {
                            escreve[0]='E';
                            escreve[1]='s';
                            escreve[2]='p';
                            escreve[3]='a';
                            escreve[4]='d';
                            escreve[5]='a';
                            escreve[6]='\0';
                            cout<<"-----------"<<endl;
                            cout<<"|"<<valor[cartas_jogador1[i]]<<"\t  |"<<endl;
                            cout<<"|   \t  |"<<endl;
                            cout<<"| "<<escreve<<"  |"<<endl;
                            cout<<"|   \t  |"<<endl;
                            cout<<"|\t"<<valor[cartas_jogador1[i]]<<" |"<<endl;
                            cout<<"-----------"<<endl;
                        }
                    }
                }
                cout<< "escolha a sua carta jogador 1 "<<endl;
                cin>>jogada1;
                while(jogada1<1||jogada1>3)
                {
                    cout<<"jogada invalida jogue novamente "<<endl;
                    cin>>jogada1;
                }
                while(cartas_jogador1[jogada1-1]==-1)
                {
                    cout<< "carta ja jogada por favor digite outra"<<endl;
                    cin>>jogada1;
                    while(jogada1<1||jogada1>3)
                    {
                        cout<<"jogada invalida jogue novamente "<<endl;
                        cin>>jogada1;
                    }
                }
                //TRUCO JOGADOR 1 VEZ 0
                if(jatrucado!=1)
                {
                    cout<< "se quiser pedir truco digite t, se nao quiser digite n "<<endl;
                    cin>>truco1;
                    while(truco1!='t'&&truco1!='n')
                    {
                        cout<<"jogada invalida"<<endl;
                        cin>>truco1;
                    }

                    if (truco1=='t')
                    {
                        jatrucado=1;
                        system("clear");
                        cout<< "jogador 1 pediu truco, vai aceitar ? se sim digite 's', se for arregar digite 'n', se ta afim de aumentar para 6 digite 'a'"<<endl;
                        if(inicia!='m')
                        {
                            cin>>truco2;
                        }
                        else if (inicia=='m')
                        {
                            truco2=108+rand()%10;
                        }
                        while(truco2!='s'&&truco2!='n'&&truco2!='a')
                        {
                            if(inicia!='m')
                            {
                                cout<<"jogada invalida"<<endl;
                                cin>>truco2;
                            }
                            else if (inicia=='m')
                            {
                                truco2=108+rand()%10;
                            }

                        }
                        if (truco2=='s')
                        {
                            cout<< "TA TRUCADO KKKK "<<endl;
                            truco++;
                        }

                        else if (truco2=='n')
                        {
                            system("clear");
                            cout<< "jogador 2 arregou entao jogador 1 ganha um ponto "<<endl;
                            sleep(3);
                            pontos_jogador1++;
                            break;
                        }
                        else if (truco2=='a')
                        {
                            truco++;
                            cout<< "jogador 2 pediu 6, vai aceitar ? se sim digite 's', se for arregar digite 'n', se ta afim de aumentar para 6 digite 'a'"<<endl;
                            cin>>truco1;
                            while(truco1!='s'&&truco1!='n'&&truco1!='a')
                            {
                                cout<<"jogada invalida"<<endl;
                                cin>>truco1;
                            }
                            if (truco1=='s')
                            {
                                cout<< "TA VALENDO SEEEISSS KKKK "<<endl;
                                truco++;
                                sleep(2);
                            }

                            else if (truco1=='n')
                            {
                                system("clear");
                                cout<< "jogador 1 arregou entao jogador 2 ganha 3 pontos "<<endl;
                                sleep(3);
                                pontos_jogador2+=3;
                                break;
                            }
                            else if (truco1=='a')
                            {
                                truco++;
                                cout<< "jogador 1 pediu 9, vai aceitar ? se sim digite 's', se for arregar digite 'n', se ta afim de aumentar para 6 digite 'a'"<<endl;
                                if(inicia!='m')
                                {
                                    cin>>truco2;
                                }
                                else if (inicia=='m')
                                {
                                    truco2=108+rand()%10;
                                }
                                while(truco2!='s'&&truco2!='n'&&truco2!='a')
                                {
                                    if(inicia!='m')
                                    {
                                        cout<<"jogada invalida"<<endl;
                                        cin>>truco2;
                                    }
                                    else if (inicia=='m')
                                    {
                                        truco2=108+rand()%10;
                                    }

                                }
                                if (truco2=='s')
                                {
                                    truco++;
                                    cout<< "TA VALENDO NOVEEEE KKKK "<<endl;
                                    sleep(2);
                                }

                                else if (truco2=='n')
                                {
                                    system("clear");
                                    cout<< "jogador 2 arregou entao jogador 1 ganha 6 pontos "<<endl;
                                    sleep(3);
                                    pontos_jogador1+=6;
                                    break;
                                }
                                else if (truco2=='a')
                                {
                                    truco++;
                                    cout<< "jogador 2 pediu 12, vai aceitar ? se sim digite 's', se for arregar digite 'n', se ta afim de aumentar para 6 digite 'a'"<<endl;
                                    cin>>truco1;
                                    while(truco1!='s'&&truco1!='n')
                                    {
                                        cout<<"jogada invalida"<<endl;
                                        cin>>truco1;
                                    }
                                    if (truco1=='s')
                                    {
                                        cout<< "TA VALENDO DOZEEEEEEEEEEEEEEEEEEEEEE KKKK "<<endl;
                                        truco++;
                                        sleep(2);
                                    }

                                    else if (truco1=='n')
                                    {
                                        system("clear");
                                        cout<< "jogador 2 arregou entao jogador 1 ganha 9 pontos "<<endl;
                                        sleep(3);
                                        pontos_jogador2+=9;
                                        break;
                                    }
                                }
                            }
                        }
                    }

                }
                system("clear");
                jogada1=jogada1-1;


                if(naipe[cartas_jogador1[jogada1]]=='P')
                {
                    escreve[0]='P';
                    escreve[1]='a';
                    escreve[2]='u';
                    escreve[3]='s';
                    escreve[4]='\0';

                    cout<<"-----------"<<endl;
                    cout<<"|"<<valor[cartas_jogador1[jogada1]]<<"\t  |"<<endl;
                    cout<<"|   \t  |"<<endl;
                    cout<<"|  "<<escreve<<"   |"<<endl;
                    cout<<"|   \t  |"<<endl;
                    cout<<"|\t"<<valor[cartas_jogador1[jogada1]]<<" |"<<endl;
                    cout<<"-----------"<<endl;
                }
                else if(naipe[cartas_jogador1[jogada1]]=='C')
                {
                    escreve[0]='C';
                    escreve[1]='o';
                    escreve[2]='p';
                    escreve[3]='a';
                    escreve[4]='s';
                    escreve[5]='\0';
                    cout<<"-----------"<<endl;
                    cout<<"|"<<valor[cartas_jogador1[jogada1]]<<"\t  |"<<endl;
                    cout<<"|   \t  |"<<endl;
                    cout<<"|  "<<escreve<<"  |"<<endl;
                    cout<<"|   \t  |"<<endl;
                    cout<<"|\t"<<valor[cartas_jogador1[jogada1]]<<" |"<<endl;
                    cout<<"-----------"<<endl;
                }

                else if(naipe[cartas_jogador1[jogada1]]=='O')
                {
                    escreve[0]='O';
                    escreve[1]='u';
                    escreve[2]='r';
                    escreve[3]='o';
                    escreve[4]='\0';
                    cout<<"-----------"<<endl;
                    cout<<"|"<<valor[cartas_jogador1[jogada1]]<<"\t  |"<<endl;
                    cout<<"|   \t  |"<<endl;
                    cout<<"|  "<<escreve<<"   |"<<endl;
                    cout<<"|   \t  |"<<endl;
                    cout<<"|\t"<<valor[cartas_jogador1[jogada1]]<<" |"<<endl;
                    cout<<"-----------"<<endl;
                }
                else
                {
                    escreve[0]='E';
                    escreve[1]='s';
                    escreve[2]='p';
                    escreve[3]='a';
                    escreve[4]='d';
                    escreve[5]='a';
                    escreve[6]='\0';
                    cout<<"-----------"<<endl;
                    cout<<"|"<<valor[cartas_jogador1[jogada1]]<<"\t  |"<<endl;
                    cout<<"|   \t  |"<<endl;
                    cout<<"| "<<escreve<<"  |"<<endl;
                    cout<<"|   \t  |"<<endl;
                    cout<<"|\t"<<valor[cartas_jogador1[jogada1]]<<" |"<<endl;
                    cout<<"-----------"<<endl;
                }
                cout<< "PLACAR :"<<endl;
                cout<<"jogador 1 = "<<pontos_jogador1<<"   jogador 2 = "<<pontos_jogador2<<endl;

                //cartas do jogador 2
                cout<<"\tcarta vira :"<<endl;
                if(naipe[vira]=='P')
                {
                    escreve[0]='P';
                    escreve[1]='a';
                    escreve[2]='u';
                    escreve[3]='s';
                    escreve[4]='\0';

                    cout<<"\t-----------"<<endl;
                    cout<<"\t|"<<valor[vira]<<"\t  |"<<endl;
                    cout<<"\t|   \t  |"<<endl;
                    cout<<"\t|  "<<escreve<<"   |"<<endl;
                    cout<<"\t|   \t  |"<<endl;
                    cout<<"\t|\t"<<valor[vira]<<" |"<<endl;
                    cout<<"\t-----------"<<endl;
                }
                else if(naipe[vira]=='C')
                {
                    escreve[0]='C';
                    escreve[1]='o';
                    escreve[2]='p';
                    escreve[3]='a';
                    escreve[4]='s';
                    escreve[5]='\0';
                    cout<<"\t-----------"<<endl;
                    cout<<"\t|"<<valor[vira]<<"\t  |"<<endl;
                    cout<<"\t|   \t  |"<<endl;
                    cout<<"\t|  "<<escreve<<"  |"<<endl;
                    cout<<"\t|   \t  |"<<endl;
                    cout<<"\t|\t"<<valor[vira]<<" |"<<endl;
                    cout<<"\t-----------"<<endl;
                }

                else if(naipe[vira]=='O')
                {
                    escreve[0]='O';
                    escreve[1]='u';
                    escreve[2]='r';
                    escreve[3]='o';
                    escreve[4]='\0';
                    cout<<"\t-----------"<<endl;
                    cout<<"\t|"<<valor[vira]<<"\t  |"<<endl;
                    cout<<"\t|   \t  |"<<endl;
                    cout<<"\t|  "<<escreve<<"   |"<<endl;
                    cout<<"\t|   \t  |"<<endl;
                    cout<<"\t|\t"<<valor[vira]<<" |"<<endl;
                    cout<<"\t-----------"<<endl;
                }
                else
                {
                    escreve[0]='E';
                    escreve[1]='s';
                    escreve[2]='p';
                    escreve[3]='a';
                    escreve[4]='d';
                    escreve[5]='a';
                    escreve[6]='\0';
                    cout<<"\t-----------"<<endl;
                    cout<<"\t|"<<valor[vira]<<"\t  |"<<endl;
                    cout<<"\t|   \t  |"<<endl;
                    cout<<"\t| "<<escreve<<"  |"<<endl;
                    cout<<"\t|   \t  |"<<endl;
                    cout<<"\t|\t"<<valor[vira]<<" |"<<endl;
                    cout<<"\t-----------"<<endl;
                }
                if(inicia!='m')
                {
                    cout<< "    VEZ DO JOGADOR 2 !!"<<endl<<endl;
                    cout<< "digite qualquer CARACTERE para ver suas cartas"<<endl;
                    cin>>continua;

                    for(int i=0; i<3; i++)
                    {
                        if(cartas_jogador2[i]!=-1)
                        {
                            cout<< "para jogar essa carta digite "<<i+1<<endl;
                            if(naipe[cartas_jogador2[i]]=='P')
                            {
                                escreve[0]='P';
                                escreve[1]='a';
                                escreve[2]='u';
                                escreve[3]='s';
                                escreve[4]='\0';

                                cout<<"-----------"<<endl;
                                cout<<"|"<<valor[cartas_jogador2[i]]<<"\t  |"<<endl;
                                cout<<"|   \t  |"<<endl;
                                cout<<"|  "<<escreve<<"   |"<<endl;
                                cout<<"|   \t  |"<<endl;
                                cout<<"|\t"<<valor[cartas_jogador2[i]]<<" |"<<endl;
                                cout<<"-----------"<<endl;
                            }
                            else if(naipe[cartas_jogador2[i]]=='C')
                            {
                                escreve[0]='C';
                                escreve[1]='o';
                                escreve[2]='p';
                                escreve[3]='a';
                                escreve[4]='s';
                                escreve[5]='\0';
                                cout<<"-----------"<<endl;
                                cout<<"|"<<valor[cartas_jogador2[i]]<<"\t  |"<<endl;
                                cout<<"|   \t  |"<<endl;
                                cout<<"|  "<<escreve<<"  |"<<endl;
                                cout<<"|   \t  |"<<endl;
                                cout<<"|\t"<<valor[cartas_jogador2[i]]<<" |"<<endl;
                                cout<<"-----------"<<endl;
                            }

                            else if(naipe[cartas_jogador2[i]]=='O')
                            {
                                escreve[0]='O';
                                escreve[1]='u';
                                escreve[2]='r';
                                escreve[3]='o';
                                escreve[4]='\0';
                                cout<<"-----------"<<endl;
                                cout<<"|"<<valor[cartas_jogador2[i]]<<"\t  |"<<endl;
                                cout<<"|   \t  |"<<endl;
                                cout<<"|  "<<escreve<<"   |"<<endl;
                                cout<<"|   \t  |"<<endl;
                                cout<<"|\t"<<valor[cartas_jogador2[i]]<<" |"<<endl;
                                cout<<"-----------"<<endl;
                            }
                            else
                            {
                                escreve[0]='E';
                                escreve[1]='s';
                                escreve[2]='p';
                                escreve[3]='a';
                                escreve[4]='d';
                                escreve[5]='a';
                                escreve[6]='\0';
                                cout<<"-----------"<<endl;
                                cout<<"|"<<valor[cartas_jogador2[i]]<<"\t  |"<<endl;
                                cout<<"|   \t  |"<<endl;
                                cout<<"| "<<escreve<<"  |"<<endl;
                                cout<<"|   \t  |"<<endl;
                                cout<<"|\t"<<valor[cartas_jogador2[i]]<<" |"<<endl;
                                cout<<"-----------"<<endl;
                            }
                        }
                    }

                    if(inicia!='m')
                    {
                        cout<< "escolha a sua carta jogador 2"<<endl;
                        cin>>jogada2;
                    }
                    while(jogada2<1||jogada2>3)
                    {
                        cout<<"jogada invalida jogue novamente "<<endl;
                        cin>>jogada2;
                    }
                    while(cartas_jogador2[jogada2-1]==-1)
                    {
                        cout<< "carta ja jogada por favor digite outra"<<endl;
                        cin>>jogada2;
                        while(jogada2<1||jogada2>3)
                        {
                            cout<< "jogda invalida jogue novamente "<<endl;
                            cin>>jogada2;
                        }
                    }
                }
                else if (inicia=='m')
                {
                    jogada2=rand()%4;
                    while(jogada2<1||jogada2>3)
                    {
                        jogada2=rand()%4;
                    }
                    while(cartas_jogador2[jogada2-1]==-1)
                    {
                        jogada2=rand()%4;
                        while(jogada2<1||jogada2>3)
                        {
                            jogada2=rand()%4;
                        }
                    }
                }
                //TRUCO
                if(jatrucado!=1)
                {
                    if(inicia!='m')
                    {
                        cout<< "se quiser pedir truco digite t, se nao quiser digite n "<<endl;

                        cin>>truco2;
                    }
                    else if (inicia=='m')
                    {
                        truco2=108+rand()%10;
                    }

                    while(truco2!='t'&&truco2!='n')
                    {
                         if(inicia!='m')
                    {
                        cout<<"jogada invalida"<<endl;
                        cin>>truco2;
                    }
                    else if (inicia=='m')
                    {
                        truco2=108+rand()%10;
                    }
                    }

                    if (truco2=='t')
                    {
                        jatrucado=1;
                        system("clear");
                        cout<< "jogador 2 pediu truco, vai aceitar ? se sim digite 's', se for arregar digite 'n', se ta afim de aumentar para 6 digite 'a'"<<endl;
                        cin>>truco1;
                        while(truco1!='s'&&truco1!='n'&&truco1!='a')
                        {
                            cout<<"jogada invalida"<<endl;
                            cin>>truco1;
                        }
                        if (truco1=='s')
                        {
                            cout<< "TA TRUCADO KKKK "<<endl;
                            truco++;
                        }

                        else if (truco1=='n')
                        {
                            system("clear");
                            cout<< "jogador 1 arregou entao jogador 2 ganha um ponto "<<endl;
                            sleep(3);
                            pontos_jogador2++;
                            break;
                        }
                        else if (truco1=='a')
                        {
                            truco++;
                             if(inicia!='m')
                    {
                       cout<< "jogador 1 pediu 6, vai aceitar ? se sim digite 's', se for arregar digite 'n', se ta afim de aumentar para 6 digite 'a'"<<endl;
                            cin>>truco2;
                    }
                    else if (inicia=='m')
                    {
                        truco2=108+rand()%10;
                    }

                            while(truco2!='s'&&truco2!='n'&&truco2!='a')
                            {
                                if(inicia!='m')
                    {
                            cout<<"jogada invalida"<<endl;
                                cin>>truco2;
                    }
                    else if (inicia=='m')
                    {
                        truco2=108+rand()%10;
                    }

                            }
                            if (truco2=='s')
                            {
                                cout<< "TA VALENDO SEEEISSS KKKK "<<endl;
                                truco++;
                                sleep(2);
                            }

                            else if (truco2=='n')
                            {
                                system("clear");
                                cout<< "jogador 2 arregou entao jogador 1 ganha 3 pontos "<<endl;
                                sleep(3);
                                pontos_jogador1+=3;
                                break;
                            }
                            else if (truco2=='a')
                            {
                                truco++;
                                cout<< "jogador 2 pediu 9, vai aceitar ? se sim digite 's', se for arregar digite 'n', se ta afim de aumentar para 6 digite 'a'"<<endl;
                                cin>>truco1;
                                while(truco1!='s'&&truco1!='n'&&truco1!='a')
                                {
                                    cout<<"jogada invalida"<<endl;
                                    cin>>truco1;
                                }
                                if (truco1=='s')
                                {
                                    truco++;
                                    cout<< "TA VALENDO NOVEEEE KKKK "<<endl;
                                    sleep(2);
                                }

                                else if (truco1=='n')
                                {
                                    system("clear");
                                    cout<< "jogador 1 arregou entao jogador 2 ganha 6 pontos "<<endl;
                                    sleep(3);
                                    pontos_jogador2+=6;
                                    break;
                                }
                                else if (truco1=='a')
                                {
                                    truco++;
                                    if(inicia!='m')
                    {
                        cout<< "jogador 1 pediu 12, vai aceitar ? se sim digite 's', se for arregar digite 'n', se ta afim de aumentar para 6 digite 'a'"<<endl;
                                    cin>>truco2;
                    }
                    else if (inicia=='m')
                    {
                        truco2=108+rand()%10;
                    }

                                    while(truco2!='s'&&truco2!='n')
                                    {
                                         if(inicia!='m')
                    {
                         cout<<"jogada invalida"<<endl;
                                        cin>>truco2;
                    }
                    else if (inicia=='m')
                    {
                        truco2=108+rand()%10;
                    }

                                    }
                                    if (truco2=='s')
                                    {
                                        cout<< "TA VALENDO DOZEEEEEEEEEEEEEEEEEEEEEE KKKK "<<endl;
                                        truco++;
                                        sleep(2);
                                    }

                                    else if (truco2=='n')
                                    {
                                        system("clear");
                                        cout<< "jogador 1 arregou entao jogador 2 ganha 9 pontos "<<endl;
                                        sleep(3);
                                        pontos_jogador1+=9;
                                        break;
                                    }
                                }
                            }
                        }
                    }

                }

                system("clear");
                jogada2=jogada2-1;


                if(naipe[cartas_jogador2[jogada2]]=='P')
                {
                    escreve[0]='P';
                    escreve[1]='a';
                    escreve[2]='u';
                    escreve[3]='s';
                    escreve[4]='\0';

                    cout<<"-----------"<<endl;
                    cout<<"|"<<valor[cartas_jogador2[jogada2]]<<"\t  |"<<endl;
                    cout<<"|   \t  |"<<endl;
                    cout<<"|  "<<escreve<<"   |"<<endl;
                    cout<<"|   \t  |"<<endl;
                    cout<<"|\t"<<valor[cartas_jogador2[jogada2]]<<" |"<<endl;
                    cout<<"-----------"<<endl;
                }
                else if(naipe[cartas_jogador2[jogada2]]=='C')
                {
                    escreve[0]='C';
                    escreve[1]='o';
                    escreve[2]='p';
                    escreve[3]='a';
                    escreve[4]='s';
                    escreve[5]='\0';
                    cout<<"-----------"<<endl;
                    cout<<"|"<<valor[cartas_jogador2[jogada2]]<<"\t  |"<<endl;
                    cout<<"|   \t  |"<<endl;
                    cout<<"|  "<<escreve<<"  |"<<endl;
                    cout<<"|   \t  |"<<endl;
                    cout<<"|\t"<<valor[cartas_jogador2[jogada2]]<<" |"<<endl;
                    cout<<"-----------"<<endl;
                }

                else if(naipe[cartas_jogador2[jogada2]]=='O')
                {
                    escreve[0]='O';
                    escreve[1]='u';
                    escreve[2]='r';
                    escreve[3]='o';
                    escreve[4]='\0';
                    cout<<"-----------"<<endl;
                    cout<<"|"<<valor[cartas_jogador2[jogada2]]<<"\t  |"<<endl;
                    cout<<"|   \t  |"<<endl;
                    cout<<"|  "<<escreve<<"   |"<<endl;
                    cout<<"|   \t  |"<<endl;
                    cout<<"|\t"<<valor[cartas_jogador2[jogada2]]<<" |"<<endl;
                    cout<<"-----------"<<endl;
                }
                else
                {
                    escreve[0]='E';
                    escreve[1]='s';
                    escreve[2]='p';
                    escreve[3]='a';
                    escreve[4]='d';
                    escreve[5]='a';
                    escreve[6]='\0';
                    cout<<"-----------"<<endl;
                    cout<<"|"<<valor[cartas_jogador2[jogada2]]<<"\t  |"<<endl;
                    cout<<"|   \t  |"<<endl;
                    cout<<"| "<<escreve<<"  |"<<endl;
                    cout<<"|   \t  |"<<endl;
                    cout<<"|\t"<<valor[cartas_jogador2[jogada2]]<<" |"<<endl;
                    cout<<"-----------"<<endl;
                }
            }
            //vez =1
            else
            {
                //cartas do jogador 2
if(inicia!='m')
                {
                    cout<< "    VEZ DO JOGADOR 2 !!"<<endl<<endl;
                    cout<< "digite qualquer CARACTERE para ver suas cartas"<<endl;
                    cin>>continua;

                    for(int i=0; i<3; i++)
                    {
                        if(cartas_jogador2[i]!=-1)
                        {
                            cout<< "para jogar essa carta digite "<<i+1<<endl;
                            if(naipe[cartas_jogador2[i]]=='P')
                            {
                                escreve[0]='P';
                                escreve[1]='a';
                                escreve[2]='u';
                                escreve[3]='s';
                                escreve[4]='\0';

                                cout<<"-----------"<<endl;
                                cout<<"|"<<valor[cartas_jogador2[i]]<<"\t  |"<<endl;
                                cout<<"|   \t  |"<<endl;
                                cout<<"|  "<<escreve<<"   |"<<endl;
                                cout<<"|   \t  |"<<endl;
                                cout<<"|\t"<<valor[cartas_jogador2[i]]<<" |"<<endl;
                                cout<<"-----------"<<endl;
                            }
                            else if(naipe[cartas_jogador2[i]]=='C')
                            {
                                escreve[0]='C';
                                escreve[1]='o';
                                escreve[2]='p';
                                escreve[3]='a';
                                escreve[4]='s';
                                escreve[5]='\0';
                                cout<<"-----------"<<endl;
                                cout<<"|"<<valor[cartas_jogador2[i]]<<"\t  |"<<endl;
                                cout<<"|   \t  |"<<endl;
                                cout<<"|  "<<escreve<<"  |"<<endl;
                                cout<<"|   \t  |"<<endl;
                                cout<<"|\t"<<valor[cartas_jogador2[i]]<<" |"<<endl;
                                cout<<"-----------"<<endl;
                            }

                            else if(naipe[cartas_jogador2[i]]=='O')
                            {
                                escreve[0]='O';
                                escreve[1]='u';
                                escreve[2]='r';
                                escreve[3]='o';
                                escreve[4]='\0';
                                cout<<"-----------"<<endl;
                                cout<<"|"<<valor[cartas_jogador2[i]]<<"\t  |"<<endl;
                                cout<<"|   \t  |"<<endl;
                                cout<<"|  "<<escreve<<"   |"<<endl;
                                cout<<"|   \t  |"<<endl;
                                cout<<"|\t"<<valor[cartas_jogador2[i]]<<" |"<<endl;
                                cout<<"-----------"<<endl;
                            }
                            else
                            {
                                escreve[0]='E';
                                escreve[1]='s';
                                escreve[2]='p';
                                escreve[3]='a';
                                escreve[4]='d';
                                escreve[5]='a';
                                escreve[6]='\0';
                                cout<<"-----------"<<endl;
                                cout<<"|"<<valor[cartas_jogador2[i]]<<"\t  |"<<endl;
                                cout<<"|   \t  |"<<endl;
                                cout<<"| "<<escreve<<"  |"<<endl;
                                cout<<"|   \t  |"<<endl;
                                cout<<"|\t"<<valor[cartas_jogador2[i]]<<" |"<<endl;
                                cout<<"-----------"<<endl;
                            }
                        }
                    }

                    if(inicia!='m')
                    {
                        cout<< "escolha a sua carta jogador 2"<<endl;
                        cin>>jogada2;
                    }
                    while(jogada2<1||jogada2>3)
                    {
                        cout<<"jogada invalida jogue novamente "<<endl;
                        cin>>jogada2;
                    }
                    while(cartas_jogador2[jogada2-1]==-1)
                    {
                        cout<< "carta ja jogada por favor digite outra"<<endl;
                        cin>>jogada2;
                        while(jogada2<1||jogada2>3)
                        {
                            cout<< "jogda invalida jogue novamente "<<endl;
                            cin>>jogada2;
                        }
                    }
                }
                else if (inicia=='m')
                {
                    jogada2=rand()%4;
                    while(jogada2<1||jogada2>3)
                    {
                        jogada2=rand()%4;
                    }
                    while(cartas_jogador2[jogada2-1]==-1)
                    {
                        jogada2=rand()%4;
                        while(jogada2<1||jogada2>3)
                        {
                            jogada2=rand()%4;
                        }
                    }
                }
                //TRUCO
                if(jatrucado!=1)
                {
                    if(inicia!='m')
                    {
                        cout<< "se quiser pedir truco digite t, se nao quiser digite n "<<endl;

                        cin>>truco2;
                    }
                    else if (inicia=='m')
                    {
                        truco2=108+rand()%10;
                    }

                    while(truco2!='t'&&truco2!='n')
                    {
                         if(inicia!='m')
                    {
                        cout<<"jogada invalida"<<endl;
                        cin>>truco2;
                    }
                    else if (inicia=='m')
                    {
                        truco2=108+rand()%10;
                    }
                    }

                    if (truco2=='t')
                    {
                        jatrucado=1;
                        system("clear");
                        cout<< "jogador 2 pediu truco, vai aceitar ? se sim digite 's', se for arregar digite 'n', se ta afim de aumentar para 6 digite 'a'"<<endl;
                        cin>>truco1;
                        while(truco1!='s'&&truco1!='n'&&truco1!='a')
                        {
                            cout<<"jogada invalida"<<endl;
                            cin>>truco1;
                        }
                        if (truco1=='s')
                        {
                            cout<< "TA TRUCADO KKKK "<<endl;
                            truco++;
                        }

                        else if (truco1=='n')
                        {
                            system("clear");
                            cout<< "jogador 1 arregou entao jogador 2 ganha um ponto "<<endl;
                            sleep(3);
                            pontos_jogador2++;
                            break;
                        }
                        else if (truco1=='a')
                        {
                            truco++;
                             if(inicia!='m')
                    {
                       cout<< "jogador 1 pediu 6, vai aceitar ? se sim digite 's', se for arregar digite 'n', se ta afim de aumentar para 6 digite 'a'"<<endl;
                            cin>>truco2;
                    }
                    else if (inicia=='m')
                    {
                        truco2=108+rand()%10;
                    }

                            while(truco2!='s'&&truco2!='n'&&truco2!='a')
                            {
                                if(inicia!='m')
                    {
                            cout<<"jogada invalida"<<endl;
                                cin>>truco2;
                    }
                    else if (inicia=='m')
                    {
                        truco2=108+rand()%10;
                    }

                            }
                            if (truco2=='s')
                            {
                                cout<< "TA VALENDO SEEEISSS KKKK "<<endl;
                                truco++;
                                sleep(2);
                            }

                            else if (truco2=='n')
                            {
                                system("clear");
                                cout<< "jogador 2 arregou entao jogador 1 ganha 3 pontos "<<endl;
                                sleep(3);
                                pontos_jogador1+=3;
                                break;
                            }
                            else if (truco2=='a')
                            {
                                truco++;
                                cout<< "jogador 2 pediu 9, vai aceitar ? se sim digite 's', se for arregar digite 'n', se ta afim de aumentar para 6 digite 'a'"<<endl;
                                cin>>truco1;
                                while(truco1!='s'&&truco1!='n'&&truco1!='a')
                                {
                                    cout<<"jogada invalida"<<endl;
                                    cin>>truco1;
                                }
                                if (truco1=='s')
                                {
                                    truco++;
                                    cout<< "TA VALENDO NOVEEEE KKKK "<<endl;
                                    sleep(2);
                                }

                                else if (truco1=='n')
                                {
                                    system("clear");
                                    cout<< "jogador 1 arregou entao jogador 2 ganha 6 pontos "<<endl;
                                    sleep(3);
                                    pontos_jogador2+=6;
                                    break;
                                }
                                else if (truco1=='a')
                                {
                                    truco++;
                                    if(inicia!='m')
                    {
                        cout<< "jogador 1 pediu 12, vai aceitar ? se sim digite 's', se for arregar digite 'n', se ta afim de aumentar para 6 digite 'a'"<<endl;
                                    cin>>truco2;
                    }
                    else if (inicia=='m')
                    {
                        truco2=108+rand()%10;
                    }

                                    while(truco2!='s'&&truco2!='n')
                                    {
                                         if(inicia!='m')
                    {
                         cout<<"jogada invalida"<<endl;
                                        cin>>truco2;
                    }
                    else if (inicia=='m')
                    {
                        truco2=108+rand()%10;
                    }

                                    }
                                    if (truco2=='s')
                                    {
                                        cout<< "TA VALENDO DOZEEEEEEEEEEEEEEEEEEEEEE KKKK "<<endl;
                                        truco++;
                                        sleep(2);
                                    }

                                    else if (truco2=='n')
                                    {
                                        system("clear");
                                        cout<< "jogador 1 arregou entao jogador 2 ganha 9 pontos "<<endl;
                                        sleep(3);
                                        pontos_jogador1+=9;
                                        break;
                                    }
                                }
                            }
                        }
                    }

                }

                system("clear");
                jogada2=jogada2-1;

                if(naipe[cartas_jogador2[jogada2]]=='P')
                {
                    escreve[0]='P';
                    escreve[1]='a';
                    escreve[2]='u';
                    escreve[3]='s';
                    escreve[4]='\0';

                    cout<<"-----------"<<endl;
                    cout<<"|"<<valor[cartas_jogador2[jogada2]]<<"\t  |"<<endl;
                    cout<<"|   \t  |"<<endl;
                    cout<<"|  "<<escreve<<"   |"<<endl;
                    cout<<"|   \t  |"<<endl;
                    cout<<"|\t"<<valor[cartas_jogador2[jogada2]]<<" |"<<endl;
                    cout<<"-----------"<<endl;
                }
                else if(naipe[cartas_jogador2[jogada2]]=='C')
                {
                    escreve[0]='C';
                    escreve[1]='o';
                    escreve[2]='p';
                    escreve[3]='a';
                    escreve[4]='s';
                    escreve[5]='\0';
                    cout<<"-----------"<<endl;
                    cout<<"|"<<valor[cartas_jogador2[jogada2]]<<"\t  |"<<endl;
                    cout<<"|   \t  |"<<endl;
                    cout<<"|  "<<escreve<<"  |"<<endl;
                    cout<<"|   \t  |"<<endl;
                    cout<<"|\t"<<valor[cartas_jogador2[jogada2]]<<" |"<<endl;
                    cout<<"-----------"<<endl;
                }

                else if(naipe[cartas_jogador2[jogada2]]=='O')
                {
                    escreve[0]='O';
                    escreve[1]='u';
                    escreve[2]='r';
                    escreve[3]='o';
                    escreve[4]='\0';
                    cout<<"-----------"<<endl;
                    cout<<"|"<<valor[cartas_jogador2[jogada2]]<<"\t  |"<<endl;
                    cout<<"|   \t  |"<<endl;
                    cout<<"|  "<<escreve<<"   |"<<endl;
                    cout<<"|   \t  |"<<endl;
                    cout<<"|\t"<<valor[cartas_jogador2[jogada2]]<<" |"<<endl;
                    cout<<"-----------"<<endl;
                }
                else
                {
                    escreve[0]='E';
                    escreve[1]='s';
                    escreve[2]='p';
                    escreve[3]='a';
                    escreve[4]='d';
                    escreve[5]='a';
                    escreve[6]='\0';
                    cout<<"-----------"<<endl;
                    cout<<"|"<<valor[cartas_jogador2[jogada2]]<<"\t  |"<<endl;
                    cout<<"|   \t  |"<<endl;
                    cout<<"| "<<escreve<<"  |"<<endl;
                    cout<<"|   \t  |"<<endl;
                    cout<<"|\t"<<valor[cartas_jogador2[jogada2]]<<" |"<<endl;
                    cout<<"-----------"<<endl;
                }
                cout<< "PLACAR :"<<endl;
                cout<<"jogador 1 = "<<pontos_jogador1<<"   jogador 2 = "<<pontos_jogador2<<endl;
                cout<<"\tcarta vira :"<<endl;
                if(naipe[vira]=='P')
                {
                    escreve[0]='P';
                    escreve[1]='a';
                    escreve[2]='u';
                    escreve[3]='s';
                    escreve[4]='\0';

                    cout<<"\t-----------"<<endl;
                    cout<<"\t|"<<valor[vira]<<"\t  |"<<endl;
                    cout<<"\t|   \t  |"<<endl;
                    cout<<"\t|  "<<escreve<<"   |"<<endl;
                    cout<<"\t|   \t  |"<<endl;
                    cout<<"\t|\t"<<valor[vira]<<" |"<<endl;
                    cout<<"\t-----------"<<endl;
                }
                else if(naipe[vira]=='C')
                {
                    escreve[0]='C';
                    escreve[1]='o';
                    escreve[2]='p';
                    escreve[3]='a';
                    escreve[4]='s';
                    escreve[5]='\0';
                    cout<<"\t-----------"<<endl;
                    cout<<"\t|"<<valor[vira]<<"\t  |"<<endl;
                    cout<<"\t|   \t  |"<<endl;
                    cout<<"\t|  "<<escreve<<"  |"<<endl;
                    cout<<"\t|   \t  |"<<endl;
                    cout<<"\t|\t"<<valor[vira]<<" |"<<endl;
                    cout<<"\t-----------"<<endl;
                }

                else if(naipe[vira]=='O')
                {
                    escreve[0]='O';
                    escreve[1]='u';
                    escreve[2]='r';
                    escreve[3]='o';
                    escreve[4]='\0';
                    cout<<"\t-----------"<<endl;
                    cout<<"\t|"<<valor[vira]<<"\t  |"<<endl;
                    cout<<"\t|   \t  |"<<endl;
                    cout<<"\t|  "<<escreve<<"   |"<<endl;
                    cout<<"\t|   \t  |"<<endl;
                    cout<<"\t|\t"<<valor[vira]<<" |"<<endl;
                    cout<<"\t-----------"<<endl;
                }
                else
                {
                    escreve[0]='E';
                    escreve[1]='s';
                    escreve[2]='p';
                    escreve[3]='a';
                    escreve[4]='d';
                    escreve[5]='a';
                    escreve[6]='\0';
                    cout<<"\t-----------"<<endl;
                    cout<<"\t|"<<valor[vira]<<"\t  |"<<endl;
                    cout<<"\t|   \t  |"<<endl;
                    cout<<"\t| "<<escreve<<"  |"<<endl;
                    cout<<"\t|   \t  |"<<endl;
                    cout<<"\t|\t"<<valor[vira]<<" |"<<endl;
                    cout<<"\t-----------"<<endl;
                }
                cout<< "    VEZ DO JOGADOR 1 !!"<<endl<<endl;
                cout<< "digite qualquer CARACTERE para ver suas cartas"<<endl;
                cin>>continua;
                for(int i=0; i<3; i++)
                {
                    if(cartas_jogador1[i]!=-1)
                    {
                        cout<< "para jogar essa carta digite "<<i+1<<endl;
                        if(naipe[cartas_jogador1[i]]=='P')
                        {
                            escreve[0]='P';
                            escreve[1]='a';
                            escreve[2]='u';
                            escreve[3]='s';
                            escreve[4]='\0';

                            cout<<"-----------"<<endl;
                            cout<<"|"<<valor[cartas_jogador1[i]]<<"\t  |"<<endl;
                            cout<<"|   \t  |"<<endl;
                            cout<<"|  "<<escreve<<"   |"<<endl;
                            cout<<"|   \t  |"<<endl;
                            cout<<"|\t"<<valor[cartas_jogador1[i]]<<" |"<<endl;
                            cout<<"-----------"<<endl;
                        }
                        else if(naipe[cartas_jogador1[i]]=='C')
                        {
                            escreve[0]='C';
                            escreve[1]='o';
                            escreve[2]='p';
                            escreve[3]='a';
                            escreve[4]='s';
                            escreve[5]='\0';
                            cout<<"-----------"<<endl;
                            cout<<"|"<<valor[cartas_jogador1[i]]<<"\t  |"<<endl;
                            cout<<"|   \t  |"<<endl;
                            cout<<"|  "<<escreve<<"  |"<<endl;
                            cout<<"|   \t  |"<<endl;
                            cout<<"|\t"<<valor[cartas_jogador1[i]]<<" |"<<endl;
                            cout<<"-----------"<<endl;
                        }

                        else if(naipe[cartas_jogador1[i]]=='O')
                        {
                            escreve[0]='O';
                            escreve[1]='u';
                            escreve[2]='r';
                            escreve[3]='o';
                            escreve[4]='\0';
                            cout<<"-----------"<<endl;
                            cout<<"|"<<valor[cartas_jogador1[i]]<<"\t  |"<<endl;
                            cout<<"|   \t  |"<<endl;
                            cout<<"|  "<<escreve<<"   |"<<endl;
                            cout<<"|   \t  |"<<endl;
                            cout<<"|\t"<<valor[cartas_jogador1[i]]<<" |"<<endl;
                            cout<<"-----------"<<endl;
                        }
                        else
                        {
                            escreve[0]='E';
                            escreve[1]='s';
                            escreve[2]='p';
                            escreve[3]='a';
                            escreve[4]='d';
                            escreve[5]='a';
                            escreve[6]='\0';
                            cout<<"-----------"<<endl;
                            cout<<"|"<<valor[cartas_jogador1[i]]<<"\t  |"<<endl;
                            cout<<"|   \t  |"<<endl;
                            cout<<"| "<<escreve<<"  |"<<endl;
                            cout<<"|   \t  |"<<endl;
                            cout<<"|\t"<<valor[cartas_jogador1[i]]<<" |"<<endl;
                            cout<<"-----------"<<endl;
                        }
                    }
                }
                cout<< "escolha a sua carta jogador 1"<<endl;
                cin>>jogada1;
                while(jogada1<1||jogada1>3)
                {
                    cout<<"jogada invalida jogue novamente"<<endl;
                    cin>>jogada1;
                }
                while(cartas_jogador1[jogada1-1]==-1)
                {
                    cout<< "carta ja jogada por favor digite outra"<<endl;
                    cin>>jogada1;
                    while(jogada1<1||jogada1>3)
                    {
                        cout<<"jogada invalida jogue novamente"<<endl;
                        cin>>jogada1;
                    }
                }
                //TRUCO
                if (truco1=='t')
                {
                    jatrucado=1;
                    system("clear");
                    cout<< "jogador 1 pediu truco, vai aceitar ? se sim digite 's', se for arregar digite 'n', se ta afim de aumentar para 6 digite 'a'"<<endl;
                    cin>>truco2;
                    while(truco2!='s'&&truco2!='n'&&truco2!='a')
                    {
                        cout<<"jogada invalida"<<endl;
                        cin>>truco2;
                    }
                    if (truco2=='s')
                    {
                        cout<< "TA TRUCADO KKKK "<<endl;
                        truco++;
                    }

                    else if (truco2=='n')
                    {
                        system("clear");
                        cout<< "jogador 2 arregou entao jogador 1 ganha um ponto "<<endl;
                        sleep(3);
                        pontos_jogador1++;
                        break;
                    }
                    else if (truco2=='a')
                    {
                        truco++;
                        cout<< "jogador 2 pediu 6, vai aceitar ? se sim digite 's', se for arregar digite 'n', se ta afim de aumentar para 6 digite 'a'"<<endl;
                        cin>>truco1;
                        while(truco1!='s'&&truco1!='n'&&truco1!='a')
                        {
                            cout<<"jogada invalida"<<endl;
                            cin>>truco1;
                        }
                        if (truco1=='s')
                        {
                            cout<< "TA VALENDO SEEEISSS KKKK "<<endl;
                            truco++;
                            sleep(2);
                        }

                        else if (truco1=='n')
                        {
                            system("clear");
                            cout<< "jogador 1 arregou entao jogador 2 ganha 3 pontos "<<endl;
                            sleep(3);
                            pontos_jogador2+=3;
                            break;
                        }
                        else if (truco1=='a')
                        {
                            truco++;
                            cout<< "jogador 1 pediu 9, vai aceitar ? se sim digite 's', se for arregar digite 'n', se ta afim de aumentar para 6 digite 'a'"<<endl;
                            cin>>truco2;
                            while(truco2!='s'&&truco2!='n'&&truco2!='a')
                            {
                                cout<<"jogada invalida"<<endl;
                                cin>>truco2;
                            }
                            if (truco2=='s')
                            {
                                truco++;
                                cout<< "TA VALENDO NOVEEEE KKKK "<<endl;
                                sleep(2);
                            }

                            else if (truco2=='n')
                            {
                                system("clear");
                                cout<< "jogador 2 arregou entao jogador 1 ganha 6 pontos "<<endl;
                                sleep(3);
                                pontos_jogador1+=6;
                                break;
                            }
                            else if (truco2=='a')
                            {
                                truco++;
                                cout<< "jogador 2 pediu 12, vai aceitar ? se sim digite 's', se for arregar digite 'n', se ta afim de aumentar para 6 digite 'a'"<<endl;
                                cin>>truco1;
                                while(truco1!='s'&&truco1!='n')
                                {
                                    cout<<"jogada invalida"<<endl;
                                    cin>>truco1;
                                }
                                if (truco1=='s')
                                {
                                    cout<< "TA VALENDO DOZEEEEEEEEEEEEEEEEEEEEEE KKKK "<<endl;
                                    truco++;
                                    sleep(2);
                                }

                                else if (truco1=='n')
                                {
                                    system("clear");
                                    cout<< "jogador 2 arregou entao jogador 1 ganha 9 pontos "<<endl;
                                    sleep(3);
                                    pontos_jogador2+=9;
                                    break;
                                }
                            }
                        }
                    }
                }



                system("clear");
                jogada1=jogada1-1;


                if(naipe[cartas_jogador1[jogada1]]=='P')
                {
                    escreve[0]='P';
                    escreve[1]='a';
                    escreve[2]='u';
                    escreve[3]='s';
                    escreve[4]='\0';

                    cout<<"-----------"<<endl;
                    cout<<"|"<<valor[cartas_jogador1[jogada1]]<<"\t  |"<<endl;
                    cout<<"|   \t  |"<<endl;
                    cout<<"|  "<<escreve<<"   |"<<endl;
                    cout<<"|   \t  |"<<endl;
                    cout<<"|\t"<<valor[cartas_jogador1[jogada1]]<<" |"<<endl;
                    cout<<"-----------"<<endl;
                }
                else if(naipe[cartas_jogador1[jogada1]]=='C')
                {
                    escreve[0]='C';
                    escreve[1]='o';
                    escreve[2]='p';
                    escreve[3]='a';
                    escreve[4]='s';
                    escreve[5]='\0';
                    cout<<"-----------"<<endl;
                    cout<<"|"<<valor[cartas_jogador1[jogada1]]<<"\t  |"<<endl;
                    cout<<"|   \t  |"<<endl;
                    cout<<"|  "<<escreve<<"  |"<<endl;
                    cout<<"|   \t  |"<<endl;
                    cout<<"|\t"<<valor[cartas_jogador1[jogada1]]<<" |"<<endl;
                    cout<<"-----------"<<endl;
                }

                else if(naipe[cartas_jogador1[jogada1]]=='O')
                {
                    escreve[0]='O';
                    escreve[1]='u';
                    escreve[2]='r';
                    escreve[3]='o';
                    escreve[4]='\0';
                    cout<<"-----------"<<endl;
                    cout<<"|"<<valor[cartas_jogador1[jogada1]]<<"\t  |"<<endl;
                    cout<<"|   \t  |"<<endl;
                    cout<<"|  "<<escreve<<"   |"<<endl;
                    cout<<"|   \t  |"<<endl;
                    cout<<"|\t"<<valor[cartas_jogador1[jogada1]]<<" |"<<endl;
                    cout<<"-----------"<<endl;
                }
                else
                {
                    escreve[0]='E';
                    escreve[1]='s';
                    escreve[2]='p';
                    escreve[3]='a';
                    escreve[4]='d';
                    escreve[5]='a';
                    escreve[6]='\0';
                    cout<<"-----------"<<endl;
                    cout<<"|"<<valor[cartas_jogador1[jogada1]]<<"\t  |"<<endl;
                    cout<<"|   \t  |"<<endl;
                    cout<<"| "<<escreve<<"  |"<<endl;
                    cout<<"|   \t  |"<<endl;
                    cout<<"|\t"<<valor[cartas_jogador1[jogada1]]<<" |"<<endl;
                    cout<<"-----------"<<endl;
                }


            }


            //testar a vitoria da mao
            if (cartas_jogador1[jogada1]%10==manilha[0]&&cartas_jogador2[jogada2]%10!=manilha[0])
            {
                mao1++;
                vitoria1=1;
                contvitoria++;
                cout<<"jogador 1 ganhou a mao"<<endl;
                vez=0;
            }
            else if (cartas_jogador1[jogada1]%10==manilha[0]&&cartas_jogador2[jogada2]%10==manilha[0])
            {
                if(cartas_jogador1[jogada1]>cartas_jogador2[jogada2])
                {
                    mao1++;
                    vitoria1=1;
                    contvitoria++;
                    cout<<"jogador 1 ganhou a mao"<<endl;
                    vez=0;
                }

                else if(cartas_jogador1[jogada1]<cartas_jogador2[jogada2])
                {
                    mao2++;
                    vitoria1=0;
                    contvitoria++;
                    cout<<"jogador 2 ganhou a mao"<<endl;
                    vez=1;
                }
            }
            else if (cartas_jogador2[jogada2]%10==manilha[0]&&cartas_jogador1[jogada1]%10!=manilha[0])
            {
                mao2++;
                vitoria1=0;
                contvitoria++;
                cout<<"jogador 2 ganhou a mao"<<endl;
                vez=1;
            }

            else if ((cartas_jogador1[jogada1]%10)>(cartas_jogador2[jogada2]%10))
            {
                mao1++;
                vitoria1=1;
                contvitoria++;
                cout<<"jogador 1 ganhou a mao"<<endl;
                vez=0;
            }
            else if ((cartas_jogador1[jogada1]%10)<(cartas_jogador2[jogada2]%10))
            {
                mao2++;
                vitoria1=0;
                contvitoria++;
                cout<<"jogador 2 ganhou a mao"<<endl;
                vez=1;
            }
            else if ((cartas_jogador1[jogada1]%10)==(cartas_jogador2[jogada2]%10))
            {
                if(empate!=1)
                {
                    mao1++;
                    mao2++;
                }
                empate++;
                cout<<"melou"<<endl;
                vez=0;
                if (contvitoria==2)
                {
                    if (vitoria1==0)
                    {
                        cout<<"jogador 1 ganhou a rodada"<<endl;
                        pontos_jogador1++;
                        flagtruco=1;
                    }
                    else if(vitoria1==1)
                    {
                        cout<<"jogador 2 ganhou a rodada"<<endl;
                        pontos_jogador2++;
                        flagtruco=2;
                    }
                }
            }
            if(empate==3)
            {
                cout<<"empate voces sao cagados pra caramba a chance de isso ocorrer eu nao sei puts grilo hahahahahaah alias o jogo eh meu eu escrevo oq eu quero ahahahaha essa mensagem jamais ocorrera ahahahahah"<<endl;
            }
            if (mao1>1&&empate<2)
            {
                pontos_jogador1++;
                flagtruco=1;
                system("clear");
                cout<< "jogador 1 ganhou a rodada"<<endl;
            }
            if (mao2>1&&empate<2)
            {
                flagtruco=2;
                pontos_jogador2++;
                system("clear");
                cout<< "jogador 2 ganhou a rodada"<<endl;
            }

            sleep(2);
            system("clear");
            cartas_jogador1[jogada1]=-1;
            cartas_jogador2[jogada2]=-1;

        }
        if(truco==1)
        {
            if (flagtruco==1)
            {
                pontos_jogador1+=2;
            }
            else if(flagtruco==2)
            {
                pontos_jogador2+=2;
            }
        }

        else if(truco==2)
        {
            if (flagtruco==1)
            {
                pontos_jogador1+=5;
            }
            else if(flagtruco==2)
            {
                pontos_jogador2+=5;
            }
        }

        else if(truco==3)
        {
            if (flagtruco==1)
            {
                pontos_jogador1+=8;
            }
            else if(flagtruco==2)
            {
                pontos_jogador2+=8;
            }
        }

        else if(truco==4)
        {
            if (flagtruco==1)
            {
                pontos_jogador1+=11;
            }
            else if(flagtruco==2)
            {
                pontos_jogador2+=11;
            }
        }

        mao1=0;
        mao2=0;
        empate=0;
        if(pontos_jogador1==12)
        {
            int cont=0;
            cout<< "jogador 1 voce ganhou!! "<<endl;
            while(cont<10)
            {

                cout<<"  _ _     _____               _____               ____    ______   _   _    _____     _ _ "<<endl;
                cout<<" ( | )   |  __ \\      /\\     |  __ \\      /\\     |  _ \\  |  ____| | \\ | |  / ____|   ( | )"<<endl;
                cout<<"  V V    | |__) |    /  \\    | |__) |    /  \\    | |_) | | |__    |  \\| | | (___      V V "<<endl;
                cout<<"         |  ___/    / /\\ \\   |  _  /    / /\\ \\   |  _ <  |  __|   | . ` |  \\___ \\         "<<endl;
                cout<<"         | |       / ____ \\  | | \\ \\   / ____ \\  | |_) | | |____  | |\\  |  ____) |        "<<endl;
                cout<<" / /     |_|      /_/    \\_\\ |_|  \\_\\ /_/    \\_\\ |____/  |______| |_| \\_| |_____/     \\ \\"<<endl;
                sleep(1);
                system("clear");
                cout<<"           _____               _____               ____    ______   _   _    _____   "<<endl;
                cout<<"          |  __ \\      /\\     |  __ \\      /\\     |  _ \\  |  ____| | \\ | |  / ____|  "<<endl;
                cout<<"          | |__) |    /  \\    | |__) |    /  \\    | |_) | | |__    |  \\| | | (___    "<<endl;
                cout<<"          |  ___/    / /\\ \\   |  _  /    / /\\ \\   |  _ <  |  __|   | . ` |  \\___ \\   "<<endl;
                cout<<"          | |       / ____ \\  | | \\ \\   / ____ \\  | |_) | | |____  | |\\  |  ____) |  "<<endl;
                cout<<"          |_|      /_/    \\_\\ |_|  \\_\\ /_/    \\_\\ |____/  |______| |_| \\_| |_____/   "<<endl;
                sleep(1);
                system("clear");
                cont++;
            }
        }
        else if (pontos_jogador2==12)
        {
            int cont=0;
            cout<< "Parabens jogador 2 voce ganhou!! "<<endl;
            while(cont<10)
            {
                cout<<"  _ _     _____               _____               ____    ______   _   _    _____     _ _ "<<endl;
                cout<<" ( | )   |  __ \\      /\\     |  __ \\      /\\     |  _ \\  |  ____| | \\ | |  / ____|   ( | )"<<endl;
                cout<<"  V V    | |__) |    /  \\    | |__) |    /  \\    | |_) | | |__    |  \\| | | (___      V V "<<endl;
                cout<<"         |  ___/    / /\\ \\   |  _  /    / /\\ \\   |  _ <  |  __|   | . ` |  \\___ \\         "<<endl;
                cout<<"         | |       / ____ \\  | | \\ \\   / ____ \\  | |_) | | |____  | |\\  |  ____) |        "<<endl;
                cout<<" / /     |_|      /_/    \\_\\ |_|  \\_\\ /_/    \\_\\ |____/  |______| |_| \\_| |_____/     \\ \\"<<endl;
                sleep(1);
                system("clear");
                cout<<"           _____               _____               ____    ______   _   _    _____   "<<endl;
                cout<<"          |  __ \\      /\\     |  __ \\      /\\     |  _ \\  |  ____| | \\ | |  / ____|  "<<endl;
                cout<<"          | |__) |    /  \\    | |__) |    /  \\    | |_) | | |__    |  \\| | | (___    "<<endl;
                cout<<"          |  ___/    / /\\ \\   |  _  /    / /\\ \\   |  _ <  |  __|   | . ` |  \\___ \\   "<<endl;
                cout<<"          | |       / ____ \\  | | \\ \\   / ____ \\  | |_) | | |____  | |\\  |  ____) |  "<<endl;
                cout<<"          |_|      /_/    \\_\\ |_|  \\_\\ /_/    \\_\\ |____/  |______| |_| \\_| |_____/   "<<endl;
                sleep(1);
                system("clear");
                cont++;
            }
        }
    }
}
