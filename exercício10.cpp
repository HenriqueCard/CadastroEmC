#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>//BIBLIOTECAS

int menu(int op);
void  cadastrar(struct uninter** varredor, int num, char nomeAluno[], char emailAluno[]);
void  cadastrados(struct uninter* varredor);
void buscar(uninter* RAIZ, int num);//CABEÇALHOS DAS FUNÇÕES

struct uninter {
	char nome[30];//ESTRUTURA HETEROGÊNEA DE DADOS
	char email[50];
	int RU;
	  struct uninter* direita,*esquerda;
}*RAIZ; 

int main()//FUNÇÃO PRINCIPAL
{
	int opcao=0,num,c;
	char nomeAluno[30];
	char emailAluno[50];//DECLARAÇÃO DE VARIÁVEIS

	   struct uninter* varredor;//CRIAÇÃO DE PONTEIRO
	varredor = ((uninter*)malloc(sizeof(uninter)));//ALOCAÇÃO DE MEMÓRIA
	
	while(1)//LAÇO DE REPETIÇÃO
	{
		opcao = menu(opcao);
		switch (opcao)//ESTRUTURA DE SELEÇÃO
		{
		case 1:

			printf("Digite o RU:\n");//IMPRESSÃO NA TELA
			scanf_s("%d", &num);//LEITURA DO DADO
			while((c=getchar())!='\n'&& c!= EOF){}//LIMPA BUFFER DE TECLADO
			printf("Digite o nome:\n");
			gets_s(nomeAluno);
			printf("Digite o email:\n");
			gets_s(emailAluno);
			cadastrar(&RAIZ, num, nomeAluno, emailAluno);//CHAMANDO A FUNÇÃO
			break;
		case 2:
			printf("ALUNOS CADASTRADOS:\n");//IMPRESSÃO NA TELA//
			cadastrados(RAIZ);//CHAMANDO A FUNÇÃO
			break;
		case 3:
			printf("Digite o RU do aluno que deseja buscar:\n");
			scanf_s("%d", &num);
			buscar(RAIZ, num);//CHAMANDO A FUNÇÃO
			printf("RU-> % d\nNome-> % s\nemail-> % s\n\n ", RAIZ->RU, RAIZ->nome, RAIZ->email);//IMPRESSÃO
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
int menu(int op)//FUNÇÃO MENU
{
	printf("1- Cadrastrar aluno:");
	printf("2- Mostrar todos os cadastros:");
	printf("3- Buscar aluno :");
	printf("4- Sair :");
	scanf_s("%d", &op);
	return op;
}
void  cadastrar(struct uninter**varredor, int num,char nomeAluno[],char emailAluno[])//FUNÇÃO 
{

	if (*varredor == NULL)//CONDIÇÃO
	{ 
		uninter* NovoElemento = NULL;//CRIAÇÃO E INICIALIZAÇÃO DO PONTEIRO
		NovoElemento = (uninter*)malloc(sizeof(uninter));//ALOCAÇÃO DE MEMÓRIA
		NovoElemento->esquerda = NULL;
		NovoElemento->direita = NULL;

		NovoElemento->RU = num;//TRANSFERÊNCIA DE DADO PARA MEMBRO DA STRUCT
		strcpy_s(NovoElemento->nome,nomeAluno);
		strcpy_s(NovoElemento->email, emailAluno);//TRANSFERINDO CONTEÚDO DE UMA STRING PARA OUTRA 
		*varredor = NovoElemento;
		return;
	}

	if (num < (*varredor)->RU)//CONDIÇÃO
	{
		cadastrar(&(*varredor)->esquerda, num, nomeAluno, emailAluno);
	}
	else
	{
		if (num > (*varredor)->RU)//CONDIÇÃO//
		{
			cadastrar(&(*varredor)->direita , num, nomeAluno, emailAluno);
		}
	}
}
void  cadastrados(struct uninter* varredor)//FUNÇAÕ
{
	if (varredor)//CONDIÇÃO
	{
		cadastrados(varredor->esquerda);
		printf("RU-> % d\nNome-> % s\nemail-> % s\n\n ", varredor->RU,varredor->nome,varredor->email);
		cadastrados(varredor->direita);
	}
}
void buscar(uninter*RAIZ,int num)//FUNÇÃO E PARÂMETROS
{
		if (RAIZ == NULL)//CONDIÇÃO
		{
			return ;
		}
		else if (num < (RAIZ->RU))//CONDIÇÃO
		{
			buscar(RAIZ->esquerda, num);
			
		}
		else if (num > (RAIZ->RU))//CONDIÇÃO
		{
			buscar(RAIZ->direita, num);
			
		}
		else if (num == (RAIZ->RU))//CONDIÇÃO
		{
			return ;

		}
		
}


