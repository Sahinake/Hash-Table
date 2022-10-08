#define tam 20

/*hash.h armazena a estrutura e os protótipos das funções*/
struct dados {
    int key;
    char *info;
    struct dados*prox;
};

typedef struct dados Dados;
typedef Dados* Hash[tam];

int funcaoHash(int chave);/**/
void inicializarHash(Hash tab); /**/
void inserirHash(Hash tab, int chave, char* valor);
void buscarHash(Hash tab, int chave);
void imprimeHash(Hash tab);
void removerHash(Hash tab, int chave);
int quantidadeColisoes(Hash tab);
void imprimeColisao(Hash tab, int pos);