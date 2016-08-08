#include<stdio.h>
#include<stdlib.h>
 struct ListNode {
	int val;
	struct ListNode *next;
 };
 struct ListNode* print(struct ListNode* head);
 struct ListNode* swapPairs(struct ListNode* head);
int main()
{
	struct ListNode *head,*newnode,*ptr,*tmp; 
	head = ptr = newnode = tmp = NULL;
	ptr = (struct ListNode*)malloc(sizeof(struct ListNode));
	ptr->val=1;
	head = ptr;
	int i=0;
	for(i=2;i<=4;i++){
		newnode=(struct ListNode *)malloc(sizeof(struct ListNode));
		ptr->next = newnode;
		ptr = newnode;
		ptr->next=NULL;
		ptr->val=i;
	}
	head = swapPairs(head);
	print(head);
	system("pause");
	return 0;
}

struct ListNode* swapPairs(struct ListNode* head) {
	
   	struct ListNode *p1,*p2,*p3;
    if(head==NULL || head->next == NULL)
   		return head;
	p1=head;
	p2=head->next;
	p3=p2->next;
	p2->next= p1;
	p1->next =  swapPairs(p3);
	return p2;

	
}

struct ListNode* print(struct ListNode* head){
	while(head!=NULL){
		printf("%d",head->val);
		head = head->next;
	}
}
