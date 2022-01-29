template<class T>
struct Node
{
	T data;//�����򣬴�ű�Ԫ��
	Node *next;//ָ����ָ����һ�����
};

template <class T>
class LinkList
{
	private:
		Node<T> *Head;// ����ͷָ��
	public:
		LinkList() ;//���캯���� ����������
		~LinkList();//����������ɾ����ռ�
		void CreateList(int n);//��������n��Ԫ�ص���������
		void Insert(int i,T e);//�ڱ��е�i��λ�ò���Ԫ��
		T Delete(int i);//ɾ�����е�i��Ԫ��
		T GetElem(int i);//��ȡ��i��Ԫ�ص�ֵ
		int Locate(T e);//�������в���ֵΪe��Ԫ��
		T prior(T e);//����Ԫ��e��ǰ��
		int Empty();//����
		int Length();//���
		void ListDisplay();//�����Ԫ��
};
template<class T>
LinkList<T>::LinkList()
{//������������һ������
	Head=new Node<T>;
	Head->next=NULL;
}

template<class T>
LinkList<T>::~LinkList()
{//�����������ͷ�������ռ�ռ�
	Node<T> *p;
	while(Head)//��ͷ��㿪ʼ�������ͷŽ��
	{
		p=Head;
		Head=Head->next;
	    delete p;
	}
	Head=NULL;//ͷ���ָ���
}

template<class T>
void LinkList<T>::CreateList(int n)
{//β�巨(����)��������n��Ԫ�ص����Ա�
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
void LinkList<T>::Insert (int i,T e)
{//��ָ��λ�ò���Ԫ��
	int j=0;
	Node<T> *p;
	p=Head;//����ָ���ʼ��
	while(p && j<i-1)//��λ�������֮ǰ
	{
		p=p->next;//
		j++;
	}
	if(!p||j>i-1) throw"λ���쳣";//����λ�ò�����i<0��i>��
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
T LinkList<T>::Delete (int i)
{//ɾ��ָ��λ��Ԫ��
	T x;
	Node<T> *p,*q;//���ù���ָ��
	p=Head;//���Ҵ�ͷ��㿪ʼ
	int j=0;//��������ʼ��
	while(p->next && j<i-1)//p��λ��ɾ�����ǰ��
	{
		p=p->next;//
		j++;
	}
	if(!p->next||j>i-1) //ɾ��λ�ò�����
		throw"λ���쳣";
	else //ɾ��λ�ú���
	{
		q=p->next;// �ݴ�ɾ�����λ��
		p->next=q->next;//��������ժ��ɾ�����
		x=q->data;//ȡɾ������Ԫ�ص�ֵ
		delete q;// �ͷ�ɾ����
		return x;//����ɾ��Ԫ�ص�ֵ
	}
}

template<class T>
int LinkList<T>::Locate (T e)
{//��Ԫ��ֵ���ң��ҵ�������Ԫ���ڱ��е�λ�򣻷��򣬷���0
	int j=1;
	Node<T> *p;//����ָ��
	p=Head->next;//��Ԫ���Ϊ������ʼλ��
	while(p && p->data!=e)
	{
		p=p->next;
		j++;
	}
	if(p==NULL) return 0;//ĩ�ҵ�������0
	else return j; //�ҵ�������λ��
}


template<class T>
T LinkList<T>::GetElem(int i)
{//��ȡ��i��Ԫ�ص�ֵ
	Node<T> *p;//���ù���ָ��
	p=Head->next;//���׽�㿪ʼ
	int j=1;//��������ʼ��
	while(p&&j<i)//��λ����i��Ԫ�ؽ��
	{
		p=p->next;j++;
	}
	if(!p||j>i)//��λλ�ò������ձ��iС��0��i���ڱ�
		throw "λ��";
	else //λ�ú���
		return p->data;
}

template<class T>
int LinkList<T>::Empty()
{//���ա�
	if(Head->next==NULL)
		return 1;//�ձ�����1
	else
		return 0;//���գ�����0
}

template<class T>
T LinkList<T>::prior(T e)
{//����Ԫ��ǰ��
	Node<T> *p,*q;
	p=Head;q=p->next;
	while(q&&q->data!=e)
	{
		p=q;q=q->next;
	}
	if(p==Head)
		throw"��Ԫ�أ���ǰ��";
	else if(q==NULL)
		throw"Ԫ�ز�����";		
	else
		return p->data;
		
}

template <class T>
int LinkList<T>::Length()
{//���
	int len=0;//��������ʼ��
	Node<T> *p;//���ù���ָ��
	p=Head;//ָ��ͷ���
	while(p->next)
	{
		len++;p=p->next;
	}
	return len;//���ر�
}//Length

template <class T>
void LinkList<T>::ListDisplay()
{//������ʾ����
	Node<T> *p;//���ù���ָ��
	p=Head->next;//����Ԫ��㿪ʼ����
	int i=1;//Ԫ��λ��
	while(p)
	{
		cout<<p->data<<"\t";
		p=p->next;
		i++;
	}
	cout<<endl;
}

