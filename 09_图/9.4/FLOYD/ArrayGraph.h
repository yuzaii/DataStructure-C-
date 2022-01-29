/*---------------�����ʾ��(���ִ���)--------------*/


#include <iostream>
using namespace std;

#ifndef MGRAPH
#define MGRAPH
 
#define MAX_VERTEX_NUM 20 //��󶥵���
  
const int infinity = INT_MAX;

struct ArcCell{
	int adj;    //����Ȩͼ��1��0��ʾ�Ƿ����ڣ��Դ�Ȩͼ����ΪȨֵ����
    char *info; //�û��������Ϣ
};

template <class T>
struct _MGraph{
    T vexs[MAX_VERTEX_NUM];
	ArcCell arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
	int vexnum;
	int arcnum;
	int kind;
};

typedef int PathMatrix_1[MAX_VERTEX_NUM][MAX_VERTEX_NUM]; // ·�����󣬶�ά����
typedef int ShortPathTable[MAX_VERTEX_NUM]; // ��̾����һά����


typedef int PathMatrix_2[MAX_VERTEX_NUM][MAX_VERTEX_NUM][MAX_VERTEX_NUM]; // 3ά����
typedef int DistancMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM]; // 2ά����



template <class T>
class MGraph{
public:		
	_MGraph<T> mgraph;
    bool visited[MAX_VERTEX_NUM];
   void CreateGraph();                                //v��ͼ�Ķ��㼯 vr��ͼ�ı߼�  //���캯��
	void DestroyGraph();                               //������������ͼ
	int LocateVex (T u);                 //ͼ���ڣ�ͼ�д��ڶ���u �򷵻ظö�����ͼ�е�λ��
	bool CreateDN();                         //����������
	bool CreateUDN();                        //����������
	bool (*VisitFunc)(T v);              //���ʶ���v�ķ�ʽ
	void DisPlay();                          //����ڽӾ���
	void ShortestPath_DIJ(int v0,PathMatrix_1 &P,ShortPathTable &D); 
	void ShortestPath_FLOYD(PathMatrix_2 &P,DistancMatrix &D);
};


template <class T>
void MGraph<T>::CreateGraph()//ok
{
	cout<<"��������Ҫ��ͼ������!   ������(0)�� ������(1)";
	cin>>mgraph.kind;
	switch(mgraph.kind)
	{ 
	case 0 :CreateDN();break; 
	case 1:CreateUDN();break;
	default: {cout<<"����ͼ���������"<<endl; MGraph();}
	}
}

template <class T>
void MGraph<T>::DestroyGraph()//ok
{
	if(mgraph.kind<2)
		//����
	{
		for(int i = 0 ;i<mgraph.vexnum;i++)
			for(int j = 0;j<mgraph.vexnum;j++)
			{
				if(mgraph.arcs[i][j].info)
				{
					delete []mgraph.arcs[i][j].info;
					mgraph.arcs[i][j].info = false;
				}
			}
	}
	else
        //����
	{
		for(int i = 0 ;i<mgraph.vexnum;i++)
			for(int j = i+1;j<mgraph.vexnum;j++)
			{
				if(mgraph.arcs[i][j].info)
				{
					delete []mgraph.arcs[i][j].info;
					mgraph.arcs[i][j].info = mgraph.arcs[j][i].info = false;
				}
			}
	}
	mgraph.vexnum = 0;
	mgraph.arcnum = 0;
}


 

 

template <class T>
bool MGraph<T>::CreateDN()//ok
//����������
{
	 int i,j ,w;
	 T v1, v2;
	cout<<"�������������Ķ�����������ĸ���: ";
	cin>>mgraph.vexnum>>mgraph.arcnum ;
	cout<<"�������������: ";
	for(i = 0;i<mgraph.vexnum;i++)
	//���춥������
	{
		cin>>mgraph.vexs[i];
	}
	for(i = 0;i<mgraph.vexnum;i++)	
	//��ʼ���ڽӾ���
	{
		for(j = 0;j<mgraph.vexnum;j++)
		{
			if(i==j)
				mgraph.arcs[i][j].adj = 0;
			else
			    mgraph.arcs[i][j].adj = infinity;
            mgraph.arcs[i][j].info = false;
		}
	}
	for(i = 0;i<mgraph.arcnum;i++)
	//�����ڽӾ���
	{
		cout<<"������һ���������,�յ�,Ȩֵ: ";
		cin>>v1>>v2>>w;
		int m = LocateVex(v1);
		int n = LocateVex(v2);
		mgraph.arcs[m][n].adj = w;// <v1, v2>��Ȩֵ
		 
	}
	mgraph.kind = 0;
	return true;
}

template <class T>
bool MGraph<T>::CreateUDN()//ok
//����������
{
	  int i , j ,w;
	  T v1, v2;
	cout<<"�������������Ķ���������ߵĸ���: ";
	cin>>mgraph.vexnum>>mgraph.arcnum ;
	cout<<"������������� ";
	for(i = 0;i<mgraph.vexnum;i++)
	//���춥������
	{
		cin>>mgraph.vexs[i];
	}
	for(i = 0;i<mgraph.vexnum;i++)	
	//��ʼ���ڽӾ���
	{
		for(j = 0;j<mgraph.vexnum;j++)
		{
			if(i==j)
				mgraph.arcs[i][j].adj = 0;
			else
				mgraph.arcs[i][j].adj = infinity;
            mgraph.arcs[i][j].info = false;
		}
	}
	for(i = 0;i<mgraph.arcnum;i++)
	//�����ڽӾ���
	{
		cout<<"������һ������������������,Ȩֵ: ";
		cin>>v1>>v2>>w;
		int m = LocateVex(v1);
		int n = LocateVex(v2);
		mgraph.arcs[m][n].adj = w;// <v1, v2>
        mgraph.arcs[n][m].adj = w;// <v2, v1>
		 
	}
	mgraph.kind = 1;
	return true;
}

template <class T>
int MGraph<T>::LocateVex(T u)//ok
{
	for(int i = 0 ;i<MAX_VERTEX_NUM;i++)
	{
		if(u == mgraph.vexs[i])
		{
			return i;
		}
	}
	return -1;
}
  

template <class T>
void MGraph<T>::DisPlay()
{
	int i,j;
	char graphkind[7];
	char arckind[3];
	switch(mgraph.kind)
	{
	case 0:strcpy(graphkind,"������");
		   strcpy(arckind,"��"); 
		   break; 
	case 1:strcpy(graphkind,"������");
		   strcpy(arckind,"��");
		   break;
	}
	cout<<mgraph.vexnum<<"������"<<mgraph.arcnum<<"��"<<arckind<<"��"<<graphkind<<endl;
	//�������
	cout<<"����Ϊ";
	for(i = 0;i<mgraph.vexnum;i++)
		cout<<mgraph.vexs[i]<<" ";
	//���Ȩֵ���ڽӾ���
	cout<<"Ȩֵ���ڽӾ���Ϊ"<<endl;
	for(i = 0;i<mgraph.vexnum;i++)
	{
		for(j = 0;j<mgraph.vexnum;j++)
			if(mgraph.arcs[i][j].adj==infinity)
				cout<<"��"<<'\t';
			else
				cout<<mgraph.arcs[i][j].adj<<'\t';
		cout<<endl;
	}//for
}
#endif
