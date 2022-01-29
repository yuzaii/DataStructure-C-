#include<iostream>
#include<cmath>
using namespace std;
#define SUCCESS 1;
#define UNSUCCESS 0;
#define NULLKEY -1;
#define TableLength 13;
#define p 13;// H(key)=key % p
            
typedef int T;
template <class T>
struct ElemType
{
	T key;//�ؼ���
	/*     //����
	....
	*/
};


template <class T>
class LHSearch
{
private:
	ElemType<T> *HT; //���Ŷ�ַ��ϣ��
	int count; //��ǰ����Ԫ�ظ���
	int size; //��ϣ����
public:
	 LHSearch(); //
    ~LHSearch(); //
    void InitHashTable(int n);//
    int Hash(T key); //�����ϣ��ַ
	void Collision(int &s);//��ͻ,������һ����ַ
	int Search(T key,int &s);//��ϣ����
	int Insert(ElemType<T> e); //Ԫ�ز���
	void Display(); //��ʾ��ϣ��
};

template <class T>
LHSearch<T>::LHSearch()
{
	HT=NULL;
	size=0;
	count=0;
}

template <class T>
LHSearch<T>::~LHSearch()
{ delete [] HT;
  count=0;
}

template <class T>
int LHSearch<T>::Hash(T key)  
{//�ɹ�ϣ�������ϣ��ַ
	return key%p;
}

template <class T>
void LHSearch<T>::Collision(int &s)
{//���Ŷ�ַ�������ͻ
	s=s++;
}

template <class T>
int LHSearch<T>::Search(T key,int &s)
{//���ң��ҵ�����
	//int s;
	s=Hash(key);
	while((HT[s].key!=-1) && (key!=HT[s].key))
		Collision(s);
	if(HT[s].key==key)
		return 1;
	else 
		return 0;
}

template <class T>
int LHSearch<T>::Insert(ElemType<T> e)
{//����Ԫ��
	int s;
	if(count==size)
	{
		cout<<"���������ܲ���!"<<endl;
		return UNSUCCESS;
	}
	else
	{
		s=Hash(e.key);
		int f;
	    f=Search(e.key,s);
  	    if(f)   //�������к�e�Ĺؼ�����ͬ��Ԫ��,�����в������
		{
		   cout<<"��Ԫ���Ѵ��ڣ����ܲ���!"<<endl;
		 return UNSUCCESS; 	}
	   else
	   {
		  HT[s].key=e.key;
    	  cout<<"����ɹ�!"<<endl;
		  count++;
		 return SUCCESS; }
	 }
}

template<class T>
void LHSearch<T>::InitHashTable(int n)
{
	size=n;
	HT=new ElemType<T>[size];
	for(int i=0;i<size;i++) //��ʼ�����ѹ�ϣ���ÿ�
		HT[i].key=NULLKEY;
}

template<class T>
void LHSearch<T>::Display()
{
	for(int i=0;i<size;i++)
	{
		cout<<i<<'\t';
		if(HT[i].key!=-1)
			cout<<HT[i].key;
        else
			cout<<'\t';
		cout<<endl;
	}
}

void main()
{
	int m;
	T key;
	int s=0;
	ElemType<int> e;
	LHSearch<int> a;
	cout<<"������Ӧ���룬�����ȴ�����ϣ��)\n";
	do { 
	    cout<<"--- 1. �������ұ�  --\n"
		    <<"--- 2. ����----------\n"
		    <<"--- 3. ����----------\n"
		    <<"--- 4. ��ʾ ---------\n"
		    <<"--- 5. �˳� ---------\n"
		    <<"��ѡ�����:";
	        cin>>m;
			switch(m)
			{
			case 1://�������ұ�
				cout<<"�������������\n";
				cin>>m;
				a.InitHashTable(m);
				cout<<"���������Ԫ�أ�-1����:\n";
				for(cin>>e.key;e.key!=-1;cin>>e.key)
					a.Insert(e);
				break;
			case 2:  //����Ԫ��
				cout<<"����Ԫ��:\n";
				cin>>e.key;
				a.Insert(e);
				break;
			case 3: //����
				cout<<"��������ҹؼ��֣�\n";
				cin>>key;
				if(a.Search(key,s))
					cout<<"�ҵ�!\n";
				else
					cout<<"�����ڣ�ĩ�ҵ�!\n";
				break;
			case 4://��ʾ��ϣ��
				a.Display();
				break;
	        case 5://
			   cout<<"����!\n";
			   break;
			}
	}while(m!=5);
}