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

    if (!h->v)
        printf("Error\n");
    
}

void changePosition(heap* h,int _bigger,int _father){ //function to change the position

    int aux;

    aux = h->v[_bigger];

    h->v[_bigger] = h->v[_father];
    h->v[_father] = aux;

}

void sift(heap* h, int _father) { 

    int lSon = leftSon(_father);
    int rSon = rightSon(_father);
    int bigger = _father;


    if(h->total > rSon && h->v[rSon] > h->v[bigger])
        bigger = rSon;

    if(h->total > lSon && h->v[lSon] > h->v[bigger])
        bigger = lSon;

    if(bigger != _father) {
        changePosition(h,bigger,_father);
        sift(h,bigger);
    }

}

void buildHeap(heap* h) { //Transform vector into heap
	int i = 0;
	
	for(i=lastFather(h); i>=0; i--)
		sift(h,i);
	
}

void destroiHeap(heap* h) { //Destroys heap
    if (h->v)
        free(h->v);
}

void insertHeap(heap* h, int _value) {
	if(h->total == h->max) {
        printf("The heap is full\n");
        return;
    }

    h->v[h->total] = _value;
    h->total++;

    if(h->total != 1)
        buildHeap(h);

}

/**Retorna o maior elemento do heap h e remove-o da ?rvore.
 */
int removeHeap(heap* h) {
 //troca com o ultimo, da -- e peneira
    int aux = h->v[0];
    h->v[0] = h->v[h->total-1];
    h->total--;
    buildHeap(h);
    return aux;
}

int main(int argc, char *argv[]) {

    heap h;
    initializeHeap(&h, 10);
    insertHeap(&h, 5);
    insertHeap(&h, 6);
    insertHeap(&h, 2);
    insertHeap(&h, 3);
    insertHeap(&h, 50);
    insertHeap(&h, 1);
    insertHeap(&h, 0);
    insertHeap(&h, 13);
    insertHeap(&h, 44);

    printf("%d\n", removeHeap(&h));
    printf("%d\n", removeHeap(&h));
    printf("%d\n", removeHeap(&h));
    printf("%d\n", removeHeap(&h));
    printf("%d\n", removeHeap(&h));
    printf("%d\n", removeHeap(&h));

    return 0;
}