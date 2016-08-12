#include<stdio.h>
#include<stdlib.h>
#include<String.h>
char* getHint(char* secret, char* guess);
int main()
{
	char *secret,*guess;
	secret = "12";
	guess = "21";
	getHint(secret,guess);
	system("pause");
	return 0;
}

char* getHint(char* secret, char* guess) {
        int bulls = 0; 
        int cows = 0;
        int hash[10] = {0};
        char result[10];
        int i;
        int len = strlen(secret);
        for (int i = 0; i < len; i++){
            hash[secret[i]-'0']++;//±N hash[secret[i]-'0']=1 
//            printf("%d",secret[i]-'0');
            if (secret[i] == guess[i])
                bulls ++;
        }
        printf("\n");
        for(i=0;i<10;i++){
        	printf("hash[%d]=%d\n",i,hash[i]);
		}
		printf("\n");
        for (int i = 0; i < len; i++){
        	printf("%d",guess[i]-'0');
            if (hash[guess[i]-'0']){ 
				cows++;
				hash[guess[i]-'0']--;//±N hash[guess[i]-'0']=0  
			}
        }
        
        sprintf(result, "%dA%dB", bulls, cows-bulls);
        printf("\n");
        for (int i = 0; i < 4; i++){
            printf("%c",*(result+i));
        }
        return result;
}
