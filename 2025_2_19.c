#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
/*int main()
{
    int num;
    while (1)
    {
        printf("������һ��������");
        scanf_s("%d", &num);
        // Check if the number is a power of two
        if (num > 0 && (num & (num - 1)) == 0)
        {
            printf("yes\n");
        }
        else
        {
            printf("no\n");
        }
    }
    return 0;
}
int main()
{
    int arr[] = { 33,5,22,44,55 };
    int max = arr[0];
   for (int i = 0; i < sizeof(arr) / 4; i++)
   {
       if (arr[i] > max)
       {
           max = arr[i];
       }
    }
   printf("���ֵ��:%d", max);
    return 0;
}

int main()
{
    int arr[10] = { 0 };
    int len = sizeof(arr) / 4;
    srand(time(NULL));
    for (int i = 0; i < len; i++)
    {
        int num = rand() % 100 + 1;
        arr[i] = num;
    }
    for (int j = 0; j < len; j++)
    {
        printf("%d\t", arr[j]);
    }




    return 0;
}
void exchange(int* x, int* y);
int main()
{
    int a = 10, b = 20;
    exchange(&a, &b);
    printf("%d,%d", a, b);
    return 0;
}
void exchange(int* x, int* y)
{
    int t = *x;
    *x = *y;
    *y = t;


}
void getmax(void* p1, void* p2, int len);
int main()
{
    int a = 10;
    int b = 20;
    getmax(&a,&b, 4);
    printf("%d,%d\n", a, b);
    
}
void getmax(void* p1,void* p2 ,int len)
{
    char* t1 = p1;
    char* t2 = p2;
    char temp = 0;
    for (int i = 0; i < len; i++)
    {
        temp = *t1;
        *t1 = *t2;
        *t2 = temp;
        *t1++;
        *t2++;
    }
}*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#define SLEEP_SECONDS Sleep(1000) // Windows��Sleep��λ�Ǻ���
#else
#include <unistd.h>
#define SLEEP_SECONDS sleep(1) // Linux��sleep��λ����
#endif

void shutdown_system() {
#ifdef _WIN32
    system("shutdown -s -t 60"); // Windows��60���ػ�
#else
    system("shutdown -h +1"); // Linux��1���Ӻ�ػ�
#endif
}

void cancel_shutdown() {
#ifdef _WIN32
    system("shutdown -a"); // Windows��ȡ���ػ�
#else
    system("shutdown -c"); // Linux��ȡ���ػ�
#endif
}

int main() {
    char input[20];
    printf("ϵͳ����60���ػ������롰�ְ��Ҵ��ˡ�ȡ���ػ�...\n");
    shutdown_system();

    while (1) {
        printf("������: ");
        scanf("%s", input);
        if (strcmp(input, "�ְ��Ҵ���") == 0) {
            printf("�ػ���ȡ����\n");
            cancel_shutdown();
            break;
        }
        else {
            printf("����������������롣\n");
        }
    }

    return 0;
}