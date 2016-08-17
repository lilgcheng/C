#include<stdio.h>
#include<stdlib.h>
bool isUgly(int num);
int main()
{
	int n;
	scanf("%d",&n);
	isUgly(n);
	system("pause");
	return 0;
}

bool isUgly(int num) {
	if(num>0 && num<2147483647){
		int facter=2;
		int c=0,i=0;
		int *nums;
		while(facter<=num){
			if(num%facter==0){
				nums = (int*)malloc(sizeof(int)*num);
				printf("%3d\n",facter);
				nums[c]= facter;
				c++;
			}
			facter++;
		}
		int k=c;
		printf("\n");
		printf("c= %d\n",c);
		for(i=0;i<c;i++){
			if(nums[i]==2 || nums[i]==3 || nums[i]==5 ){
				k--;
			}
		}
		if(k==0){
			printf("YES\n");
			return true;
		}else{
			printf("NO\n");
			return false;
		}
	}else{
		return false;
	}
}
