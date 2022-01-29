//��Ķ���
template <class T>
class SqList   //˳�����
{
	private:
		T *elem; //����ַ
		int length; //��
		int listsize;//������
	public:
		SqList(int m) ;//���캯���� ��������Ϊm�Ŀձ�
		~SqList();//����������ɾ����ռ�
		void CreateList(int n);//��������n��Ԫ�ص����Ա�
		void Insert(int i,T e);//�ڱ��е�i��λ�ò���Ԫ��
		T Delete(int i);//ɾ�����е�i��Ԫ��
		T GetElem(int i);//��ȡ��i��Ԫ�ص�ֵ
		int Locate(T e);//Ԫ�ض�λ
		void Clear();//��ձ�
		int Empty();//����
		int Full();//�����
		int Length();//���
		void ListDisp();//�����Ԫ��
};
//���ʵ��
template<class T>
SqList<T>::SqList(int m)
{//��������������һ������Ϊm�Ŀձ�
	elem=new T[m];// �����ռ�
	length=0;// �ձ���Ϊ0
	listsize=m;//������Ϊm
}

template<class T>
SqList<T>::~SqList()//��������
{//�ͷű�ռ�
	delete [] elem;
	length=0; 
	listsize=0; 
}

template<class T>
void SqList<T>::CreateList(int n)
{//��������Ϊn��˳���
	if(n>listsize) throw"�����Ƿ�";
	cout<<"����������"<<n<<"��Ԫ��ֵ��"<<endl;
	for(int i=1;i<=n;i++)
	   cin>>elem[i-1];
	length=n;
}

template<class T>
void SqList<T>::Insert (int i,T e)
{// �ڵ�i��λ�ò���Ԫ�أ��粻�ܲ��룬��ʾ�쳣��Ϣ
	if(length>=listsize) throw "����";
	if(i<1||i>length+1) throw "����λ���쳣";
	for(int j=length;j>=i;j--)
		elem[j]=elem[j-1];
	elem[i-1]=e;
	length++;
}

template <class T>
T SqList<T>::Delete (int i)
{// ɾ�����е�i��λ��Ԫ�أ��粻��ɾ������ʾ�쳣��Ϣ��
	T x;
	if(length==0) throw "����";
	if(i<1||i>length+1) throw "ɾ��λ���쳣";
	x=elem[i-1];
	for(int j=i;j<length;j++)
		elem[j-1]=elem[j];
	length--;
	return x;
}

template<class T>
int SqList<T>::Locate (T e)
{// Ԫ�ض�λ�����ҵ������ظ�Ԫ���ڱ��е�λ��ĩ�ҵ�������0��
	for(int i=0;i<length;i++)
		if(elem[i]==e) return i+1;
		return 0;
}

template<class T>
void SqList<T>::Clear()
{//�ѱ����
	length=0;
}

template<class T>
T SqList<T>::GetElem(int i)
{//��ȡ��i��Ԫ�ص�ֵ
	T e;
	if(i<1||i>length) throw "λ�ò��Ϸ�";
	e=elem[i-1];
	return e;
}

template<class T>
int SqList<T>::Empty()
{//�б�ա����գ�����1�����򣬷���0
	if(length==0)
		return 1;
	else
		return 0;
}

template<class T>
int SqList<T>::Full()
{//�б���������������1�����򣬷���0
	if(length==listsize)
		return 1;
	else
		return 0;
}


template <class T>
int SqList<T>::Length()
{//���ر�
	return length;
}

template <class T>
void SqList<T>::ListDisp()
{//��ʾ������
	for(int i=0;i<length;i++)
	{
		cout<<elem[i]<<"\t";
		
	}
	cout<<endl;
}