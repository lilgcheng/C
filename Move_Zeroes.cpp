#include<stdio.h>
#include<stdlib.h>
void moveZeroes(int* nums, int numsSize);
int main()
{
	int nums[5] = {0, 1, 0, 3, 12};
	moveZeroes(nums,5);
	system("pause");
	return 0;
}

void moveZeroes(int* nums, int numsSize) {
    int i,j=0;
    for(i=0;i<numsSize;i++){
    	if(nums[i]!=0){
			nums[j]=nums[i];
			j++;
		}
	}
	for(i=j;i<numsSize;i++){
		nums[i]=0;
	}

	for(i=0;i<numsSize;i++){
    	printf("%3d",nums[i]);
	}
}
