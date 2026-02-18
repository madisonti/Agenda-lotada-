
// Projeto Desenv


#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define MAX 5  // Limite de clientes

typedef struct endereco {
    char rua[30];
    char num[9];
    char complemento[20];
} ENDERECO;

typedef struct cliente {
    char nome[20];
    char telefone[12];
    ENDERECO edr;
} CLIENTE;

void cabecalho() {
    system("cls");  // Limpa tela no Windows
    printf("_______________________________________________\n");
    printf("AGENDA ELETRÔNICA \n");
    printf("_______________________________________________\n\n");
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    
    int opcao;
    CLIENTE clt;
    
    do {
        cabecalho();
        printf("1 - Cadastrar Novo Cliente\n");
        printf("2 - Mostrar Todos os Clientes\n");
        printf("3 - Encerrar\n");
        printf("Escolha a opção desejada: ");
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer do \n deixado pelo scanf
        
        switch(opcao) {
            case 1: {
                FILE *arquivo = fopen("AgendaClt.txt", "ab");
                if (!arquivo) {
                    printf("Problema na abertura do arquivo!\n");
                    system("pause");
                    break;
                }
                
                // Contar quantos clientes já existem
                fseek(arquivo, 0, SEEK_END);
                int totalClientes = ftell(arquivo) / sizeof(CLIENTE);
                if (totalClientes >= MAX) {
                    printf("Agenda cheia! Não é possível cadastrar mais clientes.\n");
                    fclose(arquivo);
                    system("pause");
                    break;
                }
                
                printf("Digite o nome do cliente: ");
                fgets(clt.nome, sizeof(clt.nome), stdin);
                clt.nome[strcspn(clt.nome, "\n")] = '\0'; // Remove o \n
                
                printf("Digite a rua: ");
                fgets(clt.edr.rua, sizeof(clt.edr.rua), stdin);
                clt.edr.rua[strcspn(clt.edr.rua, "\n")] = '\0';
                
                printf("Digite o número: ");
                fgets(clt.edr.num, sizeof(clt.edr.num), stdin);
                clt.edr.num[strcspn(clt.edr.num, "\n")] = '\0';
                
                printf("Digite o complemento: ");
                fgets(clt.edr.complemento, sizeof(clt.edr.complemento), stdin);
                clt.edr.complemento[strcspn(clt.edr.complemento, "\n")] = '\0';
                
                printf("Digite o telefone: ");
                fgets(clt.telefone, sizeof(clt.telefone), stdin);
                clt.telefone[strcspn(clt.telefone, "\n")] = '\0';
                
                fwrite(&clt, sizeof(CLIENTE), 1, arquivo);
                printf("Cliente cadastrado com sucesso!\n");
                
                fclose(arquivo);
                system("pause");
                break;
            }
            
            case 2: {
                FILE *arquivo = fopen("AgendaClt.txt", "rb");
                if (!arquivo) {
                    printf("Problema na abertura do arquivo!\n");
                    system("pause");
                    break;
                }
                
                fseek(arquivo, 0, SEEK_END);
                int totalClientes = ftell(arquivo) / sizeof(CLIENTE);
                rewind(arquivo);
                
                if (totalClientes == 0) {
                    printf("Agenda vazia!\n");
                    fclose(arquivo);
                    system("pause");
                    break;
                }
                
                cabecalho();
                while(fread(&clt, sizeof(CLIENTE), 1, arquivo) == 1) {
                    printf("Nome: %s\n", clt.nome);
                    printf("Telefone: %s\n", clt.telefone);
                    printf("Endereço: Rua %s, Nº %s, %s\n", clt.edr.rua, clt.edr.num, clt.edr.complemento);
                    printf("_______________________________________________\n\n");
                }
                
                fclose(arquivo);
                system("pause");
                break;
            }
            
            case 3:
                printf("Encerrando... Até a próxima!\n");
                break;
            
            default:
                printf("Opção inválida! Escolha uma opção válida.\n");
                system("pause");
                break;
        }
        
    } while(opcao != 3);
    
    return 0;
}
