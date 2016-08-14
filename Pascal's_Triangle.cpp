#include<stdio.h>
#include<stdlib.h>
int answer(int n,int m);
int** generate(int numRows, int** columnSizes);
int main()
{

	int h;
	int **num,**answer;
	scanf("%d",&h);
	num = (int**)malloc(sizeof(int*)*h);
	
	answer = (int**)malloc(sizeof(int*)*h);
	answer = generate(h,num);
	int i,j;
	for(i=0;i<h;i++){
		for(j=0;j<=i;j++){
			printf("%d",answer[i][j]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}
int** generate(int numRows, int** columnSizes) {
    if (numRows <= 0) {//0行 傳回空值 
        *columnSizes = NULL;
        return NULL;
    }

    int* columns = (int*)malloc(sizeof(int) * numRows);//一維陣列 
    columns[0] = 1;

    int** pascal = (int**)malloc(sizeof(int*) * numRows);//二維陣列
    pascal[0] = (int*)malloc(sizeof(int));
    pascal[0][0] = 1;//第一行 預設 

    for (int i = 1; i < numRows; ++i) {
        columns[i] = i + 1;
        printf("columns[%d]=%d \n",i,columns[i]);
        pascal[i] = (int*)malloc(sizeof(int) * columns[i]);//取得空間 
        pascal[i][0] = 1;
        printf("pascal[%d][0]=%d \n",i,pascal[i][0]);
        for (int j = 1; j < i; ++j) {
            pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
        }
        pascal[i][i] = 1;
    }

    *columnSizes = columns;
    return pascal;
}
