#include <iostream>
#include <string> 
#include "DFSForest.h"

using namespace std; 

void opeshow()
{
	cout<<" 1. ��������ͼ��ͼ�����ڽӱ�洢�ṹ������ʾ��"<<endl; 
	cout<<" 2. ����������ɭ��/��ͨ����"<<endl;
	cout<<" 3. �˳�"<<endl;
	cout<<"  ��ѡ��˵���: ";
}

int opekind;
void main()
{
	ALGraph<string> g;
	CSTree<string> *t;
	opeshow();
	cin>>opekind;
	while(opekind > 0 && opekind < 4)
	{
		if (opekind==1)
		{ 
				cout<<"��ѡ������ͼ"<<endl;
				//ALGraph<string> g;
				g.CreateGraph();
				//CSTree<string> *t;
				g.DisPlay();
		}
		else if(opekind==2)
		{
			g.DFSForest(t);
			g.BTreetoForest(t);
		}
		else 
		{   
			g.DestroyGraph();
			cout<<"�������н�����Bye-Bye!"<<endl;
			break; }
		cout<<endl;
		opeshow();
		cin>>opekind;
	}

}
