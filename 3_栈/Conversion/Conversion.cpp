#include<iostream.h>//cout,cin
#include"process.h"//exit()
#include"stdio.h"//EOF,NULL
#include"SqStack.h"

template<class T>
void convert(T n,T m)
{//��ʮ������nת��Ϊm������
	T e;
	char c;
	SqStack<int> s(10);
	cout<<"��ת����ʮ�������ǣ�"<<n<<endl;
	while(n)
	{
		try
		{ 
			s.Push(n%m);}
		catch(char *err)
			{ cout<<err<<endl;	 }
		n=n/m;
	}
	cout<<"ת��Ϊ"<<m<<"������Ϊ��";
	while(!s.StackEmpty())
	{
		try
			{    e=s.Pop ();
		         if(e<10)
					 cout<<e<<'\t';  
				 else 
				 {
					 c='A'+e-10;
					 cout<<c<<'\t'; 
				 }
		}
	    catch(char *err)
		   {   cout<<err<<endl;  }
	}//
	cout<<endl;
}
void main()
{
	int n,m;//�ֱ��ű�ת��������ת������
	char ans; //��������������Ƿ������Ӧ��
	int flag=1;//�����������Ƿ�����ı�־
	while(flag)
	{
		cout<<"������ת����ʮ������: ";
	    cin>>n;
	    cout<<"������ת��������: ";
	    cin>>m;
	    convert(n,m);
		cout<<"������(Y/N)��"<<endl;
		cin>>ans;
		if(ans=='Y'||ans=='y') 
			flag=1;
		else 
		{
			flag=0;
			cout<<"�������н�����BYe-Bye!"<<endl;
		}
	}//while
}//main