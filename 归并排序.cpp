#include<stdio.h>
#include<stdlib.h>
void print_arr(int arr[],int n)//��ӡ����
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void merge(int arr[], int temparr[], int left, int mid, int right)
{
	//�����������һ��δ�����Ԫ�����
	int l_pos = left;
	//�����Ұ�����һ��δ�����Ԫ�����
	int r_pos = mid + 1;
	//������ʱ����ĳ�ʼ�±�
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
void msort(int arr[],int temparr[],int left,int right)//�鲢�����ʵ��
{
	//���ֻ��һ��Ԫ�أ�ֻ��Ҫ�鲢������Ҫ��
	if (left < right)
	{
		int mid = (left + right) / 2;
		//���������
		msort(arr, temparr, left, mid);
		//�����Ұ���
		msort(arr, temparr, mid+1, right);
		//�ϲ�
		merge(arr, temparr, left, mid, right);
	}
}
void merge_sort(int arr[],int n)//�鲢��������
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
	int n = sizeof(arr) / sizeof(int);//������ĳ���
	print_arr(arr, n);
	merge_sort(arr, n);//���ù鲢������
	print_arr(arr, n);

	return 0;
}