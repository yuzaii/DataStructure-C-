//��̬������ඨ��
template <class T>
class SLinkList
{
	private:
		struct Tcomp
		{
			T data;
			int cur;
		};
		Tcomp *sls;//�洢����Ԫ�ص�һά����
		int av;//���������ͷ
		int sl;//��̬�����ͷ
		int maxlen;//������ܵ���󳤶�
	public:
		SLinkList(int maxsz=100);//���캯���� ��������Ϊmaxsz�Ŀձ�
		~SLinkList();//����������ɾ����ռ�
		void CreateList(int n);//��������n��Ԫ�ص�����
		void Insert(int i,T e);//�ڱ��е�i��λ�ò���Ԫ��
		T Delete(int i);//ɾ�����е�i��Ԫ��
		T GetElem(int i);//��ȡ��i��Ԫ�ص�ֵ
		int Locate(T e);//�ڱ��в���ֵΪe��Ԫ��
		int Empty();//����
		int Full();//�����
		int Length();//���
		void Clear();//��ձ�
		void ListDisplay();//�����Ԫ��
};
//��̬�������ʵ��
template<class T>
SLinkList<T>::SLinkList(int maxsz):maxlen(maxsz)//���캯������������Ϊmaxsz�Ŀձ�
{//����ռ䲢��������Ŀռ�����һ������������ͷ��avָ����β�ɣ�1��ʾ��
	//����ʾ��̬�����ͷ��sl����Ϊ��1
	sls=new Tcomp[maxlen];
	sl=-1;
	for(int i=0;i<maxlen;i++)  sls[i].cur=i+1;
	sls[maxlen-1].cur=-1;
	av=0;
	
}

template<class T>
SLinkList<T>::~SLinkList()//�����������ͷ�������ռ�ռ�
{
	delete[] sls;
}

template<class T>
void SLinkList<T>::CreateList(int n)//��������n��Ԫ�ص�����
{
	int value;
	if(n>maxlen) throw"�����Ƿ�";
	cout<<"����������"<<n<<"��Ԫ��ֵ��"<<endl;
	for(int i=1;i<=n;i++)
	{
		cin>>value;
		Insert(i,value);
	}
}


template<class T>
void SLinkList<T>::Insert (int i,T e)
{//��ָ��λ�ò���Ԫ��
	int m,j=0,k;
	m=av;
	if(av==-1) throw"��������Ϊ��";
	av=sls[av].cur;
	if(sl==-1)   //�ڿձ��в���
	{
		sls[m].data=e;
		sls[m].cur=-1;
		sl=m;
	}
	else if(i==1)//�����ڱ�ͷ
		{
			sls[m].data=e;
			sls[m].cur=sl;
			sl=m;		
		}
	else
	{
		k=sl;    //��ǰ�����k��������k���֮��
		while(j<i-1 && k!=-1)
		{
			j++;
			if(j<i-1)   k=sls[k].cur;
		}
		if(j!=i-1) throw"λ���쳣";
		sls[m].data=e;
		sls[m].cur=sls[k].cur;
		sls[k].cur=m;
	}
}

template <class T>
T SLinkList<T>::Delete (int i)
{//ɾ��ָ��λ��Ԫ��
	int m,j=0,k;
	
	if(sl==-1)  throw"��̬����Ϊ��";
	else if(i==1)  //ɾ����ͷ
	{
		m=sl;
		sl=sls[sl].cur;
		sls[m].cur=av;
		av=m;
		return sls[m].data;
	}
	else
	{
		k=sl;   //��ǰ�����k��ɾ��k����Ľ��
		while(j<i-1  && k!=-1)
		{
			j++;
			if(j<i-1)  k=sls[k].cur;
		}
		if(j!=i-1)  throw"λ���쳣";
		m=sls[k].cur;
		sls[k].cur=sls[m].cur;
		sls[m].cur=av;
		av=m;   //�ս�����av��
		return sls[m].data;
	}
}

template<class T>
int SLinkList<T>::Locate (T e)
{//��Ԫ��e�ھ�̬�����е����
	int k=sl,j=0;
	while(k!=-1 && sls[k].data!=e)
	{
		k=sls[k].cur;
		j++;
	}
	if(k==-1) return -1;
	else return j+1;
}

template<class T>
void SLinkList<T>::Clear()
{
	sl=-1;
	for(int i=0;i<maxlen;i++)  sls[i].cur=i+1;
	sls[maxlen-1].cur=-1;
	av=0;

}

template<class T>
T SLinkList<T>::GetElem(int i)
{//��ȡ��i��Ԫ�ص�ֵ
	int k,j=0;
	k=sl;
	while(j<i && k!=-1)
	{
		j++;
		if(j<i) k=sls[k].cur;
	}
	if(j==i) return(sls[k].data);
	else throw"λ���쳣";
}

template<class T>
int SLinkList<T>::Empty()
{//����
    if(sl==-1)
		return 1;
	else
		return 0;
}

template<class T>
int SLinkList<T>::Full()
{//�����
	if(av==-1)
		return 1;
	else
		return 0;
}


template <class T>
int SLinkList<T>::Length()
{
	int k,len=0;//
	k=sl;
	while(k!=-1)
	{
		len++;
		k=sls[k].cur;
	}
	return len;
}//Length

template <class T>
void SLinkList<T>::ListDisplay()
{//��ʾ����
	int k,i=1;
	k=sl;
	while(k!=-1)
	{
		cout<<i<<"\t";
		cout<<sls[k].data<<endl;
		k=sls[k].cur;
		i++;
	}
}

