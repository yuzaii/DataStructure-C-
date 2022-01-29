#include<iostream.h>//cout,cin
#include"process.h"//exit()
#include"stdio.h"//EOF,NULL
#include "SqList.h"
char pause;
typedef int T;

 //������
int main()
{
	int i;
	T e;
	SqList<int> L(20);//��������Ϊ20��Ԫ������Ϊ���͵Ŀ�˳���
	system("cls");//ִ��ϵͳ����cls������
	int choice;
    do
	{//��ʾ���˵�
		cout<<"1-����˳���\n";
		cout<<"2-�������i��λ�ò���Ԫ��\n";
		cout<<"3-ɾ��˳����е�i��λ�õ�Ԫ��\n";
		cout<<"4-���ص�i��Ԫ�ص�ֵ\n";
		cout<<"5-Ԫ�ض�λ\n";
		cout<<"6-��ձ�\n";
		cout<<"7-����\n";
		cout<<"8-�����\n";	
		cout<<"9-���Ա�\n";
		cout<<"10-��ʾ����\n";
		cout<<"11-�˳�\n";
		cout<<"Enter choice:";
	
		cin>>choice;
		switch(choice)
			{
			case 1://������ 
				cout<<"������Ҫ������˳�����Ԫ�ظ���:";
				cin>>i;
				cout<<endl;
				try
				{
					L.CreateList(i);
				}
				catch(char *err)
					{
					 cout<<err<<endl;
					 }
				break;
			case 2://Ԫ�ز���
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
			case 3://Ԫ��ɾ�� 
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
			case 4://���ص�i��Ԫ��ֵ
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
			case 5:// ��ֵ����Ԫ�ز�ѯ
				cout<<"������Ҫ��ѯ��Ԫ��ֵ:";
				cin>>e;//
				i=L.Locate(e);
				cout<<"��ѯԪ��"<<e<<"λ���ڱ��е�λ��Ϊ:"<<i<<endl;
				cin.get(pause);
				system("pause");
				break;
			case 6://��ձ�
				L.Clear();
				cout<<"�������"<<endl;
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
			case 8://�����
				i=L.Full();
				if(i) 
					cout<<"����"<<endl;
				else
					cout<<"��δ��"<<endl;
				cin.get(pause);
				system("pause");
				break;
			case 9://��� 
				i=L.Length();
				cout<<"��Ϊ:"<<i<<endl;
				cin.get(pause);
				system("pause");
				break;
			case 10://������ʾ��
				L.ListDisp();
				cout<<endl;
				cin.get(pause);
				system("pause");
				break;	
			case 11://�˳�
				cout<<"��������"<<endl;
                                break;
			default://�Ƿ�ѡ��
				cout<<"Invalid choice\n";
				break;
			}
	}while(choice!=11);
	return 0;
}//end of main function