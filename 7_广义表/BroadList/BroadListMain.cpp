#include <iostream>      //��������������⺯����ͷ�ļ�
#include "BroadList.cpp"  //���ù����ĳ�Ա�����ļ�
#include <string> //����string�⺯����ͷ�ļ�  
using namespace std; //ָ�����������еĳ�����䶼�����ֿռ�std��
char pause;

void main()
{
	GLists<char> *stulists,*stulistsHead,*stulistsTail;//*stulistsAdd;
	string str="(a,b,(a,b))";
	stulists = new GLists<char>(str);  //����str��ʾ�Ĺ����
    cout<<"��ʼ�����Ĺ����Ϊ��"<<"\n";
	stulists->Prnt();
	system("cls");//ִ��ϵͳ����cls������
	int choice;
    do
	{//��ʾ���˵�
		cout<<"1-���������\n";
		cout<<"2-���\n";
		cout<<"3-�����\n";
		cout<<"4-���ͷ\n";
		cout<<"5-���β\n";
		cout<<"6-��ʾ��\n";
		cout<<"7-�˳�\n";
		cout<<"Enter choice:";
	
		cin>>choice;
		switch(choice)
			{
			case 1://���������
				cout<<"��������";
				cin>>str;
				stulists = new GLists<char>(str); 
				cout<<"�Ѵ����Ĺ����Ϊ";
				stulists->Prnt();
			    cin.get(pause);
			    system("pause");
				break;
			case 2://���
                cout<<"\n"<<"�����ĳ���Ϊ��";
	            cout<<stulists->Length();
			    cout<<endl;
				cin.get(pause);
			    system("pause");
				break;
			case 3://�����
                cout<<"\n"<<"���������Ϊ��";
	            cout<<stulists->DepthGList();				
			    cout<<endl;
				cin.get(pause);
				system("pause");
				break;
			case 4://���ͷ
				stulistsHead = stulists->Head();
	            cout<<"\n"<<"������ͷָ��Ϊ��";
	            stulistsHead->Prnt();
				cin.get(pause);
				system("pause");
				break;
			case 5:// ���β
				stulistsTail = stulists->Tail();
	            cout<<"\n"<<"������βָ��Ϊ��";
	            stulistsTail->Prnt();
				cin.get(pause);
				system("pause");
				break;
			case 6://��ʾ�����
				stulists->Prnt();
				cin.get(pause);
				system("pause");
				break;
			case 7://�˳�
				break;
			default://
				cout<<"Invalid choice\n";
				break;
			}
	}while(choice!=7);//
}






