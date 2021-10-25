#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
using namespace std;
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int ElemType;
typedef int Status;
//----- 栈的顺序存储表示 -----
#define  STACK_INIT_SIZE  100 // 存储空间的初始分配量
#define  STACKINCREMENT   10  // 存储空间的分配增量
typedef struct {    
ElemType  *base;    
ElemType  *top;  
        int  stacksize;    
  } SqStack;
// 构造一个空栈S
Status InitStack(SqStack &S){
     S.base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
	 if(!S.base) exit (OVERFLOW);
	 S.top = S.base;
	 S.stacksize = STACK_INIT_SIZE;
	 return OK;
}

// 判栈S是否为空栈
Status StackEmpty(SqStack  S){
   if (S.top==S.base) return OK;
   else return ERROR;
}

//入栈函数
Status Push (SqStack &S, ElemType e) {

	if (S.top-S.base>=S.stacksize)
    {
        S.base = (ElemType *)realloc(S.base,(S.stacksize+STACKINCREMENT) * sizeof(ElemType));
        if (!S.base)
        exit (OVERFLOW);
        S.top=S.base+S.stacksize;
        S.stacksize+=STACKINCREMENT;

        
    }
    *S.top++=e;

}
//出栈函数
Status Pop (SqStack &S, ElemType &e) { 
 
	if (S.top==S.base)
    return ERROR;
    e=*--S.top ;
    return OK;

}
//输出顺序栈函数
void OutStack(SqStack  S)
{	int *p;
		if(S.top == S.base){
		printf("这是一个空栈！");
	    }
	else
for(p= S.top-1; p>= S.base;p--)
	   printf("%6d", *p);
    printf("\n"); 
}
//十进制转八进制函数
void conversion()
{   int N;
	ElemType e;
	SqStack S;
	InitStack(S);
	printf("请输入要转换成八进制的数（非负数）：");
	scanf("%d",&N);
	while(N)
	{
		Push(S,N%8);
		N=N/8;
	}
	printf("八进制数为：");
	while(!StackEmpty(S))
	{
		Pop(S,e);
		printf("%d",e);
	}
	printf("\n");
}

//主函数
int main()
{   SqStack s;
	int cord; ElemType a;
	    printf("第一次使用必须初始化！\n");
		do{		
		printf("\n                                 主菜单          \n");
		printf("  1 初始化顺序栈 ");
		printf("  2 插入一个元素 ");
		printf("  3 删除栈顶元素 ");
        printf("  4 十进制转八进制 ");
		printf("  5 结束程序运行 ");
		printf("\n------------------------------------------------------------------------------\n");
		printf("请输入您的选择( 1, 2, 3, 4, 5)");
		scanf("%d",&cord);
		printf("\n");
		switch(cord)
		{	case 1:
					InitStack(s);
					OutStack(s);
				    break;
			case 2:
					printf("请输入要插入的数据元素：a=");
					scanf("%d",&a);
					Push(s,a);
printf("%d 进栈之后的栈：",a);
					OutStack(s);
				    break;
			case 3:
					Pop(s,a);
printf("栈顶元素 %d 出栈之后的栈：",a);
					OutStack(s);
				    break;
            case 4:
                    conversion();
					 break;
			case 5:
					exit(0);
		
		}
		}while (cord<=4);
}
