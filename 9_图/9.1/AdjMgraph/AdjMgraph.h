/*--------------------------����ͼ���ڽӶ��ر��ʾ-----------------------------*/
#include "LinkQueue.h" 
using namespace std;

#define MAX_VERTEX_NUM 20  //��󶥵���
 
#define MAX_INFO 10  //��Ϣ�Ĵ�С 

struct EBox{
	bool mark; //���ʱ��0δ������,1�ѱ�����
	int ivex,jvex;//�ñ����������������λ��
	EBox *ilink,*jlink;//�ֱ�ָ�������������������һ����
	char *info; //�ñ���Ϣ
};

template <class T>
struct VexBox{
	T data; //������Ϣ
	EBox *firstedge;//ָ���һ�������ö���ı�
};


template <class T>
struct _AMGraph{
	VexBox<T> adjmulist[MAX_VERTEX_NUM];
	int vexnum,edgenum;//�������ͱ���
};


template <class T>
class AMGraph{
	
	_AMGraph<T> amgraph;

	bool visited[MAX_VERTEX_NUM];
	
public:
	
	void CreateGraph();                                //v��ͼ�Ķ��㼯 vr��ͼ�ı߼� 

	void DestroyGraph();                               //����ͼ

	int LocateVex (T u);                    //ͼ���ڣ�ͼ�д��ڶ���u �򷵻ظö�����ͼ�е�λ��

	T GetVex(int index);                    //ͼ���ڣ�index��ͼ��ĳ���������� ������v��ֵ

	void PutVex(T v,T value);           //ͼ���ڣ�v��ͼ��ĳ������ ���v��ֵvalue

	int FirstAdjVex(T v);                  //ͼ���ڣ�v��G��ĳ������ ����v�ĵ�һ���ٽӵ����� ������ӵ��򷵻ؿ�

	int NextAdjVex(T v,T w);          //ͼ���ڣ�v��ͼ��ĳ�����㣬w��v���ڽӵ� ����v�������w����һ���ڽӵ����ţ���w��v�����һ���ڽӵ��򷵻ؿ�

	void InsertVex(T v);                   //ͼ���� ��ͼ�������¶���v

	bool DeleteVex(T v);                   //ͼ����   ɾ������v������صĻ�

	bool InsertArc(T v,T w);          //ͼ���ڣ�V��w��ͼ���������� ��ͼ����ӻ�<v��w>�����ӶԳƻ�<w��v>
		
	bool DeleteArc(T v,T w);          //ͼ���ڣ�V��w��ͼ���������� ��ͼ��ɾ����<v��w>��ɾ���Գƻ�<w��v>
	
	bool (*VisitFunc)(T v);                 //���ʶ���v�ķ�ʽ

	void DFS(int index);                        //�ӵ�index����������ݹ��������ȱ���ͼ

	bool DFSTraverse(bool (*visit)(T v));  //ͼ���ڣ���ͼ����������ȱ���
		
	bool BFSTraverse(bool (*visit)(T v));  //ͼ���ڣ���ͼ���й�����ȱ���

	void MarkUnVisited();                       //�ñߵķ��ʱ��Ϊδ����

	void DisPlay();                             //���ͼ               

};


template <class T>
int AMGraph<T>::LocateVex(T v)
{
	for(int i = 0;i<amgraph.vexnum;i++)
	{
		if(amgraph.adjmulist[i].data == v)
		{
			return i;
		}
	}
	return -1;
}


template <class T>
void AMGraph<T>::CreateGraph()
{
	int i,j,k;	 
	T va,vb;
	EBox *p;
	cout<<"����������ͼ�Ķ���������ߵĸ��� ";
	cin>>amgraph.vexnum>>amgraph.edgenum ;
	cout<<"������"<<amgraph.vexnum<<"�������ֵ"<<endl;
	for(i = 0;i<amgraph.vexnum;i++)
	{
		cin>>amgraph.adjmulist[i].data;
		amgraph.adjmulist[i].firstedge = false;
	}
	cout<<"��˳������ÿ���ߵ������˵�"<<endl;
	for(k = 0;k<amgraph.edgenum;k++)
	{
		cin>>va>>vb;
		i = LocateVex(va);
		j = LocateVex(vb);
		p = new EBox;
		p->mark = 0;
		p->ivex = i;
		p->jvex = j;
		p->info = false;
		//���ڱ�ͷ
		p->ilink = amgraph.adjmulist[i].firstedge;
		amgraph.adjmulist[i].firstedge = p;
		//���ڱ�ͷ
		p->jlink = amgraph.adjmulist[j].firstedge;
		amgraph.adjmulist[j].firstedge = p;		 
			p->info = false;//�û��������Ϣ
		 
	}
}


template <class T>
T AMGraph<T>::GetVex(int index)
{
	if(index<0||index>=amgraph.vexnum)
		return false;
	return amgraph.adjmulist[index].data;
}


template <class T>
void AMGraph<T>::PutVex(T v,T value)
{
	int i = LocateVex(v);
	if(i<0)
		return;
	amgraph.adjmulist[i].data = value;
}


template <class T>
int AMGraph<T>::FirstAdjVex(T v)
{
	int i = LocateVex(v);
	if(i<0)
		return -1;
	if(amgraph.adjmulist[i].firstedge)
		//v���ڽӵ�
	{
		if(amgraph.adjmulist[i].firstedge->ivex == i)
		{
			return amgraph.adjmulist[i].firstedge->jvex;
		}
		else
		{
			return amgraph.adjmulist[i].firstedge->ivex;
		}
	}
	else
	{
		return -1;
	}
}


template <class T>
int AMGraph<T>::NextAdjVex(T v,T w)
{
	EBox *p;
	int i = LocateVex(v);
	int j = LocateVex(w);
	if(i<0||j<0)
		return -1;
	p = amgraph.adjmulist[i].firstedge;
	while(p)
	{
		if(p->ivex == i&&p->jvex != j)
			//�����ڽӵ㣬�������������ڽӵ�
		{
			//����1
			p = p->ilink;
		}
		else if(p->jvex == i&&p->ivex != j)
		{
			//����2
			p = p->jlink;
		}
		else
		{
			break;
		}
	}
	if(p&&p->ivex == i&&p->jvex ==j)
		//�ڷ���1�ҵ�
	{
		p = p->ilink;
		if(p&&p->ivex == i)
			return p->jvex;
		else if(p&&p->jvex ==i)
			return p->ivex;
	}
	if(p&&p->ivex == j&&p->jvex == i)
		//�ڷ���2�ҵ�
	{
		p = p->jlink;
		if(p&&p->ivex == i)
			return p->jvex;
		else if(p&&p->jvex == i)
			return p->ivex;
	}
	return -1;
}


template <class T>
void AMGraph<T>::InsertVex(T v)
{
	if(amgraph.vexnum>=MAX_VERTEX_NUM)
		return;
	if(LocateVex(v)>=0)
		return;
	amgraph.adjmulist[amgraph.vexnum].data = v;
    amgraph.adjmulist[amgraph.vexnum].firstedge = false;
	amgraph.vexnum++;
}

template <class T>
bool AMGraph<T>::DeleteArc(T v,T w)
{
	EBox *p,*q;
	int i = LocateVex(v);
	int j = LocateVex(w);
	if(i<0||j<0||i == j)
		return false;
	//����ʹָ���ɾ���ߵĵ�һ��ָ���ƹ�������
	p = amgraph.adjmulist[i].firstedge;
	/*------------- ��һ����Ϊ��ɾ��---------------*/
	if(p&&p->jvex == j)
		//case 1
	{
		amgraph.adjmulist[i].firstedge = p->ilink;
	}
	else if(p&&p->ivex == j)
		//case 2
	{
		amgraph.adjmulist[i].firstedge = p->jlink;
	}
	/*------------- ��һ���߲�Ϊ��ɾ��---------------*/
	else
	{
		while(p)
			//�һ�<v,w>
		{
			if(p->ivex == i&&p->jvex != j)
				//���Ǵ�ɾ��
			{
				//case1
				q = p;
				p = p->ilink;
			}
			else if(p->jvex == i&&p->ivex != j)
			{
				//case2
				q = p;
				p = p->jlink;
			}
			else
			{
				//���ڽӵ�w
				break;
			}
		}
		if(!p)
			return false;
		if(p->ivex == i&&p->jvex == j)
			//case 1
		{
			if(q->ivex == i)
				q->ilink = p->ilink;
			else
				q->jlink = p->ilink;
		}
		else if(p->ivex == j&&p->jvex == i)
			//case2
		{
			if(q->ivex == i)
				q->ilink = p->jlink;
			else
				q->jlink = p->jlink;
		}

	}
	//���´���һ������ɾ����ɾ����
	p = amgraph.adjmulist[j].firstedge;
	/*------------- ��һ����Ϊ��ɾ��---------------*/
	if(p->jvex == i)
		//case 1
	{
		amgraph.adjmulist[j].firstedge = p->ilink;
		if(p->info)
			delete p->info;
		delete p;
	}
	else if(p->ivex == i)
		//case 2
	{
		amgraph.adjmulist[j].firstedge = p->jlink;
		if(p->info)
			delete p->info;
		delete p;
	}
	/*------------- ��һ���߲�Ϊ��ɾ��---------------*/
	else
	{
		while(p)
			//�һ�<v,w>
		{
			if(p->ivex == j&&p->jvex != i)
				//���Ǵ�ɾ��
			{
				//case1
				q = p;
				p = p->ilink;
			}
			else if(p->jvex == j&&p->ivex != i)
			{
				//case2
				q = p;
				p = p->jlink;
			}
			else
			{
				break;
			}
		}
		if(p->ivex == i&&p->jvex ==j)
			//case 1
		{
			if(q->ivex == j)
				q->ilink = p->jlink;
			else
				q->jlink = p->jlink;
		}
		else if(p->ivex == j&&p->jvex == i)
			//case2
		{
			if(q->ivex == j)
				q->ilink = p->ilink;
			else
				q->jlink = p->ilink;
			if(p->info)
				delete p->info;
			delete p;
		}
	}
    amgraph.edgenum--;
	return true;
}


template <class T>
bool AMGraph<T>::DeleteVex(T v)
{
	int i,j;
	T w;
	EBox *p;
	i = LocateVex(v);
	if(i<0)
		return false;
	for(j = 0;j<amgraph.vexnum;j++)
		//ɾ�����ڵ��붥��v�����ı�
	{
		if(j == i)
			continue;
		w = GetVex(j);
		DeleteArc(v,w);
	}
	//���ڶ���v����Ķ������ż�1
	for(j = i+1;j<amgraph.vexnum;j++)
	{
		amgraph.adjmulist[j-1] = amgraph.adjmulist[j];
	}
	amgraph.vexnum--;
	//�޸Ķ������
	for(j = i;j<amgraph.vexnum;j++)
	{
		p = amgraph.adjmulist[j].firstedge;
		while(p)
		{
			if(p->ivex == j+1)
			{
				p->ivex--;
				p = p->ilink;
			}
			else
			{
				p->jvex--;
				p = p->jlink;
			}
		}
	}
	return true;
}


template <class T>
void AMGraph<T>::DestroyGraph()
{
	for(int i = amgraph.vexnum-1;i>=0;i--)
	{
		DeleteVex(amgraph.adjmulist[i].data);
	}
}


template <class T>
bool AMGraph<T>::InsertArc(T v,T w)
{ 	int i = LocateVex(v);
	int j = LocateVex(w);
	if(i<0||j<0)
		return false;
	EBox * p = new EBox;
	p->mark = 0;
	p->ivex = i;
	p->jvex = j;
	p->info = false;

	p->ilink = amgraph.adjmulist[i].firstedge;
    amgraph.adjmulist[i].firstedge = p;
	p->jlink = amgraph.adjmulist[j].firstedge;
	amgraph.adjmulist[j].firstedge = p; 	 
	amgraph.edgenum++;
	return true;
}


template <class T>
void AMGraph<T>::DFS(int index)
{
	int j;
	VisitFunc(amgraph.adjmulist[index].data);
	visited[index] = true;//�ȷ���index
	EBox *p = amgraph.adjmulist[index].firstedge;
	while(p)
	{
		//����һ������ȷ��ʵĶ���
		j = (p->ivex == index) ? p->jvex : p->ivex;
		//δ�����������ݹ���ȷ���
		if(!visited[j])
			DFS(j);
        p = (p->ivex == index) ? p->ilink :p->jlink;
	}
}



template <class T>
bool AMGraph<T>::DFSTraverse(bool (*visit)(T v))
{
	VisitFunc = visit;
	int i;
	for(i = 0;i<amgraph.vexnum;i++)
		//���ʱ�ʶ������ʼ��
	{
		visited[i] = false;
	}
	for(i = 0;i<amgraph.vexnum;i++)
		//��ÿ�����������ȵݹ�
	{
		if(!visited[i])
			DFS(i);
	}
	cout<<endl;
	return true;
}


template <class T>
bool AMGraph<T>::BFSTraverse(bool (*visit)(T v))
{
	int i,receive,j;
	T u;
	for(i = 0;i<amgraph.vexnum;i++)
		//���ʱ�ʶ������ʼ��
	{
		visited[i] = false;
	}
	LinkedQueue<int> q;
	for(i = 0;i<amgraph.vexnum;i++)
		//��ÿ��δ�����ʵĶ�����й�����ȱ���
	{
		if(!visited[i])
		{
			visited[i] = true;
			visit(amgraph.adjmulist[i].data);
			q.EnQueue(i);
			while(q.IsEmpty() == false)
			{
				q.DeQueue(receive);
				u = GetVex(receive);
				for(j = FirstAdjVex(u);j>=0;j = NextAdjVex(u,GetVex(j)))
				{
					if(!visited[j])
					{
						visited[j] = true;
						visit(amgraph.adjmulist[j].data);
						q.EnQueue(j);
					}
				}
			}
		}
	}
	cout<<endl;
	return true;
}


template <class T>
void AMGraph<T>::MarkUnVisited()
{
	EBox *p;
	for(int i = 0;i<amgraph.vexnum;i++)
	{
		p = amgraph.adjmulist[i].firstedge;
		while(p)
		{
			p->mark = 0;
			p = (p->ivex == i) ? p->ilink : p->jlink;
		}
	}
}


template <class T>
void AMGraph<T>::DisPlay()
{
	int i; EBox *p;
	//�ñߵķ��ʱ��Ϊδ����
	MarkUnVisited();
	cout<<amgraph.vexnum<<"������"<<endl;
	for(i = 0;i<amgraph.vexnum;i++)
	{
		cout<<amgraph.adjmulist[i].data<<" ";
	}
	cout<<endl;
	cout<<amgraph.edgenum<<"����"<<endl;
	for(i = 0;i<amgraph.vexnum;i++)
		//���δ�ÿ�������������
	{
		p = amgraph.adjmulist[i].firstedge;
		while(p)
		{
			if(p->ivex == i)
				//�ߵ�i����ö����й�
			{
				if(p->mark == 0)
					//�����ظ����
				{
					cout<<amgraph.adjmulist[i].data<<"<->"<<amgraph.adjmulist[p->jvex].data<<" ";
					p->mark = 1;
					if(p->info)
					cout<<"�ñߵ������Ϣ"<<p->info<<" ";
					cout<<endl;
				}
				p = p->ilink;
			}
			else
				//�ߵ�j����ö����й�
			{
				if(p->mark == 0)
					//�����ظ����
				{
					cout<<amgraph.adjmulist[p->ivex].data<<"-"<<amgraph.adjmulist[i].data<<" ";
					p->mark = 1;
					if(p->info)
					cout<<"�ñߵ������Ϣ"<<p->info<<" ";
					cout<<endl;
				}
				p = p->jlink;
			}
		}
	}
}

