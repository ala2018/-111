#include "ChYS.h"
#include<math.h>
void Operation(Treelist cys){
int i,j,n,index,True=0,False=0;//����߼����ʽ������ٴ���
char ch;
Data D;
index=cys[0].index;
bool table[20];//��Ԫȡֵ
     j=0;
     n=pow(2,cys[0].index);//������ʽѭ������
  while((j<n)&&(!True||!False)){
        D.d=j;
            j++;
      for(i=0;i<cys[0].index;i++)//����һ���Ԫȡֵ��������
                       {table[i]=D.var.v0;
                       D.d=D.d>>1;}
            Oneyun(cys,cys[0].Lchild,table);//��ǰ��Ԫȡֵ�£��߼����ʽ���
            if(cys[cys[0].Lchild].value)
              True++;
            else False++;
	}
	 if(True&&!False)
          cout<<"�߼����ʽΪ��True forever��"<<endl;
            else
              if(!True&&False)
                 cout<<"�߼����ʽΪ��False forever��"<<endl;
                 else
     {cout<<"**************************************************************************"<<endl;
      cout<<"�߼����ʽΪ��Statisfactible!����Ҫ�Ա��ʽȡֵ������Y/N��"<<endl;
        cin>>ch;
		while(ch=='Y'||ch=='y')
		  { n=cys[0].value;j=0;
			cout<<"��Ԫ���У�";
           for(i=0;i<n&&j<=index;i++)//��ӡ��Ԫ����
             if(cys[i].index==j)
			    {cout<<cys[i].ch<<" ";j++;}
        cout<<"\n�����θ���Ԫ��ֵ,��#������";
		i=0;
		cin>>ch;
		while(ch!='#')
         {table[i]=atoi(&ch);
           i++;
           cin>>ch;}
        Oneyun(cys,cys[0].Lchild,table);//����Oneyun�����߼�����
        if(cys[cys[0].Lchild].value)
	           cout<<"�������ǣ�Ture��"<<endl;
              else
	            cout<<"�������ǣ�False��"<<endl;
	    cout<<"���ʻ�Ҫ�ٶԱ��ʽȡֵ������Y/N��"<<endl;
	    cin>>ch;
	      }
     }
}
