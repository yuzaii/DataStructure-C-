//ѭ����������Ķ���
template<class T>
struct Node
{
	T data;
	Node *next;
};

template <class T>
class CLinkList
{
	private:
		Node<T> *Head;
	public:
		CLinkList() ;//���캯���� �����յ�ѭ������
		~CLinkList();//����������ɾ����ռ�
		void CreateList(int n);//��������n��Ԫ�صĵ�ѭ������
		void Insert(int i,T e);//�ڱ��е�i��λ�ò���Ԫ��
		T Delete(int i);//ɾ�����е�i��Ԫ��
		T GetElem(int i);//��ȡ��i��Ԫ�ص�ֵ
		int Locate(T e);//�������в���ֵΪe��Ԫ��
		T prior(T e);//����Ԫ��e��ǰ��
		int Empty();//����
		int Length();//���
		//void CLear();//��ձ�
		void ListDisplay();//�����Ԫ��
};
//ѭ�����������ʵ��
template<class T>
CLinkList<T>::CLinkList()//������������һ�յ�ѭ������
{
	
	Head=new Node<T>;
	Head->next=Head;
}

template<class T>
CLinkList<T>::~CLinkList()//�����������ͷ�������ռ�ռ�
{
	Node<T> *p,*q;
	q=Head;
	while(q->next!=Head)  q=q->next;   //��λq��β��� 
	while(Head!=Head->next)
	{//��ͷ��㿪ʼ�������ͷŽ��
		p=Head;
		Head=Head->next;
		q->next=Head;
	    delete p;
	}
	Head=NULL;//ͷ���ָ���
}

template<class T>
void CLinkList<T>::CreateList(int n)
{//β�巨(����)��������n��Ԫ�صĵ�ѭ������
	Node<T> *p,*s;//���ù���ָ�롣pָ��β���
	p=Head;
	cout<<"����������"<<n<<"��Ԫ��ֵ��"<<endl;
	for(int i=1;i<=n;i++)
	{
		s=new Node<T>;//�½�Ԫ�ؽ��
	    cin>>s->data;//�����½�����Ԫ��ֵ
		s->next=p->next;//�½�������β
		p->next=s;
		p=s;
	}
}

template<class T>
void CLinkList<T>::Insert (int i,T e)
{//��ָ��λ�ò���Ԫ��
	
	int j=0;
	Node<T> *p;
	p=Head;//����ָ���ʼ��
	while(p->next!=Head&& j<i-1)//��λ�������֮ǰ
	{
		p=p->next;//
		j++;
	}
	if(p->next==Head||j>i-1) throw"λ���쳣";//����λ�ò�����i<0��i>��
	else
	{
		Node<T> *s;
		s=new Node<T>;//
		s->data=e;//
		s->next=p->next;//���S���ӵ�p���֮��
		p->next=s;//
	}
}

template <class T>
T CLinkList<T>::Delete (int i)
{//ɾ��ָ��λ��Ԫ��
	T x;
	Node<T> *p,*q;//���ù���ָ��
	p=Head;//���Ҵ�ͷ��㿪ʼ
	int j=0;//��������ʼ��
	while(p->next!=Head && j<i-1)//p��λ��ɾ�����ǰ��
	{
		p=p->next;//
		j++;
	}
	if(p->next==Head||j>i-1) throw"λ���쳣";//ɾ��λ�ò�����
	else  //ɾ��λ�ú���
	{
		q=p->next;// �ݴ�ɾ�����λ��
		p->next=q->next;//��������ժ��ɾ�����
		x=q->data;//ȡɾ������Ԫ�ص�ֵ
		delete q;// �ͷ�ɾ����
		return x;//����ɾ��Ԫ�ص�ֵ
	}
}

template<class T>
int CLinkList<T>::Locate (T e)
{//��ֵ��λ
	int j=1;
	Node<T> *p;
	p=Head->next;
	while(p!=Head && p->data!=e)
	{
		p=p->next;
		j++;
	}
	if(p==Head) return 0;
	else return j;
}


template<class T>
T CLinkList<T>::GetElem(int i)
{//��ȡ��i��Ԫ�ص�ֵ
	Node<T> *p;//���ù���ָ��
	p=Head->next;//���׽�㿪ʼ
	int j=1;//��������ʼ��
	while(p!=Head&&j<i)//��λ����i��Ԫ�ؽ��
	{
		p=p->next;j++;
	}
	if(p==Head||j>i)//��λλ�ò������ձ��iС��0��i���ڱ�
		throw "λ�ò�����";
	else //λ�ú���
		return p->data;
}

template<class T>
int CLinkList<T>::Empty()
{//����
	if(Head->next==Head)
		return 1;
	else
		return 0;
}

template<class T>
T CLinkList<T>::prior(T e)
{//����Ԫ��ǰ��
	Node<T> *p,*q;
	p=Head;q=p->next;
	while(q!=Head&&q->data!=e)
	{
		p=q;q=q->next;
	}
	if(p==Head)    //��Ԫ��,��ǰ��ΪβԪ��????
	   throw"��Ԫ�أ���ǰ��";
	else if(q==Head)
		throw"Ԫ�ز�����";		
	else
		return p->data;
		
}

template <class T>
int CLinkList<T>::Length()
{
	int len=0;//
	Node<T> *p;
	p=Head;//ָ��ͷ���
	while(p->next!=Head)
	{
		len++;p=p->next;
	}
	return len;
}//Length

template <class T>
void CLinkList<T>::ListDisplay()
{//��ʾ����
	Node<T> *p;
	p=Head->next;
	int i=1;
	while(p!=Head)
	{
		cout<<i<<"\t";
		cout<<p->data<<endl;
		p=p->next;
		i++;
	}
}


