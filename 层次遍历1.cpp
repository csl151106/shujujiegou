#include <stdio.h>
#include <stdlib.h>

typedef struct NNode {
    char data;
    struct NNode *LChild;
    struct NNode *RChild;
} BiNode, *BiTree; //定义二叉树结点和结点指针

typedef BiTree QueueElementType;

typedef struct Node {
    QueueElementType data;
    struct Node *next;
} LinkQueueNode; //定义队列结点

typedef struct {
    LinkQueueNode *front; //队列头结点指针
    LinkQueueNode *rear;  //队列尾结点指针
} LinkQueue;              //定义队列

int InitQueue(LinkQueue *Q) //初始化队列
{
    Q->front = (LinkQueueNode *)malloc(sizeof(LinkQueueNode));
    if (Q->front != NULL) {
        Q->rear = Q->front;
        Q->front->next = NULL;
        return 1;
    } else
        return 0; //溢出
}

int EnterQueue(LinkQueue *Q, QueueElementType x) //元素x入链队列 尾插法
{
    LinkQueueNode *newnode;
    newnode = (LinkQueueNode *)malloc(sizeof(LinkQueueNode));
    if (newnode != NULL) {
        newnode->data = x;
        newnode->next = NULL;
        Q->rear->next = newnode;
        Q->rear = newnode;
        return 1;
    } else
        return 0;
}

int DeleteQueue(LinkQueue *Q, QueueElementType *x) //链队列出队 从开始的头开始取
{
    LinkQueueNode *p;
    if (Q->front == Q->rear)
        return 0;
    p = Q->front->next;
    Q->front->next = p->next;
    if (Q->rear == p)
        Q->rear = Q->front; //如果去掉结点p后，队列为空 不要忘记将队列置空
    *x = p->data;
    free(p);
    return 1;
}

int IsEmpty(LinkQueue *Q) //队列为空返回1  不为空返回0
{
    if (Q->front == Q->rear)
        return 1;
    else
        return 0;
}

void CreateBiTree(BiTree *T) //用先序遍历创建二叉树
{
    char ch;
    ch = getchar();
    if (ch == '#')
        (*T) = NULL;
    else {
        *T = (BiTree)malloc(sizeof(BiNode));
        (*T)->data = ch;
        CreateBiTree(&((*T)->LChild));
        CreateBiTree(&((*T)->RChild));
    }
}

int LayerOrder(BiTree T) //层次遍历二叉树 成功遍历返回1 失败返回0
{
    LinkQueue Q;
    BiTree p;
    InitQueue(&Q);
    if (T == NULL)
        return 0;
    EnterQueue(&Q, T);
    while (!IsEmpty(&Q)) {
        if (DeleteQueue(&Q, &p))
            ;
        printf("%c ", p->data);
        if (p->LChild)
            EnterQueue(&Q, p->LChild);
        if (p->RChild)
            EnterQueue(&Q, p->RChild);
    }
    return 1;
}

int main() {
    BiTree T;
    printf("用先序遍历创建二叉树：");
    CreateBiTree(&T);

    printf("层次遍历为：");
    if (LayerOrder(T))
        printf("\n层次遍历成功\n");
    else
        printf("\n层次遍历失败\n");

    return 0;
}
