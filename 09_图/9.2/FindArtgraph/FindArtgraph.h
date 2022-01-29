/*--------------------�ؽڵ������ͨ������ͼ�����ڽӱ�洢�ṹ������ʾ��----------------------*/

#include "AdjLGraph.h"
bool flg=false;//���޹ؽڵ���ڱ�־

template <class T>
void ALGraph<T>::DFSArticul(int index)//�ӵ�index���������������ȱ���ͼ���ҵ�������ؽڵ�
{
	int min,w;
	ArcNode *p;
	visited[index] = min = ++count; //index�ǵ�count�����ʵĶ����λ��
	for(p = algraph.vertices[index].firstarc;p;p = p->nextarc)
		//���λ��Ϊindex�Ķ����ÿһ���ڽӶ���
	{
		w = p->adjvex; //w���λ��Ϊindex�Ķ�����ڽӶ����λ��
		if(visited[w] == false)
			//λ��Ϊw�Ķ���δ������
		{
			DFSArticul(w);//����ǰ���low[w]
			if(low[w]<min)
			{
				min = low[w];
			}
			if(low[w]>=visited[index])
			{	
				flg=true;
				cout<<"����algraph.vertices["<<index<<"].data��һ���ؽڵ㣺"<<" "<<algraph.vertices[index].data<<endl;//����ؽڵ�
			}
		}
		else if(visited[w]<min)
			//w�ѷ��ʣ�w��v0���������ϵ�����
		{
			min = visited[w];
		}
	}
	low[index] = min;
}
	
template <class T>
void ALGraph<T>::FindArticul() //���Ҳ����G��ȫ���ؽڵ�
{
	int i,index;
	ArcNode *p;
	count = 1;//��ʼ��countΪ1
    low[0] = visited[0] = 1;//��λ��Ϊ0�Ķ�����Ϊ�������ĸ�
	for(i = 1;i<algraph.vexnum;i++)
		//��ʼ����δ���ʶ���ķ�������
	{
		visited[i] = 0;
	}
	p = algraph.vertices[0].firstarc;
	index = p->adjvex;
	DFSArticul(index); //�ӵ�index���������������Ȳ��ҹؽڵ�
	if(count<algraph.vexnum)
		//�������ĸ�����������������
	{	
		flg=true;
		cout<<"�� algraph.vertices[0].data��һ���ؽڵ㣺"<<algraph.vertices[0].data<<endl;//���ǹؽڵ㣬���
		while(p->nextarc)
		{
			p = p->nextarc;
			index = p->adjvex;
			if(visited[index] == 0)
			{
				DFSArticul(index);
			}
		}
	}
}