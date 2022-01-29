#include"BinaryTree.cpp"
#include"windows.h"
int main()
{
	int MainMenu=-1;
	BinaryTree<int> T;
	BinaryTree<int> t;
	while(MainMenu!=6)
	{
		system("cls");
		cout<<"--------------���˵�--------------"<<endl;
		cout<<"	1--����������(Ԫ������Ϊ����) "<<endl;
		cout<<"	2--������ʾ������"<<endl;
		cout<<"	3--��ȡ��������Ϣ  >>�������Ӳ˵���"<<endl;
		cout<<"	4--�Զ���������    >>�������Ӳ˵���"<<endl;
		cout<<"	5--����������      >>�������Ӳ˵���"<<endl;
		cout<<"	6--�˳�"<<endl;
		cout<<"	----------------------------------"<<endl;
		cout<<"		��ѡ�������[ ]";
		cout<<"\b\b";
		cin>>MainMenu;
		switch(MainMenu)
		{
		case 1:
			T.CreateBiTree(-1);
			break;
		case 2:
			cout<<"������ʾ����һ����ת��90�ȵ���!"<<endl;
			T.DisplayBTreeShape(T.GetRoot());//��һ�������Ǹ����ָ�룬�ڶ�������ΪĬ�ϵ�1 
			cout<<endl;
			system("pause");
			break;
		case 3:
			int op;
			//cin>>op;
			do
			{
				//system("cls");
				cout<<" ---3-��ȡ��������Ϣ---------"<<endl;
				cout<<"	0. �������˵�"<<endl;
				cout<<"	1. ��ȡ�������ֵ"<<endl;
				cout<<"	2. �ж����Ƿ�Ϊ��"<<endl;
				cout<<"	3. ���������"<<endl;
				cout<<"	4. ˫�׽��ֵ"<<endl;
				cout<<"	5. ����ֵ"<<endl;
				cout<<"	6. �Һ���ֵ"<<endl;
				cout<<"	7. ���ֵ�ֵ"<<endl;
				cout<<"	8. ���ֵ�ֵ"<<endl;
				cout<<"	9. Ҷ�ӽ��ĸ���"<<endl;
				cout<<"	10.������ʾ������"<<endl;
				cout<<" ------------------------------"<<endl;
				cout<<"	��ѡ�������[  ]";
				cout<<"\b\b\b";
				cin>>op;
				switch(op)
				{
				case 1:
					int root;
					if(T.RootValue(root)==true)
						cout<<"��������ֵΪ��"<<root<<endl;					
					else
						cout<<"������Ϊ��"<<endl;
					system("pause");
					break;
				case 2:
					if(T.IsEmpty()==true)
						cout<<"������Ϊ�գ�"<<endl;
					else 
						cout<<"���������գ�"<<endl;
					system("pause");
					break;
				case 3:
					cout<<"�����������Ϊ��"<<T.BiTreeDepth()<<endl;
					system("pause");
					break;
				case 4:
					cout<<"��������ֵ��";
					int node1;
					cin>>node1;
					cout<<"�ý���˫�׽��Ϊ��"<<T.GetParent(node1)<<endl;
					system("pause");
					break;
				case 5:
					cout<<"��������ֵ��";
					int node2;
					cin>>node2;
					cout<<"�ý������ӽ��ֵΪ��"<<T.GetLeftChild(node2)<<endl;
					system("pause");
					break;
				case 6:
					cout<<"��������ֵ��";
					int node3;
					cin>>node3;
					cout<<"�ý����Һ��ӽ��ֵΪ��"<<T.GetRightChild(node3)<<endl;
					system("pause");
					break;
				case 7:
					cout<<"��������ֵ��";
					int node4;
					cin>>node4;
					cout<<"�ý������ֵܽ��ֵΪ��"<<T.GetLeftSibling(node4)<<endl;
					system("pause");
					break;
				case 8:
					cout<<"��������ֵ��";
					int node5;
					cin>>node5;
					cout<<"�ý������ֵܽ��ֵΪ��"<<T.GetRightSibling(node5)<<endl;
					
					system("pause");
					break;
				case 9:
					cout<<"��������Ҷ�ӽ�����Ϊ��"<<T.LeafCount()<<endl;
					system("pause");
					break;
				case 10:
					cout<<"������ʾ����һ����ת��90�ȵĶ�����!"<<endl;
					T.DisplayBTreeShape(T.GetRoot());//��һ�������Ǹ����ָ�룬�ڶ�������ΪĬ�ϵ�1 
					cout<<endl;
					system("pause");
					break;
				default:
					break;
				}
			}while(op!=0);
			break;
		case 4:
			int op2;
			do
			{
				cout<<" ---------4 �Զ��������в���----------"<<endl;
				cout<<"	0. �������˵�"<<endl;
				cout<<"	1. ���ٶ�����"<<endl;
				cout<<"	2. ��ָ����㸳ֵ"<<endl;
				cout<<"	3. ����"<<endl;
				cout<<"	4. ɾ��"<<endl;
				cout<<"	5. ��ʾ������"<<endl;
				cout<<" ------------------------------------"<<endl;
				cout<<"	��ѡ�������[ ]";
				cout<<"\b\b";
				cin>>op2;
				switch(op2)
				{
				case 0:
					break;
				case 1:
					T.ClearBiTree();
					cout<<"�Ѿ������������٣�"<<endl;
					system("pause");
					break;
				case 2:
					int ChangeValue;//Ҫ�ı�Ľ��ֵ
					int NewValue;//�޸�֮��Ľ��ֵ
					cout<<"������Ҫ�޸ĵĽ��ֵ��";
					cin>>ChangeValue;
					cout<<"�������޸�֮��Ľ��ֵ��"<<endl;
					cin>>NewValue;
					if(T.SearchNode(ChangeValue)) 
					{
						(T.SearchNode(ChangeValue))->data=NewValue;
						cout<<"�޸ĳɹ���"<<endl;
					}
					else
					{
						cout<<"�޸�ʧ�ܣ�"<<endl;
					}
					system("pause");
					break;
				case 3:
					cout<<"�봴��һ��û���������Ķ�������"<<endl;
					t.CreateBiTree(-1);
					cout<<"������Ҫ����Ķ������Ľ��ֵ"<<endl;
					int invalue;
					cin>>invalue;
					cout<<"��ѡ�������������0��������������1��";
					int lr;
					cin>>lr;
					if(T.SearchNode(invalue)&&t.GetRoot()&&(t.GetRoot()->rchild)==NULL)
					{
						t.InsertChild(T.SearchNode(invalue),t.GetRoot(),lr);
						cout<<"�����ɹ���"<<endl;
						cout<<"�����Ժ�Ķ�����Ϊ��"<<endl;
						t.PreTraBiTree();
					}
					else
					{
						cout<<"����ʧ�ܣ�"<<endl;
					}
					system("pause");
					break;
				case 4:
					cout<<"���������ֵ��"<<endl;
					int mm;
					cin>>mm;
					cout<<"ɾ������������0���ҽ������1"<<endl;
					int tag;
					cin>>tag;
					if(T.SearchNode(mm))
					{
						T.DeleteChild(T.SearchNode(mm),tag);
						cout<<"�����ɹ�����ɾ��ָ���������"<<endl;
					}
					else
					{
						cout<<"����ʧ�ܣ�"<<endl;
					}
					T.PreTraBiTree();
					system("pause");
					break;
				case 5:
			        cout<<"������ʾ����һ����ת��90�ȵ���!"<<endl;
			        T.DisplayBTreeShape(T.GetRoot());//��һ�������Ǹ����ָ�룬�ڶ�������ΪĬ�ϵ�1 
		     	    cout<<endl;
			        system("pause");
			        break;
				default:
					break;
				}
			}while(op2!=0);
			break;
		case 5:
			int op3;
			do
			{
				//system("cls");
				cout<<" ---------5-����������----------------------"<<endl;
				cout<<"	0. �������˵�"<<endl;
				cout<<"	1. ����������������ݹ飩"<<endl;
				cout<<"	2. ����������������ݹ飩"<<endl;
				cout<<"	3. ����������������ݹ飩"<<endl;
				cout<<"	4. ����������������ǵݹ飩"<<endl;
				cout<<"	5. ����������������ǵݹ飩"<<endl;
				cout<<"	6. ��α���"<<endl;
				cout<<" --------------------------------------------"<<endl;
				cout<<"		��ѡ�������[ ]";
				cout<<"\b\b";
				cin>>op3;
				switch(op3)
					
				{
				case 1:
					T.PreTraBiTree();
					system("pause");
					break;
				case 2:
					T.InTraBiTree();
					system("pause");
					break;
				case 3:
					T.PostTraBiTree();
					system("pause");
					break;
				case 4:
					T.PreTraBiTree_N();
					system("pause");
					break;
				case 5:
					T.InTraBiTree_N();
					system("pause");
					break;
				case 6:
					T.LevelTraBiTree();
					system("pause");
					break;
				default:
					break;
				}
			}while(op3!=0);
			break;
		case 6:
			cout<<"�������н�����Bye-Bye!"<<endl;
			break;
		default:
			break;
}

	}
	return 0;
	
}
