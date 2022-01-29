//��ģʽƥ����ඨ��FindSub.cpp
#include<iomanip.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<string>
const maxsize=30;

int IndexBF(char s[],char t[],int pos)
{int i,j,m,n;
   i=pos-1;j=0;
   m=strlen(s);
   n=strlen(t);
 while(i<m && j<n)
  {if(s[i]==t[j])
    {++i;++j;}
   else {i=i-j+1;j=0;}
  }
 if(j>=n) 
	 return i-n+1;
 else  
	 return -1;
}

void GetNext(char t[],int next[])
{// ��ģʽ��T��next����ֵ����������next
	int j=0,k=-1;
	int n=strlen(t);
	next[j]=-1;
	while(j<n)
		{
		 if(k==-1||t[j]==t[k])
			 {j++;k++;next[j]=k;}
		 else k=next[k];
		 }
}

int IndexKMP(char s[],char t[],int next[],int pos)
{// ����ģʽ��T��next������T������S�е�pos���ַ�֮���λ�õ�KMP�㷨��
   // ����,T�ǿ�,1��pos��StrLength(S)
	int i,j,n;
	i=pos-1;j=0;
	int m=strlen(s);
	//s[m]='\0';
	n=strlen(t);
	//t[n]='\0';
	while(i<m && j<n)
	   if(j==-1||s[i]==t[j])
		{i++;j++;}// �����ȽϺ���ַ�
	   else j=next[j];// ģʽ�������ƶ�
	if(j>=n) return i-n+1;// ƥ��ɹ�
	return -1;
}

//��ģʽƥ��Ĳ���
void main()
{   char s[maxsize]="aaabaaaabaa",t[maxsize]="aaaab";
    int index,*next;
    int choice,j,pos=0;
	int m,n;
	m=strlen(s);
	n=strlen(t);
	next=new int[n];
    GetNext(t,next); 
	do
	{//��ʾ���˵�
		cout<<"1-BFƥ��\n";
		cout<<"2-KMPƥ��\n";
		cout<<"3-�鿴Next[]\n";
		cout<<"4-��ʾ��\n";
		cout<<"6-�˳�\n";
		cout<<"Enter choice:";
		cin>>choice;
		switch(choice)
			{
			case 1://BFƥ��
			   cout<<"����ƥ����ʼλ��:";
			   cin>>pos;
		   	   if(pos<=m-n+1)
			  {
			      cout<<"����Ϊ:"<<s<<'\t'<<"�Ӵ�Ϊ:"<<t<<endl;
				   cout<<"BF�Ľ��:"<<endl;
        	     index=IndexBF(s,t,pos);
                 if(index!=-1)
					 cout<<"ģʽ��t������s�е�λ�ôӵ�"<<index<<"���ַ���ʼ"<<endl;
			     else cout<<"����s�в���ģʽ��t"<<endl;
			   }
			  else
			  { cout<<"λ�÷Ƿ����޷�ƥ��!"<<endl; }
		       break;
	      case 2://KMP�㷨
		   	  cout<<"����ƥ����ʼλ��:";
		      cin>>pos; 
			  if(pos<=m-n+1)
			  {
			      cout<<"����Ϊ:"<<s<<'\t'<<"�Ӵ�Ϊ:"<<t<<endl;
				  cout<<"KMPƥ����:"<<endl;
                  index=IndexKMP(s,t,next,pos);
                  if(index!=-1)
					  cout<<"ģʽ����������λ�ôӵ�"<<index<<"���ַ���ʼ"<<endl;
			      else
					cout<<"����s�в���ģʽ��t"<<endl;
			  }
			  else
			  { cout<<"λ�÷Ƿ����޷�ƥ��!"<<endl; }
		       break;
	      case 3://��ʾNEXT
	           cout<<"�Ӵ�Ϊ��"<<t<<endl;
			  for(j=0;j<n;j++)
					{
					cout<<"next["<<j<<"]="<<next[j]<<'\t';
					if((j+1)%5==0) cout<<endl;
					}
			  cout<<endl;
			   break;
		  case 4: //��ʾ��
      		  cout<<"����Ϊ��"<<s;
			  cout<<"�Ӵ�Ϊ: "<<t;
		      cout<<endl;
		      break;
	    case 6://�˳�
		     cout<<"��������!"<<endl;  
			 break;
	    default:
		     cout<<"Invalid choice\n";
		     break;
		}
	}while(choice!=6);
}


