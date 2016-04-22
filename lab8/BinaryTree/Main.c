#include <stdio.h>
#include <stdlib.h>

typedef struct _node Node;

struct _node {

	int value;
	Node* right,*left,*father;
 	
 };  

typedef struct {

	Node* root;
	int total;

}Tree;

void initTree (Tree* __tree) {__tree->total = 0;__tree->root = NULL;}

void insertTree (Tree* __tree, int __value) {

	Node* new = malloc(sizeof(Node));

	new->value = __value;
	
	new->right = NULL; new->left = NULL; new->father = NULL;
	
	Node* father = NULL;
	Node* sun = __tree->root;

	while (sun != NULL) {
		father = sun;

		if(__value > sun->value)
			sun = sun->right;
		else 
			sun = sun->left;
	}

	new->father = father;
		
	if (father == NULL) {
		__tree->root = new;
	} else {
		if(father->value > new->value) { 		
			father->left = new;
		} else {
			father->right = new;
		}
	}

	__tree->total++;

}

Node* search (Tree* __tree, int __value){
	Node* now = __tree->root;

	while (now != NULL && now->value != __value) {
		if(now->value > __value)
			now = now->left;
		else
			now = now->right;
	}

	if (now != NULL && now->value == __value)
		return now;
	else
		return NULL;

}

int purge(Tree* __tree, int value){
	_remove(__tree, search(__tree, value));
}

int contSuns(Node* __node) {

	int cont;

	if (__node->left != NULL && __node->right != NULL) {
		cont += 2;
	} else if (__node->left == NULL && __node->right != NULL) {
		cont += 1;
	} else if (__node->left != NULL && __node->right == NULL) {
		cont += 1;
	} else {
		cont += 0;
	}

	return cont;

}

Node* searchFather (Tree* __tree, int value) {

	Node* now = __tree->root;
	Node* father = NULL;

	while (now != NULL && now->value != value) {
		father = now;
		if(now->value > value)
			now = now->left;
		else
			now = now->right;
	}

	if (now != NULL && now->value == value)
		return father;
	else
		return NULL;


}

int _remove (Tree* __tree, Node* __node) {

	if (__node == NULL)
		return -1;

	int suns = contSuns(__node);
	Node* __father = searchFather(__tree, __node->value);

	if (suns == 0) {
		if (__node->value > __father->value) 
			__father->right = NULL;
		else
			__father->left = NULL;
		
		__node == NULL;
		__tree->total--;

	} else if (suns == 1) {
		
		if (__node->value < __father->value){
			if (__node->left != NULL) 
				__father->left = __node->left;
			else
				__father->left = __node->right;
		} else {
			if (__node->left != NULL) 
				__father->right = __node->left;
			else
				__father->right = __node->right;
		}

		__node = NULL;
		__tree->total--;
		
	} else {

		Node* aux = __node->left;

		if (__node->value < __father->value){
			__father->left = aux;
			aux->right = __node->right;
		} else {
			__father->right = aux;
			aux->right = __node->right;
		} 

	__node = NULL;
	__tree->total--;


	}

}

void preOrder(Node* __node) {
    printf(" %d ", __node->value);
    if (__node->left)
        preOrder(__node->left);
    if (__node->right)
        preOrder(__node->right);
}

void inOrder(Node* __node) {

}

int main (int argc, char** argv) {


	Tree __tree;

	initTree(&__tree);
    insertTree(&__tree, 5);
    insertTree(&__tree, 9);
    insertTree(&__tree, 4);
    insertTree(&__tree, 13);
    insertTree(&__tree, 8);
    insertTree(&__tree, 10);
    insertTree(&__tree, 7);
    insertTree(&__tree, 2);
    insertTree(&__tree, 1);
    insertTree(&__tree, 3);
	printf("\n");
	printf("\n");
	printf("\n");
	preOrder(__tree.root);
	purge(&__tree, 8);
	printf("\n");
	printf("\n");
	printf("\n");
	preOrder(__tree.root);

}
