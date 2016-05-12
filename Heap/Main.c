#include <stdio.h>
#include <stdlib.h>

typedef struct { //Heap struct (You can use vector)
    int *v;
    int max;
    int total;
} heap;

int rightSon (int _number){ return 2*_number + 2; } //function to return right son
int leftSon(int _number) { return 2*_number + 1; } //function to return left son
int searchFather(int _number) { return (_number-1)/2; } //function to search for the father
int lastFather (heap* h) { return (h->total/2)-1; } //function to return de last father

void initializeHeap(heap* h, int n) { //function to initialize the heap
    h->v = malloc(sizeof (int) * n); //allocatin n numbers 
    h->max = n;
    h->total = 0;
    if (!h->v) {
        printf("Error\n");
        system("PAUSE");
    }

}

void changePosition(heap* h, _bigger, _father){ //function to change the position

    int aux = h->v[_bigger];

    h->v[_bigger] = h->v[_father];
    h->[_father] = aux;

}

/**reordena o vetor h->v para que se torne um heap
 */
void construirHeap(heap* h) { //Transform vector into heap
	int i;
	
	for(i=lastFather(h); i>=0; i--)
		sift(h,i);
	
}


void sift(heap* h, int _father) { 

	int leftSon = leftSon(_father);
    int rightSon = rightSon(_father);
    int bigger = _father;


    if(h->total < rightSon && rightSon > h->v[bigger])
        bigger = rightSon;

    if(h->total < leftSon && leftSon > h->v[bigger])
        bigger = leftSon;

    if(bigger != _father) {
        changePosition(h,bigger,_father);
        sift(h,bigger);
    }

}

void destroiHeap(heap* h) { //Destroys heap
    if (h->v)
        free(h->v);
}

void insertHeap(heap* h, int _value) {
	if(h->total == h->max)
        printf("The heap is full\n");

    h->v[h->total+1] = _value;
    h->total++;

    if(h->total != 1)
        initializeHeap(h);

}

/**Retorna o maior elemento do heap h e remove-o da ?rvore.
 */
int removeHeap(heap* h) {
 //troca com o ultimo, da -- e peneira
    int aux = h->v[0];
    h->[0] = h->v[h->total-1];
    h->total--;
    initializeHeap(h);
    return aux;
}

int main(int argc, char *argv[]) {

    heap h;
    inicializaHeap(&h, 10);
    insertHeap(&h, 5);
    insertHeap(&h, 6);
    insertHeap(&h, 2);
    insertHeap(&h, 3);
    insertHeap(&h, 1);

    printf("%d", removerMaxHeap(&h));
    printf("%d", removerMaxHeap(&h));
    printf("%d", removerMaxHeap(&h));
    printf("%d", removerMaxHeap(&h));
    printf("%d", removerMaxHeap(&h));

    system("pause");
    return 0;
}