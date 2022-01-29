/*----------------------ͼ���ڽӱ�ʾ�洢------------------------*/

#include "SeqStack.h" 
 #include <string> 
#ifndef ALGRAPH
#define ALGRAPH 
#define MAX_VERTEX_NUM 20  //��󶥵��� 
struct ArcNode{
	int adjvex;      //�û���ָ��Ķ����λ��
	struct ArcNode *nextarc; //ָ����һ������ָ��
	int *info;       //�û������Ϣ��ָ��(Ȩֵ)
};

template <class T>
struct VNode{
	T data;    //������Ϣ
	ArcNode *firstarc;//ָ���һ�������ö����ָ��
};


template <class T>
struct _ALGraph{
	VNode<T> vertices[MAX_VERTEX_NUM];
	int vexnum;
	int arcnum;
	int kind;
};

template <class T>
class ALGraph{
	_ALGraph<T> algraph;
	bool visited[MAX_VERTEX_NUM];
	int ve[MAX_VERTEX_NUM];//���������緢��ʱ��
public:
	void CreateGraph();   //v��ͼ�Ķ��㼯 vr��ͼ�ı߼�  //���캯��
    int LocateVex (T u);  //ͼ���ڣ�ͼ�д��ڶ���u �򷵻ظö�����ͼ�е�λ��
	void DestroyGraph();   //������������ͼ
    void DisPlay();    //���ͼ   
    void FindInDegree(int indegree[]); //�󶥵�����
    bool TopologicalSort(); //��ͼ�޻�·�������ͼ�Ķ����һ���������в�����true�����򷵻�false
	bool TopologicalOrder(SeqStack<int> &T); // ��������¼������緢��ʱ��ve
};


template <class T>
int ALGraph<T>::LocateVex(T u)
{
	for(int i = 0;i<algraph.vexnum;i++)
	{
		if(algraph.vertices[i].data == u)
		{
			return i;
		}
	}
	return -1;

}
template <class T>
void ALGraph<T>::CreateGraph()
{
	int i,j,k;
	T v1,v2;
	cout<<"����������ͼ�Ķ�����������: ";
	cin>>algraph.vexnum>>algraph.arcnum;
	cout<<"������"<<algraph.vexnum<<"�������ֵ: ";
	for(i = 0;i<algraph.vexnum;i++)
		// ��ʼ��������
	{
		cin>>algraph.vertices[i].data;
		algraph.vertices[i].firstarc = false;
	}
 
    for(k = 0;k<algraph.arcnum;k++)
	{
		cout<<"������һ�������ߣ��Ļ�β����ͷ: ";
		cin>>v1>>v2;
        i = LocateVex(v1);
		j = LocateVex(v2);
        ArcNode *p = new ArcNode; //����һ���µĻ����
		p->adjvex = j; p->nextarc = false;
		p->info = false;
		p->nextarc = algraph.vertices[i].firstarc; //���ڱ�ͷ
		algraph.vertices[i].firstarc = p;
		}
}
template <class T>
void ALGraph<T>::DestroyGraph()
{
	int i;
	ArcNode *p,*q;
	for(i = 0;i<algraph.vexnum;i++)
		//�Ӷ������Ϊ0�Ķ��㿪ʼ�����ͷŵ���Ӧ���ڽӱ�
	{
		p = algraph.vertices[i].firstarc;
		while(p)
		{
			q = p->nextarc;
			delete p;//ɾ�������
			p = q;
		}
	}
	algraph.arcnum = 0;
	algraph.vexnum = 0;
}

template <class T>
void ALGraph<T>::DisPlay()
{
	int i;
	ArcNode *p; 
	cout<<algraph.vexnum<<"������:"<<endl;
	//�������
	for(i = 0;i<algraph.vexnum;i++)
	{
		cout<<algraph.vertices[i].data<<" ";
	}
	cout<<endl;
	cout<<algraph.arcnum<<"�������ߣ�:"<<endl;
	for(i = 0;i<algraph.vexnum;i++)
	{
		p = algraph.vertices[i].firstarc;
		while(p)
		{ 
				cout<<algraph.vertices[i].data<<"->"<<algraph.vertices[p->adjvex].data<<'\t';
				 cout<<endl; 
			p = p->nextarc;
		}
	}
}
/*----------------��������ͼ�����ڽӱ�洢�ṹ������ʾ��--------------*/

template <class T>
void ALGraph<T>::FindInDegree(int indegree[]) 
// �󶥵�����
{
	int i;
	ArcNode *p;
	for(i = 0;i<algraph.vexnum;i++)
		//��ʼ��indegree
	{
		indegree[i] = 0; 
	}
	for(i = 0;i<algraph.vexnum;i++)
	{
		p = algraph.vertices[i].firstarc;
		while(p)
		{
			indegree[p->adjvex]++;
			p = p->nextarc;
		}
	}
}

template <class T>
bool ALGraph<T>::TopologicalSort()
// ��ͼ�޻�·�������ͼ�Ķ����һ���������в�����true�����򷵻�false
{
	int i,k,count=0; // ���������������ֵΪ0
	int indegree[MAX_VERTEX_NUM]; // ������飬��Ÿ����㵱ǰ�����
	SeqStack<int> S;//����int�;�̬ջ
	ArcNode *p;
	FindInDegree(indegree); // �Ը����������indegree[] �����������������ã�������ALGraph.h��ʵ��
	for(i = 0;i<algraph.vexnum;i++) 
		// �����ж���i
	{
		if(!indegree[i]) 
			// �������Ϊ0
		{
			S.Push(i); // ��i������ȶ���ջS
		}
	}
	while(!S.IsEmpty()) 
		// ������ȶ���ջS����
	{
		S.Pop(i); // ��ջ1������ȶ������ţ������丳��i
		cout<<algraph.vertices[i].data<<" "; // ���i�Ŷ���
		++count; // �����������+1
		for(p = algraph.vertices[i].firstarc;p;p = p->nextarc)
			// ��i�Ŷ����ÿ���ڽӶ���
		{ 
			k = p->adjvex; // �����Ϊk
			if(!(--indegree[k])) 
				// k����ȼ�1������Ϊ0����k��ջS
			{
				S.Push(k);
			}
		}
	}
	if(count<algraph.vexnum) 
		// ����ȶ���ջS�ѿգ�ͼG���ж���δ���
	{
		cout<<"������ͼ�л�·"<<endl;
		return false;
	}
	else
	{
		cout<<"Ϊһ����������"<<endl;
		return true;
	}
}
#endif