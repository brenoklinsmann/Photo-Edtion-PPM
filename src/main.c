/** @file main.c
	Include da biblioteca local implementada 'funcoes.h'. Nessa biblioteca estao todos os includes necessarios para a execucao do programa.
*/
#include "funcoes.h"

int main(){
	system("clear");
	printf("|--------------------Processador de Imagens PPM--------------------|\n\n");
	while(1){
		printf("****************** MENU ******************\n");
		printf("0 - Utilizar processador de imagens.\n");
		printf("1 - Decodificar arquivo RLE.\n");
		printf("******************************************\n");
		printf("Informe a opção desejada: \n");
		scanf("%i", &opcao_inicial);
		if (opcao_inicial != 0 && opcao_inicial != 1){
			printf("Opção inválida. Por favor, tente novamente.\n\n");
		} else {
			break;
		}
	}
	/**
		Caso o usuario escolha a opcao 1, ele será direcionado para a funcao de decodificacao de imagens, contida no arquivo 'filtros.h'. Caso escolha a opcao 0, sera pedido que digite a imagem que se deseja processar. O programa entao abre o canal de comunicacao com o arquivo e checa se o arquivo realmente existe. Caso nao exista, pede-se que o usuario digite um arquivo valido.
	*/
	if (opcao_inicial == 1){
		decodingRLE();
	} else if(opcao_inicial == 0){
		FILE *arquivo_ppm;
		while (1) {
			printf("\nDigite o nome da imagem a ser modificada (com extensão): \n");
			scanf("%s", nome);
			arquivo_ppm = fopen(nome, "r");
			if (arquivo_ppm == NULL){
				printf("Erro ao abrir imagem, por favor tente novamente.\n\n");
			} else {
				break;
			}
			
		}
		///Variavel tamanho que armazena a quantidade de caracteres do nome do arquivo.
		tamanho = strlen(nome);
		///Leitura do identificador ppm e da largura, altura e qualidade da imagem.
		fscanf(arquivo_ppm, "%s %i %i %i", id_ppm, &largura, &altura, &qualidade);
		/**
			Condicional para verificar qual das dimensões da imagem e maior. Essa checagem e necessaria para se trabalhar com imagens nao-quadradas em filtros como o de rotacionar, no qual a matriz do tipo 'pixels' que vai armazenar a imagem tera que ser quadrada e com dimensao igual a maior dimensao da imagem. Caso contrario, a operacao de rotacao nao funcionara.
		*/
		if (largura >= altura){
			dimensao = largura;
		} else {
			dimensao = altura;
		}
		pixels imagem[dimensao][dimensao];
		/// For para ler os valores R, G e B de cada pixel da imagem.
		for (i = 0; i < altura; ++i){
			for (j = 0; j < largura; ++j){
				fscanf(arquivo_ppm, "%i %i %i", &(imagem[i][j].R), &(imagem[i][j].G), &(imagem[i][j].B));
			}
		}
		fclose(arquivo_ppm);
		///Redirecionamento para a funcao que vai receber a escolha de filtro do usuario, contida no arquivo 'funcoes.h'.
		escolherFiltros(imagem);
	}
	return 0;
}