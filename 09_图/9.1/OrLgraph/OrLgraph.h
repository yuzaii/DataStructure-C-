/*--------------------------����ͼ��ʮ������洢��ʾ-----------------------------*/
#include <string>
#include "LinkedQueue.h"  
#define MAX_VERTEX_NUM 20  //��󶥵���  
#define MAX_INFO 10  //��Ϣ�Ĵ�С 

struct ArcBox{
	int tailvex,headvex;//�û���β��ͷ����λ��
	ArcBox *hlink,*tlink;//�ֱ�Ϊ��ͷ��ͬ�ͻ�β��ͬ�Ļ�������
	char *info;          //�û��������Ϣָ��
};

template <class T>
struct VexNode{
	T data;
	ArcBox *firstin,*firstout;//�ֱ�ָ��ö���ĵ�һ���뻡�ͳ���
};

template <class T>
struct _OLGraph{
	VexNode<T> xlist[MAX_VERTEX_NUM]; //��ͷ����
	int vexnum,arcnum;//����ͼ�Ķ������ͻ���             
};


template <class T>
class OLGraph{
	
	_OLGraph<T> olgraph;

	bool visited[MAX_VERTEX_NUM];
	
public:
	
	void CreateGraph();                          //v��ͼ�Ķ��㼯 vr��ͼ�ı߼� 

	void DestroyGraph();                         //����ͼ

	int LocateVex (T u);                    //ͼ���ڣ�ͼ�д��ڶ���u �򷵻ظö�����ͼ�е�λ��

	T GetVex(int index);                    //ͼ���ڣ�index��ͼ��ĳ���������� ������v��ֵ

	void PutVex(T v,T value);           //ͼ���ڣ�v��ͼ��ĳ������ ���v��ֵvalue

	int FirstAdjVex(T v);                  //ͼ���ڣ�v��G��ĳ������ ����v�ĵ�һ���ٽӵ����� ������ӵ��򷵻ؿ�

	int NextAdjVex(T v,T w);          //ͼ���ڣ�v��ͼ��ĳ�����㣬w��v���ڽӵ� ����v�������w����һ���ڽӵ����ţ���w��v�����һ���ڽӵ��򷵻ؿ�

	void InsertVex(T v);                   //ͼ���� ��ͼ�������¶���v

	bool DeleteVex(T v);                   //ͼ����   ɾ������v������صĻ�

	bool InsertArc(T v,T w);          //ͼ���ڣ�V��w��ͼ���������� ��ͼ����ӻ�<v��w>
		
	bool DeleteArc(T v,T w);          //ͼ���ڣ�V��w��ͼ���������� ��ͼ��ɾ����<v��w>
	
	bool (*VisitFunc)(T v);                 //���ʶ���v�ķ�ʽ

	void DFS(int index);                        //�ӵ�index����������ݹ��������ȱ���ͼ

	bool DFSTraverse(bool (*visit)(T v));  //ͼ���ڣ���ͼ����������ȱ���
		
	bool BFSTraverse(bool (*visit)(T v));  //ͼ���ڣ���ͼ���й�����ȱ���

	void DisPlay();                             //���ͼ               

};


template <class T>
int OLGraph<T>::LocateVex(T u)
{
	for(int i = 0;i<olgraph.vexnum;i++)
	{
		if(olgraph.xlist[i].data == u)
			return i;
	}
	return -1;
}

template <class T>
void OLGraph<T>::CreateGraph()
{
	int i,j,k;	 
	ArcBox *p;
	T v1,v2;
    cout<<"����������ͼ�Ķ�����������ĸ��� ";
	cin>>olgraph.vexnum>>olgraph.arcnum ;
	cout<<"������"<<olgraph.vexnum<<"�������ֵ "<<endl;
    for(i = 0;i<olgraph.vexnum;i++)
		//��ʼ����ͷ����
	{
		cin>>olgraph.xlist[i].data;
		olgraph.xlist[i].firstin = false;
		olgraph.xlist[i].firstout = false;
	}
	cout<<"������"<<olgraph.arcnum<<"�����Ļ�β�ͻ�ͷ"<<endl;
	for(k = 0;k<olgraph.arcnum;k++)
		//�����������ʮ������
	{
		cin>>v1>>v2;
		i = LocateVex(v1);
		j = LocateVex(v2);
		p = new ArcBox;         //����һ�������
		p->tailvex = i; p->headvex = j; //�Ի���㸳ֵ
		//������뻡�ͳ��������ͷ�Ĳ���
		p->hlink = olgraph.xlist[j].firstin; 
		p->tlink = olgraph.xlist[i].firstout;
		olgraph.xlist[j].firstin = olgraph.xlist[i].firstout = p;
		p->info = false;
	}
}


template <class T>
void OLGraph<T>::DestroyGraph()
{
	int i;
	ArcBox *p,*q;
	for(i = 0;i<olgraph.vexnum;i++)
	{
		p = olgraph.xlist[i].firstout;//�����Գ����������㹻��
		while(p)
		{
			q = p;
			p = p->tlink;
			if(q->info)
			{
				delete q->info;
			}
			delete q;
		}
	}
	olgraph.arcnum = 0;
	olgraph.vexnum = 0;
}

template <class T>
T OLGraph<T>::GetVex(int index)
{
	if(index<0||index>=olgraph.vexnum)
		return "false";
	return olgraph.xlist[index].data;
}


template <class T>
void OLGraph<T>::PutVex(T v,T value)
{
	int i = LocateVex(v);
	if(i<0)
		return;
	olgraph.xlist[i].data = value;
}

template <class T>
int OLGraph<T>::FirstAdjVex(T v)
{
	int i = LocateVex(v);
	ArcBox *p = olgraph.xlist[i].firstout;
	if(p)
		return p->headvex;
	else
		return -1;
}

template <class T>
int OLGraph<T>::NextAdjVex(T v,T w)
{
	int i = LocateVex(v);
	int j = LocateVex(w);
	ArcBox *p = olgraph.xlist[i].firstout;
	while(p&&p->headvex!=j)
	{
		p = p->tlink;
	}
	if(p)
		//w����
	{
		p = p->tlink;//
	}
	if(p)
		//�����w���ڽӵ����
	{
		return p->headvex;
	}
	else
	{
		return -1;
	}
}


template <class T>
void OLGraph<T>::InsertVex(T v)
{
	olgraph.xlist[olgraph.vexnum].data = v;
    olgraph.xlist[olgraph.vexnum].firstin = olgraph.xlist[olgraph.vexnum].firstout = false;
    olgraph.vexnum++;
}

template <class T>
bool OLGraph<T>::DeleteVex(T v)
{
    if(LocateVex(v)<0)
		//�ж϶����Ƿ����
		return false;
	int j,k;
	ArcBox *p,*q;
	k = LocateVex(v);
	if(k<0)
		return false;
	/*---ɾ������v�ĳ���---*/
	for(j = 0;j<olgraph.vexnum;j++)
		//ɾ������v�ĳ���������������뻡
	{
		if(j == k)
			continue;
		p = olgraph.xlist[j].firstin;
		while(p)
		{
			if(p->tailvex == k&& p == olgraph.xlist[j].firstin)
				//��ɾ���Ϊ�׽��
			{
				olgraph.xlist[j].firstin = p->hlink;
				break;
			}
			else if(p->tailvex != k)
				//δ�ҵ���ɾ���
			{
				q = p;
				p = p->hlink;
			}
			else
				//�ҵ���ɾ����Ҳ����׽��
			{
				q->hlink = p->hlink;
				break;
			}
		}
	}
	p = olgraph.xlist[k].firstout;
	while(p)
		//ɾ���붥��v�йصĳ���
	{
		q = p->tlink;
		if(p->info)
		{
			delete p->info;
		}
		delete p;
		olgraph.arcnum --;
		p = q;
	}
	/*---ɾ������v���뻡---*/
	for(j = 0;j<olgraph.vexnum;j++)
		//ɾ������v���뻡����������ĳ���
	{
		if(j == k)
			continue;
		p = olgraph.xlist[j].firstout;
		while(p)
		{
			if(p->headvex == k&& p == olgraph.xlist[j].firstout)
				//��ɾ���Ϊ�׽��
			{
				olgraph.xlist[j].firstout = p->tlink;
				break;
			}
			else if(p->headvex != k)
				//δ�ҵ���ɾ���
			{
				q = p;
				p = p->tlink;
			}
			else
				//�ҵ���ɾ����Ҳ����׽��
			{
				q->tlink = p->tlink;
				break;
			}
		}
	}
	p = olgraph.xlist[k].firstin;
	while(p)
		//ɾ���붥��v�йصĳ���
	{
		q = p->hlink;
		if(p->info)
		{
			delete p->info;
		}
		delete p;
		olgraph.arcnum --;
		p = q;
	}

	for(j = k+1;j<olgraph.vexnum;j++)
		//��Ҫ����k�Ķ�������ǰ��
	{
		olgraph.xlist[j-1] = olgraph.xlist[j];
	}

    olgraph.vexnum --;

	for(j = 0;j<olgraph.vexnum;j++)
		//�����Ŵ���k��Ҫ-1
	{
		p = olgraph.xlist[j].firstout;
		while(p)
		{
			if(p->tailvex>k)
				p->tailvex--;
			if(p->headvex>k)
				p->headvex--;
			p = p->tlink;
		}
	}
	return true;
}


template <class T>
bool OLGraph<T>::InsertArc(T v,T w)
{
	 
	int i = LocateVex(v);
	int j = LocateVex(w);
	if(i<0||j<0)
		return false;
	ArcBox * p = new ArcBox;
	p->tailvex = i;
	p->headvex = j;
	//�������뻡�ͳ�������ͷ
	p->hlink = olgraph.xlist[j].firstin;
	p->tlink = olgraph.xlist[i].firstout;
    olgraph.xlist[j].firstin = olgraph.xlist[i].firstout = p;
    olgraph.arcnum++; 
		p->info = false;//����Ļ�������������Ϣ
	return true;
}


template <class T>
bool OLGraph<T>::DeleteArc(T v,T w)
{
	ArcBox *p1,*p2;
	int i = LocateVex(v);
	int j = LocateVex(w);
	if(i<0||j<0||i==j)
		return false;
	//�������ӳ���������ɾȥ
	p2 = olgraph.xlist[i].firstout;
	if(p2&&p2->headvex == j)
		//��ɾ���Ϊ��һ�����
	{
		olgraph.xlist[i].firstout = p2->tlink;
	}
	else
	{
		while(p2&&p2->headvex != j)
			//�����
		{
			p1 = p2;
			p2 = p2->tlink;
		}
		if(p2)
			//û����β
		{
			p1->tlink = p2->tlink;
		}
	}
	//���������뻡������ɾȥ
	p2 = olgraph.xlist[j].firstin;
	if(p2&&p2->tailvex == i)
		//��ɾ���Ϊ��һ�����
	{
		olgraph.xlist[j].firstin = p2->hlink;
	}
	else
	{
		while(p2&&p2->tailvex != i)
			//�����
		{
			p1 = p2;
			p2 = p2->hlink;
		}
		if(p2)
			//û����β
		{
			p1->hlink = p2->hlink;
		}
	}
	if(p2->info)
	{
		delete p2->info;
	}
	delete p2;
	olgraph.arcnum--;
	return true;
}


template <class T>
void OLGraph<T>::DisPlay()
{
	ArcBox *p;
	cout<<"��"<<olgraph.vexnum<<"������"<<olgraph.arcnum<<"����"<<endl;
	for(int i = 0;i<olgraph.vexnum;i++)
	{
		cout<<"����"<<olgraph.xlist[i].data<<"����ȣ�";
		p = olgraph.xlist[i].firstin;
		while(p)
		{
			cout<<olgraph.xlist[p->tailvex].data<<" ";
			p = p->hlink;
		}
		cout<<"���ȣ�";
		p = olgraph.xlist[i].firstout;
		while(p)
		{
			cout<<olgraph.xlist[p->headvex].data<<" ";
			p = p->tlink;
		}
		p = olgraph.xlist[i].firstout;
		while(p)
			//�����Ϣ
		{
			if(p->info)
				cout<<"����Ϣ��"<<p->info<<" ";
			p = p->tlink;
		}
		cout<<endl;
	}
}


template <class T>
void OLGraph<T>::DFS(int index)
{
	ArcBox *p;
	visited[index] = true;
	if(!VisitFunc(olgraph.xlist[index].data))
		return;
	p = olgraph.xlist[index].firstout;
	while(p&&visited[p->headvex])
		//pû����β�Ҹû���ͷ�����Ѿ�������
	{
		p = p->tlink; //������һ�����
	}
	if(p&&!visited[p->headvex])
		//�û���ͷ����δ������
	{
		DFS(p->headvex);
	}

}


template <class T>
bool OLGraph<T>::DFSTraverse(bool (*visit)(T v))
{
	int i ;
    VisitFunc = visit;
   	for(i = 0;i<MAX_VERTEX_NUM;i++)
	{
		visited[i] = false;
	}
    for(i = 0;i<olgraph.vexnum;i++)
		//��ÿ��δ�����ʵĶ������������ȱ���
    {
	   if(!visited[i])
		   DFS(i);
    }
	cout<<endl;
    return true;
}


template <class T>
bool OLGraph<T>::BFSTraverse(bool (*visit)(T v))
{
	LinkedQueue<int> q;int i,j,receive; T u1;
	for(i = 0;i<MAX_VERTEX_NUM;i++)
	{
		visited[i] = false;
	}
	for(i = 0;i<olgraph.vexnum;i++)
		//��ÿ��δ�����ʵĶ�����й�����ȱ���
	{
		if(!visited[i])
		{
			visited[i] = true;
			if(!visit(olgraph.xlist[i].data))
				return false;
			q.EnQueue(i);
			while(!q.IsEmpty())
			{
				q.DeQueue(receive); //��ͷԪ�س��Ӳ���Ϊreceive
				u1 = GetVex(receive);
				for(j = FirstAdjVex(u1);j>=0;j = NextAdjVex(u1,GetVex(j)))
				{
					if(!visited[j])
					{
						visited[j] = true;
						if(!visit(olgraph.xlist[j].data))
							return false;
						q.EnQueue(j);
					}
				}
			}
		}
	}
	cout<<endl;
	return true;
}
