#include<iostream.h>//cout,cin
#include"process.h"//exit()
#include"stdio.h"//EOF,NULL
#include "LinkStack.h"
char pause;
 //������
int main()
{
	int e;
	LinkStack<int> s;
	system("cls");//ִ��ϵͳ����cls������
	int choice;
    do
	{//��ʾ���˵�
		cout<<"1-Ԫ����ջ\n";
		cout<<"2-Ԫ�س�ջ\n";
		cout<<"3-ȡջ��Ԫ��\n";
		cout<<"4-��ջ��\n";
        cout<<"5-��ջ��\n";
		cout<<"6-���ջԪ��\n";
		cout<<"7-�˳�\n";
		cout<<"Enter choice:";
		
		cin>>choice;
		switch(choice)
			{
			case 1://��ջ
				cout<<"���������Ԫ�ص�ֵ:";
				cin>>e;//
				cout<<endl;
				s.Push(e);
				cin.get(pause);
                system("pause");
				break;
	       case 2://��ջ
		        try
					{
		             e=s.Pop ();
		             cout<<"��ջԪ��Ϊ��"<<e<<endl;
					 }
	           catch(char *err)
				   {
		            cout<<err<<endl;
					}
		       cin.get(pause);
               system("pause");
		       break;
	      case 3://��ȡջ��Ԫ��
		       try
				   {
				   e=s.GetTop ();
				   cout<<"ջ��Ԫ��Ϊ��"<<e<<endl;
				   }
			   catch(char *err)
				   {
				    cout<<err<<endl;
					}
			   cin.get(pause);
			   system("pause");
			   break;
	      case 4://���ջ 
		       s.ClearStack();
		       cin.get(pause);
               system("pause");
		       break;
	     case 5://��ջ��
		      if(s.StackEmpty())
				  cout<<"ջ��"<<endl;
		      else
			      cout<<"ջ����"<<endl;
		      cin.get(pause);
              system("pause");
		      break;
	    case 6://����ջ 
		     s.StackTranverse();
		     cin.get(pause);
             system("pause");
		     break;
	    case 7://�˳�
		    cout<<"�������У�Bye-Bye!"<<endl;
			break;
	    default:
		     cout<<"Invalid choice\n";
		break;
		}
	}while(choice!=7);
	return 0;
}//end of main function














