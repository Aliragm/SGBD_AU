#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void criar_tabela(){


    /* Cria uma tabela com um número especificado de linhas e colunas, e salva a tabela em um arquivo.
    
    A função primeiro solicita ao usuário para fornecer o número de linhas e colunas, o tipo de dados para a tabela, e o nome da tabela.
    Em seguida, dependendo do tipo de dados fornecido pelo usuário, a função cria uma tabela com o número especificado de linhas e colunas.
    A função então solicita ao usuário para fornecer os valores para cada célula da tabela.
    Finalmente, a função salva a tabela em um arquivo com o nome fornecido pelo usuário.
    
    O tipo de dados pode ser um dos seguintes:
    i = int
    c = char
    f = float
    d = double
    
    Se ocorrer um erro ao abrir o arquivo para escrita, a função imprime uma mensagem de erro e retorna imediatamente.
    */
    FILE *arquivo_nomes;
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
    arquivo_nomes = fopen("NOMES.txt", "a");
    fprintf(arquivo_nomes,"%s\n", nome_tabela);
    fclose(arquivo_nomes);
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
                getchar();
            }
        }
        arquivo_tabela = fopen(nome_tabela,"w");
        if(arquivo_tabela == NULL) {
            perror("Erro ao abrir o arquivo");
            return;
        }
      fprintf(arquivo_tabela, "c\n");
        for (i = 0; i < linhas; i++){
            for (j = 0; j < colunas; j++){
                fprintf(arquivo_tabela, "%c ", tabela[i][j]);
            }
            fprintf(arquivo_tabela, "\n");
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
      fprintf(arquivo_tabela, "f\n");
        for (i = 0; i < linhas; i++){
            for (j = 0; j < colunas; j++){
                fprintf(arquivo_tabela, "%f ", tabela[i][j]);
            }
            fprintf(arquivo_tabela, "\n");
        }
        fclose(arquivo_tabela);
    }
    else if(tipo_dado == 'd'){
        double tabela[linhas][colunas];
        for (i = 0; i < linhas; i++){
            printf("Digite a linha  %i\n", i + 1);
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
        fprintf(arquivo_tabela, "d\n");
        for (i = 0; i < linhas; i++){
            for (j = 0; j < colunas; j++){
                fprintf(arquivo_tabela, "%lf ", tabela[i][j]);
            }
            fprintf(arquivo_tabela, "\n");
        }
        fclose(arquivo_tabela);
    }
}

void apagar_tabela(){
    /*    Apaga uma tabela específica.
    
    A função pede ao usuário para inserir o nome da tabela (sem a extensão .txt) que deseja apagar.
    Em seguida, lê o arquivo "NOMES.txt" linha por linha e copia todas as linhas, exceto a linha correspondente à tabela a ser apagada, para um arquivo temporário "TEMPNOMES.txt".
    Por fim, remove o arquivo da tabela e o arquivo "NOMES.txt", e renomeia o arquivo temporário "TEMPNOMES.txt" para "NOMES.txt".
    
    Variáveis:
    arquivo - Ponteiro para o arquivo "NOMES.txt".
    temp_nomes - Ponteiro para o arquivo temporário "TEMPNOMES.txt".
    nome_arquivo - Array de caracteres para armazenar o nome do arquivo inserido pelo usuário.
    linha - Array de caracteres para armazenar cada linha lida do arquivo.
    */
    FILE *arquivo;
    FILE *temp_nomes;
    char nome_arquivo[21];
    char linha[256];

    printf("Digite o nome da tabela (sem o .txt)\n:");
    getchar();
    fgets(nome_arquivo, 20, stdin);
    nome_arquivo[strcspn(nome_arquivo, "\n")] = 0;
    strcat(nome_arquivo, ".txt");
    if(strcmp(nome_arquivo, "NOMES.txt") == 0 || strcmp(nome_arquivo, "TEMP.txt") == 0 || strcmp(nome_arquivo, "TEMPNOMES.txt") == 0){
        printf("Nao e possivel apagar esse arquivo.");
        return;
    }
    arquivo = fopen("NOMES.txt", "r");
    if (arquivo == NULL) {
        printf("Não foi possível abrir o arquivo NOMES.txt\n");
        return;
    }
    temp_nomes = fopen("TEMPNOMES.txt", "w");
    if (temp_nomes == NULL) {
        printf("Não foi possível abrir o arquivo TEMPNOMES.txt\n");
        return;
    }
    while(fgets(linha, sizeof(linha), arquivo)){
        linha[strcspn(linha, "\n")] = 0;
        strcat(linha, ".txt");
        if(strcmp(linha, nome_arquivo) != 0){
            linha[strcspn(linha, ".txt")] = 0;
            fputs(linha, temp_nomes);
            fputc('\n', temp_nomes);
        }
    }
    fclose(arquivo);
    fclose(temp_nomes);
    remove(nome_arquivo);
    remove("NOMES.txt");
    rename("TEMPNOMES.txt", "NOMES.txt");
}

void lista_tabelas(){
    /*    * Lista todas as tabelas disponíveis.
    
    A função abre o arquivo "NOMES.txt" e lê cada linha, que representa uma tabela.
    Em seguida, imprime cada linha (tabela) para o usuário.
    
    Variáveis:
    arquivo - Ponteiro para o arquivo "NOMES.txt".
    linha - Array de caracteres para armazenar cada linha lida do arquivo.
    */
    FILE *arquivo;
    char linha[256];

    arquivo = fopen("NOMES.txt", "r");
    printf("As tabelas sao:\n");
    while(fgets(linha, sizeof(linha), arquivo)){
    printf("%s", linha);
    }
    fclose(arquivo);
}