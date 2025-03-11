#include<stdio.h>
#include<stdlib.h>
void print_arr(int arr[],int n)//打印数组
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void merge(int arr[], int temparr[], int left, int mid, int right)
{
	//定义左半区第一个未排序的元素序号
	int l_pos = left;
	//定义右半区第一个未排序的元素序号
	int r_pos = mid + 1;
	//定义临时数组的初始下标
	int pos = 0;
	while (l_pos <= mid && r_pos <= right)
	{
		if (arr[l_pos] < arr[r_pos])
			temparr[pos++] = arr[l_pos++];
		else
			temparr[pos++] = arr[r_pos++];
	}
	while (l_pos <= mid )
		temparr[pos++] = arr[l_pos++];
	while ( r_pos <= right)
		temparr[pos++] = arr[r_pos++];
	for (int i = 0; i < pos; i++)
		arr[left+i] = temparr[i];
}
void msort(int arr[],int temparr[],int left,int right)//归并排序的实现
{
	//如果只有一个元素，只需要归并，不需要分
	if (left < right)
	{
		int mid = (left + right) / 2;
		//划分左半区
		msort(arr, temparr, left, mid);
		//划分右半区
		msort(arr, temparr, mid+1, right);
		//合并
		merge(arr, temparr, left, mid, right);
	}
}
void merge_sort(int arr[],int n)//归并排序的入口
{
	int* temparr = (int*)malloc(n * sizeof(int));
	if (temparr)
	{
		msort(arr, temparr, 0, n - 1);
		free(temparr);
	}
	else
		printf("error");

}


int main(int agc,char const*agcv[])
{
	int arr[] = { 1,4,65,87,34,23,12 };
	int n = sizeof(arr) / sizeof(int);//求数组的长度
	print_arr(arr, n);
	merge_sort(arr, n);//调用归并排序函数
	print_arr(arr, n);

	return 0;
}