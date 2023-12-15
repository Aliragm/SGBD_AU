#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void listar_dados_tabelas(){
    /*    * Lista todos os dados de uma tabela específica.
    
    A função pede ao usuário para inserir o nome do arquivo (sem a extensão .txt) do qual deseja listar os dados.
    Em seguida, lê o arquivo linha por linha a partir da terceira linha e imprime cada linha (dado) para o usuário.
    
    Variáveis:
    arquivo - Ponteiro para o arquivo.
    nome_arquivo - Array de caracteres para armazenar o nome do arquivo inserido pelo usuário.
    linha - Array de caracteres para armazenar cada linha lida do arquivo.
    */
    FILE *arquivo;
    char nome_arquivo[21];
    char linha[256];

    printf("Digite o nome do arquivo (sem o .txt)\n:");
    getchar();
    fgets(nome_arquivo, 20, stdin);
    nome_arquivo[strcspn(nome_arquivo, "\n")] = 0;
    strcat(nome_arquivo, ".txt");
    if(strcmp(nome_arquivo, "NOMES.txt") == 0 || strcmp(nome_arquivo, "TEMP.txt") == 0 || strcmp(nome_arquivo, "TEMPNOMES.txt") == 0){
        printf("Nao e possivel acessar esse arquivo.");
        return;
    }
    arquivo = fopen(nome_arquivo, "r");
    fseek(arquivo, 2, SEEK_SET);
    printf("Os dados sao:\n");
    while(fgets(linha, sizeof(linha), arquivo)){
    printf("%s", linha);
    }
    fclose(arquivo);
    
}

void pesquisar_valor(){
    /*    * Realiza uma operação de busca em uma tabela específica com base em um valor fornecido pelo usuário.
    
    A função pede ao usuário para inserir o nome do arquivo (sem a extensão .txt) no qual deseja realizar a busca.
    Em seguida, lê o arquivo linha por linha para determinar o número de colunas e linhas existentes.
    O usuário é então solicitado a inserir o valor que deseja procurar e a coluna na qual deseja procurar.
    A função suporta diferentes tipos de arquivos, cada um representado por um caractere ('i' para int, 'f' para float, 'd' para double, 'c' para char).
    O usuário também é solicitado a escolher uma opção de comparação (maior, maior ou igual, igual, menor, menor ou igual).
    
    Variáveis:
    arquivo - Ponteiro para o arquivo.
    nome_arquivo - Array de caracteres para armazenar o nome do arquivo inserido pelo usuário.
    linha - Array de caracteres para armazenar cada linha lida do arquivo.
    colunas - Contador para acompanhar o número de colunas no arquivo.
    linhas - Contador para acompanhar o número de linhas no arquivo.
    coluna_escolhida - Número da coluna na qual o usuário deseja procurar.
    token - Ponteiro para armazenar cada token ao dividir a linha em colunas.
    opcao - Opção de comparação escolhida pelo usuário.
    tipo_arquivo - Caractere para armazenar o tipo do arquivo.
    valor_escolhidoI - Valor inteiro que o usuário deseja procurar.
    valor_escolhidoD - Valor double que o usuário deseja procurar.
    valor_escolhidoF - Valor float que o usuário deseja procurar.
    valor_escolhidoC - Caractere que o usuário deseja procurar.
    tabelaI - Matriz de inteiros para armazenar os dados do arquivo se o tipo do arquivo for 'i'.
    tabelaF - Matriz de floats para armazenar os dados do arquivo se o tipo do arquivo for 'f'.
    tabelaD - Matriz de doubles para armazenar os dados do arquivo se o tipo do arquivo for 'd'.
    tabelaC - Matriz de caracteres para armazenar os dados do arquivo se o tipo do arquivo for 'c'.
    */
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
    if(strcmp(nome_arquivo, "NOMES.txt") == 0 || strcmp(nome_arquivo, "TEMP.txt") == 0 || strcmp(nome_arquivo, "TEMPNOMES.txt") == 0){
        printf("Nao e possivel acessar esse arquivo.");
        return;
    }
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

void apagar_linha(){
    /*  Apaga uma linha específica de um arquivo de texto.
    
    A função pede ao usuário para inserir o nome do arquivo (tabela) do qual deseja apagar um registro (linha).
    Em seguida, lê o arquivo linha por linha e copia todas as linhas, exceto a linha a ser apagada, para um arquivo temporário.
    Por fim, remove o arquivo original e renomeia o arquivo temporário com o nome do arquivo original.
    
    Variáveis:
    arquivo - Ponteiro para o arquivo original.
    arquivo_temp - Ponteiro para o arquivo temporário.
    linha - Array de caracteres para armazenar cada linha lida do arquivo.
    nome_arquivo - Array de caracteres para armazenar o nome do arquivo inserido pelo usuário.
    contador_linhas - Contador para acompanhar o número da linha atual enquanto lê o arquivo.
    linha_para_apagar - Número da linha a ser apagada.
    */
    FILE *arquivo;
    FILE *arquivo_temp;
    char linha[256];
    char nome_arquivo[21];
    int contador_linhas = 0;
    int linha_para_apagar = 0;

    printf("Escolha o nome da tabela que deseja apagar o registro\n:");
    getchar();
    fgets(nome_arquivo, 20, stdin);
    nome_arquivo[strcspn(nome_arquivo, "\n")] = 0;
    strcat(nome_arquivo, ".txt");
    if(strcmp(nome_arquivo, "NOMES.txt") == 0 || strcmp(nome_arquivo, "TEMP.txt") == 0 || strcmp(nome_arquivo, "TEMPNOMES.txt") == 0){
        printf("Nao e possivel acessar esse arquivo.");
        return;
    }
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

void add_registro(){
    /*
    Adiciona um novo registro (linha) a um arquivo de texto.
    
    A função pede ao usuário para inserir o nome do arquivo (sem a extensão .txt) ao qual deseja adicionar um registro.
    Em seguida, lê o arquivo linha por linha para determinar o número de colunas e linhas existentes.
    O usuário é então solicitado a inserir os valores para cada coluna do novo registro.
    Os valores são adicionados ao final do arquivo.
    
    Variáveis:
    arquivo - Ponteiro para o arquivo.
    nome_arquivo - Array de caracteres para armazenar o nome do arquivo inserido pelo usuário.
    linha - Array de caracteres para armazenar cada linha lida do arquivo.
    colunas - Contador para acompanhar o número de colunas no arquivo.
    linhas - Contador para acompanhar o número de linhas no arquivo.
    tipo_arquivo - Caractere para armazenar o tipo do arquivo.
    token - Ponteiro para armazenar cada token ao dividir a linha em colunas.
    coisas_addI - Variável para armazenar o valor inteiro a ser adicionado ao arquivo.
    coisas_addF - Variável para armazenar o valor float a ser adicionado ao arquivo.
    coisas_addD - Variável para armazenar o valor double a ser adicionado ao arquivo.
    coisas_addC - Variável para armazenar o caractere a ser adicionado ao arquivo.
    */
    FILE *arquivo;
    char nome_arquivo[21];
    char linha[256];
    int colunas = 0, linhas = 0;
    char tipo_arquivo;
    char *token;
    int coisas_addI;
    float coisas_addF;
    double coisas_addD;
    char coisas_addC;

    printf("Digite o nome do arquivo (sem o .txt)\n:");
    getchar();
    fgets(nome_arquivo, 20, stdin);
    nome_arquivo[strcspn(nome_arquivo, "\n")] = 0;
    strcat(nome_arquivo, ".txt");
    if(strcmp(nome_arquivo, "NOMES.txt") == 0 || strcmp(nome_arquivo, "TEMP.txt") == 0 || strcmp(nome_arquivo, "TEMPNOMES.txt") == 0){
        printf("Nao e possivel acessar esse arquivo.");
        return;
    }
    arquivo = fopen(nome_arquivo, "r+");
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
    fgets(linha, sizeof(linha), arquivo);
    while(fgets(linha, sizeof(linha), arquivo)){
        linhas += 1;
    }
    fseek(arquivo, 0, SEEK_END);
    switch(tipo_arquivo){
        case 'i':
        for(int i = 0; i < colunas; i++){
            printf("Digite o numero a ser adicionado na coluna %i\n:", i + 1);
            scanf("%i", &coisas_addI);
            fprintf(arquivo, "%i ", coisas_addI);
        }
        fprintf(arquivo, "\n");
        printf("Linha adicionada com sucesso, agora ha %i linhas", linhas + 1);
        break;
        case 'f':
        for(int i = 0; i < colunas; i++){
            printf("Digite o numero a ser adicionado na coluna %i\n:", i + 1);
            scanf("%f", &coisas_addF);
            fprintf(arquivo, "%f ", coisas_addF);
        }
        fprintf(arquivo, "\n");
        printf("Linha adicionada com sucesso, agora ha %i linhas", linhas + 1);
        break;
        case 'd':
        for(int i = 0; i < colunas; i++){
            printf("Digite o numero a ser adicionado na coluna %i\n:", i + 1);
            scanf("%lf", &coisas_addD);
            fprintf(arquivo, "%lf ", coisas_addD);
        }
        fprintf(arquivo, "\n");
        printf("Linha adicionada com sucesso, agora ha %i linhas", linhas + 1);
        break;
        case 'c':
        for(int i = 0; i < colunas; i++){
            printf("Digite o caratere a ser adicionado na coluna %i\n:", i + 1);
            scanf(" %c", &coisas_addC);
            fprintf(arquivo, "%c ", coisas_addC);
        }
        fprintf(arquivo, "\n");
        printf("Linha adicionada com sucesso, agora ha %i linhas", linhas + 1);
        break;
    }
    fclose(arquivo);
}