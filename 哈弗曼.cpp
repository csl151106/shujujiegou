#include<stdio.h>
#include<stdlib.h>
#include <string.h> 

#define N 30
#define M 2*N-1

typedef struct
{
	int weight;
	int parent,lchild,rchild;
}HTNode,HuffmanTree[M+1];

void CrtHuffmanTree(HuffmanTree ht,int w[],int n)//½¨Á¢¹ş·òÂüÊ÷ 
{
	m=2*n-1;
	for(i=1;i<=n;i++)
	{
		ht[i]={w[i],0,0,0};
	}
	for(i=n+1;i<=m;i++)
	{
		ht[i]={0,0,0,0};
	}
	for(i=n+1;i<=m;i++){
		select(ht,i-1£¬&s1,&s2);
		ht[i].weight=ht[s1].weight+ht[s2].weight;
		ht[i].lchild=s1;ht[i].rchild=s2;
		ht[s1].parent=i;ht[s2].parent=i;
	}
}

void CrtHuffmanCode1(HuffmanTree ht,HuffmanCode hc,int n)//¹ş·òÂü±àÂë 
{
	char *cd;
	int start;
	cd=(char*)malloc(n *sizeof(char));
	cd[n-1]='\0'; 
	for(i=1;i<=n;i++)
	{
		start=n-1;c=i;p=ht[i].parent;
		while(p!=0)
		{
			--start;
			if(ht[p].lchild==c)   
			{
				cd[start]='0';
			}
			else{
				cd[start]='1';
			}
			c=p;
			p=ht[p].parent;
		}
		hc[i]=(char*)malloc((n-start)*sizeof(char));
		strcpy(hc[i],&cd[start]);
	}
	free(cd);
 } 
