#Projeto Processador de Imagens PPM 
	Disciplina: ITP/PTP

#Descri��o
	O Processador se referiu ao trabalho de conclus�o das disciplinas de ITP(Introdu��o as T�cnicas de Programa��o) e PTP (Pr�tica de 		 	 T�cnicas de Programa��o), onde tivemos que criar um processador e editor de imagens do tipo ppm que fazia a leitura de uma imagem .ppm e 		criava uma c�pia da imagem original e aplicava um filtro escolhido pelo usu�rio na execu��o do programa.

#PARA COMPILAR
	Primeiro coloque os arquivos funcoes.h, variaveis.h, filtros.h, main.c e a imagem que se deseja manipular na mesma pasta
	Depois use gcc main.c -o "nome do executavel que desejar"
	Em seguida escolha a op��o 0 -> para entrar no editor ou 1 -> para decodificar uma imagem ( caso j� tenha codificado alguma )
	Se escolheu a op��o 0 ent�o o menu com os filtros apareceram e voc� deverar escolher o filtro que deseja e digitar as suas iniciais como 	 indicado no pr�prio menu.
		Ex: usou a imagem lena.ppm e esclolheu a op��o 1 e quer o filtro de blurring ent�o digitar� blu.
	Ap�s isso ser� criado uma nova imagem, na mesma pasta, com o efeito aplicado. O nome da imagem sair� com o acr�scimo de 	-"Nome_do_Filtro". 
	

#Autores
	Breno Klinsmann Medeiros
	Thiago C�sar M. D. de Lucena
