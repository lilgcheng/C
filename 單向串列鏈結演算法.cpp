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
	printf("���M ");
	printList(search(head,2));
	system("pause");
	return 0;
}

NODE *getnode(void){//���͸`�I 
	NODE *p;
	p=(NODE*)malloc(sizeof(NODE));//�t�m�O���� 
	if(p==NULL){
		printf("�O���餣��\n");
		exit(1);
	}
	return p;
}

NODE *insert(NODE *head,NODE *ptr,int value){
	NODE *newnode;
	newnode = getnode();
	newnode->data = value;
	newnode->next = NULL;
	if(ptr == NULL){//�Ĥ@�ت��p���J�Ĥ@�Ӹ`�I 
		printf("���J�Y\n");
		newnode->next = head;
		head = newnode;
	}else{
		if(ptr->next==NULL){//�Ĥ@�ت��p���J�̫�@�Ӹ`�I 
			printf("���J��\n");
			ptr->next=newnode;
		}else{
			printf("���J����\n");
			newnode->next = ptr->next;
			ptr->next = newnode;
		}
	}
	return head;
} 

NODE *delect(NODE *head,NODE *ptr){
	NODE *previous; 
	if(head==NULL){//�p�G��C�O�Ū� 
		printf("Nothing to del\n");
		return NULL;
	}
	if(ptr == head){//�R���Ĥ@�Ӹ`�I 
		printf("�R���Y\n");
		head = head->next;
		return head;
	}else{
		previous = head;
		while(previous->next != ptr){//��ptr���e�@�Ӹ`�I 
			previous = previous->next;
		}
		if(ptr->next == NULL){//�R���̫�@�Ӹ`�I 
			printf("�R����\n");
			previous->next =NULL; 
		}else{
			printf("�R������\n");
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
			node=node->next;//�_�̫��Ы��V�U�@�Ӹ`�I 
		}
	} 
	return NULL;//�䤣�ŦX���`�I�A�h�Ǧ^NULL 
}

void printList(NODE* frist){
	
	NODE* node = frist;

	if(frist == NULL){
		printf("List is empty!\n");
	}else{
		while(node!=NULL){
			printf("��}%p->�s��%d\t",node,node->data);
			node = node->next;
			printf("�U�@�Ӧ�}%p\n",node);
		}
		printf("\n");
	}
}

NODE *invert(NODE *head){
	NODE *current,*prev;
	current = NULL;
	while(head!=NULL){
		prev = current;//�����`�I�Ǩ쵲�� 
//		printf("%p\n",last);
		current = head;//�}�Y�`�I�Ǩ줤�� 
		head = head->next;//��U�@���쵲 
		current->next= prev;//�ǳƤU�@���쵲 
	}
	return current;
} 
