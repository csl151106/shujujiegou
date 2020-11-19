#include <stdio.h>
#include <stdlib.h>

typedef struct NNode {
    char data;
    struct NNode *LChild;
    struct NNode *RChild;
} BiNode, *BiTree; //������������ͽ��ָ��

typedef BiTree QueueElementType;

typedef struct Node {
    QueueElementType data;
    struct Node *next;
} LinkQueueNode; //������н��

typedef struct {
    LinkQueueNode *front; //����ͷ���ָ��
    LinkQueueNode *rear;  //����β���ָ��
} LinkQueue;              //�������

int InitQueue(LinkQueue *Q) //��ʼ������
{
    Q->front = (LinkQueueNode *)malloc(sizeof(LinkQueueNode));
    if (Q->front != NULL) {
        Q->rear = Q->front;
        Q->front->next = NULL;
        return 1;
    } else
        return 0; //���
}

int EnterQueue(LinkQueue *Q, QueueElementType x) //Ԫ��x�������� β�巨
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

int DeleteQueue(LinkQueue *Q, QueueElementType *x) //�����г��� �ӿ�ʼ��ͷ��ʼȡ
{
    LinkQueueNode *p;
    if (Q->front == Q->rear)
        return 0;
    p = Q->front->next;
    Q->front->next = p->next;
    if (Q->rear == p)
        Q->rear = Q->front; //���ȥ�����p�󣬶���Ϊ�� ��Ҫ���ǽ������ÿ�
    *x = p->data;
    free(p);
    return 1;
}

int IsEmpty(LinkQueue *Q) //����Ϊ�շ���1  ��Ϊ�շ���0
{
    if (Q->front == Q->rear)
        return 1;
    else
        return 0;
}

void CreateBiTree(BiTree *T) //�������������������
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

int LayerOrder(BiTree T) //��α��������� �ɹ���������1 ʧ�ܷ���0
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
    printf("���������������������");
    CreateBiTree(&T);

    printf("��α���Ϊ��");
    if (LayerOrder(T))
        printf("\n��α����ɹ�\n");
    else
        printf("\n��α���ʧ��\n");

    return 0;
}
