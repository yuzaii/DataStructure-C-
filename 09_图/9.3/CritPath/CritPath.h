/*----------------�ؼ�·����ͼ�����ڽӱ�洢�ṹ������ʾ��--------------*/

#include "AdjLGraph.h"
#include "SqStack.h"


template <class T>
bool ALGraph<T>::TopologicalOrder(SeqStack<int> &t)
// ��������¼������緢��ʱ��ve
{
	int j,k,count,indegree[MAX_VERTEX_NUM];
	SeqStack<int> s;
	ArcNode *p;
	FindInDegree(indegree); // �Ը����������indegree[] �����������������ã�������ALGraph.h��ʵ��
	for(j = 0;j<algraph.vexnum;j++)
		//����0���ջS
	{
		if(!indegree[j])
		{
			s.Push(j);
		}
	}
	//��ʼ��
	count = 0; 
	for(j = 0;j<algraph.vexnum;j++)
	{
		ve[j] = 0;
	}
	while(!s.IsEmpty())
		//S�ǿ�
	{
		s.Pop(j);
		t.Push(j); count++; //j�Ŷ�����Tջ������
		for(p = algraph.vertices[j].firstarc;p;p = p->nextarc)
			//��j�Ŷ����ÿ���ڽӵ����ȼ�1
		{
			k = p->adjvex;
			if(--indegree[k] == 0)
				//��ȼ�Ϊ0����ջ
			{
				s.Push(k);
			}
			if(ve[j] + *(p->info) >ve[k])
			{
				ve[k] = ve[j] + *(p->info);
			}
		}
	}
	if(count<algraph.vexnum)
	{
		cout<<"������ͼ�л�·"<<endl;
		return false;
	}
	else
	{
		return true;
	}
}

template <class T>
bool ALGraph<T>::CriticalPath()
//���ͼ�ĸ���ؼ��
{
	int vl[MAX_VERTEX_NUM];
	SeqStack<int> t;
	int i,j,k,ee,el,dut;
	ArcNode *p;
	char tag;
	if(!TopologicalOrder(t))
		//��������
	{
		return false;
	}
	j = ve[0];
	for(i = 1;i<algraph.vexnum;i++)
		//j����ve�����ֵ
	{
		if(ve[i]>j)
		{
			j = ve[i];
		}
	}
	for(i = 0;i<algraph.vexnum;i++)
		//��ʼ������ʱ�����ٷ���ʱ�䣨���ֵ)
	{
		vl[i] = j;//��ɵ�����緢��ʱ��
	}
	while(!t.IsEmpty())
		//������������������vlֵ
	{
		for(t.Pop(j),p = algraph.vertices[j].firstarc;p;p = p->nextarc)
		{
			k = p->adjvex;
			dut = *(p->info); //dut<j,k>
			if(vl[k]-dut<vl[j])
			{
				vl[j] = vl[k]-dut;
			}
		}
	}
	cout<<"j  k  dut  ee  el  tag"<<endl;
	for(j = 0;j<algraph.vexnum;j++)
		//��ee el�͹ؼ��
	{
		for(p = algraph.vertices[j].firstarc;p;p = p->nextarc)
		{
			k = p->adjvex;
			dut = *(p->info);
			ee = ve[j];
			el = vl[k]-dut;
			tag = (ee == el)?'*':' ';
			cout<<j<<"  "<<k<<"  "<<dut<<"    "<<ee<<"   "<<el<<"   "<<tag<<endl;//����ؼ��
		}
	}
	cout<<"�ؼ�·��Ϊ��"<<endl;
	for(j = 0;j<algraph.vexnum;j++)
		//��ee el�͹ؼ����ͬ�ϣ�
	{
		for(p = algraph.vertices[j].firstarc;p;p = p->nextarc)
		{
			k = p->adjvex;
			dut = *(p->info);
			if(ve[j] == vl[k]-dut)
			{
				cout<<algraph.vertices[j].data<<"->"<<algraph.vertices[k].data<<endl;//����ؼ��
			}
		}
	}
	return true;
}