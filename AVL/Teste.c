#include <stdio.h>
#include <stdlib.h>
#define MAX(a,b) (((a) > (b)) ? (a) : (b))

typedef struct node Node;

struct node {
	int value;
	Node* father, *left, *right;
};

typedef struct {
	
	Node* root;
	int total;

}Tree;

void initializeTree (Tree* _tree) {
	_tree->total = 0;
	_tree->root = NULL;
}

int height(Node* _node) {
	if(!_node)
		return -1;

	return (MAX(height(_node->left), height(_node->right))+1);
}

int balance_factor(Node* _node) {
	if(!_node)
		return 0;

	return (height(_node->right) - height(_node->left));
}



void leftRotate(Tree* _tree, Node* _node) {

	Node* y = _node->right;
	Node* b = y->left;
	Node* father = _node->father;

	y->left = _node;
	_node->father = y;
	_node->right = b;

	if(b)
		b->father = _node;

	if(!father)
		_tree->root = y;
	else {
		
		if (_node == father->right)
			father->right = y;
		else 
			father->left = y;
	}

	y->father = father;
	
}


void rightRotate(Tree* _tree, Node* _node) {

	Node* x = _node->left;
	Node* b = x->right;
	Node* father = _node->father;


	x->right = _node;
	_node->left = b;
	_node->father = x;

	if(b)
		b->father = _node;

	if(!father)
		_tree->root = x;
	else {
		if(_node == father->left)
			father->left = x;
		else 
			father->right = x;

	}
	x->father = father;
	

}

int balance(Tree* _tree, Node* _node){
	
	int factor = balance_factor(_node);
	int left_factor = balance_factor(_node->left);
	int right_factor = balance_factor(_node->right);

	if(factor >= 2) {
		if(right_factor < 0)
			rightRotate(_tree,_node->right);

		leftRotate(_tree, _node);
	} else if (factor <= -2) {
		if(left_factor > 0 )
			leftRotate(_tree, _node->left);

		rightRotate(_tree, _node);
	}

}

int insertTree(Tree* _tree, int _value) {
	
	Node* new = malloc(sizeof(Node));

	if(!new){
		printf("Impossible to allocate\n");
		return 0;
	}

	new->left = NULL;
	new->right = NULL;
	new->father = NULL;
	new->value = _value;

	Node* father = NULL;
	Node* son  = _tree->root;

	while(son != NULL) {
		father = son;

		if (_value > son->value)
			son = son->right;
		else
			son = son->left;
	}

	new->father = father;

	if(father == NULL) {
		_tree->root = new;
	} else {
		if(father->value > new->value) 
			father->left = new;
		else 
			father->right = new;
	}

	_tree->total++;
	
	Node* aux = new;

	while(aux != NULL){
		int factor = balance_factor(aux);
		if (factor >= 2 || factor <= -2){
			balance(_tree, aux);
		}

		aux = aux->father;
	}
	
	return 1;

}

int _print_t(Node *tree, int is_left, int offset, int depth, char s[20][255]) {
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

int print_t(Node *tree) {

	int i = 0;

    char s[20][255];
    for (i = 0; i < 20; i++)
        sprintf(s[i], "%80s", " ");

    _print_t(tree, 0, 0, 0, s);

    for (i = 0; i < 20; i++)
        printf("%s\n", s[i]);
}



int main(int argc, char const *argv[]) {

	Tree tree;

	initializeTree(&tree);
    insertTree(&tree, 5);  	
    insertTree(&tree, 9);
    insertTree(&tree, 4);
    insertTree(&tree, 15);
    insertTree(&tree, 14);
    insertTree(&tree, 13);
    insertTree(&tree, 10);
    
    insertTree(&tree, 8);
   
    insertTree(&tree, 7);
    insertTree(&tree, 2);
    insertTree(&tree, 1);
    insertTree(&tree, 3);
    insertTree(&tree, 20);
    print_t(tree.root);
    /*
    insertTree(&tree, 5);
   	print_t(tree.root);
   	insertTree(&tree, 8);
   	print_t(tree.root);
   	insertTree(&tree, 6);
   	print_t(tree.root);
   	insertTree(&tree, 20);
   	print_t(tree.root);
   	insertTree(&tree, 19);
   	print_t(tree.root);
   	insertTree(&tree, 17);
   	print_t(tree.root);
   	insertTree(&tree, 18);
   	print_t(tree.root);
   	insertTree(&tree, 15);
   	print_t(tree.root);
	*/
	

}
