

template <class T> //
class CirQueue
{
	private:
		T *base;// �洢�ռ��ַ
		int front;// ��ͷָ��
		int rear;// ��βָ��
		int queuesize;// ������
	public:
		CirQueue(int m);//����ն���
		~CirQueue();// �����������ͷ����Ӹ����Ĵ洢�ռ�
		void EnQueue(T x);// Ԫ��x���
		T DeQueue();// �Ӷ�Ԫ�س���
		T GetHead();// ȡ��ͷԪ��
		T GetLast();//ȡ��βԪ��
		int QueueEmpty(); // �жӿ�
		int QueueFull();//�ж���
		void ClearQueue();//��ն�
		void QueueTranverse();//�����ӣ��������Ԫ��
};


template <class T>
CirQueue<T>::CirQueue(int m)//���캯��
{//����һ�ն�
	base=new T[m];
	if(base==NULL) 
	{
		cout<<"�Ӵ���ʧ�ܣ��˳�!"<<endl;
		exit(1);
	}
	front=rear=0;
	queuesize=m;
}

template <class T>
CirQueue<T>::~CirQueue()//��������
{//�ͷŶ�����ռ�洢�ռ�
	delete [] base;
	rear=0;
	front=0;
	queuesize=0;
}

template <class T>
void CirQueue<T>::EnQueue(T x)
{//Ԫ�����
	if((rear+1)%queuesize==front) throw "���磬�޷����";
	base[rear]=x;
	rear=(rear+1)%queuesize;
	cout<<"��ӳɹ����¶�βΪ��"<<rear<<endl;
}

template <class T>
T CirQueue<T>::DeQueue()
{
	T x;
	if(front==rear) throw "���磬���ܳ���";
	x=base[front];
	front=(front+1)%queuesize;
	cout<<"���ӳɹ����¶�ͷΪ��"<<front<<endl;
	return x;
}

template <class T>
T CirQueue<T>::GetHead()
{
	T x;
	if(front==rear) throw "�ӿգ��Ӷ���Ԫ��";
	x=base[front];
    cout<<"ȡ��ͷԪ�سɹ�����ͷΪ��"<<front<<endl;
	return x;
}

template <class T>
T CirQueue<T>::GetLast()
{
	T x;
	if(front==rear) throw "�ӿգ��Ӷ���Ԫ��";
	x=base[rear-1];
	cout<<"ȡ��βԪ�سɹ�����βΪ��"<<rear<<endl;
	return x;
}


template <class T>
int CirQueue<T>::QueueEmpty()
{
	if(front==rear) 
		return 1;
	else
		return 0;
}

template <class T>
int CirQueue<T>::QueueFull()
{
	if((rear+1)%queuesize==front)
		return 1;
	else
		return 0;
}

template <class T>
void CirQueue<T>::ClearQueue()
{
	front=rear=0;
}

template <class T>
void CirQueue<T>::QueueTranverse()
{
	int i=front;
   while(i!=rear)
   {
     cout<<base[i]<<'\t';
	 i=(i+1)%queuesize;
   }
   cout<<endl;
}