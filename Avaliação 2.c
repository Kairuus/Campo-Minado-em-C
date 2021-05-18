#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<string.h>
#include<locale.h>
#include<windows.h>

void bombadesenho();
void gotoxy(int x,int y)
{
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
int main(){
    setlocale(LC_ALL,"");
    srand(time(NULL));
    char campo[5][5];
    int bombas[5*5];
    int linha,coluna,jogada,i,j,k,flag = 0;

    printf("\n\n---------------------SEJA BEM VINDO AO CAMPO MINADO BOOM!---------------------               Feito por: Victor Muniz\n\n");
    bombadesenho();

    for (linha = 0; linha < 5; linha++) {
        for (coluna = 0; coluna < 5; coluna++) {
            campo[linha][coluna] = 0;
        }
    }
    for (linha = 0; linha < 5*5; linha++) {
        bombas[linha] = linha;
    }
    for (linha = 0; linha < 5*5; linha++) {
        int indice, temporario = bombas[linha];
        indice = rand()%(5*5);
        bombas[linha] = bombas[indice];
        bombas[indice] = temporario;
    }
    for (linha = 0; linha < 8; linha++) {
        campo[bombas[linha]%5][bombas[linha]/5] = '*';
    }
    getch();
    system("cls");
    printf("\n\n                  Colunas\n             0   1   2   3   4\n");
    printf("Linha 0 ->    |   |   |   |   \n");
    printf("            ---+---+---+---+---\n");
    printf("Linha 1 ->    |   |   |   |   \n");
    printf("            ---+---+---+---+---\n");
    printf("Linha 2 ->    |   |   |   |   \n");
    printf("            ---+---+---+---+---\n");
    printf("Linha 3 ->    |   |   |   |   \n");
    printf("            ---+---+---+---+---\n");
    printf("Linha 4 ->    |   |   |   |   \n");
for(jogada=1;jogada<6;jogada++){
        do{
            gotoxy(5,15);
            printf("                                            \n");
            printf("                                              ");
            gotoxy(5,15);
            printf("Informa a linha que voce quer jogar: ");
            scanf("%d",&linha);
            printf("     Informe a coluna que voce quer jogar: ");
            scanf("%d",&coluna);
        }while((linha<0||linha>4) || (coluna<0||coluna>4));
        if(campo[linha][coluna]=='*'){
            printf("\n\nParece que voce pisou na bomba, BOOOOOOMMMM!");
            printf("\n\n       GAME OVER >:D");
            flag=1;
            break;
        }
         else{
         campo[linha][coluna]='X';
        }
        for(i=0;i<5;i++){
            k=13;
            for(j=0;j<5;j++){
                if(campo[i][j] !='*')
                {
                    gotoxy(k,i*2+4);
                    printf("%c",campo[i][j]);
                }
                k+=4;
            }
        }
    }
    gotoxy(0,22);
    if(flag==0)printf("    Meus parabens jogador,  Você Venceu!\n");
    printf("\n          Finalizar ... !\n\n");

return(0);
}
    void bombadesenho(){
        printf("		      *\n");
        printf("	       ___**                                             REGRAS DO JOGO:\n");
        printf("	      /	   *                     1- O jogo a seguir eh um campo minado tradicional 5x5, ou seja, 25 casas.\n");
        printf("	     /                           2- O objetivo do jogo eh selecionar 5 casas que nao tenham bombas.\n");
        printf("	   __|__                         3- Voce pode selecionar as casas informando a linha e a coluna desejada.\n");
        printf("      _____|   |_____                    4- Se voce selecionar uma casa que contem uma bomba, o jogo acaba e voce perde.");
        printf("    _/		     |_                  5- Existem 8 bombas no campo, tome cuidado.        \n");
        printf("  _/                   |_                6- Eh um jogo simples e fácil, dito isso,boa sorte e divirta-se :D. \n");
        printf(" /                       |_ \n");
        printf("|                         |\n");
        printf("|                         |\n");
        printf("|                         |\n");
        printf("|                         |\n");
        printf("|_                       _/\n");
        printf("  |_                   _/\n");
        printf("    |_________________/\n\n\n\n\n");
        printf("APERTE QUALQUER TECLA PARA INICIAR O JOGO");
    }

