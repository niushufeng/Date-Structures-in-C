#include <stdio.h>
#include <stdlib.h>
#define N 10

void *intput(int a[N]);//输入数组
void seq_search(int a[N], int key);//顺序查找
void bin_search(int x, int key);//折半查找
void selectsort(int a[N]);//选择排序
void output(int a[N]);


int main()//主函数
{
    menu();
    system("pause");
    return 0;
}

void *intput(int a[])//建立数组
{
    printf("please input 10 numbers\n");
    for(int i=0;i<N;++i)
    {
        scanf("%d",&a[i]);
    }
    return a;
}

void seq_search(int a[N], int key)//查找函数
{
    //a[0]=key;
    int i=N-1;
    int y=0;//设置判断变量
        for(;i>0;--i)
        {
            if (a[i]==key)//条件
            {
                y=1;
                printf(" search reslut is %d\n", i);
                break;
            }
        }
        if(y==0)
            printf("seq search reslut is not null\n");
    
}
 

void bin_search(int a[N], int key)//折半查找
{
    selectsort(a);//排序函数
    int low=0;//第一个值
    int high=N-1;//最后一个值
    int mid;//中间值
    while(low<high)
    {
        mid=(low+high)/2;
        if(key==a[mid])
        {
            printf(" search reslut is %d\n",mid);
            break;
        }
        else if(key<a[mid]) high=mid-1;
        else low=mid+1;
    }
   if(low>high)
    printf("bin search reslut is not null\n");
}
void selectsort(int a[N])//排序函数
{
    int i=0,j,k,t;
    for(;i<N;++i)//第i次比较
    {
        k=i;
        for(j=i+1;j<=N;++j)//从第i+1到第n处比较
        if (a[j]<a[k]) k=j;
        if(k!=i)
        {
            t=a[i];a[i]=a[k];a[k]=t;//交换数值
        }
    }
}
void output(int a[N]);

void menu()
{
    int num;
    int key;
    int a[N];
    while (1)
    {
        printf("=======================================\n");
        printf("|     Welcome to use find system!      \n");
        printf("|     Please select an operation       \n");
        printf("|  1.input               2.find in half\n");
        printf("|  3.sequential search   4.selectsort  \n");
        printf("|======================================\n");
        scanf("%d", &num);
        switch (num)
        {
        case 1:
            intput(a);break;
        case 2:
            printf("case 2 please enter the value to find:\n");
            scanf("%d", &key);
            bin_search(a, key);break;
        case 3:
            printf("please enter the value to find:\n");
            scanf("%d", &key);
            seq_search(a, key);break;
            //case 4:
            //selectsort(a);
        
        default:
            printf("  please 1-3!\n");
        }
    }
}

