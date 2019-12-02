#include "stdio.h"//猴子吃桃
int main(int argc, char const *argv[]) {
    int day,x1,x2;
    day=9;
    x2=1;
    while (day>0) {
        x1=(x2+1)*2;
        x2=x1;
        day--;
        /* code */
    }
    printf("the total is %d\n",x1 );//输出吃的总数
    return 0;
}
