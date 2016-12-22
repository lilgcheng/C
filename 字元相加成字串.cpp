#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>
int main(void)
{
			 
	char mother[3] = {'1', '2', '3'}; 
	char str[11];
	char ch[100];
	int i,j;
	for(i=0;i<100;i++){
		if(i%5==0){
			ch[i]='0';
		}else{
			ch[i]='1';       
		}
	}       
	for(i=0;i<100;i++)
		printf("%c",ch[i]);
		printf("\n");
		printf("\n");
	for(i=0;i<100;i++){ 
		sprintf( str, "%c%c%c%c%c%c%c%c%c%c", ch[i],ch[i+1],ch[i+2],ch[i+3],ch[i+4],ch[i+5],ch[i+6],ch[i+7],ch[i+8],ch[i+9] );          
		printf(str); 
		printf("\n");
		if(strcmp(str, "0111101111") == 0) {
			printf("true\n");
		}
	}        
	system("pause");
	return 0;
}
 
