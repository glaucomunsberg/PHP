#include <stdio.h>
#include <stdlib.h>
#include "las.h"


void imprimir(struct desc_lista *descritor);
void menu(struct desc_lista *descritor);
int main(int argc, char **argv)
{
	//----Identificadores & Atribuições----
	int escolha;
	int chave;
	int retorno;
	unsigned int posicao;
	desc_lista descritor;
	descritor.position = 0;
	//-------------------------------------
	
	for(;;)
	{
		printf("Lista de Alocação Seguencial\n1.Insert\n2.get\n3.set\n4.Delete\n5.Locate\n6.Imprimir\n0.Sair\nESCOLHA:");
		do
		{
			scanf("%d",&escolha);
		}while( escolha < 0 && escolha >6);
		
		switch(escolha)
		{
			case 0: printf("Saindo do programa");
					exit(0);
					break;
			case 1:
					system("clear");
					printf("Lista de Alocação Seguencial - INSERT\nPosição:\n");
					scanf("%d", &posicao);
					printf("Valor\n");
					chave = 1;
					retorno  = insert( posicao, chave, &descritor);
					if( retorno == 1)
					{
						printf("O valor foi inserido com sucesso.");
					}
					else
					{
						printf("O valor %d não pode ser inserido na posição %d", chave, posicao);
					}
					break;
			case 2: printf("Get\n");
					break;
			case 3: printf("Set\n");
					break;
			case 4: printf("Delete\n");
					break;
			case 5: printf("Locate\n");
					break;
			case 6: imprimir(&descritor);
					break;
			default: printf("Ooops! Você não deveria estar aqui!"); exit(0);
		}
		
	}
	printf("...Fim\n");
	return 0;
}

void imprimir(struct desc_lista *descritor)
{
	system("clear");
	printf("Lista de Alocação Seguencial - IMPRIMIR\n");
	int i;
	if(descritor->position != 0)
	{
		printf("Vetor: [");
		for(i=0; i<descritor->position;i++)
		{
			if(i+1 != descritor->position)
			{
				printf("%d,", descritor->vet[i]);
			}
			else
			{
				printf("%d", descritor->vet[i]);
			}
		}
		printf("]\n");
	}
	else
	{
		printf("Vetor: [NULL]\n");
	}
	
}
