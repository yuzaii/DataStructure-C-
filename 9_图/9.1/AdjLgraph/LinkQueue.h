/*-------------------------------��������------------------------------*/

 
#define LINKNODE
template <class T>
struct LinkNode{
	T            data;
	LinkNode<T> *next;
};



template <class T>
class LinkedQueue{
protected:

	LinkNode<T> *front;

	LinkNode<T>  *rear;

	int         length;
	
public:

	LinkedQueue();

	~LinkedQueue();

	void ClearQueue();

	bool IsEmpty() const;

	int GetLength() const;

	LinkNode<T>* GetHead() const;//���ض�ͷԪ��

	bool EnQueue(T &elem);

	bool DeQueue(T &receive);

	bool QueueTraverse(bool (*Visit)(T &elem));
};


template <class T>
LinkedQueue<T>::LinkedQueue()
{
	front = new LinkNode<T>;
	if(!front) return;
	rear = front;
	front->next = false;
	length=0;
}


template <class T>
LinkedQueue<T>::~LinkedQueue()
{
    ClearQueue();
	delete front;
}


template <class T>
void LinkedQueue<T>::ClearQueue()//�Ӷ�ͷ�嵽��β
{
	LinkNode<T> *temp = front->next;
	while(front->next)
	{
		front->next = temp->next;
		delete temp;
		temp = front->next;
	}
	rear = front;
	length=0;
}


template <class T>
bool LinkedQueue<T>::IsEmpty() const
{
	return (front==rear)?true:false;
}


template <class T>
int LinkedQueue<T>::GetLength() const
{
	return length;
}


template <class T>
LinkNode<T>* LinkedQueue<T>::GetHead() const
{
	return front;
}


template <class T>
bool LinkedQueue<T>::EnQueue(T &elem)
{
	LinkNode<T> *temp = new LinkNode<T>;
	if(!temp) return false;
	temp->data = elem; temp->next = false;
	rear->next = temp;
	rear = temp;
	++length;
	return true;
}


template <class T>
bool LinkedQueue<T>::DeQueue(T &receive)
{
	if(front==rear) return false;
    LinkNode<T> *temp = front->next;//ָ���ͷԪ��
	receive = temp->data;
	front->next = temp->next;
	delete temp;
	if(!front->next) rear = front;
	--length;
	return true;
}


template <class T>
bool LinkedQueue<T>::QueueTraverse(bool (*Visit)(T &elem)) //�Ӷ�ͷ����β����һ�α���
{
    LinkNode<T> *temp=front->next;
	while(temp)
	{
		if(!Visit(temp->data))
			return false;
		temp = temp->next;
	}
	return true;
}




 