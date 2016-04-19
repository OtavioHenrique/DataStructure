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

}Stack;

void initStack(Stack* s){
	s->total = 0;
	s->first = NULL;
}

Node* aloc(){
	Node* new = malloc(sizeof(Node));
	if(!new) {
		printf("Out of Memory\n");
	} else {
		return new;
	}
}

int empty(Stack* s) {

	if(s->first == NULL)
		return 1;
	else
		return 0;

}

void insertStack(Stack* s, char value){ 

	Node* new = aloc();
	new->content = value;

	if(empty(s)){
		s->first = new;
	}else {
		new->prox = s->first;
		s->first = new;
	}
	s->total++;
}

char removeStack(Stack* s) {

	if(s->first == NULL) {
		printf("Empty Stack\n");
	} else {

		Node* aux = s->first;
		s->first = aux->prox;
		s->total--;
		return aux->content;

	}
}

void print(Stack* s){

	if(empty(s)){
		printf("Empty Stack\n");
		return;
	} else {
		printf("Stack: \n\n\n");
		Node* aux = s->first;

		while(aux != NULL) {
			printf("%c\n", aux->content);
			aux = aux->prox;
		}
	}
}


typedef struct {

	int total;
	Node* first;

}Queue;

void initQueue(Queue* f) {
	f->total = 0;
	f->first = NULL;
}

int emptyQ(Queue* f) {

	if(f->first == NULL) 
		return 1;
	else 
		return 0;
}

void insertQueue(Queue* f, char value){

	Node* new = aloc();
	new->prox = NULL;
	new->content = value;

	if(emptyQ(f)){
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
		return;
	} else {

		Node* aux = f->first;
		f->first = aux->prox;
		f->total--;
		return aux->content;

	}
}

void printQ(Queue* f){

	if(emptyQ(f)){
		printf("Empty Queue\n");
		return;
	} else {
		printf("Fila: \n\n\n");
		Node* aux = f->first;

		while(aux != NULL) {
			printf("%c\n", aux->content);
			aux = aux->prox;
		}
	}
}

void compare(Queue* f, Stack* s){
	printf("Flag\n");
	char a = '1'; 
	char b = '1';
	int cont=0,tot=0;

	if(f->total == s->total) {
		tot = s->total;
		printf("Flag2: %d\n", tot);
	 } else{
	 	printf("Different\n");
		return;
	 }
	while(cont < tot && a != '\0' && b != '\0') {
		a = removeStack(s);
		b = removeQueue(f);

		printf("A: %c\n", a);
		printf("B: %c\n", b);


		if (a == b) {
			cont++;
		}

		
	}


	if (cont == tot) {
		printf("Equal\n");
		return;
	}
}

int main (int argc, char** argv) {

	Stack charStack;
	Queue charQueue;

	initStack(&charStack);
	initQueue(&charQueue);

	insertStack(&charStack, 'a');
	insertStack(&charStack, 'm');
	insertStack(&charStack, 'o');
	insertStack(&charStack, 'r');
	print(&charStack);

	

	printf("\n");
	printf("\n");
	printf("\n");


	
	insertQueue(&charQueue, 'r');
	insertQueue(&charQueue, 'o');
	insertQueue(&charQueue, 'm');
	insertQueue(&charQueue, 'a');
	printQ(&charQueue);

	printf("\n");
	printf("\n");
	printf("\n");



	printf("\n");
	printf("\n");
	printf("\n");
	printf("Comparing:\n");
	printf("\n");


	compare(&charQueue,&charStack);
	printf("Git\n");
}
