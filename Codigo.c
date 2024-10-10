#include <stdio.h>
#include <string.h>

#define MAX_PRODUTOS 10

typedef struct {
    char nome[50];
    float preco;
} Produto;

void cat(int *a)
{
    printf("\n--Catalogo--");
    printf("\n--1|Cestas Basicas--");
    printf("\n--2|Produtos Higienicos--");
    printf("\n--3|Alimentos--");
    printf("\n--4|Bebidas--");
    printf("\n--5|Produtos de Limpeza--");
    printf("\nDigite a opcao: \n");
    scanf("%d", a);
}

void menuCestas(int *a)
{
    printf("\n--Cestas Basicas--");
    printf("\n--1|Mostrar Cestas--");
    printf("\n--2|Escolher Cesta--");
    printf("\n--Digite a opcao: ");
    scanf("%d", a);
}

void mostrarCestas()
{
    printf("\n--Cestas Disponiveis--\n");
    printf("1. Cesta Básica Simples - R$ 50.00\n");
    printf("2. Cesta Básica Intermediária - R$ 80.00\n");
    printf("3. Cesta Básica Completa - R$ 120.00\n");
}

void escolherCesta(int escolha, Produto carrinho[], int *quantidade)
{
    if (*quantidade >= MAX_PRODUTOS) {
        printf("Carrinho cheio! Não é possível adicionar mais itens.\n");
        return;
    }

    switch (escolha)
    {
        case 1:
            strcpy(carrinho[*quantidade].nome, "Cesta Básica Simples");
            carrinho[*quantidade].preco = 50.00;
            (*quantidade)++;
            printf("Cesta Básica Simples adicionada ao carrinho.\n");
            break;
        case 2:
            strcpy(carrinho[*quantidade].nome, "Cesta Básica Intermediária");
            carrinho[*quantidade].preco = 80.00;
            (*quantidade)++;
            printf("Cesta Básica Intermediária adicionada ao carrinho.\n");
            break;
        case 3:
            strcpy(carrinho[*quantidade].nome, "Cesta Básica Completa");
            carrinho[*quantidade].preco = 120.00;
            (*quantidade)++;
            printf("Cesta Básica Completa adicionada ao carrinho.\n");
            break;
        default:
            printf("Opção inválida!\n");
    }
}

void mostrarCarrinho(Produto carrinho[], int quantidade)
{
    if (quantidade == 0) {
        printf("Carrinho vazio!\n");
        return;
    }
    
    printf("\n--Carrinho--\n");
    for (int i = 0; i < quantidade; i++) {
        printf("%d. %s - R$ %.2f\n", i + 1, carrinho[i].nome, carrinho[i].preco);
    }
}

void removerProduto(Produto carrinho[], int *quantidade)
{
    if (*quantidade == 0) {
        printf("Carrinho vazio! Não há produtos para remover.\n");
        return;
    }

    int remover;
    mostrarCarrinho(carrinho, *quantidade);
    printf("Digite o número do produto que deseja remover: ");
    scanf("%d", &remover);

    if (remover < 1 || remover > *quantidade) {
        printf("Opção inválida!\n");
        return;
    }

    for (int i = remover - 1; i < *quantidade - 1; i++) {
        carrinho[i] = carrinho[i + 1];
    }
    (*quantidade)--;
    printf("Produto removido com sucesso!\n");
}

void pagar(Produto carrinho[], int *quantidade, float *dinheiro)
{
    if (*quantidade == 0) {
        printf("Carrinho vazio! Não há produtos para pagar.\n");
        return;
    }

    float total = 0;
    for (int i = 0; i < *quantidade; i++) {
        total += carrinho[i].preco;
    }

    printf("Total a pagar: R$ %.2f\n", total);

    if (*dinheiro >= total) {
        *dinheiro -= total;
        *quantidade = 0;
        printf("Compra realizada com sucesso! Saldo restante: R$ %.2f\n", *dinheiro);
    } else {
        printf("Saldo insuficiente!\n");
    }
}

void menu(int *a)
{
    printf("\n--MENU--");
    printf("\n--1|Adicionar Money--");
    printf("\n--2|Ver Money--");
    printf("\n--3|Catalogo--");
    printf("\n--4|Carrinho--");
    printf("\n--5|Sair");
    printf("\n--Digite a opcao: ");
    scanf("%d", a);
}

int main(void)
{
    int opcao, dinheiro_opcao;
    float dinheiro = 0, temp;
    Produto carrinho[MAX_PRODUTOS];
    int quantidade = 0; 

    do
    {
        menu(&opcao);  
        switch (opcao)
        {
            case 1:
                printf("Digite quanto voce quer adicionar: ");
                scanf("%f", &temp);
                dinheiro += temp;
                printf("Dinheiro atualizado: %.2f\n", dinheiro);
                break;
            case 2:
                printf("Valor atual: %.2f\n", dinheiro);
                break;
            case 3:
            {
                int cat_opcao;
                cat(&cat_opcao); 
                switch (cat_opcao)
                {
                    case 1:  
                    {
                        int cestas_opcao;
                        menuCestas(&cestas_opcao);
                        switch (cestas_opcao)
                        {
                            case 1:
                                mostrarCestas(); 
                                break;
                            case 2:
                            {
                                int escolha;
                                mostrarCestas(); 
                                printf("Digite o numero da cesta que voce quer escolher: ");
                                scanf("%d", &escolha);
                                escolherCesta(escolha, carrinho, &quantidade);
                                break;
                            }
                            default:
                                printf("Opcao de Cesta invalida!\n");
                        }
                        break;
                    }
                    case 2:  // Produtos Higienicos
                        printf("Produtos Higienicos ainda nao implementados.\n");
                        break;
                    case 3:  // Alimentos
                        printf("Alimentos ainda nao implementados.\n");
                        break;
                    case 4:  // Bebidas
                        printf("Bebidas ainda nao implementadas.\n");
                        break;
                    case 5:  // Produtos de Limpeza
                        printf("Produtos de Limpeza ainda nao implementados.\n");
                        break;
                    default:
                        printf("Opcao de catalogo invalida!\n");
                }
                break;
            }
            case 4:
            {
                int carrinho_opcao;
                printf("\n--Carrinho--");
                printf("\n1. Ver carrinho");
                printf("\n2. Remover produto");
                printf("\n3. Pagar");
                printf("\nDigite a opcao: ");
                scanf("%d", &carrinho_opcao);

                switch (carrinho_opcao)
                {
                    case 1:
                        mostrarCarrinho(carrinho, quantidade);
                        break;
                    case 2:
                        removerProduto(carrinho, &quantidade);
                        break;
                    case 3:
                        pagar(carrinho, &quantidade, &dinheiro);
                        break;
                    default:
                        printf("Opcao de carrinho invalida!\n");
                }
                break;
            }
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 5);
}
