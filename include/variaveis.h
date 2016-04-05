/** @file variaveis.h

	O registro 'pixels' contem as variaveis do tipo inteiro R, G e B, que vao armazenar, respectivamente, o nivel de vermelho, verde e azul de cada pixel. Alem disso, 'pixels' foi definido atraves do typedef para facilitar a declaracao de registros desse tipo.

*/
typedef struct {
	int R;
	int G;
	int B;
} pixels;
/** 
	Aqui esta declarada a maioria das variaveis utilizadas pelas diversas funcoes do programa. Em geral, sao variaveis utilizadas mais de uma vez em funcoes diferentes.
*/
char opcao[4], id_ppm[2], nome[50];
int  opcao_inicial, largura, altura, qualidade, tamanho, zoom, dimensao, media_rgb;;
int i, j, k, l, R, G, B, r, g, b;