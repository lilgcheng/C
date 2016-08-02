#include<stdio.h>
#include<stdlib.h>
int removeDuplicates(int* nums, int numsSize);
void print_arr(int *nums,int numsSize);
int main() {
    int num[] = {
        1,
        1,
        2
    };
    removeDuplicates(num, 3);
    system("pause");
    return 0;
}

int removeDuplicates(int * nums, int numsSize) {
    if (numsSize < 2) {
        return numsSize;
    }
    int i, j, temp;
    for (i = 0; i < numsSize; i++) {
        for (j = i; j < numsSize; j++) {
            if ( * (nums + i) > * (nums + j)) {
                temp = * (nums + i); *
                (nums + i) = * (nums + j); *
                (nums + j) = temp;
            }
        }
    }
    print_arr(nums, numsSize);
    int id = 1;
    for (int i = 1; i < numsSize; ++i) {
        if ( * (nums + i) != * (nums + i - 1)) { *
            (nums + id) = * (nums + i);
            id++;
        }
    }
    printf("\nid=%d\n", id);
    print_arr(nums, numsSize);
    printf("\n");
    return id;
}


void print_arr(int * nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        printf("%2d", * (nums + i));
    }
}
