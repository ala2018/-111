#include "ChYS.h"
int main(){
    Treelist cys;
    cys=new Chyanshi[MAXSIZE];
    char ch=' ';
    string Oder;
Show();
    cout<<"请输入命令：";
	cin>>Oder;
while(Oder!="exit"&&Oder!="EXIT"){
    if(Oder=="cls"||Oder=="CLS"){
		system("cls");
	Show();}
      else
    switch(Input_ch(cys)){
        case 1:Operation(cys);break;
        case -1:cout<<"表达式不规范！请重新输入！"<<endl;
               while(ch!='#') cin>>ch;//处理不规范表达式后面剩余的字符；
               break;
        case 0:break;
    }
	cout<<"**************************************************************************"<<endl;
	cout << "exit退出程序,cls清屏，其他键判断下一个式子！" << endl;
	cout<<"请输入命令：";
	cin>>Oder;
}
    delete[] cys;//删除结构体数组指针
    return 0;
}
void Show(){
	cout<<"##########################################################"<<endl;
	cout<<"                  课题：重言式判别                        "<<endl;
	cout<<"                  姓名：郑志康                            "<<endl;
	cout<<"                  学号：15251102242                       "<<endl;
	cout<<"                  班级：15计算机科学与技术2班             "<<endl;
	cout<<"                  指导老师：罗勇                          "<<endl;
	cout<<"                  时间：2017年5月28日                     "<<endl;
	cout<<"     exit退出程序,cls清屏，其他键开始进入重言式判别！     " << endl;
	cout<<"##########################################################\n\n"<<endl;

}
