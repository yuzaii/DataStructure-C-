#include<iostream.h>//cout,cin

void ArrayCreat(int * &A,int n)
{//����һ����������
	A=new int[n];
	cout<<"��������"<<n<<"��Ԫ��ֵ��"<<endl;
	for(int i=0;i<n;i++)
		cin>>A[i];
}//ArrayCreat


int MinNum(int A[],int n)
{
	int min;//�����С��
	min=A[0];
	for(int i=1;i<n;i++)
	{
		if(A[i]<min) min=A[i];
	}
	return min;
}
void ArrayDisp(int A[],int n)
{//����Ԫ�����
	for(int i=0;i<n;i++)
		cout<<A[i]<<'\t';
	cout<<endl;
}
void main()
{//
	int n;//Ԫ�ظ���
	int *A;
	cout<<"����Ҫ����������Ԫ�ظ�����";
	cin>>n;
	ArrayCreat(A,n);//���ô�����������������
	cout<<"�Ѵ���������Ϊ��"<<endl;
	ArrayDisp(A,n);//������ʾ�������������
	cout<<"���������СԪ��Ϊ��"<<MinNum(A,n)<<endl;
}
