/*----------------------ͼ���ڽӱ�ʾ�洢------------------------*/
// #include "CSTree.h"

#ifndef ALGRAPH
#define ALGRAPH


#ifndef MAX_VERTEX_NUM 
#define MAX_VERTEX_NUM 20  //��󶥵���
#endif


struct ArcNode{
	int adjvex;      //�û���ָ��Ķ����λ��
	struct ArcNode *nextarc; //ָ����һ������ָ��
	char *info;       //�û������Ϣ��ָ��
};


template <class T>
struct VNode{
	T data;    //������Ϣ
	ArcNode *firstarc;//ָ���һ�������ö����ָ��
};

template <class T>
struct _ALGraph{
	VNode<T> vertices[MAX_VERTEX_NUM];//���㼯
	int vexnum;//������
	int arcnum;//����
	int kind;//ͼ����
};



template <class T>
class ALGraph{
	
public:
	_ALGraph<T> algraph;
	int visited[MAX_VERTEX_NUM];
    int count;  //�ڹؽڵ������ͨ�����жԷ��ʼ���
	int low[MAX_VERTEX_NUM]; 
	void CreateGraph();                                  //v��ͼ�Ķ��㼯 vr��ͼ�ı߼�  //���캯��
	void DestroyGraph();                                 //��������ͼ
	int LocateVex (T u);                    //ͼ���ڣ�ͼ�д��ڶ���u �򷵻ظö�����ͼ�е�λ��
	void DisPlay();             //���ͼ
	bool (*VisitFunc)(T v);                 //���ʶ���v�ķ�ʽ
	void DFSArticul(int index); //�ӵ�index���������������ȱ���ͼ���ҵ�������ؽڵ�
	void FindArticul();   //���Ҳ����G��ȫ���ؽڵ�
};

template <class T>
int ALGraph<T>::LocateVex(T u) //ͼ���ڣ�ͼ�д��ڶ���u �򷵻ظö�����ͼ�е�λ��
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
void ALGraph<T>::CreateGraph()//����ͼ
{
	int i,j,k;
	char w[10];//Ȩֵ
	T v1,v2;
	cout<<"��������Ҫ��ͼ������!  ����ͼ(0)��������(1)������ͼ(2)��������(3)";
	cin>>algraph.kind;
	cout<<"������ͼ�Ķ�����������: ";
	cin>>algraph.vexnum>>algraph.arcnum;
	cout<<"������"<<algraph.vexnum<<"�������ֵ: ";
	for(i = 0;i<algraph.vexnum;i++)
		// ��ʼ��������
	{
		cin>>algraph.vertices[i].data;
		algraph.vertices[i].firstarc = false;
	}
	if(algraph.kind%2)
	{
		cout<<"������ÿ�������ߣ���Ȩֵ(С��10���ַ�)����β����ͷ: "<<endl;
	}
	else
	{
		cout<<"������ÿ�������ߣ��Ļ�β����ͷ: "<<endl;
	}
	//�����������
	for(k = 0;k<algraph.arcnum;k++)
	{
		
		if(algraph.kind%2)
		{
			cout<<"������һ�������ߣ���Ȩֵ(С��10���ַ�)����β����ͷ: ";
			cin>>w>>v1>>v2;
		}
		else
		{
			cout<<"������һ�������ߣ��Ļ�β����ͷ: ";
			cin>>v1>>v2;
		}
		i = LocateVex(v1);
		j = LocateVex(v2);
        ArcNode *p = new ArcNode; //����һ���µĻ����
		p->adjvex = j; p->nextarc = false;
		if(algraph.kind%2)
			//��
		{
			p->info = new char[strlen(w)+1];
			strcpy(p->info,w);
		}
		else
			//ͼ
		{
			p->info = false;
		}
		p->nextarc = algraph.vertices[i].firstarc; //���ڱ�ͷ
		algraph.vertices[i].firstarc = p;
		
		if(algraph.kind>1)
			//����
		{
			ArcNode *p = new ArcNode; //����һ���µĻ����
			p->adjvex = i; p->nextarc = false;
			if(algraph.kind == 3)
				//������
			{
				p->info = new char[strlen(w)+1];
				strcpy(p->info,w);
			}
			else
				//����ͼ
			{
				p->info = false;
			}
			p->nextarc = algraph.vertices[j].firstarc; //���ڱ�ͷ
			algraph.vertices[j].firstarc = p;
		}
	}
}


template <class T>
void ALGraph<T>::DestroyGraph()//��������ͼ
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
			if(algraph.kind%2)
				//��,���ͷ�Ȩֵ��Ϣ
			{
				delete p->info;
			}
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
	switch(algraph.kind)
	{
	case 0:cout<<"����ͼ"<<endl;
		   break;
	case 1:cout<<"������"<<endl;
		   break;
	case 2:cout<<"����ͼ"<<endl;
		   break;
	case 3:cout<<"������"<<endl;
		   break;
	}
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
			if(algraph.kind<2)
				//����
			{
				cout<<algraph.vertices[i].data<<"->"<<algraph.vertices[p->adjvex].data<<'\t';
				if(algraph.kind == 1)
					//������
				{
					cout<<*(p->info);
				}
				cout<<endl;
			}
			else
				//����
			{
				if(i<p->adjvex)
					//�����������ʱ��һ���߱��������
				{
					cout<<algraph.vertices[i].data<<"-"<<algraph.vertices[p->adjvex].data<<'\t';
					if(algraph.kind == 3)
						//������
					{
						cout<<*(p->info);
					}
					cout<<endl;
				}
			}
			p = p->nextarc;
		}
	}
} 
#endif