//����˫�ױ�洢��ʾ������C++ģ���װ����
#define MAX_TREE_SIZE 200
#include <iostream>
#include <cstdlib>
#include <windows.h>
#include "LinkQueue.h"
using namespace std;
//------------------------------------------------------------------------------------------------------
template <class T>
struct PTNode
{
	T data;//���������
	int parent;//˫�׽��λ����
};
//------------------------------------------------------------------------------------------------------
template <class T>
struct PTree
{
	PTNode<T> nodes[MAX_TREE_SIZE];//�������
	int n;//�����
};
//------------------------------------------------------------------------------------------------------
template <class T>
class CTree
{
	PTree<T> Tree;
	public:
		CTree();								// ���캯��������һ�ÿ���
		bool CreateTree(T end);					//����һ����
		void ClearTree();						//���һ����
		bool IsEmpty();							//�ж����Ƿ�Ϊ��
		int TreeDepth();						//�����������
		T Root();								//��������
		T Value(int i);							//i�����еĽ����ţ����ؽ���ֵ
		bool Assign(T cur_e,T value);			//�����н��ֵΪcur_e�޸ĳ�value
		T parent(T cur_e);						//cur_e�����н��ֵ������˫�׽���ڣ�����˫�׵�ֵ�����򷵻ؿ�
		T LeftChild(T cur_e);					//cur_e�����н��ֵ,��cur_e�Ƿ�Ҷ�ӽ�㣬����������ߵĺ���ֵ�����򷵻ؿ�
		T RightSibling(T cur_e);				//cur_e�����е�ĳ����㣬�������ֵ���ô�������ֵܵ�ֵ
		void Print();							//�����
		bool InsertChild(T p,int i,PTree<T> c);	//�������
		void DeleteChild(T p,int i);			//ɾ������
		void TraverseTree();					//����һ����
		PTree<T> GetTree(){return Tree;}		//������

};
//------------------------------------------------------------------------------------------------------
template <class T>
CTree<T>::CTree()
{
	Tree.n=0;
}
//------------------------------------------------------------------------------------------------------
//template <class T>
struct QElemType
{//�������Ԫ������
	int num;
	char name;
};
template <class T>
bool CTree<T>::CreateTree(T end)
{//����һ����
	LinkQueue<QElemType> Q;//����
	QElemType p,qq;//�������ͱ���
	int i=0;
	int j;
	int len;
	T c[MAX_TREE_SIZE];//��ʱ��ź��ӽ������
	cout<<"���������㣺";
	cin>>Tree.nodes[0].data;//���������Ϊ0
	if(Tree.nodes[0].data!=end)//������
	{
		Tree.nodes[0].parent=-1;//�����û��˫��
		qq.name=Tree.nodes[0].data;
		qq.num=0;//���
		i++;
		Q.EnQueue(qq);//����������
		while(i<MAX_TREE_SIZE&&Q.QueueEmpty()!=1)//����δ���Ҷ��в���
		{
			qq=Q.DeQueue();
			cout<<"�밴����˳�������� "<<qq.name<<" �����к��ӣ�(û�к�������"<<end<<')';
			//cin>>noskipws;
			cin>>c;
			if(c[0]==end) continue;
			len=strlen(c);//��ȡ�ַ����ĳ���
			for(j=0;j<len;j++)
			{
				Tree.nodes[i].data=c[j];
				Tree.nodes[i].parent=qq.num;
				p.name=c[j];
				p.num=i;
				Q.EnQueue(p);
				i++;
			}
		}
		if(i>MAX_TREE_SIZE)
		{
			cout<<"�������������������"<<endl;
			exit(-1);
		}
		Tree.n=i;
	}
	else
	{
		Tree.n=0;//��Ϊ��
	}
	return true;
}
//------------------------------------------------------------------------------------------------------
template <class T>
void CTree<T>::ClearTree()
{
	Tree.n=0;//�����ĳ�ʼ������ͬ��
}
//------------------------------------------------------------------------------------------------------
template <class T>
bool CTree<T>::IsEmpty()
{
	if(Tree.n==0) return true;//��Ϊ�շ���true;
	return false;//�����գ�����false.
}
//------------------------------------------------------------------------------------------------------
template <class T>
int CTree<T>::TreeDepth()					//�����������
{
	int k,m,def,max=0;
	for(k=0;k<Tree.n;k++)
	{
		def=1;
		m=Tree.nodes[k].parent;
		while(m!=-1)
		{//����˫�׽��һֱ�ҵ������
			m=Tree.nodes[m].parent;
			def++;
		}
		if(max<def)
		{
			max=def;
		}
	}
	return max;//�������
}
//------------------------------------------------------------------------------------------------------
template <class T>
T CTree<T>::Root()
{
	if(Tree.n==0)
	return 0;
	else
		return Tree.nodes[0].data;
}
//------------------------------------------------------------------------------------------------------
template <class T>
T CTree<T>::Value(int i)
{
	if(i<Tree.n)
	{
		return Tree.nodes[i].data;
	}
	else
		return 0;
}
//------------------------------------------------------------------------------------------------------
template <class T>
bool CTree<T>::Assign(T cur_e,T value)
{
	if(Tree.n==0) return false;//��Ϊ��
	for(int i=0;i<Tree.n;i++)
	{
		if(Tree.nodes[i].data==cur_e)
		{//�ҵ�ֵΪcur_e��㣬�޸�ֵΪvalue
			Tree.nodes[i].data=value;
			return true;//�޸ĳɹ�������true
		}		
	}
	return false;//���в�����ֵΪcur_e�Ľ�㣬����false
}
//------------------------------------------------------------------------------------------------------
template <class T>
T CTree<T>::parent(T cur_e)
{
	for(int i=1;i<Tree.n;i++)
	{//���������Ϊ0�����
		if(Tree.nodes[i].data==cur_e)
			return Tree.nodes[Tree.nodes[i].parent].data;
	}
	return 0;//�˽��ǡ���Ǹ���㣬��û���ҵ��˽��
}
//------------------------------------------------------------------------------------------------------
template <class T>
T CTree<T>::LeftChild(T cur_e)
{//��ʼ������cur_e�����еĽ�㣬��cur_e�Ƿ�Ҷ�ӽ�㷵��������ߵĺ��ӷ��򷵻ء��ա�
	int i;
	for(i=1;i<Tree.n;i++)
	{
		if(Tree.nodes[Tree.nodes[i].parent].data==cur_e)
			return Tree.nodes[i].data;
	}
	return 0;

}
//------------------------------------------------------------------------------------------------------
template <class T>
T CTree<T>::RightSibling(T cur_e)
{//��ʼ�����������ڣ�cur_e�����е�ĳ�����
 //�����������cur_e�����ֵܣ������������ֵܣ����򷵻ء��ա�
	for(int i=0;i<Tree.n;i++)
	{
		if(Tree.nodes[i].data==cur_e)
			break;//�ҵ�ֵΪcur_e�Ľ�㣬i��¼���������
	}
	if(Tree.nodes[i].parent==Tree.nodes[i+1].parent)//��cur_e�����ֵܣ���ô���ֵ�Ӧ�ý������
		return Tree.nodes[i+1].data;
	return 0;//û�����ֵܣ���ý�㲻����
}
//------------------------------------------------------------------------------------------------------
template <class T>
void CTree<T>::Print()
{
	int i;
	cout<<"���ĸ���Ϊ��"<<Tree.n<<endl;
	cout<<"���   ˫��"<<endl;;
	for(i=0;i<Tree.n;i++)
	{
		cout<<Value(i)<<'\t';
		if(Tree.nodes[i].parent>=0)
		{
			cout<<Value(Tree.nodes[i].parent)<<' ';
		}
		cout<<endl;
	}
}
//------------------------------------------------------------------------------------------------------
template <class T>
bool CTree<T>::InsertChild(T p,int i,PTree<T> c)
{
	int j,k,len,f=1,n=0;
	//�轻����־f�ĳ�ֵΪ1��p������n�ĳ�ֵ0
	PTNode<T> t;
	if(IsEmpty()!=true)//������
	{
		for(j=0;j<Tree.n;j++)//Ѱ��p�����е����
		{
			if(Tree.nodes[j].data==p)//�ҵ�p�����Ϊ j
				break;
		}
		len=j+1;	//���c��p�ĵ�1������������뵽j+1��
		if(i>1)	//c����p�ĵ�1������
		{
			for(k=j+1;k<Tree.n;k++)
			{
				if(Tree.nodes[k].parent==j)
				{
					n++;//��������1
					if(n==i-1)//�ҵ�p�ĵ�i-1�����ӣ������Ϊk
						break;
				}

			}
			len=k+1;
		}
		if(len<Tree.n)
		{//�����len�������
			for(k=Tree.n-1;k>=len;k--)
			{
				Tree.nodes[k+c.n]=Tree.nodes[k];
				if(Tree.nodes[k].parent>=len)
				{
					Tree.nodes[k+c.n].parent+=c.n;
				}
			}
		}
		for(k=0;k<c.n;k++)
		{//���ν���c�����н�����˴�
			Tree.nodes[len+k].data=c.nodes[k].data;
			Tree.nodes[len+k].parent=c.nodes[k].parent+len;
		}
		Tree.nodes[len].parent=j;//��c�ĸ�����˫��Ϊp
		Tree.n+=c.n;
		while(f)
		{//�Ӳ����֮�󣬽�����԰��������
			f=0;
			for(j=len;j<Tree.n-1;j++)
			{
				if(Tree.nodes[j].parent>Tree.nodes[j+1].parent)
				{//������j��˫�����ڽ��j+1��˫��֮����û�а��������У������������
					t=Tree.nodes[j];
					Tree.nodes[j]=Tree.nodes[j+1];
					Tree.nodes[j+1]=t;
					f=1;//�����ı�־��1
					for(k=j;k<Tree.n;k++)
					{
						if(Tree.nodes[k].parent==j)
							Tree.nodes[k].parent++;
						else if(Tree.nodes[k].parent==j+1)
						{
							Tree.nodes[k].parent--;
						}
					}
					
				}
			}
		}
		
		return true;
	}//if(IsEmpty()!=true)
	else
		return false;
}
//------------------------------------------------------------------------------------------------------
int deleted[MAX_TREE_SIZE+1];
template <class T>
void CTree<T>::DeleteChild(T p,int i)
{//��ʼ�����������ڣ�p�����е�ĳ���ڵ㣬1��i��p��ָ���Ķ�
   // ���������ɾ�����н��p�ĵ�i������
   int j,k,n=0;
   LinkQueue<QElemType> q;
   QElemType pq,qq;
   for(j=0;j<=Tree.n;j++)
     deleted[j]=0; // �ó�ֵΪ0(��ɾ�����)
   pq.name='a'; // �˳�Ա����
   //InitQueue(q); // ��ʼ������
   for(j=0;j<Tree.n;j++)
     if(Tree.nodes[j].data==p)
       break; // jΪ���p�����
   for(k=j+1;k<Tree.n;k++)
   {
     if(Tree.nodes[k].parent==j)
       n++;
     if(n==i)
       break; // kΪp�ĵ�i�������������
   }
   if(k<Tree.n) // p�ĵ�i������������
   {
     n=0;
     pq.num=k;
     deleted[k]=1; // ��ɾ�����
     n++;
     q.EnQueue(pq);
     while(!q.QueueEmpty())
     {
       qq=q.DeQueue();
       for(j=qq.num+1;j<Tree.n;j++)
         if(Tree.nodes[j].parent==qq.num)
         {
           pq.num=j;
           deleted[j]=1; // ��ɾ�����
           n++;
           q.EnQueue(pq);
         }
     }
     for(j=0;j<Tree.n;j++)
       if(deleted[j]==1)
       {
         for(k=j+1;k<=Tree.n;k++)
         {
           deleted[k-1]=deleted[k];
           Tree.nodes[k-1]=Tree.nodes[k];
           if(Tree.nodes[k].parent>j)
             Tree.nodes[k-1].parent--;
         }
         j--;
       }
     Tree.n-=n; // nΪ��ɾ�������
   }
 
}
//------------------------------------------------------------------------------------------------------
template <class T>
void CTree<T>::TraverseTree()
{//��α�����
	cout<<"-----------------------------------------------------------------------"<<endl;
	cout<<"��α�����Ϊ��";
	for(int i=0;i<Tree.n;i++)
	{
		cout<<Tree.nodes[i].data<<" -> ";
	}
	cout<<"\n-----------------------------------------------------------------------"<<endl;

}

