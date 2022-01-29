#include<iostream.h>//cout,cin
#include"process.h"//exit()
#define Max 20
typedef struct 
{ 
	float coef;
	int exp;
}PolyArray[Max];

struct PolyNode
{
   float coef;
   int exp;
   PolyNode *next;
};

class Poly
{
private:
	PolyNode *head;
public:
	Poly();//���캯���������ն���ʽ
	~Poly();//�����������ͷŶ���ʽ
	void Create(PolyArray a,int n);//�������룬��������ʽ����
	void Disp();//����ʽ��ʾ
	void Sort();//���������
	void Add (Poly LB);//����ʽ��
    //void Substract(PolyNode * hbQ);//����ʽ��
    //void Multiply(PolyNode * hb);//����ʽ��
};

Poly::Poly()
{ //����һ�ն���ʽ
	head=new PolyNode;
	head->next=NULL;
}

Poly::~Poly()
{//�ͷŶ���ʽ��ռ�ռ�
	PolyNode *p;
	while(head!=NULL)
	{//��ͷ��㿪ʼ�������ͷŽ��
		p=head;
		head=head->next;
	    delete p;
	}
	head=NULL;//ͷ���ָ���
}

void Poly::Disp ()
{
	PolyNode *p;
	p=head->next;
	while(p!=NULL)
	{
		cout<<p->coef <<"x^"<<p->exp<<'\t' ;
		p=p->next ;
	}
	cout<<endl;
}

void Poly::Create (PolyArray a,int n)
{//�ɶ���ʽ���鴴������ʽ����
	PolyNode *s,*r;
	int i;
	r=head;
	for(i=0;i<n;i++)
	{
		s=new PolyNode;
		s->coef =a[i].coef;
		s->exp =a[i].exp;
		s->next =NULL;
		r->next =s;
		r=s;
	}
}

void Poly::Sort()
{
	PolyNode *p,*q,*r;
	p=head->next ;
	if(p!=NULL)
	{
		r=p->next ;//rָ��p�ĺ�̽��
		p->next =NULL;//����ֻ��һ�����������
		p=r;
		while(p!=NULL)
		{
			r=p->next;
			q=head;
			while(q->next!=NULL && q->next ->exp < p->exp )
				q=q->next ;//��������в���*p��ǰ�����*q
			p->next =q->next ;//*p���뵽*q֮��
			q->next =p;
			p=r;
		}
	}
}

void Poly::Add(Poly LB)
{ 
	float sum;
	PolyNode *pa,*pb,*qa,*qb;
    pa=head;
	qa=pa->next;
    pb=LB.head ;
	qb=pb->next;
	while (qa!=NULL && qb!=NULL )
   {
	   if (qa->exp < qb->exp ) 
	   {//
		   pa=qa;qa=qa->next;   }
	   else if ( qa->exp > qb->exp )
	   { //
		   pb->next =qb->next; 
		   qb->next=qa; 
		   pa->next=qb; 
		   pa=qb;
		   qb=pb->next; 
	   }
	   else
	   {//
		   sum=qa->coef+qb->coef;
		   if (sum==0 )  
		   {//
			   pa->next=qa->next;
			   delete qa;
			   qa=pa->next;
			   pb->next=qb->next;
			   delete qb;
			   qb=pb->next;
			   }
            else 
			{
                qa->coef=sum;
                pa=qa; qa=qa->next;
                pb->next=qb->next;
                delete qb;
                qb=pb->next;
             }
          }
   }//while
   if(qb!=NULL) 
     qa->next=qb;//
}//Add

void main()
{
	Poly LA,LB;
	PolyArray a={{7.0,0},{3.0,1},{9.0,8},{5.0,16}};
	PolyArray b={{8.0,1},{22,7},{-9.0,8}};
	LA.Create (a,4);
	LB.Create (b,3);
	cout<<"ԭ����ʽAΪ��";
	LA.Disp ();
	cout<<"ԭ����ʽBΪ��";
	LB.Disp ();
	LA.Sort ();
	LB.Sort ();
	cout<<"�������ʽAΪ��";
	LA.Disp ();
	cout<<"�������ʽBΪ��";
	LB.Disp();
	LA.Add (LB);
	cout<<"�Ͷ���ʽΪ��";
	LA.Disp ();
}
