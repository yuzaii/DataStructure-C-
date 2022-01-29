/*---------����ͼ����ͨ��������������ͼ�����ڽӱ�洢�ṹ������ʾ��----------*/
#include "AdjLGraph.h" 

template <class T>
bool visit(T v)
{
	cout<<v<<" ";
	return true;
}


template <class T>
void ALGraph<T>::DFSTree(int index,CSTree<T>* &t)
//�ӵ�index���������������ȱ���ͼ������Ϊt��������
{

	CSTree<T> *p,*q;
	T v1;int w;
	visited[index] = true;
	bool firsttag = true; 
	v1 = GetVex(index);
	for(w = FirstAdjVex(v1);w>=0;w = NextAdjVex(v1,GetVex(w)))
		//w����Ϊv���ڽӶ���
	{
		if(visited[w] == false)
		{
			p = new CSTree<T>;//���亢�ӽ��
			p->data = GetVex(w);
			p->firstchild = false;
			p->nextsibling = false;
			if(firsttag)
				//w��v�ĵ�һ��δ�����ʵ��ڽӶ��㣬��Ϊ�������ӽ��
			{
				t->firstchild = p;
				firsttag = false;
			}
			else
				//w��v������δ�����ʵ��ڽӶ��㣬��Ϊ��һ�ڽӶ�������ֵ�
			{
				q->nextsibling = p;
			}
			q = p;
			DFSTree(w,q);//�ӵ�w���������������ȱ���ͼG��������������*q
		}
	}
}


template <class T>
void ALGraph<T>::DFSForest(CSTree<T> * &t) 
//��������ͼ�������������ɭ�ֵĺ����ֵ�����  
{
	CSTree<T> *p,*q;
	int index;
	t = false;
	for(index = 0;index<algraph.vexnum;index++)
	{
		visited[index] = false;
	}
	for(index = 0;index<algraph.vexnum;index++)
		//�ӵ�0��λ�õĶ�������
	{
		if(visited[index] == false)
			//��index�����㲻�������� 
		{
			//�����Ե�index������Ϊ����������
			p = new CSTree<T>;
			p->data = GetVex(index);
			p->firstchild = false;
			p->nextsibling = false;
			if(!t)
			{
				t = p;//t�ǵ�һ���������ĸ�
			}
			else
			{
				q->nextsibling = p;//ǰһ�õĸ����ֵ��������������ĸ�
			}
			q = p;  //qָʾ��ǰ�������ĸ�
			DFSTree(index,p);//������pΪ����������

		}
	}
}

template <class T>
void ALGraph<T>::PreOrderTraverse(CSTree<T> * &t,bool (*visit)(T v))
//�ȸ�������������ṹ����t
{
	if(t)
	{
		visit(t->data);//������
		PreOrderTraverse(t->firstchild,visit); //����������
		PreOrderTraverse(t->nextsibling,visit);//����������
	}
}


template <class T>
void ALGraph<T>::BTreetoForest(CSTree<T> * &t)//�����������֧�Ǻ��ӣ��ҷ�֧���ֵܣ�ת����ɭ�֣�
{   CSTree<T>  *q;
    int j=0;
	while(t )
	{
		 	q=t;
			t=t->nextsibling;
			if(t) 
			{	j=j+1;  
				q->nextsibling=false;
			}
			else
			{
				if(j>0)
					j++;
			 }
			if (j==0)
			{	cout<<"�������������Ϊ��"<<endl;
			}
			else
			{	cout<<"�����������ɭ�ֵ�"<<j<<"����Ϊ��"<<endl; 
			}

			PreOrderTraverse(q,visit);
			cout<<endl;
	}
}