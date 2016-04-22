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

int _remove (Tree* __tree, Node* __node) {

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
    insertTree(&__tree, 8);
    insertTree(&__tree, 1);
    insertTree(&__tree, 3);
    insertTree(&__tree, 7);
	printf("\n");
	printf("\n");
	printf("\n");
	preOrder(__tree.root);

}
