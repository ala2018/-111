#include"ChYS.h"
void Oneyun(Treelist cys,int root,bool table[]){
	if(cys[root].Lchild!=-1)
	Oneyun(cys,cys[root].Lchild,table);
	if(cys[root].Rchild!=-1)
		Oneyun(cys,cys[root].Rchild,table);
	switch(cys[root].ch){
	case '&' :cys[root].value=cys[cys[root].Lchild].value && cys[cys[root].Rchild].value;break;
	case '|' :cys[root].value=cys[cys[root].Lchild].value ||cys[cys[root].Rchild].value;break;
	case '~' :cys[root].value=! cys[cys[root].Rchild].value;break;
	default :cys[root].value=table[cys[root].index];break;
	}
}