/** @file funcoes.h

	Includes necessarios para compilar o programa. Biblioteca padrão de entrada e saída, biblioteca com funções para manipulação de cadeias de caracteres, a biblioteca 'variaveis.h' que contem as variaveis do programa, e a biblioteca local implementada 'filtros.h' que contem as funcoes utilizadas para mostrar e escolher os filtros de manipulacao da imagem.
*/
#include <stdio.h>
#include <string.h>
#include "variaveis.h"
#include "filtros.h"

void mostrarMenu(){
	printf("\n************************* Filtros ***********************\n\n");
	printf("'thr': thresholding\n");
	printf("‘blu': blurring\n");
	printf("'sha': sharpening\n");
	printf("'rot': rotacionar imagem\n");
	printf("'amp': ampliar imagem (Digite a quantidade de zoom)\n");
	printf("'red': reduzir imagem (Digite a quantidade de zoom)\n");
	printf("'neg': filtro negativo\n");
	printf("'esp': filtro espelhar\n");
	printf("'bor': detecção de bordas\n");
	printf("'rle': codificar arquivo de imagem utilizando RLE\n");
	printf("'sair': sair do programa\n");
	printf("\n********************************************************\n");
	printf("Digite um filtro para transformar a imagem digitada:\n");
}
void escolherFiltros(pixels imagem[altura][largura]){
	mostrarMenu();
	scanf("%s", opcao);
	/**
		Estrutura condicional para ler o filtro desejado pelo usuario, possuindo opcao de sair do programa e tratamento de opcao invalida. Compara-se a entrada do usuario com uma da opcoes dadas no menu atraves da funcao 'strcmp' da biblioteca 'string.h' e, caso a entrada represente uma opcao valida, o usuario e redirecionado para a respectiva funcao. Todas as funcoes estao na biblioteca 'filtros.h'.
	*/
	if ((strcmp(opcao,"thr")) == 0){
		filtroThresholding(imagem);
		
	} else if ((strcmp(opcao,"blu")) == 0){
		filtroBlurring(imagem); 
		
	} else if ((strcmp(opcao,"sha")) == 0){
		filtroSharpening(imagem); 
		
	} else if ((strcmp(opcao,"rot")) == 0){
		filtroRotacionar(imagem); 
		
	} else if ((strcmp(opcao,"amp")) == 0){
		filtroAmpliar(imagem);
		
	} else if ((strcmp(opcao,"red")) == 0){
		filtroReduzir(imagem);
		
	} else if ((strcmp(opcao,"neg")) == 0){
		filtroNegativo(imagem); 
		
	} else if ((strcmp(opcao,"esp")) == 0){
		filtroEspelhar(imagem); 

	} else if ((strcmp(opcao,"bor")) == 0){
		filtroBorda(imagem); 	
	
	} else if ((strcmp(opcao,"rle")) == 0){
		encodingRLE(); 	

	} else if ((strcmp(opcao,"sair")) == 0){
		printf("Até a próxima!\n");

	} else {
		system("clear");
		printf("Opção inválida. Tente novamente.\n");
		/**
			Caso o usuario tenha digitado uma opcao invalida, o programa informa a situacao na tela e chama a propria funcao para que um filtro valido seja escolhido.
		*/
		escolherFiltros(imagem);
	}
}