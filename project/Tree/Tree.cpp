#include <iostream>
#include "stdio.h"
#include "stdlib.h"
using namespace std;
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define NULL 0
typedef char TElemType;
typedef int Status;
typedef struct BiTNode { // 结点结构
    TElemType      data;
    struct BiTNode  *lchild, *rchild;  // 左右孩子指针
} BiTNode, *BiTree;
Status CreateBiTree(BiTree &T){
    char ch;
    cin >> ch;
    if (ch=='#') T=NULL;
    else {
        if (!(T = (BiTNode *)malloc(sizeof(BiTNode))))
        exit(OVERFLOW);
        T->data = ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
    return OK;
}
void PreOrder (BiTree T)
{ 
   if (T) {
      printf("%4c",T->data);            // 访问结点
      PreOrder(T->lchild); // 遍历左子树
      PreOrder(T->rchild);// 遍历右子树
   }
}

// 输入中序遍历二叉树算法 
void InOrder (BiTree T)
{ 
   if (T) {
        PreOrder(T->lchild); // 遍历左子树
      printf("%4c",T->data);            // 访问结点
      PreOrder(T->rchild);// 遍历右子树
   }
}
void PostOrder (BiTree T)
{ // 后序遍历二叉树 
   if (T) {      
      PostOrder (T->lchild); // 遍历左子树
      PostOrder (T->rchild);// 遍历右子树
printf("%4c",T->data);            // 访问结点
   }
}
void CountLeaf (BiTree T, int &count){
    if(T){
        if((!T->lchild)&&(!T->rchild))
        count++;
        CountLeaf(T->lchild,count);
        CountLeaf(T->rchild,count);
    }
}
void CountBT1(BiTree T, int &m)
{
if(T){
	    if(((T->lchild!=0)&&(T->rchild==0))||((T->lchild==0)&&(T->rchild!=0)))
                m++;                     //度为1的结点
		CountBT1(T->lchild,m);
		CountBT1(T->rchild,m);
	}
}
void CountBT2(BiTree T, int &n)
{
    if(T){
        if((T->lchild!=0)&&(T->rchild!=0))
        n++;
        CountBT2(T->lchild,n);
        CountBT2(T->rchild,n);
    }
}
int Depth (BiTree T){
    int m,n;
    if(!T)
    return 0;
    else{
        m = Depth(T->lchild);
        n = Depth(T->rchild);
        return (m>n?m:n)+1;
    }
}
void Get_preSeq(BiTree T,int k,int &c){
    if(T)
    {
        c++;
        if(c==k){
            cout << "\n先序遍历中第" << k << "个位置节点的值为：" << T->data << "\n";
            return ;
        }
        Get_preSeq(T->lchild,k,c);
        Get_preSeq(T->rchild,k,c);
    }
}
int main(){
 BiTree T;
 int s=0,m=0,n=0,d=0,k;
 T=NULL;
 int select;
 while(1){
    printf("\n");
	printf("*********************菜单*******************\n");
    printf("1.创建二叉树\n");
    printf("2.二叉树的递归遍历算法（前、中、后）\n");
    printf("3.求二叉树的叶子结点数和度为1、度为2的结点数\n");
    printf("4.求二叉树的深度\n");
    printf("5.求先序序列中第k个结点的值\n");  
    printf("0.退出\n");
	printf("\n请选择要执行的操作:\n");
    scanf("%d",&select);
	getchar();
    switch(select){
      case 0:return 0;
      case 1:
           printf("\n请按先序次序输入各结点的值，以#表示空树:\n");
           CreateBiTree(T);
           printf("二叉树已建立完毕！\n");
           break;
      case 2:
           if(!T) printf("\n未建立树，请先建树！\n");
           else{
               printf("\n先序遍历:");
		       PreOrder(T);
               printf("\n中序遍历:");
               InOrder(T);
               printf("\n后序遍历:");
               PostOrder(T);
               printf("\n");
             }
           break;
      case 3:
          if(!T) printf("\n未建立树，请先建树！\n");
          else{
              CountLeaf(T,s);
              printf("\n叶子结点数为：%d\n",s);
              CountBT1(T,m);
	          printf("度为1的结点数为：%d\n",m);
              CountBT2(T,n);
              printf("度为2的结点数为：%d\n",n);
           }
	      break;
      case 4:
            if(!T) printf("\n未建立树，请先建树！\n");
            else{
                d=Depth(T);
                printf("\n二叉树的深度为：%d\n",d);        
             }
          break;
      case 5:
            if(!T) printf("\n未建立树，请先建树！\n");
            else{
				int c=0;       //给计数器赋初值0 
                printf("\n请输入所要求的结点在先序序列中的位置:\n");
                scanf("%d",&k);
                Get_preSeq(T,k,c);
                if(k>c||k<1) printf("\n输入的位置%d不合法！\n",k);
				        
             }
           break;
      default:
            printf("请确认选择项:\n");
    }//end switch
 }//end while 
}
