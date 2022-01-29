//��ջ��Ķ���
template<class T>
struct Node
{
	T data;
	Node<T> *next;//�˴�T����ʡ��
};

template<class T>
class LinkStack
{//��������������һ��ջ
	private:
		Node<T> *top;//// ������Ϊջ��
	public:
		LinkStack(){top=NULL;}//���캯�����ÿ���ջ
		~LinkStack();// �����������ͷ���ջ�и����Ĵ洢�ռ�
		void Push(T x);// Ԫ��x��ջ
		T Pop();// ջ��Ԫ�س�ջ
		T GetTop();// ȡջ��Ԫ��
		int StackEmpty(); // �ж�ջ�Ƿ�Ϊ��
		void ClearStack();//���ջ
		void StackTranverse();//�������ջ��Ԫ��
};
//��ջ���ʵ��
template<class T>
LinkStack<T>::~LinkStack()
{//��������������ջ
	Node<T> *q;
	while(top)//��ջ����ʼ�ͷ�ջ����ÿһ�����Ĵ洢�ռ�
	{
		q=top;//�ݴ汻�ͷŽ��
		top=top->next;//ͷָ�����ָ����һ�����ͷŽ��
		delete q;
	}
}

template<class T>
void LinkStack<T>::Push(T x)
{//��ջ
	Node<T> *s;
	s=new Node<T>;s->data=x;//����һ�½�㣬������Ϊx�Ľ��s
	s->next=top;top=s;//�½��������ף�Ϊջ��
}

template<class T>
T LinkStack<T>::Pop()
{//��ջ
	T x;
    Node<T> *p;
	if(top==NULL) throw"����";
	x=top->data;//�ݴ�ջ��Ԫ��
	p=top;top=top->next;//ջ������
	delete p;//ɾ��ԭջ�����
	return x;
}


template <class T>
T LinkStack<T>::GetTop()
{//��ȡջ��Ԫ��
	if(top==NULL) throw "ջ�գ�ջ����Ԫ��";
	return top->data;
}


template <class T>
void LinkStack<T>::ClearStack()
{//���ջ
	while(top)//��ջ����ʼ�ͷ�ջ����ÿһ�����Ĵ洢�ռ�
	{
		Node<T> *q;
		q=top;//�ݴ汻�ͷŽ��
		top=top->next;//ͷָ�����ָ����һ�����ͷŽ��
		delete q;
	}
}

template <class T>
int LinkStack<T>::StackEmpty()
{//��ջ��
	if(top==NULL) 
		return 1;
	else
		return 0;
}


template <class T>
void LinkStack<T>::StackTranverse()
{//��ջ���𣬱������ջԪ��
   Node<T> *p;
   p=top;
   while(p)
   {
     cout<<p->data<<'\t';
	 p=p->next;
   }
   cout<<endl;
 }


