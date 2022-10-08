# include <stdio.h>
# include <stdlib.h>
# include "hash.h"

/*
Algoritmo: Função Hash; 
Entrada: variável do tipo inteiro (num)
Função: Retorna o resto da divisão do valor dessa variável pelo tamanho da tabela
*/
int funcaoHash(int num) {
    return(num%tam);
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
void inserirHash(Hash tab, int chave) {
    int i = 0, indice = funcaoHash(chave);
    Dados* aux = tab[indice];
    
    // percorre a hash, se encontra o elemento, nada acontece!
    while(aux != NULL) {
        if(aux->key == chave) {
            break;
        }
        aux = aux->prox;
    }
    // se chegou ao fim da lista, cria um novo elemento e insere
    if(aux == NULL) {
        aux = (Dados*)malloc(sizeof(Dados));
        aux->key = chave;
        aux->prox = tab[indice];
        tab[indice] = aux;
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
        imprimeColisao(tab, indice);
    }
}

/*
Algoritmo: Imprimir Hash; 
Entrada: variável do tipo Hash (tab)
Função: Sua função é imprimir todos os elementos da variável.
*/
void imprimeHash(Hash tab) {
    int i = 0, cont = 0;
    printf("\n========================\n");
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
            imprimeColisao(tab,indice);

            if(tab[indice]->key == chave) {
                if(tab[indice]->prox != NULL) {
                    tab[indice]->key = tab[indice]->prox->key;
                    tab[indice]->prox = tab[indice]->prox->prox;
                    return;               
                }
            else {
                if(tab[indice]->key != chave) {
                    if(tab[indice]->prox == NULL) {
                        printf("\nRegistro não encontrado!");
                        return;
                    }
                    else {
                        Dados* ant = NULL;
                        Dados* aux = tab[indice]->prox;
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

    inserirHash(hash,40);
    imprimeHash(hash);
    inserirHash(hash,30);
    imprimeHash(hash);
    inserirHash(hash,70);
    imprimeHash(hash);
    inserirHash(hash,120);
    imprimeHash(hash);
    inserirHash(hash,56);
    imprimeHash(hash);
    inserirHash(hash,67);
    imprimeHash(hash);
    inserirHash(hash,2);
    imprimeHash(hash);

    removerHash(hash,rand()%70);
    removerHash(hash,70);
    imprimeHash(hash);

    return 0;
}

