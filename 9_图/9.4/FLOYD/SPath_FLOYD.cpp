#include <iostream>
using namespace std;
#include "ArrayGraph.h"
#include "SPath_FLOYD.h"
#include <string>

void opeshow()
{
	cout<<"*       ��      ��        *"<<endl;   
	cout<<" 1. ����ͼ������洢�ṹ��"<<endl; 
	cout<<" 2. ÿһ�Զ���֮������·��"<<endl;
	cout<<" 3. �˳�"<<endl;
	cout<<"��ѡ�������";

}


int opekind;

void main()
{		MGraph<string> g;
		PathMatrix_2 p; // 3ά����
		DistancMatrix d; // 2ά����
		int i,j,k;

	opeshow();
	cin>>opekind;
	while(opekind>0 && opekind<4)
	{
		if (opekind==1)
		{
			cout<<"��ѡ��������"<<endl;
		    g.CreateGraph();
			g.DisPlay(); // ���������g
		}
		else if (opekind==2)
		{
			g.ShortestPath_FLOYD(p,d); //��ÿ�Զ��������·��
			cout<<"d����:"<<endl;
			for(i = 0;i<g.mgraph.vexnum;i++)
			{
				for(j = 0;j<g.mgraph.vexnum;j++)
				{
					cout<<d[i][j]<<"  ";
				}
				cout<<endl;
			}
			for(i = 0;i<g.mgraph.vexnum;i++)
			{
				for(j = 0;j<g.mgraph.vexnum;j++)
				{
					if(i != j)
						//����ͬһ����֮���������
					{
						cout<<g.mgraph.vexs[i]<<"��"<<g.mgraph.vexs[j]<<"����̾���Ϊ��"<<d[i][j]<<endl;
					}
				}
			}
			cout<<"p����:"<<endl;
			for(i = 0;i<g.mgraph.vexnum;i++)
			{
				for(j = 0;j<g.mgraph.vexnum;j++)
				{
					if(i != j)
					{//����ͬһ����֮���������
						cout<<"��"<<g.mgraph.vexs[i]<<"��"<<g.mgraph.vexs[j]<<"������";
						for(k = 0;k<g.mgraph.vexnum;k++)
							if(p[i][j][k] == 1)
								cout<<g.mgraph.vexs[k]<<"  ";
						cout<<endl;
					}
				}
			}//for
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