/*-------------------��ĳ��Դ�㵽���������������·����ͼ��������洢�ṹ������ʾ��---------------*/

#include "ArrayGraph.h"

template <class T>
void MGraph<T>::ShortestPath_DIJ(int v0,PathMatrix_1 &P,ShortPathTable &D)
//��Dijkstra�㷨����������v0���㵽���ඥ��v�����·��P[v]����Ȩ����
//D[v]����P[v][w]Ϊtrue����w�Ǵ�v0��v��ǰ������·���ϵĶ��㡣
//final[v]Ϊtrue���ҽ���v��S�����Ѿ���ô�v0��v�����·��
{ 
	int v,w,i,j,min;
	bool final[MAX_VERTEX_NUM]; // ��������Ϊ���ʾ�ö��㵽v0����̾������������ֵΪ��
	for(v = 0;v<mgraph.vexnum;v++)
	{
		final[v] = false; // ���ֵ
		D[v] = mgraph.arcs[v0][v].adj; // D[]���v0��v����̾��룬��ֵΪv0��v��ֱ�Ӿ���
		for(w = 0;w<mgraph.vexnum;w++)
			// ���·��
		{
			P[v][w] = false; 
		}
		if(D[v]<infinity) 
			// v0��v��ֱ��·��
		{
			P[v][v0] = P[v][v] = true; // һά����p[v][]��ʾԴ��v0��v���·��ͨ���Ķ���
		}
	}
	D[v0] = 0; // v0��v0����Ϊ0
	final[v0] = true; // v0���㲢��S��
	for(i = 1;i<mgraph.vexnum;i++) 
		// ����G.vexnum-1������
	{ 
		// ��ʼ��ѭ����ÿ�����v0��ĳ������v�����·��������v����S��
		min = infinity; // ��ǰ��֪��v0�����������룬���ֵΪ��
		for(w = 0;w<mgraph.vexnum;w++) 
			// �����ж�����
		{
			if(!final[w]&&D[w]<min) //��S��֮��Ķ���������v0����Ķ��㣬�����丳��v�����븳��min
			{
				v = w;
				min = D[w];
			}
		}
		final[v] = true; // ��v0�����v����S��
		for(w = 0;w<mgraph.vexnum;w++) 
			// �����²���Ķ��㣬���²���S���Ķ��㵽v0�ľ����·������
		{
			if(!final[w]&&min<infinity&&mgraph.arcs[v][w].adj<infinity&&
				(min+mgraph.arcs[v][w].adj<D[w]))
				// w������S����v0��v��w�ľ���<Ŀǰv0��w�ľ���
			{ 
				D[w] = min+mgraph.arcs[v][w].adj; // ����D[w]
				for(j = 0;j<mgraph.vexnum;j++) 
					// �޸�P[w]��v0��w�����Ķ������v0��v�����Ķ����ټ��϶���w
				{
					P[w][j] = P[v][j];
				}
				P[w][w] = true;
			}
		}
	}
}

