#include "ChYS.h"
int main(){
    Treelist cys;
    cys=new Chyanshi[MAXSIZE];
    char ch=' ';
    string Oder;
Show();
    cout<<"���������";
	cin>>Oder;
while(Oder!="exit"&&Oder!="EXIT"){
    if(Oder=="cls"||Oder=="CLS"){
		system("cls");
	Show();}
      else
    switch(Input_ch(cys)){
        case 1:Operation(cys);break;
        case -1:cout<<"���ʽ���淶�����������룡"<<endl;
               while(ch!='#') cin>>ch;//�����淶���ʽ����ʣ����ַ���
               break;
        case 0:break;
    }
	cout<<"**************************************************************************"<<endl;
	cout << "exit�˳�����,cls�������������ж���һ��ʽ�ӣ�" << endl;
	cout<<"���������";
	cin>>Oder;
}
    delete[] cys;//ɾ���ṹ������ָ��
    return 0;
}
void Show(){
	cout<<"##########################################################"<<endl;
	cout<<"                  ���⣺����ʽ�б�                        "<<endl;
	cout<<"                  ������֣־��                            "<<endl;
	cout<<"                  ѧ�ţ�15251102242                       "<<endl;
	cout<<"                  �༶��15�������ѧ�뼼��2��             "<<endl;
	cout<<"                  ָ����ʦ������                          "<<endl;
	cout<<"                  ʱ�䣺2017��5��28��                     "<<endl;
	cout<<"     exit�˳�����,cls��������������ʼ��������ʽ�б�     " << endl;
	cout<<"##########################################################\n\n"<<endl;

}
