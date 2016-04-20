#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node Node;

struct _node { //Node struct for stack and queues

	char content;
	Node* prox;

};

typedef struct { //Stack struct

	int total;
	Node* first;
}Stack;

Node* aloc(){ //Function to allocate and return node struct
	Node* new = malloc(sizeof(Node));
	if(!new) {
		printf("Out of Memory\n");
	} else {
		return new;
	}
}

void initStack(Stack* s){ // Starting Stack
	s->total = 0;
	s->first = NULL;
}


int empty(Stack* s) { //Function to check if stack struct is empty

	if(s->first == NULL)
		return 1;
	else
		return 0;

}

void insertStack(Stack* s, char value){ //Function to insert char into stack

	Node* new = aloc();
	new->content = value;

	if(empty(s)){ //Check if is empty
		s->first = new; //Define first node
	}else {
		new->prox = s->first;
		s->first = new;
	}
	s->total++;
}

char removeStack(Stack* s) { //Function to remove first node content from stack

	if(s->first == NULL) {
		return 0;
	} else { //Remove and return the content of the first node

		Node* aux = s->first;
		s->first = aux->prox;
		s->total--;
		return aux->content;

	}
}

typedef struct { //Queue Struct

	int total;
	Node* first;
}Queue; 

void initQueue(Queue* f) { //  Starting Queue
	f->total = 0;
	f->first = NULL;
}

int emptyQ(Queue* f) { //Check if queue is empty

	if(f->first == NULL) 
		return 1;
	else 
		return 0;
}


void insertQueue(Queue* f, char value){ //Method to insert char into queue

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

char removeQueue(Queue* f){ //Remove char from queue

	if(f->first == NULL) {
		return 0;
	} else {

		Node* aux = f->first;
		f->first = aux->prox;
		f->total--;
		return aux->content;

	}
}

void printQ(Queue* f){ //print queue

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

void print(Stack* s){ //Print Stack

	if(empty(s)){ //Check if is empty
		printf("Empty Stack\n"); 
		return;
	} else {
		printf("Stack: \n\n\n"); 
		Node* aux = s->first; 

		while(aux != NULL) { //Print
			printf("%c\n", aux->content);
			aux = aux->prox;
		}
	}
}

int compare(Queue* f, Stack* s){ //Method to compare the content of the stack and queue
	char a = '1'; 
	char b = '1';
	int cont=0,tot=0;

	if(f->total == s->total) {
		tot = s->total;
	 } else{
		return -1;
	 }
	while(cont < tot && a != '\0' && b != '\0') {
		a = removeStack(s);
		b = removeQueue(f);


		if (a == b) {
			cont++;
		}

		
	}


	if (cont == tot) {
		return 1;
	}else {
		return -1;
	}
}


 char strrts(char * word) {

 	int i = 0;
 	int answer;

 	Stack charStack;
	Queue charQueue;

	initStack(&charStack); 
	initQueue(&charQueue);


	int stringLen = strlen(word); //Taking the length of the string


		for (i=0; i < stringLen/2; i++){ //Inserting first word into queue
			if(word[i] != '\0') {
				insertQueue(&charQueue,word[i]);
			}
		}	

		int aux = (stringLen%2 == 0) ? 0 : 1; 


		for (i=(stringLen/2)+aux; i < stringLen; i++){ //Inserting second word into queue
 			if(word[i] != '\0') {
				insertStack(&charStack,word[i]);
			}
		}	

		answer = compare(&charQueue, &charStack); //calling the compare function
 
		if (answer == 1 && stringLen%2 == 0) {
			word = "4";
			return *word;
		} else if (answer == 1) {
			return word[(stringLen/2)];
		} else {
			word = "6";
			return *word;
		}

	}


	

void writeString(){ //Method to ask user inputs, insert into stack/queue and call compare method
	int i;

	char w1[50];

	fflush(stdin);
	printf("Enter with the word\n");
	scanf("%s", w1); //First word

	char answer = strrts(w1);

	printf("Answer: "); //Printing Answers

	if(answer == '4') {
		printf("' '\n");	
	} else if (answer == '6'){
		printf("NULL\n");
		
	} else {
		printf("%c\n", answer);
	}

}



int main (int argc, char** argv) {
	
	

	int x;

	do { //Menu

		printf("1. Check if is anagram\n");
		printf("2. Exit\n");
		scanf("%d", &x);
		switch(x) {
			case 1:
				writeString();
				break;
			case 2:
				exit(0);
				break;
			default:
				printf("Invalid\n");
		}



	}while(x);

}