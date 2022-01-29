#include<iostream.h>//cout,cin
#include"process.h"//exit()
#include"stdio.h"//EOF,NULL

typedef struct MNode
{ 
	int i,j;//�кţ��к�
	int e;//����Ԫ
}MNode;

typedef struct
{
	int mu,nu,tu;// ����������������Ԫ����
	MNode *data;// ��Ԫ���
}SMatrix;

SMatrix MCreate(int d[][3],int m,int n,int k)
{//����Ԫ��Ķ�ά��������������ϡ��洢����
	SMatrix M={m,n,k,NULL};
	if(k!=0) 
		M.data=new MNode[k];
	for(int i=0;i<k;i++)
	{
		M.data [i].i=d[i][0];
	    M.data [i].j=d[i][1];
		M.data [i].e=d[i][2];
	}
	return M;
}//


void MDisp(SMatrix a)
{
	MNode p;
	int i,j,k=0,c=0;
	p=a.data[k];
	for(i=0;i<a.mu;i++)
	{
		for(j=0;j<a.nu;j++)
		{
			if(k<a.tu && p.i ==i && p.j ==j)  
			{
				cout<<'\t'<<p.e;
				k++;
				if(k<a.tu ) p=a.data[k];
			}
			else
			{
				cout<<'\t'<<c;
			}
		}//for
		cout<<endl;
	}//for
}//MatrixDisp

void MatrixTrans(SMatrix A,SMatrix &B)
{//
	int col,k,p,q;
	int *num,*cpot;
	num= new int[B.nu];
	cpot=new int [B.nu];
	if(B.tu)// ����Ԫ������Ϊ�㣬ʵʩת��
	{
		for(col=0;col<A.tu ;++col)//A��ÿһ�з���Ԫ������ʼ��Ϊ0
			num[col]=0;
		for(k=0;k<A.tu ;++k)/�����A��ÿһ�з���Ԫ����
			++num[A.data [k].j];
		cpot[0]=0;//A�е�0���׸�����Ԫ��B�е��±�
		for(col=1;col<=A.nu ;++col)// ��A��ÿһ���׸�����Ԫ��B�е��±�
			cpot[col]=cpot[col-1]+num[col-1];
		for(p=0;p<A.tu ;++p)//ɨ��A����Ԫ���
		{
			col=A.data [p].j ;//��ǰ��Ԫ���к�
			q=cpot[col];//��ǰ��Ԫ����B�е��±�
			B.data[q].i=A.data[p].j;
			B.data [q].j =A.data [p].i;
			B.data [q].e =A.data [p].e;
			++cpot[col];// Ԥ��ͬһ����һ����Ԫ����B�е��±�
		}//for
	}//if
}//



void main()
{
	SMatrix ma,mb;
	int m1=4,n1=6,k1=6;//���˾�������������������Ԫ����
	int da[6][3]={{0,2,11},{0,4,12},{1,3,22},{2,1,31},{2,3,32},{3,0,41}};//ma��ķ���Ԫ
	ma=MCreate(da,m1,n1,k1);//������Ԫ��˳��洢��ma��
	cout<<"ma="<<endl;
	MDisp(ma);//��ʾma��
	mb.mu =ma.nu ;
	mb.nu=ma.mu ;
	mb.tu=ma.tu;
	mb.data=new MNode[ma.tu ];
	MatrixTrans(ma,mb);
	cout<<"mb="<<endl;
	MDisp(mb);
}//