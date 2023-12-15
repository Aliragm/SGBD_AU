#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "funcs_dados.h"
#include "funcs_tabela.h"

int main(){
    /*    * Função principal que executa o Sistema de Gerenciamento de Banco de Dados (SGBD).
    
    A função exibe uma mensagem de boas-vindas e entra em um loop infinito, solicitando ao usuário que insira um comando para realizar uma ação específica.
    As ações possíveis incluem criar tabela, remover tabela, listar dados de uma tabela, pesquisar valor em uma tabela, listar tabelas, apagar registro, adicionar registro e sair do programa.
    Cada ação é representada por um caractere e o usuário é solicitado a inserir o caractere correspondente à ação desejada.
    A função então chama a função correspondente à ação escolhida pelo usuário.
    
    Variáveis:
    comando - Caractere para armazenar o comando inserido pelo usuário.
    */
    char comando;
    printf("Bem vindo, para utilizar o SGBD primeiro crie uma tabela.");
    while (1)
    {
        printf("\n\nDigite o que deseja fazer:\nCriar tabela = c\nRemover tabela = r\nListar Dados de uma tabela = l\nPesquisar valor em uma tabela = p\nListar tabelas = n\nApagar registro = a\nAdicionar registro = i\nSair do programa = s\n:");
        scanf("%c", &comando);
        switch (comando)
        {
        case 'c': criar_tabela(); getchar(); break;
        case 'r': apagar_tabela(); break;
        case 'l': listar_dados_tabelas(); break;
        case 'p': pesquisar_valor(); break;
        case 'n': lista_tabelas(); getchar(); break;
        case 'a': apagar_linha(); getchar(); break;
        case 'i': add_registro(); getchar(); break;
        case 's': return 0; break;
        default: printf("Comando %c nao e reconhecido...tente novamente.", comando); break;
        }
    }
    return 0;
}