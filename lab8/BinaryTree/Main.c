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
	Node* son = __tree->root;

	while (son != NULL) {
		father = son;

		if(__value > son->value)
			son = son->right;
		else 
			son = son->left;
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

int contsons(Node* __node) {

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

	int sons = contsons(__node);
	Node* __father = searchFather(__tree, __node->value);

	if (sons == 0) {
		if (__node->value > __father->value) 
			__father->right = NULL;
		else
			__father->left = NULL;
		
		__node == NULL;
		__tree->total--;

	} else if (sons == 1) {
		
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

		Node* aux = __node->right;

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


int _print_t(Node *tree, int is_left, int offset, int depth, char s[20][255])
{
    char b[20];
    int width = 5;
    int i = 0;

    if (!tree) return 0;

    sprintf(b, "(%03d)", tree->value);

    int left  = _print_t(tree->left,  1, offset,                depth + 1, s);
    int right = _print_t(tree->right, 0, offset + left + width, depth + 1, s);

#ifdef COMPACT
    for (i = 0; i < width; i++)
        s[depth][offset + left + i] = b[i];

    if (depth && is_left) {

        for (i = 0; i < width + right; i++)
            s[depth - 1][offset + left + width/2 + i] = '-';

        s[depth - 1][offset + left + width/2] = '.';

    } else if (depth && !is_left) {

        for (i = 0; i < left + width; i++)
            s[depth - 1][offset - width/2 + i] = '-';

        s[depth - 1][offset + left + width/2] = '.';
    }
#else
    for (i = 0; i < width; i++)
        s[2 * depth][offset + left + i] = b[i];

    if (depth && is_left) {

        for (i = 0; i < width + right; i++)
            s[2 * depth - 1][offset + left + width/2 + i] = '-';

        s[2 * depth - 1][offset + left + width/2] = '+';
        s[2 * depth - 1][offset + left + width + right + width/2] = '+';

    } else if (depth && !is_left) {

        for (i = 0; i < left + width; i++)
            s[2 * depth - 1][offset - width/2 + i] = '-';

        s[2 * depth - 1][offset + left + width/2] = '+';
        s[2 * depth - 1][offset - width/2 - 1] = '+';
    }
#endif

    return left + width + right;
}

int print_t(Node *tree)
{

	int i = 0;

    char s[20][255];
    for (i = 0; i < 20; i++)
        sprintf(s[i], "%80s", " ");

    _print_t(tree, 0, 0, 0, s);

    for (i = 0; i < 20; i++)
        printf("%s\n", s[i]);
}

int main (int argc, char** argv) {


	Tree __tree;

	initTree(&__tree);
    insertTree(&__tree, 5);
    insertTree(&__tree, 9);
    insertTree(&__tree, 4);
    insertTree(&__tree, 13);
    insertTree(&__tree, 8);
   // insertTree(&__tree, 10);
    insertTree(&__tree, 7);
    insertTree(&__tree, 2);
    insertTree(&__tree, 1);
    insertTree(&__tree, 3);
     insertTree(&__tree, 14);
     print_t(__tree.root);
	printf("\n");
	printf("\n");
	printf("\n");
	//preOrder(__tree.root);
	purge(&__tree, 9);
	printf("\n");
	printf("\n");
	printf("\n");
	//preOrder(__tree.root);
	print_t(__tree.root);


}
