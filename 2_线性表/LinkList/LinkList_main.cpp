#include<iostream.h>//cout,cin
#include"process.h"//exit()
#include"stdio.h"//EOF,NULL
#include "LinkList.h"
char pause;
typedef  int T;
 //������
int main()
{
	int i;
	T e,prior_e;
	LinkList<int> L;//
	system("cls");//ִ��ϵͳ����cls������
	int choice;
    do
	{//��ʾ���˵�
		cout<<"1-��������\n";
		cout<<"2-��λ�����\n";
		cout<<"3-��λ��ɾ��\n";
		cout<<"4-��λ�����\n";
		cout<<"5-��ֵ����\n";
		cout<<"6-��ֵ��ǰ��\n";
		cout<<"7-����\n";
		cout<<"8-���\n";
		cout<<"9-��ʾ����\n";
		cout<<"10-�˳�\n";
		cout<<"Enter choice:";
		cin>>choice;
		switch(choice)
			{
			case 1://��������
				cout<<"������Ҫ������������Ԫ�ظ���:";
				cin>>i;
				cout<<endl;
				L.CreateList(i);
				break;
			case 2://��ָ��λ�ò���Ԫ��
				cout<<"���������λ��:";
				cin>>i;
				cout<<endl;
				cout<<"���������Ԫ�ص�ֵ:";
				cin>>e;
				cout<<endl;
				try
				{
					L.Insert(i,e);
				}
				catch(char *err)
					{
					 cout<<err<<endl;
					 }
				break;
			case 3://ɾ��ָ��λ��Ԫ��
				cout<<"������ɾ��λ��:";
				cin>>i;
				cout<<endl;
				try
				{
					e=L.Delete(i);
					cout<<"��ɾ��Ԫ��Ϊ��"<<e<<endl;
				}
				catch(char *err)
					{
					 cout<<err<<endl;
					 }
				
				cin.get(pause);
				system("pause");
				break;
			case 4://��λ�����
				cout<<"������Ҫ��ѯ��Ԫ��λ��:";
				cin>>i;
				try
				{
					e=L.GetElem(i);
					cout<<"��"<<i<<"��Ԫ��ֵΪ��"<<e<<endl;
				}
				catch(char *err)
					{
					 cout<<err<<endl;
					 }
				cin.get(pause);
				system("pause");
				break;
			case 5:// ��ֵ����
				cout<<"������Ҫ��ѯ��Ԫ��ֵ:";
				cin>>e;//
				i=L.Locate(e);
				cout<<"��ѯԪ��"<<e<<"λ�������λ��Ϊ:"<<i<<endl;
				cin.get(pause);
				system("pause");
				break;
			case 6://��Ԫ��ǰ��
				cout<<"������Ҫ��ǰ��Ԫ�ص�ֵ:";
				cin>>e;
				try
				{
					prior_e=L.prior(e);
					cout<<"Ԫ��"<<e<<"��ǰ��ֵΪ��"<<prior_e<<endl;
				}
				catch(char *err)
					{
					 cout<<err<<endl;
					 }
				cin.get(pause);
				system("pause");
				break;
			case 7://����
				i=L.Empty();
				if(i) 
					cout<<"���"<<endl;
				else
					cout<<"����"<<endl;
				cin.get(pause);
				system("pause");
				break;
			case 8://���
				cout<<"������Ϊ��"<<L.Length()<<endl;
				cin.get(pause);
				system("pause");
				break;	
			case 9://��ʾ��
				L.ListDisplay();
				cout<<endl;
				cin.get(pause);
				system("pause");
				break;	
			case 10://�˳�
				cout<<"��������"<<endl;
				break;
			default://
				cout<<"Invalid choice\n";
				break;
			}
	}while(choice!=10);//
	return 0;
}