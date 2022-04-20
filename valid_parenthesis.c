#define _CRT_SECURE_NO_WARNINGS

//ջ���ص㣺�������������ȳ�
char match(char matchcharacter)   //����ƥ����������
{
    switch (matchcharacter)
    {
    case ')':return '(';
    case ']':return '[';
    case '}':return '{';
    }
    return 0;
}

bool isValid(char* s)
{
    int length = strlen(s);
    if (length % 2 != 0)
    {
        return false;
    }
    char* leftParentheses = (char*)calloc(length + 1, 1);//��¼��˳����ֵ�������
    int leftnum = 0;                //��¼��ƥ���������������ͬʱҲ�ǽ�������������Ҫ��¼�����±�λ��
    for (int i = 0; i < length; i++)
    {
        //����һ������
        char ch = match(s[i]);//�ж��������Ż���������

        if (ch == 0)//�����������
        {
            //˵����ƥ�����������Ŀ����1,ͬʱ��¼�����ţ���¼����
            leftParentheses[leftnum] = s[i];
            leftnum++;
        }
        else//����������ţ������������ֵ������Ž���ƥ��
        {
            if (leftnum == 0)//��û���ֿ�ƥ��������ţ�ֱ��false
            {
                return false;
            }
            else if (leftParentheses[--leftnum] != match(s[i]))//�������ֵ������Ų���ƥ��ճ��ֵ�������
            {
                return false;
            }
            //ע�⣺�������ƥ�䣬��ʱleftnum�Ѿ�-1
            else
            {
                //ƥ��ɹ���Ӧȥ�������ֵ��Ǹ�������
                leftParentheses[leftnum] = '\0';
            }
        }
    }
    if (strlen(leftParentheses) == 0)//��󲻴���δƥ��������ţ��ͷ���true
    {
        return true;
    }
    else
        return false;
}