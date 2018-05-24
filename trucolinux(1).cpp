#include <iostream>
#include <cstdlib>
#include <ctime>
#include<unistd.h>


using namespace std;
int main ()
{
    int N_PARTIDAS =12;
    char valor[40]= {'4','5','6','7','Q','J','K','A','2','3','4','5','6','7','Q','J','K','A','2','3','4','5','6','7','Q','J','K','A','2','3','4','5','6','7','Q','J','K','A','2','3'} , naipes[40]= {'O','O','O','O','O','O','O','O','O','O','E','E','E','E','E','E','E','E','E','E','C','C','C','C','C','C','C','C','C','C','P','P','P','P','P','P','P','P','P','P'};
    int pont_jog1=0, pont_jog2=0, distribuicao_cartas, indice,cont,contmao1,contmao2,vira,carta_escolhida1, carta_escolhida2,vitoria1[3],vitoria2[3],round,soma1,soma2;
    char ch, ca;
    int jog_vez=1,jog_n_vez,mao_vez[3],mao_n_vez[3];
    cout<<"\t"<<"  ___  ____ _  _    _  _ _ _  _ ___  ____    ____ ____"<<endl;
    cout<<"\t"<<"  |__] |___ |\\/|    |  | | |\\ | |  \\ |  |    |__| |  |"<<endl;
    cout<<"\t"<<"  |__] |___ |  |     \\/  | | \\| |__/ |__|    |  | |__|"<<endl;
    cout<<"\t"<<"   _____      ____        _   _     ____     U  ___ u"<<endl;
    cout<<"\t"<<"  |_   _|  U |  _ \\ u  U | |u| | U / ___|     \\/ _ \\/ "<<endl;
    cout<<"\t"<<"    | |     \\| |_) |/   \\| |\\| | \\| | u       | | | | "<<endl;
    cout<<"\t"<<"   /| |\\     |  _ <      | |_| |  | |/__  .-,_| |_| | "<<endl;
    cout<<"\t"<<"  u |_|U     |_| \\_\\    <<\\___/    \\____|  \\_)-\\___/  "<<endl;
    cout<<"\t"<<"  _// \\\\_    //   \\\\_  (__) )(    _// \\\\        \\\\    "<<endl;
    cout<<"\t"<<" (__) (__)  (__)  (__)     (__)  (__)(__)      (__)   "<<endl;
    cout<<endl<<" para comecar a jogar digite qualquer caractere!"<<endl;
    cin>>ch;
    system("clear");
    cout<<endl<<endl;
    cout<<"\t '||'''|, '||''''| .|'''''| '||'''|,      /.\\      .|'''|"<<endl;
    cout<<"\t  ||   ||  ||   .  || .      ||   ||     // \\\\     ||      "<<endl;
    cout<<"\t  ||...|'  ||'''|  || |''||  ||...|'    //...\\\\    `|'''|, "<<endl;
    cout<<"\t  || \\\\    ||      ||    ||  || \\\\     //     \\\\    .   || "<<endl;
    cout<<"\t. ||  \\\\. .||....| `|....|' .||  \\\\. .//       \\\\.  |...|' "<<endl;
    cout<<"\n\tGANHA O JOGO QUEM FIZER PRIMEIRO 12 PONTOS!"<<endl;
    cout<<"\tCada jogador recebe 1 mao de 3 cartas."<<"\n\tGanha o round quem jogar a maior carta"<<"\n\tA ordem crescente do valor das cartas eh:"<<"\n\t4 5 6 7 Q J K A 2 3"<<endl;
    cout<<"\tO jogador que ganhar dois rounds ganha 1 ponto!"<<"\n\tEm caso de empate no round 2 e 3 ganha quem vencer o 1 round."<<"\n\tEm caso de empate no round 1 ganha quem venceu o 2 round."<<endl;
    cout<<"\tA carta virada 'VIRA' indica quais serao as 'Manilhas'."<<"\n\tAs Manilhas sao as cartas mais poderosas do jogo"<< endl;
    cout<<"\tA ordem dos naipes das cartas valem para as Manilhas."<<"\n\tOuros- Pica Fumo < Espadas- Espadilha < Copas- Copeta < Paus- ZAP "<<endl;
    cout<<"\n\n BOA SORTE JOGADORES!!!"<<endl<<"\n para continuar o jogo digite qualquer caractere!"<<endl;
    cin>>ca;
    system("clear");
    //pont_jog1 e pont_jog2 marcam quantos pontos cada jogador tem
    while(pont_jog1<N_PARTIDAS&& pont_jog2<N_PARTIDAS)
    {
        int cartas_sorteadas[40],mao1[3],mao2[3];//mao1,mao2 e vira guardam os indices das cartas
        srand(time(NULL));
        //zerar variaveis para inicio de cada rodada
        round=0;
        for(int i=0; i<40; i++)
        {
            cartas_sorteadas[i]=0;
        }
        for(int i=0; i<3; i++)
        {
            vitoria1[i]=0;
            vitoria2[i]=0;
        }
        //sortear cartas para os jogadores e a vira
        for(int i=0; i<7; i++)
        {
            do
            {
                indice=rand()%40;//31
            }
            while(cartas_sorteadas[indice]==1);
            cartas_sorteadas[indice]=1;
        }
        //distribuir as cartas do jog 1 e 2 e vira
        //verificar as cartas marcadas
        cont=0;
        contmao1=0,contmao2=0;
        while(contmao1<3 || contmao2<3)
        {
            //para uma distribuição mais equitativa, demos uma carta sort pra um e outra pro outro
            if(cartas_sorteadas[cont]==1)
            {
                if(contmao1<=contmao2)
                {
                    mao1[contmao1]=cont;
                    contmao1++;
                }
                else
                {
                    mao2[contmao2]=cont;
                    contmao2++;
                }
            }
            cont++;
        }
        //vira
        while(cartas_sorteadas[cont]!=1)
        {
            cont++;
        }
        vira=cont;
        cout<<endl<<"\t EMBARALHANDO AS CARTAS...  "<<endl;
        cout<<"  _ _ _ _ ___ ___ _ _ _ ___ _ _ _________"<<endl;
        cout<<" |A|3|2|4|5  |6  |7|Q|J|K  |A|2|3        |"<<endl;
        cout<<" |*|*|*|*|*  |*  |*|*|*|*  |*|*|*   *    |"<<endl;
        cout<<" | | | | |   |   | | | |   | | |    |    |"<<endl;
        cout<<" | | | | | *-| *-| | | | *-| | |  *-P-*  |"<<endl;
        cout<<" | | | | |   |   | | | |   | | |    |    |"<<endl;
        cout<<" | | | | |   |   | | | |   | | |    *   *|"<<endl;
        cout<<" | | | | |   |   | | | |   | | |        3|"<<endl;
        cout<<"  ~ ~ ~ ~ ~~~ ~~~ ~ ~ ~ ~~~ ~ ~ ~~~~~~~~~"<<endl;
        sleep(3);
        system("clear");
        cout<<endl<<"   CARTA VIRADA: "<<endl;
        cout<<"\t _________"<<endl;
        cout<<"\t|"<<valor[vira]<<"        |"<<endl;
        cout<<"\t|*   *    |"<<endl;
        cout<<"\t|    |    |"<<endl;
        cout<<"\t|  *-"<<naipes[vira]<<"-*  |"<<endl;
        cout<<"\t|    |    |"<<endl;
        cout<<"\t|    *   *|"<<endl;
        cout<<"\t|        "<<valor[vira]<<"|"<<endl;
        cout<<"\t ~~~~~~~~~"<<endl;
        sleep(3);
        system("clear");
        //jogadas
        while(round<3)
        {
            //mostrar o round
            if (round==0){
            cout<<"\n\n\t   ___   ____   __  __ _  __ ___     ___\n"<<"\t  / _ \\ / __ \\ / / / // |/ // _ \\   <  /\n"<<"\t / , _// /_/ // /_/ //    // // /   / / \n"<<"\t/_/|_| \\____/ \\____//_/|_//____/   /_/  \n";
            }
            else if (round==1){
            cout<<"\n\n\t   ___   ____   __  __ _  __ ___     ___ \n"<<"\t  / _ \\ / __ \\ / / / // |/ // _ \\   |_  |\n"<<"\t / , _// /_/ // /_/ //    // // /  / __/ \n"<<"\t/_/|_| \\____/ \\____//_/|_//____/  /____/ \n";
            }
            else {
            cout<<"\n\n\t   ___   ____   __  __ _  __ ___     ____\n"<<"\t  / _ \\ / __ \\ / / / // |/ // _ \\   |_  /\n"<<"\t / , _// /_/ // /_/ //    // // /  _/_ < \n"<<"\t/_/|_| \\____/ \\____//_/|_//____/  /____/ \n";
            }
            sleep(2);
            system("clear");
            //verificar quem eh o jogador da vez
            if(jog_vez==1)
            {
                for(int i=0; i<3; i++)
                {
                    mao_vez[i]=mao1[i];
                    mao_n_vez[i]=mao2[i];
                }
                jog_n_vez=2;
            }
            else
            {
                for(int i=0; i<3; i++)
                {
                    mao_vez[i]=mao2[i];
                    mao_n_vez[i]=mao1[i];
                }
                jog_n_vez=1;
            }
            //mostrar o placar o round e a carta vira novamente
            cout<<"PLACAR:                       "<<endl;
            cout<<" _____________________________"<<endl;
            cout<<"|                             |"<<endl;
            cout<<"|    JOGADOR 1   JOGADOR 2    |"<<endl;
            cout<<"|            "<<pont_jog1<<" X "<<pont_jog2<<"            |"<<endl;
            cout<<"|_____________________________|"<<endl;
            cout<<endl<<"\t    VIRA: "<<endl;
            cout<<"\t _________"<<endl;
            cout<<"\t|"<<valor[vira]<<"        |"<<endl;
            cout<<"\t|*   *    |"<<endl;
            cout<<"\t|    |    |"<<endl;
            cout<<"\t|  *-"<<naipes[vira]<<"-*  |"<<endl;
            cout<<"\t|    |    |"<<endl;
            cout<<"\t|    *   *|"<<endl;
            cout<<"\t|        "<<valor[vira]<<"|"<<endl;
            cout<<"\t ~~~~~~~~~"<<endl;
            //apresentar as cartas para o jogador
            //jogador1
            cout<<endl<<" SUAS CARTAS JOGADOR "<<jog_vez<<": "<<endl;
            for(int i=0; i<3; i++)
            {
                if(mao_vez[i]!=-1)
                {
                    cout<<"\n"<<" CARTA "<<mao_vez[i]<<":\n";
                    cout<<"  _________"<<endl;
                    cout<<" |"<<valor[mao_vez[i]]<<"        |"<<endl;
                    cout<<" |*   *    |"<<endl;
                    cout<<" |    |    |"<<endl;
                    cout<<" |  *-"<<naipes[mao_vez[i]]<<"-*  |"<<endl;
                    cout<<" |    |    |"<<endl;
                    cout<<" |    *   *|"<<endl;
                    cout<<" |        "<<valor[mao_vez[i]]<<"|"<<endl;
                    cout<<"  ~~~~~~~~~"<<endl;
                }
            }
            //digite as opções das cartas
            cout<<"\n"<<" ELABORE SUA ESTRATEGIA... "<<endl;
            do
            {
                cout<<endl<<" Digite o numero da carta escolhida: \n";
                cin>>carta_escolhida1;
                if(carta_escolhida1!=mao_vez[0]&&carta_escolhida1!=mao_vez[1]&&carta_escolhida1!=mao_vez[2])
                {
                    cout<<" Carta invalida, digite novamente.\n";
                }
            }
            while(carta_escolhida1!=mao_vez[0]&&carta_escolhida1!=mao_vez[1]&&carta_escolhida1!=mao_vez[2]);
            sleep(1);
            system("clear");
            //system clear e mostrar as cartas do jogador2
            //jogador2
            // mostrar placar o round o vira e a carta escolhida
            cout<<"PLACAR:                       "<<endl;
            cout<<" _____________________________"<<endl;
            cout<<"|                             |"<<endl;
            cout<<"|    JOGADOR 1   JOGADOR 2    |"<<endl;
            cout<<"|            "<<pont_jog1<<" X "<<pont_jog2<<"            |"<<endl;
            cout<<"|_____________________________|"<<endl;
            cout<<endl<<"\t 'VIRA': \t    A CARTA "<<carta_escolhida1<<" foi jogada!"<<endl;
            cout<<"\t _________\t\t _________"<<endl;
            cout<<"\t|"<<valor[vira]<<"        |\t\t|"<<valor[carta_escolhida1]<<"        |"<<endl;
            cout<<"\t|*   *    |\t\t|*   *    |"<<endl;
            cout<<"\t|    |    |\t\t|    |    |"<<endl;
            cout<<"\t|  *-"<<naipes[vira]<<"-*  |\t\t|  *-"<<naipes[carta_escolhida1]<<"-*  |"<<endl;
            cout<<"\t|    |    |\t\t|    |    |"<<endl;
            cout<<"\t|    *   *|\t\t|    *   *|"<<endl;
            cout<<"\t|        "<<valor[vira]<<"|\t\t|        "<<valor[carta_escolhida1]<<"|"<<endl;
            cout<<"\t ~~~~~~~~~\t\t ~~~~~~~~~"<<endl;
            //vez do jogador que não é o da vez e escolher sua carta para colocar na mesa
            cout<<endl<<" SUAS CARTAS JOGADOR "<<jog_n_vez<<": "<<endl;
            for(int i=0; i<3; i++)
            {
                if(mao_n_vez[i]!=-1)
                {
                    cout<<"\n"<<" CARTA "<<mao_n_vez[i]<<":\n";
                    cout<<"  _________"<<endl;
                    cout<<" |"<<valor[mao_n_vez[i]]<<"        |"<<endl;
                    cout<<" |*   *    |"<<endl;
                    cout<<" |    |    |"<<endl;
                    cout<<" |  *-"<<naipes[mao_n_vez[i]]<<"-*  |"<<endl;
                    cout<<" |    |    |"<<endl;
                    cout<<" |    *   *|"<<endl;
                    cout<<" |        "<<valor[mao_n_vez[i]]<<"|"<<endl;
                    cout<<"  ~~~~~~~~~"<<endl;
                }
            }
            cout<<"\n"<<" ELABORE SUA ESTRATEGIA... "<<endl;
            do
            {
                cout<<endl<<" Digite o numero da carta escolhida: \n";
                cin>>carta_escolhida2;
                if(carta_escolhida2!=mao_n_vez[0]&&carta_escolhida2!=mao_n_vez[1]&&carta_escolhida2!=mao_n_vez[2])
                {
                    cout<<" Carta invalida, digite novamente.\n";
                }
            }
            while(carta_escolhida2!=mao_n_vez[0]&&carta_escolhida2!=mao_n_vez[1]&&carta_escolhida2!=mao_n_vez[2]);
            sleep(1);
            system("clear");
            // mostrar a carta escolhida na "mesa"
            cout<<endl<<endl<<" CARTA "<<carta_escolhida1<<" do jogador "<<jog_vez<<" VERSUS "<<"CARTA "<<carta_escolhida2<<" do jogador "<<jog_n_vez<<endl;
            cout<<"\t _________"<<"         "<<"\t _________"<<endl;
            cout<<"\t|"<<valor[carta_escolhida1]<<"        |"<<"            "<<"\t|"<<valor[carta_escolhida2]<<"        |"<<endl;
            cout<<"\t|*   *    |"<<"   __  __   "<<"\t|*   *    |"<<endl;
            cout<<"\t|    |    |"<<"   \\ \\/ /   "<<"\t|    |    |"<<endl;
            cout<<"\t|  *-"<<naipes[carta_escolhida1]<<"-*  |"<<"    \\  /    "<<"\t|  *-"<<naipes[carta_escolhida2]<<"-*  |"<<endl;
            cout<<"\t|    |    |"<<"    /  \\    "<<"\t|    |    |"<<endl;
            cout<<"\t|    *   *|"<<"   /_/\\_\\   "<<"\t|    *   *|"<<endl;
            cout<<"\t|        "<<valor[carta_escolhida1]<<"|"<<"            "<<"\t|        "<<valor[carta_escolhida2]<<"|"<<endl;
            cout<<"\t ~~~~~~~~~"<<"            "<<"\t ~~~~~~~~~"<<endl;
            //marcar a carta escolhida
            if(jog_vez==1)
            {
                for(int i=0; i<3; i++)
                {
                    if(mao1[i]==carta_escolhida1)
                    {
                        mao1[i]=-1;
                    }
                    if (mao2[i]==carta_escolhida2)
                    {
                        mao2[i]=-1;
                    }
                }
            }
            else
            {
                for(int i=0; i<3; i++)
                {
                    if(mao2[i]==carta_escolhida1)
                    {
                        mao2[i]=-1;
                    }
                    if (mao1[i]==carta_escolhida2)
                    {
                        mao1[i]=-1;
                    }
                }
            }
            //comparações e anunciar o vencedor da jogada
            //verificar a manilha=vira+1
            //ambos tem a manilha
            if (((vira+1)%10==carta_escolhida1%10)&&((vira+1)%10==carta_escolhida2%10))
            {
                //analisar o naipe
                if (carta_escolhida1>carta_escolhida2)
                {
                    cout<<"\n\t Jogador "<<jog_vez<<" ganhou o round!"<<endl;
                    if(jog_vez==1)
                    {
                        vitoria1[round]=1;
                    }
                    else
                    {
                        vitoria2[round]=1;
                    }
                }
                else
                {
                    cout<<"\n\t Jogador "<<jog_n_vez<<" ganhou o round!"<<endl;
                    if(jog_n_vez==1)
                    {
                        vitoria1[round]=1;
                        jog_vez=1;
                    }
                    else
                    {
                        vitoria2[round]=1;
                        jog_vez=2;
                    }
                }
            }
            // jogador da vez tem a manilha e o que nao eh da vez não tem
            else if((vira+1)%10==carta_escolhida1%10)
            {
                cout<<"\n\t Jogador "<<jog_vez<<" ganhou o round!"<<endl;
                if(jog_vez==1)
                {
                    vitoria1[round]=1;
                }
                else
                {
                    vitoria2[round]=1;
                }
            }
            // jogador que nao eh da vez tem a manilha e o jogador da vez não tem
            else if ((vira+1)%10==carta_escolhida2%10)
            {
                cout<<"\n\t Jogador "<<jog_n_vez<<" ganhou o round!"<<endl;
                if(jog_n_vez==1)
                {
                    vitoria1[round]=1;
                    jog_vez=1;
                }
                else
                {
                    vitoria2[round]=1;
                    jog_vez=2;
                }
            }
            // nenhum dos dois tem a manilha
            else
            {
                if (carta_escolhida1%10>carta_escolhida2%10)
                {
                    cout<<"\n\t Jogador "<<jog_vez<<" ganhou o round!"<<endl;
                    if(jog_vez==1)
                    {
                        vitoria1[round]=1;
                    }
                    else
                    {
                        vitoria2[round]=1;
                    }
                }
                else if(carta_escolhida2%10>carta_escolhida1%10)
                {
                    cout<<"\n\t Jogador "<<jog_n_vez<<" ganhou o round!"<<endl;
                    if(jog_n_vez==1)
                    {
                        vitoria1[round]=1;
                        jog_vez=1;
                    }
                    else
                    {
                        vitoria2[round]=1;
                        jog_vez=2;
                    }
                }
                else
                {
                    cout<<"\n\t Empate\n";
                    vitoria1[round]=-1;
                    vitoria2[round]=-1;
                }
            }
            //analisar se deu empate no round 0:primeiro round
            if(round==1 &&(vitoria1[0]==-1 && vitoria2[0]==-1))
            {
                //ganha quem vencer o 2ºround, vence a partida
                if(vitoria1[1]==1)
                {
                    cout<<"\n\t Ponto para o Jogador 1!\n";
                    cout<<"\n\t         _  \n"<<"\t    _   / | \n"<<"\t  _| |_ | | \n"<<"\t |_   _|| | \n"<<"\t   |_|  |_| \n"<<endl;
                    pont_jog1++;
                    jog_vez=1;
                    break;
                }
                else if(vitoria2[1]==1)
                {
                    cout<<"\n\t Ponto para o Jogador 2!\n";
                    cout<<"\n\t         _  \n"<<"\t    _   / | \n"<<"\t  _| |_ | | \n"<<"\t |_   _|| | \n"<<"\t   |_|  |_| \n"<<endl;
                    pont_jog2++;
                    jog_vez=2;
                    break;
                }
            }
            //empate no 2ºround
            else if(round==1 &&(vitoria1[1]==-1 && vitoria2[1]==-1))
            {
                //ganha quem vencer o 2ºround, vence a partida
                if(vitoria1[0]==1)
                {
                    cout<<"\n\t Ponto para o Jogador 1!\n";
                    cout<<"\n\t         _  \n"<<"\t    _   / | \n"<<"\t  _| |_ | | \n"<<"\t |_   _|| | \n"<<"\t   |_|  |_| \n"<<endl;
                    pont_jog1++;
                    jog_vez=1;
                    break;
                }
                else if(vitoria2[0]==1)
                {
                    cout<<"\n\t Ponto para o Jogador 2!\n";
                    cout<<"\n\t         _  \n"<<"\t    _   / | \n"<<"\t  _| |_ | | \n"<<"\t |_   _|| | \n"<<"\t   |_|  |_| \n"<<endl;
                    pont_jog2++;
                    jog_vez=2;
                    break;
                }
            }
            //empate no terceiro round
            else if(round==2 &&(vitoria1[2]==-1 && vitoria2[2]==-1))
            {
                //ganha quem vencer o 1ºround, vence a partida
                if(vitoria1[0]==1)
                {
                    cout<<"\n\t Ponto para o Jogador 1!\n";
                    cout<<"\n\t         _  \n"<<"\t    _   / | \n"<<"\t  _| |_ | | \n"<<"\t |_   _|| | \n"<<"\t   |_|  |_| \n"<<endl;
                    pont_jog1++;
                    jog_vez=1;
                    break;
                }
                else if(vitoria2[0]==1)
                {
                    cout<<"\n\t Ponto para o Jogador 2!\n";
                    cout<<"\n\t         _  \n"<<"\t    _   / | \n"<<"\t  _| |_ | | \n"<<"\t |_   _|| | \n"<<"\t   |_|  |_| \n"<<endl;
                    pont_jog2++;
                    jog_vez=2;
                    break;
                }
            }
            //empate em todos
            else if(vitoria1[0]==-1 &&vitoria1[1]==-1 &&vitoria1[2]==-1)
            {
                cout<<"\n\t Ninguem ganhou ponto!"<<endl;
                break;
            }
            //nao deu empate em nenhum
            //jogador 1 venceu dois round seguidos
            else if(vitoria1[0]==1&&vitoria1[1]==1)
            {
                cout<<"\n\t Ponto para o Jogador 1! \n";
                cout<<"\n\t         _  \n"<<"\t    _   / | \n"<<"\t  _| |_ | | \n"<<"\t |_   _|| | \n"<<"\t   |_|  |_| \n"<<endl;
                pont_jog1++;
                jog_vez=1;
                break;
            }
            //jogador 2 venceu dois round seguidos
            else if(vitoria2[0]==1&&vitoria2[1]==1)
            {
                cout<<"\n\t Ponto para o Jogador 2!\n";
                cout<<"\n\t         _  \n"<<"\t    _   / | \n"<<"\t  _| |_ | | \n"<<"\t |_   _|| | \n"<<"\t   |_|  |_| \n"<<endl;
                pont_jog2++;
                jog_vez=2;
                break;
            }
            //analisar a somatoria de vitorias total
            else if(round==2)
            {
                soma1=0;
                soma2=0;
                for(int i=0; i<3; i++)
                {
                    soma1=soma1+vitoria1[i];
                    soma2=soma2+vitoria2[i];
                }
                if(soma1>soma2)
                {
                    cout<<"\n\t Ponto para o Jogador 1! \n";
                    cout<<"\n\t         _  \n"<<"\t    _   / | \n"<<"\t  _| |_ | | \n"<<"\t |_   _|| | \n"<<"\t   |_|  |_| \n"<<endl;
                    pont_jog1++;
                    jog_vez=1;
                }
                else
                {
                    cout<<"\n\t Ponto para o Jogador 2!\n";
                    cout<<"\n\t         _  \n"<<"\t    _   / | \n"<<"\t  _| |_ | | \n"<<"\t |_   _|| | \n"<<"\t   |_|  |_| \n"<<endl;
                    pont_jog2++;
                    jog_vez=2;
                }

            }
            //incrementar o round
            round++;
            sleep(3);
            system("clear");
        }//fim de cada partida
        sleep(1);
        system("clear");

        cout<<"\n\n\t _____________________________"<<endl;
        cout<<"\t|  __            __       __  |"<<endl;
        cout<<"\t| |__) |    /\\  /    /\\  |__) |"<<endl;
        cout<<"\t| |    |__ /--\\ \\__ /--\\ | \\  |"<<endl;
        cout<<"\t|                             |"<<endl;
        cout<<"\t|    JOGADOR 1   JOGADOR 2    |"<<endl;
        cout<<"\t|            "<<pont_jog1<<" X "<<pont_jog2<<"            |"<<endl;
        cout<<"\t|_____________________________|"<<endl;
        sleep(3);
        system("clear");
    }
    cout<<endl<<endl<<"'||''|.      |     '||''|.       |     '||''|. * '||''''|  '|.   '|'  .|'''.| "<<endl;
    cout<<" ||   ||    ||| *   ||   || *   |||     ||   ||   ||  .     |'|   |   ||..  '  "<<endl;
    cout<<" ||...|'   |  ||    ||''|'     |  ||*   ||'''|.   ||''|     | '|. |    ''|||.  "<<endl;
    cout<<" ||       .''''|. * ||   |.   .''''|.   ||    ||  ||   *    |   |||  . *   '|| "<<endl;
    cout<<".||.  *  .|.  .||. .||.  '|' .|.  .||. .||...|'  .||.....| .|.   '|  |'....|'  "<<endl;
}

