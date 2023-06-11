#include <stdio.h>

typedef struct node{
	int info;
	struct node *next;
}NODE;

NODE *start = NULL;

//	DELETING
void delete_from_front();									// Implmented
void delete_at_index(int index_val);						// Implemented
void delete_from_end();										// Implemented
//	INSERTING
void insert_from_front(int value);							// Implemented
void insert_at_index(int value, int index_val);				// Implemented
void insert_from_end(int value);							// Implemented
//	DISPLAYING
void display();												// Implemented


int main(){
	int value;
	insert_from_end(45);
	insert_from_end(22);
	insert_from_end(34);
	insert_from_end(74);
	display();
	insert_at_index(123, 22);
	display();
	insert_at_index(4, 22);
	display();
	delete_at_index(123);
	display();
	delete_from_end();
	display();
	insert_from_front(59);
	display();
	return 0;
}


void insert_from_front(int value){
	NODE *temp = (int *) malloc(sizeof(NODE));
	temp->info = value;
	temp->next = start;
	start = temp;
}
void delete_from_end(){
	NODE *x = start;
	while(x->next->next != NULL){
		x = x->next;
	}
	x->next = NULL;
}
void delete_at_index(int index_val){
	NODE *a, *b;
	a = b = start;
	while(a->info != index_val){
		b = a;
		a = a->next;
	}
	a = a->next;
	b->next = a;
	
}
void insert_at_index(int value, int index_val){
	NODE *temp = (int *) malloc(sizeof(NODE));
	temp->info = value;
	temp->next = NULL;
	NODE *a, *b;
	a = b = start;
	while(a->info != index_val){
		b = a;
		a = a->next;
	}
	b->next = temp;
	temp->next = a;
}
void delete_from_front(){
	start = start->next;
}
void display(){
	NODE *a = (int *) malloc(sizeof(NODE));
	a = start;
	while(a != NULL){
		printf("%d\t", a->info);
		a = a->next;
	}
	printf("\n\n");
}
void insert_from_end(int value){
	NODE *newNode = (NODE *)malloc(sizeof(NODE));
	newNode->info = value;
	newNode->next = NULL;

	if (start == NULL){
		start = newNode;
	}
	else{
		NODE *temp = start;
		while (temp->next != NULL){
			temp = temp->next;
		}
		temp->next = newNode;
	}
}

