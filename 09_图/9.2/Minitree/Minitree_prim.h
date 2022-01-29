/*---------------��С��������ͼ��������洢�ṹ������ʾ��----------*/
//#include "MGraph.h"
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

#ifndef MGRAPH
#define MGRAPH
 
#define MAX_VERTEX_NUM 20 //��󶥵��� 
 
#define MAXEDGE 190 //ͼ�е�������
const int infinity = INT_MAX;

struct ArcCell{
	int adj;    //����Ȩͼ��1��0��ʾ�Ƿ����ڣ��Դ�Ȩͼ����ΪȨֵ����
    char *info; //�û��������Ϣ
};


template <class T>
	struct miniside{
		//��¼�Ӷ��㼯U�����㼯V-U�Ĵ�����С�ıߵĸ������鶨��
		T adjvex;
		int lowcost;
	};

template <class T>
	struct EdgeType{
		T v1;
		T v2;
		int cost;
	};

template <class T>
	struct _MGraph{
		T vexs[MAX_VERTEX_NUM];
		ArcCell arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
		int vexnum;
		int arcnum;
		int kind;
	};

template <class T>
	class MGraph{

		_MGraph<T> mgraph;

		bool visited[MAX_VERTEX_NUM];

	public:	
		bool  CreateUDN();                    //��������ͼ   
	    int Minimum(miniside<T> *SZ);        //��������sz�е�lowcost����С��ֵ
        int LocateVex (T u);                 //ͼ���ڣ�ͼ�д��ڶ���u �򷵻ظö�����ͼ�е�λ��
		void DisPlay();						//��ʾͼ
		void MiniSpanTree_PRIM(T u);         //������ķ�㷨�Ӷ���u��ʼ����������С�������������������
        void DestroyGraph();                      //������������ͼ
	};
template <class T>
void MGraph<T>::DisPlay()
{
	int i,j;	 
	 
	//���Ȩֵ���ڽӾ���
	cout<<"���������ڽӾ���Ϊ"<<endl;
	for(i = 0;i<mgraph.vexnum;i++)
	{
		for(j = 0;j<mgraph.vexnum;j++)
		{	if (mgraph.arcs[i][j].adj==infinity)
				cout<<setw(15)<<"��"<<'\t';
			else
				cout<<setw(15)<<mgraph.arcs[i][j].adj<<'\t';
		}
		cout<<endl<<endl;
	}
}



template <class T>
bool MGraph<T>::CreateUDN()  //����������
{
	  int i , j ,w;T v1, v2;
	cout<<"�������������Ķ���������ߵĸ���: ";
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
	mgraph.kind = 3;
	return true;
}
template <class T>
void MGraph<T>::DestroyGraph()//����ͼ
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
	 
	mgraph.vexnum = 0;
	mgraph.arcnum = 0;
}

template <class T>
int MGraph<T>::LocateVex(T u)//ȷ��������ͼ�е�λ��
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
	int MGraph<T>::Minimum(miniside<T> SZ[MAX_VERTEX_NUM])
	//��������sz�е�lowcost����С��ֵ
	{
		int i = 0,min,k,j;
		while(!SZ[i].lowcost)
		{
			i++;
		}
		min = SZ[i].lowcost;//�ҵ���һ����0ֵ
		k = i;//k�ȴ�ŵ�һ����0ֵ��λ��
		for(j = i+1;j<mgraph.vexnum;j++)
			//�ڵ�һ����0ֵ֮��ʼ����Ѱ�ҽ�Сֵ���Ҽ�¼λ��
		{
			if(SZ[j].lowcost>0)
			{
				if(min>SZ[j].lowcost)
					//�ҵ���Сֵ
				{
					min = SZ[j].lowcost;
					k = j;//��¼��Сֵ��λ��
				}
			}
		}
		return k;
	}

template <class T>
	void MGraph<T>::MiniSpanTree_PRIM(T u) 	//������ķ�㷨�Ӷ���u��ʼ����������С�������������������
	{
		int i,j,k;
		miniside<T> closedge[MAX_VERTEX_NUM];
		k = LocateVex(u);
		for(j = 0;j<mgraph.vexnum;j++)
			//��ʼ����������
		{
			if(j != k)
			{
				closedge[j].adjvex = u;
				closedge[j].lowcost = mgraph.arcs[k][j].adj;
			}
		}
		closedge[k].lowcost = 0 ;//��ʼ�����㼯 U = {u}
		cout<<"��С�������ĸ���������Ϊ��"<<endl;
		for(i = 1;i<mgraph.vexnum;i++)
			//����mgraph.vexnumge-1������
		{
			k = Minimum(closedge);//�����һ������λ��
			cout<<closedge[k].adjvex<<"-"<<mgraph.vexs[k]<< "Ȩֵ��"<<closedge[k].lowcost <<endl;
			closedge[k].lowcost = 0;//��λ��Ϊk�Ķ��㲢��u����
			for(j = 0;j<mgraph.vexnum;j++)
				//�¶��㲢��u��������ѡ����С��
			{
				if(mgraph.arcs[k][j].adj<closedge[j].lowcost)
				{
					closedge[j].adjvex = mgraph.vexs[k];
					closedge[j].lowcost = mgraph.arcs[k][j].adj;
				}
			}
		}
}
#endif

