#include <stdio.h>

typedef struct node{
	int info;
	struct node *next;
}NODE;
NODE *start = NULL;

void insert_from_front(int value);				// Implemented
void insert_from_end(int value);				// Implemented
void insert_at_index(int value, int index);		// Implemented

void delete_from_front();						// Implemented (Buggy)
void delete_from_end();							// Implemented (Buggy)
void delete_at_index(int value, int index);		// Not Implemented

void display();									// Implemented

int main(){
	insert_from_front(10);
	display();
	insert_from_front(20);
	display();
	insert_from_front(40);
	display();
	insert_at_index(56, 20);
	display();
	delete_from_front();
	delete_from_front();
	delete_from_front();
	delete_from_front();
	display();
	
	return 0;
}

void delete_from_end(){
	NODE *b = start;
	while(b->next->next != start){
		b = b->next;
	}
	b->next = start;
}
void delete_from_front(){
	NODE *b = start;
	while(b->next != start){
		b = b->next;
	}
	start = start->next;
	b->next = start;
}
void insert_at_index(int value, int index){
	NODE *index_node = start;
	while(index_node->next->info != index){
		index_node = index_node->next;
	}
	NODE *last_node = start;
	while(last_node->next != start){
		last_node = last_node->next;
	}
//	printf("END_NODE: %d", last_node->info);
//	printf("FRONT_NODE: %d", start->info);
//	printf("VALUE_NODE: %d", index_node->info);
	
	if(index_node->next->info == start->info){
		insert_from_front(value);
	}
	else if(index_node->next->info == last_node->info){
		insert_from_end(value);
	}
	else{
		NODE *temp = (int *) malloc(sizeof(NODE));
		temp->info = value;
		temp->next = index_node->next;
		index_node->next = temp;
	}
}
void insert_from_end(int value){
	NODE *temp = (int *) malloc(sizeof(NODE));
	temp->info = value;
	temp->next = temp;
	if(start == NULL){
		start = temp;
	}
	else{
		NODE *b = start;
		while(b->next != start){
			b = b->next;
		}
		b->next = temp;
		temp->next = start;
	}
}
void insert_from_front(int value){
	NODE *temp = (int *) malloc(sizeof(NODE));
	temp->info = value;
	temp->next = temp;
	if(start == NULL){
		start = temp;
	}
	else{
		temp->next = start;
		NODE *b = start;
		while(b->next != start){
			b = b->next;
		}
		b->next = temp;
		start = temp;
	}
}
void display(){
	NODE *a = start->next;
	printf("%d\t", start->info);
	while(a != start){
		printf("%d\t", a->info);
		a = a->next;
	}
	printf("\n");
}
