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
                getchar();
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
      fprintf(arquivo_tabela, "f ");
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
                fprintf(arquivo_tabela, "%lf ", tabela[i][j]);
            }
            fprintf(arquivo_tabela, "\n");
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
    fseek(arquivo, 2, SEEK_SET);
    printf("Os dados sao:\n");
    while(fgets(linha, sizeof(linha), arquivo)){
    printf("%s", linha);
    }
    fclose(arquivo);
}

void pesquisar_valor(){
    FILE *arquivo;
    char nome_arquivo[21];
    char linha[256];
    int colunas = 0;
    int opcao = 0;
    char tipo_arquivo;
    char valor_da_vez[3];
    char valor_pesquisa;

    printf("Digite o nome do arquivo (sem o .txt)\n:");
    getchar();
    fgets(nome_arquivo, 20, stdin);
    nome_arquivo[strcspn(nome_arquivo, "\n")] = 0;
    strcat(nome_arquivo, ".txt");
    arquivo = fopen(nome_arquivo, "r");
    fscanf(arquivo, "%c", tipo_arquivo);
    fseek(arquivo, 2, SEEK_SET);
    fgets(linha, sizeof(linha), arquivo);
    for(int i = 0; i < sizeof(linha); i++){
        if(linha[i] == ' '){
            colunas += 1;
        }
    }
    printf("Selecione uma coluna das %i disponiveis: ", colunas);
    scanf("%i", &colunas);
    printf("Digite qual o valor você deseja procurar\n:");
    getchar();
    scanf("%c", &valor_pesquisa);
    printf("Selecione uma opcao desejada:\n1 - valores maior que o valor informado\n2 - valores maiores ou iguais o valor informado\n3 - valores iguais ao valor informado\n4 - valores menores que o valor informado\n5 - valores menor ou igual que o valor informado\n:");
    scanf("%i", &opcao);
    //lembrar-se de adicionar o ngc de strings quando strings for implementado
    switch(opcao){
        case 1:
        if(tipo_arquivo == 'i' | tipo_arquivo == 'f' | tipo_arquivo == 'd'){
            double *resultados;
            int contador_alocacao = 0;
            int contador_indice = 0;
            resultados = malloc(sizeof(double));
            if(colunas == 1){
                while(fgets(valor_da_vez, 1, arquivo)){
                    if(strtod(valor_da_vez, NULL) > strtod(valor_pesquisa, NULL)){
                        contador_alocacao += 1;
                        resultados = realloc(resultados, sizeof(double) * contador_alocacao);
                        resultados[contador_indice] = strtod(valor_da_vez, NULL);
                        contador_indice += 1;
                    }
                }
                if(sizeof(resultados) == sizeof(double)){
                    printf("Não há valores elegíveis");
                    break;
                }
                else{
                    printf("Os valores que se encaixam são:\n");
                    for(int i = 0; i < contador_indice; i++){
                        printf("%i\n", resultados[i]);
                    }
                }
            }
            else{
                fseek(arquivo, 2 * colunas, SEEK_SET);
                while(fgets(valor_da_vez, 1, arquivo)){
                    if(strtod(valor_da_vez, NULL) > strtod(valor_pesquisa, NULL)){
                        contador_alocacao += 1;
                        resultados = realloc(resultados, sizeof(double) * contador_alocacao);
                        resultados[contador_indice] = strtod(valor_da_vez, NULL);
                        contador_indice += 1;
                    }
                }
                if(sizeof(resultados) == sizeof(double)){
                    printf("Não há valores elegíveis");
                }
                else{
                    printf("Os valores que se encaixam são:\n");
                    for(int i = 0; i < contador_indice; i++){
                        printf("%i\n", resultados[i]);
                    }
                }
            }
            free(resultados);
        }
        else{//char

        }
        break;
        case 2: 
        if(tipo_arquivo == 'i' | tipo_arquivo == 'f' | tipo_arquivo == 'd'){
            double *resultados;
            int contador_alocacao = 0;
            int contador_indice = 0;
            resultados = malloc(sizeof(double));
            if(colunas == 1){
                while(fgets(valor_da_vez, 1, arquivo)){
                    if(strtod(valor_da_vez, NULL) >= strtod(valor_pesquisa, NULL)){
                        contador_alocacao += 1;
                        resultados = realloc(resultados, sizeof(double) * contador_alocacao);
                        resultados[contador_indice] = strtod(valor_da_vez, NULL);
                        contador_indice += 1;
                    }
                }
                if(sizeof(resultados) == sizeof(double)){
                    printf("Não há valores elegíveis");
                    break;
                }
                else{
                    printf("Os valores que se encaixam são:\n");
                    for(int i = 0; i < contador_indice; i++){
                        printf("%i\n", resultados[i]);
                    }
                }
            }
            else{
                fseek(arquivo, 2 * colunas, SEEK_SET);
                while(fgets(valor_da_vez, 1, arquivo)){
                    if(strtod(valor_da_vez, NULL) >= strtod(valor_pesquisa, NULL)){
                        contador_alocacao += 1;
                        resultados = realloc(resultados, sizeof(double) * contador_alocacao);
                        resultados[contador_indice] = strtod(valor_da_vez, NULL);
                        contador_indice += 1;
                    }
                }
                if(sizeof(resultados) == sizeof(double)){
                    printf("Não há valores elegíveis");
                }
                else{
                    printf("Os valores que se encaixam são:\n");
                    for(int i = 0; i < contador_indice; i++){
                        printf("%i\n", resultados[i]);
                    }
                }
            }
            free(resultados);
        }
        else{//char
              
        }
        break;
        case 3:
        if(tipo_arquivo == 'i' | tipo_arquivo == 'f' | tipo_arquivo == 'd'){
            double *resultados;
            int contador_alocacao = 0;
            int contador_indice = 0;
            resultados = malloc(sizeof(double));
            if(colunas == 1){
                while(fgets(valor_da_vez, 1, arquivo)){
                    if(strtod(valor_da_vez, NULL) == strtod(valor_pesquisa, NULL)){
                        contador_alocacao += 1;
                        resultados = realloc(resultados, sizeof(double) * contador_alocacao);
                        resultados[contador_indice] = strtod(valor_da_vez, NULL);
                        contador_indice += 1;
                    }
                }
                if(sizeof(resultados) == sizeof(double)){
                    printf("Não há valores elegíveis");
                    break;
                }
                else{
                    printf("Os valores que se encaixam são:\n");
                    for(int i = 0; i < contador_indice; i++){
                        printf("%i\n", resultados[i]);
                    }
                }
            }
            else{
                fseek(arquivo, 2 * colunas, SEEK_SET);
                while(fgets(valor_da_vez, 1, arquivo)){
                    if(strtod(valor_da_vez, NULL) == strtod(valor_pesquisa, NULL)){
                        contador_alocacao += 1;
                        resultados = realloc(resultados, sizeof(double) * contador_alocacao);
                        resultados[contador_indice] = strtod(valor_da_vez, NULL);
                        contador_indice += 1;
                    }
                }
                if(sizeof(resultados) == sizeof(double)){
                    printf("Não há valores elegíveis");
                }
                else{
                    printf("Os valores que se encaixam são:\n");
                    for(int i = 0; i < contador_indice; i++){
                        printf("%i\n", resultados[i]);
                    }
                }
            }
            free(resultados);
        }
        else{//char

        }
        break;
        case 4:
        if(tipo_arquivo == 'i' | tipo_arquivo == 'f' | tipo_arquivo == 'd'){
            double *resultados;
            int contador_alocacao = 0;
            int contador_indice = 0;
            resultados = malloc(sizeof(double));
            if(colunas == 1){
                while(fgets(valor_da_vez, 1, arquivo)){
                    if(strtod(valor_da_vez, NULL) < strtod(valor_pesquisa, NULL)){
                        contador_alocacao += 1;
                        resultados = realloc(resultados, sizeof(double) * contador_alocacao);
                        resultados[contador_indice] = strtod(valor_da_vez, NULL);
                        contador_indice += 1;
                    }
                }
                if(sizeof(resultados) == sizeof(double)){
                    printf("Não há valores elegíveis");
                    break;
                }
                else{
                    printf("Os valores que se encaixam são:\n");
                    for(int i = 0; i < contador_indice; i++){
                        printf("%i\n", resultados[i]);
                    }
                }
            }
            else{
                fseek(arquivo, 2 * colunas, SEEK_SET);
                while(fgets(valor_da_vez, 1, arquivo)){
                    if(strtod(valor_da_vez, NULL) < strtod(valor_pesquisa, NULL)){
                        contador_alocacao += 1;
                        resultados = realloc(resultados, sizeof(double) * contador_alocacao);
                        resultados[contador_indice] = strtod(valor_da_vez, NULL);
                        contador_indice += 1;
                    }
                }
                if(sizeof(resultados) == sizeof(double)){
                    printf("Não há valores elegíveis");
                }
                else{
                    printf("Os valores que se encaixam são:\n");
                    for(int i = 0; i < contador_indice; i++){
                        printf("%i\n", resultados[i]);
                    }
                }
            }
            free(resultados);
        }
        else{//char

        } 
        break;
        case 5: 
        if(tipo_arquivo == 'i' | tipo_arquivo == 'f' | tipo_arquivo == 'd'){
            double *resultados;
            int contador_alocacao = 0;
            int contador_indice = 0;
            resultados = malloc(sizeof(double));
            if(colunas == 1){
                while(fgets(valor_da_vez, 1, arquivo)){
                    if(strtod(valor_da_vez, NULL) <= strtod(valor_pesquisa, NULL)){
                        contador_alocacao += 1;
                        resultados = realloc(resultados, sizeof(double) * contador_alocacao);
                        resultados[contador_indice] = strtod(valor_da_vez, NULL);
                        contador_indice += 1;
                    }
                }
                if(sizeof(resultados) == sizeof(double)){
                    printf("Não há valores elegíveis");
                    break;
                }
                else{
                    printf("Os valores que se encaixam são:\n");
                    for(int i = 0; i < contador_indice; i++){
                        printf("%i\n", resultados[i]);
                    }
                }
            }
            else{
                fseek(arquivo, 2 * colunas, SEEK_SET);
                while(fgets(valor_da_vez, 1, arquivo)){
                    if(strtod(valor_da_vez, NULL) <= strtod(valor_pesquisa, NULL)){
                        contador_alocacao += 1;
                        resultados = realloc(resultados, sizeof(double) * contador_alocacao);
                        resultados[contador_indice] = strtod(valor_da_vez, NULL);
                        contador_indice += 1;
                    }
                }
                if(sizeof(resultados) == sizeof(double)){
                    printf("Não há valores elegíveis");
                }
                else{
                    printf("Os valores que se encaixam são:\n");
                    for(int i = 0; i < contador_indice; i++){
                        printf("%i\n", resultados[i]);
                    }
                }
            }
            free(resultados);
        }
        else{//char

        }
        break;
        //lembrar de add o caso 6 das strings
    }
}

int main(){
    char comando;
    while (comando != 's')
    {
        printf("\n\nDigite o que deseja fazer:\nCriar tabela = c\nRemover tabela = r\nListar Dados de uma tabela = l\nSair do programa = s\n:");
        scanf("%c", &comando);
        switch (comando)
        {
        case 'c': criar_tabela(); break;
        case 'r': apagar_tabela(); break;
        case 'l': listar_dados_tabelas(); break;
        }
    }
    return 0;
}
