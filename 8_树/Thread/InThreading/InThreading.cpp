#include "Base.cpp"
//--------------------------------------------------------------------------------
//��������������
template <class T>
class InThreading:public CThr<T>
{
	bool IsThreaded;								//��¼�Ƿ�������
	public:
		InThreading(){IsThreaded=false;};
	void In_ThreadBiTree();							//������������������
	void In_Thread(BiThrNode<T>*p,BiThrNode<T>**h);	//��������
	void In_TraThrBiTree();							//������������������
	void ShowPostTree();
};
//------------------------------------------------------------------------------
template <class T>
void InThreading<T>::In_ThreadBiTree()
{//��������������������
	BiThrNode<T>*p,*q=NULL;
	p=BT;
	In_Thread(p,&q);
}
//--------------------------------------------------------------------------------
template <class T>
void InThreading<T>::In_Thread(BiThrNode<T>*p,BiThrNode<T>**h)
{
	if(p)//pָ��Ľ�㲻��
	{
		
		In_Thread(p->lchild,h);//����������
		 //���ϴη��ʵĽ�����ָ��Ϊ�գ��򽫵�ǰ���ʵ��Ľ��ָ�븳������ָ�룬�����ұ�־��Ϊ1
		if((*h!=NULL)&&((*h)->rchild==NULL))
		{
			(*h)->rchild=p;//h���Ǹձ����ʹ��Ľ��ָ�룬p�ǵ�ǰ�����ʵĽ��ָ��
			(*h)->rflag=1;
		}
		//����ǰ���ʵĽ�����ָ��Ϊ�գ����ϴη��ʵ�ָ�븳����ǰ������ָ���򣬲������־λ1
		if(p->lchild==NULL)
		{
			p->lchild=(*h);
			p->lflag=1;
		}
		*h=p;
		In_Thread(p->rchild,h);//����������
	}
	IsThreaded=true;
}
//--------------------------------------------------------------------------------
template <class T>
void InThreading<T>::In_TraThrBiTree()
{//������������������
	if(IsThreaded==false){cout<<"������������"<<endl;return;}
	cout<<"\n--------------------------------------------------"<<endl;
	cout<<"�������������������ã�";
	BiThrNode<T> *p;
	if(BT==NULL) return ;			//��������Ϊ��
	p=BT;							//�����
	while(p->lflag==0) p=p->lchild;	//�������ҵ�Ҷ�ӽ��
	cout<<p->data<<' ';				//������������еĵ�һ�����ֵ
	while(p->rchild!=NULL)
	{
		if(p->rflag==1) p=p->rchild;
		else
		{							//��������������ɨ��
			p=p->rchild;
			while((p->lflag==0)&&(p->lchild!=NULL)) p=p->lchild;
		}
		cout<<p->data<<' ';			//����������н��ֵ
	}
	cout<<endl;
	cout<<"--------------------------------------------------"<<endl;
}
//--------------------------------------------------------------------------------
template <class T>
void InThreading<T>::ShowPostTree()
{
	if(IsThreaded==false){cout<<"������������"<<endl;return;}
	cout<<"\n--------------------------------------------------"<<endl;
	cout<<"����������������֮��:\n";
	BiThrNode<T> *p;
	if(BT==NULL) return ;			//��������Ϊ��
	p=BT;							//�����
	while(p->lflag==0) p=p->lchild;	//�������ҵ�Ҷ�ӽ��

	if(p->lflag==1&&p->lchild)				//�����־��Ϊ1���������ǰ����
		cout<<"ֵΪ��"<<p->data<<"����ǰ���ǣ�"<<p->lchild->data<<endl;
	if(p->rflag==1&&p->rchild)				//�����־��Ϊ1��������ĺ�̡�
		cout<<"ֵΪ��"<<p->data<<"���ĺ���ǣ�"<<p->rchild->data<<endl;
	while(p->rchild!=NULL)
	{
		if(p->rflag==1) p=p->rchild;
		else
		{							//��������������ɨ��
			p=p->rchild;
			while((p->lflag==0)&&(p->lchild!=NULL)) p=p->lchild;
		}
		if(p->lflag==1&&p->lchild)					//�����־��Ϊ1���������ǰ����
			cout<<"ֵΪ��"<<p->data<<"����ǰ���ǣ�"<<p->lchild->data<<endl;
		if(p->rflag==1&&p->rchild)					//�����־��Ϊ1��������ĺ�̡�
			cout<<"ֵΪ��"<<p->data<<"���ĺ���ǣ�"<<p->rchild->data<<endl;
	}
	cout<<"--------------------------------------------------"<<endl;
}
//void TestFunc()
void main()
{int opr;							//��������
		InThreading<int> Tr;		//����һ�� int ģ�����͵Ķ���
	do{
		system("cls");
		cout<<"--------��   ��---------------*"<<endl;
		cout<<"* 1����������������         *"<<endl;
		cout<<"* 2������������������       *"<<endl;
		cout<<"* 3����������������������   *"<<endl;
		cout<<"* 4����ʾ�����������Ķ����� *"<<endl;
		cout<<"* 5���˳�����               *"<<endl;
		cout<<"-----------------------------"<<endl;
		cout<<"��ѡ�����  [ ]";
		cout<<"\b\b";
		
		cin>>opr;
		switch(opr)
		{
		case 1:
			if(Tr.GetRoot()) Tr.DeleteNode();//�ͷ�֮ǰ�����Ķ�������н��ռ�
			Tr.CreateBiTree(-1);
			system("pause");
			break;
		case 2:
			Tr.In_ThreadBiTree();
			cout<<"��������ɣ�"<<endl;
			system("pause");
			break;
		case 3:
			Tr.In_TraThrBiTree();
			system("pause");
			break;
		case 4:
			Tr.ShowPostTree();
			system("pause");
			break;
		case 5:
			cout<<"���н�����Bye-Bye!"<<endl;
			break;
		default:
			break;

		}
	}while(opr!=5);
}

//1 3 6 -1 -1 2 -1 -1 8 4 -1 -1 -1
