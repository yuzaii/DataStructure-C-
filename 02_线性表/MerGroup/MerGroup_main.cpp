#include<iostream.h>//cout,cin
#include"process.h"//exit()
#include "LinkList.h"
typedef  int T;

void main()
{
	T e;
    LinkList<int> La,Lb;
	int la_len,lb_len;
	int i;
	cout<<"������Ҫ����A������Ԫ�ظ���:";
	cin>>la_len;//������������������Ԫ�صĸ���
	cout<<endl;
	La.CreateList(la_len);
	cout<<"������Ҫ������B������Ԫ�ظ���:";
	cin>>lb_len;//������������������Ԫ�صĸ���
	cout<<endl;
	Lb.CreateList(lb_len);
	cout<<endl;
	cout<<"La:"<<"\t";
	La.ListDisplay();
	cout<<"Lb:"<<"\t";
	Lb.ListDisplay();
		for(i=1;i<=lb_len;i++)
	{
		try
		{
			e=Lb.GetElem(i);}
		catch(char *err)
					{
					 cout<<err<<endl;
					 }
		if(!La.Locate(e))
			try
				{
					La.Insert(++la_len,e);
				}
				catch(char *err)
					{
					 cout<<err<<endl;
					 }
			}//for
    cout<<"union:"<<"\t";
	La.ListDisplay();
	cout<<endl;
}//end main



	
	
