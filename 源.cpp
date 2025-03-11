#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

 int MAX(int arr[], int n);
int main()
{
	int arr[] = { 2,5,1,6,8 };
	int n = sizeof(arr) / sizeof(int);
	int max = MAX(arr,n);
	printf("%d", max);
return 0;
}
int MAX(int arr[],int n)
{
	int max = arr[0];
	for (int i = 0; i < n;i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	return max;
}
T(n)=(n+1)/2=O(n),所以平均时间复杂度为O（n）
int highest_palce(int n);
int main()
{
	int n;
	scanf("%d", &n);
	int N=highest_palce(n);
	printf("最高位是：%d", N);
	return 0;
}
int highest_palce(int n)
{
	while (n > 10)
	{
		n = n / 10;
}
return n;
}
