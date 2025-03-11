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
        printf("请输入一个整数：");
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
   printf("最大值是:%d", max);
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
#define SLEEP_SECONDS Sleep(1000) // Windows下Sleep单位是毫秒
#else
#include <unistd.h>
#define SLEEP_SECONDS sleep(1) // Linux下sleep单位是秒
#endif

void shutdown_system() {
#ifdef _WIN32
    system("shutdown -s -t 60"); // Windows下60秒后关机
#else
    system("shutdown -h +1"); // Linux下1分钟后关机
#endif
}

void cancel_shutdown() {
#ifdef _WIN32
    system("shutdown -a"); // Windows下取消关机
#else
    system("shutdown -c"); // Linux下取消关机
#endif
}

int main() {
    char input[20];
    printf("系统将在60秒后关机，输入“爸爸我错了”取消关机...\n");
    shutdown_system();

    while (1) {
        printf("请输入: ");
        scanf("%s", input);
        if (strcmp(input, "爸爸我错了") == 0) {
            printf("关机已取消。\n");
            cancel_shutdown();
            break;
        }
        else {
            printf("输入错误，请重新输入。\n");
        }
    }

    return 0;
}