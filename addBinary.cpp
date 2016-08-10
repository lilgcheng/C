#include<stdio.h>
#include<stdlib.h>
#include<String.h>
char* addBinary(char* a, char* b);
int main()
{
	char *a = "10000011";
	char *b = "111000";
	addBinary(a,b);
	system("pause");
	return 0;
}

char* addBinary(char* a, char* b) {
    int sum1=0,sum2=0;
    int i,bit=0,j;
	int len_a=0,len_b=0;
	len_a = strlen(a);
	len_b = strlen(b);
	int len_c = len_a > len_b?len_a:len_b;
	char *str;
	str = (char*)malloc(len_c+1);

	int b1=1,b2=1;
	for(i=0;i<len_a;i++){//取得a位元最高次方 
		if(i==0){
			b1*=b1*1;
		}else{
			b1=b1*2;
		}
	}
	for(i=0;i<len_b;i++){//取得b位元最高次方 
		if(i==0){
			b2*=b2*1;
		}else{
			b2=b2*2;
		}
	}	
	for(i=len_a-1,j=0;i>=0;i--,j++){
		if(i==0){
			sum1 +=(*(a+j)-'0')*1;
		}else{
			sum1 += (*(a+j)-'0')*b1;
			b1/=2;
		}
	} 
	printf("sum1 = %d\n",sum1);
	for(i=len_b-1,j=0;i>=0;i--,j++){
		if(i==0){
			sum2 +=(*(b+j)-'0')*1;
		}else{
//			printf("*(a+i)-'0' = %d\n",*(a+j)-'0');
			sum2 += (*(b+j)-'0')*b2;
			b2/=2;
		}
//		printf("bb = %d\n",bb);
	} 
	printf("sum2 = %d\n",sum2);
	int total = sum1+sum2;
	printf("total = %d\n",total);
	if(total==0){
		*str='0';
		return str;
	}
	int r,c=0;
	char *answer;
	int k=0;
	answer = (char*)malloc(sizeof(char));
	while(total!=0){
		r = total%2;
		total = total/2;
		*(answer+k)=r+'0';
		printf("r= %c k=%d\n",*(answer+k),k);
		k++; 
	}	
//	*answer='\0';
	for(i=0;i<k;i++){
		printf("%c",*(answer+i));
	}
	printf("\n");

	for(i=0,j=k-1;i<k;i++,j--){
		*(str+i)=*(answer+j);
	}
	*(str+k+1)='\0';
	for(i=0;i<k;i++){
		printf("%c",*(str+i));
	}
	return str;
}
