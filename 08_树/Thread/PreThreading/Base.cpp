#include<iostream>
using namespace std;
//���������������Ľ������
template <class T>
struct BiThrNode
{
	T data;				//������
	int lflag;			//���־��
	int rflag;			//�ұ�־��
	BiThrNode<T> *lchild;	//��ָ����
	BiThrNode<T> *rchild;	//��ָ����
};
//--------------------------------------------------------------------------------
//����
template <class T>
class CThr
{
								
public:
	BiThrNode<T>*BT;	//�������ĸ����ָ��										
	CThr(){BT=NULL;};						//���캯�����Զ���������г�ʼ��
	~CThr();								//�����������ͷŽ��ռ�õĿռ�
	void DeleteNode(){Clear(BT,0);}				//�ͷŽ��ռ�
	void Clear(BiThrNode<T>*bt,int flag);
	void CreateBiTree(T end);					//������������
	void create(BiThrNode<T>*p,int flag,T end);	
	BiThrNode<T>* GetRoot()
	{
		return BT;
	}
};

//--------------------------------------------------------------------------------
template <class T>
CThr<T>::~CThr()
{
	DeleteNode();
	BT=NULL;
}
//------------------------------------------------------------------------------
template <class T>
void CThr<T>::Clear(BiThrNode<T>*bt,int flag)   
{   
	if(bt&&flag!=1)
	{   
		Clear(bt->lchild,bt->lflag);//�ͷ��������Ľ�� 
		Clear(bt->rchild,bt->rflag);//�ͷ��������Ľ��
		cout<<bt->data<<" :�ͷ���ָ�� "<<bt<<" ��ָ��Ŀռ䡣"<<endl;
		delete   bt;				//�ͷŵ�ǰ���ʵĽ��
		   
	}   
}
//--------------------------------------------------------------------------------
template <class T>
void CThr<T>::CreateBiTree(T end)
{//�����������������õĶ�������û����������
	cout<<"����������������������ֵ��-1δ������־�� ";
	BiThrNode<T>*p;
	T x;
	cin>>x;
	if(x!=end)				//������������Ϊ��
	{
		p=new BiThrNode<T>;
		p->data=x;
		p->lchild=NULL;
		p->rchild=NULL;
		p->lflag=0;
		p->rflag=0;
		BT=p;				//p��Ϊ�����������ĸ����
		create(p,1,end);	//����������
		create(p,2,end);	//����������
	}
}
//--------------------------------------------------------------------------------
template <class T>
void CThr<T>::create(BiThrNode<T>*p,int flag,T end)
{//����һ�ö�������flagΪ1ʱ������������2ʱ������������endΪ�����ı�־
	BiThrNode<T>*q;
	T x;
	cin>>x;		//�������ֵ
	if(x!=end)
	{
		q=new BiThrNode<T>;	//�������������
		q->data=x;
		q->lchild = NULL;
		q->rchild = NULL;
		q->lflag = 0;
		q->rflag = 0;
		if(flag==1)p->lchild=q;	//���ӵ�������
		if(flag==2)p->rchild=q;	//���ӵ�������
		create(q,1,end);		//����������
		create(q,2,end);		//����������
	}	
}