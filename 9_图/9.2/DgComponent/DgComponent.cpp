#include<string> 
#include "OrLgraph.h"
 
#include <iostream>
using namespace std;

void opeshow()
{
	cout<<"  1. ��������ͼ��ͼ����ʮ������洢�ṹ������ʾ��"<<endl; 
	cout<<"  2. ��ͼǿ��ͨ����"<<endl;
	cout<<"  3. �˳�"<<endl;
	cout<<"��ѡ��˵���: ";
}
int opekind;
void main()
{
 OLGraph<string> G;
 opeshow();
	cin>>opekind;
	while(opekind>0 && opekind < 4)
	{
		if (opekind==1)
		{ 
				 
           G.CreateGraph();
		   G.DisPlay();
		   cout<<endl; 
          }
		else if ( opekind==2)
		{
			G.Get_SGraph( );//��ʮ������ṹ���������ͼG��ǿ��ͨ����
           cout<<endl;
		}
		else
		{	G.DestroyGraph();
			cout<<"�������н�����Bye-Bye!"<<endl;	 
			break;
		}//if
				cout<<endl;
				opeshow();
				cin>>opekind;
	}//while
		 
}
 
