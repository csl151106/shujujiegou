#include<stdio.h>
#include<stdlib.h>
#define N 20


typedef struct BiTNode
{
	int  data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BitTree;

void PreOrder(BitTree T)//递归先序遍历 
{
	    if(T==NULL)
           return ;
        printf("%c ",T->data);
		PreOrder(T->lchild);
		PreOrder(T->rchild);		
}

void CreateBiTree(BitTree* T)//用扩展先序遍历创建二叉链表 
{
	char ch;
    scanf("%c", &ch);
    if(ch=='#')
        *T=NULL;
        else{
        	*T=(BitTree )malloc(sizeof(BiTNode));
			if(!*T)
			exit(-1);
			(*T)->data=ch;
			CreateBiTree(&(*T)->lchild);
			CreateBiTree(&(*T)->rchild);
		} 
}
int Calculate(BitTree T)
{
	int oper1=0;
	int oper2=0;
	if(T->lchild==NULL&&T->rchild==NULL)
	{
		return (T->data);
	}
	else
	{
		oper1=Calculate(T->lchild);
		oper2=Calculate(T->rchild);
		return Get_Value(T->data,oper1,oper2); 
	}
}
int main()
{
	BitTree* T; 
}
