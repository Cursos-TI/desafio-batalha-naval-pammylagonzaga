#include <stdio.h>

int main()
{
    //JOGO BATALHA NAVAL
    char posicaoLetras[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int tabuleiro[10][10] = {0}; // Inicializa o tabuleiro com 0 (água)

     // tabuleiro é uma matriz de 10x10, onde cada posição pode ser representada por um número inteiro (0 para água, 1 para navio, etc.)
    
     //Exemplo de saída de habilidade em cone:
        // 0 0 3 0 0
        // 0 3 3 3 0 
        // 3 3 3 3 3

    int linhaCone, colunaCone; // Exemplo de posição inicial do cone
    int topoCone = 1; // Exemplo de habilidade em cone com 3 linhas
    int baseCone = 2; // Exemplo de habilidade em cone com base de 5 colunas

    for (int i = 0; i < 3; i++)
    {
        linhaCone = topoCone + i; // Calcula a linha do cone para cada linha (aumenta a cada iteração)
        colunaCone = baseCone - i; // Calcula a coluna inicial do cone para cada linha

        for (int j = 0; j < (2 * i + 1); j++)
        {
            tabuleiro[linhaCone][colunaCone + j] = 3; // Marca a posição do cone no tabuleiro
        }
    }

    //Exemplo de saída de habilidade em cruz:

    // 0 0 3 0 0 
    // 3 3 3 3 3 
    // 0 0 3 0 0

    int alcanceCruz = 2; // Exemplo de habilidade em cruz com alcance de 2
    int centroCruzLinha = 5; // Exemplo de linha central da cruz
    int centroCruzColuna = 6; // Exemplo de coluna central da cruz

    while (alcanceCruz >= 0)
    {
        // Marca a linha central da cruz
        tabuleiro[centroCruzLinha][centroCruzColuna - alcanceCruz] = 3; // Esquerda
        tabuleiro[centroCruzLinha][centroCruzColuna + alcanceCruz] = 3; // Direita

        // Marca a coluna central da cruz
        tabuleiro[centroCruzLinha - alcanceCruz][centroCruzColuna] = 3; // Cima
        tabuleiro[centroCruzLinha + alcanceCruz][centroCruzColuna] = 3; // Baixo

        alcanceCruz--; // Diminui o alcance para a próxima iteração
    }
    
    //Exemplo de saída de habilidade em octaedro:
    // 0 0 3 0 0 
    // 0 3 3 3 0 
    // 0 0 3 0 0 

    int alcanceOctaedro = 2; // Exemplo de habilidade em octaedro com alcance de 1
    int centroOctaedroLinha = 7; // Exemplo de linha central do octaedro
    int centroOctaedroColuna = 2; // Exemplo de coluna central do octaedro
    int linha, coluna;

    for (int i = -alcanceOctaedro; i <= alcanceOctaedro; i++)
    {
        for (int j = -alcanceOctaedro; j <= alcanceOctaedro; j++)
        {
            linha = centroOctaedroLinha + i;
            coluna = centroOctaedroColuna + j;

            if (linha >= 0 && linha < 10 && coluna >= 0 && coluna < 10) // Verifica se a posição está dentro do tabuleiro
            {
                int ipositivo = (i >= 0) ? i : -i; // Valor absoluto de i
                int jpositivo = (j >= 0) ? j : -j; // Valor absoluto de j

                if (ipositivo + jpositivo <= alcanceOctaedro) // Verifica se a posição está dentro do octaedro
                {
                    tabuleiro[linha][coluna] = 3; // Marca a posição do octaedro no tabuleiro
                }
            }
        }
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