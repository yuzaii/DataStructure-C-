#include <iostream>
#include <string>
using namespace std;
#include "Minitree_prim.h"
 
void opeshow()
{
	cout<<"  1. �������Ĵ���(��������洢�ṹ��"<<endl; 
	cout<<"  2. ����С������(Pirm�㷨)"<<endl;
	cout<<"  3. �˳�"<<endl;
	cout<<"��ѡ��˵��";
}
int opekind;
void main()
{	
	MGraph<string> g;
	string u;
	opeshow();
    cin>>opekind;
	while(opekind>0 && opekind<4)
	{
	   if (opekind==1)
	   {
		   g.CreateUDN();
		   g.DisPlay();}
	   else if (opekind==2)
	   {
		   cout<<"������������Ҫ��������ķ�㷨������С�������ĳ�������u:"<<endl;
           cin>>u;
	       g.MiniSpanTree_PRIM(u);
	   }
       else
	   {
		   g.DestroyGraph();
	       cout<<endl; 
	       cout<<"�������н�����Bye-Bye!"<<endl;
	       break;
	   }
	   opeshow();
	   cin>>opekind;
	  }
}
