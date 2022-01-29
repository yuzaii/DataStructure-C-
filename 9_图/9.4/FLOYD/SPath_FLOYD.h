/*-------------------ÿһ�Զ���֮������·����ͼ��������洢�ṹ������ʾ��---------------*/

#include "ArrayGraph.h"

template <class T>
void MGraph<T>::ShortestPath_FLOYD(PathMatrix_2 &P,DistancMatrix &D)
// ��Floyd�㷨��������G�и��Զ���v��w֮������·��P[v][w]�����Ȩ����D[v][w]
// ��P[v][w][u]ΪTRUE����u�Ǵ�v��w��ǰ������·���ϵĶ��㡣
{ 
	int u,v,w,i;
	for(v = 0;v<mgraph.vexnum;v++)
		//���Խ��֮���ʼ��֪·��������
	{
		for(w = 0;w<mgraph.vexnum;w++)
		{
			D[v][w] = mgraph.arcs[v][w].adj;// ����v������w��ֱ�Ӿ���
			for(u = 0;u<mgraph.vexnum;u++)
			{
				P[v][w][u] = false;//·�������ֵ
			}
			if(D[v][w]<infinity)
				//��v��w��ֱ��·��
			{
				P[v][w][v] = P[v][w][w] = true;//��v��w��·������v��w����
			}
		}
	}
	for(u = 0;u<mgraph.vexnum;u++)
	{
		for(v = 0;v<mgraph.vexnum;v++)
		{
			for(w = 0;w<mgraph.vexnum;w++)
			{
				if(D[v][u]+D[u][w]<D[v][w])
					//��v��u��w��һ��·������
				{
					D[v][w] = D[v][u]+D[u][w];// ������̾���
					for(i = 0;i<mgraph.vexnum;i++)
					{
						P[v][w][i] = P[v][u][i]||P[u][w][i];//��v��w��·��������v��u�ʹ�u��w������·��
					}
				}
			}
		}
	}
	
}