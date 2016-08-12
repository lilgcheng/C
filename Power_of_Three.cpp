#include<stdio.h>
#include<stdlib.h>
#include<math.h>
bool isPowerOfThree(int n);
int main()
{
	isPowerOfThree(81);
	system("pause");
	return 0;
}

bool isPowerOfThree(int n) {
    int power;
    double log3 = log(3);
    printf("log3 = %f\n",log3);
    if(n==0 ) return false;
    power = (int)(log(n)/log3 + 0.5);
    printf("power = %d\n",power);
    if(pow(3,power) == n) return true;
    else return false;
}
