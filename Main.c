#include <stdio.h>
#include <stdlib.h>

typedef struct _node Node;

struct _node {

	char content;
	Node* prox;

};

typedef struct {

	int total;
	Node* first;

}Queue;

void initQueue(Queue* f) {
	f->total = 0;
	f->first = NULL;
}

int empty(Queue* f) {

	if(f->first == NULL) 
		return 1;
	else 
		return 0;
}

Node* aloc() {
	Node* new = malloc(sizeof(Node));
	if(!new){
		printf("Out of Memory\n");
	}else {
		return new;
	}
}

void insertQueue(Queue* f, char value){

	Node* new = aloc();
	new->prox = NULL;
	new->content = value;

	if(empty(f)){
		f->first = new;
	}
	else {

		Node* aux = f->first;

		while(aux->prox != NULL) {
			aux = aux->prox;
		}

		aux->prox = new;

	}

	f->total++;
}

char removeQueue(Queue* f){

	if(f->first == NULL) {
		printf("Empty Queue\n");
	} else {

		Node* aux = f->first;
		f->first = aux->prox;
		f->total--;
		return aux->content;

	}
}

void print(Queue* f){

	if(empty(f)){
		printf("Empty Queue\n");
	} else {
		printf("Fila: \n\n\n");
		Node* aux = f->first;

		while(aux != NULL) {
			printf("%c\n", aux->content);
			aux = aux->prox;
		}
	}
}

int main (int argc, char** argv) {
	
	Queue charQueue;

	initQueue(&charQueue);
	insertQueue(&charQueue, 'a');
	insertQueue(&charQueue, 'm');
	insertQueue(&charQueue, 'o');
	insertQueue(&charQueue, 'r');
	print(&charQueue);

	char one = removeQueue(&charQueue);
	char two = removeQueue(&charQueue);
	char three = removeQueue(&charQueue);
	char four = removeQueue(&charQueue);

	printf("\n");
	printf("\n");
	printf("\n");

	printf("%c\n", one);
	printf("%c\n", two);
	printf("%c\n", three);
	printf("%c\n", four);

}