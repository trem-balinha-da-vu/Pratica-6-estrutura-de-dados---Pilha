#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

PilhaC * push(PilhaC *topo, char caractere)
{
	PilhaC *novo_topo = (PilhaC *) malloc(sizeof(PilhaC));
	
	novo_topo->caractere = caractere;
	novo_topo->prox = topo;
	
	return novo_topo;
}

void pop (PilhaC **topo)
{
	PilhaC *novo_topo = *topo;
	if(novo_topo == NULL) return;
	
	*topo = (*topo)->prox;
	
	free(novo_topo);
	
}

char caractere_correspondente(char ch) {
    switch (ch) {
        case '(': return ')';
        case ')': return '(';
        case '[': return ']';
        case ']': return '[';
        case '{': return '}';
        case '}': return '{';
        default: return '\0'; // Retorna '\0' se o caractere não for válido
    }
}

void recebe_entrada(char *vet)
{
	fflush(stdin);
	printf("Informe a sequencia de caracteres: \n");
	scanf("%[^\n]", vet);			
}

PilhaC * verifica_seq(char * vet, int tam_vet, PilhaC *topo)
{
	int i;
	for (i = tam_vet-1; i >=0; i--)
	{
		char correspondente = caractere_correspondente(vet[i]);
				
		if(topo == NULL)
		{
			topo = push(topo, vet[i]);
		} else
		{
			if(topo->caractere == correspondente)
			{
				pop(&topo);
				continue;
			} else 
			{
				topo = push(topo, vet[i]);
			}
		}
	}
	
	return topo;
}


int main()
{
	PilhaC * pilha = NULL;
		
	do
	{
		fflush(stdin);
		char vet[100] = "\0";
		recebe_entrada(vet);
		if(strcmp(vet, "\0") != 0)
		{
			pilha = verifica_seq(vet,strlen(vet), pilha);
			
			if(pilha == NULL) printf("\n Sim.\n");
			else printf("\nNao.\n");
		}else
		{
			break;
		}
	} while(1);
	
	return 0;
}
