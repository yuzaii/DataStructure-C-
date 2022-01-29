#include<iostream.h>//cout,cin
#include"process.h"//exit()
#include"stdio.h"//EOF,NULL
#include<string.h>
#include<stdlib.h> // atoi()
#include"SqStack.h"
char pause;

char Precede(char t1,char t2)  
 {//��������ȼ��Ƚ� 
   char f;
   switch(t2)
   {
     case '+':
     case '-':if(t1=='('||t1=='=')
                f='<';
              else
                f='>';
              break;
     case '*':
     case '/':if(t1=='*'||t1=='/'||t1==')')
                f='>';
              else
                f='<';
              break;
     case '(':if(t1==')')
              {
                cout<<"ERROR1"<<endl;
                exit(0);
              }
              else
                f='<';
              break;
     case ')':switch(t1)
              {
                case '(':f='=';
                         break;
                case '=':cout<<"ERROR2"<<endl;
                         exit(0);
                default: f='>';
              }
              break;
     case '=':switch(t1)
              {
                case '=':f='=';
                         break;
                case '(':cout<<"ERROR2"<<endl;
                         exit(0);
                default: f='>';
              }
   }
   return f;
 }

 
int In(char c) 
 { // �ж�c�Ƿ�Ϊ�����
   switch(c)
   {
     case'+':
     case'-':
     case'*':
     case'/':
     case'(':
     case')':
     case'=':return 1; 
     default:return 0;
   }
 }


float Operate(float a,char theta,float b) 
 {//ʵʩһ������
   float c;
   switch(theta)
   {
     case'+':c=a+b;
             break;
     case'-':c=a-b;
             break;
     case'*':c=a*b;
             break;
     case'/':c=a/b;
   }
   return c;
 }

float Val_Exp(char *exp) 
 { //��׺���ʽ��ֵ����OPTR��OPND�ֱ�Ϊ�����ջ��������ջ
   SqStack<char> OP(20);
   SqStack<float>  OD(20);
   char theta;
   float a,b,d;
   char c,x; // ����ɼ��̽��յ��ַ�
   char z[6]; // ��ŷ������ַ���
   int i;
   OP.Push('='); // =�Ǳ��ʽ������־
   c=*exp++;
   x=OP.GetTop();
   while(c!='='||x!='=')
   {
     if(In(c)) // ��7�������֮һ
       switch(Precede(x,c))
       {
         case'<':OP.Push(c); // ջ��Ԫ������Ȩ��
                 c=*exp++;
                 break;
         case'=':x=OP.Pop(); // �����Ų�������һ�ַ�
                 c=*exp++;
                 break;
         case'>':theta=OP.Pop(); // ��ջ������������ջ
                 b=OD.Pop();
                 a=OD.Pop();
                 OD.Push(Operate(a,theta,b));
       }
     else if(c>='0'&&c<='9'||c=='.') // c�ǲ�����
     {
       i=0;
       do
       {
         z[i]=c;
         i++;
         c=*exp++;
       }while(c>='0'&&c<='9'||c=='.');
       z[i]='\0';
       d=atof(z); // ���ַ�������תΪ�����ʹ���d
       OD.Push(d);
     }
     else // c�ǷǷ��ַ�
     {
       cout<<"ERROR3"<<endl;;
       exit(0);
     }
     x=OP.GetTop();
   }
   d=OD.GetTop();
   return d;
 }

void CreatePostExp(char * exp,char * &postexp)
{//����׺ʽ���׺ʽ
	char c,x;
	int i=0;
	SqStack<char> OP(20);
	OP.Push('='); // =�Ǳ��ʽ������־
	cout<<"exp:"<<exp<<endl;
	c=*exp++;
	while(c)
	{
		if((c>='0'&&c<='9')||c=='.')
		{
			postexp[i++]=c;
			c=*exp++;
		}
		if(In(c)) // ��7�������֮һ
		{
			postexp[i++]=' ';
     	    x=OP.GetTop();
			switch(Precede(x,c))
			{
				case'<':OP.Push(c); // ջ��Ԫ������Ȩ��
                         c=*exp++;
                         break;
                 case'=':x=OP.Pop(); // �����Ų�������һ�ַ�
                         c=*exp++;
                         break;
                 case'>':postexp[i++]=OP.Pop(); // �������ջ���
					     break;
			}
		}
		postexp[i]='\0';
	}//while
	cout<<"��׺���ʽΪ:"<<postexp<<endl;
}

float Val_PostExp(char *postexp)
{//��׺���ʽ��ֵ
	int i;
	char z[6];
	float v=0,d=0,a,b;
	char c;
	SqStack<float> OD(20);
	c=*postexp++;
	while(c!='\0')
	{
		if((c>='0'&&c<='9')||c=='.')//Ϊ������
		{
			i=0;
			do
			{
				z[i++]=c;
				c=*postexp++;
			}while(c>='0'&&c<='9'||c=='.');
			z[i]='\0';
			d=atof(z); // ���ַ�������תΪ�����ʹ���d
			OD.Push(d);
		}
		if(In(c))//cΪ�����
		{
			b=OD.Pop ();
			a=OD.Pop ();
			OD.Push (Operate(a,c,b));
			c=*postexp++;
		}
		c=*postexp++;
	}
	v=OD.Pop ();
	return v;
}


 //������
void main()
{
	//int i;
	char exp[20]="(2.2+5)+4*(5-3.1)=";
	char *postexp;
	postexp=new char[20];
	*postexp='\0';
    //char c;
	float v1;
	system("cls");//ִ��ϵͳ����cls������
	int choice;
    do
	{//��ʾ���˵�
		cout<<"1-�������ʽ\n";
		cout<<"2-���ʽ��ֵ\n";
		cout<<"3-���׺���ʽ\n";
		cout<<"4-��׺���ʽ��ֵ\n";
		cout<<"5-��ʾ���ʽ\n";
		cout<<"6-�˳�\n";
		cout<<"Enter choice:";
		cin>>choice;
		switch(choice)
			{
			case 1://�������ʽ
				cout<<"��������ʽ����=����"<<endl;
				cin>>exp;
				cin.get(pause);
				system("pause");
				break;
			case 2://���ʽ��ֵ
				v1=Val_Exp(exp) ;
				cout<<exp;
				cout<<v1<<endl;
				cin.get(pause);
    			system("pause");
				break;
			case 3://���׺���ʽ
				CreatePostExp(exp,postexp);
				cin.get(pause);
				system("pause");
				break;
			case 4://��׺���ʽ��ֵ
				v1=Val_PostExp(postexp);
				cout<<postexp<<"="<<v1<<endl;
				cin.get(pause);
				system("pause");
				break;
			case 5:// ��ʾ���ʽ
				cout<<endl;
				cout<<"�Ѵ����ı��ʽΪ��";
				cout<<exp<<endl;
				if(strlen(postexp))
				{
					cout<<"��׺���ʽΪ��";
					cout<<postexp<<endl; }
				    cin.get(pause);
				    system("pause");
				break;
			case 6://�˳�
				cout<<"�������У�Bye-Bye!"<<endl;
				break;
			default://
				cout<<"Invalid choice\n";
				break;
			}
	}while(choice!=6);
}//end main