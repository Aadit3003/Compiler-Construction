#include "symbolTable.h"

int hashcode(char* key){
    int len = strlen(key);
    unsigned long hashed=7;
    for(int i=0; i<len; i++){
        hashed = hashed*31 + key[i];
    }
    return hashed%SIZE;
}

//to check if key is already present in the hash table
bool exists(struct table *list, char* key)
{
	struct table *temp = list;
	while (temp) 
    {
		if (strcmp(temp->key,key)==0) return true;
  		temp = temp->next;
	}
	return false;
}

void insertID(char* key, char* value)
{	
	int index = hashcode(key);  
 	struct table *list = (struct table*) symbolTable[index].head;
 
	if (!list) //if no entries are present for the given index
    {
		struct table *entry = (struct table*) malloc(sizeof(struct table));
		entry->key = key;
		entry->token = value;
		entry->next = NULL;
		symbolTable[index].head = entry;
		noEle++;
	}
    else{ //entries are presesnt for the given index
		if(!exists(list, key)){ 
			struct table *entry = (struct table*) malloc(sizeof(struct table));
			entry->key = key;
			entry->token = value;
			entry->next = symbolTable[index].head;
			symbolTable[index].head = entry;
			noEle++;
 
		}
        else{
        	printf("Key already present in symbol table");
		}
	}
}

//initialize and populate table with keywords
void initTable()
{
	for(int i = 0; i < SIZE; i++)
    {
		symbolTable[i].head = NULL;
	}
	for(int i=0; i<27; i++){
         insertID(keywords[i].key,keywords[i].value);
    }
}

void display()
{
	for (int i = 0; i < SIZE; i++){
		struct table *temp = symbolTable[i].head;
		if (temp == NULL) {
			printf("%d: XXX\n", i);
		}
        else{
			printf("%d: ", i);
			while(temp != NULL){
				printf("key= %s  value= %s\t", temp->key, temp->token);
				temp = temp->next;
			}
			printf("\n");
		}
	}
}

void main(){
	initTable();
	insertID("if","bruh");
	display();
}