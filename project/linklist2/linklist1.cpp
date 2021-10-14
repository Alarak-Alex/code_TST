#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <stdio.h>
#include <string>
#include <conio.h>
using namespace std;
#define OK 1
#define ERROR 0
int j;
typedef int ElemType;
typedef int Status;
typedef struct Lnode {
	ElemType data;
	struct Lnode *next;
}Lnode,*LinkList;
void CreatList_L(LinkList &head)
{
    LinkList tail,p;
    int n,i;
    p=(Lnode*)malloc(sizeof(Lnode));
    head=tail=p;
    head->next=NULL;
    printf("输入表长");
    cin>>n;
    printf("输入元素值，使用空格隔开");
    for(i=1;i<=n;i++)
    {
        p=(Lnode*)malloc(sizeof(Lnode));
        cin>>p->data;
        p->next=NULL;
        tail->next=p;
        tail=p;
    }
    cout<<"链表创建成功";
}
LinkList Find(LinkList L, int position)
{
    LinkList p = L;
    int i = 0;
    while (p->next && i < position) {
        p = p->next;
        i++;
    }
    if (i == position) {
        return p;
    } else {
        return NULL;
    }
}
void OutputList_L(LinkList L)
{
    LinkList p = L->next;
    if (p==NULL)
    {
        cout << "\n该表是空表\n";
        return;
    }
    cout << "该元素的值为：";
    while (p)
    {   
        cout << "\n";
        cout << setiosflags(ios::right);
        cout << setw(4) << p->data <<endl;
        p = p->next;
    }
    cout << "\n";
    
}
Status ListInsert_L(LinkList L,int position,ElemType &e)
{
    LinkList p;
    LinkList tmp;
    if (p = Find(L, position - 1)) {
        tmp = (LinkList)malloc(sizeof(Lnode));
        tmp->data = e;
        tmp->next = p->next;;
        p->next = tmp;
    }
    return OK;
    
}
Status ListDelete_L(LinkList L, int position, ElemType &e) 
{
    LinkList p;
    LinkList tmp;
    if (p = Find(L, position - 1)) 
    {
        tmp = p->next;
        p->next = tmp->next;
        free(tmp);
    }
}
int main()
{ LinkList L;
  int choice,i;  
  ElemType e;
  choice=1;
  printf("必须首先建立一个单链表!\n");
      CreatList_L(L);
      OutputList_L(L);
  while(choice!=0) {
    printf("\n                                 菜单          \n");
	printf("  1  插入一个元素");
	printf("  2  删除一个元素");
	printf("  3  显示元素列表");
	printf("  0  退出系统");
	printf("\n------------------------------------------------------------------------------\n");
	printf("请输入选项(0-3)：");
    scanf("%d",&choice);
    if(choice==0) break; 
    else if(choice==1) {
      printf("请输入插入的位置和元素值: \n");
      scanf("%d%d", &i,&e);
      if(ListInsert_L(L,i,e)){  		  
          printf("插入成功!\n");
		  OutputList_L(L);}
      else printf("插入位置不合法! 请重新输入!\n");
      }
    else if (choice==2){
      printf("请输入要删除元素的位置:\n");
      scanf("%d", &i);
      if(ListDelete_L(L,i,e)){
          printf("删除成功，已删除的元素值为 %d\n",e);
		  OutputList_L(L);}
      else printf("删除位置不合法! 请重新输入!\n");
      }
    else if (choice==3){
      OutputList_L(L); }
    else
      printf("输入的选项不存在，请重新输入！\n");      
   } 
} 