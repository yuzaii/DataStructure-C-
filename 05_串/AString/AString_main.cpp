#include<iostream.h>
#include"stdio.h"//EOF,NULL
#include<string>
const int defaultSize = 128;
using namespace std;
#include"AString.h"

int main()
{
    cout<<"------------------------------------------------------------------------"<<endl;
    cout<<"�������ʼ������Ĵ�С��";
    int len;
    cin>>len;
	char *str = new char[len+1];
    cout<<"\n������Ҫ��ʼ���ַ���(���ܺ��пո�)��";
    cin>>str;
    AString string(len);
    string = str;
    int tag=0;
    while(1)
    {
        cout<<"1-ɾ������\n"
            <<"2-�������\n"
            <<"3-���Ӳ���\n"
            <<"4-��ȡ�ַ���\n"
            <<"5-�ַ��Ƚ�\n"
            <<"6-����ַ�������\n"
            <<"7-����ַ�����(��պ��ѡ�����8�����¸�ֵ)\n"
            <<"8-�ַ�������ֵ\n"
            <<"9-�˳�����\n";
        cout<<"\n������Ҫ�����ķ�������ţ�";
        cin>>tag;
        switch(tag)
        {
        case 1:
			{int index,length;
                 cout<<"������Ҫɾ������ʼλ�ã�";
                 cin>>index;
                 cout<<"\n������Ҫɾ���ĳ��ȣ�";
                 cin>>length;
                 string.Remove(index,length);
                 cout<<"\nɾ������ַ�����"<<endl;
                 string.Output();
                 break;}
        case 2:
			{int index;
                char *input = new char[defaultSize];
                cout<<"\n������Ҫ������ַ�����";
                cin>>input;
               	//cout<<" ����Ĵ���Ϊ��"<<strlen(input)<<endl;
				cout<<"\n������Ҫ�����λ�ã�";
                cin>>index;
                string.Insert(index,input);
                cout<<"\n�����ַ�������ַ�����"<<endl;
                string.Output();
                delete[] input;
                break;}
        case 3:
			{char *value = new char[defaultSize+1];
                cout<<"\n������Ҫ���ӵ��ַ�����";
                cin>>value;
                AString astr = value;
                string+=astr;
                cout<<"\n�����ַ�������ַ�����"<<endl;
                string.Output();
                delete[] value;
                break;}
		  case 4:
			  {int len,i;
               AString subs;
                cout<<"\n������Ҫ��ȡ���ַ������ȣ�";
                cin>>len;
               	cout<<"\n�����뿪ʼ��ȡ��λ�ã�";
                    cin>>i;
                 string.SubString(subs,i,len);
                cout<<"\n����Ϊ��ȡ����ַ�������";
                subs.Output();
                break;}
        case 5:
			{char *value = new char[128];
                cout<<"\n������Ҫ�Ƚϵ��ַ�����";
                cin>>value;
                cout<<"\n�ַ����ȽϽ��������ʾ��";
                string.Output();
                if(string>value) cout<<">";
				if(string==value) cout<<"=";
				if(string<value) cout<<"<";
				cout<<value<<endl;
                break;}
        case 6:
                cout<<"\n��ǰ�ַ��������ֵ������ʾ��";
                string.Output();
                break;
        case 7:
                string.Clear();
                cout<<"\n�ַ�����������գ�\n";
                break;
        case 8:
			{char *str = new char[128];
                cout<<"\n������Ҫ��ֵ���ַ���(�����пո�)��";
                cin>>str;
                string = str;
                cout<<"\n��ֵ����ַ�������Ϊ��";
                string.Output();
                break;}
        case 9:
			cout<<"���н���"<<endl;
			 return 0;
			 break;
		default:
			cout<<"ѡ��Ƿ�������ѡ!";
            break;
        }
    }
    
}