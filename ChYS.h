#include <iostream>
#include<cstdlib>
#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define ILLGELA -1
using namespace std;
typedef struct{//�߼����ʽ�ṹ��
   char ch;
   int weight;
   int index;//��Ԫֵ�������е��±�
   int value;
   int Lchild;
   int Rchild;
}Chyanshi,*Treelist;

typedef struct{//����ʱ�õ���˳��ջ
	int *base;
	int *top;
	int stacksize;
}SqStack;
union Data{//������ֵ��ʱ�õ��Ĺ�����ṹ
struct{
unsigned v0:1;
}var;
int d;
};
//�Զ��庯��
int InitStack(SqStack &S);//ջ��ʼ��
int Push(SqStack &S,int e);//��ջ
int Pop(SqStack &S);       //��ջ
int Read(SqStack &S);     //�鿴ջ��Ԫ��
int Postfix_Expression(int i,Treelist cys,SqStack &bian,SqStack &yun);//��׺���ʽ�����㷨
int Input_ch(Treelist cys);//�����߼����ʽͬʱ����������
void Oneyun(Treelist cys,int root,bool table[]);//���һ���߼�����
void Operation(Treelist cys);//�жϱ��ʽ����
void Show();//��ӡ����

