/** 
@file filtros.h

	Na funcao de thresholding, e pedido que o usuario digite o valor base para fazer a binarizacao, que deve ser um valor entre 0 e 255. Em seguida, todos os pixels da imagem sao percorridos e alterados, de modo que e feita a media aritmetica dos valores de R, G e B do pixel e, caso essa media seja menor que o valor base informado, os valores de R, G e B recebem o valor 0. Caso contrario, ou seja, se a media  dos pixels for maior que o valor base, os valores de R, G e B recebem o valor 255. A funcao recebe como parametro a matriz do tipo 'pixels' que contem a imagem armazenada.
*/
void filtroThresholding(pixels imagem[altura][largura]){
	int valor_base;
	/*Cria-se um char para acrescentar ao nome do novo arquivo o filtro que foi utilizado. O 'for' servirá para zerar as posições que armazenam a cadeia de caracteres '.ppm' para logo apos seu término concatenar o nome da imagem com a extensão em questao (-thr.ppm). 
	*/
	char extensao[8] = "-thr.ppm";
	for (i = tamanho - 4; i < tamanho; i++){
		nome[i] = 0;
	}
	strcat(nome, extensao);
	printf("Qual o valor base para binarização:\n");
	scanf("%i", &valor_base);
	if (valor_base > 255 || valor_base < 0){
		printf("Valor base inválido! O valor precisa ser um número entre 0 e 255. Por favor, tente novamente.\n\n");
		//Caso o valor esteja fora do intervalo [0, 255], a função é chamada para que um novo valor seja escolhido.
		filtroThresholding(imagem);
	}
	for(i = 0; i < altura; i++){
		for(j = 0; j < largura; j++){
			media_rgb = imagem[i][j].R + imagem[i][j].G + imagem[i][j].B;
			if(media_rgb / 3 < valor_base){
				imagem[i][j].R = 0;
				imagem[i][j].G = 0;
				imagem[i][j].B = 0;
			}else{
				imagem[i][j].R = 255;
				imagem[i][j].G = 255;
				imagem[i][j].B = 255;
			}
		}
	}
	FILE *imagem_saida = fopen(nome, "w");
	//Escrevendo os valores dos pixels modificados no arquivo de saída.
	fprintf(imagem_saida, "%s\n%i %i\n %i\n", id_ppm, largura, altura, qualidade);
	for (i = 0; i < altura; i++){
		for (j = 0; j < largura; j++){
			fprintf(imagem_saida, "%i %i %i \n", imagem[i][j].R, imagem[i][j].G, imagem[i][j].B);
			if (j % 6 == 5){
 				fprintf(imagem_saida, "\n");
 			}
		}
	}
	fclose(imagem_saida);
	printf("Imagem processada com sucesso!\n");
}
/**
	Na funcao de blurring, os pixels da imagem que nao pertecem as bordas (superior, inferior, direita e esquerda) sao modificados de forma que soma-se os valores de mesma cor (R, G, B) do pixel em questao com o dos 8 pixels ao redor dele e divide-se esse valor por 9. Esse novo valor entao e atribuido ao pixel em questao e passa-se para o proximo pixel. Os pixels das bordas sao excluidos, uma vez que eles nao possuem 8 pixels ao seu redor. A funcao recebe como parametro a matriz do tipo 'pixels' que contem a imagem armazenada.
*/
void filtroBlurring(pixels imagem[altura][largura]){
	/*
		Cria-se um char para acrescentar ao nome do novo arquivo o filtro que foi utilizado. O 'for' servirá para zerar as posições que armazenam a cadeia de caracteres '.ppm' para logo após seu término concatenar o nome da imagem com a extensão em questao (-blu.ppm). 
	*/
	char extensao[8] = "-blu.ppm";
	for (i = tamanho - 4; i < tamanho; i++){
		nome[i] = 0;
	}
	strcat(nome, extensao);
	//Cria-se uma matriz auxiliar para facilitar as operações com os pixels da imagem.
	pixels imagem_aux[altura][largura];
	//A matrix auxiliar recebe todos os pixels da imagem recebida como entrada.
	for (i = 0; i < altura; i++){
		for (j = 0; j < largura; j++){
			imagem_aux[i][j] = imagem[i][j];
		}
	}
	/* 
		O for irá percorrer de 1 até altura - 1 para não utilizar os pixels das bordas superior e inferior.
	    O for irá percorrer de 1 até largura - 1 para não utilizar os pixels das bordas do lado esquerdo e direito.
	*/
	for (i = 1; i < altura -1; i++){
		for (j = 1; j < largura -1; j++){
			/* 
				Efetua-se a soma do valor do pixel com o dos pixels ao seu redor e realiza-se a média aritmética.
				O valor obtido com o cálculo realizado é atribuido à posicao correspondente da matriz auxiliar.
			*/
			imagem_aux[i][j].R = (imagem[i-1][j-1].R + imagem[i-1][j].R + imagem[i-1][j+1].R + imagem[i][j-1].R+imagem[i][j].R + imagem[i][j+1].R + imagem[i+1][j-1].R + imagem[i+1][j].R + imagem[i+1][j+1].R) / 9;

			imagem_aux[i][j].G = (imagem[i-1][j-1].G + imagem[i-1][j].G + imagem[i-1][j+1].G + imagem[i][j-1].G + imagem[i][j].G + imagem[i][j+1].G + imagem[i+1][j-1].G + imagem[i+1][j].G + imagem[i+1][j+1].G) / 9;

			imagem_aux[i][j].B = (imagem[i-1][j-1].B + imagem[i-1][j].B + imagem[i-1][j+1].B + imagem[i][j-1].B + imagem[i][j].B + imagem[i][j+1].B + imagem[i+1][j-1].B + imagem[i+1][j].B + imagem[i+1][j+1].B) / 9;

		}
	}
	FILE *imagem_saida = fopen(nome, "w");
	//Escrevendo os valores dos pixels modificados no arquivo de saída.
	fprintf(imagem_saida, "%s\n%i %i\n%i\n", id_ppm, largura, altura, qualidade);
	for (i = 0; i < altura; i++){
		for (j = 0; j < largura; j++){
			fprintf(imagem_saida, "%i %i %i ", imagem_aux[i][j].R, imagem_aux[i][j].G, imagem_aux[i][j].B);
			if (j % 6 == 5){
				fprintf(imagem_saida, "\n");
			}
		}
	}
	fclose(imagem_saida);
	printf("Imagem processada com sucesso!\n");
}
/**
	Na funcao de sharpening, os pixels da imagem que nao pertecem as bordas (superior, inferior, direita e esquerda) sao modificados de forma que os valores de mesma cor (R, G, B) do pixel em questao e multiplicado por 5 e desse novo valor sao subtraidos os valores de mesma cor dos pixels acima, abaixo, a esquerda e a direita do pixel em questao. Em seguida, e feita uma verificacao para checar se o novo valor esta dentro do intervalo [0, 255]. Caso o valor esteja abaixo de 0, a cor do pixel recebe 0, e caso esteja acima de 255, a cor do pixel recebe 255. Em seguida, passa-se para o proximo pixel. Os pixels das bordas sao excluidos, uma vez que eles nao possuem necessariamente pixels acima, abaixo, a esquerda e a direita. A funcao recebe como parametro a matriz do tipo 'pixels' que contem a imagem armazenada.

*/
void filtroSharpening(pixels imagem[altura][largura]){
	/*
		Cria-se um char para acrescentar ao nome do novo arquivo o filtro que foi utilizado. O 'for' servirá para zerar as posicoes que armazenam a cadeia de caracteres '.ppm' para logo apos seu termino concatenar o nome da imagem com a extensao em questao (-sha.ppm). 
	*/
	char extensao[8] = "-sha.ppm";
	for (i = tamanho - 4; i < tamanho; i++){
		nome[i] = 0;
	}
	strcat(nome, extensao);
	//Cria-se uma matriz auxiliar para facilitar as operações com os pixels da imagem.
	pixels imagem_aux[altura][largura];
	//A matrix auxiliar recebe todos os pixels da imagem recebida como entrada.
	for (i = 0; i < altura; i++){
		for (j = 0; j < largura; j++){
			imagem_aux[i][j] = imagem[i][j];
		}
	}
	FILE *imagem_saida = fopen(nome, "w");
	fprintf(imagem_saida, "%s\n%i %i\n%i\n", id_ppm, largura, altura, qualidade);
	for (i = 1; i < altura - 1; i++){
		for (j = 1; j < largura - 1; j++){
			//O pixel em questão recebe seu valor multiplicado por 5 subtraido dos valores dos pixel acima, abaixo, a esquerda e a direita.
			imagem_aux[i][j].R = 5 * (imagem[i][j].R) - imagem[i-1][j].R - imagem[i+1][j].R - imagem[i][j-1].R - imagem[i][j+1].R;
			imagem_aux[i][j].G = 5 * (imagem[i][j].G) - imagem[i-1][j].G - imagem[i+1][j].G - imagem[i][j-1].G - imagem[i][j+1].G;
			imagem_aux[i][j].B = 5 * (imagem[i][j].B) - imagem[i-1][j].B - imagem[i+1][j].B - imagem[i][j-1].B - imagem[i][j+1].B;
			//É feita entao a verificação dos valores para garantir que eles estejam dentro do intervalo [0, 255].
			if (imagem_aux[i][j].R < 0){
				imagem_aux[i][j].R = 0; 
			}
			if (imagem_aux[i][j].R > 255){
				imagem_aux[i][j].R = 255;
			}
			if (imagem_aux[i][j].G < 0){
				imagem_aux[i][j].G = 0; 
			}
			if (imagem_aux[i][j].G > 255){
				imagem_aux[i][j].G = 255;
			}
			if (imagem_aux[i][j].B < 0){
				imagem_aux[i][j].B = 0; 
			}
			if (imagem_aux[i][j].B > 255){
				imagem_aux[i][j].B = 255;
			}
		}
	}
	//Escrevendo os valores dos pixels modificados no arquivo de saída.
	for (i = 0; i < altura; i++){
		for (j = 0; j < largura; j++){
			fprintf(imagem_saida, "%i %i %i ", imagem_aux[i][j].R, imagem_aux[i][j].G, imagem_aux[i][j].B);
			if (j % 6 == 5){
				fprintf(imagem_saida, "\n");
			}
		}
	}
	fclose(imagem_saida);
	printf("Imagem processada com sucesso!\n");
}
/**
	Na funcao de rotacionar, a imagem recebida da entrada do usuario e armazenada em uma matriz quadrada de ordem 'dimensao', tal que dimensao e o maior valor entre a largura e a altura da imagem recebida. Isso ocorre porque, com imagens retangulares, e preciso que a matriz que armazena a imagem seja maior que a propria imagem, para que quando seja feita rotacao, a matriz que armazena a imagem possua espacos de memoria suficientes para guardar as posicoes dos pixel da imagem rotacionada.\n
	Primeiro, pede-se que o usuario digite o angulo de rotacao em graus. E feita uma verificacao para garantir que o angulo seja maior ou igual a 90º e que também seja múltiplo desse valor. Em seguida, a variavel 'rotacoes' recebe o valor do modulo da divisao por 4 do angulo dividido por 90, que sera exatamente o numero de rotacoes para a direita que a imagem ira passar. Se o numero de rotacoes for par, e escrito no arquivo de saida largura e altura, e caso contrario, sera escrito altura e largura. Isso vai garantir que, ao rotacionar imagens retangulares, a imagem de saida tenha as dimensoes certas no arquivo ppm.\n
	Logo apos essas verificacoes, a operacao de rotacao da imagem comeca. Os pixels da primeira linha da imagem original ordenados da esquerda para a direita serao os pixels da primeira coluna da imagem rotacionada ordenados de baixo para cima, e assim sucessivamente. Ou seja, a imagem sera rotacionada para a direita, e isso sera feito um numero 'rotacoes' de vezes.\n
	A funcao recebe como parametro a matriz do tipo 'pixels' que contem a imagem armazenada.
*/
void filtroRotacionar(pixels imagem[dimensao][dimensao]){
	int angulo, rotacoes, rot_aux;
	/*
		Cria-se um char para acrescentar ao nome do novo arquivo o filtro que foi utilizado. O 'for' sevira para zerar as posicoes que armazenam a cadeia de caracteres '.ppm' para logo apos seu termino concatenar o nome da imagem com a extensao em questao (-rot.ppm). 
	*/
	char extensao[8] = "-rot.ppm";
	for (i = tamanho - 4; i < tamanho; i++){
		nome[i] = 0;
	}
	strcat(nome, extensao);
	//Cria-se uma matriz auxiliar para facilitar as operacoes com os pixels da imagem.
	pixels imagem_aux[dimensao][dimensao];
	//A matrix auxiliar recebe todos os pixels da imagem recebida como entrada.
	for (i = 0; i < altura; i++){
		for (j = 0; j < largura; j++){
			imagem_aux[i][j] = imagem[i][j];
		}
	}
	//Verificacao do ângulo digitado pelo usuário.
	while (1) {
		printf("\nDigite o ângulo em graus para rotacionar para a esquerda (múltiplo de 90):\n");
		scanf("%i", &angulo);
		if (angulo >= 90 && angulo % 90  == 0){
			break;
		} else {
			printf("Número inválido. Tente novamente\n");
		}
	}
	//'rotacoes' recebe o número de rotações para a direita que serão necessárias (0, 1, 2, 3).
	rotacoes = (angulo / 90) % 4;
	FILE *imagem_saida = fopen(nome, "w");
	//Caso seja um número par de rotações, as coordenadas de largura e altura são impressas nessa mesma ordem no arquivo de saída.
	if (rotacoes % 2 == 0) {
		fprintf(imagem_saida, "%s\n%i %i\n%i\n", id_ppm, largura, altura, qualidade);
	} else {
	//Caso seja um número ímpar de rotações, as coordenadas de largura e altura são impressas na ordem contrária no arquivo de saída.
	//Isso garante que imagens retangulares possuam as dimensões corretas quando rotacionadas.
		fprintf(imagem_saida, "%s\n%i %i\n%i\n", id_ppm, altura, largura, qualidade);
	}
	for (i = 1; i <= rotacoes; i++){
		//A matriz auxiliar recebe os valores nas posições corretas para representar a rotação.
		for (j = 0; j < altura; j++){
			for (k = 0; k < largura; k++){
				imagem_aux[largura-1-k][j].R = imagem[j][k].R;
				imagem_aux[largura-1-k][j].G = imagem[j][k].G;
				imagem_aux[largura-1-k][j].B = imagem[j][k].B;
			}
		}
		//A matriz original que armazena a imagem recebe agora os pixels da imagem rotacionada.
		for (j = 0; j < largura; j++){
			for (k = 0; k < altura; k++){
				imagem[j][k].R = imagem_aux[j][k].R;
				imagem[j][k].G = imagem_aux[j][k].G;
				imagem[j][k].B = imagem_aux[j][k].B;
			}
		}
		//É feita uma troca de variáveis para que as variáveis 'largura' e 'altura' tenham seus valores corrijidos a cada rotação (essencial para imagens retangulares).
		rot_aux = largura;
		largura = altura;
		altura = rot_aux;
	}
	//Escrevendo os valores dos pixels modificados no arquivo de saída.
	for (i = 0; i < altura; i++){
		for (j = 0; j < largura; j++){
			fprintf(imagem_saida, "%i %i %i ", imagem_aux[i][j].R, imagem_aux[i][j].G, imagem_aux[i][j].B);
			if (j % 6 == 5){
				fprintf(imagem_saida, "\n");
			}
		}
	}
	fclose(imagem_saida);
	printf("Imagem processada com sucesso!\n");
}
/**
	A funcao ampliar recebe o nivel de zoom desejado pelo usuario, com limite igual a 10. Em seguida, imprime no arquivo de saida da imagem cada pixel da imagem original n vezes, tal que n e igual ao numero de zoom informado ao quadrado. Isso e feito com estruturas de repeticao 'for' aninhadas, sendo dois laços mais externos para percorrer as linhas da imagem e imprimi-las uma quantidade 'zoom' de vezes, e dois laços internos para percorrer as colunas e imprimi-las uma quantidade 'zoom' de vezes. A funcao recebe como parametro a matriz do tipo 'pixels' que contem a imagem armazenada.
*/
void filtroAmpliar(pixels imagem[altura][largura]){
	/*
		Cria-se um char para acrescentar ao nome do novo arquivo o filtro que foi utilizado. O 'for' servirá para zerar as posicões que armazenam a cadeia de caracteres '.ppm' para logo apos seu término concatenar o nome da imagem com a extensão em questão (-amp.ppm). 
	*/
	char extensao[8] = "-amp.ppm";
	for (i = tamanho - 4; i < tamanho; i++){
		nome[i] = 0;
	}
	strcat(nome, extensao);
	printf("\nDigite a quantidade de zoom desejada. (LIM = 10)\n");
	scanf("%i", &zoom);
	if(zoom > 10 || zoom < 1){
		printf("Quantidade de zoom inválida. Tente novamente.\n");
		filtroAmpliar(imagem);
	}
	FILE *imagem_saida = fopen(nome, "w");
	fprintf(imagem_saida, "%s\n%i %i\n%i\n", id_ppm, largura*zoom, altura*zoom, qualidade);
	for (i = 0; i < altura; i++){
		/*	
			Dois 'for' que servirão para acrescentar os pixels já existentes na quantidade de vezes indicada pelo usuário na mesma linha.
		*/
		for (k = 0; k < zoom; k++) {
			for (j = 0; j < largura; j++){
				/*
					Dois 'for' que servirão para acrescentar os pixels já existentes na quantidade de vezes indicada pelo usuário na mesma coluna.
				*/
				for (l = 0; l < zoom; l++) {
					fprintf(imagem_saida, "%i %i %i ", imagem[i][j].R, imagem[i][j].G, imagem[i][j].B);
					if (j % 6 == 5){
						fprintf(imagem_saida, "\n");
					}
				}
			}
		}
	}	
	fclose(imagem_saida);
	printf("Imagem processada com sucesso!\n");
}
/**
	A funcao reduzir recebe um nivel de zoom desejado pelo usuario. Esse nivel e um numero inteiro que deve dividir tanto o valor da altura quanto o valor da largura da imagem. Isso garante que a imagem possa ser dividida em rmatrizes quadradas de pixels de ordem igual ao número de zoom. De cada uma dessas regioes sera tirada a media dos valores de todos os pixel de acordo com cada uma das cores (R, G, B), e esse valor da média dividido pelo número de elementos que foram somados, que é exatamente o numero zoom elevado ao quadrado, sera apenas um pixel na imagem reduzida.\n
	Em outras palavras, a imagem original e dividida em quadrados de pixels e a média dos valores de cada quadrado sera um pixel da imagem reduzida.\n
	A funcao recebe como parametro a matriz do tipo 'pixels' que contem a imagem armazenada.
*/
void filtroReduzir(pixels imagem[altura][largura]){
	int mediaR, mediaG, mediaB;
	/*
		Cria-se um char para acrescentar ao nome do novo arquivo o filtro que foi utilizado. O 'for' servirá para zerar as posicões que armazenam a cadeia de caracteres '.ppm' para logo apos seu término concatenar o nome da imagem com a extensão em questão (-red.ppm). 
	*/
	char extensao[8] = "-red.ppm";
	for (i = tamanho - 4; i < tamanho; i++){
		nome[i] = 0;
	}
	strcat(nome, extensao);
	//O nível de redução desejado deve ser um número que divide tanto a altura quanto a largura da imagem, para que a dimensão da imagem reduzida possa funcionar corretamente.
	do {
		printf("\nDigite o nível de redução desejado:\n");
		scanf("%i", &zoom);
		if (largura % zoom != 0 || altura % zoom != 0) {
			printf("Opção inválida - o número de redução deve dividir tanto a altura (%i) quanto a largura (%i) da imagem. Tente novamente.\n", altura, largura);
		} else {
			break;
		}
	} while (1);
	FILE *imagem_saida = fopen(nome,"w");
	//Escreve na imagem de saída as dimensões apropriadas da imagem reduzida, com largura e altura divididas pelo zoom.
	fprintf(imagem_saida, "%s\n%i %i\n%i\n", id_ppm, largura/zoom, altura/zoom, qualidade);
	//As variáveis 'i' e 'j' são incrementadas um número zoom de vezes, para que os quadrados de pixels comecem a partir de um salto de zoom pixels.
	for (i = 0; i < altura; i+=zoom){
		for (j = 0; j < largura; j+=zoom){
			//As variáveis que armazenam a média de cada valor são zeradas em cada iteração.
			mediaR = 0;
			mediaG = 0;
			mediaB = 0;
			//Dois 'for' aninhados para somar os valores de cada pixel componente do quadrado de dimensão zoom² da imagem original, começando do pixel de posição [i, j].
			for (k = i; k < i+zoom; k++){
				for(l = j; l < j+zoom; l++){
					mediaR += imagem[k][l].R;
					mediaG += imagem[k][l].G;
					mediaB += imagem[k][l].B;
				}
			}
			//A média então é finalmente calculada, dividindo-se o valor da soma de cada cor pela quantidade de pixels que foi somada (que é exatamente zoom²).
			mediaR /= (zoom*zoom);
			mediaG /= (zoom*zoom);
			mediaB /= (zoom*zoom);
			//Escreve-se no arquivo de saída então o pixel que será a média dos pixels da matriz quadrada.
			fprintf(imagem_saida, "%i %i %i ", mediaR, mediaG, mediaB);
			if (j % (zoom * 6) == 0){
				fprintf(imagem_saida, "\n");
			}
		}		
	}
	fclose(imagem_saida);
	printf("Imagem processada com sucesso!\n");
}
/**
	A funcao de filtro negativo imprime no arquivo de saida o valor que falta para a cor (R, G, B) de cada pixel ser igual a 255. Em outras palavras, e 255 menos o valor e cada pixel. A funcao recebe como parametro a matriz do tipo 'pixels' que contem a imagem armazenada.
*/
void filtroNegativo(pixels imagem[altura][largura]){
	/*
		Cria-se um char para acrescentar ao nome do novo arquivo o filtro que foi utilizado. O 'for' servirá para zerar as posicões que armazenam a cadeia de caracteres '.ppm' para logo apos seu término concatenar o nome da imagem com a extensão em questão (-neg.ppm). 
	*/
	char extensao[8] = "-neg.ppm";
	for (i = tamanho - 4; i < tamanho; i++){
		nome[i] = 0;
	}
	strcat(nome, extensao);
	FILE *imagem_saida = fopen(nome, "w");
	//Escrevendo os valores dos pixels no arquivo de saída, modificados diretamente no 'printf'.
	fprintf(imagem_saida, "%s\n%i %i\n%i\n", id_ppm, largura, altura, qualidade);
	for (i = 0; i < altura; i++){
		for (j = 0; j < largura; j++){
			fprintf(imagem_saida, "%i %i %i ", 255 - imagem[i][j].R, 255 - imagem[i][j].G, 255 - imagem[i][j].B);
			if (j % 6 == 5){
				fprintf(imagem_saida, "\n");
			}
		}
	}
	fclose(imagem_saida);
	printf("Imagem processada com sucesso!\n");
}
/**
	A funcao espelhar usa uma matriz auxiliar para exibir as colunas de pixel da matriz original em ordem inversa, da direita para a esquerda. Ou seja, a ultima coluna de pixels da imagem de entrada sera a primera coluna da imagem espelhada, e assim sucessivamente. A funcao recebe como parametro a matriz do tipo 'pixels ' que contem a imagem armazenada.
*/
void filtroEspelhar(pixels imagem[altura][largura]){
	/*
		Cria-se um char para acrescentar ao nome do novo arquivo o filtro que foi utilizado. O 'for' servirá para zerar as posicões que armazenam a cadeia de caracteres '.ppm' para logo apos seu término concatenar o nome da imagem com a extensão em questão (-esp.ppm). 
	*/
	char extensao[8] = "-esp.ppm";
	for (i = tamanho - 4; i < tamanho; i++){
		nome[i] = 0;
	}
	strcat(nome,extensao);
	//Matriz auxiliar para armazenar as colunas da matriz original em ordem inversa.
	pixels imagem_aux[altura][largura];
	for (i = 0; i < altura; i++){
		for (j = 0; j < largura; j++){
			//Matriz auxiliar receberá a matriz original espelhada.
			imagem_aux[i][j].R = imagem[i][largura - 1 - j].R;
			imagem_aux[i][j].G = imagem[i][largura - 1 - j].G;
			imagem_aux[i][j].B = imagem[i][largura - 1 - j].B;
		} 
	}
	FILE *imagem_saida = fopen(nome,"w");
	//Escrevendo os valores dos pixels modificados no arquivo de saída.
	fprintf(imagem_saida, "%s\n%i %i\n%i\n", id_ppm, largura, altura, qualidade);
	for (i = 0; i < altura ; i++){
		for (j = 0; j <largura ; j++){
			fprintf(imagem_saida, "%i %i %i ", imagem_aux[i][j].R, imagem_aux[i][j].G, imagem_aux[i][j].B);
			if (j % 6 == 5){
				fprintf(imagem_saida, "\n");
			}
		}
	}
	fclose(imagem_saida);
	printf("Imagem processada com sucesso!\n");		
}
/**
	A funcao de deteccao de bordas usa uma matriz auxiliar para receber todos os pixels da imagem original e altera-los. Os pixels da imagem, excluindo-se os das bordas (superior, inferior, esquerda e direita) sao alterados de forma que o valor da cor (R, G, B) de cada pixel e multiplicado por 8 e subtraido dos valores correspondentes dos 8 pixels ao redor. Os pixels das bordas, que nao possuem 8 pixels ao redor, recebem seus valores todos iguais a 0. Em seguida, aplica-se a mesma operacao da funcao de thresholding (binarizacao) utilizando 127 como valor base. Caso o valor esteja abaixo de 0, a cor do pixel recebe 0, e caso esteja acima de 255, a cor do pixel recebe 255. A funcao recebe como parametro a matriz do tipo 'pixels ' que contem a imagem armazenada.
*/
void filtroBorda(pixels imagem[altura][largura]){
	/*
		Cria-se um char para acrescentar ao nome do novo arquivo o filtro que foi utilizado. O 'for' servirá para zerar as posicões que armazenam a cadeia de caracteres '.ppm' para logo apos seu término concatenar o nome da imagem com a extensão em questão (-bor.ppm). 
	*/
	char extensao[8] = "-bor.ppm";
	for (i = tamanho - 4; i < tamanho; i++){
		nome[i] = 0;
	}
	//Matriz auxiliar criada para armazenar os valores dos pixels e depois modificá-los.
	pixels imagem_aux[altura][largura];
	strcat(nome, extensao);
	//A matriz auxiliar recebe os pixels da imagem original.
	for (i = 0; i < altura; i++){
		for (j = 0; j < largura; j++){
			imagem_aux[i][j] = imagem[i][j];
		}
	}
	FILE *imagem_saida = fopen(nome, "w");
	fprintf(imagem_saida, "%s\n%i %i\n%i\n", id_ppm, largura, altura, qualidade);
	//Todos os pixels da matriz auxiliar recebem 0 para posteriormente alterar os valores dos pixels que não fazem parte das bordas.
	for (i = 0; i < altura; i++){
		for (j = 0; j < largura; j++){
			imagem_aux[i][j].R = 0;
			imagem_aux[i][j].G = 0;
			imagem_aux[i][j].B = 0;
		}
	}
	//Os pixels que não fazem parte da borda da imagem recebem o pixel de mesma posição da matriz que armazena a imagem original multiplicado por 8 e subtraido dos valores correspondentes dos 8 pixels ao seu redor.
	for (i = 1; i < altura - 1; i++){
		for (j = 1; j < largura - 1; j++){
			imagem_aux[i][j].R = 8 * (imagem[i][j].R) - (imagem[i-1][j-1].R + imagem[i-1][j].R + imagem[i-1][j+1].R + imagem[i][j-1].R + imagem[i][j+1].R + imagem[i+1][j-1].R + imagem[i+1][j].R + imagem[i+1][j+1].R);
			imagem_aux[i][j].G = 8 * (imagem[i][j].G) - (imagem[i-1][j-1].G + imagem[i-1][j].G + imagem[i-1][j+1].G + imagem[i][j-1].G + imagem[i][j+1].G + imagem[i+1][j-1].G + imagem[i+1][j].G + imagem[i+1][j+1].G);
			imagem_aux[i][j].B = 8 * (imagem[i][j].B) - (imagem[i-1][j-1].B + imagem[i-1][j].B + imagem[i-1][j+1].B + imagem[i][j-1].B + imagem[i][j+1].B + imagem[i+1][j-1].B + imagem[i+1][j].B + imagem[i+1][j+1].B);
			//É feita entao a verificação dos valores para garantir que eles estejam dentro do intervalo [0, 255].
			if (imagem_aux[i][j].R < 0){
				imagem_aux[i][j].R = 0; 
			}
			if (imagem_aux[i][j].R > 255){
				imagem_aux[i][j].R = 255;
			}
			if (imagem_aux[i][j].G < 0){
				imagem_aux[i][j].G = 0; 
			}
			if (imagem_aux[i][j].G > 255){
				imagem_aux[i][j].G = 255;
			}
			if (imagem_aux[i][j].B < 0){
				imagem_aux[i][j].B = 0; 
			}
			if (imagem_aux[i][j].B > 255){
				imagem_aux[i][j].B = 255;
			}
		}
	}
	//Aplicando a mesma operação utilizada no thresholding em todos os pixels da matriz auxiliar, utilizando 127 como valor base.
	for(i = 0; i < altura; i++){
		for(j = 0; j < largura; j++){
			media_rgb = imagem_aux[i][j].R + imagem_aux[i][j].G + imagem_aux[i][j].B;
			if(media_rgb / 3 < 127){
				imagem_aux[i][j].R = 0;
				imagem_aux[i][j].G = 0;
				imagem_aux[i][j].B = 0;
			} else {
				imagem_aux[i][j].R = 255;
				imagem_aux[i][j].G = 255;
				imagem_aux[i][j].B = 255;
			}
		}
	}
	//Escrevendo os valores dos pixels modificados no arquivo de saída.
	for (i = 0; i < altura; i++){
		for (j = 0; j < largura; j++){
			fprintf(imagem_saida, "%i %i %i ", imagem_aux[i][j].R, imagem_aux[i][j].G, imagem_aux[i][j].B);
			if (j % 6 == 5){
				fprintf(imagem_saida, "\n");
			}
		}
	}
	fclose(imagem_saida);
	printf("Imagem processada com sucesso!\n");
}
/**
	Codificação da imagem utilizando Run-Length Encoding (RLE). Na leitura da imagem entrada pelo usuario, apos a leitura do cabecalho, verifica-se quantas vezes cada pixel se repete sequencialmente na leitura na imagem. Esse numero de vezes e contado e escrito em um arquivo de saida .txt contendo o cabecalho da imagem original e quantas vezes cada pixel e repetido na sequencia, seguido pelos valores de cor (R, G, B) do respectivo pixel.
*/
void encodingRLE() {
	int contador = 1;
	/*
		Cria-se um char para acrescentar ao nome do novo arquivo a extensão de codificação '-rle.txt'. O 'for' sevira para zerar as posicoes que armazenam a cadeia de caracteres '.ppm' para logo apos seu termino concatenar o nome da imagem com a extensao em questao. 
	*/
	char extensao[8] = "-rle.txt";
	FILE *imagem_entrada = fopen(nome, "r");
	for (i = tamanho - 4; i < tamanho; i++){
		nome[i] = 0;
	}
	strcat(nome, extensao);
	//Canal de comunicação criado para gerar o arquivo de saida que receberá a codificação.
	FILE *arquivo_saida = fopen(nome, "w");
	//Leitura do cabeçalho da imagem e escrita dele no arquivo de saída.
	fscanf(imagem_entrada, "%s %i %i %i", id_ppm, &largura, &altura, &qualidade);
	fprintf(arquivo_saida, "%s\n%i %i\n%i\n", id_ppm, largura, altura, qualidade);
	/*
		Lê-se o primeiro pixel da imagem e armazena seus valores nas variáveis de teste R, G, e B. Em seguida, enquanto não chegar no fim da imagem, o programa realiza uma série de comandos:
		1. Lê o próximo pixel e verifica se ele é igual ao pixel armazenado.
		2. Em caso afirmativo, incrementa o contador daquele pixel e passa para a leitura do próximo pixel.
			2.1 Se ele leu o último pixel, escreve no arquivo de saída a quantidade de vezes que o pixel se repetiu juntamente com seu valor, sem incrementar o contador, e para o while.
		3. Em caso negativo, escreve no arquivo de saída quantas vezes o pixel se repetiu juntamente com seus valores de RGB (variáveis R, G e B), armazena os valores do pixel lido nas variáveis R, G e B, e zera o contador;
	*/
	fscanf(imagem_entrada, "%i %i %i", &R, &G, &B);
	while (!feof(imagem_entrada)){
		fscanf(imagem_entrada, "%i %i %i", &r, &g, &b);
		if (r == R && g == G && b == B){
			if (feof(imagem_entrada)){
				fprintf(arquivo_saida, "%i %i %i %i\n", contador, R, G, B);	
				break;
			}
			contador++;
		} else {
			fprintf(arquivo_saida, "%i %i %i %i\n", contador, R, G, B);
			R = r;
			G = g;
			B = b;
			contador = 1;
		}
	}
	fclose(imagem_entrada);
	fclose(arquivo_saida);
	printf("Imagem codificada com sucesso!\n");
}
/**
	Decodificacao de uma imagem previamente codificada com RLE pelo programa. A funcao le um arquivo com final '-rle.txt' que foi gerado anteriormente pelo programa e, apos ler seu cabecalho, faz a leitura de 4 valores. O primeiro valor representa o numero de vezes que o pixel representado pelos 3 valores em seguida se repete na sequencia da imagem. Entao, o pixel em questao e escrito essa quantidade de vezes no arquivo de saida e passa-se para a leitura dos proximos 4 valores. Ao final dessa operacao, sera gerada a imagem original que foi anteriormente codificada.
*/
void decodingRLE() {
	int contador, linhas = 0;
	char extensao[8] = ".ppm";
	FILE *arquivo_entrada;
	while (1) {
		printf("Digite o nome do arquivo com extensão '-rle.txt' a ser decodificado: \n");
		scanf("%s", nome);
		arquivo_entrada = fopen(nome, "r");
		if (arquivo_entrada == NULL){
			printf("Erro ao abrir arquivo, por favor tente novamente.\n\n");
		} else {
			break;
		}
		
	}
	//A extensão '-rle.txt' do nome do arquivo lido é apagada. Concatena-se então o nome do arquivo com '.ppm' para gerar uma imagem ppm no arquivo de imagem da saída.
	tamanho = strlen(nome);
	for (i = tamanho - 8; i < tamanho; i++){
		nome[i] = 0;
	}
	strcat(nome, extensao);
	FILE *imagem_saida = fopen(nome, "w");
	//Leitura do cabeçalho do arquivo de entrada e escrita desse cabeçalho na imagem de saída.
	fscanf(arquivo_entrada, "%s %i %i %i", id_ppm, &largura, &altura, &qualidade);
	fprintf(imagem_saida, "%s\n%i %i\n%i\n", id_ppm, largura, altura, qualidade);
	/*
		Enquanto não chegar no fim do arquivo, lê-se de 4 em 4 valores do arquivo de entrada. O primeiro valor representa a quantidade de vezes que o pixel, representado pelos 3 valores em seguida, será repetido. A quantidade de vezes é colocada dentro de uma estrutura de repetição para garantir que o pixel seja escrito corretamente na imagem de saída.
	*/
	while (!feof(arquivo_entrada)){
		fscanf(arquivo_entrada, "%i %i %i %i", &contador, &R, &G, &B);
		for (i = 1; i <= contador; i++){
			fprintf(imagem_saida, "%i %i %i ", R, G, B);
			linhas++;
			if (linhas % 6 == 0){
				fprintf(imagem_saida, "\n");
			}
		}
	}
	fclose(arquivo_entrada);
	fclose(imagem_saida);
	printf("Imagem decodificada com sucesso!\n");
}