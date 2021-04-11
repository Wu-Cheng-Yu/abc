#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
	int data;
	struct node* next;
	struct node* prev; 
}Node;
 
typedef struct{
	Node* head; 
	Node* tail;
}DDL;

void init_list(DDL *list){
	list->head = NULL;
	list->tail = NULL;
}

void leave(DDL* list){
	if(list->tail == NULL){return;}
	Node* temp = list->tail;
	if(list->tail == list->head){
		list->tail = NULL;
		list->head = NULL;
		free(temp);
		return;
	}
	else{
		list->tail = list->tail->prev;
		list->tail->next = NULL;
		free(temp);
	}
	return;
}	 


void enter(DDL* list, int label){
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = label;
	new_node->next = NULL;
	
	if(list->head == NULL){
		new_node->prev = NULL;
		list->tail = new_node;
		list->head = new_node;
 		return;
	}
	
	else{
	list->tail->next = new_node;
	new_node -> prev = list->tail;
	list->tail = new_node;
	}
	return;
}

void printll(DDL* list){
	if(list->head == NULL){
		printf("%c",'\n');
		return; 
	}
	
	Node* node = list->head;
	
	if(node->prev == NULL && node->next==NULL){
		printf("%d",node->data);
		printf("%c",'\n');
		return;
	} 
	
	Node* temp = NULL;
	
	while(node!=NULL){
		printf("%d ",node->data);
		if(node->next == temp){
			temp = node;
			node = node->prev;
		}
		else if(node->prev == temp){
			temp = node;
			node = node->next;
		}
	}
	printf("%c",'\n');
	return;
}


void migrate(DDL* railone,DDL* railtwo){
	if(railtwo->head == NULL){
		return;
	}
	
	if (railone->head == NULL){
		railone->head = railtwo->tail;
		railone->tail = railtwo->head;
		railtwo->head = NULL;
		railtwo->tail = NULL;
		return;
	} 
	Node* temp;
	temp = railtwo->tail;
	railtwo->tail = railtwo->head;
	railtwo->head = temp;
	railone->tail->next = railtwo->tail;  
	railone->tail = railtwo->head;
	railone->tail->next = NULL;
	railtwo->head = NULL;
	railtwo->tail = NULL; 
	return;
}

int main(void){
	int k,n,r,l,r_a,r_b;
	scanf("%d%d",&k,&n);
	DDL ddl[k]; 
	char string[10];
	
	for(int i=0;i<k;i++){
		init_list(&ddl[i]);
	}
	
	for(int i=0;i<n;i++){
		scanf("%s",string);
			
		if(!strcmp(string,"enter")){
		scanf("%d %d",&r,&l);
		enter(&ddl[r],l);
		}
		
		if(!strcmp(string,"leave")){
		scanf("%d",&r);
		leave(&ddl[r]);
		}
		
		if(!strcmp(string,"migrate")){
		scanf("%d %d",&r_a,&r_b);
		migrate(&ddl[r_a],&ddl[r_b]); 
		} 
	} 
	 
	for(int i=0;i<k;i++){
		printll(&ddl[i]);
	}
	return 0;	
}
