#include<iostream.h>//cout,cin
#include"process.h"//exit()
#include"stdio.h"//EOF,NULL
#include "iostream.h"
#include "CirQueue.h"

char pause;

 //������
int main()
{
	int e;
	CirQueue<int> q(10);
	system("cls");//ִ��ϵͳ����cls������
	int choice;
    do
	{//��ʾ���˵�
		cout<<"1-Ԫ�����\n";
		cout<<"2-Ԫ�س���\n";
		cout<<"3-ȡ��ͷԪ��\n";
		cout<<"4-ȡ��βԪ��\n";
		cout<<"5-�öӿ�\n";
        cout<<"6-��ӿ�\n";
		cout<<"7-�����\n";
		cout<<"8-��ʾ�ס�βλ��\n";
		cout<<"9-�����Ԫ��\n";
		cout<<"10-�˳�\n";
		cout<<"Enter choice:";
		
		cin>>choice;
		switch(choice)
			{
			case 1://���
				cout<<"���������Ԫ�ص�ֵ:";
				cin>>e;//
				cout<<endl;
				q.EnQueue(e);
                cout<<e<<" ��ӳɹ�!"<<endl;
				cin.get(pause);
                system("pause");
				break;
	        case 2://����
		        try
					{
		             e=q.DeQueue();
		             cout<<"����Ԫ��Ϊ��"<<e<<endl;
					 }
	           catch(char *err)
				   {
		            cout<<err<<endl;
					}
		       cin.get(pause);
               system("pause");
		       break;
	       case 3://��ȡ��ͷԪ��
		       try
				   {
				   e=q.GetHead();
				   cout<<"��ͷԪ��Ϊ��"<<e<<endl;
				   }
			   catch(char *err)
				   {
				    cout<<err<<endl;
					}
			   cin.get(pause);
			   system("pause");
			   break;
		   case 4://��ȡ��βԪ��
		       try
				   {
				   e=q.GetLast();
				   cout<<"��βԪ��Ϊ��"<<e<<endl;
				   }
			   catch(char *err)
				   {
				    cout<<err<<endl;
					}
			   cin.get(pause);
			   system("pause");
			   break;
	       case 5://��ն� 
		       q.ClearQueue();
		       cin.get(pause);
               system("pause");
		       break;
	       case 6://��ӿ�
		      if(q.QueueEmpty())
				  cout<<"�ӿ�"<<endl;
		      else
			      cout<<"�Ӳ���"<<endl;
		      cin.get(pause);
              system("pause");
		      break;
	       case 7://����� 
		      if(q.QueueFull())
				  cout<<"����"<<endl;
		      else
			      cout<<"�Ӳ���"<<endl;
		          cin.get(pause);
                  system("pause");
		          break;
	        case 8://��ʾ�ס�βλ��
				q.Pointer();
				cin.get(pause);
                system("pause");
				break;
		   case 9://������ 
		       q.QueueTranverse();
		       cin.get(pause);
               system("pause");
		       break;
	       case 10://�˳�
		       break;
	       default:
		     cout<<"Invalid choice\n";
		     break;
		}
	}while(choice!=10);
	return 0;
}//end of main function