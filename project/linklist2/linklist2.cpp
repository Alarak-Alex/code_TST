#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <iomanip>
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
    while (p->next && i < position) 
    {
        p = p->next;
        i++;
    }
    if (i == position) 
    {
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
void MergeList(LinkList &La, LinkList &Lb, LinkList &Lc)
{   LinkList pa, pb, pc;

    pa=La->next;
	pb=Lb->next;
	Lc=La;
	pc=Lc;						 
	while(pa&&pb){
		if(pa->data<=pb->data){
			pc->next=pa;
			pc=pa;				
			pa=pa->next;
		}
		else{
			pc->next=pb;
			pc=pb;
			pb=pb->next;
		}
	}
	pc->next=pa?pa:pb;
	delete Lb;
    
}
// 以下是主程序
int main()
{ LinkList La,Lb,Lc; 
  printf("必须首先建立两个递增有序的单链表!\n");  
  printf("请建立第一个递增有序的单链表A：\n");      
  CreatList_L(La);
  OutputList_L(La);
  printf("请建立第二个递增有序的单链表B：\n");
  CreatList_L(Lb);
  OutputList_L(Lb);
  MergeList (La,Lb,Lc);
  printf("表A和表B已成功合并为C表!\n");
  OutputList_L(Lc);
  system("pause");
  
}
