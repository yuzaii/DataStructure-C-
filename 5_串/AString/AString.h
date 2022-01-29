//����Ķ���
class AString
{
private:
    char *ch;   //���������
    int curLength;    //����ʵ�ʳ���
    int maxSize;    //����������󳤶�. 
    void CheckMem();  //����ڴ��Ƿ�����ɹ�
public:
    AString();
    AString(int sz);         //���캯��,����һ����󳤶�Ϊsz,ʵ�ʳ���Ϊ0���ַ���
    AString(const char *init);   //���캯��,����һ����󳤶�ΪmaxSize,��init��ʼ�������ַ�������
    AString(const AString &ob);    //���ƹ��캯��,��һ�����е��ַ�������ob����һ�����ַ���
    ~AString(){delete[] ch;}   //��������,�ͷŶ�̬����Ĵ��ռ䲢�������ַ�������
    //���ַ�������ıȽ�����
    int operator == (AString &ob)const {return strcmp(ch,ob.ch) == 0;}  //�жϵ�ǰʵ���Ƿ���ob�����,������򷵻�1,���򷵻�0
    int operator != (AString &ob)const {return strcmp(ch,ob.ch) != 0;}  //�жϵ�ǰʵ���Ƿ���ob������,�������򷵻�1,���򷵻�0
    int operator < (AString &ob)const {return strcmp(ch,ob.ch)<0;} //�жϵ�ǰʵ�����Ƿ�С��ob��,��С���򷵻�1,����Ϊ0
    int operator > (AString &ob)const {return strcmp(ch,ob.ch)>0;}//�жϵ�ǰʵ�����Ƿ����ob��,��С���򷵻�1,����Ϊ0
    int operator <= (AString &ob)const {return strcmp(ch,ob.ch)<=0;}//�жϵ�ǰʵ�����Ƿ�С�ڵ���ob��,��С�ڵ����򷵻�1,����Ϊ0
    int operator >= (AString &ob)const {return strcmp(ch,ob.ch)>=0;}//�жϵ�ǰʵ�����Ƿ���ڵ���ob��,�����ڵ����򷵻�1,����Ϊ0
    //���ַ����ıȽ�����
    int operator == (char *str)const{return strcmp(ch,str) == 0;} //�жϵ�ǰʵ���Ƿ���C++�����,������򷵻�1,���򷵻�0
    int operator != (char *str)const{return strcmp(ch,str) != 0;}//�жϵ�ǰʵ���Ƿ���C++�������,�������򷵻�1,���򷵻�0
    int operator < (char *str)const {return strcmp(ch,str)<0;}//�жϵ�ǰʵ���Ƿ���С��C++��,��С���򷵻�1,���򷵻�0
    int operator > (char *str)const{return strcmp(ch,str)>0;}//�жϵ�ǰʵ���Ƿ������C++��,��С���򷵻�1,���򷵻�0
    int operator <= (char *str)const{return strcmp(ch,str)<=0;}//�жϵ�ǰʵ���Ƿ���С�ڵ���C++��,��С�ڵ����򷵻�1,���򷵻�0
    int operator >=(char *str)const {return strcmp(ch,str)>=0;}//�жϵ�ǰʵ���Ƿ�����ڵ���C++��,�����ڵ����򷵻�1,���򷵻�0
    AString& operator = (AString &ob);       //����ob��ֵ����ǰʵ��.
    AString& operator = (const char *str);   //���ַ�����ֵ���ַ�������
    AString& operator +=(AString &ob);      //����ǰʵ����������ob������֮�Ͳ�����maxSize���ob�����ڵ�ǰʵ���ĺ���.
    AString& operator +=(const char *str);   //����ǰʵ����������str������֮�Ͳ�����maxSize,���str���ӵ����������.
    char& operator[](int i);   //ȡ��ǰʵ���ĵ�i���ַ�����.
    bool IsEmpty()const{return curLength == 0;}    //�пպ���
    int Length() const{return curLength;}    //���ص�ǰʵ����ʵ���ַ�����.
    //������Ҫ�ǳ��ú��������صȵȣ�������ֵ��÷���
    void SubString(AString &subs,int index,int length);  //������index��ʼ��ȡlength���ȵ��ַ�������.
    AString& Remove(int startIndex,int length);   //������startIndex��ʼɾ��length���ַ�
    AString& Insert(int pos,const char *value);
     void Clear();   //��յ�ǰ�ַ�������
    void Output();   //���
};
//�����ʵ��
void AString::CheckMem()
{
    if(ch == NULL)
    {
        cerr<<"�ڴ����ʧ��!\n";
        exit(1);
    }
}

AString::AString()
{
    maxSize = defaultSize;
    curLength = 0;
    ch = new char[maxSize];
    CheckMem();
    ch[0] = '\0';
}

AString::AString(int sz)
{//�����캯��
    maxSize = sz;
    ch = new char[maxSize+1];
    CheckMem();
    curLength = 0;
    ch[0] = '\0';
}

AString::AString(const char *init)
{//�����캯��
    int initLength = strlen(init);
    maxSize = (initLength > defaultSize) ? initLength : defaultSize;
    ch = new char[maxSize+1];
    CheckMem();
    curLength = initLength;
    strcpy(ch,init);
}

AString::AString(const AString &ob)
{//�������ƹ��캯��
    maxSize = ob.maxSize;
    ch = new char[maxSize+1];
    CheckMem();
    strcpy(ch,ob.ch);
    curLength = ob.curLength;
}


AString& AString::operator =(AString &ob)
{
    if(&ob != this)//�����������Ϊ���Ҹ�ֵ
    {
        Clear();
        curLength = ob.curLength;
        strcpy(ch,ob.ch);
    }
    else
        cout<<"�ַ�������ֵ����!\n";
    return *this;
}

AString& AString::operator =(const char *str)
{//�ַ�����ֵ
    int strLength = strlen(str);
    maxSize = strLength>maxSize?strLength:maxSize;
    Clear();
    strcpy(ch,str);
    curLength = strLength;
    return *this;
}


AString& AString::operator +=(AString &ob)
{//�ַ�����������
    char *tempCH = ch;
    char *tempOb = ob.ch;
    int addLength = curLength+strlen(tempOb);
    maxSize = maxSize>addLength?maxSize:addLength;
    char *temp = new char[maxSize+1];
    char *tempT = temp;
    while(*tempCH!='\0')
        *tempT++=*tempCH++;
    while(*tempOb!='\0')
        *tempT++=*tempOb++;
    *tempT++='\0';
    Clear();
    strcpy(ch,temp);
    curLength=strlen(ch);
    delete[] temp;
    return *this;
}

AString& AString::operator +=(const char *str)
{//�ַ������ӵ��ַ�������
    char *tempCH = ch;
    int addLength = curLength+strlen(str);
    maxSize = maxSize>addLength?maxSize:addLength;
    char *temp = new char[maxSize+1];
    char *tempT = temp;
    while(*tempCH!='\0')
        *tempT++=*tempCH++;
    while(*str!='\0')
        *tempT++=*str++;
    *tempT++='\0';
    Clear();
    strcpy(ch,temp);
    curLength=strlen(ch);
    delete[] temp;
    return *this;
}

char& AString::operator [](int i)
{//��ȡ����λ���ϵ��ַ�
    if(i<0||i>curLength)
    {
        cerr<<"�ַ��±�Խ��\n";
        exit(1);
    }
    return ch[i];
}

void AString::SubString(AString &subs,int index,int length)
{
    if(index<0||index+length>maxSize||length<0)
    {
        cerr<<"���������߳���Խ��\n";
        exit(1);
    }
    if(IsEmpty())
        cerr<<"�ַ�������Ϊ��\n",exit(1);
    else
    {
        char *temp = new char[length+1];
        if(temp==NULL)
        {
            cerr<<"�ڴ�������\n";
            exit(1);
        }
        for(int i=0,j=index;i<length;i++,j++)
        {
            temp[i] = ch[j];
        }
        temp[length] = '\0';
		subs=temp;
    }
}



AString& AString::Remove(int startIndex,int length)
{
    if(startIndex<0||startIndex+length>maxSize||length<0)
    {
        cerr<<"�����򳤶�Խ��\n";
        exit(1);
    }
    if(IsEmpty())
        cerr<<"�ַ�������Ϊ��\n",exit(1);
    for(int i=0;i<curLength-startIndex-length;i++)
    {
        ch[i+startIndex] = ch[i+length+startIndex];
    }
    ch[curLength-length] = '\0';
    curLength=strlen(ch);
    return *this;
}


AString& AString::Insert(int pos,const char *value)
{
    if(pos>curLength||pos<0)
    {
        cerr<<"��ͼ�����λ��Խ��\n";
        exit(1);
    }
    int addLength = strlen(value) + curLength;

    maxSize = addLength>maxSize?addLength:maxSize;
    char *temp = new char[maxSize+1];
    char *tempCH = ch;
    char *tempH = temp;
    for(int i=0;i<pos;i++)
        *temp++ = *tempCH++;//�Ƚ���ǰ�����в���λ��֮ǰ���ַ����Ƶ�tempHָ����ڴ���
    while(*value!='\0')
        *temp++=*value++;//�ٽ���������ַ������ӵ�tempHָ����ڴ���
    while(*tempCH!='\0')
        *temp++=*tempCH++;//��󽫵�ǰ�������λ��֮����ַ����ӵ�tempHָ����ڴ���
    *temp='\0';
    Clear();            //��յ�ǰ����
    
    strcpy(ch,tempH);//��ƴ�Ӻõ��ַ������Ƶ�ʵ����
    curLength=strlen(ch);
    return *this;
    
}

void AString::Clear()
{
    delete[] ch;
    ch = new char[maxSize+1];
    CheckMem();//�ͷ��ڴ沢��������
    ch[0] = '\0';//����������Ϊ��
    curLength = 0;
}

void AString::Output()
{
    if(IsEmpty())
        cerr<<"�ַ�������Ϊ��"<<endl;
    else
        cout<<ch<<endl;
}

