
#include <stdio.h>
#include <stdlib.h>
#define N 20
 
//���������Ľṹ���ʾ��ʽ
typedef struct tree
{
    char ch;
    struct tree *lchild;
	struct tree *rchild;
}BitTree;
 
//���������������õݹ�ķ���
//��ǰ��������롣 �� A # #(#��ʾ����)
BitTree *CreateTree()
{
	BitTree *T;
    char str; 
    scanf("%c",&str);
    if (str=='#')
        return NULL;
    else
    {
        T=(BitTree *)malloc(sizeof(BitTree));
        T->ch=str;
        T->lchild=CreateTree();
        T->rchild=CreateTree();
        return T;
    }
}
 
//ǰ������ķǵݹ�ʵ��
/*
 ˼�룺����ջ��ʵ�֣�������ջ��֮��ջ�ǿգ����������Ÿ��ڵ���ҽ���ջ��
 ֮����ڵ��ջ�����ţ�����ջ��Ԫ�أ������,
 �˽����ҽ���ջ��֮����ڵ��ջ������ջ��Ԫ�أ������...һֱ������ȥ��
 ֱ��ջΪ�ա�
 */
void PreOrder(BitTree *T)
{
    BitTree **s;
	BitTree *p;
	int top=-1;
	//����ջ��
	s=(BitTree **)malloc((N+1)*sizeof(BitTree *));
	//��ʼ��ջ��
	s[++top]=T;
	//�ǵݹ�ǰ�������
	while(top!=-1)
	{
		p=s[top--];
		printf("%c ",p->ch);    //ջ���ص㣬�Ƚ������
		if(p->rchild)
			s[++top]=p->rchild;
		if(p->lchild)
			s[++top]=p->lchild;
	}
	free(s);
}
 
 
//����������ǵݹ�ʵ��
/*
 ˼�룺����ջ���Ӹ��ڵ㿪ʼѭ����ֻҪ�����ӽڵ����ջ��ֱ�����ӽڵ�Ϊ�ա�
 ���ŵ���ջ��������жϸý���Ƿ������ӽڵ㣬
 �������ջ����û�м�����ջ�������ӽڵ��������жϸýڵ��Ƿ������ӽڵ㣬
 �����ջ��ֱ�����ӽڵ�Ϊ�գ��������ӽڵ�û��
 ���ӽڵ㣬��ջ���жϵ����Ľڵ㣬�Ƿ������ӽڵ㣬�������ջ��û�м�����ջ��
 ������Ҫ�жϸս�ջ������ڵ㣬�Ƿ������ӽڵ㣬
 �����ջ��û���������ջ���ظ���ȥ....
 ջ�գ����ж�������
 */
void InOrder(BitTree *T)
{
	BitTree **s;
    BitTree *p,*q;
    int top=-1;
	//����ջ��
	s=(BitTree **)malloc((N+1)*sizeof(BitTree *));
	//�ǵݹ����������
    if(T)
    {
        while(T)   //һֱ����������ֱ���ý������ӿ�Ϊֹ��
        {
            s[++top]=T;   //���������Ӵ���ջ�У�
            T=T->lchild;     //ָ����һ����������
        }
        while(top!=-1)  //ջ��ʱ����ѭ����
        {
            p=s[top--];//�տ�ʼ����pָ�����½ǵ����ӣ���������ý��ĸ���㣻
            printf("%c ",p->ch);  //������½ǵĽ�㣻
            while(p->rchild)  //�����ƶ�������û���ҽ�㣻
            {
                s[++top]=p->rchild;   //�����������������ջ��
                q=p->rchild;		  //�����������㸳��q��
                while(q->lchild)      //�жϽ��q��û����������
                {
                    s[++top]=q->lchild;  //����������������������������������������ջ��
                    q=q->lchild;
                }
                break;   //������ǰѭ�����ص��ڶ���whileѭ�������ղŵĲ��裻
            }
        }
    }
}
 
//����������ǵݹ�ʵ��
/*
 �㷨˼��:����ջ��ʵ�֡��Ӹ���㿪ʼ,ֻҪ���ӽڵ�ǿ�,���ջ,ֱ�����ӽڵ�
 Ϊ��Ϊֹ��ȡ��ջ��Ԫ��(ֻ��ȡ,���ǵ�ջ),�ж�:
 1:ȡ����ջ��Ԫ���Ƿ������ӽڵ�,�������ӽڵ��Ƿ񱻷��ʹ�,����������(������
 �ڵ�,�������ӽڵ㱻���ʹ�),������ý�㣬ͬʱ��ջ,���Ҽ�¼�¸÷��ʵĽڵ㡣
 2:ȡ����ջ��Ԫ�أ��������ӽڵ㣬��δ�����ʹ�����ָ������ƶ������ӽڵ㣬
 �ظ�һ��ʼ�Ƿ������ӽڵ���жϡ�
*/
void PostOrder(BitTree *T)
{	
	BitTree **s;
	BitTree *p;
    int top=-1;
	//����ջ��
	s=(BitTree **)malloc((N+1)*sizeof(BitTree *));
	//�ǵݹ���������
    do
    {
        while(T)     //һֱ����������ֱ���������������ӿ�Ϊֹ��
        {
            s[++top]=T;     //���������Ӵ���ջ�У�
            T=T->lchild;   //ָ����һ����������
        }
        p=NULL;
        while(top!=-1)
        {
            T=s[top];
            if(T->rchild==p)  //p:��ʾΪnull���������ӽڵ㱻���ʹ���;
            {
                printf("%c ",T->ch);   //������������
                top--;           //����Ժ�top--��
                p=T;  //p��¼�¸ոշ��ʵĽڵ�;
            }
            else
            {
                T=T->rchild;   //������������㣻
                break;
            }
        }
    }while(top!=-1);
}
 
int main()
{
    printf("����˳�����������(#��ʾ�ý����ӽ��Ϊ��):\n");
    BitTree *btr=CreateTree();
    printf("ǰ������ǵݹ�ʵ�֣�\n");
    PreOrder(btr);
    printf("\n");
    printf("��������ǵݹ�ʵ�֣�\n");
    InOrder(btr);
    printf("\n");
    printf("��������ǵݹ�ʵ�֣�\n");
    PostOrder(btr);
    printf("\n");
    return 0;
}
