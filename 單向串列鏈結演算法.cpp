#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}NODE;
NODE *getnode(void);
NODE *insert(NODE *head,NODE *ptr,int value);
NODE *delect(NODE *head,NODE *ptr);
void printList(NODE* frist);
NODE *search(NODE *p,int item);
NODE *invert(NODE *head);
int main(){
	NODE *head,*ptr;
	head = getnode();
	head = NULL;
//	head->next=NULL;
	ptr = head;
	printList(head);
	
	head = insert(head,NULL,1);
	printList(head);
	head = insert(head,head,2);
	printList(head);
	head = insert(head,head->next,3);
	printList(head);
	head = invert(head);
	printList(head);
	head = delect(head,head	);
	printList(head);
	head = delect(head,head->next);
	printList(head);
	printf("收尋 ");
	printList(search(head,2));
	system("pause");
	return 0;
}

NODE *getnode(void){//產生節點 
	NODE *p;
	p=(NODE*)malloc(sizeof(NODE));//配置記憶體 
	if(p==NULL){
		printf("記憶體不足\n");
		exit(1);
	}
	return p;
}

NODE *insert(NODE *head,NODE *ptr,int value){
	NODE *newnode;
	newnode = getnode();
	newnode->data = value;
	newnode->next = NULL;
	if(ptr == NULL){//第一種狀況插入第一個節點 
		printf("插入頭\n");
		newnode->next = head;
		head = newnode;
	}else{
		if(ptr->next==NULL){//第一種狀況插入最後一個節點 
			printf("插入尾\n");
			ptr->next=newnode;
		}else{
			printf("插入中間\n");
			newnode->next = ptr->next;
			ptr->next = newnode;
		}
	}
	return head;
} 

NODE *delect(NODE *head,NODE *ptr){
	NODE *previous; 
	if(head==NULL){//如果串列是空的 
		printf("Nothing to del\n");
		return NULL;
	}
	if(ptr == head){//刪除第一個節點 
		printf("刪除頭\n");
		head = head->next;
		return head;
	}else{
		previous = head;
		while(previous->next != ptr){//找ptr的前一個節點 
			previous = previous->next;
		}
		if(ptr->next == NULL){//刪除最後一個節點 
			printf("刪除尾\n");
			previous->next =NULL; 
		}else{
			printf("刪除中間\n");
			previous->next = ptr->next;
		}
	}
	free(ptr);
	return head;
}

NODE *search(NODE *p,int item){
	NODE *node=p;
	while(node!=NULL){
//		printf("node->data=%d\n",node->data);
		if(node->data==item){
			return node;
		}else{
			node=node->next;//否者指標指向下一個節點 
		}
	} 
	return NULL;//找不符合的節點，則傳回NULL 
}

void printList(NODE* frist){
	
	NODE* node = frist;

	if(frist == NULL){
		printf("List is empty!\n");
	}else{
		while(node!=NULL){
			printf("位址%p->存值%d\t",node,node->data);
			node = node->next;
			printf("下一個位址%p\n",node);
		}
		printf("\n");
	}
}

NODE *invert(NODE *head){
	NODE *current,*prev;
	current = NULL;
	while(head!=NULL){
		prev = current;//中間節點傳到結尾 
//		printf("%p\n",last);
		current = head;//開頭節點傳到中間 
		head = head->next;//到下一個鏈結 
		current->next= prev;//準備下一個鏈結 
	}
	return current;
} 
