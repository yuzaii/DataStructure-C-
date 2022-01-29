/*--------------------------����ͼ��ʮ������洢��ʾ-----------------------------*/
#include <string>
  
#define MAX_VERTEX_NUM 20  //��󶥵���  
//#define MAX_INFO 10  //��Ϣ�Ĵ�С 

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
	T finished[MAX_VERTEX_NUM ];
public:
	
	void CreateGraph();                          //v��ͼ�Ķ��㼯 vr��ͼ�ı߼� 

	void DestroyGraph();                         //����ͼ

	int LocateVex (T u);                    //ͼ���ڣ�ͼ�д��ڶ���u �򷵻ظö�����ͼ�е�λ��

	 

	int FirstAdjVex(T v);                  //ͼ���ڣ�v��G��ĳ������ ����v�ĵ�һ���ٽӵ����� ������ӵ��򷵻ؿ�

	int NextAdjVex(T v,T w);          //ͼ���ڣ�v��ͼ��ĳ�����㣬w��v���ڽӵ� ����v�������w����һ���ڽӵ����ţ���w��v�����һ���ڽӵ��򷵻ؿ�

	 
	
//	bool (*VisitFunc)(T v);                 //���ʶ���v�ķ�ʽ 
	void DisPlay();                             //���ͼ 
  void  Get_SGraph( ); //��ʮ������ṹ���������ͼG��ǿ��ͨ����
 void   DFS1(  int v);//��һ��������ȱ������㷨 
 void  DFS2(  int v);//�ڶ��������������ȱ������㷨

};
 int count; //count�ڵ�һ��������ȱ���������ָʾfinished��������λ��
template <class T>
 void OLGraph<T>::Get_SGraph( ) //��ʮ������ṹ���������ͼG��ǿ��ͨ����
{   int v,i,j; 
	string w; 
		for (v=0;v<olgraph.vexnum;++v) visited[v]=false;
		for(v=0;v<olgraph.vexnum;++v) 
			if(!visited[v])	DFS1( v);
		 finished[count]=olgraph.xlist[v].data ;  
        for (v=0;v<olgraph.vexnum;++v) visited[v]=false;
		cout<<"����ͼ��ǿ��ͨ����"<<endl;
		j=0;
		for( i=olgraph.vexnum-1;i>=0;--i) //�ڶ��������������ȱ���
		{ //T w;
			w=finished[i]; 
			v=LocateVex(w); 
			if(!visited[v])
			{   j=j+1;  
				cout<<endl<<"��"<<j<<"��ǿ��ͨ����:"<<endl ; //��ͬ��ǿ��ͨ�����ڲ�ͬ�������
				DFS2( v);
			}
		}//for
}//Get_SGraph 
 template <class T>
 void OLGraph<T>:: DFS1( int v)//��һ��������ȱ������㷨 
{   ArcBox *p;
    int w;
	visited[v]=true;
	 
	for(p=olgraph.xlist[v].firstout;p;p=p->tlink)
	{
		w=p->headvex;
		if(!visited[w]) DFS1( w);
	}//for
	finished[count++ ]=olgraph.xlist[v].data ; //�ڵ�һ�α����н���finished����
	
}//DFS1 
 template <class T>
 void OLGraph<T>:: DFS2(  int v)//�ڶ��������������ȱ������㷨
 {      ArcBox *p;
        int w;
		visited[v]=true;
		cout<<olgraph.xlist[v].data<<"  "  ; //�ڵڶ��α��������������
		for(p=olgraph.xlist[v].firstin;p;p=p->hlink)
		{
			w=p->tailvex;
			if(!visited[w]) DFS2(w);
		}//for
}//DFS2


template <class T>
int OLGraph<T>::LocateVex(T u) //ͼ���ڣ�ͼ�д��ڶ���u �򷵻ظö�����ͼ�е�λ��
{
	for(int i = 0;i<olgraph.vexnum;i++)
	{
		if(olgraph.xlist[i].data == u)
			return i;
	}
	return -1;
}

template <class T>
void OLGraph<T>::CreateGraph()//v��ͼ�Ķ��㼯 vr��ͼ�ı߼� 
{
	int i,j,k;	 
	ArcBox *p;
	T v1,v2;
    cout<<"����������ͼ�Ķ�����������ĸ���: ";
	cin>>olgraph.vexnum>>olgraph.arcnum ;
	cout<<"������"<<olgraph.vexnum<<"�������ֵ: "<<endl;
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
void OLGraph<T>::DestroyGraph()//����ͼ
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
int OLGraph<T>::FirstAdjVex(T v) //ͼ���ڣ�v��G��ĳ������ ����v�ĵ�һ���ٽӵ����� ������ӵ��򷵻ؿ�
{
	int i = LocateVex(v);
	ArcBox *p = olgraph.xlist[i].firstout;
	if(p)
		return p->headvex;
	else
		return -1;
}

template <class T>
int OLGraph<T>::NextAdjVex(T v,T w)//ͼ���ڣ�v��ͼ��ĳ�����㣬w��v���ڽӵ� ����v�������w����һ���ڽӵ����ţ���w��v�����һ���ڽӵ��򷵻ؿ�
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
void OLGraph<T>::DisPlay()//��ʾͼ
{
	ArcBox *p;
	cout<<"��"<<olgraph.vexnum<<"������"<<olgraph.arcnum<<"����"<<endl;
	for(int i = 0;i<olgraph.vexnum;i++)
	{
		cout<<"����"<<olgraph.xlist[i].data<<"����ȣ�";
		p = olgraph.xlist[i].firstin;
		if (!p ) cout<<"��"<<" ";
		while(p)
		{
			cout<<olgraph.xlist[p->tailvex].data<<" ";
			p = p->hlink;
		}
		cout<<"���ȣ�";
		p = olgraph.xlist[i].firstout;
       if (!p ) cout<<"��"<<" ";
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



