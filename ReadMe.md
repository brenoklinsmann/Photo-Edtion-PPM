#Projeto Processador de Imagens PPM 
	Disciplina: ITP/PTP

#Descrição
	O Processador se referiu ao trabalho de conclusão das disciplinas de ITP(Introdução as Técnicas de Programação) e PTP (Prática de 		 	 Técnicas de Programação), onde tivemos que criar um processador e editor de imagens do tipo ppm que fazia a leitura de uma imagem .ppm e 		criava uma cópia da imagem original e aplicava um filtro escolhido pelo usuário na execução do programa.

#PARA COMPILAR
	Primeiro coloque os arquivos funcoes.h, variaveis.h, filtros.h, main.c e a imagem que se deseja manipular na mesma pasta
	Depois use gcc main.c -o "nome do executavel que desejar"
	Em seguida escolha a opção 0 -> para entrar no editor ou 1 -> para decodificar uma imagem ( caso já tenha codificado alguma )
	Se escolheu a opção 0 então o menu com os filtros apareceram e você deverar escolher o filtro que deseja e digitar as suas iniciais como 	 indicado no próprio menu.
		Ex: usou a imagem lena.ppm e esclolheu a opção 1 e quer o filtro de blurring então digitará blu.
	Após isso será criado uma nova imagem, na mesma pasta, com o efeito aplicado. O nome da imagem sairá com o acréscimo de 	-"Nome_do_Filtro". 
	

#Autores
	Breno Klinsmann Medeiros
	Thiago César M. D. de Lucena
