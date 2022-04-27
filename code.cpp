#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <cmath>
#include <windows.h>
#include <string>
#include <time.h>
#include <fstream>
#include <cstring>
#include <string>
#include <cctype>
//#include<limits>


 char xadrez[12][12]=
{
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
    ' ', '-', '1', '2', '3', '4', '5', '6', '7', '8', '-', ' ',   /*TABULEIRO,  USEI UMA MATRIZ  12x12*/
    ' ', '1', 't', 'c', 'b', 'k', 'q', 'b', 'c', 't', '|', ' ',
    ' ', '2', 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p', '|', ' ',
    ' ', '3', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ',
    ' ', '4', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ',
    ' ', '5', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ',
    ' ', '6', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ',
    ' ', '7', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', '|', ' ',
    ' ', '8', 'T', 'C', 'B', 'Q', 'K', 'B', 'B', 'T', '|', ' ',
    ' ', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', ' ',
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
};

template <class T> //Tempo
T TempoRestante(T Tempototal,T Tempogasto){
T TRestante = (Tempototal - (Tempogasto/1000));
    return TRestante;                                   //Para calcular quanto tempo resta total, sendo divido em segundo pois é dado em milissegundos

}

void printartorre1(void);
void printarcavalo1(void);
void printarbispo1(void);
void printarrainha1(void);
void printarrei1(void);
void printarpeao1(void);
void printartorre2(void);                   //funções para printar o 'x' no tabuleiro
void printarcavalo2(void);
void printarbispo2(void);
void printarrainha2(void);
void printarrei2(void);
void printarpeao2(void);

void jogador1(void);                     //funçoes onde o jogadores colocam suas jogadas e ela é verificada
void jogador2(void);

void jogadorbranco(void);                 //funções apenas para dicromática, apenas para dar cor preto e branco
void jogadorpreto(void);

void menu(void);
void tutorial(void);                       //funções de texto

void abrirarquivo(void);                    //função para abrir o arquivo e ler o que tem dentro

void printartabuleiro(void);                   //função para printar o tabuleiro já colorido



int main(void)
{
    int escolhadojogador;
    float tempototal=300.0;       //default 300 segundos
    int querjogar=0;
    while(querjogar==0){         //coloquei while para retornar caso escolha uma opcao que é interessante voltar pro menu, por exemplo REGRAS e MUDAR TEMPO

        menu();
        std::cout << "Escolha uma das opcoes acima: ";
        std::cin >> escolhadojogador;
        if(escolhadojogador==4){          //caso o usuario quer ver o menu
            tutorial();
            continue;
        }
        if(escolhadojogador==3){
            std::cout << "Digite o limite de tempo total individual em segundos: " << std::endl;
            std::cin >> tempototal;
            continue;
        }
        if(escolhadojogador==1){
            querjogar = 1;
        }
        if(escolhadojogador==2){
            abrirarquivo();
            continue;
        }
        if(escolhadojogador==5){
            querjogar=1;
            continue;
        }
        float Tinicio, Tfim, Tdecorrido1, Tdecorrido2, Tgasto1=0, Tgasto2=0;
        int rodada=0;
        std::string nomejogador1;
        std::cout << "  Nome do jogador 1 (pecas maiusculas): ";          //apenas para ficar mais bonito, mostrar o número da rodada e também o nome do jogador em si
        std::cin >> nomejogador1;
        std::string nomejogador2;
        jogadorpreto();
        std::cout << "  Nome do jogador 2 (pecas minusculas): ";
        std::cin >> nomejogador2;
        std::ofstream arquivo;
        arquivo.open("xadrez.txt", std::ios::app);                       //mesma coisa, mas escrever isso dentro de um arquivo temporario "xadrez.txt"
        arquivo << "\n";                                                   //explicarei mais porque chamo esse arquivo de temporário quando depois e está no doc explicativo do código.
        arquivo << "ARQUIVO DE PARTIDA DE XADREZ: COM OS DOIS JOGADORES SEGUINTES";
        arquivo << "\n";
        arquivo << "Jogador das pecas maiusculas/brancas: " << nomejogador1 << std::endl;
        arquivo << "Jogador das pecas minusculas/pretas: " << nomejogador2 << std::endl;
        arquivo << "\n";
        arquivo.close();
        while(1){
            rodada = rodada + 1;
            arquivo.open("xadrez.txt", std::ios::app);
            arquivo << "\n";
            arquivo << "RODADA " << rodada << std::endl;
            arquivo << "\n";
            arquivo << "Vez do jogador " << nomejogador1 << "." << std::endl;
            arquivo << "\n";
            arquivo.close();
            std::cout << "\n";
            jogadorbranco();    //estético
            Tinicio = clock();
            std::cout << "        RODADA " << rodada << " do/da " << nomejogador1 << std::endl;
            std::cout << "        Resta: " << TempoRestante(tempototal, Tgasto1) << " segundos" << std::endl;
            std::cout << "\n" << std::endl;
            jogador1();           //jogador 1 efetuando sua jogada
            Tfim = clock();
            Tdecorrido1 = Tfim - Tinicio;
            std::cout << "\n";
            jogadorpreto();
            Tinicio = clock();
            std::cout << "        RODADA " << rodada << " do/da " << nomejogador2 << "         " << std::endl;
            std::cout << "        Resta: " << TempoRestante(tempototal, Tgasto2) << " segundos" << "          " << std::endl;
            jogadorbranco();
            arquivo.open("xadrez.txt", std::ios::app);
            arquivo << "\n";
            arquivo << "Vez do jogador " << nomejogador2 << "." << std::endl;
            arquivo << "\n";
            arquivo.close();
            jogador2();            //jogador 2 efetuando sua jogada
            Tfim = clock();
            Tdecorrido2 = Tfim - Tinicio;
            Tgasto1 = Tdecorrido1 + Tgasto1;
            Tgasto2 = Tdecorrido2 + Tgasto2;
            if((TempoRestante(tempototal, Tgasto1)) < 0)  //para caso um dos jogador zere o tempo total de sua partida, ele automaticamente perde
            {
                std::cout << nomejogador2 << " VENCEU O JOGO! O jogado adversario(" << nomejogador1 << ") foi lento demais!";
                arquivo << "\n";
                arquivo << nomejogador2 << " VENCEU O JOGO! O jogado adversario(" << nomejogador1 << ") foi lento demais!";
                arquivo << "\n";
                arquivo.close();
                break;
            }
            if((TempoRestante(tempototal, Tgasto2)) < 0)
            {
                std::cout << nomejogador1 << " VENCEU O JOGO! O jogado adversario(" << nomejogador2 << ") foi lento demais!";
                arquivo << "\n";
                arquivo << nomejogador1 << " VENCEU O JOGO! O jogado adversario(" << nomejogador2 << ") foi lento demais!";
                arquivo << "\n";
                arquivo.close();
                break;
            }
        }


    }

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void abrirarquivo(void){
    std::string continuar;
    std::cout<< "\n" << std::endl;
    std::ifstream arquive;
    std::string linha;
    std::cout << "Qual o nome do arquivo que quer abrir? (Digite sem o "".txt"")" << std::endl;  //o kogador não precisará colocar .txt, para caso ele não saiba qual tipo colocar, na linha abaixo tratamos isso
    char ArquivoQueSeraAberto[15];
    std::cin >> ArquivoQueSeraAberto;
    std::strcat(ArquivoQueSeraAberto, ".txt");  //o nome que o jogador recebeu é concatenado com .txt

    arquive.open(ArquivoQueSeraAberto);
    if(arquive.is_open()){                     //enqunto o arquivo estiver aberto, ele vai printando linha por linha
        while(getline(arquive, linha)){           //MAS se a linha tiver "..." ele para o programa para apertar Enter
            if(linha == "..."){                    //fiz isso para que o arquivo mostre jogada a jogada e não printe tudo que está dentro de uma vez.
               system("pause");
            }else{
            std::cout<< linha << std::endl;   //se não, printa a linha toda
            }
        }
        std::cout << "PARTIDA FINALIZADA." << std::endl;
    }else{
        std::cout << "ERRO: nenhum arquivo .txt foi encontrado com esse nome" << std::endl;
        }
    arquive.close();
    std::cout<< linha << std::endl;
    std::cout << "\n" << std::endl;
    std::cout << "Digite Q caso queira finalizar o programa: ";  //Após mostrar a partida inteira, digite Q para você fechar o programa
    std::cin >> continuar;
    if((continuar.compare("Q"))==0)
    {
        exit(0);
    }
    std::cout << "\n" << std::endl;
}

void jogadorbranco(void){
    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 15);
}
                                                        //apenas para colocar cores
void jogadorpreto(void){
    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 240);
}

void tutorial(void){
HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(h, 262);
std::cout << "\n";
std::cout << "\n";
std::cout << " 1 - Este jogo foi feito para ser jogado em duas pessoas" << std::endl;
std::cout << " 2 - TEMPO DE JOGO! Esse jogo ha uma implementacao para deixar o xadrez mais dinamico e divertido:" << std::endl;
std::cout << "   --> Voce pode escolher colocar um tempo total para os jogadores, cada rodada esse tempo diminui. " << std::endl;
std::cout << "   --> Quando o seu tempo acaba voce automaticamente PERDE! Portanto, seja rapido na sua jogada!" << std::endl;
std::cout << "   --> O tempo padrao desse jogo eh 300 segundos (5 minutos), mas voce pode alterar no menu na opcao 3." << std::endl;
std::cout << " 3 - Quanto a movimentacao das pecas:" << std::endl;
std::cout << "   --> Peao: Na primeira jogada pode andar ate duas casas para a frente, apos esta, apenas uma casa por jogada e captura apenas em diagonal." << std::endl;
std::cout << "   --> Bispo: Movimenta - se e captura apenas em diagonal sem restricao de quantidade de casas." << std::endl;
std::cout << "   --> Cavalo: Movimenta - se e captura apenas em formato de L (captura apenas no final do movimento)." << std::endl;
std::cout << "   --> Torre: Movimenta - se e captura apenas em linha reta na horizontal e na vertical." << std::endl;
std::cout << "   --> Rainha/Queen: Movimenta - se em linha reta horizontalmente e verticalmente, ou ainda, em diagonal, captura no mesmo caminho em que se move." << std::endl;
std::cout << "   --> Rei/King: Movimenta - se como a Rainha mas restringido a movimentar apenas uma casa por vez, captura no mesmo caminho em que se move." << std::endl;
std::cout << " 4 - Promotion: Regra que consiste na troca de um peao que alcancar a ultima fileira (oitava) do tabuleiro por qualquer outra peca do jogo(substituicao na mesma casa em que se encontra o peao." << std::endl;
std::cout << " 5 - Encerramento da Partida: A partida se encerra apenas com a captura do Rei/King." << std::endl;
std::cout << "\n";
std::cout << "\n";
}

void menu(void) {

HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(h, 86);
std::cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&" << std::endl;
std::cout << "&&&&          &&&&&&  &&&&&&&&&&  &&&&           &&&&&          &&&&&&           &&&" << std::endl;
std::cout << "&&   &&&&&&&&  &&&&&  &&&&&&&&&&  &&&&   &&&&&&&&&&&&  &&&&&&&&   &&&  &&&&&&&&   &&" << std::endl;
std::cout << "&&  &&&&&&&&&&&&&&&&  &&&&&&&&&&  &&&&   &&&&&&&&&&&&   &&&&&&&&&&&&&   &&&&&&&&&&&&" << std::endl;
std::cout << "&&  &&&&&&&&&&&&&&&&              &&&&           &&&&&&       &&&&&&&&&       &&&&&&" << std::endl;
std::cout << "&&  &&&&&&&&&&&&&&&&  &&&&&&&&&&  &&&&   &&&&&&&&&&&&&&&&&&&&   &&&&&&&&&&&&&    &&&" << std::endl;
std::cout << "&&  &&&&&&&&&&  &&&&  &&&&&&&&&&  &&&&   &&&&&&&&&&&   &&&&&&&&   &&   &&&&&&&&   &&" << std::endl;
std::cout << "&&&   &&&&&&   &&&&&  &&&&&&&&&&  &&&&   &&&&&&&&&&&&   &&&&&    &&&    &&&&&&    &&" << std::endl;
std::cout << "&&&&&        &&&&&&&  &&&&&&&&&&  &&&&            &&&&&       &&&&&&&&        &&&&&&" << std::endl;
std::cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&" << std::endl;
jogadorbranco();
std::cout << "\n";


std::cout << "  1 - ";
SetConsoleTextAttribute(h, 96);
std::cout << "INICIAR UMA PARTIDA"<< std::endl;
jogadorbranco();
std::cout << "  2 - ";
SetConsoleTextAttribute(h, 96);
std::cout << "ABRIR UMA PARTIDA"<< std::endl;
jogadorbranco();

std::cout << "  3 - ";
SetConsoleTextAttribute(h, 96);
std::cout << "MUDAR O LIMITE DE TEMPO"<< std::endl;
jogadorbranco();

std::cout << "  4 - ";
SetConsoleTextAttribute(h, 96);
std::cout << "REGRAS"<< std::endl;
jogadorbranco();

std::cout << "  5 - ";
SetConsoleTextAttribute(h, 96);
std::cout << "FECHAR O GAME"<< std::endl;


std::cout << "\n";
jogadorbranco();
}
void printartabuleiro(void){
    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);        //mostrando o tabuleiro
    int t, i;                                        //variaveis de PRINTAR o tabuleiro, não manipularei os valores dela fora dos for durante o código
    int corTabuleiro = 0;
    for(t=0; t<12; ++t) {
        for(i=0; i<12; ++i){
            if((t==0) || (t==11) || (i==0) || (i==11) || (t==1) || (t==10) || (i==1) || (i==10)){      //para que as bordas fiquem roxas, como uma mesa
                SetConsoleTextAttribute(h, 94);
                std::cout << "  "  << xadrez[t][i];
            }else{                                 //aqui a estratégia para printar em preto e branco foi a seguinte:
                corTabuleiro += 1;
                if(corTabuleiro%9==0){           //explico abaixo
                    corTabuleiro += 1;
                }
                if(corTabuleiro%2==0){            //se essa variavel for divisivel por 2, pinta o backgrounf de preto, se não irá pintar de branco, igual o xadrez
                    SetConsoleTextAttribute(h, 262);   //MAS quando chega no final de uma linha, e desde para baixo, a ultima cor precisa se repetir, por isso acima
                    std::cout << "  "  << xadrez[t][i]; //dividi por 9 para quando percorra todas as colnas de uma linha ele some mais um e repita o background anterior.
                }else{
                    SetConsoleTextAttribute(h, 246);
                    std::cout << "  " << xadrez[t][i];
                }

            }
        }
    std::cout << "\n";
      }
    SetConsoleTextAttribute(h, 15);
}

void printartorre1(int a,int b){   //aqui começa as funções de printar os x no tabuleiro, recebem 2 parametros, as coordenadas das linhas e colunas da peça que quer mover respectivamente
 /*cima*/
        int l, c, t, i;
        l=a-1;                              //percorre as casa verticais para cima
        c=b;
        if (xadrez[l][c] ==' ' ) {
            while(xadrez[l][c] == ' ') {    //enquanto for vazio coloca os 'x'
            xadrez[l][c]='x';
            l=l-1;
            }
        }
        /*baixo*/
        l=a+1;
        c=b;
        if (xadrez[l][c] ==' ' ) {
            while(xadrez[l][c] == ' ') {
            xadrez[l][c]='x';
            l=l+1;
            }
        }
    /*esquerda*/
        l=a;
        c=b-1;
        if (xadrez[l][c] ==' ' ) {
            while(xadrez[l][c] == ' ') {
            xadrez[l][c]='x';
            c=c-1;
            }
        }
    /*direita*/
        l=a;
        c=b+1;
        if (xadrez[l][c] ==' ' ) {
            while(xadrez[l][c] == ' ') {
            xadrez[l][c]='x';
            c=c+1;
            }
        }

        printartabuleiro();      //por fim printa o tabuleiro com os x
}



void printarcavalo1(int a, int b){
        int l, c, t, i;
 /*cima esquerda*/
        l=a-2;       //a logica aqui é coloca os x em cada posicao que o cavalo poderia estar se estiver vazia
        c=b-1;
        if(xadrez[l][c]==' '){
            xadrez[l][c]='x';
        }

    /*cima esquerda*/
        l=a-2;
        c=b-1;
        if(xadrez[l][c]==' '){
            xadrez[l][c]='x';
        }

    /*baixo esquerda*/
        l=a+2;
        c=b-1;
        if(xadrez[l][c]==' '){
            xadrez[l][c]='x';
        }

    /*cima direita*/
        l=a-2;
        c=b+1;
        if(xadrez[l][c]==' '){
            xadrez[l][c]='x';
        }

    /*baixo direito*/
        l=a+2;
        c=b+1;
        if(xadrez[l][c]==' '){
            xadrez[l][c]='x';
    }

    /*esquerda baixo*/
        l=a+1;
        c=b-2;
        if(xadrez[l][c]==' '){
            xadrez[l][c]='x';
        }

    /*esquerda cima*/
        l=a-1;
        c=b-2;
        if(xadrez[l][c]==' '){
            xadrez[l][c]='x';
        }

    /*direita baixo*/
        l=a+1;
        c=b+2;
        if(xadrez[l][c]==' '){
            xadrez[l][c]='x';
        }

    /*direita cima*/
        l=a-1;
        c=b+2;
        if(xadrez[l][c]==' '){
            xadrez[l][c]='x';
        }

        for(t=0; t<12; ++t) {
                for(i=0; i<12; ++i){
                        if((t==0) || (i==0) || (t==11) || (i==11)){         //para que não printe x fora do tabuleiro, o cavalo era o único que permitia esse erro por "pular"
                            if(xadrez[t][i]=='x'){
                            xadrez[t][i]=' ';
                            }
                        }

                    }
                }

         printartabuleiro();
}

void printarbispo1(int a, int b){
    int l, c, t, i;
    /*cima direita*/
        l=a-1;              //percorrendo na diagonal
        c=b+1;
        if (xadrez[l][c] ==' ' ) {
            while(xadrez[l][c] == ' ') {
               xadrez[l][c]='x';
                l=l-1;
                c=c+1;
            }
        }
    /*cima esquerda*/
        l=a-1;
        c=b-1;
        if (xadrez[l][c] ==' ' ) {
            while(xadrez[l][c] == ' ') {
                xadrez[l][c]='x';
                l=l-1;
                c=c-1;
            }
        }

    /*baixo direita*/
        l=a+1;
        c=b+1;
        if (xadrez[l][c] ==' ' ) {
            while(xadrez[l][c] == ' ') {
                xadrez[l][c]='x';
                l=l+1;
                c=c+1;
            }
        }

    /*baixo esquerda*/
        l=a+1;
        c=b-1;
        if (xadrez[l][c] == ' ' ) {
            while(xadrez[l][c] == ' ') {
            xadrez[l][c]='x';
            l=l+1;
            c=c-1;
            }
        }

         printartabuleiro();
}


void printarrainha1(int a, int b){  //basicamete o bispo + torre
    int t, i, l, c;
    /*cima*/
        l=a-1;
        c=b;
        if (xadrez[l][c] ==' ' ) {
            while(xadrez[l][c] == ' ') {
                xadrez[l][c]='x';
                l=l-1;
            }
        }

    /*baixo*/
        l=a+1;
        c=b;
        if (xadrez[l][c] ==' ' ) {
            while(xadrez[l][c] == ' ') {
                xadrez[l][c]='x';
                l=l+1;
            }
        }

    /*esquerda*/
        l=a;
        c=b-1;
        if (xadrez[l][c] ==' ' ) {
            while(xadrez[l][c] == ' ') {
                xadrez[l][c]='x';
                c=c-1;
            }
        }

    /*direita*/
        l=a;
        c=b+1;
        if (xadrez[l][c] ==' ' ) {
            while(xadrez[l][c] == ' ') {
                xadrez[l][c]='x';
                c=c+1;
            }
        }

    /*cima direita*/
        l=a-1;
        c=b+1;
        if (xadrez[l][c] ==' ' ) {
            while(xadrez[l][c] == ' ') {
                xadrez[l][c]='x';
                l=l-1;
                c=c+1;
            }
        }

    /*cima esquerda*/
        l=a-1;
        c=b-1;
        if (xadrez[l][c] ==' ' ) {
            while(xadrez[l][c] == ' ') {
                xadrez[l][c]='x';
                l=l-1;
                c=c-1;
            }
        }


    /*baixo direita*/
        l=a+1;
        c=b+1;
        if (xadrez[l][c] ==' ' ) {
            while(xadrez[l][c] == ' ') {
                xadrez[l][c]='x';
                l=l+1;
                c=c+1;
            }
        }


        /*baixo esquerda*/
        l=a+1;
        c=b-1;
        if (xadrez[l][c] ==' ' ) {
            while(xadrez[l][c] == ' ') {
                xadrez[l][c]='x';
                l=l+1;
                c=c-1;
            }
        }

         printartabuleiro();


}

void printarrei1(int a, int b){
    int t, i, l, c;
    /*cima*/
        l=a-1;
        c=b;
        if (xadrez[l][c] ==' ' ) {
            xadrez[l][c]='x';
    }

    /*baixo*/
        l=a+1;
        c=b;
        if (xadrez[l][c] ==' ' ) {
            xadrez[l][c]='x';
        }

    /*esquerda*/
        l=a;
        c=b-1;
        if (xadrez[l][c] ==' ' ) {
            xadrez[l][c]='x';
        }

    /*direita*/
        l=a;
        c=b+1;
        if (xadrez[l][c] ==' ' ) {
            xadrez[l][c]='x';
        }

      /*cima direita*/
        l=a-1;
        c=b+1;
        if (xadrez[l][c] ==' ' ) {
            xadrez[l][c]='x';
        }

    /*cima esquerda*/
        l=a-1;
        c=b-1;
        if (xadrez[l][c] ==' ' ) {
            xadrez[l][c]='x';
        }

    /*baixo direita*/
        l=a+1;
        c=b+1;
        if (xadrez[l][c] ==' ' ) {
            xadrez[l][c]='x';
        }

    /*baixo esquerda*/
        l=a+1;
        c=b-1;
        if (xadrez[l][c] ==' ' ) {
            xadrez[l][c]='x';
        }

         printartabuleiro();
}

void printarpeao1(int a, int b){   //pro peao, tem que ter um detalhe, se for a primeira rodada dele, ele pode andar 2 casas, portanto pode ter de printar 2 x
    int t, i, l, c;
     if (a==8){                //isso acontece quando as peças do jogador 1 esta na linha 8 (aqui tá 8, pq somaremos linha e coluna em uma unidade)
    /*cima*/
            l=a-2;
            c=b;
            if (xadrez[l][c] ==' ' ) {
                xadrez[l][c]='x';
            }
            l=a-1;
            c=b;
            if (xadrez[l][c] ==' ' ) {
                xadrez[l][c]='x';
            }
        }
        else{
            l=a-1;
            c=b;
            if (xadrez[l][c] ==' ' ) {
                xadrez[l][c]='x';
            }

        }

        printartabuleiro();

}

void printartorre2(int a, int b){   //aqui é pro jogador 2, a estrátegia é a mesma
    int t, i, l, c;                 //MAS a estrátegia foi "espelhar" as jogadas do jogador 1, ou seja
    /*cima*/                         //enquanto o peao do jogador 2 anda para baixo, aumentando a linha, o do jogador 1 sobe diminuindo 1
        l=a+1;                      // é basicamente esse espelhamento a diferença dessas funções, portanto, não irei repetir
        c=b;
        if (xadrez[l][c] ==' ' ) {
            while(xadrez[l][c] == ' ') {
            xadrez[l][c]='x';
            l=l+1;
            }
        }
        /*baixo*/
        l=a-1;
        c=b;
        if (xadrez[l][c] ==' ' ) {
            while(xadrez[l][c] == ' ') {
            xadrez[l][c]='x';
            l=l-1;
            }
        }
    /*esquerda*/
        l=a;
        c=b+1;
        if (xadrez[l][c] ==' ' ) {
            while(xadrez[l][c] == ' ') {
            xadrez[l][c]='x';
            c=c+1;
            }
        }
    /*direita*/
        l=a;
        c=b-1;
        if (xadrez[l][c] ==' ' ) {
            while(xadrez[l][c] == ' ') {
            xadrez[l][c]='x';
            c=c-1;
            }
        }

         printartabuleiro();

}

void printarcavalo2(int a, int b){
    int t, i, l, c;
    //NOROESTE
        l=a+2;
        c=b+1;
        if(xadrez[l][c]==' '){
            xadrez[l][c]='x';
        }
    //SUDOESTE
        l=a-2;
        c=b+1;
        if(xadrez[l][c]==' '){
            xadrez[l][c]='x';
        }

    //NORDESTE
        l=a+2;
        c=b-1;
        if(xadrez[l][c]==' '){
            xadrez[l][c]='x';
        }

    //SUDESTE
        l=a-2;
        c=b-1;
        if(xadrez[l][c]==' '){
            xadrez[l][c]='x';
    }

    //SUDOESTE
        l=a-1;
        c=b+2;
        if(xadrez[l][c]==' '){
            xadrez[l][c]='x';
        }

    //NOROESTE
        l=a+1;
        c=b+2;
        if(xadrez[l][c]==' '){
            xadrez[l][c]='x';
        }

    //SUDESTE
        l=a-1;
        c=b-2;
        if(xadrez[l][c]==' '){
            xadrez[l][c]='x';
        }

    //NORDESTE
        l=a+1;
        c=b-2;
        if(xadrez[l][c]==' '){
            xadrez[l][c]='x';
        }

         for(t=0; t<12; ++t) {
                for(i=0; i<12; ++i){
                        if((t==0) || (i==0) || (t==11) || (i==11)){
                            if(xadrez[t][i]=='x'){
                            xadrez[t][i]=' ';
                            }
                        }

                }
         }

         printartabuleiro();


}

void printarbispo2(int a, int b){
    int t, i, l, c;
    //NORDESTE
        l=a+1;
        c=b-1;
        if (xadrez[l][c] ==' ' ) {
            while(xadrez[l][c] == ' ') {
               xadrez[l][c]='x';
                l=l+1;
                c=c-1;
            }
        }
    //NOROESTE
        l=a+1;
        c=b+1;
        if (xadrez[l][c] ==' ' ) {
            while(xadrez[l][c] == ' ') {
                xadrez[l][c]='x';
                l=l+1;
                c=c+1;
            }
        }

    //SUDESTE
        l=a-1;
        c=b-1;
        if (xadrez[l][c] ==' ' ) {
            while(xadrez[l][c] == ' ') {
                xadrez[l][c]='x';
                l=l-1;
                c=c-1;
            }
        }

    //SUDOESTE
        l=a-1;
        c=b+1;
        if (xadrez[l][c] == ' ' ) {
            while(xadrez[l][c] == ' ') {
            xadrez[l][c]='x';
            l=l-1;
            c=c+1;
            }
        }

         printartabuleiro();
}

void printarrainha2(int a, int b){
    int t, i, l, c;
      /*cima*/
        l=a+1;
        c=b;
        if (xadrez[l][c] ==' ' ) {
            while(xadrez[l][c] == ' ') {
                xadrez[l][c]='x';
                l=l+1;
            }
        }

    /*baixo*/
        l=a-1;
        c=b;
        if (xadrez[l][c] ==' ' ) {
            while(xadrez[l][c] == ' ') {
                xadrez[l][c]='x';
                l=l-1;
            }
        }

    /*esquerda*/
        l=a;
        c=b+1;
        if (xadrez[l][c] ==' ' ) {
            while(xadrez[l][c] == ' ') {
                xadrez[l][c]='x';
                c=c+1;
            }
        }

    /*direita*/
        l=a;
        c=b-1;
        if (xadrez[l][c] ==' ' ) {
            while(xadrez[l][c] == ' ') {
                xadrez[l][c]='x';
                c=c-1;
            }
        }

    /*cima direita*/
        l=a+1;
        c=b-1;
        if (xadrez[l][c] ==' ' ) {
            while(xadrez[l][c] == ' ') {
                xadrez[l][c]='x';
                l=l+1;
                c=c-1;
            }
        }

    /*cima esquerda*/
        l=a+1;
        c=b+1;
        if (xadrez[l][c] ==' ' ) {
            while(xadrez[l][c] == ' ') {
                xadrez[l][c]='x';
                l=l+1;
                c=c+1;
            }
        }


    /*baixo direita*/
        l=a-1;
        c=b-1;
        if (xadrez[l][c] ==' ' ) {
            while(xadrez[l][c] == ' ') {
                xadrez[l][c]='x';
                l=l-1;
                c=c-1;
            }
        }


        /*baixo esquerda*/
        l=a-1;
        c=b+1;
        if (xadrez[l][c] ==' ' ) {
            while(xadrez[l][c] == ' ') {
                xadrez[l][c]='x';
                l=l-1;
                c=c+1;
            }
        }

        printartabuleiro();
}

void printarrei2(int a, int b){
    int t, i, l, c;
     /*cima*/
        l=a+1;
        c=b;
        if (xadrez[l][c] ==' ' ) {
            xadrez[l][c]='x';
    }

    /*baixo*/
        l=a-1;
        c=b;
        if (xadrez[l][c] ==' ' ) {
            xadrez[l][c]='x';
        }

    /*esquerda*/
        l=a;
        c=b+1;
        if (xadrez[l][c] ==' ' ) {
            xadrez[l][c]='x';
        }

    /*direita*/
        l=a;
        c=b-1;
        if (xadrez[l][c] ==' ' ) {
            xadrez[l][c]='x';
        }

      /*cima direita*/
        l=a+1;
        c=b-1;
        if (xadrez[l][c] ==' ' ) {
            xadrez[l][c]='x';
        }

    /*cima esquerda*/
        l=a+1;
        c=b+1;
        if (xadrez[l][c] ==' ' ) {
            xadrez[l][c]='x';
        }

    /*baixo direita*/
        l=a-1;
        c=b-1;
        if (xadrez[l][c] ==' ' ) {
            xadrez[l][c]='x';
        }

    /*baixo esquerda*/
        l=a-1;
        c=b+1;
        if (xadrez[l][c] ==' ' ) {
            xadrez[l][c]='x';
        }

         printartabuleiro();


}

void printarpeao2(int a, int b){
    int t, i, l, c;
     if (a==3){
    /*cima*/
            l=a+2;
            c=b;
            if (xadrez[l][c] ==' ' ) {
                xadrez[l][c]='x';
            }
            l=a+1;
            c=b;
            if (xadrez[l][c] ==' ' ) {
                xadrez[l][c]='x';
            }
        }
        else{
            l=a+1;
            c=b;
            if (xadrez[l][c] ==' ' ) {
                xadrez[l][c]='x';
            }

        }

        printartabuleiro();

}



void jogador1(void)
{
HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
int contator = 0;
int contator2 = 0;
int contator3 = 0;
int contator4 = 0;
int jogadnv = 0;
int movimentolinha;
int movimentocoluna;
std::string querosalvar;
char nomedojogo[20];
std::string querocontinuar;
while(jogadnv == 0){  //para caso uma jogada seja inválida perguntar de novo
       jogadnv = 0;
       int pesa;
       int x,y,a,b;                                //explicando essas variaveis:   a e b são as coordenadas da peça que escolheu movimentar acrescido de uma unidade
       unsigned  int l,c;                                                          //x e y é as coordenadas para onde ele quer movimenta-la
       int t,i;                                                                       //l e c são coordenadas para fazer manipulações em a e b ou x e y sem perder as informações delas
                                                                                        //t e i apenas para printar o tabuleiro
    printartabuleiro();

    std::cout << "Escolha a peca que quer movimentar: (linha:3 e coluna:7) " << std::endl;
    std::cout << "Linha: ";
    std::cin >> a;
    std::ofstream arquivo;



    std::cout << "Coluna: ";
    std::cin >> b;
    l = a;
    c = b;

    a = a + 1;  //soma 1, pq começa com 0 os indices
    b = b + 1;


    arquivo.open("xadrez.txt", std::ios::app);
    arquivo << "Jogador das pecas maiusculas/brancas movimentou a peca da linha " << a-1 << " e coluna " << b-1 << std::endl;
    arquivo.close();

    arquivo.open("xadrez.txt", std::ios::app);
    for(t=0; t<12; ++t) {
        for(i=0; i<12; ++i){
                arquivo << "  "  << xadrez[t][i];
        }
    arquivo << "\n";
    }
    std::cout << "\n";
    arquivo.close();


    if((a>9) ||  (b>9) || (a<1) || (b<1))  //para que só escolha uma peça que esteja no tabuleiro
    {
        std::cout << "Digite coordenadas do tabuleiro, apenas de 1 a 8." << std::endl;
        continue;
    }

    //TORRE
    if (xadrez[a][b]=='T'){  //escolheu torre
        printartorre1(a,b);

        std::cout << "Digite o local que deseja movimentar (ex: linha:4 e coluna:8) " << std::endl;;
        std::cout << "linha: ";
        std::cin >> x;
        std::cout << "coluna: ";
        std::cin >> y;
        x = x + 1;
        y = y + 1;


        l = a - 1;       //aqui começa o tratamento de erro, por meio de l e c
        c = b;           //começa com l = a -1 para já subir uma linha

        arquivo.open("xadrez.txt", std::ios::app);
        arquivo << "\n";
        arquivo << "..." << std::endl;
        arquivo.close();

        if((xadrez[x][y]=='x') | (xadrez[x][y]=='t') | (xadrez[x][y]=='c') | (xadrez[x][y]=='b') | (xadrez[x][y]=='q') | (xadrez[x][y]=='p')) {  //só pode comer essas peças
            if((x==a) || (y==b)){  //para o movimento da torre ser correto, tem de ser na mesma linha ou coluna, isso trata
                if(y==b){                                  //verticalmente
                    while((xadrez[l][c]) == 'x'){                               //o while para quando os x acaba, para que possa comer só a primeira peça encontrada no caminho
                        l = l - 1;                        //subindo
                    }

                  char *px;
                  char *py;
                  px = &xadrez[l][c];
                  py = &xadrez[x][y];
                    if((px==py) || (xadrez[x][y] == 'x')){  //se o endereço da casa que digitou for o mesmo da primeira casa disponivel para comer, pode substituir OU apenas tiver um x dentro do endereço.
                        jogadnv = 1;                        //fiz isso para a torre só pode comer a primeira peça no alcance dela, não podendo comer uma atrás
                        xadrez[x][y]=xadrez[a][b];          //dela (e claro, a peça do mesmo time), precisei usar ponteiros para verificar se o endereço é o mesmo
                        xadrez[a][b]=' ';                   //toda vez que uma jogada for feita certa, jogadnv recebe 1 para não repetir, e a casa recebe a peça e a posiçao anterior é limpada
                        arquivo.open("xadrez.txt", std::ios::app);
                        arquivo << "Portanto, a TORRE maiuscula/branca foi para a posicao da linha " << x-1 << " e coluna " << y-1 << std::endl;
                        arquivo.close();
                        for(t=0; t<12; ++t) {
                            for(i=0; i<12; ++i){
                                if(xadrez[t][i]=='x'){   //limpa os x
                                    xadrez[t][i]=' ';
                                }
                            }
                        }
                    }else{              //se não
                            l = a + 1;
                            c = b;
                            while((xadrez[l][c]) == 'x'){
                                l = l + 1;                 //descendo
                            }
                            char *pz;
                            pz = &xadrez[l][c];
                            if((pz==py) || (xadrez[x][y] == 'x')){
                                jogadnv = 1;
                                xadrez[x][y]= xadrez[a][b];
                                xadrez[a][b]=' ';
                                for(t=0; t<12; ++t) {
                                    for(i=0; i<12; ++i){
                                        if(xadrez[t][i]=='x'){
                                            xadrez[t][i]=' ';
                                        }
                                    }
                                }
                                jogadnv = 1;
                        }else{
                            std::cout << "posicao invalida, tente novamente" << std::endl; //para não andar mais de duas na primeira rodada
                            for(t=0; t<12; ++t) {
                                for(i=0; i<12; ++i){
                                    if(xadrez[t][i]=='x'){
                                        xadrez[t][i]=' ';
                                    }
                                }
                            }
                        }
                    }
                }else{  //a logica é a mesma, mas para horizontal








                    while((xadrez[l][c]) == 'x'){
                        c = c - 1;                        //esquerda
                    }
                  char *px;
                  char *py;
                  px = &xadrez[l][c];
                  py = &xadrez[x][y];
                    if((px==py) || (xadrez[x][y] == 'x')){
                        jogadnv = 1;
                        xadrez[x][y]=xadrez[a][b];
                        xadrez[a][b]=' ';
                        jogadnv = 1;
                        arquivo.open("xadrez.txt", std::ios::app);
                        arquivo << "Portanto, a TORRE maiuscula/branca foi para a posicao da linha " << x-1 << " e coluna " << y-1 << std::endl;
                        arquivo.close();
                        for(t=0; t<12; ++t) {
                            for(i=0; i<12; ++i){
                                if(xadrez[t][i]=='x'){
                                    xadrez[t][i]=' ';
                                }
                            }
                        }
                    }else{
                            l = a;
                            c = b + 1;
                            while((xadrez[l][c]) == 'x'){
                                c = c + 1;                 //direita
                            }
                            char *pz;
                            pz = &xadrez[l][c];
                            if((pz==py) || (xadrez[x][y] == 'x')){
                                jogadnv = 1;
                                xadrez[x][y]= xadrez[a][b];
                                jogadnv = 1;
                                xadrez[a][b]=' ';
                                arquivo.open("xadrez.txt", std::ios::app);
                                arquivo << "Portanto, a TORRE maiuscula/branca foi para a posicao da linha " << x-1 << " e coluna " << y-1 << std::endl;
                                arquivo.close();
                                for(t=0; t<12; ++t) {
                                    for(i=0; i<12; ++i){
                                        if(xadrez[t][i]=='x'){
                                            xadrez[t][i]=' ';
                                        }
                                    }
                                }
                        }else{
                            std::cout << "posicao invalida, tente novamente" << std::endl; //para não andar mais de duas na primeira rodada
                            for(t=0; t<12; ++t) {
                                for(i=0; i<12; ++i){
                                    if(xadrez[t][i]=='x'){
                                        xadrez[t][i]=' ';
                                    }
                                }
                            }
                        }
                    }



                }
            }else{
                std::cout << "posicao invalida, tente novamente" << std::endl; //para não andar mais de duas na primeira rodada
                for(t=0; t<12; ++t) {
                    for(i=0; i<12; ++i){
                        if(xadrez[t][i]=='x'){
                            xadrez[t][i]=' ';
                        }
                    }
                }
             }
        }else{
                std::cout << "posicao invalida, tente novamente" << std::endl; //para não andar mais de duas na primeira rodada
                for(t=0; t<12; ++t) {
                    for(i=0; i<12; ++i){
                        if(xadrez[t][i]=='x'){
                            xadrez[t][i]=' ';
                        }
                    }
                }
        }

}


    /*CAVALO*/
    if (xadrez[a][b]=='C'){       //pro cavalo
    printarcavalo1(a, b);



        std::cout << "Digite o local que deseja movimentar (ex: linha:4 e coluna:8) " << std::endl;
            std::cout << "linha: ";
            std::cin >> x;
            std::cout << "coluna: ";
            std::cin >> y;
            x = x + 1;
            y = y + 1;

        if((xadrez[x][y]=='x') | (xadrez[x][y]=='t') | (xadrez[x][y]=='c') | (xadrez[x][y]=='b') | (xadrez[x][y]=='q') | (xadrez[x][y]=='p')) {
            if(pow(a-x,2)+pow(b-y,2) == 5){    //a estratégia de tratar aqui é fazer pitágoras, o cavalo anda na hipotenusa, sendo os catetos a diferença da linha/coluna atual e linha/coluna que ele quer ir
                xadrez[x][y]= xadrez[a][b];     //portanto, se o teorema de pitagoras der verdadeiro, ele teoricamente poderia pisar naquela casa
                jogadnv = 1;                    //exceto quando não é peça inimiga
                arquivo.open("xadrez.txt", std::ios::app);
                arquivo << "Portanto, o CAVALO maiusculo/branco foi para a posicao da linha " << x-1 << " e coluna " << y-1 << std::endl;
                arquivo.close();
                xadrez[a][b]=' ';
                for(t=0; t<12; ++t) {
                    for(i=0; i<12; ++i){
                        if(xadrez[t][i]=='x'){
                            xadrez[t][i]=' ';
                        }
                    }
                }

            }else{
                std::cout << "posicao invalida, tente novamente" << std::endl; //para não andar mais de duas na primeira rodada
                for(t=0; t<12; ++t) {
                    for(i=0; i<12; ++i){
                        if(xadrez[t][i]=='x'){
                            xadrez[t][i]=' ';
                        }
                    }
                }


            }
        }

    }






    /*BISPO*/

    if (xadrez[a][b]=='B'){
        printarbispo1(a, b);


            std::cout << "Digite o local que deseja movimentar (ex: linha:4 e coluna:8) " << std::endl;;
            std::cout << "linha: ";
            std::cin >> x;
            std::cout << "coluna: ";
            std::cin >> y;
            x = x + 1;
            y = y + 1;

         if((xadrez[x][y]=='x') | (xadrez[x][y]=='t') | (xadrez[x][y]=='c') | (xadrez[x][y]=='b') | (xadrez[x][y]=='q') | (xadrez[x][y]=='p')) {
            if(abs(x-a) == abs(y-b)){    //para tratar o bispo, a estrategia foi verificar se ele colocou uma diagonal da peça escolhida, isso é, o módulo da diferenca de linhas e colunas tem de ser o mesmo
                if(((x-a) == 1) || ((x-a) == -1)){  //para que uma cas de distância coma a peça inimiga
                    xadrez[x][y]= xadrez[a][b];
                    jogadnv = 1;
                    arquivo.open("xadrez.txt", std::ios::app);
                    arquivo << "Portanto, O BISPO maiusculo/branco foi para a posicao da linha " << x-1 << " e coluna " << y-1 << std::endl;
                    arquivo.close();
                    xadrez[a][b]=' ';
                    for(t=0; t<12; ++t) {
                        for(i=0; i<12; ++i){
                            if(xadrez[t][i]=='x'){
                                xadrez[t][i]=' ';
                            }
                        }
                    }
                    jogadnv = 1;

                    }else{    //se não, precisamos ver se a peça da diagonal é a primeira peça disponivel (por ex: se ele está comendo uma peça na diagonal que está atrás de outra).
                        if((x-a) >= 0){   //para percorremos na diagonal escolhida
                            movimentolinha = 1;
                        }else{
                            movimentolinha = -1;
                        }
                        if((y-b) >= 0){
                            movimentocoluna = 1;
                        }else{
                            movimentocoluna = -1;
                        }
                        c = b + movimentocoluna;
                        l = a + movimentolinha;
                        while(l != x && c != y){    //enquando não for a mesma, quando for, ele para e verifica se a posição anterior é diferente de x ou B, se for, é pq tinha uma peça no caminho
                            if((xadrez[l][c]!='x') || (xadrez[l][c]=!'B')){
                                std::cout << "posicao invalida, tente novamente" << std::endl;
                                for(t=0; t<12; ++t) {
                                    for(i=0; i<12; ++i){
                                        if(xadrez[t][i]=='x'){
                                            xadrez[t][i]=' ';
                                        }
                                    }
                                }
                                break;
                            }
                        l += movimentolinha;
                        c += movimentocoluna;
                        }
                        if((l == x) && (c == y))    //se não, é igual e está correto
                        {
                            xadrez[x][y]= xadrez[a][b];
                            xadrez[a][b]=' ';
                            jogadnv = 1;
                            for(t=0; t<12; ++t) {
                                for(i=0; i<12; ++i){
                                    if(xadrez[t][i]=='x'){
                                    xadrez[t][i]=' ';
                                    }
                                }
                            }
                            jogadnv = 1;
                            arquivo.open("xadrez.txt", std::ios::app);
                            arquivo << "Portanto, O BISPO maiusculo/branco foi para a posicao da linha " << x-1 << " e coluna " << y-1 << std::endl;
                            arquivo.close();

                        }


                    }


               }
            else{

                std::cout << "posicao invalida, tente novamente" << std::endl; //para não andar mais de duas na primeira rodada
                for(t=0; t<12; ++t) {
                    for(i=0; i<12; ++i){
                        if(xadrez[t][i]=='x'){
                            xadrez[t][i]=' ';
                        }
                    }
                }
            }
         }else{
             std::cout << "posicao invalida, tente novamente" << std::endl; //para não andar mais de duas na primeira rodada
            for(t=0; t<12; ++t) {
                for(i=0; i<12; ++i){
                    if(xadrez[t][i]=='x'){
                        xadrez[t][i]=' ';
                    }
                }
            }
         }

    }








































    /*RAINHA*/
    if (xadrez[a][b]=='Q'){  //apenas a junção do tratamento do bispo + torre
        printarrainha1(a,b);


        std::cout << "Digite o local que deseja movimentar (ex: linha:4 e coluna:8) " << std::endl;;
            std::cout << "linha: ";
            std::cin >> x;
            std::cout << "coluna: ";
            std::cin >> y;
            x = x + 1;
            y = y + 1;

         if((xadrez[x][y]=='x') | (xadrez[x][y]=='t') | (xadrez[x][y]=='c') | (xadrez[x][y]=='b') | (xadrez[x][y]=='q') | (xadrez[x][y]=='p')) {
                if((abs(x-a) == abs(y-b)) || (x==a) || (y==b)){
                    if((x==a) || (y==b)){
                        l = a - 1;
                        c = b;
                        if(y==b){
                            while((xadrez[l][c]) == 'x'){
                                l = l - 1;
                            }
                          char *px;
                          char *py;
                          px = &xadrez[l][c];
                          py = &xadrez[x][y];
                            if((px==py) || (xadrez[x][y] == 'x')){
                                jogadnv = 1;
                                xadrez[x][y]=xadrez[a][b];
                                xadrez[a][b]=' ';
                                jogadnv = 1;
                                arquivo.open("xadrez.txt", std::ios::app);
                                arquivo << "Portanto, A RAINHA maiuscula/branca foi para a posicao da linha " << x-1 << " e coluna " << y-1 << std::endl;
                                arquivo.close();
                                for(t=0; t<12; ++t) {
                                    for(i=0; i<12; ++i){
                                        if(xadrez[t][i]=='x'){
                                            xadrez[t][i]=' ';
                                        }
                                    }
                                }
                            }else{
                                    l = a + 1;
                                    c = b;
                                    while((xadrez[l][c]) == 'x'){
                                        l = l + 1;
                                    }
                                    char *pz;
                                    pz = &xadrez[l][c];
                                    if((pz==py) || (xadrez[x][y] == 'x')){
                                        jogadnv = 1;
                                        xadrez[x][y]= xadrez[a][b];
                                        arquivo.open("xadrez.txt", std::ios::app);
                                        arquivo << "Portanto, A RAINHA maiuscula/branca foi para a posicao da linha " << x-1 << " e coluna " << y-1 << std::endl;
                                        arquivo.close();
                                        xadrez[a][b]=' ';
                                        for(t=0; t<12; ++t) {
                                            for(i=0; i<12; ++i){
                                                if(xadrez[t][i]=='x'){
                                                    xadrez[t][i]=' ';
                                                }
                                            }
                                        }
                                }else{
                                    std::cout << "posicao invalida, tente novamente" << std::endl; //para não andar mais de duas na primeira rodada
                                    for(t=0; t<12; ++t) {
                                        for(i=0; i<12; ++i){
                                            if(xadrez[t][i]=='x'){
                                                xadrez[t][i]=' ';
                                            }
                                        }
                                    }
                                }
                            }
                        }else{
                            while((xadrez[l][c]) == 'x'){
                                c = c - 1;
                            }
                          char *px;
                          char *py;
                          px = &xadrez[l][c];
                          py = &xadrez[x][y];
                            if((px==py) || (xadrez[x][y] == 'x')){
                                jogadnv = 1;
                                arquivo.open("xadrez.txt", std::ios::app);
                                arquivo << "Portanto, A RAINHA maiuscula/branca foi para a posicao da linha " << x-1 << " e coluna " << y-1 << std::endl;
                                arquivo.close();
                                xadrez[x][y]=xadrez[a][b];
                                xadrez[a][b]=' ';
                                for(t=0; t<12; ++t) {
                                    for(i=0; i<12; ++i){
                                        if(xadrez[t][i]=='x'){
                                            xadrez[t][i]=' ';
                                        }
                                    }
                                }
                            }else{
                                    l = a;
                                    c = b + 1;
                                    while((xadrez[l][c]) == 'x'){
                                        c = c + 1;
                                    }
                                    char *pz;
                                    pz = &xadrez[l][c];
                                    if((pz==py) || (xadrez[x][y] == 'x')){
                                        arquivo.open("xadrez.txt", std::ios::app);
                                        arquivo << "Portanto, A RAINHA maiuscula/branca foi para a posicao da linha " << x-1 << " e coluna " << y-1 << std::endl;
                                        arquivo.close();
                                        xadrez[x][y]= xadrez[a][b];
                                        jogadnv = 1;
                                        xadrez[a][b]=' ';
                                        for(t=0; t<12; ++t) {
                                            for(i=0; i<12; ++i){
                                                if(xadrez[t][i]=='x'){
                                                    xadrez[t][i]=' ';
                                                }
                                            }
                                        }
                                }else{
                                    std::cout << "posicao invalida, tente novamente" << std::endl; //para não andar mais de duas na primeira rodada
                                    for(t=0; t<12; ++t) {
                                        for(i=0; i<12; ++i){
                                            if(xadrez[t][i]=='x'){
                                                xadrez[t][i]=' ';
                                            }
                                        }
                                    }
                                }
                            }


                        }
                    }

                    if(abs(x-a) == abs(y-b)){
                        if(((x-a) == 1) || ((x-a) == -1)){
                            xadrez[x][y]= xadrez[a][b];
                            arquivo.open("xadrez.txt", std::ios::app);
                            arquivo << "Portanto, A RAINHA maiuscula/branca foi para a posicao da linha " << x-1 << " e coluna " << y-1 << std::endl;
                            arquivo.close();
                            xadrez[a][b]=' ';
                            for(t=0; t<12; ++t) {
                                for(i=0; i<12; ++i){
                                    if(xadrez[t][i]=='x'){
                                        xadrez[t][i]=' ';
                                    }
                                }
                            }

                            }else{
                                if((x-a) >= 0){
                                    movimentolinha = 1;
                                }else{
                                    movimentolinha = -1;
                                }
                                if((y-b) >= 0){
                                    movimentocoluna = 1;
                                }else{
                                    movimentocoluna = -1;
                                }
                                c = b + movimentocoluna;
                                l = a + movimentolinha;
                                while(l != x && c != y){
                                    if((xadrez[l][c]!='x') || (xadrez[l][c]=!'B')){
                                        std::cout << "posicao invalida, tente novamente" << std::endl; //para não andar mais de duas na primeira rodada
                                        for(t=0; t<12; ++t) {
                                            for(i=0; i<12; ++i){
                                                if(xadrez[t][i]=='x'){
                                                    xadrez[t][i]=' ';
                                                }
                                            }
                                        }
                                        break;
                                    }
                                l += movimentolinha;
                                c += movimentocoluna;
                                }
                                if(l == x && c == y)
                                {
                                    xadrez[x][y]= xadrez[a][b];
                                    arquivo.open("xadrez.txt", std::ios::app);
                                    arquivo << "Portanto, A RAINHA maiuscula/branca foi para a posicao da linha " << x-1 << " e coluna " << y-1 << std::endl;
                                    arquivo.close();
                                    jogadnv = 1;
                                    xadrez[a][b]=' ';
                                    for(t=0; t<12; ++t) {
                                        for(i=0; i<12; ++i){
                                            if(xadrez[t][i]=='x'){
                                            xadrez[t][i]=' ';
                                            }
                                        }
                                    }

                                }


                            }


                       }


                }else{
                    std::cout << "posicao invalida, tente novamente" << std::endl; //para não andar mais de duas na primeira rodada
                    for(t=0; t<12; ++t) {
                        for(i=0; i<12; ++i){
                            if(xadrez[t][i]=='x'){
                                xadrez[t][i]=' ';
                            }
                        }
                    }

                }
            }else{
                std::cout << "posicao invalida, tente novamente" << std::endl; //para não andar mais de duas na primeira rodada
                for(t=0; t<12; ++t) {
                    for(i=0; i<12; ++i){
                        if(xadrez[t][i]=='x'){
                            xadrez[t][i]=' ';
                        }
                    }
                }


            }






    }



    /*REI*/
    if (xadrez[a][b]=='K'){
      printarrei1(a, b);

        std::cout << "Digite o local que deseja movimentar (ex: linha:4 e coluna:8) " << std::endl;;
            std::cout << "linha: ";
            std::cin >> x;
            std::cout << "coluna: ";
            std::cin >> y;
            x = x + 1;
            y = y + 1;


         if((xadrez[x][y]=='x') | (xadrez[x][y]=='t') | (xadrez[x][y]=='c') | (xadrez[x][y]=='b') | (xadrez[x][y]=='q') | (xadrez[x][y]=='p')) {
            if((x==a-1) || (x==a+1) || (y==b-1) || (y==b+1)){ //o rei é um dos mais tranquilo, pode se movimentar para lá se a distância for apenas uma unidade
                xadrez[x][y]= xadrez[a][b];
                jogadnv = 1;
                arquivo.open("xadrez.txt", std::ios::app);
                arquivo << "Portanto, A RAINHA maiuscula/branca foi para a posicao da linha " << x-1 << " e coluna " << y-1 << std::endl;
                arquivo.close();
                xadrez[a][b]=' ';
                for(t=0; t<12; ++t) {
                    for(i=0; i<12; ++i){
                        if(xadrez[t][i]=='x'){
                            xadrez[t][i]=' ';
                        }
                }
                    }
            }else{
                std::cout << "posicao invalida, tente novamente" << std::endl; //para não andar mais de duas na primeira rodada
                for(t=0; t<12; ++t) {
                    for(i=0; i<12; ++i){
                        if(xadrez[t][i]=='x'){
                            xadrez[t][i]=' ';
                        }
                    }
                }
            }

        }else{
            std::cout << "posicao invalida, tente novamente" << std::endl; //para não andar mais de duas na primeira rodada
                for(t=0; t<12; ++t) {
                    for(i=0; i<12; ++i){
                        if(xadrez[t][i]=='x'){
                            xadrez[t][i]=' ';
                        }
                    }
                }
        }




    }


    /*PEAO*/
    if (xadrez[a][b]=='P'){
       printarpeao1(a,b);

        std::cout << "Digite o local que deseja movimentar (ex: linha:4 e coluna:8) " << std::endl;;
            std::cout << "linha: ";
            std::cin >> x;
            std::cout << "coluna: ";
            std::cin >> y;
            x = x + 1;
            y = y + 1;


         if(xadrez[x][y]=='x'){
                if(a==8){            //o peao temos que verificar se é a primeira rodada ou não, na primeira rodada ele sempre estará na linha 7
                    if(((x==a-2) || (x==a-1)) && (y==b)){  //primeira rodada (do peão escolhido) pode andar duas ou uma verticalmente
                        xadrez[x][y]= xadrez[a][b];
                        xadrez[a][b]=' ';
                        jogadnv = 1;
                        arquivo.open("xadrez.txt", std::ios::app);
                        arquivo << "Portanto, o PEAO maiusculo/branco foi para a posicao da linha " << x-1 << " e coluna " << y-1 << std::endl;
                        arquivo.close();
                        for(t=0; t<12; ++t) {
                        for(i=0; i<12; ++i){
                            if(xadrez[t][i]=='x'){
                                xadrez[t][i]=' ';    //limpando os x
                            }
                        }
                        }
                    }
                }else{
                if((x==a-1) && (y==b-1 || y==b || y==b+1)){  //após a primeira rodada, só anda uma verticalmente (menos quando tem inimigo na diagonal)
                    xadrez[x][y]=xadrez[a][b];
                    xadrez[a][b]=' ';
                    jogadnv = 1;
                    arquivo.open("xadrez.txt", std::ios::app);
                    arquivo << "Portanto, O PEAO maiusculo/branco foi para a posicao da linha " << x-1 << " e coluna " << y-1 << std::endl;
                    arquivo.close();
                    for(t=0; t<12; ++t) {
                        for(i=0; i<12; ++i){
                            if(xadrez[t][i]=='x'){
                                xadrez[t][i]=' ';
                            }
                        }
                    }
                }else{
                std::cout << "posicao invalida, tente novamente" << std::endl;  //para não andar mais de uma após a primeira rodada
                }
                }
        }else{ if((xadrez[x][y]=='t') || (xadrez[x][y]=='c') || (xadrez[x][y]=='b') || (xadrez[x][y]=='q') || (xadrez[x][y]=='p')){ //coloquei esse grande elif para garantir que a peça peão só coma na diagonal e que seja a uma casa de distância 1
                if((x==a-1) && (y==b-1 || y==b+1)){  //após a primeira rodada, só anda uma verticalmente
                    xadrez[x][y]=xadrez[a][b];
                    xadrez[a][b]=' ';
                    jogadnv = 1;
                    arquivo.open("xadrez.txt", std::ios::app);
                    arquivo << "Portanto, O PEAO maiusculo/branco foi para a posicao da linha " << x-1 << " e coluna " << y-1 << std::endl;
                    arquivo.close();
                    for(t=0; t<12; ++t) {
                        for(i=0; i<12; ++i){
                            if(xadrez[t][i]=='x'){
                                xadrez[t][i]=' ';
                            }
                        }
                    }
                }else{
                std::cout << "posicao invalida, tente novamente" << std::endl;  //para não andar mais de uma após a primeira rodada
                }
            }else{
                std::cout << "posicao invalida, tente novamente" << std::endl; //para não andar mais de duas na primeira rodada
                for(t=0; t<12; ++t) {
                        for(i=0; i<12; ++i){
                            if(xadrez[t][i]=='x'){
                                xadrez[t][i]=' ';
                            }
                        }
                    }
                 }
            }



    }



    arquivo.open("xadrez.txt", std::ios::app);
    for(t=0; t<12; ++t) {
        for(i=0; i<12; ++i){
                arquivo << "  "  << xadrez[t][i];      //salvando no arquivo o tabuleiro pós jogda
        }
    arquivo << "\n";
    }
    std::cout << "\n";
    arquivo.close();



        int promocao;
        for(i=0; i<12; ++i){
            if(xadrez[2][i]=='P'){           //o famoso Promotion, quando o peao chega na linha 1, o jogador é perguntado para qual peça quer promove-lo
                std::cout << "\n " << std::endl;
                std::cout << "PEAO DAS PECAS MAIUSCULAS PROMOVIDO! " << std::endl;
                std::cout << "Escolha uma das pecas abaixo para promover seu peao da linha 1 coluna " << i-1 << std::endl;
                std::cout << "1 - Torre " << std::endl;
                std::cout << "2 - Cavalo " << std::endl;
                std::cout << "3 - Bispo " << std::endl;
                std::cout << "4 - Rainha " << std::endl;
                arquivo.open("xadrez.txt", std::ios::app);
                while(1){          //salvando em arquivos abaixo
                    std::cout << "Digite o numero correspondente: " << std::endl;
                    std::cin >> promocao;
                    if(promocao==1){
                        xadrez[2][i] = 'T';
                        arquivo << "E PROMOVEU esse peao para uma TORRE "  << std::endl;
                        arquivo.close();
                        break;
                    }else if(promocao==2){
                            xadrez[2][i] = 'C';
                            arquivo << "E PROMOVEU esse peao para um CAVALO "  << std::endl;
                            arquivo.close();
                            break;
                        }else if(promocao==3){
                                xadrez[2][i] = 'B';
                                arquivo << "E PROMOVEU esse peao para um BISPO "  << std::endl;
                                arquivo.close();
                                break;
                                }else if(promocao==4){
                                    arquivo << "E PROMOVEU esse peao para uma RAINHA "  << std::endl;
                                    arquivo.close();
                                    xadrez[2][i] = 'Q';
                                    break;
                                }else{
                                    std::cout << "Valor invalido, Digite novamente" << std::endl;
                                    continue;
                                }
                }

            }
        }


            arquivo.open("xadrez.txt", std::ios::app);
            arquivo << "\n";
            arquivo << "..." << std::endl;
            arquivo.close();



}

    std::cout << "Digite qualquer tecla para continuar. (Q - para sair): ";
    std::cin >> querocontinuar;
    if(querocontinuar.compare("Q")==0)
    {
        std::cout << "Finalizando o programa, quer salvar o jogo? [S/N] ";
        std::cin >> querosalvar;
        if(querosalvar.compare("S")==0)
        {
            std::cout << "Qual nome voce quer salvar o arquivo? (sem colocar .txt) ";
            std::cin >> nomedojogo;                                   //a estratégia de salvar arquivos foi a seguinte: será criado um arquivo chamado "xadrez.txt" temporario onde será escrito tudo
            std::strcat(nomedojogo, ".txt");                          //caso o usuario não quer salvar, esse arquivo é excluido, caso ele queira salvar, o programa pedirá um nome e ele vai RENOMEAR esse arquivo
            std::rename("xadrez.txt", nomedojogo);                 //e adicionar ".txt" a esse nome (para que o usuario nao fique em duvida de qual tipo colocar)
            exit(0);
        }else
        {
            remove("xadrez.txt");
            exit(0);
        }
    }

}





























































//para fazer o jogador 2, é a mesma coisa, mas baseei na reflexao, portanto, a principal diferença dessa função para a de cima, é que as operações soma e subtração estão invertidas
//e também será referido na tela como jogador das peças minusculas etc

void jogador2(void)
{
HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
int jogadnv = 0;
int movimentolinha;
int movimentocoluna;
char nomedojogo[20];
std::string querocontinuar;
std::string querosalvar;


while(jogadnv == 0){


    jogadnv = 0;
       int pesa;
       int x,y,a,b;
       unsigned  int l,c;
       int t,i;

    printartabuleiro();

    jogadorbranco();

    std::cout << "Escolha a peca que quer movimentar: (linha:3 e coluna:7)" << std::endl;
    std::cout << "Linha: ";
    std::cin >> a;


    std::cout << "Coluna: ";
    std::cin >> b;
    a = a + 1;
    b = b + 1;



    std::ofstream arquivo;
    arquivo.open("xadrez.txt", std::ios::app);
    arquivo << "Jogador das pecas minusculas/pretas movimentou a peca da linha " << a-1 << " e coluna " << b-1 << std::endl;
    arquivo.close();

    arquivo.open("xadrez.txt", std::ios::app);
    int corTabuleiro = 0;
    for(t=0; t<12; ++t) {
        for(i=0; i<12; ++i){
                arquivo << "  "  << xadrez[t][i];
        }
    arquivo << "\n";
    }
    std::cout << "\n";
    arquivo.close();



     if((a<1) || (a>9) || (b<1) || (b>9))
    {
        std::cout << "Digite coordenadas do tabuleiro, apenas de 1 a 8." << std::endl;
        continue;
    }


        arquivo.open("xadrez.txt", std::ios::app);
        arquivo << "\n";
        arquivo << "..." << std::endl;
        arquivo.close();


    //TORRE
    if (xadrez[a][b]=='t'){
        printartorre2(a,b);

        std::cout << "Digite o local que deseja movimentar (ex: linha:4 e coluna:8) " << std::endl;;
        std::cout << "linha: ";
        std::cin >> x;
        std::cout << "coluna: ";
        std::cin >> y;
        x = x + 1;
        y = y + 1;

        l = a + 1;
        c = b;
        if((xadrez[x][y]=='x') | (xadrez[x][y]=='T') | (xadrez[x][y]=='C') | (xadrez[x][y]=='B') | (xadrez[x][y]=='Q') | (xadrez[x][y]=='P')) {
            if((x==a) || (y==b)){
                if(y==b){                                  //verticalmente
                    while((xadrez[l][c]) == 'x'){
                        l = l + 1;                        //subindo
                    }
                  char *px;
                  char *py;
                  px = &xadrez[l][c];
                  py = &xadrez[x][y];
                    if((px==py) || (xadrez[x][y] == 'x')){
                        jogadnv = 1;
                        xadrez[x][y]=xadrez[a][b];
                        arquivo.open("xadrez.txt", std::ios::app);
                        arquivo << "Portanto, a TORRE minuscula/preta foi para a posicao da linha " << x-1 << " e coluna " << y-1 << std::endl;
                        arquivo.close();
                        xadrez[a][b]=' ';
                        for(t=0; t<12; ++t) {
                            for(i=0; i<12; ++i){
                                if(xadrez[t][i]=='x'){
                                    xadrez[t][i]=' ';
                                }
                            }
                        }
                    }else{
                            l = a - 1;
                            c = b;
                            while((xadrez[l][c]) == 'x'){
                                l = l - 1;                 //descendo
                            }
                            char *pz;
                            pz = &xadrez[l][c];
                            if((pz==py) || (xadrez[x][y] == 'x')){
                                jogadnv = 1;
                                xadrez[x][y]= xadrez[a][b];
                                arquivo.open("xadrez.txt", std::ios::app);
                                arquivo << "Portanto, a TORRE minuscula/preta foi para a posicao da linha " << x-1 << " e coluna " << y-1 << std::endl;
                                arquivo.close();
                                xadrez[a][b]=' ';
                                for(t=0; t<12; ++t) {
                                    for(i=0; i<12; ++i){
                                        if(xadrez[t][i]=='x'){
                                            xadrez[t][i]=' ';
                                        }
                                    }
                                }
                        }else{
                            std::cout << "posicao invalida, tente novamente" << std::endl; //para não andar mais de duas na primeira rodada
                            for(t=0; t<12; ++t) {
                                for(i=0; i<12; ++i){
                                    if(xadrez[t][i]=='x'){
                                        xadrez[t][i]=' ';
                                    }
                                }
                            }
                        }
                    }
                }else{
                    while((xadrez[l][c]) == 'x'){
                        c = c + 1;                        //esquerda
                    }
                  char *px;
                  char *py;
                  px = &xadrez[l][c];
                  py = &xadrez[x][y];
                    if((px==py) || (xadrez[x][y] == 'x')){
                        jogadnv = 1;
                        arquivo.open("xadrez.txt", std::ios::app);
                        arquivo << "Portanto, a TORRE minuscula/preta foi para a posicao da linha " << x-1 << " e coluna " << y-1 << std::endl;
                        arquivo.close();
                        xadrez[x][y]=xadrez[a][b];
                        xadrez[a][b]=' ';
                        for(t=0; t<12; ++t) {
                            for(i=0; i<12; ++i){
                                if(xadrez[t][i]=='x'){
                                    xadrez[t][i]=' ';
                                }
                            }
                        }
                    }else{
                            l = a;
                            c = b - 1;
                            while((xadrez[l][c]) == 'x'){
                                c = c - 1;                 //direita
                            }
                            char *pz;
                            pz = &xadrez[l][c];
                            if((pz==py) || (xadrez[x][y] == 'x')){
                                jogadnv = 1;
                                arquivo.open("xadrez.txt", std::ios::app);
                                arquivo << "Portanto, a TORRE minuscula/preta foi para a posicao da linha " << x-1 << " e coluna " << y-1 << std::endl;
                                arquivo.close();
                                xadrez[x][y]= xadrez[a][b];
                                xadrez[a][b]=' ';
                                for(t=0; t<12; ++t) {
                                    for(i=0; i<12; ++i){
                                        if(xadrez[t][i]=='x'){
                                            xadrez[t][i]=' ';
                                        }
                                    }
                                }
                        }else{
                            std::cout << "posicao invalida, tente novamente" << std::endl; //para não andar mais de duas na primeira rodada
                            for(t=0; t<12; ++t) {
                                for(i=0; i<12; ++i){
                                    if(xadrez[t][i]=='x'){
                                        xadrez[t][i]=' ';
                                    }
                                }
                            }
                        }
                    }












                }
            }else{
                std::cout << "posicao invalida, tente novamente" << std::endl; //para não andar mais de duas na primeira rodada
                for(t=0; t<12; ++t) {
                    for(i=0; i<12; ++i){
                        if(xadrez[t][i]=='x'){
                            xadrez[t][i]=' ';
                        }
                    }
                }
             }
        }else{
                std::cout << "posicao invalida, tente novamente" << std::endl; //para não andar mais de duas na primeira rodada
                for(t=0; t<12; ++t) {
                    for(i=0; i<12; ++i){
                        if(xadrez[t][i]=='x'){
                            xadrez[t][i]=' ';
                        }
                    }
                }
        }
}


/*CAVALO*/
if(xadrez[a][b]=='c'){
    printarcavalo2(a,b);

        std::cout << "Digite o local que deseja movimentar (ex: linha:4 e coluna:8) " << std::endl;;
            std::cout << "linha: ";
            std::cin >> x;
            std::cout << "coluna: ";
            std::cin >> y;
            x = x + 1;
            y = y + 1;

        if((xadrez[x][y]=='x') || (xadrez[x][y]=='T') || (xadrez[x][y]=='C') || (xadrez[x][y]=='B') || (xadrez[x][y]=='Q') || (xadrez[x][y]=='P')) {
            if(pow(a-x,2)+pow(b-y,2) == 5){
                xadrez[x][y]= xadrez[a][b];
                jogadnv = 1;
                arquivo.open("xadrez.txt", std::ios::app);
                arquivo << "Portanto, o CAVALO minusculo/preto foi para a posicao da linha " << x-1 << " e coluna " << y-1 << std::endl;
                arquivo.close();
                xadrez[a][b]=' ';
                for(t=0; t<12; ++t) {
                    for(i=0; i<12; ++i){
                        if(xadrez[t][i]=='x'){
                            xadrez[t][i]=' ';
                        }
                    }
                }

            }else{
                std::cout << "posicao invalida, tente novamente" << std::endl; //para não andar mais de duas na primeira rodada
                for(t=0; t<12; ++t) {
                    for(i=0; i<12; ++i){
                        if(xadrez[t][i]=='x'){
                            xadrez[t][i]=' ';
                        }
                    }
                }


            }
        }else{
            std::cout << "posicao invalida, tente novamente" << std::endl; //para não andar mais de duas na primeira rodada
                for(t=0; t<12; ++t) {
                    for(i=0; i<12; ++i){
                        if(xadrez[t][i]=='x'){
                            xadrez[t][i]=' ';
                        }
                    }
                }
        }

    }



 /*BISPO*/

    if (xadrez[a][b]=='b'){
        printarbispo2(a,b);


            std::cout << "Digite o local que deseja movimentar (ex: linha:4 e coluna:8) " << std::endl;;
            std::cout << "linha: ";
            std::cin >> x;
            std::cout << "coluna: ";
            std::cin >> y;
            x = x + 1;
            y = y + 1;

         if((xadrez[x][y]=='x') | (xadrez[x][y]=='T') | (xadrez[x][y]=='C') | (xadrez[x][y]=='B') | (xadrez[x][y]=='Q') | (xadrez[x][y]=='P')) {
            if(abs(x-a) == abs(y-b)){    //PARA TER CERTEZA QUE ESTÁ NA DIAGONAL
                if(((x-a) == 1) || ((x-a) == -1)){  //UMA CASA DE DISTâNCIA PODE COMER PEÇA INIMIGA
                    xadrez[x][y]= xadrez[a][b];
                    jogadnv = 1;
                    arquivo.open("xadrez.txt", std::ios::app);
                    arquivo << "Portanto, o BISPO minusculo/preto foi para a posicao da linha " << x-1 << " e coluna " << y-1 << std::endl;
                    arquivo.close();
                    xadrez[a][b]=' ';
                    for(t=0; t<10; ++t) {
                        for(i=0; i<10; ++i){
                            if(xadrez[t][i]=='x'){
                                xadrez[t][i]=' ';
                            }
                        }
                    }


                    }else{
                        if((x-a) >= 0){
                            movimentolinha = 1;
                        }else{
                            movimentolinha = -1;
                        }
                        if((y-b) >= 0){
                            movimentocoluna = 1;
                        }else{
                            movimentocoluna = -1;
                        }
                        c = b + movimentocoluna;
                        l = a + movimentolinha;
                        while(l != x && c != y){
                            if((xadrez[l][c]!='x') || (xadrez[l][c]=!'b')){
                                std::cout << "posicao invalida, tente novamente" << std::endl; //para não andar mais de duas na primeira rodada
                                for(t=0; t<10; ++t) {
                                    for(i=0; i<10; ++i){
                                        if(xadrez[t][i]=='x'){
                                            xadrez[t][i]=' ';
                                        }
                                    }
                                }
                                break;
                            }
                        l += movimentolinha;
                        c += movimentocoluna;
                        }
                        if((l == x) && (c == y))
                        {
                            xadrez[x][y]= xadrez[a][b];
                            jogadnv = 1;
                            arquivo.open("xadrez.txt", std::ios::app);
                            arquivo << "Portanto, o BISPO minusculo/preto foi para a posicao da linha " << x-1 << " e coluna " << y-1 << std::endl;
                            arquivo.close();
                            xadrez[a][b]=' ';
                            for(t=0; t<10; ++t) {
                                for(i=0; i<10; ++i){
                                    if(xadrez[t][i]=='x'){
                                    xadrez[t][i]=' ';
                                    }
                                }
                            }

                        }


                    }


               }
            else{

                std::cout << "posicao invalida, tente novamente" << std::endl; //para não andar mais de duas na primeira rodada
                for(t=0; t<10; ++t) {
                    for(i=0; i<10; ++i){
                        if(xadrez[t][i]=='x'){
                            xadrez[t][i]=' ';
                        }
                    }
                }
            }
         }else{
             std::cout << "posicao invalida, tente novamente" << std::endl; //para não andar mais de duas na primeira rodada
            for(t=0; t<10; ++t) {
                for(i=0; i<10; ++i){
                    if(xadrez[t][i]=='x'){
                        xadrez[t][i]=' ';
                    }
                }
            }
         }

    }





    /*RAINHA*/
    if (xadrez[a][b]=='q'){
        printarrainha2(a,b);

        std::cout << "Digite o local que deseja movimentar (ex: linha:4 e coluna:8) " << std::endl;;
            std::cout << "linha: ";
            std::cin >> x;
            std::cout << "coluna: ";
            std::cin >> y;
            x = x + 1;
            y = y + 1;




         if((xadrez[x][y]=='x') | (xadrez[x][y]=='T') | (xadrez[x][y]=='C') | (xadrez[x][y]=='B') | (xadrez[x][y]=='Q') | (xadrez[x][y]=='P')) {
                if((abs(x-a) == abs(y-b)) || (x==a) || (y==b)){
                    if((x==a) || (y==b)){
                        l = a + 1;
                        c = b;
                        if(y==b){                                  //verticalmente
                            while((xadrez[l][c]) == 'x'){                               //para o while para comer só a primeira peça encontrada no caminho
                                l = l - 1;                        //subindo
                            }
                          char *px;
                          char *py;
                          px = &xadrez[l][c];
                          py = &xadrez[x][y];
                            if((px==py) || (xadrez[x][y] == 'x')){  //se o endereço for o mesmo ou tiver um x dentro do endereço, fiz isso pois
                                jogadnv = 1;                        //a torre só pode comer a primeira peça no alcance dela, não podendo comer uma atrás
                                xadrez[x][y]=xadrez[a][b];          //dessa (e claro, a peça do mesmo time), precisei usar ponteiros para verificar se o endereço é o mesmo
                                xadrez[a][b]=' ';
                                arquivo.open("xadrez.txt", std::ios::app);
                                arquivo << "Portanto, a RAINHA minuscula/preta foi para a posicao da linha " << x-1 << " e coluna " << y-1 << std::endl;
                                arquivo.close();
                                for(t=0; t<12; ++t) {
                                    for(i=0; i<12; ++i){
                                        if(xadrez[t][i]=='x'){
                                            xadrez[t][i]=' ';
                                        }
                                    }
                                }
                            }else{              //se não
                                    l = a - 1;
                                    c = b;
                                    while((xadrez[l][c]) == 'x'){
                                        l = l - 1;                 //descendo
                                    }
                                    char *pz;
                                    pz = &xadrez[l][c];
                                    if((pz==py) || (xadrez[x][y] == 'x')){
                                        jogadnv = 1;
                                        arquivo.open("xadrez.txt", std::ios::app);
                                        arquivo << "Portanto, a RAINHA minuscula/preta foi para a posicao da linha " << x-1 << " e coluna " << y-1 << std::endl;
                                        arquivo.close();
                                        xadrez[x][y]= xadrez[a][b];
                                        xadrez[a][b]=' ';
                                        for(t=0; t<12; ++t) {
                                            for(i=0; i<12; ++i){
                                                if(xadrez[t][i]=='x'){
                                                    xadrez[t][i]=' ';
                                                }
                                            }
                                        }
                                }else{
                                    std::cout << "posicao invalida, tente novamente" << std::endl; //para não andar mais de duas na primeira rodada
                                    for(t=0; t<12; ++t) {
                                        for(i=0; i<12; ++i){
                                            if(xadrez[t][i]=='x'){
                                                xadrez[t][i]=' ';
                                            }
                                        }
                                    }
                                }
                            }
                        }else{
                            while((xadrez[l][c]) == 'x'){
                                c = c + 1;                        //esquerda
                            }
                          char *px;
                          char *py;
                          px = &xadrez[l][c];
                          py = &xadrez[x][y];
                            if((px==py) || (xadrez[x][y] == 'x')){
                                jogadnv = 1;
                                arquivo.open("xadrez.txt", std::ios::app);
                                arquivo << "Portanto, a RAINHA minuscula/preta foi para a posicao da linha " << x-1 << " e coluna " << y-1 << std::endl;
                                arquivo.close();
                                xadrez[x][y]=xadrez[a][b];
                                xadrez[a][b]=' ';
                                for(t=0; t<12; ++t) {
                                    for(i=0; i<12; ++i){
                                        if(xadrez[t][i]=='x'){
                                            xadrez[t][i]=' ';
                                        }
                                    }
                                }
                            }else{
                                    l = a;
                                    c = b - 1;
                                    while((xadrez[l][c]) == 'x'){
                                        c = c - 1;                 //direita
                                    }
                                    char *pz;
                                    pz = &xadrez[l][c];
                                    if((pz==py) || (xadrez[x][y] == 'x')){
                                        jogadnv = 1;
                                        arquivo.open("xadrez.txt", std::ios::app);
                                        arquivo << "Portanto, a RAINHA minuscula/preta foi para a posicao da linha " << x-1 << " e coluna " << y-1 << std::endl;
                                        arquivo.close();
                                        xadrez[x][y]= xadrez[a][b];
                                        xadrez[a][b]=' ';
                                        for(t=0; t<12; ++t) {
                                            for(i=0; i<12; ++i){
                                                if(xadrez[t][i]=='x'){
                                                    xadrez[t][i]=' ';
                                                }
                                            }
                                        }
                                }else{
                                    std::cout << "posicao invalida, tente novamente" << std::endl; //para não andar mais de duas na primeira rodada
                                    for(t=0; t<12; ++t) {
                                        for(i=0; i<12; ++i){
                                            if(xadrez[t][i]=='x'){
                                                xadrez[t][i]=' ';
                                            }
                                        }
                                    }
                                }
                            }


                        }
                    }

                    if(abs(x-a) == abs(y-b)){    //PARA TER CERTEZA QUE ESTÁ NA DIAGONAL
                        if(((x-a) == 1) || ((x-a) == -1)){
                            xadrez[x][y]= xadrez[a][b];
                            jogadnv = 1;
                            arquivo.open("xadrez.txt", std::ios::app);
                            arquivo << "Portanto, a RAINHA minuscula/preta foi para a posicao da linha " << x-1 << " e coluna " << y-1 << std::endl;
                            arquivo.close();
                            xadrez[a][b]=' ';
                            for(t=0; t<12; ++t) {
                                for(i=0; i<12; ++i){
                                    if(xadrez[t][i]=='x'){
                                        xadrez[t][i]=' ';
                                    }
                                }
                            }

                            }else{
                                if((x-a) >= 0){
                                    movimentolinha = 1;
                                }else{
                                    movimentolinha = -1;
                                }
                                if((y-b) >= 0){
                                    movimentocoluna = 1;
                                }else{
                                    movimentocoluna = -1;
                                }
                                c = b + movimentocoluna;
                                l = a + movimentolinha;
                                while(l != x && c != y){
                                    if((xadrez[l][c]!='x') || (xadrez[l][c]=!'b')){
                                        std::cout << "posicao invalida, tente novamente" << std::endl; //para não andar mais de duas na primeira rodada
                                        for(t=0; t<12; ++t) {
                                            for(i=0; i<12; ++i){
                                                if(xadrez[t][i]=='x'){
                                                    xadrez[t][i]=' ';
                                                }
                                            }
                                        }
                                        break;
                                    }
                                l += movimentolinha;
                                c += movimentocoluna;
                                }
                                if(l == x && c == y)
                                {
                                    xadrez[x][y]= xadrez[a][b];
                                    jogadnv = 1;
                                    arquivo.open("xadrez.txt", std::ios::app);
                                    arquivo << "Portanto, a RAINHA minuscula/preta foi para a posicao da linha " << x-1 << " e coluna " << y-1 << std::endl;
                                    arquivo.close();
                                    xadrez[a][b]=' ';
                                    for(t=0; t<12; ++t) {
                                        for(i=0; i<12; ++i){
                                            if(xadrez[t][i]=='x'){
                                            xadrez[t][i]=' ';
                                            }
                                        }
                                    }

                                }


                            }


                       } //stop


                }else{
                    std::cout << "posicao invalida, tente novamente" << std::endl; //para não andar mais de duas na primeira rodada
                    for(t=0; t<12; ++t) {
                        for(i=0; i<12; ++i){
                            if(xadrez[t][i]=='x'){
                                xadrez[t][i]=' ';
                            }
                        }
                    }

                }
            }else{
                std::cout << "posicao invalida, tente novamente" << std::endl; //para não andar mais de duas na primeira rodada
                for(t=0; t<12; ++t) {
                    for(i=0; i<12; ++i){
                        if(xadrez[t][i]=='x'){
                            xadrez[t][i]=' ';
                        }
                    }
                }


            }











    }



    /*REI*/
    if (xadrez[a][b]=='k'){
        printarrei2(a,b);


        std::cout << "Digite o local que deseja movimentar (ex: linha:4 e coluna:8) " << std::endl;;
            std::cout << "linha: ";
            std::cin >> x;
            std::cout << "coluna: ";
            std::cin >> y;
            x = x + 1;
            y = y + 1;


         if((xadrez[x][y]=='x') | (xadrez[x][y]=='T') | (xadrez[x][y]=='C') | (xadrez[x][y]=='B') | (xadrez[x][y]=='Q') | (xadrez[x][y]=='P')) {
            if((x==a-1) || (x==a+1) || (y==b-1) || (y==b+1)){
                xadrez[x][y]= xadrez[a][b];
                jogadnv = 1;
                arquivo.open("xadrez.txt", std::ios::app);
                arquivo << "Portanto, o REI minusculo/preto foi para a posicao da linha " << x-1 << " e coluna " << y-1 << std::endl;
                arquivo.close();
                xadrez[a][b]=' ';
                for(t=0; t<12; ++t) {
                    for(i=0; i<12; ++i){
                        if(xadrez[t][i]=='x'){
                            xadrez[t][i]=' ';
                        }
                }
                    }
            }else{
                std::cout << "posicao invalida, tente novamente" << std::endl; //para não andar mais de duas na primeira rodada
                for(t=0; t<12; ++t) {
                    for(i=0; i<12; ++i){
                        if(xadrez[t][i]=='x'){
                            xadrez[t][i]=' ';
                        }
                    }
                }
            }

        }else{
            std::cout << "posicao invalida, tente novamente" << std::endl; //para não andar mais de duas na primeira rodada
                for(t=0; t<12; ++t) {
                    for(i=0; i<12; ++i){
                        if(xadrez[t][i]=='x'){
                            xadrez[t][i]=' ';
                        }
                    }
                }
        }




    }


    /*PEAO*/
    if (xadrez[a][b]=='p'){
       printarpeao2(a,b);

        std::cout << "Digite o local que deseja movimentar (ex: linha:4 e coluna:8) " << std::endl;;
            std::cout << "linha: ";
            std::cin >> x;
            std::cout << "coluna: ";
            std::cin >> y;
            x = x + 1;
            y = y + 1;

         if(xadrez[x][y]=='x'){
                if(a==3){
                    if(((x==a+2) || (x==a+1)) && (y==b)){  //primeira rodada (do peão escolhido) pode andar duas ou uma verticalmente
                        xadrez[x][y]= xadrez[a][b];
                        xadrez[a][b]=' ';
                        jogadnv = 1;
                        arquivo.open("xadrez.txt", std::ios::app);
                        arquivo << "Portanto, o PEAO minusculo/preto foi para a posicao da linha " << x-1 << " e coluna " << y-1 << std::endl;
                        arquivo.close();
                        for(t=0; t<12; ++t) {
                        for(i=0; i<12; ++i){
                            if(xadrez[t][i]=='x'){
                                xadrez[t][i]=' ';    //limpando os x
                            }
                        }
                        }
                    }
                }else{
                if((x==a+1) && (y==b+1 || y==b || y==b-1)){  //após a primeira rodada, só anda uma verticalmente
                    xadrez[x][y]=xadrez[a][b];
                    xadrez[a][b]=' ';
                    jogadnv = 1;
                    arquivo.open("xadrez.txt", std::ios::app);
                    arquivo << "Portanto, o PEAO minusculo/preto foi para a posicao da linha " << x-1 << " e coluna " << y-1 << std::endl;
                    arquivo.close();
                    for(t=0; t<12; ++t) {
                        for(i=0; i<12; ++i){
                            if(xadrez[t][i]=='x'){
                                xadrez[t][i]=' ';
                            }
                        }
                    }
                }else{
                std::cout << "posicao invalida, tente novamente" << std::endl;  //para não andar mais de uma após a primeira rodada
                }
                }
        }else{ if((xadrez[x][y]=='T') || (xadrez[x][y]=='C') || (xadrez[x][y]=='B') || (xadrez[x][y]=='Q') || (xadrez[x][y]=='P')){ //coloquei esse grande elif para garantir que a peça peão só coma na diagonal e que seja a uma casa de distância
                if((x==a+1) && (y==b+1 || y==b-1)){  //após a primeira rodada, só anda uma verticalmente
                    xadrez[x][y]=xadrez[a][b];
                    xadrez[a][b]=' ';
                    jogadnv = 1;
                    arquivo.open("xadrez.txt", std::ios::app);
                    arquivo << "Portanto, o PEAO minusculo/preto foi para a posicao da linha " << x-1 << " e coluna " << y-1 << std::endl;
                    arquivo.close();
                    for(t=0; t<12; ++t) {
                        for(i=0; i<12; ++i){
                            if(xadrez[t][i]=='x'){
                                xadrez[t][i]=' ';
                            }
                        }
                    }
                }else{
                std::cout << "posicao invalida, tente novamente" << std::endl;
                }
            }else{
                std::cout << "posicao invalida, tente novamente" << std::endl;
                for(t=0; t<12; ++t) {
                        for(i=0; i<12; ++i){
                            if(xadrez[t][i]=='x'){
                                xadrez[t][i]=' ';
                            }
                        }
                    }
                 }
            }



    }


     int promocao;
        for(i=0; i<12; ++i){
            if(xadrez[9][i]=='p'){
                std::cout << "\n " << std::endl;
                std::cout << "PEAO DAS PECAS MINUSCULAS PROMOVIDO! " << std::endl;
                std::cout << "Escolha uma das pecas abaixo para promover seu peao da linha 8 e coluna " << i-1 << std::endl;
                std::cout << "1 - Torre " << std::endl;
                std::cout << "2 - Cavalo " << std::endl;
                std::cout << "3 - Bispo " << std::endl;
                std::cout << "4 - Rainha " << std::endl;
                arquivo.open("xadrez.txt", std::ios::app);
                while(1){
                    std::cout << "Digite o numero correspondente: " << std::endl;
                    std::cin >> promocao;
                    if(promocao==1){
                        xadrez[9][i] = 'p';
                        arquivo << "E PROMOVEU esse peao para uma TORRE "  << std::endl;
                        arquivo.close();
                        break;
                    }else if(promocao==2){
                            xadrez[9][i] = 'c';
                            arquivo << "E PROMOVEU esse peao para um CAVALO "  << std::endl;
                            arquivo.close();
                            break;
                        }else if(promocao==3){
                                xadrez[9][i] = 'b';
                                arquivo << "E PROMOVEU esse peao para um BISPO "  << std::endl;
                                arquivo.close();
                                break;
                                }else if(promocao==4){
                                    xadrez[9][i] = 'q';
                                    arquivo << "E PROMOVEU esse peao para uma RAINHA "  << std::endl;
                                    arquivo.close();
                                    break;
                                }else{
                                    std::cout << "Valor invalido, Digite novamente" << std::endl;
                                    continue;
                                }
                }

            }
        }
        int existereiB=1;
        int existereiP=1;

        for(i=0; i<12; ++i){
            for(t=0; t<12; ++t){
                if(xadrez[t][i]=='K'){
                    existereiB = existereiB - 1;
                }
            }
        }


        for(i=0; i<12; ++i){
            for(t=0; t<12; ++t){
                if(xadrez[t][i]=='k'){
                    existereiP = existereiP - 1;
                }
            }
        }

        if(existereiB==1){
                arquivo.open("xadrez.txt", std::ios::app);
                arquivo << "O JOGADOR PRETO/MINUSCULO GANHOU A PARTIDA! " << std::endl;
                arquivo.close();
                std::cout << "O JOGADOR PRETO/MINUSCULO GANHOU A PARTIDA!" << std::endl;
                std::cout << "Finalizando o programa, quer salvar o jogo? [S/N] ";
                std::cin >> querosalvar;
                if(querosalvar.compare("S")==0)
                {
                    std::cout << "Qual nome voce quer salvar o arquivo? (sem colocar .txt) ";
                    std::cin >> nomedojogo;
                    std::strcat(nomedojogo, ".txt");
                    std::rename("xadrez.txt", nomedojogo);
                    exit(0);
                }else
                {
                    remove("xadrez.txt");
                    exit(0);
                }

        }

        arquivo.open("xadrez.txt", std::ios::app);
        for(t=0; t<12; ++t) {
            for(i=0; i<12; ++i){
                    arquivo << "  "  << xadrez[t][i];
            }
        arquivo << "\n";
        }
        std::cout << "\n";
        arquivo.close();


}

std::cout << "Digite qualquer tecla para continuar. (Q - para sair): ";
    std::cin >> querocontinuar;
    if(querocontinuar.compare("Q")==0)
    {
        std::cout << "Finalizando o programa, quer salvar o jogo? [S/N] ";
        std::cin >> querosalvar;
        if(querosalvar.compare("S")==0)
        {
            std::cout << "Qual nome voce quer salvar o arquivo? (sem colocar .txt) ";
            std::cin >> nomedojogo;
            std::strcat(nomedojogo, ".txt");
            std::rename("xadrez.txt", nomedojogo);
            exit(0);
        }else
        {
            remove("xadrez.txt");
            exit(0);
        }
    }

}
