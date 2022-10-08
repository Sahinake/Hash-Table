# include <stdio.h>
# include <stdlib.h>
# include "hash.h"

/*
Algoritmo: Função Hash; 
Entrada: variável do tipo inteiro (num)
Função: Retorna o resto da divisão do valor dessa variável pelo tamanho da tabela
*/
int funcaoHash(int chave) {
    return(chave%tam);
}

/*
Algoritmo: Inicializar Hash; 
Entrada: variável do tipo Hash (tab)
Função: Sua função é que todas as posições da tab se tornem nulas.
*/
 void inicializarHash(Hash tab) {
    int i;
    for (i = 0; i < tam; i++) {
        tab[i] = NULL;
    }
 }

/*
Algoritmo: Inserir Hash; 
Entrada: variável do tipo Hash (tab) e um inteiro (num);
Função: Sua função é inserir os elementos na tabela através da função Hash e caso esta posição já esteja 
preenchida, como colisão está sendo adotado neste procedimento o encadeamento direto.
*/
void inserirHash(Hash tab, int chave, char *valor) {
    int i = 0, indice = funcaoHash(chave);
    
    Dados* item = tab[indice];

    Dados* novoItem = (Dados*)malloc(sizeof(Dados));
    novoItem->key = chave;
    novoItem->info = valor;
    novoItem->prox = NULL;

    if(item == NULL) {
        tab[indice] = novoItem;
        return;
    }
    else {
        while(item != NULL) {
            if (item->key == chave) {
                printf("\nEsta chave já existe!");
                return;
            }
            if (item->prox == NULL) {
                item->prox = novoItem;
                return;
            }
            item = item->prox;
        }
    }
}

/*
Algoritmo: Imprime Colisão; 
Entrada: variável do tipo Hash (tab) e inteiro indice (pos);
Função: mostra uma posição e todas as suas colisões.
*/
void imprimeColisao(Hash tab, int pos) {
    Dados* aux = tab[pos];
    
    if(aux == NULL) {
        printf("Esta posição está vazia!\n");
        return;
    }
    else {
        printf("%3d", aux->key);
        while(aux->prox != NULL) {
            printf(" -> %d", aux->prox->key);
            aux = aux->prox;
            
        }
    }
}

/*
Algoritmo: Busca Hash; 
Entrada: variável do tipo Hash (tab) e inteiro (num);
Função: A variável tab tem como função passar a tabela e a variável num
tem como função determinar a posição da tabela que o usuário deseja visualizar.
*/
void buscarHash(Hash tab, int chave) {
    int indice = funcaoHash(chave);
    if(indice > tam || indice < 0) {
        printf("\nPosição não encontrada!");
        return;
    }
    else {
        Dados* aux = tab[indice];
        while(aux != NULL && aux->key != chave) {
            aux = aux->prox;
        }
        if(aux == NULL) {
            printf("\nChave não encontrada!");
            return;
        }
        else {
            printf("\nResultado da busca: %s", aux->info);
            printf("\n");
            return;
        }
    }
}

/*
Algoritmo: Imprimir Hash; 
Entrada: variável do tipo Hash (tab)
Função: Sua função é imprimir todos os elementos da variável.
*/
void imprimeHash(Hash tab) {
    int i = 0, cont = 0;
    printf("\n========================");
    for(i = 0; i < tam; i++) {
        if(tab[i] != NULL) {
            printf("\n %d", tab[i]->key);
            Dados* aux = tab[i]->prox;
            while(aux != NULL) {
                printf(" -> %3d", aux->key);
                aux = aux->prox;
            }
        }
    }
    printf("\n========================\n");
}

/*
Algoritmo: Remover Hash; 
Entrada: variável do tipo Hash (tab) e inteiro (num);
Função: A variável do tipo Hash serve para termos acesso à tabela, e a variável
do tipo inteiro serve para escolher a posição que o usário deseja visualizar. Após a 
visualização da chave, o usuário escolhe a keyrmação da chave que deseja eliminar.
*/
void removerHash(Hash tab, int chave) {
    int indice = funcaoHash(chave);
    
    // checa se o índice passado é válido
    if(indice > tam) {
        printf("\nEsta posição não existe na tabela!");
        return;
    }
    else {
        // checa se está vazio
        if(tab[indice] == NULL) {
            printf("Esta chave está vazia!");
            return;
        }
        else {
            printf("\n\n\n");
            printf("Colisão:"); imprimeColisao(tab,indice);

            Dados* aux = tab[indice];
            if(aux->key == chave) {
                if(aux->prox != NULL) {
                    aux->key = aux->prox->key;
                    aux->info = aux->prox->info;
                    aux->prox = aux->prox->prox;
                    return;               
                }
                else {
                    tab[indice] = NULL;
                    aux = NULL;
                    free(aux);
                    return;
                }
            }
            else {
                if(aux->key != chave) {
                    if(aux->prox == NULL) {
                        printf("\nRegistro não encontrado!");
                        return;
                    }
                    else {
                        Dados* ant = NULL;
                        aux = aux->prox;
                        while(aux->prox != NULL && aux->key != chave) {
                            ant = aux;
                            aux = aux->prox;
                        }
                        if(aux->key != chave) {
                            printf("\nRegistro não encontrado!");
                            return;
                        }
                        else {
                            if(ant == NULL) {
                                tab[indice]->prox = aux->prox;
                            }
                            else {
                                ant->prox = aux->prox;
                            }
                            aux = NULL;
                            free(aux);
                        }
                    }
                }
            }
        }
    }
}


/*
Algoritmo: Quantidade de Colisões; 
Entrada: variável do tipo Hash (tab);
Função: Retorna em variável do tipo inteiro, o total de colisões que ocorreram na tabela.
*/
int quantidadeColisoes(Hash tab) {
    int i, cont = 0;
    for(i = 0; i < tam; i++) {
        Dados* aux = tab[i];
        if(aux != NULL) {
            while(aux->prox != NULL) {
                cont++;
                aux = aux->prox;
            }
        }
    }
    return cont;

}


int main() {
    Hash hash;
    inicializarHash(hash);

    inserirHash(hash, 20, "All of Us Are Dead");
    inserirHash(hash, 2, "Bring it On Ghost");
    inserirHash(hash, 64, "Flower of Evil");
    inserirHash(hash, 45, "Healer");
    inserirHash(hash, 40, "A Business Proposal");
    inserirHash(hash, 23, "Crash Landing on You");
    inserirHash(hash, 86, "Hotel Del Luna");
    inserirHash(hash, 46, "Hot Young Bloods");
    inserirHash(hash, 13, "Playfull Kiss");
    inserirHash(hash, 27, "The Uncanny Counter");
    inserirHash(hash, 47, "Twenty-five, Twenty-one");

    imprimeHash(hash);

    removerHash(hash, 11);
    removerHash(hash, 13);
    removerHash(hash, 46);

    imprimeHash(hash);

    buscarHash(hash, 13);
    buscarHash(hash, 45);
    buscarHash(hash, 40);





    return 0;
}

