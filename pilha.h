#ifndef PILHA_H
#define PILHA_H

typedef struct pilha {
	int info;
	struct pilha *prox;
} Pilha;

typedef struct pilha2 {
	char caractere;
	struct pilha2 * prox;
} PilhaC;

#endif 
