//------------------------------------------------------------------------------------------------------------------------
//                     �Զ������Ļ�����������ģ���װ
//------------------------------------------------------------------------------------------------------------------------
#include<iostream>
using namespace std;
//------------------------------------------------------------------------------------------------------------------------
//����������Ľ������BTNode,���а������������ӣ��Һ��ӽ�㡣
template <class T>
struct BTNode
{
	T data ;			//������
	BTNode* lchild;		//ָ����������ָ��
	BTNode* rchild;		//ָ����������ָ��
};
//------------------------------------------------------------------------------------------------------------------------
//CBinary����ģ��
template <class T>
class BinaryTree
{
	BTNode<T>* BT;
	public: 
		BinaryTree(){BT=NULL;}					// ���캯��,��������ÿ�
		~BinaryTree(){clear(BT);}				// ����Clear()����������������
		void ClearBiTree(){clear(BT);BT=NULL;};	// ����һ�ö�����
		void CreateBiTree(T end);				// ����һ�ö�������endΪ��ָ�����־
		bool IsEmpty();							// �ж϶������Ƿ�Ϊ��
		int BiTreeDepth();						// ��������������
		bool RootValue(T &e);					// ����������Ϊ����e���ظ�����ֵ����������true������������false
		BTNode<T>*GetRoot();					// ��������Ϊ�ջ�ȡ�����ָ�룬���򷵻�NULL
		bool Assign(T e,T value);				// �ҵ���������ֵΪe�Ľ�㣬������ֵ�޸�Ϊvalue��
		T GetParent(T e);						// ��������������e�Ƕ������е�һ�������ô������˫�׽��ֵ
		T GetLeftChild(T e);					// ��ȡ���ӽ��ֵ
		T GetRightChild(T e);					// ��ȡ�Һ��ӽ��ֵ
		T GetLeftSibling(T e);					// ��ȡ���ֵܵĽ��ֵ
		T rightsibling(BTNode<T>*p,T e);
		T GetRightSibling(T e);					// ��ȡ�Һ��ӵĽ��ֵ
		bool InsertChild(BTNode<T>* p,BTNode<T>* c,int RL);// �������
		bool DeleteChild(BTNode<T>* p,int RL);  //ɾ������
		void PreTraBiTree();					// �ݹ��㷨���������������
		void InTraBiTree();						// �ݹ��㷨���������������
		void PostTraBiTree();					// �ݹ��㷨���������������
		void PreTraBiTree_N();					// �ǵݹ��㷨���������������
		void InTraBiTree_N();					// �ǵݹ��㷨���������������
		void LevelTraBiTree();				    // ���ö��в�α���������
		int  LeafCount();						// ����Ҷ�ӽ��ĸ���
		BTNode<T>* SearchNode(T e);				// Ѱ�ҵ����ֵΪe�Ľ�㣬����ָ�����ָ��
		void DisplayBTreeShape(BTNode<T>*bt,int level=1);
};
//��������������ʾ�㷨
template <class T>
void BinaryTree<T>::DisplayBTreeShape(BTNode<T>*bt,int level)
{
   if(bt)//�ն���������ʾ
   { DisplayBTreeShape(bt->rchild,level+1);//��ʾ������
     cout<<endl; //��ʾ����
     for(int i=0;i<level-1;i++)
        cout<<"   "; //ȷ���ڵ�level����ʾ�ڵ�
     cout<<bt->data; //��ʾ�ڵ�
    DisplayBTreeShape(bt->lchild,level+1);//��ʾ������  
   }//if
}//DisplayBTree

template <class T>
static int clear(BTNode<T>*bt)   
{   //����һ�ö�����
	if(bt)//����㲻��
	{   
		clear(bt->lchild);	 //�ݹ����Clear()��������������
		clear(bt->rchild);	 //�ݹ����Clear()��������������
		cout<<"�ͷ���ָ��"<<bt<<"��ָ��Ŀռ䡣"<<endl;
		delete   bt;		 //�ͷŵ�ǰ���ʵĸ����  
	}
	return 0;
}

template <class T>
void BinaryTree<T>::CreateBiTree(T end)
{	//����һ�ö��������������е�˳���������ݣ�endΪ�����ı�־
	cout<<"�밴�������е�˳�����������,-1Ϊ��ָ�����־��"<<endl;
	BTNode<T>*p;
	T x;
	cin>>x;				//�������������
	if(x==end) return ;	//end ��ʾָ��Ϊ�գ�˵����Ϊ��
	p=new BTNode<T>;	//�����ڴ�
	if(!p)
	{
		cout<<"�����ڴ�ʧ�ܣ�"<<endl;
		exit(-1);//�����ڴ�ʧ���˳�
	}
	p->data=x;
	p->lchild=NULL;
	p->rchild=NULL;
	BT=p;			//�����
	create(p,1,end);//�����������������1Ϊ��־����ʾ������
	create(p,2,end);//�����������������2Ϊ��־����ʾ������
}

template <class T>
static int create(BTNode<T>*p,int k,T end)
{//��̬������������������kΪ���������������������ı�־��endΪ��ָ����ı�־
	BTNode<T>*q;
	T x;
	cin>>x;
	if(x!=end)
	{						//����˳����������
		q=new BTNode<T>;
		q->data=x;
		q->lchild=NULL;
		q->rchild=NULL;
		if(k==1) p->lchild=q;	//qΪ������
		if(k==2) p->rchild=q;	//pΪ������
		create(q,1,end);		//�ݹ鴴��������
		create(q,2,end);		//�ݹ鴴��������
	}
	return 0;
}


template <class T>
bool BinaryTree<T>::IsEmpty()
{//�ж϶������Ƿ�Ϊ��
	if(BT==NULL) return true;//�������Ϊ�գ�˵����Ϊ��
	return false;
}

template <class T>
int BinaryTree<T>::BiTreeDepth()
{//���õݹ��㷨�����������
	BTNode<T>*bt=BT;//�������
	int depth=0;//��ʼ��ʱ��������ȳ�ʼ��Ϊ0
	if(bt)//�������Ϊ��
	Depth(bt,1,depth);
	return depth;
}
template <class T>
static int Depth(BTNode<T>* p,int level,int &depth)
{	//���������BiTreeDepth()�����������������ȵļ���
	//����p�Ǹ���㣬Level �ǲ㣬depth���������������
	if(level>depth) depth=level;
	if(p->lchild) Depth(p->lchild,level+1,depth);//�ݹ�ı��������������Ҳ�����1
	if(p->rchild) Depth(p->rchild,level+1,depth);//�ݹ�ı��������������Ҳ�����1
	return 0;
}

template <class T>
bool BinaryTree<T>::RootValue(T &e)
{//����������Ϊ����e���ظ�����ֵ����������true������������false
	if(BT!=NULL)	//�ж϶������Ƿ�Ϊ��
	{
		e=BT->data;	//�����գ��򽫸��������ݸ�ֵ��e
		return true;//�����ɹ�������true
	}
	return false;	//������Ϊ�գ�����false
}

template <class T>
BTNode<T>*BinaryTree<T>::GetRoot()
{//��ȡ����Ϣ
	return BT;//���ظ�����ָ�룬��������Ϊ����ô����NULL
}

template <class T>
bool BinaryTree<T>::Assign(T e,T value)
{//��㸳ֵ
	if(SearchNode(e)!=NULL)
	{
		(SearchNode(e))->data=value;
		return true;
	}
	return false;
}

template <class T>
T BinaryTree<T>::GetParent(T e)
{//��ȡ˫����Ϣ
	BTNode<T>*Queue[200],*p;
	int rear,front;
	rear=front=0;
	if(BT)
	{
		Queue[rear++]=BT;
		while(rear!=front)
		{
			p=Queue[front++];
			if(p->lchild&&p->lchild->data==e||p->rchild&&p->rchild->data==e)
				return p->data;
			else
			{
				if(p->lchild) Queue[rear++]=p->lchild;
				if(p->rchild) Queue[rear++]=p->rchild;
			}
		}
	}
	return NULL;
}

template <class T>
T BinaryTree<T>::GetRightChild(T e)
{//������������ڣ�e�Ƕ������е�һ����㣬������������ô�����������Ľ��ֵ�����򷵻�0����ʾ������Ϊ��
	BTNode<T>*p=SearchNode(e);
	if(p->rchild) return p->rchild->data;//���������գ�����������������ֵ
	cout<<"���"<<e<<"��������Ϊ��"<<endl;
	return 0;
}

template <class T>
T BinaryTree<T>::GetLeftChild(T e)
{//������������ڣ�e�Ƕ������е�һ����㣬������������ô�����������Ľ��ֵ�����򷵻�0����ʾ������Ϊ��
	BTNode<T>*p=SearchNode(e);
	if(p->lchild) return p->lchild->data;
	cout<<"���"<<e<<"��������Ϊ��"<<endl;
	return 0;
}

template <class T>
T BinaryTree<T>::GetLeftSibling(T e)
{//��ȡ���ֵ���Ϣ
	if(BT!=NULL)
	{
		return leftsibling(BT,e);
	}
	else
	{//������Ϊ��
		cout<<"������Ϊ�գ�"<<endl;
		return 0;
	}
}

template <class T>
T leftsibling(BTNode<T>*p,T e)
{
	T q=0;
	if(p==NULL) return 0;
	else
	{
		if(p->rchild)
		{
			if(p->rchild->data==e)
			{
				if(p->lchild) return p->lchild->data;
				else
					return NULL;
			}
		}
		q=leftsibling(p->lchild,e);
		if(q)return q;
		q=leftsibling(p->rchild,e);
		if(q)return q;
	}
	return 0;
}
//------------------------------------------------------------------------------------------------------------------------
template <class T>
T BinaryTree<T>::GetRightSibling(T e)
{//��ȡ���ֵ���Ϣ
	if(BT!=NULL)
	{
		return rightsibling(BT,e);
	}
	else
	{//������Ϊ��
		cout<<"������Ϊ�գ�"<<endl;
		return 0;
	}
}
template <class T>
 T BinaryTree<T>::rightsibling(BTNode<T>*p,T e)
{
	BTNode<T> *q=SearchNode(e);
	BTNode<T> *pp;
	if(q)
	{
		pp=SearchNode(GetParent(e));
		if(pp)
		{
			if(pp->rchild) return pp->rchild->data;
			else return 0;
		}
		else return 0;

	}
	return 0;
}

template <class T>
bool BinaryTree<T>::InsertChild(BTNode<T>* p,BTNode<T>* c,int LR)
{//���뺢��
	if(p)
	{
		if(LR==0)
		{
			c->rchild=p->lchild;
			p->lchild=c;
		}
		else
		{
			c->rchild=p->rchild;
			p->rchild=c;
		}
		return true;
	}
	return false;//pΪ��
}
//------------------------------------------------------------------------------------------------------------------------
template <class T>
bool BinaryTree<T>::DeleteChild(BTNode<T>* p,int RL)  
{//ɾ�����
	if(p)
	{
		if(RL==0)
		{
			clear(p->lchild);//�ͷ�p�����������н��ռ�
			p->lchild=NULL;
		}
		else
		{
			clear(p->rchild);
			p->rchild=NULL;
		}
		return true;//ɾ���ɹ�
	}
	return false;//pΪ��
}
//------------------------------------------------------------------------------------------------------------------------
template <class T>
void BinaryTree<T>::PreTraBiTree()
{//�������������
	cout<<"----------------------------------------------"<<endl;
	cout<<"�������������:";
	BTNode<T>*p;
	p=BT;			//�����
	PreTraverse(p); //�Ӹ���㿪ʼ�������������
	cout<<endl;
	cout<<"----------------------------------------------"<<endl;
}
template <class T>
static int PreTraverse(BTNode<T>*p)
{
	if(p!=NULL)
	{
		cout<<p->data<<' ';		//�������ϵ�����
		PreTraverse(p->lchild);	//�ݹ�ĵ���ǰ�����������
		PreTraverse(p->rchild);	//�ݹ�ĵ���ǰ�����������
	}
	return 0;
}			
//------------------------------------------------------------------------------------------------------------------------
template <class T>
void BinaryTree<T>::InTraBiTree()
{//�������������
	cout<<"----------------------------------------------"<<endl;
	cout<<"�������������:";
	BTNode<T>*p;
	p=BT;//�����
	InTraverse(p);//�Ӹ���㿪ʼ�������������
	cout<<endl;
	cout<<"----------------------------------------------"<<endl;
}
template <class T>
static int InTraverse(BTNode<T>*p)
{
	if(p!=NULL)
	{
		InTraverse(p->lchild);	//�ݹ�ĵ����������������
		cout<<p->data<<' ';		//�������ϵ�����
		InTraverse(p->rchild);	//�ݹ�ĵ����������������
	}
	return 0;
}
//------------------------------------------------------------------------------------------------------------------------
template <class T>
void BinaryTree<T>::PostTraBiTree()
{//�������������
	cout<<"----------------------------------------------"<<endl;
	cout<<"�������������:";
	BTNode<T>*p;
	p=BT;//�����
	PostTraverse(p);//�Ӹ���㿪ʼ����������
	cout<<endl;
	cout<<"----------------------------------------------"<<endl;
}
template <class T>
static int PostTraverse(BTNode<T>*p)
{
	if(p!=NULL)
	{
		PostTraverse(p->lchild);//�ݹ���ú������������
		PostTraverse(p->rchild);//�ݹ���ú������������
		cout<<p->data<<' ';		//�������ϵ�����
	}
	return 0;
}
//------------------------------------------------------------------------------------------------------------------------
template <class T>
void BinaryTree<T>::PreTraBiTree_N()
{//
	cout<<"----------------------------------------------"<<endl;
	cout<<"����(�ǵݹ�)�����������ã�";
	BTNode<T> *Stack[200];//����ָ��������Ϊջ
	int top=0;
	BTNode<T>*p=BT;//��������ָ�븳ֵ��p
	while(p!=NULL||top!=0)
	{
		while(p!=NULL)
		{
			cout<<p->data<<" ";
			Stack[top++]=p->rchild;
			p=p->lchild;
		}
		if(top!=0)
		{
			p=Stack[--top];
		}
	}
	cout<<"\n----------------------------------------------"<<endl;
}
//------------------------------------------------------------------------------------------------------------------------
template <class T>
void BinaryTree<T>::InTraBiTree_N()
{//�ǵݹ��������������
	cout<<"----------------------------------------------"<<endl;
	cout<<"����(�ǵݹ�)�����������ã�";
	int top=0;
	BTNode<T> *Stack[200];
	BTNode<T> *p=BT;
	while(p||top)
	{
		while(p)
		{
			Stack[top++]=p;
			p=p->lchild;
		}
		
		if(top)
		{
			p=Stack[--top];
			cout<<p->data<<' ';
			p=p->rchild;
		}
	}
	cout<<"\n----------------------------------------------"<<endl;
	
}

//------------------------------------------------------------------------------------------------------------------------
template <class T>
void BinaryTree<T>::LevelTraBiTree()
{//���ö���Queue��α���������
	BTNode<T> *Queue[100];	//����һά������Ϊ���У���Ž���ָ��
	BTNode<T> *b;
	int front,rear;			//ָ����е�ͷ��β�±�
	front=rear=0;			//���г�ʼΪ��
	cout<<"----------------------------------------------"<<endl;
	if(BT)					//����������Ϊ�ա�
	{
		Queue[rear++]=BT;	//�������ĸ����ָ������С�
		while(front!=rear)	//���в�Ϊ�ա�
		{
			b=Queue[front++];			//���׵�Ԫ�س�����
			if(b)cout<<b->data<<' ';	//�������ֵ
			if(b->lchild) Queue[rear++]=b->lchild;//������������գ����ӡ�
			if(b->rchild) Queue[rear++]=b->rchild;//������������գ����ӡ�
		}

	}
	cout<<"\n----------------------------------------------"<<endl;
}

template <class T>
int BinaryTree<T>::LeafCount()
{//����Ҷ�ӵĸ���

	int count=0;
	return Leaf(BT,count);
}
template <class T>
static int Leaf(BTNode<T>* p,int &count)
{
	//static int count=0;//��̬���������Ҷ�ӽ��ĸ���
	if(p)
	{
		if(p->lchild==NULL&&p->rchild==NULL) count++;//�ж��Ƿ�ΪҶ�ӽ��
		Leaf(p->lchild,count);//�ݹ����������
		Leaf(p->rchild,count);//�ݹ����������
	}
	return count;

}

template <class T>
BTNode<T>* BinaryTree<T>::SearchNode(T e)
{//����ѯ
	BTNode<T>*t;
	if(BT)
	{
		
		if(BT->data==e)	return BT;
		t=search(BT->lchild,e);//���������в���
		if(t)return t;
		
		t=search(BT->rchild,e);//������������
		if(t) return t;
	}

	return NULL;
}
template <class T>
static BTNode<T>* search(BTNode<T>*bn,T e)
{BTNode<T>*t;
	if(bn)
	{	
		if(bn->data==e)	{return bn;}
		t=search(bn->lchild,e);//�ݹ����������
		if(t) return t;
		t=search(bn->rchild,e);//�ݹ����������
		if(t) return t;
	}
	return NULL;
}
//------------------------------------------------------------------------------------------------------------------------
