#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>


void criar_tabela(){
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
            printf("Digite a linha (Até 4 digitos depois da virgula.) %i\n", i + 1);
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
                fprintf(arquivo_tabela, "%.4f ", tabela[i][j]);
            }
            fprintf(arquivo_tabela, "\n");
        }
        fclose(arquivo_tabela);
    }
    else if(tipo_dado == 'd'){
        double tabela[linhas][colunas];
        for (i = 0; i < linhas; i++){
            printf("Digite a linha (Até 4 digitos depois da virgula.) %i\n", i + 1);
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
                fprintf(arquivo_tabela, "%.4lf ", tabela[i][j]);
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
    int colunas = 0, linhas = 0, coluna_escolhida = 0;
    char *token;
    int opcao = 0;
    char tipo_arquivo;
    int valor_escolhidoI;
    double valor_escolhidoD;
    float valor_escolhidoF;
    char valor_escolhidoC;

    printf("Digite o nome do arquivo (sem o .txt)\n:");
    getchar();
    fgets(nome_arquivo, 20, stdin);
    nome_arquivo[strcspn(nome_arquivo, "\n")] = 0;
    strcat(nome_arquivo, ".txt");
    arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    fscanf(arquivo, "%c", &tipo_arquivo);
    fgets(linha, sizeof(linha), arquivo);
    fgets(linha, sizeof(linha), arquivo);
    linha[strcspn(linha, "\n")] = 0;
    token = strtok(linha, " ");
    while (token != NULL) {
        colunas += 1;
        token = strtok(NULL, " ");
    }
    rewind(arquivo);
    fscanf(arquivo, "%c", &tipo_arquivo);
    fgets(linha, sizeof(linha), arquivo);
    while(fgets(linha, sizeof(linha), arquivo)){
        linhas += 1;
    }
    rewind(arquivo);
    fscanf(arquivo, "%c", &tipo_arquivo);
    fgets(linha, sizeof(linha), arquivo);
    int tabelaI[linhas][colunas];
    float tabelaF[linhas][colunas];
    double tabelaD[linhas][colunas];
    char tabelaC[linhas][colunas];
    if(tipo_arquivo == 'i'){
        for(int i = 0; i < linhas; i++){
            for(int j = 0; j < colunas; j++){
                fscanf(arquivo, "%i", &tabelaI[i][j]);
            }
        } 
    }  
    else if(tipo_arquivo == 'f'){
        for(int i = 0; i < linhas; i++){
            for(int j = 0; j < colunas; j++){
                fscanf(arquivo, "%f", &tabelaF[i][j]);
            }
        }
    }
    else if(tipo_arquivo == 'd'){
        for(int i = 0; i < linhas; i++){
            for(int j = 0; j < colunas; j++){
                fscanf(arquivo, "%lf", &tabelaD[i][j]);
            }
        }
    }
    else if(tipo_arquivo == 'c'){
        for(int i = 0; i < linhas; i++){
            for(int j = 0; j < colunas; j++){
                fscanf(arquivo, "%c", &tabelaC[i][j]);
            }
        }
    }
    printf("existem %i colunas, selecione uma\n:", colunas);
    scanf("%i", &coluna_escolhida);
    coluna_escolhida -= 1;
    switch(tipo_arquivo){
        case 'i': printf("Digite qual o valor você deseja procurar\n:"); getchar();scanf("%i", &valor_escolhidoI); break;
        case 'f': printf("Digite qual o valor você deseja procurar\n:"); getchar();scanf("%f", &valor_escolhidoF); break;
        case 'd': printf("Digite qual o valor você deseja procurar\n:"); getchar();scanf("%lf", &valor_escolhidoD); break;
        case 'c': printf("Digite qual o valor você deseja procurar\n:"); getchar();scanf("%c", &valor_escolhidoC); break;
    }
    printf("Selecione uma opcao desejada:\n1 - valores maior que o valor informado\n2 - valores maiores ou iguais o valor informado\n3 - valores iguais ao valor informado\n4 - valores menores que o valor informado\n5 - valores menor ou igual que o valor informado\n:");
    scanf("%i", &opcao);
    getchar();
    switch(opcao){
        case 1: 
        if(tipo_arquivo == 'i'){
            int contador_memoria = 0, contadorind = 0;
            int *resultados;
            resultados = malloc(sizeof(int));
            for(int i = 0; i < linhas; i++){
                if(tabelaI[i][coluna_escolhida] > valor_escolhidoI){
                    contador_memoria += 1;
                    resultados = realloc(resultados, sizeof(int) * contador_memoria);
                    resultados[contadorind] = tabelaI[i][coluna_escolhida];
                    contadorind += 1;
                }
            }
            if(contador_memoria == 0){
                printf("Nao ha numeros que satisfazem suas exigencias.");
                return;
            }
            else{
                printf("Os numeros sao:\n");
                for(int i = 0; i < contadorind; i++){
                    printf("%i\n", resultados[i]);
                }
            }
            free(resultados);
        }
        if(tipo_arquivo == 'f'){
            int contador_memoria = 0, contadorind = 0;
            float *resultados;
            resultados = malloc(sizeof(float));
            for(int i = 0; i < linhas; i++){
                if(tabelaF[i][coluna_escolhida] > valor_escolhidoF){
                    contador_memoria += 1;
                    resultados = realloc(resultados, sizeof(float) * contador_memoria);
                    resultados[contadorind] = tabelaF[i][coluna_escolhida];
                    contadorind += 1;
                }
            }
            if(contador_memoria == 0){
                printf("Nao ha numeros que satisfazem suas exigencias.");
                return;
            }
            else{
                printf("Os numeros sao:\n");
                for(int i = 0; i < contadorind; i++){
                    printf("%f\n", resultados[i]);
                }
            }
            free(resultados);
        }
        if(tipo_arquivo == 'd'){
            int contador_memoria = 0, contadorind = 0;
            double *resultados;
            resultados = malloc(sizeof(double));
            for(int i = 0; i < linhas; i++){
                if(tabelaD[i][coluna_escolhida] > valor_escolhidoD){
                    contador_memoria += 1;
                    resultados = realloc(resultados, sizeof(double) * contador_memoria);
                    resultados[contadorind] = tabelaD[i][coluna_escolhida];
                    contadorind += 1;
                }
            }
            if(contador_memoria == 0){
                printf("Nao ha numeros que satisfazem suas exigencias.");
                return;
            }
            else{
                printf("Os numeros sao:\n");
                for(int i = 0; i < contadorind; i++){
                    printf("%lf\n", resultados[i]);
                }
            }
            free(resultados);
        }
        if(tipo_arquivo == 'c'){
            int contador_memoria = 0, contadorind = 0;
            char *resultados;
            char valor = valor_escolhidoC;
            resultados = malloc(sizeof(char));
            for(int i = 0; i < linhas; i++){   
                if(tabelaC[i][coluna_escolhida] > valor){
                    contador_memoria += 1;
                    resultados = realloc(resultados, sizeof(char) * contador_memoria);
                    resultados[contadorind] = tabelaC[i][coluna_escolhida];
                    contadorind += 1;
                }
            }
            if(contador_memoria == 0){
                printf("Nao ha caracteres que satisfazem suas exigencias.");
                return;
            }
            else{
                printf("Os caracteres sao:\n");
                for(int i = 0; i < contadorind; i++){
                    printf("%c\n", resultados[i]);
                }
            }
            free(resultados);
        }
        break;
        case 2:
        if(tipo_arquivo == 'i'){
            int contador_memoria = 0, contadorind = 0;
            int *resultados;
            resultados = malloc(sizeof(int));
            for(int i = 0; i < linhas; i++){
                if(tabelaI[i][coluna_escolhida] >= valor_escolhidoI){
                    contador_memoria += 1;
                    resultados = realloc(resultados, sizeof(int) * contador_memoria);
                    resultados[contadorind] = tabelaI[i][coluna_escolhida];
                    contadorind += 1;
                }
            }
            if(contador_memoria == 0){
                printf("Nao ha numeros que satisfazem suas exigencias.");
                return;
            }
            else{
                printf("Os numeros sao:\n");
                for(int i = 0; i < contadorind; i++){
                    printf("%i\n", resultados[i]);
                }
            }
            free(resultados);
        }
        if(tipo_arquivo == 'f'){
            int contador_memoria = 0, contadorind = 0;
            float *resultados;
            resultados = malloc(sizeof(float));
            for(int i = 0; i < linhas; i++){
                if(tabelaF[i][coluna_escolhida] >= valor_escolhidoF){
                    contador_memoria += 1;
                    resultados = realloc(resultados, sizeof(float) * contador_memoria);
                    resultados[contadorind] = tabelaF[i][coluna_escolhida];
                    contadorind += 1;
                }
            }
            if(contador_memoria == 0){
                printf("Nao ha numeros que satisfazem suas exigencias.");
                return;
            }
            else{
                printf("Os numeros sao:\n");
                for(int i = 0; i < contadorind; i++){
                    printf("%f\n", resultados[i]);
                }
            }
            free(resultados);
        }
        if(tipo_arquivo == 'd'){
            int contador_memoria = 0, contadorind = 0;
            double *resultados;
            resultados = malloc(sizeof(double));
            for(int i = 0; i < linhas; i++){
                if(tabelaD[i][coluna_escolhida] >= valor_escolhidoD){
                    contador_memoria += 1;
                    resultados = realloc(resultados, sizeof(double) * contador_memoria);
                    resultados[contadorind] = tabelaD[i][coluna_escolhida];
                    contadorind += 1;
                }
            }
            if(contador_memoria == 0){
                printf("Nao ha numeros que satisfazem suas exigencias.");
                return;
            }
            else{
                printf("Os numeros sao:\n");
                for(int i = 0; i < contadorind; i++){
                    printf("%lf\n", resultados[i]);
                }
            }
            free(resultados);
        }
        if(tipo_arquivo == 'c'){
            int contador_memoria = 0, contadorind = 0;
            char *resultados;
            char valor = valor_escolhidoC;
            resultados = malloc(sizeof(char));
            for(int i = 0; i < linhas; i++){   
                if(tabelaC[i][coluna_escolhida] >= valor){
                    contador_memoria += 1;
                    resultados = realloc(resultados, sizeof(char) * contador_memoria);
                    resultados[contadorind] = tabelaC[i][coluna_escolhida];
                    contadorind += 1;
                }
            }
            if(contador_memoria == 0){
                printf("Nao ha caracteres que satisfazem suas exigencias.");
                return;
            }
            else{
                printf("Os caracteres sao:\n");
                for(int i = 0; i < contadorind; i++){
                    printf("%c\n", resultados[i]);
                }
            }
            free(resultados);
        }
        break;
        case 3:
        if(tipo_arquivo == 'i'){
            int contador_memoria = 0, contadorind = 0;
            int *resultados;
            resultados = malloc(sizeof(int));
            for(int i = 0; i < linhas; i++){
                if(tabelaI[i][coluna_escolhida] == valor_escolhidoI){
                    contador_memoria += 1;
                    resultados = realloc(resultados, sizeof(int) * contador_memoria);
                    resultados[contadorind] = tabelaI[i][coluna_escolhida];
                    contadorind += 1;
                }
            }
            if(contador_memoria == 0){
                printf("Nao ha numeros que satisfazem suas exigencias.");
                return;
            }
            else{
                printf("Os numeros sao:\n");
                for(int i = 0; i < contadorind; i++){
                    printf("%i\n", resultados[i]);
                }
            }
            free(resultados);
        }
        if(tipo_arquivo == 'f'){
            int contador_memoria = 0, contadorind = 0;
            float *resultados;
            resultados = malloc(sizeof(float));
            for(int i = 0; i < linhas; i++){
                if(tabelaF[i][coluna_escolhida] == valor_escolhidoF){
                    contador_memoria += 1;
                    resultados = realloc(resultados, sizeof(float) * contador_memoria);
                    resultados[contadorind] = tabelaF[i][coluna_escolhida];
                    contadorind += 1;
                }
            }
            if(contador_memoria == 0){
                printf("Nao ha numeros que satisfazem suas exigencias.");
                return;
            }
            else{
                printf("Os numeros sao:\n");
                for(int i = 0; i < contadorind; i++){
                    printf("%f\n", resultados[i]);
                }
            }
            free(resultados);
        }
        if(tipo_arquivo == 'd'){
            int contador_memoria = 0, contadorind = 0;
            double *resultados;
            resultados = malloc(sizeof(double));
            for(int i = 0; i < linhas; i++){
                if(tabelaD[i][coluna_escolhida] == valor_escolhidoD){
                    contador_memoria += 1;
                    resultados = realloc(resultados, sizeof(double) * contador_memoria);
                    resultados[contadorind] = tabelaD[i][coluna_escolhida];
                    contadorind += 1;
                }
            }
            if(contador_memoria == 0){
                printf("Nao ha numeros que satisfazem suas exigencias.");
                return;
            }
            else{
                printf("Os numeros sao:\n");
                for(int i = 0; i < contadorind; i++){
                    printf("%lf\n", resultados[i]);
                }
            }
            free(resultados);
        }
        if(tipo_arquivo == 'c'){
            int contador_memoria = 0, contadorind = 0;
            char *resultados;
            char valor = valor_escolhidoC;
            resultados = malloc(sizeof(char));
            for(int i = 0; i < linhas; i++){   
                if(tabelaC[i][coluna_escolhida] == valor){
                    contador_memoria += 1;
                    resultados = realloc(resultados, sizeof(char) * contador_memoria);
                    resultados[contadorind] = tabelaC[i][coluna_escolhida];
                    contadorind += 1;
                }
            }
            if(contador_memoria == 0){
                printf("Nao ha caracteres que satisfazem suas exigencias.");
                return;
            }
            else{
                printf("Os caracteres sao:\n");
                for(int i = 0; i < contadorind; i++){
                    printf("%c\n", resultados[i]);
                }
            }
            free(resultados);
        }
        break;
        case 4:
        if(tipo_arquivo == 'i'){
            int contador_memoria = 0, contadorind = 0;
            int *resultados;
            resultados = malloc(sizeof(int));
            for(int i = 0; i < linhas; i++){
                if(tabelaI[i][coluna_escolhida] < valor_escolhidoI){
                    contador_memoria += 1;
                    resultados = realloc(resultados, sizeof(int) * contador_memoria);
                    resultados[contadorind] = tabelaI[i][coluna_escolhida];
                    contadorind += 1;
                }
            }
            if(contador_memoria == 0){
                printf("Nao ha numeros que satisfazem suas exigencias.");
                return;
            }
            else{
                printf("Os numeros sao:\n");
                for(int i = 0; i < contadorind; i++){
                    printf("%i\n", resultados[i]);
                }
            }
            free(resultados);
        }
        if(tipo_arquivo == 'f'){
            int contador_memoria = 0, contadorind = 0;
            float *resultados;
            resultados = malloc(sizeof(float));
            for(int i = 0; i < linhas; i++){
                if(tabelaF[i][coluna_escolhida] < valor_escolhidoF){
                    contador_memoria += 1;
                    resultados = realloc(resultados, sizeof(float) * contador_memoria);
                    resultados[contadorind] = tabelaF[i][coluna_escolhida];
                    contadorind += 1;
                }
            }
            if(contador_memoria == 0){
                printf("Nao ha numeros que satisfazem suas exigencias.");
                return;
            }
            else{
                printf("Os numeros sao:\n");
                for(int i = 0; i < contadorind; i++){
                    printf("%f\n", resultados[i]);
                }
            }
            free(resultados);
        }
        if(tipo_arquivo == 'd'){
            int contador_memoria = 0, contadorind = 0;
            double *resultados;
            resultados = malloc(sizeof(double));
            for(int i = 0; i < linhas; i++){
                if(tabelaD[i][coluna_escolhida] < valor_escolhidoD){
                    contador_memoria += 1;
                    resultados = realloc(resultados, sizeof(double) * contador_memoria);
                    resultados[contadorind] = tabelaD[i][coluna_escolhida];
                    contadorind += 1;
                }
            }
            if(contador_memoria == 0){
                printf("Nao ha numeros que satisfazem suas exigencias.");
                return;
            }
            else{
                printf("Os numeros sao:\n");
                for(int i = 0; i < contadorind; i++){
                    printf("%lf\n", resultados[i]);
                }
            }
            free(resultados);
        }
        if(tipo_arquivo == 'c'){
            int contador_memoria = 0, contadorind = 0;
            char *resultados;
            char valor = valor_escolhidoC;
            resultados = malloc(sizeof(char));
            for(int i = 0; i < linhas; i++){   
                if(tabelaC[i][coluna_escolhida] < valor){
                    contador_memoria += 1;
                    resultados = realloc(resultados, sizeof(char) * contador_memoria);
                    resultados[contadorind] = tabelaC[i][coluna_escolhida];
                    contadorind += 1;
                }
            }
            if(contador_memoria == 0){
                printf("Nao ha caracteres que satisfazem suas exigencias.");
                return;
            }
            else{
                printf("Os caracteres sao:\n");
                for(int i = 0; i < contadorind; i++){
                    printf("%c\n", resultados[i]);
                }
            }
            free(resultados);
        }
        break;
        case 5:
        if(tipo_arquivo == 'i'){
            int contador_memoria = 0, contadorind = 0;
            int *resultados;
            resultados = malloc(sizeof(int));
            for(int i = 0; i < linhas; i++){
                if(tabelaI[i][coluna_escolhida] <= valor_escolhidoI){
                    contador_memoria += 1;
                    resultados = realloc(resultados, sizeof(int) * contador_memoria);
                    resultados[contadorind] = tabelaI[i][coluna_escolhida];
                    contadorind += 1;
                }
            }
            if(contador_memoria == 0){
                printf("Nao ha numeros que satisfazem suas exigencias.");
                return;
            }
            else{
                printf("Os numeros sao:\n");
                for(int i = 0; i < contadorind; i++){
                    printf("%i\n", resultados[i]);
                }
            }
            free(resultados);
        }
        if(tipo_arquivo == 'f'){
            int contador_memoria = 0, contadorind = 0;
            float *resultados;
            resultados = malloc(sizeof(float));
            for(int i = 0; i < linhas; i++){
                if(tabelaF[i][coluna_escolhida] <= valor_escolhidoF){
                    contador_memoria += 1;
                    resultados = realloc(resultados, sizeof(float) * contador_memoria);
                    resultados[contadorind] = tabelaF[i][coluna_escolhida];
                    contadorind += 1;
                }
            }
            if(contador_memoria == 0){
                printf("Nao ha numeros que satisfazem suas exigencias.");
                return;
            }
            else{
                printf("Os numeros sao:\n");
                for(int i = 0; i < contadorind; i++){
                    printf("%f\n", resultados[i]);
                }
            }
            free(resultados);
        }
        if(tipo_arquivo == 'd'){
            int contador_memoria = 0, contadorind = 0;
            double *resultados;
            resultados = malloc(sizeof(double));
            for(int i = 0; i < linhas; i++){
                if(tabelaD[i][coluna_escolhida] <= valor_escolhidoD){
                    contador_memoria += 1;
                    resultados = realloc(resultados, sizeof(double) * contador_memoria);
                    resultados[contadorind] = tabelaD[i][coluna_escolhida];
                    contadorind += 1;
                }
            }
            if(contador_memoria == 0){
                printf("Nao ha numeros que satisfazem suas exigencias.");
                return;
            }
            else{
                printf("Os numeros sao:\n");
                for(int i = 0; i < contadorind; i++){
                    printf("%lf\n", resultados[i]);
                }
            }
            free(resultados);
        }
        if(tipo_arquivo == 'c'){
            int contador_memoria = 0, contadorind = 0;
            char *resultados;
            char valor = valor_escolhidoC;
            resultados = malloc(sizeof(char));
            for(int i = 0; i < linhas; i++){   
                if(tabelaC[i][coluna_escolhida] <= valor){
                    contador_memoria += 1;
                    resultados = realloc(resultados, sizeof(char) * contador_memoria);
                    resultados[contadorind] = tabelaC[i][coluna_escolhida];
                    contadorind += 1;
                }
            }
            if(contador_memoria == 0){
                printf("Nao ha caracteres que satisfazem suas exigencias.");
                return;
            }
            else{
                printf("Os caracteres sao:\n");
                for(int i = 0; i < contadorind; i++){
                    printf("%c\n", resultados[i]);
                }
            }
            free(resultados);
        }
        break;

    }
    fclose(arquivo);
}

void lista_tabelas(){
    FILE *arquivo;
    char linha[256];

    arquivo = fopen("NOMES.txt", "r");
    printf("As tabelas são:\n");
    while(fgets(linha, sizeof(linha), arquivo)){
    printf("%s", linha);
    }
    fclose(arquivo);
    
}

void apagar_linha(){
    FILE *arquivo;
    FILE *arquivo_temp;
    char linha[256];
    char nome_arquivo[21];
    int contador_linhas = 1;
    int linha_para_apagar = 0;

    printf("Escolha o nome da tabela que deseja apagar o registro\n:");
    getchar();
    fgets(nome_arquivo, 20, stdin);
    nome_arquivo[strcspn(nome_arquivo, "\n")] = 0;
    strcat(nome_arquivo, ".txt");
    arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        printf("Não foi possível abrir o arquivo %s\n", nome_arquivo);
        return;
    }
    arquivo_temp = fopen("Temp.txt", "w");
    if (arquivo_temp == NULL) {
        printf("Não foi possível abrir o arquivo Temp.txt\n");
        return;
    }
    while(fgets(linha, sizeof(linha), arquivo)){
        linha_para_apagar += 1;
    }
    printf("Escolha o registro que deseja apagar, existem %i registros\n:", linha_para_apagar - 1);
    scanf("%i", &linha_para_apagar);
    linha_para_apagar;
    if (linha_para_apagar <= 1) {
        printf("Não é possível apagar a primeira linha.\n");
        return;
    }
    rewind(arquivo);
    while(fgets(linha, sizeof(linha), arquivo) != NULL){
        if(contador_linhas != linha_para_apagar){
            fputs(linha, arquivo_temp);
        }
        contador_linhas += 1;
    }
    fclose(arquivo);
    fclose(arquivo_temp);
    remove(nome_arquivo);
    rename("Temp.txt", nome_arquivo);
}

int main(){
    char comando;
    while (comando != 's')
    {
        printf("\n\nDigite o que deseja fazer:\nCriar tabela = c\nRemover tabela = r\nListar Dados de uma tabela = l\nPesquisar valor em uma tabela = p\nListar tabelas = n\nApaagar registro = a\nSair do programa = s\n:");
        scanf("%c", &comando);
        switch (comando)
        {
        case 'c': criar_tabela(); break;
        case 'r': apagar_tabela(); break;
        case 'l': listar_dados_tabelas(); break;
        case 'p': pesquisar_valor(); break;
        case 'n': lista_tabelas(); break;
        case 'a': apagar_linha(); break;
        }
    }
    return 0;
}
