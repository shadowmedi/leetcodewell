#define _CRT_SECURE_NO_WARNINGS
//������
/*int strStr(char * haystack, char * needle)
{
    int length = strlen(haystack);
    for(int i = 0; i < length; i++)
    {
        //����haystack������Ԫ��
        if(*(haystack+i) == *needle)//�����������Ԫ����needle�����ַ���ͬ
        {
            //��ʼ��needle������Ԫ�ض���
            char* tem2 = needle;
            char* tem1 = haystack+i;//Ϊ�˲��ı�needle��haystack,������ʱֵ
            while(*tem2 !='\0' && *tem1 == *tem2)//��Ҫ�ҵ��ַ���ȫ���ɹ����ա���*tem2=='\0'
            {                                    //��*tem1!=*tem2ʱ����ʧ��  �����˳�ѭ��
                tem2++;
                tem1++;
            }
            if(*tem2 == '\0')//ȫ�����ճɹ�
            {
                return i;
            }
        }
        //����������������Ԫ��
    }
    return -1;
}*/
//KMP�㷨
int getNEXTnum(char* needle, int index)
{
    int i = 0;          //ǰ׺�Ŀ�ͷ���֣�ͬʱҲ��ǰ��׺��ͬ���ֵ���󳤶�
    int j = 1;          //��׺�Ŀ�ͷ����
    if (index == 0)      //���next�����±�Ϊ0��needle��һ��Ԫ��֮ǰ��ǰ��׺������0
        return 0;         //����needle��һ��Ԫ�ؿ�ʼû�к�haystack��ǰ��������Ԫ�سɹ�ƥ�䣬��һ���������ַ���Ȼ��needle�ĵ�һ���ַ�����
    else if (index == 1)//���next�����±�Ϊ1��needle�ڶ���Ԫ��֮ǰ����ͬǰ��׺������0
        return 0;          //����needle�ڶ���Ԫ�ؿ�ʼû�к�haystack��ǰ��������Ԫ�سɹ�ƥ�䣬
    else
    {
        for (int j = 1; j <= index - 1; )
        {
            if (needle[i] != needle[j])//����ǰ׺�������׺���ֲ�ͬ��i����ǰ׺��ʼλ�� ���¶���
            {
                if (i > 0)//��i > 0˵��ǰ׺�ͺ�׺�Ѿ�ƥ��һ���֣���ʱӦ��j���˵�֮ǰһ��ʼ��iƥ�����һ��λ��
                {
                    j = j - i + 1;
                    i = 0;
                }
                else  
                {
                    j++;
                }
            }
            else
            {
                ++i;
                ++j; //iҲ��¼ǰ��׺��ͬ���ֵ���󳤶�
            }
        }
        return i;
    }
}
void initNEXT(int* next, char* needle)    //��ʼ��next��
{
    for (int k = 0; k < strlen(needle); k++)//��ֵ
    {
        next[k] = getNEXTnum(needle, k);
    }
}
int strStr(char* haystack, char* needle)
{
    int length1 = strlen(haystack);
    int length2 = strlen(needle);
    int* next = (int*)calloc(length2, sizeof(int));
    initNEXT(next, needle);
    int k = 0;
    for (int i = 0; i < length1; i++)
    {
        if (k < length2 && haystack[i] == needle[k])
        {
            k++;
        }
        else
        {
            if (k > 0 && k < length2)//����Ѿ�ƥ����k���ַ��жϣ���ʱӦ��next������needle����һ���±�ֵ���жεĵط�ƥ�䣬����i���ܱ�
            {
                i--;
                k = next[k];
            }
            else if (k == 0)
            {
                k = next[k];
            }
        }
        if (k == length2)//ƥ��ɹ��󣬷��ص�һ��ƥ��ɹ������ַ��±�
            return i - k + 1;
    }
    return -1;
}