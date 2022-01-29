#include<iostream>
#include"assert.h"
#include"sort.h"
using namespace std;

void main()
{
	int file,choice1,choice2,choice3,choice4,choice5;
	SqList<int> sl;
	cout<<"* ��  ��  ��  *"<<endl;
	cout<<"  0 �˳�����"<<endl
		<<"  1 ��������"<<"�������Ӳ˵���"<<endl
		<<"  2 ��������"<<"�������Ӳ˵���"<<endl
		<<"  3 ѡ������"<<"�������Ӳ˵���"<<endl
		<<"  4 �鲢����"<<"�������Ӳ˵���"<<endl
		<<"  5 ��������"<<"�������Ӳ˵���"<<endl; //������������
		cout<<"��ѡ�����˵���";
	cin>>file;
	while(file!=0)
	{
		switch(file)
		{
		case 1:
			cout<<"* ��  ��  ��  �� * "<<endl
				<<"  0 �˳���������"<<endl
				<<"  1 ֱ�Ӳ�������"<<endl
				<<"  2 �۰��������"<<endl
				<<"  3 ���������"<<endl
				<<"  4 ϣ������"<<endl;
			cout<<"��ѡ��������򷽷���";
			cin>>choice1;
			while(choice1!=0)//��ֵ���溯�������仯��������������������������
			{
				switch(choice1)
				{
				case 1:
					CreateSqList(sl);
					InsertSort(sl);
					cout<<"ֱ�Ӳ������������£�"<<endl;
					OutPut(sl);
					delete sl.key;
					break;
				case 2: 
					CreateSqList(sl);
					BInsertSort(sl);
					cout<<"�۰�������������£�"<<endl;
	                OutPut(sl);
					break;
				case 3:
					StaListInsertSort();
					break;
				case 4:
					int *p,n;
					cout<<"��������������"<<endl;
					cin>>n;
					p=new int[n];
					assert(p);
					cout<<"���������������ֵ��"<<endl;
					for(int i=0;i<n;i++)
						cin>>p[i];
                    CreateSqList(sl);
					ShellSort(sl,p,n);
					cout<<"��ϣ���������£�"<<endl;
					OutPut(sl);
					delete p;
					break;

				}
				cout<<"*  ��  ��  ��  ��  *��"<<endl
					<<"  0 �˳���������"<<endl
					<<"  1 ֱ�Ӳ�������"<<endl
					<<"  2 �۰��������"<<endl
					<<"  3 ���������"<<endl
					<<"  4 ϣ������"<<endl;
				cout<<"��ѡ��������򷽷���";
				cin>>choice1;
			}
			break;
		case 2:
			cout<<"* ��  ��  ��  �� *"<<endl
				<<" 0 �˳���������"<<endl
				<<" 1 ��������"<<endl
				<<" 2 ��������"<<endl;
			cout<<"��ѡ��������򷽷���";
			cin>>choice2;
			while(choice2!=0)
			{
				switch(choice2)
				{
				case 1:
					CreateSqList(sl);
					BubbleSort(sl);
					cout<<"�������������£�"<<endl;
					OutPut(sl);
					delete sl.key;
					break;
				case 2:
					CreateSqList(sl);
					QuitSort(sl);
					cout<<"�������������£�"<<endl;
					OutPut(sl);
					break;
				}
               cout<<"* ��  ��  ��  �� *"<<endl
				   <<" 0 �˳���������"<<endl
				   <<" 1 ��������"<<endl
				   <<" 2 ��������"<<endl;
			    cout<<"��ѡ��������򷽷���";
			    cin>>choice2;			
			}
			break;
		case 3:
			cout<<"* ѡ   ��   ��   �� *"<<endl
				<<"  0 �˳�ѡ������"<<endl
				<<"  1 ��ѡ������"<<endl
				<<"  2 ����ѡ������"<<endl
				<<"  3 ������"<<endl;
               cout<<"��ѡ��ѡ�����򷽷���";
			cin>>choice3;
			while(choice3!=0)
			{
				switch(choice3)
				{
				case 1:
					CreateSqList(sl);
					SelectSort(sl);
					cout<<"��ѡ�����������£�"<<endl;
					OutPut(sl);
					delete sl.key;
					break;
				case 2:
					{
						int *date,n;
						cout<<"���������ݸ���"<<endl;
						cin>>n;
						date=new int[n];
						assert(date);
						cout<<"����������"<<endl;
						for(int  i=0;i<n;i++)
							cin>>date[i];
						TreeSort(date,n);
						cout<<"����ѡ�����������£�"<<endl;
						OutPut(date,n);
						delete date;
						break;
					}
				case 3:
					CreateSqList(sl);
					HeapSort(sl);
				    cout<<"�����������£�"<<endl;
					OutPut(sl);
					delete sl.key;
					break;
				}
            cout<<"* ѡ   ��   ��   �� *"<<endl
				<<"  0 �˳�ѡ������"<<endl
				<<"  1 ��ѡ������"<<endl
				<<"  2 ����ѡ������"<<endl
				<<"  3 ������"<<endl;
               cout<<"��ѡ��ѡ�����򷽷���";
			cin>>choice3;
			}
			break;
		case 4:
			cout<<"* ��   ��   ��   ��  *"<<endl
				<<"  0 �˳��鲢����"<<endl
				<<"  1 �鲢����"<<endl;
				cout<<"��ѡ��鲢���򷽷���";
			cin>>choice4;
			while(choice4!=0)
			{
				switch(choice4)
				{
				case 1:
					CreateSqList(sl);
					MergeSort(sl);
					cout<<"�鲢���������£�"<<endl;
					OutPut(sl);
					delete sl.key;
					break;
				}
				cout<<"* ��   ��   ��   ��  *"<<endl
				<<"  0 �˳��鲢����"<<endl
				<<"  1 �鲢����"<<endl;
				cout<<"��ѡ��鲢���򷽷���";
			cin>>choice4;
			}
			break;
		case 5:
			cout<<"* ��  ��  ��  ��  "<<endl
				<<"  0 �˳���������"<<endl
				<<"  1 ��ʽ��������"<<endl;
			cout<<"��ѡ��������򷽷���";
			cin>>choice5;
			while(choice5!=0)
			{
				switch(choice5)
				{
				case 1:
					SLList<int> SL;
					InitSLList(SL);
					RadixSort(SL);
					cout<<"��ʽ�������������£�"<<endl;
					OutPut(SL);
					RelList(SL);
					break;
				}
				cout<<"* ��  ��  ��  ��  "<<endl
				<<"  0 �˳���������"<<endl
				<<"  1 ��ʽ��������"<<endl;
			cout<<"��ѡ��������򷽷���";
			cin>>choice5;
			}
			break;
		}
		cout<<"* ��  ��  ��  *"<<endl;
	    cout<<"  0 �˳�����"<<endl
		    <<"  1 ��������"<<"�������Ӳ˵���"<<endl
		    <<"  2 ��������"<<"�������Ӳ˵���"<<endl
		    <<"  3 ѡ������"<<"�������Ӳ˵���"<<endl
		    <<"  4 �鲢����"<<"�������Ӳ˵���"<<endl
		    <<"  5 ��������"<<"�������Ӳ˵���"<<endl; //������������
		cout<<"��ѡ�����˵���";
	    cin>>file;
	}
	cout<<"�������н�����Bye-Bye!"<<endl;
 }
	


