//--------------------------------------------------------------------------------
#include "Base.cpp"
template <class T>
class CPreThreading:public CThr<T>
{
	bool IsThreaded;
	public:
		CPreThreading(){IsThreaded=false;}
		void Pre_ThreadBiTree();							//������������������
		void Pre_Thread(BiThrNode<T>*p,BiThrNode<T>**h);	//��������
		void Pre_TraThrBiTree();							//������������������
		void ShowPreTree();									//��ʾ�����������Ϣ
};
template <class T>
void CPreThreading<T>::Pre_ThreadBiTree()
{									//��������������������
	BiThrNode<T>*bt,*q=NULL;
	bt=BT;							//�����
	Pre_Thread(bt,&q);
}
//--------------------------------------------------------------------------------
template <class T>
void CPreThreading<T>::Pre_TraThrBiTree()
{
	if(IsThreaded==false){cout<<"������������"<<endl;return;}
	cout<<"\n--------------------------------------------------"<<endl;
	cout<<"�������������������ã�";
	BiThrNode<T>*p;
	if(BT==NULL) return ;			//��������Ϊ��
	cout<<BT->data<<' ';			//���������ֵ
	p=BT->lchild;					//��������
	if(p==NULL) p=BT->rchild;		//������Ϊ������������
	while(p!=NULL)
	{
		cout<<p->data<<' ';			//�����ǰ����ֵ
		while(p->lflag==0)			//����������ֱ�����־��0
		{
			p=p->lchild;
			cout<<p->data<<' ';
		}
		p=p->rchild;
	}
	cout<<"\n--------------------------------------------------"<<endl;

}
//--------------------------------------------------------------------------------
template <class T>
void CPreThreading<T>::Pre_Thread(BiThrNode<T>*bt,BiThrNode<T>**h)
{
	BiThrNode<T>*p,*q;				//�����������ָ�����
	if(bt!=NULL)					//btָ��Ľ�㲻��
	{
		p=bt->lchild ;
		q=bt->rchild ;
									//����ǰ���ʵĽ�����ָ��Ϊ�գ����ϴη��ʵĽ�㸳����ָ���򣬲��ñ�־��
		if((*h!=NULL)&&(p==NULL))
		{
			bt->lchild= *h;
			bt->lflag= 1;
		}
									//���ϴη��ʵĽ�����ָ��Ϊ��
									//�򽫷��ʹ��Ľ��ָ�븳����ǰ������ָ���򣬲��ñ�־��Ϊ1
		if((*h!=NULL)&&((*h)->rchild==NULL))
		{
			(*h)->rchild=bt;
			(*h)->rflag=1;
		}
		*h=bt;						//���µ�ǰ���ʵĽ��
		Pre_Thread(p,h);			//����������
		Pre_Thread(q,h);			//����������
	}
	IsThreaded=true;
}
//--------------------------------------------------------------------------------
template <class T>
void CPreThreading<T>::ShowPreTree()
{
	if(IsThreaded==false){cout<<"������������"<<endl;return;}
	cout<<"\n--------------------------------------------------"<<endl;
	cout<<"������ʾ���������������Ժ�Ľ����"<<endl;
	BiThrNode<T>*p;
	if(BT==NULL) return ;				//��������Ϊ�ա�
	if(BT->lflag==1)					//�����־��Ϊ1���������ǰ����
		cout<<"ֵΪ��"<<BT->data<<"����ǰ���ǣ�"<<BT->lchild->data<<endl;
	if(BT->rflag==1)					//�����־��Ϊ1��������ĺ�̡�
		cout<<"ֵΪ��"<<BT->data<<"���ĺ���ǣ�"<<BT->rchild->data<<endl;
	p=BT->lchild;						//����������
	if(p==NULL) p=BT->rchild;			//������Ϊ��������������
	while(p!=NULL)
	{
		if(p->lflag==1)					//�����־��Ϊ1���������ǰ����
			cout<<"ֵΪ��"<<p->data<<"����ǰ���ǣ�"<<p->lchild->data<<endl;
		if(p->rflag==1)					//�����־��Ϊ1��������ĺ�̡�
			cout<<"ֵΪ��"<<p->data<<"���ĺ���ǣ�"<<p->rchild->data<<endl;
		while(p->lflag==0)				//����������ֱ�����־��0
		{
			p=p->lchild;
			if(p->lflag==1)				//�����־��Ϊ1���������ǰ����
				cout<<"ֵΪ��"<<p->data<<"����ǰ���ǣ�"<<p->lchild->data<<endl;
			if(p->rflag==1)				//�����־��Ϊ1��������ĺ�̡�
				cout<<"ֵΪ��"<<p->data<<"���ĺ���ǣ�"<<p->rchild->data<<endl;
		}
		p=p->rchild;
	}
	cout<<"--------------------------------------------------"<<endl;

}
//--------------------------------------------------------------------------------
void main()
{
	int opr;//��������
	CPreThreading<int> Tr;//����һ�� int ģ�����͵Ķ���
	do{
		system("cls");
		cout<<"----------��   ��---------------"<<endl;
		cout<<"--* 1������������               *--"<<endl;
		cout<<"--* 2������������������         *--"<<endl;
		cout<<"--* 3������������������������� *--"<<endl;
		cout<<"--* 4����ʾ����������Ϣ         *--"<<endl;
		cout<<"--* 5���˳�����                 *--"<<endl;
		cout<<"--------------------------------"<<endl;
		cout<<"��ѡ�����  [ ]";
		cout<<"\b\b";
		
		cin>>opr;
		switch(opr)
		{
		case 1:
			if(Tr.GetRoot()) Tr.DeleteNode();	//�ͷ�֮ǰ�����Ķ�������н��ռ�
			Tr.CreateBiTree(-1);				//����������
			system("pause");
			break;
		case 2:
			Tr.Pre_ThreadBiTree();				//����������������
			cout<<"��������ɣ�"<<endl;
			system("pause");
			break;
		case 3:
			Tr.Pre_TraThrBiTree();				//�������������
			system("pause");
			break;
		case 4:
			Tr.ShowPreTree();					//��ʾ������֮��ı�־����Ϣ
			system("pause");
			break;
		case 5:
			cout<<"�������У�Bye-Bye!"<<endl;
			break;
		default:
			cout<<"ѡ�񲻺�������ѡ!"<<endl;
			break;
		}
	}while(opr!=5);
}
