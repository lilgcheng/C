#include<stdio.h>
#include<stdlib.h>
int answer(int n,int m);
int** generate(int numRows, int** columnSizes);
int main()
{

	int h;
	int **num;
	scanf("%d",&h);
	num = (int**)malloc(sizeof(int*)*h);
	generate(h,num);
	system("pause");
	return 0;
}

int** generate(int numRows, int** columnSizes) {
    int i,j;
     if (numRows <= 0) {
        *columnSizes = NULL;
        return NULL;
    }
    
	for(i=0;i<=numRows-1;i++){
		columnSizes[i]=(int*)malloc(sizeof(int)*5);
		for(j=0;j<=i;j++){
			columnSizes[i][j] = answer(i,j);
//			printf("[%d][%d] = ",i,j);
			printf("%d",columnSizes[i][j]);
		}
		printf("\n");
	} 
	return columnSizes;
}

int answer(int n,int m){
	int i,j,sum1=1,sum2=1,sum3=1,answer=0;
	for(i=n;i>=1;i--){
		sum1 = sum1*i;
	}
//	printf("%d\n",sum1);
	for(i=m;i>=1;i--){
		sum2 = sum2*i;
	}
//	printf("%d\n",sum2);
	for(i=(n-m);i>=1;i--){
		sum3 = sum3*i;
	}
//	printf("%d\n",sum3);
	answer = sum1/(sum2*sum3);
	return answer;
}
