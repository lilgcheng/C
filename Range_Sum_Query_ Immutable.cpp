#include<stdio.h>
#include<stdlib.h>
struct NumArray {
 	int size;
    int *sum;
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
//	printList(head);
	int answer = sumRange(head,0,5);
	printf("answer = %d\n",answer);
	system("pause");
	return 0;
}



/** Initialize your data structure here. */
struct NumArray* NumArrayCreate(int* nums, int numsSize) {
    struct NumArray *array;
    int i;

    array = (struct NumArray*)calloc(1, sizeof(struct NumArray));
    array->sum = (int *) calloc(numsSize+1, sizeof(int));
    array->size = numsSize;
    array->sum[0] = 0;
    for(i = 0; i < numsSize; i++){
            array->sum[i+1] = nums[i] + array->sum[i];/*Àx¦sÁ`©M EX:array->sum[1] = nums[0]+array->sum[0] 
																	array->sum[2] = nums[1]+array->sum[1]*/
            printf("%d-%3d\n",i+1,array->sum[i+1]);
    }
    printf("\n");
    return array;
}

int sumRange(struct NumArray* numArray, int i, int j) {
	int sum = 0;
    if(!numArray)
        return 0;
    sum = numArray->sum[j+1] - numArray->sum[i];
    return sum;	
  return sum;
}
/** Deallocates memory previously allocated for the data structure. */
void NumArrayFree(struct NumArray* numArray) {
    free(numArray->sum);
    free(numArray);
}
//

// Your NumArray object will be instantiated and called as such:
// struct NumArray* numArray = NumArrayCreate(nums, numsSize);
// sumRange(numArray, 0, 1);
// sumRange(numArray, 1, 2);
// NumArrayFree(numArray);
