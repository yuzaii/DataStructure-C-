#include <iostream>
#include<string>
using namespace std;

#include "SqStack.h"
#include "TSort.h"

void opeshow()
{   cout<<"*       ��           ��    *"<<endl;   
	cout<<" 1. ����ͼ���ڽӱ�洢�ṹ��"<<endl;
	cout<<" 2. ��������"<<endl;	 
	cout<<" 3. �˳�"<<endl;
	cout<<"��ѡ��˵�: ";
} 

int opekind;

void main()
{
    ALGraph<string> g;
	opeshow();
	cin>>opekind;
	while(opekind>0 && opekind<4)
	{
		if (opekind==1)
		{
			g.CreateGraph();
			g.DisPlay();
		}
		else if(opekind==2)
			g.TopologicalSort();
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