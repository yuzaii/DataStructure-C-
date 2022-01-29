#include <iostream>
#include <cstdlib>
#include <windows.h>
#include "LinkQueue.h"
using namespace std;
#include "CTree.h"
int main()
{
	CTree<char> PT; 
	CTree<char> c;
	int op;
	do
	{
		cout<<"\t-----���˵�------"<<endl;
		cout<<"\t0 - �˳� "<<endl;
		cout<<"\t1 - ������ "<<endl;
		cout<<"\t2 - ���һ���� "<<endl;
		cout<<"\t3 - �ж����Ƿ�Ϊ�� "<<endl;
		cout<<"\t4 - ����������� "<<endl;
		cout<<"\t5 - ��������ֵ "<<endl;
		cout<<"\t6 - ������ţ����ؽ��ֵ "<<endl;
		cout<<"\t7 - �޸Ľ��ֵ "<<endl;
		cout<<"\t8 - ����˫�׽���ֵ "<<endl;
		cout<<"\t9 - ��������ߵĺ���ֵ "<<endl;
		cout<<"\t10 - �������ֵܵ�ֵ  "<<endl;
		cout<<"\t11 - �����   "<<endl;
		cout<<"\t12 - �������  "<<endl;
		cout<<"\t13 - ɾ������  "<<endl;
		cout<<"\t14 - ������  "<<endl;
		cout<<"\t��ѡ�������[ ]";
		cout<<"\b\b";
		cin>>op;
		switch(op)
		{
		case 0:
			cout<<"�������У�Bye-Bye!"<<endl;
			break;
		case 1://����һ����
			PT.CreateTree('#');
			break;
		case 2://���һ����
			PT.ClearTree();
			system("pause");
			break;
		case 3://�ж����Ƿ�Ϊ��
			cout<<(PT.IsEmpty()==true?"��Ϊ��":"����Ϊ��")<<endl;
			system("pause");
			break;
		case 4://�������
			cout<<"�������Ϊ��"<<PT.TreeDepth()<<endl;
			system("pause");
			break;
		case 5://�������Ľ��
			if(PT.Root()==0)cout<<"��Ϊ�գ�"<<endl;
			else cout<<"��������ֵΪ��"<<PT.Root()<<endl;
			system("pause");
			break;
		case 6://���ݽ������,���ؽ��ֵ
			cout<<"�����������ţ�";
			int index;
			cin>>index;
			if(PT.Value(index)!=0)
			{
				cout<<"���Ϊ"<<index<<"�Ľ��ֵΪ"<<PT.Value(index)<<endl;
			}
			else
			{
				cout<<"����ʧ�ܣ�������������"<<endl;
			}
			system("pause");
			break;
		case 7://�޸Ľ��ֵ
			char cur_e;
			cout<<"������Ҫ�ı�Ľ��ֵ��";
			cin>>cur_e;
			char value;
			cout<<"������ı���ֵ";
			cin>>value;
			if(PT.Assign(cur_e,value)==true)cout<<"�����ɹ���"<<endl;
			else cout<<"����ʧ�ܣ�"<<endl;
			system("pause");
			break;
		case 8://˫�׽��
			char cur_e2;
			cout<<"���������ֵ��";
			cin>>cur_e2;
			if(PT.parent(cur_e2)==0)
			{
				cout<<"�ý�㲻���ڻ�˽���Ǹ���㣡"<<endl;
			}
			else
			{
				cout<<"�ý���˫�׽���ǣ�"<<PT.parent(cur_e2)<<endl;
			}
			system("pause");
			break;
		case 9://���ظ�������������
			char cur_e3;
			cout<<"���������ֵ��";
			cin>>cur_e3;
			if(PT.LeftChild(cur_e3))
			{
				cout<<"��� "<<cur_e3<<" �������ӽ��Ϊ��"<<PT.LeftChild(cur_e3)<<endl;
			}
			else
			{
				cout<<"�ý����Ҷ�ӽ�㣬��ý�㲻���ڣ�"<<endl;
			}
			system("pause");
			break;
		case 10://���ظ���������ֵܽ��ֵ
			char cur_e4;
			cout<<"���������ֵ��";
			cin>>cur_e4;
			if(PT.RightSibling(cur_e4))
			{
				cout<<"�ý������ֵܽ��ֵΪ��"<<PT.RightSibling(cur_e4)<<endl;
			}
			else
			{
				cout<<"�ý�㲻���ڣ���ý��û�����ֵܣ�"<<endl;
			}
			system("pause");
			break;
		case 11:
			PT.Print();
			system("pause");
			break;
		case 12:
			
			c.CreateTree('#');
			cout<<"����c���뵽��ǰ���У��������λ��˫�׽��ֵ�Լ�����λ��";
			int insertPos;
			char p;
			cin>>p>>insertPos;

			PT.InsertChild(p,insertPos,c.GetTree());
			break;
		case 13:
			char par;
			cout<<"������Ҫɾ�����˫�׽��ֵ��";
			cin>>par;
			cout<<"������ɾ�����������У�";
			int pos;
			cin>>pos;
			PT.DeleteChild(par,pos);
			break;
		case 14://��α���������
			PT.TraverseTree();
			system("pause");
			break;
		default:
			break;
		}
	}while(op!=0);
	return 0;
}