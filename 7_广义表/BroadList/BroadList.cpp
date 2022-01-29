#include "BroadList.h" //���ù�����ͷ�ļ�
#include <string> //����string�⺯����ͷ�ļ�     
using namespace std;//ָ�����������еĳ�����䶼�����ֿռ�std��

template <class T>
GLists<T>::GLists(string st)
{
	ls=Crtlists(st);
}

template <class T>
GLNode<T>* GLists<T>::Crtlists(string st)
{
  GLNode<T> *ls,*p,*q;
  string sub,hsub;
  if(st == "()")//�������stΪ��ʱ����ls = NULL
    ls = NULL;
  else
    if(st.length()==1) //�������stΪ��Ԫ��ʱ������һ��Ԫ�ؽڵ㣬����ֵ�����ѽڵ㸳��ls
    {
      ls = new GLNode<T> ;
			ls->tag = 0;
			ls->data = st[0];
    }
    else //�������stΪ�ǿ�ʱ���������µĴ���
    {
      ls = new GLNode<T> ;
			ls->tag = 1;   //���һ����ڵ�����ǰ�ڵ�
      p = ls;sub = st.substr(1,st.length()-2); //ȥ���ַ�����ͷ��"()"
      do // ����ִ��������̣�ֱ��st�г�Աȫ�������
      {
        Server(sub,hsub); //��st��ȡ��һ��Ա
        p->ptr.hp = Crtlists(hsub);q=p;
        if(sub!="")
        {
          p = new GLNode<T> ;
					p->tag = 1;
					q->ptr.tp= p;
        };
      }while(sub!="");
      q->ptr.tp = NULL;
    }
    return(ls); 
}


template <class T>
void GLists<T>::Server(string &st,string &hst)
{
  char ch;string sch;
  int i,k,n;
  n=st.length();i=1;k=0;
  do //Ѱ�ҷֽ��
  {
    
		sch = st.substr(i-1,1);ch = sch[0];//�õ�st�еĵ�һ�ַ�
    switch(ch) //�ж��Ƿ�Ϊ  '(' ')'
    {
      case '(':k++;break;
      case ')':k--;break;
    };
    i++;
  }while(!((i>n)||((ch==',')&&(k==0))));
  if(i<=n)//ȡ��һ����Ա
  {
    hst = st.substr(0,i-2);
    st = st.substr(i-1,n-i+1);
  }
  else  //ɨ�����ʱ��û������',', stȫ����hst��st��Ϊ��ֵ��
  {
    hst = st;
    st = "";
  };
}

template <class T>
void GLists<T>::Prt(GLNode<T>* ls)
{
  GLNode<T>* p;
  if(ls !=NULL)       //���lsΪ���˳�������ִ������Ĳ���
  {
    if(ls->tag == 1)  //�жϽڵ��ǲ��Ǳ�ڵ�
    {
      Ena('(');       // �����"("
      Prt(ls->ptr.hp);p = ls->ptr.tp; // �ٵݹ���ñ���������ù����ĵ�һ����Ա��
      while(p!=NULL) //�ظ��ù��̴�������������Ա
      {
        Ena(',');    //��Ա֮��Ӹ�����
        Prt(p->ptr.hp);p = p->ptr.tp;
      };
      Ena(')');
    }
    else // lsָ��Ԫ�ؽڵ�ʱ���Ԫ�ؽڵ��ֵ
			Ena(ls->data);
	}

}

template <class T>
void GLists<T>::Ena(char ch)
{
  stprt[chnumber]=ch;chnumber++;
}

template <class T>
void GLists<T>:: Setinfo()
{
	chnumber=0;
}

template <class T>
void GLists<T>::Prnt()
{
  Setinfo();
	Prt(ls);
	for(int i=0;i<chnumber;i++)
	cout<<stprt[i];
	cout<<endl;
}

template <class T>
int GLists<T>::DepthGList()
{
	return Depth(ls);
}

template <class T>
int GLists<T>::Depth(GLNode<T>* ls)
{
  if (ls==NULL) return 1;         //�ձ����Ϊ1
  if (ls->tag==0) return 0;       //��Ԫ�����Ϊ0
  int max=0,dep; GLNode<T>*p = ls;
  while (p)
  {
    dep = Depth(p->ptr.hp);      //����p��ptr.hpΪͷָ����ӱ���ͷ�����
    if (dep>max) max = dep;
    p = p->ptr.tp;              //׼�����β�����
  }
  return max+1;                 //�ǿձ������Ǹ�Ԫ�ص���ȵ����ֵ��1
}

template <class T>
int GLists<T>::Length()
{
  if (ls==NULL) return 0;         //�ձ���Ϊ0
  int max=1; 
  GLNode<T>*p = ls->ptr.tp;
  while (p)
  {
    max++;
    p = p->ptr.tp;              //׼�����β�ĳ���
  }
  return max;                
}

template <class T>
GLists<T> * GLists<T>::Head()
{
  GLists<T> * hlists = new GLists<T>;   //����һ���¹����
  if(ls->tag==1)                //���ls�б�ͷ����ֵ��hlists
    hlists->ls = ls->ptr.hp;
  return (hlists);
}

template <class T>
GLists<T> *GLists<T>::Tail()
{
  GLists<T> * tlists = new GLists<T>;  //����һ���¹����
  if(ls->tag==1)                     //���ls�б�β����ֵ��hlists
    tlists->ls = ls->ptr.tp;
  return (tlists);
}

template <class T>
GLists<T>::GLists(GLists ls1, GLists ls2)
{
	GLNode<T> *p,*q,*ls;
  ls = new GLNode<T>;//����������ͷָ��
  ls->tag = 1;       //��������ڵ�Ϊ�ӱ�
	p = new GLNode<T> ;
	q = new GLNode<T> ;
	*p = *ls1.ls;
	*q = *ls2.ls;
  ls->ptr.hp = p;  //��ͷָ��ָ��ls1
  ls->ptr.tp = q;  //��βָ��ָ��ls2
}
