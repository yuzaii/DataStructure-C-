#include <iostream>
#include <string>
#include "CritPath.h"
using namespace std;
void opeshow()
{//�˵�
	cout<<"*           ��      ��           *"<<endl;
	cout<<" 1. ������������ͼ�����ڽӱ�洢��"<<endl;
	cout<<" 2. ��ؼ�·��"<<endl;
	cout<<" 3. �˳�"<<endl;
	cout<<"��ѡ��˵�����: ";
}

int opekind;

void main()
{
	ALGraph<string> g;
	opeshow();
	cin>>opekind;
	while(opekind>0 && opekind<4 )
	{
		if(opekind==1)
		{
			cout<<"������������!!"<<endl;
		    g.CreateGraph();
		    g.DisPlay();
		}
		else if(opekind==2)
			g.CriticalPath();
		else
		{
			cout<<"�������н�����Bye-Bye!"<<endl;
			g.DestroyGraph();
			break;
		}//if
		opeshow();
		cin>>opekind;
	}//while
}//main