#define tam 40

/*hash.h armazena a estrutura e os protótipos das funções*/
struct dados {
    int key;
    int info;
    struct dados*prox;
};

typedef struct dados Dados;
typedef Dados* Hash[tam];

int funcaoHash(int num);/**/
void inicializarHash(Hash tab); /**/
void inserirHash(Hash tab, int chave);
void buscarHash(Hash tab, int chave);
void imprimeHash(Hash tab);
void removerHash(Hash tab, int chave);
int quantidadeColisoes(Hash tab);
void imprimeColisao(Hash tab, int pos);