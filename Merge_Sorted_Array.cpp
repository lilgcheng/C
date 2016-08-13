#include<stdio.h>
#include<stdlib.h>
void merge(int* nums1, int m, int* nums2, int n);
int main()
{
	int a[5]={0,0,1,2,3};
	int b[2]={0,5};
	merge(a,5,b,2);
	system("pause");
	return 0;
}

void merge(int* nums1, int m, int* nums2, int n) {
  int k;
  int len = m+n-1;
  for( k=m+n-1;k>=0;k--)
    {
        if ((nums1[m-1]>nums2[n-1]&&m>0)||n<=0)
        {
            nums1[n+m-1]=nums1[m-1];
            printf("%3d",n+m-1);
            m--;
        }
        else
        {
            nums1[n+m-1]=nums2[n-1];
            printf("%3d",n+m-1);
            n--;
        }
        
    }
    printf("\n");
    for(int i=0;i<=len;i++){
    	printf("%3d",nums1[i]);
	}
}
