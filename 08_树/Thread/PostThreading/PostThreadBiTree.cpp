//����������������
#include<iostream>
using namespace std;
//�������������������������
template <class T>
struct TTTNode
{
	T data;						//������
	int lflag;					//���־��
	int rflag;					//�б�־��
	TTTNode<T> *pre;			//˫�׽��ָ����
	TTTNode<T> *lchild;			//����ָ����
	TTTNode<T> *rchild;			//�к���ָ����
};
//������������������
template <class T>
class PostThreadBiTree
{
	TTTNode<T> * BT;						//������������ָ��
	public:									//��Ա����
		PostThreadBiTree(){BT=NULL;}		//���캯���������������ʼ��
		void CreateBiTree(T end);			//������������
		void CreateThreadBT();				//��������������
		void TraverseTree();				//��������������������

};

template <class T>
void PostThreadBiTree<T>::CreateBiTree(T end)
{
	TTTNode<T> *p;				//����������
	T x;
	cin>>x;						//�����һ�����ֵ
	if(x==end) return;			//����������Ϊ��
	p=new TTTNode<T>;			//��������������
	p->data=x;					//������ֵ
	p->pre=NULL;				//˫�׽���ʼ״̬ΪNULL
	p->lchild=NULL;				//�������ʼ״̬ΪNULL
	p->rchild=NULL;				//�Һ������ʼ״̬ΪNULL
	p->lflag=0;
	p->rflag=0;
	BT=p;						//��������ĸ����
	create(p,1,end);			//����������
	create(p,2,end);			//����������
}
template <class T>
static int create(TTTNode<T>*p,int k,T end)
{
	TTTNode<T> *Q;				//����������
	T x;
	cin>>x;						//������ֵ
	if(x!=end)
	{
		Q= new TTTNode<T>;		//��������������
		Q->data=x;
		Q->lchild=NULL;
		Q->rchild=NULL;
		Q->lflag=0;
		Q->rflag=0;
		Q->pre=p;
		if(k==1) p->lchild=Q;	//���ӵ�������
		if(k==2) p->rchild=Q;	//���ӵ�������
		create(Q,1,end);		//�ݹ鴴��������
		create(Q,2,end);		//�ݹ鴴��������	
	}
	return 0;
}
//-------------------------------------------------------------------------------------------------
template <class T>
void PostThreadBiTree<T>::CreateThreadBT()
{
	//������
	TTTNode<T> *p=BT,*q=NULL;
	Thread(p,&q);
}
template <class T>
static int Thread(TTTNode<T> *p,TTTNode<T> **h)
{
	if(p!=NULL)
	{
		Thread(p->lchild,h);//�ݹ�����������
		Thread(p->rchild,h);//�ݹ�����������
		//���ϴη��ʵĽ�����ָ��Ϊ��
		//�򽫵�ǰ���ʵĽ��������룬�����ұ�־��1
		if(*h!=NULL&&(*h)->rchild==NULL)
		{
			(*h)->rchild=p;
			(*h)->rflag=1;
		}
		//���ϴη��ʵĽ�����ָ��Ϊ��
		//�򽫵�ǰ���ʵĵĽ��������룬�����ұ�־��Ϊ1
		if((*h!=NULL)&&(p->lchild==NULL))
		{
			p->lchild=(*h);
			p->lflag=1;
		}
		*h=p;//��ס��ǰ���ʵĽ��
	}
	return 0;
}
//-------------------------------------------------------------------------------------------------
template <class T>
void PostThreadBiTree<T>::TraverseTree()
{//������������������
	TTTNode<T> *p,*h;
	if(BT==NULL) return ;//������Ϊ��
	h=BT;//�������ĸ����
	while(h->lchild!=NULL||h->rflag==0&&h->rchild!=NULL)
	{//���������գ�������������
		if(h->lchild!=NULL)
		h=h->lchild;
		else
			h=h->rchild;
	}
	//����������ҵ�һ�����
	cout<<h->data<<"��";//������������еĵ�һ�����ֵ
	while(h->pre!=NULL)//
	{
		if(h->rflag!=0) h=h->rchild;
		else
		{
			p=h->pre;
			if((p->rchild==h)||(p->lchild==h)&&((p->rflag!=0)||(p->rchild==NULL)))
				h=p;//˫�׽����Ϊ���
			else
			{
				h=p->rchild;
				while(((h->lflag==0)&&(h->lchild!=NULL))||
					((h->rflag==0)&&(h->rchild!=NULL)))
				{
					if((h->lflag==0)&&h->lchild!=NULL)
						h=h->lchild;
					else
						h=h->rchild;
				}
			}
		}
		cout<<h->data<<"��";
	}
	cout<<"NULL"<<endl;
}

int main()
{
	PostThreadBiTree<char> PT;
	int op;//ѡ��Ĳ���
	do
	{
		system("cls");
		cout<<"----------��   ��----------------"<<endl;
		cout<<"\t1������һ�ö�����"<<endl;
		cout<<"\t2�����ɺ�������������"<<endl;
		cout<<"\t3��������������������"<<endl;
		cout<<"\t4���˳�"<<endl;
		cout<<"-----------------------------------"<<endl;
		cout<<"��ѡ�������[ ]";
		cout<<"\b\b";
		cin>>op;
		switch(op)
		{
		case 1:
			cout<<"������˳���������ĸ�����㣬'#'Ϊ��ָ���־��";
			PT.CreateBiTree('#');
			system("pause");
			break;
		case 2:
			PT.CreateThreadBT();
			system("pause");
			break;
		case 3:
			PT.TraverseTree();
			system("pause");
			break;
		case 4:
			cout<<"�������У�Bye-Bye!"<<endl;
			break;
		default:
			cout<<"ѡ��Ĳ�������"<<endl;
		}
	}while(op!=4);
	return 0;
}