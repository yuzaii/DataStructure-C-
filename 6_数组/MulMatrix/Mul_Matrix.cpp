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

SMatrix MMul(SMatrix ma,SMatrix mb)
{
	SMatrix mc;
	int m1,n1,k1,m2,n2,k2;
	int *num,*rpot,*ctemp;
	int i,j,k,r,t;
	int p,q;
	if(ma.nu!=mb.mu)
	{
		cout<<"A������������B���������������������!"<<endl;
        exit(1);
	}
	m1=ma.mu ;n1=ma.nu ;k1=ma.tu ;
	m2=mb.mu ;n2=mb.nu ;k2=mb.tu ;
	mc.mu =m1;mc.nu =n2;
	r=m1*n2;
	mc.data=new MNode[r];
	num=new int[m2];
	for(i=0;i<m2;i++) num[i]=0;//���з���Ԫ������������ʼ��
	rpot=new int[m2+1];
	rpot[0]=0;
	for(i=0;i<k2;i++)
	{
		k=mb.data[i].i;
		num[k]++;//����B����з���Ԫ����
	}
	for(i=1;i<=m2;i++)//�����B������׸�����Ԫ����Ԫ����е�λ��
		rpot[i]=rpot[i-1]+num[i-1];
	ctemp=new int[n2];
	r=0;//C�ķ���Ԫ����
	p=0;//A����Ԫ��λ��ָ��
	for(i=0;i<m1;i++)
	{
		for(j=0;j<n2;j++) ctemp[j]=0;//cij�ۼ�����ʼ��
		while(ma.data [p].i ==i)
		{
			k=ma.data [p].j ;
			if(k<m2)  t=rpot[k+1];//ȷ��B�е�k�еķ���Ԫ��B����Ԫ����е�λ��
			else t=mb.tu +1;
			for(q=rpot[k];q<t;q++)
			{
				j=mb.data [q].j;
				ctemp[j]+=ma.data [p].e *mb.data [q].e;
			}//for
			p++;
		}//while
		for(j=0;j<n2;j++)
		{
			if(ctemp[j]!=0)
			{
				r++;
				mc.data[r-1].i=i;
				mc.data[r-1].j=j;
				mc.data[r-1].e=ctemp[j];
			}//if
		}//for
	}
	mc.tu =r;
	return mc;
}//MMul

void main()
{
	SMatrix ma,mb,mc;
	int m1=3,n1=4,k1=4;//���˾�������������������Ԫ����
	int m2=4,n2=2,k2=4;//������������������������Ԫ����
	int da[4][3]={{0,0,3},{0,3,7},{1,3,-1},{2,1,2}};//ma��ķ���Ԫ
	int db[4][3]={{0,1,1},{1,0,2},{2,0,3},{2,1,4}};//mb��ķ���Ԫ
	ma=MCreate(da,m1,n1,k1);//������Ԫ��˳��洢��ma��
	cout<<"ma="<<endl;
	MDisp(ma);//��ʾma��
	mb=MCreate(db,m2,n2,k2);//������Ԫ��˳��洢��mb��
	cout<<"mb="<<endl;
	MDisp(mb);//��ʾmb��
	if(ma.nu !=mb.mu )
	{
		cout<<"A��������������B�����������������"<<endl;
		exit(1);
	}
	if(ma.tu ==0||mb.tu ==0)
	{
		cout<<"CΪ����"<<endl;
		exit(1);
	}
	mc=MMul(ma,mb);//mcΪma��mb�ĳ˻�
	cout<<"mc="<<endl;
	MDisp(mc);//���������
}//main

