#include <iostream>
using namespace std;
#include "ArrayGraph.h"
#include "SPath_DIJ.h"
#include <string>

void opeshow()
{
	cout<<"*           ��           ��          *"<<endl;   
	cout<<" 1. ����ͼ������洢�ṹ��"<<endl;
	cout<<" 2. ��ĳ��Դ�㵽���������������·��"<<endl;
	cout<<" 3. �˳�"<<endl;
    cout<<"��ѡ��˵��";
}


int opekind;

void main()
{
	MGraph<string> g;
	int i,j;
	PathMatrix_1 p; 
	ShortPathTable d; 
	opeshow();
	cin>>opekind;
	while(opekind>0 && opekind<4)
	{
		
		if (opekind==1)
		{
			cout<<"��ѡ��������"<<endl;
		    g.CreateGraph();
			g.DisPlay(); 
		}
		else if(opekind==2)
		{
			g.ShortestPath_DIJ(0,p,d);
		    cout<<"���·������p[i][j]����: "<<endl;
	        for(i = 0;i<g.mgraph.vexnum;i++)
			{
			   for(j = 0;j<g.mgraph.vexnum;j++)
			   	  cout<<p[i][j]<<" ";
				cout<<endl;
			}
			cout<<g.mgraph.vexs[0]<<"������������·������Ϊ��"<<endl;
			for(i = 1;i<g.mgraph.vexnum;i++)
				if(d[i]==INT_MAX)
                   cout<<g.mgraph.vexs[0]<<"-"<<g.mgraph.vexs[i]<<": ��"<<endl;
				else
				   cout<<g.mgraph.vexs[0]<<"-"<<g.mgraph.vexs[i]<<":"<<d[i]<<endl;
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