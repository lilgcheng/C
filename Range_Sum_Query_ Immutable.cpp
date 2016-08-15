#include<stdio.h>
#include<stdlib.h>
struct NumArray {
	int data;
    struct NumArray *next;
};
typedef struct NumArray NODE;
struct NumArray* NumArrayCreate(int* nums, int numsSize);
int sumRange(struct NumArray* numArray, int i, int j);
void printList(NODE* frist);
void NumArrayFree(struct NumArray* numArray);
int main()
{
	int nums[6]={-2,0,3,-5,2,-1};
	NODE *head = NumArrayCreate(nums,6);
	printList(head);
	int answer = sumRange(head,0,5);
	printf("answer = %d\n",answer);
	system("pause");
	return 0;
}



/** Initialize your data structure here. */
struct NumArray* NumArrayCreate(int* nums, int numsSize) {
    int i;
	NODE *current,*frist,*preivous;
	if(nums == NULL){
		printf("List is empty!\n");
	}
	for(i=0;i<numsSize;i++){
		current=(NODE*)malloc(sizeof(NODE));
		current->data=nums[i];
		if(i==0){//存儲 
			frist = current;
		}else{
			preivous->next = current;//把前一個的節點next指向目前節點	 
		}
		current->next=NULL;
		preivous = current;
	}
	return frist;
}

int sumRange(struct NumArray* numArray, int i, int j) {
	int len =j-i;
    int sum=0;
    NODE *ptr1;
	ptr1 =numArray;
    int k;
    for(k=i;i>0;i--){
    	ptr1 = ptr1->next;
	}
//    printf("%d",ptr1->data);
 
    for(j=len;j>=0;j--){
	    printf("%3d",ptr1->data);
	    sum += ptr1->data;
    	ptr1 = ptr1->next;
	}
	
//  
  return sum;
}
/** Deallocates memory previously allocated for the data structure. */
void NumArrayFree(struct NumArray* numArray) {
    free(numArray);
}

void printList(NODE* frist){
	NODE *p = frist;
	while(p!=NULL){
		printf("%3d",p->data);
		p=p->next;
	}
	printf("\n");
}
// Your NumArray object will be instantiated and called as such:
// struct NumArray* numArray = NumArrayCreate(nums, numsSize);
// sumRange(numArray, 0, 1);
// sumRange(numArray, 1, 2);
// NumArrayFree(numArray);
