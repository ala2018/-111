#include "ChYS.h"
#include<math.h>
void Operation(Treelist cys){
int i,j,n,index,True=0,False=0;//标记逻辑表达式运算真假次数
char ch;
Data D;
index=cys[0].index;
bool table[20];//变元取值
     j=0;
     n=pow(2,cys[0].index);//计算表达式循环次数
  while((j<n)&&(!True||!False)){
        D.d=j;
            j++;
      for(i=0;i<cys[0].index;i++)//产生一组变元取值，并回显
                       {table[i]=D.var.v0;
                       D.d=D.d>>1;}
            Oneyun(cys,cys[0].Lchild,table);//当前变元取值下，逻辑表达式真假
            if(cys[cys[0].Lchild].value)
              True++;
            else False++;
	}
	 if(True&&!False)
          cout<<"逻辑表达式为：True forever！"<<endl;
            else
              if(!True&&False)
                 cout<<"逻辑表达式为：False forever！"<<endl;
                 else
     {cout<<"**************************************************************************"<<endl;
      cout<<"逻辑表达式为：Statisfactible!请问要对表达式取值运算吗（Y/N）"<<endl;
        cin>>ch;
		while(ch=='Y'||ch=='y')
		  { n=cys[0].value;j=0;
			cout<<"变元序列：";
           for(i=0;i<n&&j<=index;i++)//打印变元序列
             if(cys[i].index==j)
			    {cout<<cys[i].ch<<" ";j++;}
        cout<<"\n请依次给变元赋值,以#结束：";
		i=0;
		cin>>ch;
		while(ch!='#')
         {table[i]=atoi(&ch);
           i++;
           cin>>ch;}
        Oneyun(cys,cys[0].Lchild,table);//调用Oneyun（）逻辑演算
        if(cys[cys[0].Lchild].value)
	           cout<<"运算结果是：Ture！"<<endl;
              else
	            cout<<"运算结果是：False！"<<endl;
	    cout<<"请问还要再对表达式取值运算吗（Y/N）"<<endl;
	    cin>>ch;
	      }
     }
}
