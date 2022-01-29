// �����ʾ��
#include "iostream"
#include "string"
#include "iomanip"
#include "LinkQueue.h"
using namespace std;

#define MAX_VERTEX_NUM 20 //��󶥵���
const int infinity = INT_MAX;

struct ArcCell{
	int adj;    //����Ȩͼ��1��0��ʾ�Ƿ����ڣ��Դ�Ȩͼ����ΪȨֵ����
    char *info; //�û��������Ϣ
};


template <class T>
struct _MGraph{
    T vexs[MAX_VERTEX_NUM];//�����
	ArcCell arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//�ڽӾ��󣬼��߱�
	int vexnum;//������
	int arcnum;//����
	int kind;//�����ڽӾ���洢��ͼ����
};


template <class T>
class MGraph{
	_MGraph<T> mgraph;
    bool visited[MAX_VERTEX_NUM];
public:		
	void CreateGraph();                                //v��ͼ�Ķ��㼯 vr��ͼ�ı߼� 
	void DestroyGraph();                               //����ͼ	 
	int LocateVex (T u);                 //ͼ���ڣ�ͼ�д��ڶ���u �򷵻ظö�����ͼ�е�λ��
	T GetVex(int index);                 //ͼ���ڣ�index��ͼ��ĳ���������� �򷵻�index�Ķ���
	void PutVex(T v,T value);        //ͼ���ڣ�v��ͼ��ĳ������ ���v��ֵvalue
	int FirstAdjVex(T v);                //ͼ���ڣ�v��G��ĳ������ ����v�ĵ�һ���ٽӵ����� ������ӵ��򷵻ؿ�
	int NextAdjVex(T v,T w);         //ͼ���ڣ�v��ͼ��ĳ�����㣬w��v���ڽӵ� ����v�������w����һ���ڽӵ����� ��w��v�����һ���ڽӵ��򷵻ؿ�
	bool InsertVex(T v);                 //ͼ���� ��ͼ�������¶���v
	bool DeleteVex(T v);                 //ͼ����   ɾ������v������صĻ�
	bool InsertArc(T v,T w);         //ͼ���ڣ�V��w��ͼ���������� ��ͼ����ӻ�<v��w>��������ͼ����Ӧ���ӶԳƻ�<w��v>
	bool DeleteArc(T v,T w);         //ͼ���ڣ�V��w��ͼ���������� ��ͼ��ɾ����<v��w>��������ͼ����Ӧɾ���Գƻ�<w��v>
	bool CreateDG();                         //��������ͼ
	bool CreateDN();                         //����������
	bool CreateUDG();                        //��������ͼ
	bool CreateUDN();                        //����������
	void DFS(int index);                     //�ӵ�index�����ݹ��������ȱ���ͼ
	bool (*VisitFunc)(T v);              //���ʶ���v�ķ�ʽ
	void DisPlay();                          //����ڽӾ���
	bool DFSTraverse(bool (*visit)(T v));//ͼ���ڣ���ͼ����������ȱ���
	bool BFSTraverse(bool (*visit)(T v));//ͼ���ڣ���ͼ���й�����ȱ���

};
template <class T>
bool visit(T v)
{
	cout<<v<<" ";
	return true;
}

template <class T>
void MGraph<T>::CreateGraph()//ok
{
	cout<<"��������Ҫ��ͼ������!  ����ͼ(0)��������(1)������ͼ(2)��������(3)";
	cin>>mgraph.kind;
	switch(mgraph.kind)
	{
	case 0 :CreateDG();break;
	case 1 :CreateDN();break;
	case 2:CreateUDG();break;
	case 3:CreateUDN();break;
	default: {cout<<"����ͼ���������"<<endl; MGraph();}
	}
}

template <class T>
void MGraph<T>::DestroyGraph()//ok
{
	if(mgraph.kind<2)
		//����
	{
		for(int i = 0 ;i<mgraph.vexnum;i++)
			for(int j = 0;j<mgraph.vexnum;j++)
			{
				if(mgraph.arcs[i][j].info)
				{
					delete []mgraph.arcs[i][j].info;
					mgraph.arcs[i][j].info = false;
				}
			}
	}
	else
        //����
	{
		for(int i = 0 ;i<mgraph.vexnum;i++)
			for(int j = i+1;j<mgraph.vexnum;j++)
			{
				if(mgraph.arcs[i][j].info)
				{
					delete []mgraph.arcs[i][j].info;
					mgraph.arcs[i][j].info = mgraph.arcs[j][i].info = false;
				}
			}
	}
	mgraph.vexnum = 0;
	mgraph.arcnum = 0;
}


template <class T>
T MGraph<T>::GetVex(int index)//ok
{
	if(index<0||index>=mgraph.vexnum)
		return false;//Խ�緵�ؿ�
	return mgraph.vexs[index];
}

template <class T>
void MGraph<T>::PutVex(T v,T value)//ok
{
	int index = LocateVex(v);
	if(index<0)
		return;
	mgraph.vexs[index] = value;
}

template <class T>
bool MGraph<T>::CreateDG()//ok
//��������ͼ
{
	  int i , j ;T v1,v2;
	cout<<"����������ͼ�Ķ�����������ĸ���: ";
	cin>>mgraph.vexnum>>mgraph.arcnum;
	cout<<"�������������: ";
	for(i = 0;i<mgraph.vexnum;i++)
	//���춥������
	{
		cin>>mgraph.vexs[i];
	}
	for(i = 0;i<mgraph.vexnum;i++)	
	//��ʼ���ڽӾ���
	{
		for(j = 0;j<mgraph.vexnum;j++)
		{
			mgraph.arcs[i][j].adj = 0;
            mgraph.arcs[i][j].info = false;
		}
	}
	for(i = 0;i<mgraph.arcnum;i++)
	//�����ڽӾ���
	{
		cout<<"������һ���������,�յ�: ";
		cin>>v1>>v2;
		int m = LocateVex(v1);
		int n = LocateVex(v2);
		mgraph.arcs[m][n].adj = 1;// <v1, v2>
	}
	mgraph.kind = 0;
	return true;
}

template <class T>
bool MGraph<T>::CreateDN()//ok
//����������
{
	  int i,j ,w;T v1, v2;
	cout<<"�������������Ķ�����������ĸ���: ";
	cin>>mgraph.vexnum>>mgraph.arcnum;
	cout<<"�������������: ";
	for(i = 0;i<mgraph.vexnum;i++)
	//���춥������
	{
		cin>>mgraph.vexs[i];
	}
	for(i = 0;i<mgraph.vexnum;i++)	
	//��ʼ���ڽӾ���
	{
		for(j = 0;j<mgraph.vexnum;j++)
		{
			mgraph.arcs[i][j].adj = infinity;
            mgraph.arcs[i][j].info = false;
		}
	}
	for(i = 0;i<mgraph.arcnum;i++)
	//�����ڽӾ���
	{
		cout<<"������һ���������,�յ�,Ȩֵ";
		cin>>v1>>v2>>w;
		int m = LocateVex(v1);
		int n = LocateVex(v2);
		mgraph.arcs[m][n].adj = w;// <v1, v2>��Ȩֵ
	}
	mgraph.kind = 1;
	return true;
}


template <class T>
bool MGraph<T>::CreateUDG()//ok
//��������ͼ
{
	  int i , j ;T v1, v2;
	cout<<"����������ͼ�Ķ���������ߵĸ���: ";
	cin>>mgraph.vexnum>>mgraph.arcnum;
	cout<<"�������������: ";
	for(i = 0;i<mgraph.vexnum;i++)
	//���춥������
	{
		cin>>mgraph.vexs[i];
	}
	for(i = 0;i<mgraph.vexnum;i++)	
	//��ʼ���ڽӾ���
	{
		for(j = 0;j<mgraph.vexnum;j++)
		{
			mgraph.arcs[i][j].adj = 0;
            mgraph.arcs[i][j].info = false;
		}
	}
	for(i = 0;i<mgraph.arcnum;i++)
	//�����ڽӾ���
	{
		cout<<"������һ������������������: ";
		cin>>v1>>v2 ;
		int m = LocateVex(v1);
		int n = LocateVex(v2);
		mgraph.arcs[m][n].adj = 1;// <v1, v2>
        mgraph.arcs[n][m].adj = 1;// <v2, v1>
	}
	mgraph.kind = 2;
	return true;
}

template <class T>
bool MGraph<T>::CreateUDN()//ok
//����������
{
	  int i , j ,w;T v1, v2;
	cout<<"�������������Ķ���������ߵĸ���: ";
	cin>>mgraph.vexnum>>mgraph.arcnum ;
	cout<<"�������������: ";
	for(i = 0;i<mgraph.vexnum;i++)
	//���춥������
	{
		cin>>mgraph.vexs[i];
	}
	for(i = 0;i<mgraph.vexnum;i++)	
	//��ʼ���ڽӾ���
	{
		for(j = 0;j<mgraph.vexnum;j++)
		{
			mgraph.arcs[i][j].adj = infinity;
            mgraph.arcs[i][j].info = false;
		}
	}
	for(i = 0;i<mgraph.arcnum;i++)
	//�����ڽӾ���
	{
		cout<<"������һ�����������������㡢Ȩֵ: ";
		cin>>v1>>v2>>w;
		int m = LocateVex(v1);
		int n = LocateVex(v2);
		mgraph.arcs[m][n].adj = w;// <v1, v2>
        mgraph.arcs[n][m].adj = w;// <v2, v1>
	}
	mgraph.kind = 3;
	return true;
}

template <class T>
int MGraph<T>::LocateVex(T u)//ok
{
	for(int i = 0 ;i<MAX_VERTEX_NUM;i++)
	{
		if(u == mgraph.vexs[i])
		{
			return i;
		}
	}
	return -1;
}


template <class T>
int MGraph<T>::FirstAdjVex(T v)//ok
{
	int temp = LocateVex(v); int j = 0;
	if(mgraph.kind==1||mgraph.kind==3)
		j = infinity;
	for(int i = 0 ;i<mgraph.vexnum;i++)
	{
		if(mgraph.arcs[temp][i].adj!=j)
		{
			return i;
		}
	}
	return -1; //���ڽӵ㷵�ؿ�
}


template <class T>
int MGraph<T>::NextAdjVex(T v,T w)//ok
{
	int id_v = LocateVex(v);
	int id_w = LocateVex(w);
	int j = 0;
	if(mgraph.kind==1||mgraph.kind==3)
		j = infinity;
	for(int i = id_w+1;i<mgraph.vexnum;i++)
	{
		if(mgraph.arcs[id_v][i].adj!=j)
		{
			return i;
		}
	}
	return -1;
}


template <class T>
bool MGraph<T>::InsertVex(T v)//ok
{
	if(mgraph.vexnum>=MAX_VERTEX_NUM)
		return false;
	if(LocateVex(v)>=0)
		return false;
	mgraph.vexs[mgraph.vexnum] = v;
	for(int i = 0;i<=mgraph.vexnum;i++)
	{
		if(mgraph.kind%2)
		//��
		{
			mgraph.arcs[mgraph.vexnum][i].adj = infinity; //����һ��
			mgraph.arcs[i][mgraph.vexnum].adj = infinity; //�ұ�һ��
		}
		else
		//ͼ
		{
			mgraph.arcs[mgraph.vexnum][i].adj = 0; //����һ��
			mgraph.arcs[i][mgraph.vexnum].adj = 0; //�ұ�һ��
		}
		mgraph.arcs[mgraph.vexnum][i].info = false;
		mgraph.arcs[i][mgraph.vexnum].info = false;
	}
	mgraph.vexnum++;
	return true;
}


template <class T>
bool MGraph<T>::InsertArc(T v,T w)//ok
{
	int v1,w1,weight ;
	v1 = LocateVex(v);
	w1 = LocateVex(w);
	if(v1<0||w1<0)
		return false;
	mgraph.arcnum++;
	if(mgraph.kind%2)//��
	{
		cout<<"������˻���ߵ�Ȩֵ";
		cin>>weight;
		mgraph.arcs[v1][w1].adj = weight;
	}
	else//ͼ
	{
		mgraph.arcs[v1][w1].adj = 1;
	}

	if(mgraph.kind>1) //����
	{
		mgraph.arcs[w1][v1].adj = mgraph.arcs[v1][w1].adj;
        mgraph.arcs[w1][v1].info = mgraph.arcs[v1][w1].info;//����һ���ڴ�

	}
	return true;
}


template <class T>
bool MGraph<T>::DeleteVex(T v)//ok
{
	int delpos,vrtype = 0,i,j;
	delpos = LocateVex(v);
	if(delpos<0)
		return false;
	if(mgraph.kind%2)
		vrtype = infinity;
	for(i = 0;i<mgraph.vexnum;i++)
	{
		if(mgraph.arcs[i][delpos].adj != vrtype)
		//���뻡���
		{
			if(mgraph.arcs[i][delpos].info != false)
				//ɾ����Ϣ
			{
				delete [](mgraph.arcs[i][delpos].info);
                mgraph.arcs[i][delpos].info = false;
				mgraph.arcs[delpos][i].info = false;
			}
			mgraph.arcnum--;
		}
	}

	if(mgraph.kind<2)//����
	{
		 for(j = 0;j<mgraph.vexnum;j++)
		 {
			 if(mgraph.arcs[delpos][j].adj != vrtype)
				 //�г���
			 {
				 if(mgraph.arcs[delpos][j].info)
				 {
					 delete []mgraph.arcs[delpos][j].info;
					 mgraph.arcs[delpos][i].info = false;
				 }
				 mgraph.arcnum--;
			 }
		 }
	}
	for(i = delpos+1;i<mgraph.vexnum;i++)
		//���delpos��Ķ����������δ�ǰ��
	{
		mgraph.vexs[i-1] = mgraph.vexs[i];
	}
	for(i = 0;i<mgraph.vexnum;i++)
	{
		for(j = delpos+1;j<mgraph.vexnum;j++)
			//�ƶ�ɾ������֮�ҵľ���Ԫ��
		{
			mgraph.arcs[i][j-1] = mgraph.arcs[i][j];
		}
	}
	for(i = 0;i<mgraph.vexnum;i++)
	{
		for(j = delpos+1;j<mgraph.vexnum;j++)
			//�ƶ���ɾ������֮�µľ���Ԫ��
		{
		    mgraph.arcs[j-1][i] = mgraph.arcs[j][i];
		}
	}
	mgraph.vexnum--;
	return true;
}

template <class T>
bool MGraph<T>::DeleteArc(T v,T w)//ok
{
	int v1,w1;
	v1 = LocateVex(v);
	w1 = LocateVex(w);
	if(v1<0||w1<0)
		return false;
	if(mgraph.kind%2 == 0)
		//ͼ
	{
		mgraph.arcs[v1][w1].adj = 0;
	}
	else
		//��
	{
		mgraph.arcs[v1][w1].adj = infinity;
	}
	if(mgraph.arcs[v1][w1].info)
	{
		delete []mgraph.arcs[v1][w1].info;
		mgraph.arcs[v1][w1].info = false;
	}
	if(mgraph.kind>1)
		//����ɾ��<w,v>
	{
		mgraph.arcs[w1][v1].adj = mgraph.arcs[v1][w1].adj;
		mgraph.arcs[w1][v1].info = false;
	}
	mgraph.arcnum--;
	return true;
}

template <class T>
void MGraph<T>::DisPlay()
{
	int i,j;
	char graphkind[7];
	char arckind[3];
	switch(mgraph.kind)
	{
	case 0:strcpy(graphkind,"����ͼ");
		   strcpy(arckind,"��");
		   break;
	case 1:strcpy(graphkind,"������");
		   strcpy(arckind,"��"); 
		   break;
	case 2:strcpy(graphkind,"����ͼ");
		   strcpy(arckind,"��");
		   break;
	case 3:strcpy(graphkind,"������");
		   strcpy(arckind,"��");
		   break;
	}
	cout<<mgraph.vexnum<<"������"<<mgraph.arcnum<<"��"<<arckind<<"��"<<graphkind<<endl;
	//�������
	cout<<"����Ϊ";
	for(i = 0;i<mgraph.vexnum;i++)
	{
		cout<<mgraph.vexs[i]<<" ";
	}
	//���Ȩֵ���ڽӾ���
	cout<<"Ȩֵ���ڽӾ���Ϊ: "<<endl;
	for(i = 0;i<mgraph.vexnum;i++)
	{
		for(j = 0;j<mgraph.vexnum;j++)
		{
			if(mgraph.arcs[i][j].adj==infinity)
				cout<<setw(5)<<"��"<<'\t';
			else
				cout<<setw(5)<<mgraph.arcs[i][j].adj<<'\t';
		}
		cout<<endl<<endl;
	}
}


template <class T>
void MGraph<T>::DFS(int index)
//�ӵ�index����������ݹ��������ȱ���ͼ
{
	T v1;int i;
	visited[index] = true;//�ѷ���
	VisitFunc(mgraph.vexs[index]);//����index �Ķ���
	v1 = GetVex(index);
	for(i = FirstAdjVex(v1);i>=0;i = NextAdjVex(v1,GetVex(i)))
	{
		if(!visited[i])
			DFS(i);//��v����δ���ʵ��ڽӶ���w�ݹ����DFS
	}
}

template <class T>
bool MGraph<T>::DFSTraverse(bool (*visit)(T v))
{
	int i ;
    VisitFunc = visit;
   	for(i = 0;i<MAX_VERTEX_NUM;i++)
	{
		visited[i] = false;
	}
    for(i = 0;i<mgraph.vexnum;i++)
		//��ÿ��δ�����ʵĶ������������ȱ���
    {
	   if(!visited[i])
		   DFS(i);
    }
	cout<<endl;
    return true;
}

template <class T>
 bool MGraph<T>::BFSTraverse(bool (*visit)(T v))
{
	LinkedQueue<int> q;int i,j,receive; T u1;
	for(i = 0;i<MAX_VERTEX_NUM;i++)
	{
		visited[i] = false;
	}
	for(i = 0;i<mgraph.vexnum;i++)
		//��ÿ��δ�����ʵĶ�����й�����ȱ���
	{
		if(!visited[i])
		{
			visited[i] = true;
			if(!visit(mgraph.vexs[i]))
				return false;
			q.EnQueue(i);
			while(!q.IsEmpty())
			{
				q.DeQueue(receive); //��ͷԪ�س��Ӳ���Ϊreceive
				u1 = GetVex(receive);
				for(j = FirstAdjVex(u1);j>=0;j = NextAdjVex(u1,GetVex(j)))
				{
					if(!visited[j])
					{
						visited[j] = true;
						if(!visit(mgraph.vexs[j]))
							return false;
						q.EnQueue(j);
					}
				}
			}
		}
	}
	cout<<endl;
	return true;

}; 

//�˵� 
void ShowOper()
{
	cout<<endl;
	cout<<"0.  ����ͼ"<<endl;
	cout<<"1.  ���ض���v��ͼ�е�λ��"<<endl;
	cout<<"2.  ��������λ�õĶ����ֵ"<<endl;
	cout<<"3.  �ı�ĳ����֪����v��ֵ"<<endl;
	cout<<"4.  ��ͼ�������¶���v"<<endl;
	cout<<"5.  ��ͼ��ɾ������v�Լ����кͶ���v������ı߻�"<<endl;
	cout<<"6.  ��ͼ������һ���Ӷ���v������w�ı߻�"<<endl;
	cout<<"7.  ��ͼ��ɾ��һ���Ӷ���v������w�ı߻�"<<endl;
	cout<<"8.  ��ͼ�У��ӵ�һ���������������ȱ���ͼ"<<endl;
	cout<<"9.  ��ͼ�У��ӵ�һ�����������ȱ���ͼ"<<endl;
    cout<<"10. ��ʾͼ"<<endl;
	cout<<"11. ����ͼ"<<endl;
	cout<<"12. �˳�"<<endl;
	cout<<"��ѡ����Ҫ�Ĳ���: "<<endl;
}

void main()
{
	int opchoice;
	MGraph<string> g;//case0
    g.CreateGraph();
	do
	{   ShowOper();
		cin>>opchoice;
   	   switch(opchoice)
			{
				case 0:
					{
						g.CreateGraph();
						cout<<endl;
						break;
					}
				case 1:
					{
						string a;
						cout<<"��������Ҫ����Ҫ��ѯλ�õĶ�������� ";
						cin>>a;
						cout<<"����"<<a<<"��ͼ�е�λ��Ϊ"<<g.LocateVex(a)<<endl;
						cout<<endl;
						break;
					}
				case 2:
					{
						int index;
						cout<<"��������Ҫ����Ҫ��ѯ�����λ��";
						cin>>index;
						cout<<"λ��Ϊ"<<index<<"�Ķ���Ϊ"<<g.GetVex(index)<<endl;
						cout<<endl;
						break;
					}
				case 3:
					{
						string v;
						 string value;
						cout<<"��������Ҫ����Ҫ���ĵĶ����ֵ";
						cin>>v;
						cout<<"��������Ҫ����Ҫ���ĵĶ������ֵ";
						cin>>value;
						g.PutVex(v,value);
						cout<<endl;
						break;
					}
				case 4:
					{
						string v;
						cout<<"����������Ҫ���ӵĶ����ֵ";
						cin>>v;
						g.InsertVex(v);
						cout<<endl;
						break;
					}
				case 5:
					{
						string v;
						cout<<"����������Ҫɾ���Ķ����ֵ";
						cin>>v;
						g.DeleteVex(v);
						g.DisPlay();
						cout<<endl;
						break;
					}
				case 6:
					{
						string v,w;
						cout<<"����������Ҫ����һ���Ӷ���v������w�ı߻򻡵Ķ���v�Ͷ���w";
						cin>>v>>w;
						g.InsertArc(v,w);
						cout<<endl;
						break;
					}
				case 7:
					{
						string v,w;
						cout<<"����������Ҫɾ��һ���Ӷ���v������w�ı߻򻡵Ķ���v�Ͷ���w";
						cin>>v>>w;
						g.DeleteArc(v,w);
						cout<<endl;
						break;
					}
				case 8:
					{
						cout<<"�ӵ�һ���������������ȱ���ͼ������Ϊ"<<endl;
						g.DFSTraverse(visit);
						cout<<endl;
						break;
					}
				case 9:
					{
						cout<<"�ӵ�һ���������������ȱ���ͼ������Ϊ"<<endl;
						g.BFSTraverse(visit);
						cout<<endl;
					break;
					}
				case 10:
					{
						g.DisPlay();
						cout<<endl;
						break;
					}
				case 11:
					{
						g.DestroyGraph();
						cout<<endl;
						break;
					}
				case 12:
					cout<<"�������У�Bye-Bye!"<<endl;
					break;
				default:
					cout<<"ѡ�񲻺�������ѡ!"<<endl;
			}//case
		}while(opchoice!=12);
}//main
		 