#include<string> 
#include "OrLgraph.h"
#include "LinkQueue.h"
#include <iostream>
using namespace std;

template <class T>
bool visit(T v)
{
	cout<<v<<" ";
	return true;
}

void ShowOper()
{
	cout<<"��ѡ����Ҫ�Ĳ���"<<endl;
	cout<<"0.  ����ͼ"<<endl;
	cout<<"1.  ���ض���v��ͼ�е�λ��"<<endl;
	cout<<"2.  ��������λ�õĶ����ֵ"<<endl;
	cout<<"3.  �ı�ĳ����֪����v��ֵ"<<endl;
	cout<<"4.  ��ͼ�������¶���v"<<endl;
	cout<<"5.  ��ͼ��ɾ������v�Լ����кͶ���v������ı߻�"<<endl;
	cout<<"6.  ��ͼ������һ���Ӷ���v������w�ı߻�"<<endl;
	cout<<"7.  ��ͼ��ɾ��һ���Ӷ���v������w�ı߻�"<<endl;
	cout<<"8.  ��ͼ�У��ӵ�һ���������������ȱ���ͼ"<<endl;
	cout<<"9.  ��ͼ�У��ӵ�һ�����������ȱ���ͼ"<<endl;
    cout<<"10. ��ʾͼ"<<endl;
	cout<<"11. ����ͼ"<<endl;
	cout<<"12. �˳�"<<endl;
}
int graphkind;
int opchoice;
 
void main()
{
    int opchoice;
	OLGraph<string> g;//case0
    g.CreateGraph();
    do
	{
		ShowOper();
	    cin>>opchoice;
		switch(opchoice)
				{
				case 0:
					{
						g.CreateGraph();
						cout<<endl;
						break;
					}
					
					
				case 1:
					{
						string a;
						cout<<"��������Ҫ����Ҫ��ѯλ�õĶ��������";
						cin>>a;
						cout<<"����"<<a<<"��ͼ�е�λ��Ϊ"<<g.LocateVex(a)<<endl;
						cout<<endl;
						break;
					}
					
					
				case 2:
					{
						int index;
						cout<<"��������Ҫ����Ҫ�����λ��(int��)";
						cin>>index;
						cout<<"λ��Ϊ"<<index<<"�Ķ���Ϊ"<<g.GetVex(index)<<endl;
						cout<<endl;
						break;
					}
					
				case 3:
					{
						string v(""),value("");
						cout<<"��������Ҫ����Ҫ���ĵĶ����ֵ";
						cin>>v;
						cout<<"��������Ҫ����Ҫ���ĵĶ������ֵ";
						cin>>value;
						g.PutVex(v,value);
						cout<<endl;
						break;
					}
					
				case 4:
					{
						string v;
						cout<<"����������Ҫ���ӵĶ����ֵ";
						cin>>v;
						g.InsertVex(v);
						cout<<endl;
						break;
					}
					
				case 5:
					{
						string v;
						cout<<"����������Ҫɾ���Ķ����ֵ";
						cin>>v;
						g.DeleteVex(v);
						g.DisPlay();
						cout<<endl;
						break;
					}
					
				case 6:
					{
						string v,w;
						cout<<"����������Ҫ����һ���Ӷ���v������w�ı߻򻡵Ķ���v�Ͷ���w";
						cin>>v>>w;
						g.InsertArc(v,w);
						cout<<endl;
						break;
					}
					
				case 7:
					{
						string v,w;
						cout<<"����������Ҫɾ��һ���Ӷ���v������w�ı߻򻡵Ķ���v�Ͷ���w";
						cin>>v>>w;
						g.DeleteArc(v,w);
						cout<<endl;
						break;
					}
					
				case 8:
					{
						cout<<"�ӵ�һ���������������ȱ���ͼ������Ϊ"<<endl;
						g.DFSTraverse(visit);
						cout<<endl;
						break;
					}
					
					 
				case 9:
					{
						cout<<"�ӵ�һ���������������ȱ���ͼ������Ϊ"<<endl;
						g.BFSTraverse(visit);
						cout<<endl;
					break;
					}
					
					 
				case 10:
					{
						g.DisPlay();
						cout<<endl;
						break;
					}
					
				case 11:
					{
						g.DestroyGraph();
						cout<<endl;
						break;
					}
				case 12:
					cout<<"�������У�Bye-Bye!"<<endl;
					break;
				default:
					cout<<"ѡ�񲻺�������ѡ!"<<endl;
			}//case
		}while(opchoice!=12);
}