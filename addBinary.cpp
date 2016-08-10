#include<stdio.h>
#include<stdlib.h>
#include<String.h>
char* addBinary(char* a, char* b);
int main()
{
	char *a = "1001";
	char *b = "1";
	addBinary(a,b);
	system("pause");
	return 0;
}

char* addBinary(char* a, char* b) {
	int la = strlen(a);
	int lb = strlen(b);
	int lr = la > lb ? la : lb;
	int carry = 0;
	char *res = (char*)calloc(lr + 2, sizeof(char));
	res[lr + 1] = '\0';
	la--; lb--;
	while (la >= 0 || lb >= 0) {
	    int ba = la >= 0 ? a[la--] - '0' : 0;
	    printf("ba =%d\t",ba);
	    int bb = lb >= 0 ? b[lb--] - '0' : 0;
	    printf("bb =%3d\t",bb);
		int br = ba ^ bb ^ carry;
		printf("br =%3d\t",br);
	    carry = (ba & bb) | (carry & (ba ^ bb));
	    printf("carry =%3d\n",carry);
	    res[lr--] = br + '0';
	}
	if (carry==0) {
		printf("%s\n",res+1);
		return res + 1;
	}
		
	res[0] = '1';
	printf("%s\n",res);
	return res;
}
