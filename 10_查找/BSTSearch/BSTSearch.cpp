#include<iostream>
using namespace std;
#define TRUE  1;
#define FALSE  0;
typedef int T;
const maxsize=50;

template <class T>
struct Node
{
	T key;
	/*.....*/
};

template <class T>
struct bitree
{
	Node<T> data;
    bitree<T> *lchild;
	bitree<T> *rchild;
};


template <class T>
class BSTree
{
public:
	Node<T> *ST;
	int len;        //���ظ���
	bitree<T> *t;	//��ָ��
	bitree<T> *f;	//��ָ���˫��ָ��
	bitree<T> *p;	//ָ�����·���������ʵĽڵ�
	BSTree();//���캯��
	~BSTree();//��������
	void SearchBST(bitree<T> *t,T key);//��������������
	void InsertBST(bitree<T> *(&t),Node<T> e);//Ԫ�ز���
	int DeleteBST(bitree<T> *(&t),T key);//������������Ԫ��ɾ��
	int Delete(bitree<T> *(&p));//
	void DeleteElem(T key);//���ұ�Ԫ��ɾ��
	void InDisplay(bitree<T> *t);//�����������������
	void Display();//���ұ���ʾ
};

template <class T>
BSTree<T>::BSTree()
{//���캯������ʼ�����ұ�
	ST=new Node<T>[maxsize];//˳���Ų��ұ�
	len=0;
	t=NULL;//��������ʼ��
}

template <class T>
BSTree<T>::~BSTree()
{//�������������ٲ��ұ�
	delete [] ST;
    len=0;
	delete t;
	cout<<"�ɹ����ٶ���������\n";
}

template <class T>
void BSTree<T>::SearchBST(bitree<T> *t,T key)
{//Ԫ�ز���
   if(t==NULL || key==t->data.key)
	{
		if(key==t->data.key)                    
			cout<<"�ҵ�"<<key<<"�Ľڵ�"<<endl;
		else
		cout<<"������"<<key<<"�Ľڵ�"<<endl;
	}
	else if(key<t->data.key)
		SearchBST(t->lchild,key);
	else
		SearchBST(t->rchild,key);
}

template <class T>
void BSTree<T>::InsertBST(bitree<T> *(&t),Node<T> e)
{//Ԫ�ز���
	ST[len]=e;
	len++;
    p=t;
   while(p)
	{
		if(p->data.key==e.key)
		{
		cout<<"�������������Ѿ�����ֵΪ:"<<e.key<<"�Ľڵ�\n";
		exit(1);
		}
		f=p;
		if(e.key<p->data.key)
			p=p->lchild;
		else
			p=p->rchild;
		p=new bitree<T>;
		p->data=e;
		p->lchild=p->rchild=NULL;
		if(t==NULL)
			t=p;
		else
		{
			if(e.key<f->data.key)
				f->lchild=p;
			else
				f->rchild=p;
		}
	}
}
template <class T>
int BSTree<T>::DeleteBST(bitree<T> *(&t),T key)
{// Ԫ��ɾ��		
	if(!t)
	{
	  cout<<"������Ϊ��,�޷�ɾ��\n";
	  return FALSE;
	}
	else
	{
    	if(key==t->data.key)
			return Delete(t);
		else if(key<t->data.key)
	     	return DeleteBST(t->lchild,key);
		else
		return DeleteBST(t->rchild,key);
	}
}

template <class T>
int BSTree<T>::Delete(bitree<T> *(&p))
{
		bitree<T> *q,*s;
		if(!p->rchild)
		{
			q=p;
			p=p->lchild;
			delete q;
			cout<<"�ɹ�ɾ��"<<endl;
			
		}
		else if(!p->lchild)
		{
			q=p;
			p=p->rchild;
			delete q;
			cout<<"�ɹ�ɾ��"<<endl;
		}
		else
		{
			q=p;
			s=p->lchild;
			while(s->rchild)
			{
				q=s;
				s=s->rchild;
			}
			p->data=s->data;
		   if(q!=p)
			q->rchild=s->lchild;
		   else
			q->lchild=s->lchild;
		  delete s;
		  cout<<"�ɹ�ɾ��"<<endl;
		}
		return TRUE;
}

template <class T>
void BSTree<T>::DeleteElem(T key)
{//˳���Ԫ��ɾ�� 
	for(int i=0;i<len && ST[i].key!=key;i++);
	if(i<len)
	{
		for(int j=i+1;j<len;j++)
			ST[i]=ST[j];
		len--;
	}
}
		
template <class T>
void BSTree<T>::InDisplay(bitree<T> *t)
{//����������
	if(t!=NULL)
	{
		InDisplay(t->lchild);
		cout<<t->data.key<<"    ";	
	   	InDisplay(t->rchild);
	}
}

template <class T>
void BSTree<T>::Display()
{//������ұ��е�����Ԫ��
	cout<<"���ұ��е�����Ԫ�عؼ�������Ϊ:\n";
	for(int i=0;i<len;i++)
		cout<<ST[i].key<<"   ";
	cout<<endl;
}

void main()
{
	int m,l,i;
	BSTree<int> a;
	do  {
	  cout<<"---- �����������Ļ�������--------"<<endl;
	  cout<<"--- 1. �������ұ� --------------\n"
	      <<"----2. ����Ԫ��-------------\n" 
	      <<"--- 3. ɾ��Ԫ��  ---------------\n"
	      <<"--- 4. ����Ԫ�� ----------------\n"
		  <<"--- 5. ��������������������---\n"
	      <<"--- 6. ���ұ����  -------------\n"
	      <<"--- 7. �˳�  -------------------\n"
		  <<"��ѡ�����:";
	  cin>>m;
	 if(m==1)
		{
			Node<T> e;
			cout<<"����Ҫ���������Ԫ�ظ���\n";
			cin>>l;
			cout<<"����"<<l<<"����ͬ������Ԫ��\n";
			for(i=0;i<l;i++)
			{
				cin>>e.key;	
				a.InsertBST(a.t,e);
			}
		}
	  else if(m==2)
		{
			Node<T> e;
			cout<<"����Ҫ���������Ԫ��\n";
			cin>>e.key;
			a.InsertBST(a.t,e);
		}
	  else if(m==3)
		{
			T key;
			cout<<"����Ҫɾ��������Ԫ��:";
			cin>>key;
			a.DeleteBST(a.t,key);
			a.DeleteElem(key);
		}
	  else if(m==4)
		{
			T key;
			cout<<"������ҵ�����Ԫ��: ";
			cin>>key;
			a.SearchBST(a.t,key);
		}
		else if(m==5)
		{
			cout<<"���������������Ϊ:\n";
			a.InDisplay(a.t);
			cout<<endl;
		}
		else if(m==6)
		{
			cout<<"�������������:\n";
			a.Display();
			cout<<endl;
		}
		else if(m==7)
			cout<<"��������!\n";
		else
			cout<<"�������Ƿ�,������0--7֮��,����������"<<endl;
		//cout<<endl;
		cout<<"�����ѡ�����"<<endl;
	}while(m!=7);
}