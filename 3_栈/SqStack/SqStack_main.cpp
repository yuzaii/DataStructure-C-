#include<iostream.h>//cout,cin
#include"process.h"//exit()
#include"stdio.h"//EOF,NULL
#include"SqStack.h"
char pause;
 //������
int main()
{
	int e;
	SqStack<int> s(20);//��������Ϊ20��Ԫ������Ϊ���͵Ŀ�ջ
	system("cls");//ִ��ϵͳ����cls������
	int choice;
    do
	{//��ʾ���˵�
		cout<<"1-Ԫ����ջ\n";
		cout<<"2-Ԫ�س�ջ\n";
		cout<<"3-ȡջ��Ԫ��\n";
		cout<<"4-��ջ��\n";
        cout<<"5-��ջ��\n";
		cout<<"6-��ʾջԪ��\n";
		cout<<"7-��ʾջ��ָ��\n";
		cout<<"8-�˳�\n";
		cout<<"Enter choice:";
		cin>>choice;
		switch(choice)
			{
			case 1://��ջ
				cout<<"���������Ԫ�ص�ֵ:";
				cin>>e;//
				cout<<endl;
				try
					{
					s.Push(e);
					}
				catch(char *err)
					{
					 cout<<err<<endl;
					 }
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
		case 7://��ʾջ��ָ��
			s.StackTop ();
			break;
		case 8://
			 cout<<"�������,Bye-Bye!"<<endl;
		    break;
	    default:
		     cout<<"Invalid choice\n";
		break;
		}
	cout<<endl;
	}while(choice!=8);
	return 0;
}














