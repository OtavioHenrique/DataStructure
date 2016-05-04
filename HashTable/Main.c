#include <stdio.h>
#include <stdlib.h>

typedef struct { //Hash Item struct
 int key;
 int value;
}tHashItem;

typedef struct s_node node;

struct s_node { //Node struct
 tHashItem content;
 node* next;
};

typedef struct { //Linked List struct
 node* first;
 int total;
} tLde;

typedef struct { //Hash Table struct
 int size;
 int total;
 tLde* table;
}tHashTable; 

int InsertList(tLde* lista, tHashItem item){ //Function to insert number on linked list
}
int RemoveList(tLde *lista, int chave){ //Function to remove item from linked list
}
node* searchList(tLde* lista, int chave){ //Function to search for node on linked list
}
void cleanList(tLde*lista){ //Method to clean linked list
} 
int hashFunc(int chave, int tamanho){ //Hash Function (Return key)
}

tHashTable* createHashTable(int _size){ //Method to create hash table

	tHashTable* hashTable = malloc(sizeof(tHashTable)); //Create hash table
	hashTable->size = _size; //Setting size of hash table equal argument of the function (_size)
	hashTable->total = 0; //Setting total equal 0
	hashTable->table = malloc(sizeof(tLde) * _size); //Create hash items 

	int i;

	for(i=0; i < _size; i++){ //Initializing hash table items  
		hashTable->table[i].first = NULL;
		hashTable->table[i].total = 0;
	} 

	return hashTable;

}
int insertHash(tHashItem item, tHashTable* h){ //method to insert number on hash
}
int removeHash(int key, tHashTable* h){ //Method to remove hash item
}
void destroyHash(tHashTable *h){ //Method to destroy hash
}
tHashItem* searchHash(tHashTable* h, int key){ //Function to search hash item
}
int main (int argc, char** argv){

	int size = 10;

	tHashTable* hash = createHashTable(size);

}