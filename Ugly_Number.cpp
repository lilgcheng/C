#include<stdio.h>
#include<stdlib.h>
bool isUgly(int num);
int main()
{
	int n;
	scanf("%d",&n);
	if(isUgly(n)){
		printf("YES\n");
	}else{
		printf("NO\n");
	}
	system("pause");
	return 0;
}

bool isUgly(int n) {
	if(n == 0){
		return false;
	} 
	while(n%2 == 0){
		n /= 2;
		printf("2/ = %d\n",n);
	} 
	while(n%3 == 0){
		n /= 3;
		printf("3/ = %d\n",n);
	} 
	while(n%5 == 0){
		n /= 5;
		printf("5/ = %d\n",n);
	} 
	return (n==1)?true:false;
}
