#include <stdio.h>
int  main()
 {
  int i,j,a[11],t;

  printf(" 请输入10个数：\n" );//输入10个数
  for ( i = 1; i < 11; i++)
    /* code */
  scanf("%d",&a[i] );
  for(i = 0; i < 10; j++)
      for ( j = 1; j < 11-i; j++)

            if (a[j]>a[j+1]){
             t=a[j];a[j]=a[j+1];a[j+1]=t;//交换
              /* code */
            }
            printf("排序后的结果\n" );//输出结果
      for(i=0; i< 11; i++)
        printf("%d", a[i]);
        printf("\n" );
}
