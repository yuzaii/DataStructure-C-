//#include<iostream.h>//cout,cin
#include"process.h"//exit()
#include"stdio.h"//EOF,NULL

template<class T>
struct Node
{
	T data;
	Node<T> *next;//�˴�T����ʡ��
};

template<class T>
class LinkQueue
{
	private:
		Node<T> *front;//��ͷָ��
		Node<T> *rear;//��βָ��
	public:
		LinkQueue();//����ն���
		~LinkQueue();// �����������ͷ����Ӹ����Ĵ洢�ռ�
		void EnQueue(T x);// Ԫ��x���
		T DeQueue();// �Ӷ�Ԫ�س���
		T GetHead();// ȡ��ͷԪ��
		T GetLast();//ȡ��βԪ��
		int QueueEmpty(); // �ж϶��Ƿ�Ϊ��
		void ClearQueue();//
		void QueueTranverse();//
};

template<class T>
LinkQueue<T>::LinkQueue()
{
	front=new Node<T>;//������ͷ���
	front->next=NULL;
	rear=front;//�ն�
}

template<class T>
LinkQueue<T>::~LinkQueue()
{
	Node<T> *p;
	while(front!=NULL)//�Ӷ�ͷ��ʼ���ɾ�������еĽ��
	{
		p=front;//�ݴ汻�ͷŽ��
		front=front->next;//ͷָ�����ָ����һ�����ͷŽ��
		delete p;
	}
}

template<class T>
void LinkQueue<T>::EnQueue(T x)
{
	Node<T> *s;
	s=new Node<T>; s->data=x; //����һ������Ϊx�Ľ��s
	s->next=rear->next;
	rear->next=s; //�½���������β
	rear=s; //�޸�βָ��
	if(front->next==NULL)//�������������Ԫ��㣬front->nextָ����
		front->next=s;
}

template<class T>
T LinkQueue<T>::DeQueue()
{
	T x;
    Node<T> *p;
	if(rear==front) throw"����";//�ӿգ�������
	p=front->next;
	x=p->data;//�ݴ��ͷԪ��
	front->next=p->next;//����ͷ����������ժ��
	if(p->next==NULL) rear=front;//������Ӻ�Ϊ�նӣ��޸Ķ�βָ��
	delete p;
	return x;
}


template <class T>
T LinkQueue<T>::GetHead()
{
	Node<T> *p;
	if(front==rear) throw "�ӿգ��޶�ͷԪ��";//
	p=front->next;
	return p->data;
}

template <class T>
T LinkQueue<T>::GetLast()
{
	if(front==rear) throw "�ӿգ��޶�βԪ��";
	return rear->data;
}


template <class T>
void LinkQueue<T>::ClearQueue()
{
	Node<T> *p;
	p=front->next;
	while(p)//�Ӷ�ͷ��ʼ���ɾ�������еĽ��
	{
		front->next=p->next;//�ݴ汻�ͷŽ��
		delete p;
        p=front->next;
	}
	rear=front;
}

template <class T>
int LinkQueue<T>::QueueEmpty()
{
	if(front==rear) 
		return 1;
	else
		return 0;
}


template <class T>
void LinkQueue<T>::QueueTranverse()
{
   Node<T> *p;
   p=front->next;
   while(p)
   {
     cout<<p->data<<'\t';
	 p=p->next;
   }
   cout<<endl;
 }


