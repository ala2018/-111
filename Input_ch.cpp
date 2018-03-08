#include "ChYS.h"
int Input_ch(Treelist cys){
 int i,root,index,add_weight,varfag[26];
 char ch;//接收字符
 bool legfag1=0,legfag2=1;//表达式合法判断标记
 SqStack yun,bian;
 index=0;
 root=-1;
    InitStack(yun);
    InitStack(bian);
 add_weight=0;//括号加权标记，一个括号8
  for(i=0;i<26;i++)
    varfag[i]=26;
    i=1;//式子从第一个单元开始存放
    cys[0].weight=0;
 cout<<"资源有限，表达式少于100个字符,变元数少于26，变元为单个字母"<<endl;
 cout<<"请输入表达式，以#结束：";
 cin>>ch;
 while(ch!='#'){
    switch(ch){
      case '&': if(!legfag1) return ILLGELA;
                legfag1=0;legfag2=1;
                cys[i].weight=2+add_weight;
                cys[i].index=26;
                //调用Postfix_Expression构建后缀表达式
                Postfix_Expression(i,cys,bian,yun);break;

      case '|': if(!legfag1) return ILLGELA;
                legfag1=0;legfag2=1;
                cys[i].weight=1+add_weight;
                cys[i].index=26;
                Postfix_Expression(i,cys,bian,yun);break;

      case '~':if(!legfag2) return ILLGELA;
                legfag2=0;
                cys[i].weight=3+add_weight;
                cys[i].index=26;
                Postfix_Expression(i,cys,bian,yun);break;

      case '(':add_weight+=8;cys[i].Lchild=-1;cys[i].Rchild=-1;cys[i].weight=0;cys[i].index=26;break;
      case ')':add_weight-=8;cys[i].Lchild=-1;cys[i].Rchild=-1;cys[i].weight=0;cys[i].index=26;break;

      default : if(legfag1) return ILLGELA;
                legfag1=1;
                cys[i].index=(int)tolower(ch)-97;
                if(cys[i].index<0||cys[i].index>=26) return ILLGELA;
                if(varfag[cys[i].index]!=26)
                    cys[i].index=varfag[cys[i].index];
                else
                    {varfag[cys[i].index]=index;cys[i].index=index;index++;}
                Push(bian,i);cys[i].Lchild=-1;cys[i].Rchild=-1;cys[i].weight=0;break;

    }
    if(add_weight<0) return ILLGELA;
    cys[i].ch=ch;
    i++;
    cin>>ch;
 }
 if(add_weight!=0){cout<<"括号不匹配，请重新输入"<<endl;return ERROR;}
 while(Read(yun)){
            root=Pop(yun);
           if(cys[root].ch=='~')
             {cys[root].Rchild=Pop(bian);cys[root].Lchild=-1;}
            else
            {cys[root].Rchild=Pop(bian);cys[root].Lchild=Pop(bian);}
           Push(bian,root);
}
if(root==-1){
        cout<<"表达式为空！"<<endl;
         return ERROR;}
    cys[0].Lchild=root;//运算树树根
    cys[0].value=i;//第一个元素的值域用来存放逻辑表达式的长度；
    cys[0].index=index;//变元个数
    return OK;
}

//构建后缀表达式
int Postfix_Expression(int i,Treelist cys,SqStack &bian,SqStack &yun){
                   int root=Read(yun);
		           if(cys[i].weight>cys[root].weight)
                      {Push(yun,i);return OK;}
				   root=Pop(yun);
                   if(cys[root].ch=='~')
					{cys[root].Rchild=Pop(bian);
                     cys[root].Lchild=-1;}
                   else
				   {cys[root].Rchild=Pop(bian);
                   cys[root].Lchild=Pop(bian);}
                   Push(bian,root);
                   Postfix_Expression(i,cys,bian,yun);
                   return OK;
}

//顺序栈的初始化
int InitStack(SqStack &S){
	S.base = new int[MAXSIZE/2];	//分配最大容量为MAXSIZE/2的数组空间
	if(!S.base)
		return ERROR;   //存储分配失败
	S.top=S.base;
	S.stacksize=MAXSIZE/2;
	return OK;
}
//顺序栈的入栈
int Push(SqStack &S,int e){
	if(S.top-S.base==S.stacksize)
		return ERROR;	//栈满
	*(S.top++)=e;	//元素e压入栈顶，栈顶指针加1
	return OK;
}
//顺序栈的出栈
int Pop(SqStack &S){
	if(S.base==S.top)
		return ERROR;//栈空
	return *(--S.top); //栈顶指针减1，将栈顶元素赋给e

}
//查看栈顶元素
int Read(SqStack &S){
	if(S.base==S.top)
		return ERROR;//栈空
	return *(S.top-1); //返回栈顶元素

}
