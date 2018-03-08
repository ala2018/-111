#include "ChYS.h"
int Input_ch(Treelist cys){
 int i,root,index,add_weight,varfag[26];
 char ch;//�����ַ�
 bool legfag1=0,legfag2=1;//���ʽ�Ϸ��жϱ��
 SqStack yun,bian;
 index=0;
 root=-1;
    InitStack(yun);
    InitStack(bian);
 add_weight=0;//���ż�Ȩ��ǣ�һ������8
  for(i=0;i<26;i++)
    varfag[i]=26;
    i=1;//ʽ�Ӵӵ�һ����Ԫ��ʼ���
    cys[0].weight=0;
 cout<<"��Դ���ޣ����ʽ����100���ַ�,��Ԫ������26����ԪΪ������ĸ"<<endl;
 cout<<"��������ʽ����#������";
 cin>>ch;
 while(ch!='#'){
    switch(ch){
      case '&': if(!legfag1) return ILLGELA;
                legfag1=0;legfag2=1;
                cys[i].weight=2+add_weight;
                cys[i].index=26;
                //����Postfix_Expression������׺���ʽ
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
 if(add_weight!=0){cout<<"���Ų�ƥ�䣬����������"<<endl;return ERROR;}
 while(Read(yun)){
            root=Pop(yun);
           if(cys[root].ch=='~')
             {cys[root].Rchild=Pop(bian);cys[root].Lchild=-1;}
            else
            {cys[root].Rchild=Pop(bian);cys[root].Lchild=Pop(bian);}
           Push(bian,root);
}
if(root==-1){
        cout<<"���ʽΪ�գ�"<<endl;
         return ERROR;}
    cys[0].Lchild=root;//����������
    cys[0].value=i;//��һ��Ԫ�ص�ֵ����������߼����ʽ�ĳ��ȣ�
    cys[0].index=index;//��Ԫ����
    return OK;
}

//������׺���ʽ
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

//˳��ջ�ĳ�ʼ��
int InitStack(SqStack &S){
	S.base = new int[MAXSIZE/2];	//�����������ΪMAXSIZE/2������ռ�
	if(!S.base)
		return ERROR;   //�洢����ʧ��
	S.top=S.base;
	S.stacksize=MAXSIZE/2;
	return OK;
}
//˳��ջ����ջ
int Push(SqStack &S,int e){
	if(S.top-S.base==S.stacksize)
		return ERROR;	//ջ��
	*(S.top++)=e;	//Ԫ��eѹ��ջ����ջ��ָ���1
	return OK;
}
//˳��ջ�ĳ�ջ
int Pop(SqStack &S){
	if(S.base==S.top)
		return ERROR;//ջ��
	return *(--S.top); //ջ��ָ���1����ջ��Ԫ�ظ���e

}
//�鿴ջ��Ԫ��
int Read(SqStack &S){
	if(S.base==S.top)
		return ERROR;//ջ��
	return *(S.top-1); //����ջ��Ԫ��

}
