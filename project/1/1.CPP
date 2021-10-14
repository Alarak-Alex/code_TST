#include <stdio.h>
int main()
{
    int a=1,b=2,c=3,d=4,m=2,n=2;
    (a=a*d)||(c=d/a);
    printf("%d\n%d\n",a,c);
}