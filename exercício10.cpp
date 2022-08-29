#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>//BIBLIOTECAS

int menu(int op);
void  cadastrar(struct uninter** varredor, int num, char nomeAluno[], char emailAluno[]);
void  cadastrados(struct uninter* varredor);
void buscar(uninter* RAIZ, int num);//CABE�ALHOS DAS FUN��ES

struct uninter {
	char nome[30];//ESTRUTURA HETEROG�NEA DE DADOS
	char email[50];
	int RU;
	  struct uninter* direita,*esquerda;
}*RAIZ; 

int main()//FUN��O PRINCIPAL
{
	int opcao=0,num,c;
	char nomeAluno[30];
	char emailAluno[50];//DECLARA��O DE VARI�VEIS

	   struct uninter* varredor;//CRIA��O DE PONTEIRO
	varredor = ((uninter*)malloc(sizeof(uninter)));//ALOCA��O DE MEM�RIA
	
	while(1)//LA�O DE REPETI��O
	{
		opcao = menu(opcao);
		switch (opcao)//ESTRUTURA DE SELE��O
		{
		case 1:

			printf("Digite o RU:\n");//IMPRESS�O NA TELA
			scanf_s("%d", &num);//LEITURA DO DADO
			while((c=getchar())!='\n'&& c!= EOF){}//LIMPA BUFFER DE TECLADO
			printf("Digite o nome:\n");
			gets_s(nomeAluno);
			printf("Digite o email:\n");
			gets_s(emailAluno);
			cadastrar(&RAIZ, num, nomeAluno, emailAluno);//CHAMANDO A FUN��O
			break;
		case 2:
			printf("ALUNOS CADASTRADOS:\n");//IMPRESS�O NA TELA//
			cadastrados(RAIZ);//CHAMANDO A FUN��O
			break;
		case 3:
			printf("Digite o RU do aluno que deseja buscar:\n");
			scanf_s("%d", &num);
			buscar(RAIZ, num);//CHAMANDO A FUN��O
			printf("RU-> % d\nNome-> % s\nemail-> % s\n\n ", RAIZ->RU, RAIZ->nome, RAIZ->email);//IMPRESS�O
			break;
		case 4:
			return 0;
			break;
		default:
			break;
		}

	}

	system("pause");//PAUSA A TELA
	return 0;
}
int menu(int op)//FUN��O MENU
{
	printf("1- Cadrastrar aluno:");
	printf("2- Mostrar todos os cadastros:");
	printf("3- Buscar aluno :");
	printf("4- Sair :");
	scanf_s("%d", &op);
	return op;
}
void  cadastrar(struct uninter**varredor, int num,char nomeAluno[],char emailAluno[])//FUN��O 
{

	if (*varredor == NULL)//CONDI��O
	{ 
		uninter* NovoElemento = NULL;//CRIA��O E INICIALIZA��O DO PONTEIRO
		NovoElemento = (uninter*)malloc(sizeof(uninter));//ALOCA��O DE MEM�RIA
		NovoElemento->esquerda = NULL;
		NovoElemento->direita = NULL;

		NovoElemento->RU = num;//TRANSFER�NCIA DE DADO PARA MEMBRO DA STRUCT
		strcpy_s(NovoElemento->nome,nomeAluno);
		strcpy_s(NovoElemento->email, emailAluno);//TRANSFERINDO CONTE�DO DE UMA STRING PARA OUTRA 
		*varredor = NovoElemento;
		return;
	}

	if (num < (*varredor)->RU)//CONDI��O
	{
		cadastrar(&(*varredor)->esquerda, num, nomeAluno, emailAluno);
	}
	else
	{
		if (num > (*varredor)->RU)//CONDI��O//
		{
			cadastrar(&(*varredor)->direita , num, nomeAluno, emailAluno);
		}
	}
}
void  cadastrados(struct uninter* varredor)//FUN�A�
{
	if (varredor)//CONDI��O
	{
		cadastrados(varredor->esquerda);
		printf("RU-> % d\nNome-> % s\nemail-> % s\n\n ", varredor->RU,varredor->nome,varredor->email);
		cadastrados(varredor->direita);
	}
}
void buscar(uninter*RAIZ,int num)//FUN��O E PAR�METROS
{
		if (RAIZ == NULL)//CONDI��O
		{
			return ;
		}
		else if (num < (RAIZ->RU))//CONDI��O
		{
			buscar(RAIZ->esquerda, num);
			
		}
		else if (num > (RAIZ->RU))//CONDI��O
		{
			buscar(RAIZ->direita, num);
			
		}
		else if (num == (RAIZ->RU))//CONDI��O
		{
			return ;

		}
		
}


