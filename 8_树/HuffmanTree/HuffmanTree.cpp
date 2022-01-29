//���Ŷ�����
#include<iostream>
#include<iomanip>
using namespace std;
//����������
template <class T>
struct hufnode
{
	T wei;//Ȩֵ
	int prt;//ָ�򸸽���ָ���򣨽��Ԫ�ص��±꣩
	int lch;//��ָ���򣨽��Ԫ�ص��±꣩
	int rch;//��ָ���򣨽��Ԫ�ص��±꣩
};
//���������±�һ���ǷǸ�����������˿�����-1��Ϊ��ָ��ֵ
template <class T>
class huffman_BT
{
	int nn;//Ҷ�ӽ��ĸ���
	hufnode<T>*BT;//���Ŷ�����˳��洢�ռ���׵�ַ
	public:
		huffman_BT(){BT=NULL;}//���캯���������Ŷ��������г�ʼ��
		void creat_hufm_BT(int n,T w[]);//�������Ŷ�����
		void select(hufnode<T>*p,int k,int *i,int *j);
		void prt_hufm_BT();//������Ŷ������洢�ռ�״��
};
//�������Ŷ�����
template <class T>
void huffman_BT<T>::creat_hufm_BT(int n,T w[])
{//n��Ҷ�ӽ��ĸ�����w��Ҷ�ӽ���Ȩֵ����
	hufnode<T> *p;
	int k,i,j,m;
	nn=n;
	m=n*2-1;
	BT=new hufnode<T>[m];//�������Ŷ������洢�ռ�
	p=BT;
	for(k=0;k<m;k++)
	{//���ó�ʼ״̬�����н���ָ��Ϊ��
		(p+k)->prt=-1;
		(p+k)->lch=-1;
		(p+k)->rch=-1;
	}
	for(k=0;k<n;k++)
	{//ǰn������Ȩֵ�ֱ�Ϊ������Ȩֵ
		(p+k)->wei=w[k];
	}
	for(k=n;k<m;k++)
	{//�������Ŷ�����
		select(p,k,&i,&j);//��ǰK-1�������ѡ��Ȩֵ��С�����������i��j
		(p+i)->prt=k;
		(p+j)->prt=k;//�ϲ������µĶ�����
		(p+k)->lch=i;
		(p+k)->rch=j;
		(p+k)->wei=(p+i)->wei+(p+j)->wei;
	}
}
template <class T>
void huffman_BT<T>::select(hufnode<T>*p,int k,int *i,int *j)
{//��ǰK-1�������ѡ��Ȩֵ��С�����������i��j
	T w;
	int n=0;
	while(n<k&&(p+n)->prt!=-1)	n++;//Ѱ��ָ�򸸽��ָ��Ϊ�յ���ʼ���
	w=(p+n)->wei;
	*i=n;
	while(n<k)
	{
		if((((p+n)->wei)<w)&&((p+n)->prt==-1))
		{
			*i=n;
			w=(p+n)->wei;
			
		}n++;
	}
	n=0;
	while((n<k)&&((p+n)->prt!=-1)||(n==(*i))) n++;
	w=(p+n)->wei;
	*j=n;
	while(n<k)
	{
		if(((p+n)->wei<w)&&(n!=(*i))&&((p+n)->prt==-1))
		{
			*j=n;
			w=(p+n)->wei;
		}
		n++;
	}
	if((*i)>(*j))
	{
		n=(*i);
		*i=*j;
		*j=n;
	}

}
template <class T>
void huffman_BT<T>::prt_hufm_BT()
{
	hufnode <T>*p;
	int k;
	p=BT;
	cout<<"k"<<setw(7)<<"WEI"<<setw(7)<<"PRT"
		<<setw(7)<<"LCH"<<setw(7)<<"RCH"<<endl;
	for(k=0;k<2*nn-1;k++)
	{
		cout<<k<<setw(7)<<(p+k)->wei<<setw(7)<<(p+k)->prt
			<<setw(7)<<(p+k)->lch<<setw(7)<<(p+k)->rch<<endl;
	}
}

void main()
{
	int *w;
	int op;
	int i;
	huffman_BT<int> b;
	do
	{
		cout<<"1-������Ȩֵ"<<endl;
		cout<<"2-�������Ŷ�����"<<endl;
		cout<<"3-�˳�����"<<endl;
		cout<<"��ѡ�������[ ]";
		cout<<"\b\b";
		cin>>op;
		switch(op)
		{
		case 1:
			cout<<"��������ĸ�����";
			int sum;
			cin>>sum;
			w=new int[sum];
			cout<<"����������Ȩֵ��"<<endl;
			for(i=0;i<sum;i++)
			{
				cout<<"�������"<<i+1<<"��Ȩֵ��";
				cin>>w[i];
			}
			break;
		case 2:
			b.creat_hufm_BT(sum,w);
			b.prt_hufm_BT();
			system("pause");
			break;
		case 3:
			cout<<"�������У�Bye-Bye!"<<endl;
			break;
		}
	}while(op!=3);
}
