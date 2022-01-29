#include<iostream.h>//cout,cin
#include"process.h"//exit()
#include"stdio.h"//EOF,NULL

typedef int T;  //����ؼ��ֵ�����,�����������������
//���ұ��ඨ��
template <class T>
struct Node
{
	T key;     //�ؼ�����
	/*
	........		//������,�����Լ�������Ҫ���	
	*/
};

template <class T>
class SSearch {
private:
	Node<T> *ST;
	int len;//��
public:	
    SSearch();//
    ~SSearch();//����������ɾ����ռ�
	void Create(int n);    //����ʱ�����û�ʵ������,��Ϊ��Ӧ������Ԫ�ظ�ֵ
	void Display();	 //�����̬���е�����Ԫ��
	int SeSearch(T key);	 //�ӱ������һ��Ԫ�ؿ�ʼ˳�����
	void Ascendsort();    //��������
	int BiSearch_1(T key);//�۰���ң��ǵݹ��㷨
	int BiSearch_2(T key);//�۰���ң��ݹ��㷨
    int BiSearch2(int x,int y,T key);
};

template <class T>
SSearch<T>::SSearch()
{//
	ST=NULL;
	len=0;   
}

template <class T>
SSearch<T>::~SSearch()
{//�ͷű�ռ�
	delete [] ST;
	len=0; 
}


template <class T>
void SSearch<T>::Create(int n)                            
	{
		len=n;
		ST=new Node<T>[len];
		Node<T> e;
		int i=0;
		cout<<"����"<<len<<"������Ԫ��"<<endl;
		while(i<len)
		{
			cin>>e.key;
			ST[i]=e;
			i++;
		}
}

template <class T>
int SSearch<T>::SeSearch(T key)   
{//�ӱ������һ��Ԫ�ؿ�ʼ˳����ң����ҵ�������λ�򣬷��򣬷���-1
	for(int i=len-1;i>=0;i--)
		if(ST[i].key==key)
			{
				cout<<"���ҳɹ�!λ�ӵ�"<<i+1<<endl;
				return i;
			}
		cout<<"ĩ�ҵ�!"<<endl;
		return -1;
}


template <class T>
void SSearch<T>::Ascendsort()
	{
		T t;
		for(int i=0;i<len-1;i++)
		{
			for(int j=0;j<len-i-1;j++)
				if(ST[j].key>ST[j+1].key)
				{
					t=ST[j].key;
					ST[j].key=ST[j+1].key;
					ST[j+1].key=t;
				}
		}
	}


template <class T>
int SSearch<T>::BiSearch_1(T key) 
{ //�۰���ҷǵݹ��㷨
		if(len==0 && ST==NULL)
		{
			cout<<"˳�������,���Ƚ�����\n";
				return -1;
		}
		else
		{
			int low=0,high=len-1;
			int mid;
			while(low<=high)
			{
				mid=(high+low)/2;
				if(ST[mid].key==key)
				{
					cout<<"�ҵ�!λ��"<<mid+1<<endl;
					return mid;
				}
				if(ST[mid].key>key)
					high=mid-1;
				else
					low=mid+1;
			}
			cout<<"ĩ�ҵ�!"<<endl;
			return -1;
		}
	}

template <class T>
int SSearch<T>::BiSearch2(int x,int y,T key)
{//�۰���ҵݹ��㷨
		int mid=(x+y)/2;
		if(ST[mid].key==key)
			return mid;
		if(x>y)
			return -1;    //��ʾû���ҵ�
		if(key<ST[mid].key)
			return BiSearch2(x,mid-1,key);
		else
			return BiSearch2(mid+1,y,key);
}//
template <class T>
int SSearch<T>::BiSearch_2(T key)
{
    int k;
    k=BiSearch2(0,len-1,key);
    return k;
}

template <class T>
void SSearch<T>::Display()    
{//�����̬���е�����Ԫ��
		cout<<"��̬���е�����Ԫ�عؼ�������Ϊ:\n";
		for(int i=0;i<len;i++)
		{
			cout<<ST[i].key<<"   ";
		}
		cout<<endl;
}

void main()
{
	int choice,n,k;
	SSearch<int> a;
	cout<<"ע�⣺�����ȴ�����̬��)\n";
	cout<<"=======================\n";
	T key;

		cout<<"--- 1.  �������ұ� ------------------------\n"
	        <<"--- 2.  ˳�����  -------------------------\n"
		    <<"--- 3.  �۰����<�ݹ�>----------------------\n"
		    <<"--- 4.  �۰����<�ǵݹ�> -------------------\n"
		    <<"--- 5.  �����̬���е���������Ԫ�عؼ���----\n"
		    <<"--- 6.  �˳� ------------------------- -----\n";
		    
    do
	{	cout<<"��ѡ�����:";
		cin>>choice;
		switch(choice)
		{
		 case 1://
            cout<<"���뾲̬���ұ�ĳ���"<<endl;
		    cin>>n;			
            a.Create(n);
			break;
		 case 2://
			cout<<"��������ҹؼ��֣�"<<endl;
			cin>>key;
		   	a.SeSearch(key);
			break;
		 case 3:
			a.Ascendsort();
			cout<<"������ҹؼ��֣�"<<endl;
			cin>>key;
			k=a.BiSearch_2(key);
			if(k==-1)
				cout<<"ĩ�ҵ�!"<<endl;
			else
				cout<<"�ҵ�!λ�ӵ�"<<k+1<<endl;
		    break;
		 case 4:
			a.Ascendsort();
            cout<<"������ҹؼ��֣�"<<endl;
			cin>>key;
			a.BiSearch_1(key);
		    break;
		 case 5:
			a.Display();
			break;
		 case 6:
		    cout<<"���н���"<<endl;
		    break;
		 default:
			cout<<"�������Ƿ���Ӧ��0--7֮��"<<endl;
		     cout<<"�����ѡ�����";
		    break;
		}//switch
	}while(choice!=6);
}//main
