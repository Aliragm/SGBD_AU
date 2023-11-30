#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void criar_tabela(){
    FILE *arquivo_tabela;
    char tipo_dado, nome_tabela[21];
    int linhas, colunas, i, j;
    printf("Digite a quantidade de linhas e colunas respectivamente:\n");
    scanf("%i %i", &linhas, &colunas);
    printf("Selecione o tipo de dado:\n");
    getchar();
    scanf("%c", &tipo_dado);
    printf("Qual sera o nome da tabela? (Máx. 20 char)\n");
    getchar();
    fgets(nome_tabela, 20, stdin);

    if(tipo_dado == 'i'){
        int tabela[linhas][colunas];
        for (i = 0; i < linhas; i++){
            printf("Digite a %i° linha\n", i + 1);
            for (j = 0; j < colunas; j++){
                scanf("%i", &tabela[i][j]);
            }
        }
        arquivo_tabela = fopen(nome_tabela,"w");
        for (i = 0; i < linhas; i++){
            printf("\n");
            for (j = 0; j < colunas; j++){
                fprintf(arquivo_tabela, "%i ", tabela[i][j]);
            }
        }
    }
    else if(tipo_dado == 'c'){
        char tabela[linhas][colunas];
        for (i = 0; i < linhas; i++){
            printf("Digite a %i° linha\n", i + 1);
            for (j = 0; j < colunas; j++){
                scanf("%c", &tabela[i][j]);
            }
        }
        arquivo_tabela = fopen(nome_tabela,"w");
        for (i = 0; i < linhas; i++){
            printf("\n");
            for (j = 0; j < colunas; j++){
                fprintf(arquivo_tabela, "%c ", tabela[i][j]);
            }
        }
    }
    else if(tipo_dado == 'f'){
        float tabela[linhas][colunas];
        for (i = 0; i < linhas; i++){
            printf("Digite a %i° linha\n", i + 1);
            for (j = 0; j < colunas; j++){
                scanf("%f", &tabela[i][j]);
            }
        }
        for (i = 0; i < linhas; i++){
            printf("\n");
            for (j = 0; j < colunas; j++){
                fprintf(arquivo_tabela, "%f ", tabela[i][j]);
            }
        }
    }
    else if(tipo_dado == 'd'){
        double tabela[linhas][colunas];
        for (i = 0; i < linhas; i++){
            printf("Digite a %i° linha\n", i + 1);
            for (j = 0; j < colunas; j++){
                scanf("%lf", &tabela[i][j]);
            }
        }
        for (i = 0; i < linhas; i++){
            printf("\n");
            for (j = 0; j < colunas; j++){
                fprintf(arquivo_tabela, "%lf ", tabela[i][j]);
            }
        }
    }
/*    
    else if(tipo_dado == 's'){
        char *tabela[linhas][colunas];
        for (i = 0; i < linhas; i++){
            printf("Digite a %i° linha\n", i + 1);
            for (j = 0; j < colunas; j++){
                
                scanf("%s", tabela[i][j]);
            }
        }
        for (i = 0; i < linhas; i++){
            printf("\n");
            for (j = 0; j < colunas; j++){
                fprintf(arquivo_tabela, "%s ", tabela[i][j]);
            }
        }
    }
*/

    
    
    
}




int main(){
    criar_tabela();
    return 0;
}