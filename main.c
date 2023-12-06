#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>


void criar_tabela(){
    FILE *arquivo_tabela;
    char tipo_dado, nome_tabela[21];
    int linhas, colunas, i, j;
    printf("Digite a quantidade de linhas e colunas respectivamente:\n");
    printf("Linhas: ");
    scanf("%i", &linhas);
    printf("Colunas: ");
    scanf("%i", &colunas);
    printf("\nSelecione o tipo de dado:\nInt = i, Char = c, Float = f, Double = d\n:");
    getchar();
    scanf("%c", &tipo_dado);
    printf("Qual sera o nome da tabela? (Max. 20 char)\n");
    getchar();
    fgets(nome_tabela, 20, stdin);
    nome_tabela[strcspn(nome_tabela, "\n")] = 0;
    strcat(nome_tabela, ".txt");

    if(tipo_dado == 'i'){
        int tabela[linhas][colunas];
        for (i = 0; i < linhas; i++){
            printf("Digite a linha %i\n", i + 1);
            for (j = 0; j < colunas; j++){
                printf("Coluna %i: ", j + 1);
                scanf("%i", &tabela[i][j]);
            }
        }
        arquivo_tabela = fopen(nome_tabela,"w");
        if(arquivo_tabela == NULL) {
            perror("Erro ao abrir o arquivo");
            return;
        }
        fprintf(arquivo_tabela, "i\n");
        for (i = 0; i < linhas; i++){
            for (j = 0; j < colunas; j++){
                fprintf(arquivo_tabela, "%i ", tabela[i][j]);
            }
            fprintf(arquivo_tabela, "\n");
        }
        fclose(arquivo_tabela);
    }
    else if(tipo_dado == 'c'){
        char tabela[linhas][colunas];
        for (i = 0; i < linhas; i++){
            printf("Digite a linha %i\n", i + 1);
            for (j = 0; j < colunas; j++){
                printf("Coluna %i: ", j + 1);
                scanf("%c", &tabela[i][j]);
            }
        }
        arquivo_tabela = fopen(nome_tabela,"w");
        if(arquivo_tabela == NULL) {
            perror("Erro ao abrir o arquivo");
            return;
        }
      fprintf(arquivo_tabela, "c ");
        for (i = 0; i < linhas; i++){
            for (j = 0; j < colunas; j++){
                fprintf(arquivo_tabela, "%c", tabela[i][j]);
            }
        }
        fclose(arquivo_tabela);
    }
    else if(tipo_dado == 'f'){
        float tabela[linhas][colunas];
        for (i = 0; i < linhas; i++){
            printf("Digite a linha %i\n", i + 1);
            for (j = 0; j < colunas; j++){
                printf("Coluna %i: ", j + 1);
                scanf("%f", &tabela[i][j]);
            }
        }
        arquivo_tabela = fopen(nome_tabela,"w");
        if(arquivo_tabela == NULL) {
            perror("Erro ao abrir o arquivo");
            return;
        }
      fprintf(arquivo_tabela, "f ");
        for (i = 0; i < linhas; i++){
            for (j = 0; j < colunas; j++){
                fprintf(arquivo_tabela, "%f", tabela[i][j]);
            }
        }
        fclose(arquivo_tabela);
    }
    else if(tipo_dado == 'd'){
        double tabela[linhas][colunas];
        for (i = 0; i < linhas; i++){
            printf("Digite a linha %i\n", i + 1);
            for (j = 0; j < colunas; j++){
                printf("Coluna %i: ", j + 1);
                scanf("%lf", &tabela[i][j]);
            }
        }
        arquivo_tabela = fopen(nome_tabela,"w");
        if(arquivo_tabela == NULL) {
            perror("Erro ao abrir o arquivo");
            return;
        }
        fprintf(arquivo_tabela, "d ");
        for (i = 0; i < linhas; i++){
            for (j = 0; j < colunas; j++){
                fprintf(arquivo_tabela, "%lf", tabela[i][j]);
            }
        }
        fclose(arquivo_tabela);
    }//implementar strings
}

void apagar_tabela(){
    char nome_arquivo[21];

    printf("Digite o nome da tabela (sem o .txt)\n:");
    getchar();
    fgets(nome_arquivo, 20, stdin);
    nome_arquivo[strcspn(nome_arquivo, "\n")] = 0;
    strcat(nome_arquivo, ".txt");
    remove(nome_arquivo);
}

void listar_dados_tabelas(){
    FILE *arquivo;
    char nome_arquivo[21];
    char linha[256];

    printf("Digite o nome do arquivo (sem o .txt)\n:");
    getchar();
    fgets(nome_arquivo, 20, stdin);
    nome_arquivo[strcspn(nome_arquivo, "\n")] = 0;
    strcat(nome_arquivo, ".txt");
    arquivo = fopen(nome_arquivo, "r");
    fseek( arquivo, 2, SEEK_SET );
    printf("Os dados sao:\n");
    while(fgets(linha, sizeof(linha), arquivo)){
    printf("%s", linha);
    }
    fclose(arquivo);
}

int main(){
    char comando;
    printf("Digite o que deseja fazer:\nCriar tabela = c\nRemover tabela = r\nListar Dados de uma tabela = l\n:");
    scanf("%c", &comando);
    switch (comando)
    {
    case 'c': criar_tabela(); break;
    case 'r': apagar_tabela(); break;
    case 'l': listar_dados_tabelas(); break;
    }
    return 0;
}
