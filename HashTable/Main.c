#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
} tHashTable; 

void clear(){
    #if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
        system("clear");
    #endif

    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #endif
}
int InsertList(tLde* _list, tHashItem _item){ //Function to insert number on linked list
	
	node* previus = NULL;
	node* current = _list->first;

	node* item = malloc(sizeof(node));
	item->content = _item;
	item->next = NULL;

	if(_list->total == 0) {
		_list->first = item;
		_list->total++;
		return 1;
	} else {
		while(current != NULL) {
			previus = current;
			current = current->next;
		}

		current = item;
		previus->next = item;
		_list->total++;
		return 1;
	}
	
	return -1;

}

int checkFull(tHashTable* hashTable) {
	int i;
	int total = 0;

	for(i=0; i < hashTable->size; i++){ 
		if (hashTable->table[i].first != NULL)
			total +=1;
	}

	if (total == hashTable->size)
		return -1;
	else
		return 1;

}

int countNumbers(tHashTable* hashTable){
	int i;
	int total = 0;

	for(i=0; i < hashTable->size; i++){ 
		total = total + hashTable->table[i].total;
	} 
	return total;
}

int RemoveList(tLde* _list, int _key){ //Function to remove item from linked list

	node* previus = NULL;
	node* current = _list->first;

	if (current->content.value == _key) {
		_list->first = current->next;
		free(current);
		_list->total--;
		return 1;
	} else {
		while(current != NULL && current->content.value != _key) {
			previus = current;
			current = current->next;
			}
		}
	

	if (current->next == NULL){
		previus->next = NULL;
		free(current);
		_list->total--;
		return 1;
	} else {
		previus->next = current->next;
		free(current);
		_list->total--;
		return 1;
	}

	return -1;

}

node* searchList(tLde* _list, int _key){ //Function to search for node on linked list

	node* current = _list->first;

	if (current->content.value == _key) {
		return current;
	} else {
		while(current != NULL) {
			current = current->next;
			if (current->content.value == _key)
				return current;
		}
		
	}

	return NULL;

}

void cleanList(tLde* _list){ //Method to clean linked list
	
	node* current = _list->first;
	node* aux = current;

	while(aux != NULL) {
		if(current->next != NULL)
			current = current->next;
		aux = current->next;			
		free(current);
	}
} 

int hashFunc(int _value, int _size){ //Hash Function (Return key)
	return _value % _size;
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

int insertHash(tHashItem _item, tHashTable* h){ //method to insert number on hash
	
	int answer;

	if(h != NULL){
		answer = InsertList(&(h->table[_item.key]), _item);
	}
	else{
		printf("Hash doesnt exist!\n");
		return -1;
	}

	if (answer == 1){
		printf("Successful Insertion of the number: %d\n", _item.value);
		printf("Hash is now with %d numbers\n", countNumbers(h));
	}
	else 
		printf("Error 001 - Failed while inserting hash item\n");



}

int removeHash(int key, tHashTable* h){ //Method to remove hash item
	int aux = hashFunc(key, h->size);

	int answer = RemoveList(&(h->table[aux]), key);
	if (answer == 1) 
		printf("Successful remove of number %d\n", key);
	else 
		printf("Error 003 - Failed while removing node from list on remove hash method\n");


}

void destroyHash(tHashTable *h){ //Method to destroy hash

	int i;
	
	for(i=0; i < h->size; i++) {
		cleanList(&(h->table[i]));
	}  

	free(h);
	printf("Hash Destroyed\n");
}

tHashItem* searchHash(tHashTable* h, int key){ //Function to search hash item
	int aux = hashFunc(key, h->size);
	node* answer = searchList(&(h->table[aux]), key);

	if(answer != NULL) {
		return &(answer->content);
	}else {
		return NULL;
	}
}

void test(tHashTable* hash){ //This test works with hash size equal 10
	int answer;
	tHashItem num1;
	num1.value = 15;
	num1.key = hashFunc(num1.value, hash->size);

	answer = insertHash(num1, hash);

	tHashItem num2;
	num2.value = 7;
	num2.key = hashFunc(num2.value, hash->size);

	answer = insertHash(num2, hash);

	tHashItem num3;
	num3.value = 2;
	num3.key = hashFunc(num3.value, hash->size);

	answer = insertHash(num3, hash);

	tHashItem num4;
	num4.value = 12;
	num4.key = hashFunc(num4.value, hash->size);

	answer = insertHash(num4, hash);

	tHashItem num5;
	num5.value = 22;
	num5.key = hashFunc(num5.value, hash->size);

	answer = insertHash(num5, hash);

	answer = removeHash(22, hash);

	tHashItem num6;

	num6.value = 32;
	num6.key = hashFunc(num6.value, hash->size);

	answer = insertHash(num6, hash);

	destroyHash(hash);

	tHashItem num7;
	num7.value = 22;
	num7.key = hashFunc(num7.value, hash->size);

	answer = insertHash(num7, hash);

	printf("hash size: %d\n", hash->size);
	printf("hash total: %d\n", hash->total);

}


int main (int argc, char** argv){
	int x;
	int size;
	tHashTable* hash;
	//test(hash);

	do{
		clear();
		printf("\n");
		printf("\n");
		printf("Hash Example Program\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("1 - Create Hash\n");
		printf("2 - Insert Numbers\n");
		printf("3 - Remove Number\n");
		printf("4 - Search for number\n");
		printf("5 - Print total of numbers in hash\n");
		printf("\n");
		printf("\n");
		printf("6 - Destroy hash\n");

		scanf("%d", &x);

		switch(x) {
			case 1:
			{	
				clear();
				printf("\n");
				printf("Hash Example Program\n");
				printf("\n");
				printf("Enter with the size of your hash: ");
				scanf("%d", &size);
				hash = createHashTable(size);
				clear();
				if (hash != NULL)
					printf("Successful Created\n");
				
				
				break;
			}
			case 2:
			{
				int aux,i;
				clear();
				printf("\n");
				printf("Hash Example Program\n");
				printf("\n");
				printf("How much numbers do you want to insert on your hash: ");
				scanf("%d", &aux);
				
				printf("Insert: \n");

				for(i=0; i < aux; i ++) {
					int number, answer;
					printf("Number %d: \n", i+1);
					scanf("%d", &number);

					tHashItem num1;
					num1.value = number;
					num1.key = hashFunc(num1.value, hash->size);

					answer = insertHash(num1, hash);
				}

				
				break;
			}
			case 3:
			{
				int aux;

				clear();
				printf("\n");
				printf("Hash Example Program\n");
				printf("\n");
				printf("Wich number do you want to remove from your hash: ");
				scanf("%d", &aux);
				
				int answer = removeHash(aux, hash);

				
				break;
			}
			case 4:
			{
				int aux;

				clear();
				printf("\n");
				printf("Hash Example Program\n");
				printf("\n");
				printf("Wich number do you want to search if exists: ");
				scanf("%d", &aux);

				tHashItem* number = searchHash(hash, aux);

				if(number != NULL) 
					printf("This number exists\n");
				else 
					printf("This number dosent exists\n");

				
				break;
			}
			case 5:
			{
				printf("Hash is now with %d numbers\n", countNumbers(hash));
				break;
			}
			case 6:
			{	
				int no;


				clear();
				printf("Are you sure? 1. Yes / 2. No\n");
				scanf("%d", &no);
				if (no == 1) {
					destroyHash(hash);
				}
				else {
				
					break;
				}
				
				break;
			}
			default:
				printf("Please enter with valid option\n");
		}


	}while(x);
	
}