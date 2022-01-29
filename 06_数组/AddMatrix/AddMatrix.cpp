#include<iostream.h>//cout,cin
#include"process.h"//exit()
#include"stdio.h"//EOF,NULL

typedef struct MNode
{ 
	int i,j;//�кţ��к�
	int e;//����Ԫ
	MNode *next;// ָ��ͬ����һ�����
}MNode,*MLink;

typedef struct
{
	int mu,nu,tu;// ����������������Ԫ����
	MLink *rops;// ��Ÿ��������ͷָ��
}LMatrix;

int cmp(int a,int b)
{//�кűȽ�
	if(a<b) return -1;
	else if(a=b) return 0;
	else return 1;
}

void NodeCopy(MNode * &s,MNode * x)
{//��㿽��
	s->e=x->e;s->i=x->i;s->j=x->j;
}

void AddNode(MNode * &lp,MNode * &lq,MNode *s)
{
	MNode *p;
	p=new MNode;
	NodeCopy(p,s);
	p->next=NULL;
	if(lp==NULL)//��Ԫ���
	{
		lp=p;
		lq=p;
	}
	else//����Ԫ���
	{
		 lq->next =p;
		 lq=p;
	 }
}//

 
 LMatrix MAdd(LMatrix ma,LMatrix mb)
{
	LMatrix mc;
	MNode *pa,*pb,*pc;//�ֱ�ָ�򱻼������������;�����������Ԫ���
	MNode *s;//
	int i,sum;
	int m,n;//����������
	int flag=1;
	m=ma.mu ;
	n=ma.nu ;
	mc.mu=m;mc.nu=n;mc.tu=0;mc.rops=NULL;
	if(mc.rops) delete [] mc.rops;
	mc.rops=new MLink [m];
	for(i=0;i<m;i++)
		mc.rops[i]=NULL;//C��ָ��������ʼ��
	for(i=0;i<m;i++)
	{
		pa=ma.rops[i];
	    pb=mb.rops[i];
		pc=mc.rops[i];
		while(pa && pb)//���Ӿ��󡢼Ӿ�����������
		{
			flag=1;
			switch(cmp(pa->j,pb->j))//�����Ƚ�
				{
				case -1:
					s=new MNode;//
					NodeCopy(s,pa);
					s->next=NULL;
					pa=pa->next;
					break;
		        case 0:
					sum=pa->e+pb->e;
					if(sum==0)  flag=0;
					else
					{
						s=new MNode;
						NodeCopy(s,pa);
						s->e=sum;
					    s->next=NULL;
					}
					pa=pa->next;pb=pb->next;//pa,pb����
			        break;
		        case 1:
					s=new MNode;
                    NodeCopy(s,pb);//����pb��ָ���
					pb=pb->next;//pb����
					s->next=NULL;
					break;
			}//switch
			if(flag)//���½������
			{
				mc.tu++;
				AddNode(mc.rops [i],pc,s);
			}
		}//while
		if(pa)//pa���գ�����paʣ�������;�����
		{
			while(pa)
			{
				NodeCopy(s,pa);pa=pa->next;
				AddNode(mc.rops [i],pc,s);
			}//while
		}//if(pa)
		if(pb)        //pb���գ�����pbʣ�������;�����
		{
			while(pb)
			{
				NodeCopy(s,pb);pb=pb->next ;
				AddNode(mc.rops [i],pc,s);
			}//while
		}//if(pb)
	}//for
	return mc;
}//MAdd

void MDisp(LMatrix a)
{
	MNode *p;
	int i,j,c=0;
	for(i=0;i<a.mu;i++)
	{
		p=a.rops[i];
		for(j=0;j<a.nu;j++)
		{
			if(p==NULL)
				cout<<'\t'<<c;
			else if (j<p->j)
				cout<<'\t'<<c;
			else
			{
				cout<<'\t'<<p->e;
				p=p->next;
			}
		}//for
		cout<<endl;
	}//for
}//MatrixDisp

LMatrix MCreate(int d[][3],int m,int n,int k)
{//����Ԫ��Ķ�ά��������������ϡ��洢����
	LMatrix M={m,n,k,NULL};
	int i,r1,r2;
	MNode *s,*p;//����ָ��
	if(M.rops) delete [] M.rops;
	M.rops=new MLink[m];
	for(i=0;i<m;i++)
		M.rops[i]=NULL;
	r1=m;
	p=M.rops[r1];//
	for(i=0;i<k;i++)//ɨ�����Ԫ����
	{
		s=new MNode;
		s->i=d[i][0];
		s->j=d[i][1];
		s->e=d[i][2];
		r2=s->i;//����Ԫ������
		if(r2!=r1) //���������1�����
		{
			M.rops[r2]=s;
			s->next=NULL;
			p=s;
			r1=r2;
		}
		else//�����������Ԫ���
		{
			s->next=p->next;
			p->next =s;
			p=s;
		}
	}//for
	return M;
}//MCreate
		

void main()
{
	//MNode *p;
	LMatrix ma,mb,mc;
	int m=4,n=6;//����������
	int da[5][3]={{0,1,3},{1,1,2},{1,3,5},{3,0,9},{3,5,1}};
	int db[4][3]={{0,2,7},{1,1,6},{1,3,-5},{2,1,4}};
	ma=MCreate(da,4,6,5);
	cout<<"ma="<<endl;
	MDisp(ma);
	mb=MCreate(db,4,6,4);
	cout<<"mb="<<endl;
	MDisp(mb);
	mc=MAdd(ma,mb);
	cout<<"mc=ma+mb="<<endl;
	MDisp(mc);
}