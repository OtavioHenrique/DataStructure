//This is a simple exercise to train data strcuctures(Queue and Stack).
//Consist in check if 2 words (User Input) are palidrome. (A palindrome is a word, phrase, number, or other sequence of characters which reads the same backward or forward. Wikpedia)

//First the software ask the user inputs and insert each string into a data structure (Queue and Stack), and call the compare method.
//The compare method remove each character of the structs and compare each other. (Respecting the structs rules, stack = LIFO, queue = FIFO).
//
//				   Queue						Stack
//				____________			 	 ____________                     
//			   |	 C		|		      /	|     C      |                    
//				------------			 /	 ------------						
//			   | 	 I		|			/	|     I      |
//				------------		   /  	 ------------
//			   |	 V		|	C = C = OK 	|     V      |
//				------------	/	     	 ------------						
//			   |	 I		|  /			|     I      |
//				------------   /		 	 ------------					
//			   |	 C		| /				|     C      |
//				------------			 	 ------------                       
//
//					FIFO                         LIFO
//					
//
//
//					
//This exercise has many other more simple solutions.  
//
//
//
//Developed with <3 by Otavio Henrique

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

void initStack(Stack* s){ // Starting Stack
	s->total = 0;
	s->first = NULL;
}

Node* aloc(){ //Function to allocate and return node struct
	Node* new = malloc(sizeof(Node));
	if(!new) {
		printf("Out of Memory\n");
	} else {
		return new;
	}
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

void compare(Queue* f, Stack* s){ //Method to compare the content of the stack and queue
	char a = '1'; 
	char b = '1';
	int cont=0,tot=0;

	if(f->total == s->total) {
		tot = s->total;
	 } else{
	 	printf("Different\n");
		return;
	 }
	while(cont < tot && a != '\0' && b != '\0') {
		a = removeStack(s);
		b = removeQueue(f);


		if (a == b) {
			cont++;
		}

		
	}


	if (cont == tot) {
		printf("Equal\n");
		return;
	}
}

void writeStrings(Stack* s, Queue* f){ //Method to ask user inputs, insert into stack/queue and call compare method
	int i;

	char w1[50];
	char w2[50];

	fflush(stdin);
	printf("Enter with first word\n");
	scanf("%s", w1); //First word

	printf("Enter with second word \n");
	scanf("%s", w2); //Second word

	int stringLen = strlen(w1); //Taking the length of the string
	int stringLen2 = strlen(w2); //Taking the length of the string

	for(i=0; i < stringLen; i++){ //Inserting first word into queue
		if(w1[i] != '\0') {
		insertQueue(f,w1[i]);
		}
	}	

	for(i=0; i < stringLen2; i++){ //Inserting second word into queue
 		if(w2[i] != '\0') {
		insertStack(s,w2[i]);
		}
	}		
	
	compare(f,s); //Calling the compare function


}

int main (int argc, char** argv) {
	
	Stack charStack;
	Queue charQueue;

	initStack(&charStack); 
	initQueue(&charQueue);

	int x;

	do { //Menu

		printf("1. Check if is anagram\n");
		printf("2. Exit\n");
		scanf("%d", &x);
		switch(x) {
			case 1:
				writeStrings(&charStack, &charQueue);
				break;
			case 2:
				exit(0);
				break;
			default:
				printf("Invalid\n");
		}



	}while(x);

}