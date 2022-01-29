#ifndef __BROADLIST_H_
#define __BROADLIST_H_
#include <string> //����string�⺯����ͷ�ļ�  
using namespace std; //ָ�����������еĳ�����䶼�����ֿռ�std��

template <class T>
struct  GLNode
{
    int  tag;                //��־����������Ԫ�ؽ��ͱ���
    T data;                  //data��Ԫ�ؽ���������
    struct atom
    {
      GLNode *hp, *tp;       //hp��tp�ֱ�ָ���ͷ�ͱ�β
    } ptr;

};

template <class T>
class GLists
{
public:
  GLists(){ls = NULL;}//�޲ι��캯������ʼ��Ϊ�յĹ����
  GLists(string st);//�вι��캯�����������������ʽ���������Ĵ洢�ṹ
  GLists(GLists ls1, GLists ls2);   //�вι��캯�����ñ�ͷls1�ͱ�βls2��������
  ~GLists(){delete [] ls;}   //�����������ͷŹ�����и����Ĵ洢�ռ�
  int DepthGList();   //����������
  int Length(); //������ĳ���
  GLists<T> *Head();  //������ı�ͷ
  GLists<T> *Tail();   //������ı�β
  void Prnt(); //���������ʾ����
private:
  GLNode<T>* ls;  //ls��ָ�������ͷָ��
  GLNode<T>* Crtlists(string st);//�ѹ����������ʽstת��Ϊ������ͷβ�洢�ṹ
  void Server(string &st,string &hst); // ��st��ȡ����һ��Ա���뵽hst������ĳ�Ա����st��
  void Ena(char ch);//�洢�����������Ϣ
  int Depth(GLNode<T>* ls);   //����������
  char stprt[50];//��ʾһЩ������Ϣ
  int chnumber;
  void  Setinfo();//��ʼ����������Ϣ
  void Prt(GLNode<T>* ls);//��ls��ָ�Ĺ������ʾ����
};
#endif

