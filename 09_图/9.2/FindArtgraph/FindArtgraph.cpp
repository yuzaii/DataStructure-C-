#include <iostream>
#include <string>
#include "AdjLGraph.h"
#include "FindArtgraph.h" 
using namespace std;

void opeshow()
{
	cout<<"*       ��           ��          *"<<endl;   
	cout<<" 1. ����ͼ��ͼ�����ڽӱ�洢�ṹ��"<<endl;
	cout<<" 2. �ؽڵ������ͨ����"<<endl;
	cout<<" 3. �˳�"<<endl;
    cout<<"��ѡ��˵���: ";
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
		{
			g.FindArticul();
			if (flg==false)  cout<<"��ͼ�����ڹؽڵ�"<<endl;
			cout<<"��ͼ�������������visited��low�ĺ���ֵ��������"<<endl;
			cout<<"i\talgraph.vertices[i].data\tvisited[i]\tlow[i]"<<endl;
			for(int i = 0;i<g.algraph.vexnum;i++)
				cout<<i<<'\t'<<g.algraph.vertices[i].data<<"\t\t\t\t"<<g.visited[i]<<"\t\t\t"<<g.low[i]<<endl;
		}
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
  
