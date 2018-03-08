#include <iostream>
#include<cstdlib>
#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define ILLGELA -1
using namespace std;
typedef struct{//逻辑表达式结构体
   char ch;
   int weight;
   int index;//变元值在数组中的下标
   int value;
   int Lchild;
   int Rchild;
}Chyanshi,*Treelist;

typedef struct{//运算时用到的顺序栈
	int *base;
	int *top;
	int stacksize;
}SqStack;
union Data{//生成真值表时用到的共用体结构
struct{
unsigned v0:1;
}var;
int d;
};
//自定义函数
int InitStack(SqStack &S);//栈初始化
int Push(SqStack &S,int e);//入栈
int Pop(SqStack &S);       //出栈
int Read(SqStack &S);     //查看栈顶元素
int Postfix_Expression(int i,Treelist cys,SqStack &bian,SqStack &yun);//后缀表达式生成算法
int Input_ch(Treelist cys);//接收逻辑表达式同时生成运算树
void Oneyun(Treelist cys,int root,bool table[]);//完成一次逻辑运算
void Operation(Treelist cys);//判断表达式类型
void Show();//打印版面

