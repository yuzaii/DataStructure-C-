/*----------------------ͼ���ڽӱ�ʾ�洢------------------------*/

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
	VNode<T> vertices[MAX_VERTEX_NUM];//���㼯
	int vexnum;//������
	int arcnum;//����
	int kind;//ͼ����
};

/*#ifndef CSNODE
#define CSNODE
template <class T>
struct CSTree{
	//���Ķ�������洢
	T data;
	CSTree *firstchild; //����
	CSTree *nextsibling;//�ֵ�
};
#endif */


template <class T>
class ALGraph{
	_ALGraph<T> algraph;
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
	bool InsertArc(T v,T w);          //ͼ���ڣ�V��w��ͼ���������� ��ͼ����ӻ�<v��w>��������ͼ����Ӧ���ӶԳƻ�<w��v>
	void DeleteArc(T v,T w);          //ͼ���ڣ�V��w��ͼ���������� ��ͼ��ɾ����<v��w>��������ͼ����Ӧɾ���Գƻ�<w��v>
	bool (*VisitFunc)(T v);                 //���ʶ���v�ķ�ʽ
	void DFS(int index);                        //�ӵ�index����������ݹ��������ȱ���ͼ
	bool DFSTraverse(bool (*visit)(T v));  //ͼ���ڣ���ͼ����������ȱ���
	bool BFSTraverse(bool (*visit)(T v));  //ͼ���ڣ���ͼ���й�����ȱ���
	void DisPlay();             //���ͼ  
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
	int w;//Ȩֵ
	T v1,v2;
	cout<<"��������Ҫ��ͼ������!  ����ͼ(0)��������(1)������ͼ(2)��������(3): ";
	cin>>algraph.kind;
	cout<<"������ͼ�Ķ�����������: ";
	cin>>algraph.vexnum>>algraph.arcnum;
	cout<<"������"<<algraph.vexnum<<"�������ֵ" ;
	for(i = 0;i<algraph.vexnum;i++)
		// ��ʼ��������
	{
		cin>>algraph.vertices[i].data;
		algraph.vertices[i].firstarc = false;
	}
	if(algraph.kind%2)
	{
		cout<<"������ÿ�������ߣ���Ȩֵ����β����ͷ! "<<endl;
	}
	else
	{
		cout<<"������ÿ�������ߣ��Ļ�β����ͷ! "<<endl;
	}
	//�����������
	for(k = 0;k<algraph.arcnum;k++)
	{
		
		if(algraph.kind%2)
		{
			cout<<"������һ�������ߣ���Ȩֵ����β����ͷ: ";
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
			p->info = new int;
			*(p->info) = w;
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
				p->info = new int;
				*(p->info) = w;
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
T ALGraph<T>::GetVex(int index)
{
	if(index<0||index>=algraph.vexnum)
		return false;
	return algraph.vertices[index].data;
}

template <class T>
void ALGraph<T>::PutVex(T v,T value)
{
	int i = LocateVex(v);
	if(i<0) //�ö��㲻����
		return;
	algraph.vertices[i].data = value;
}

template <class T>
int ALGraph<T>::FirstAdjVex(T v)
{
	int i = LocateVex(v);
	ArcNode * p = algraph.vertices[i].firstarc;//pָ���±�Ϊi�ĵ�һ���ڽӵ�
	if(p)
	{
		return p->adjvex;
	}
	else
	{
		return -1;
	}
}

template <class T>
int ALGraph<T>::NextAdjVex(T v,T w)
{
	ArcNode *p;
	int i = LocateVex(v);
	int j = LocateVex(w);
	p = algraph.vertices[i].firstarc;
	while(p&&(p->adjvex!=j))
		//��pָ�򶥵�w
	{
		p = p->nextarc;
	}
	if(!p||!p->nextarc) //û�ҵ�w��w�����һ������
		return -1;
	else
		//�ҵ�w��w�������һ������
	{
		return p->nextarc->adjvex;
	}
}

template <class T>
void ALGraph<T>::InsertVex(T v)
{
	if(algraph.vexnum > MAX_VERTEX_NUM)
		return ;//�޷�����
	if(LocateVex(v)>=0)
		return;
	algraph.vertices[algraph.vexnum].data = v;
	algraph.vertices[algraph.vexnum].firstarc = false;
	algraph.vexnum++;
}

template <class T>
bool ALGraph<T>::DeleteVex(T v)
{
	if(algraph.vexnum>=MAX_VERTEX_NUM)
		return false;
	int i,j; ArcNode *p,*q;
	i = LocateVex(v);
	if(i<0)
		return false;
	p = algraph.vertices[i].firstarc;
	
	while(p)
		//ɾ����vΪ���ȵĻ����
	{
		q = p;
		p = p->nextarc;
		if(algraph.kind%2)
			//��
		{
			delete q->info;
		}
		delete q;
		algraph.arcnum--;
	}
	algraph.vexnum--;
	for(j = i;j<algraph.vexnum;j++) 
		//����v����Ķ���ǰ��
	{
		algraph.vertices[j] = algraph.vertices[j+1];
	}

	for(j = 0;j<algraph.vexnum;j++)
		//ɾ����vΪ��ȵĻ����
	{
		p = algraph.vertices[j].firstarc;
		while(p)
			//�л����
		{
			if(p->adjvex == i)
				//�ҵ���ɾ���
			{
				if(p == algraph.vertices[j].firstarc)
					//��ɾ�����Ϊ��һ���ڽӵ�
				{
					algraph.vertices[j].firstarc = p->nextarc;
					if(algraph.kind%2)
						//��
					{
						delete p->info;
					}
					delete p;
					p = algraph.vertices[j].firstarc;
					if(algraph.kind<2)
						//����
					{
						algraph.arcnum--;
					}
				}
				else
				{
					q->nextarc = p->nextarc;
					if(algraph.kind%2)
						//��
					{
						delete p->info;
					}
					delete p;
					p = q->nextarc;
					if(algraph.kind<2)
						//����
					{
						algraph.arcnum--;
					}
				}
			}
			else
			{
				if(p->adjvex>i)
					//�޸ı���Ķ���λ�����
				{
					p->adjvex--;
				}
				q = p;
				p = p->nextarc;
			}

		}
	}
	return true;
}


template <class T>
bool ALGraph<T>::InsertArc(T v,T w)
{
	ArcNode *p;
	int i,j;
	int w1;
	i = LocateVex(v);
	j = LocateVex(w);
	if(i<0||j<0)
		return false;
	algraph.arcnum++;
	if(algraph.kind%2)
		//��
	{
		cout<<"�����뻡���ߣ�"<<v<<"->"<<w<<"��Ȩֵ";
		cin>>w1;
	}
	p = new ArcNode;
	p->adjvex = j; p->nextarc = false;
	if(algraph.kind%2)
		//��
	{
		p->info = new int;
		*(p->info) = w1;
	}
	else
		//ͼ
	{
		p->info = false;
	}
	//���ڱ�ͷ
	p->nextarc = algraph.vertices[i].firstarc;
	algraph.vertices[i].firstarc = p;
	if(algraph.kind>1)//����
	{
		p = new ArcNode;
	    p->adjvex = i; p->nextarc = false;
		if(algraph.kind == 3)
			//������
		{
			p->info = new int;
		    *(p->info) = w1;
		}
		else
			//����ͼ
		{
			p->info = false;
		}
		//���ڱ�ͷ
		p->nextarc = algraph.vertices[j].firstarc;
	    algraph.vertices[j].firstarc = p;
	}
	return true;
}

template <class T>
void ALGraph<T>::DeleteArc(T v,T w)
{
	ArcNode *p,*q;
	int i,j;
	i = LocateVex(v);
	j = LocateVex(w);
	if(i<0||j<0||i == j)
		return;
	p = algraph.vertices[i].firstarc;
	while(p&&p->adjvex!=j)
		//p������qָ��Ĳ��Ǵ�ɾ�����
	{
		q = p;
		p = p->nextarc;
	}

	if(p&&p->adjvex ==j)
		//�ҵ���<v,w>
	{
		if(p == algraph.vertices[i].firstarc)
		{
			algraph.vertices[i].firstarc = p->nextarc;
		}
		else
		{
			q->nextarc = p->nextarc;
		}
		if(algraph.kind%2)
			//��
		{
			delete p->info;
		}
		delete p;
		algraph.arcnum--;
	}
	if(algraph.kind>1)
		//������ɾ���Գƻ�<w��v>
	{
		p = algraph.vertices[j].firstarc;
		while(p&&p->adjvex!=i)
			//p������qָ��Ĳ��Ǵ�ɾ�����
		{
			q = p;
			p = p->nextarc;
		}
	}
	if(p&&p->adjvex ==i)
		//�ҵ���<w,v>
	{
		if(p == algraph.vertices[j].firstarc)
		{
			algraph.vertices[j].firstarc = p->nextarc;
		}
		else
		{
			q->nextarc = p->nextarc;
		}
		if(algraph.kind == 3)
			//������
		{
			delete p->info;
		}
		delete p;
	}
}

template <class T>
void ALGraph<T>::DFS(int index)
{
	T v1;int i;
	visited[index] = true;//�ѷ���
	VisitFunc(algraph.vertices[index].data);//����index �Ķ���
	v1 = GetVex(index) ;
	for(i = FirstAdjVex(v1);i>=0;i = NextAdjVex(v1,GetVex(i)))
	{
		if(!visited[i])
			DFS(i);
	}
}


template <class T>
bool ALGraph<T>::DFSTraverse(bool (*visit)(T v))
{
	int i ;
    VisitFunc = visit;
   	for(i = 0;i<MAX_VERTEX_NUM;i++)
	{
		visited[i] = false;
	}
    for(i = 0;i<algraph.vexnum;i++)
		//��ÿ��δ�����ʵĶ������������ȱ���
    {
	   if(!visited[i])
		   DFS(i);
    }
	cout<<endl;
    return true;
}


template <class T>
bool ALGraph<T>::BFSTraverse(bool (*visit)(T v))
{
	LinkedQueue<int> q;int i,j,receive; T u1;
	for(i = 0;i<MAX_VERTEX_NUM;i++)
	{
		visited[i] = false;
	}
	for(i = 0;i<algraph.vexnum;i++)
		//��ÿ��δ�����ʵĶ�����й�����ȱ���
	{
		if(!visited[i])
		{
			visited[i] = true;
			if(!visit(algraph.vertices[i].data))
				return false;
			q.EnQueue(i);
			while(!q.IsEmpty())
			{
				q.DeQueue(receive); //��ͷԪ�س��Ӳ���Ϊreceive
				u1= GetVex(receive);
				for(j = FirstAdjVex(u1);j>=0;j = NextAdjVex(u1,GetVex(j)))
				{
					if(!visited[j])
					{
						visited[j] = true;
						if(!visit(algraph.vertices[j].data))
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


