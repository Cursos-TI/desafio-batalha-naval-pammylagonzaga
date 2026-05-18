#include <stdio.h>

int main()
{
    //JOGO BATALHA NAVAL
    char posicaoLetras[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int tabuleiro[10][10] = {0}; // Inicializa o tabuleiro com 0 (água)

     // tabuleiro é uma matriz de 10x10, onde cada posição pode ser representada por um número inteiro (0 para água, 1 para navio, etc.)
    
     int linhaH = 8, colH = 1; // Exemplo de posição do navio (linha 8, coluna 1) +1 pois conta o 0;
     for (int i = 0; i < 3; i++)
     {
        tabuleiro[linhaH][colH + i] = 3; // Marca a posição do navio no tabuleiro
     }

     int linhaV = 2, colV = 5; // Exemplo de posição do navio (linha 2, coluna 5)+1 pois conta o 0;
        for (int i = 0; i < 3; i++)
        {
            tabuleiro[linhaV + i][colV] = 3; // Marca a posição do navio no tabuleiro
        }
     
    int linhaD, colD;
    for (int i = 0; i < 3; i++)
    {
        linhaD = 7 + i; // Exemplo de posição do navio diagonal (linha 8, coluna 5) +1 pois conta o 0;
        colD = 4 + i;
        tabuleiro[linhaD][colD] = 3; // Marca a posição do navio no tabuleiro
    }

    int linhaD2, colD2;
    for (int i = 0; i < 3; i++)
    {
        linhaD2 = 1 + i; // Exemplo de posição do navio diagonal (linha 2, coluna 5 consecutivamente) +1 pois conta o 0;
        colD2 = 4 - i;
        tabuleiro[linhaD2][colD2] = 3; // Marca a posição do navio no tabuleiro
    }

    // -------------------------------- EXIBIÇÃO DO TABULEIRO ------------------ --------------

    printf("TABULEIRO BATALHA NAVAL \n");    
    
    for (int i = 0; i < 10; i++)
    {
        printf(" %c ", posicaoLetras[i]); // Imprime as letras das colunas
    }
    printf("\n");

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", i+1);
        for (int j = 0; j < 10; j++)
        {
            if (tabuleiro[i][j] == 3) // Verifica se há um navio na posição
            {
                printf(" 3 "); // Representa um navio
            }
            else
            {
                printf(" 0 "); // Representa água
            }
        }
        printf("\n");
    }  

    return 0;
}