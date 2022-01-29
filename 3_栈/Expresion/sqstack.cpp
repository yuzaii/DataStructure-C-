#include"sqstack.h"
#include<iostream.h>//cout,cin
#include"process.h"//exit()
#include"stdio.h"//EOF,NULL

template <class T>
SqStack<T>::SqStack(int m)
{
	
	base=new T[m];
	if(base==NULL) 
	{
		cout<<"ջ����ʧ�ܣ��˳�!"<<endl;exit(1);
	}
	stacksize=m;
	top=-1;
}

template <class T>
void SqStack<T>::Push(T x)
{
	if(top==stacksize-1) throw "ջ�����޷���ջ";
	top++;
	base[top]=x;
}


template <class T>
T SqStack<T>::Pop()
{
	T x;
	if(top==-1) throw "ջ�գ����ܳ�ջ";
	x=base[top--];
	return x;
}

template <class T>
T SqStack<T>::GetTop()
{
	if(top==-1) throw "ջ�գ�ջ����Ԫ��";
	return base[top];
}

template <class T>
int SqStack<T>::StackEmpty()
{
	if(top==-1) 
		return 0;
	else
		return 1;
}

template <class T>
void SqStack<T>::ClearStack()
{
	top=-1;
}

template <class T>
void SqStack<T>::StackTranverse()
{
	int i=top;
   while(i>=0)
     cout<<base[i--]<<'\t';
   cout<<endl;
 }
