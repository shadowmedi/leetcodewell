#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int convert(char a)
{
    switch (a)
    {
    case 'I':return 1;
    case 'V':return 5;
    case 'X':return 10;
    case 'L':return 50;
    case 'C':return 100;
    case 'D':return 500;
    case 'M':return 1000;
    }
    return -1;
}
/*
//˼·1�������ұ�������
//ÿһ�����ڵ��������ұ����ִ���������֣����ڼ��ϵ�ǰ���ֵ�ͬʱ����ȥ������ֵ�2��
int romanToInt(char * s)
{
    int ret = 0;
    int t = INT_MAX;//��t��¼������ֵ�ֵ
    for(int i = 0; i < strlen(s); i++)
    {
        if(convert(s[i]) > t)
        {
            ret -= 2*t;
            ret += convert(s[i]);
        }
        else
        {
            ret += convert(s[i]);
        }
        t = convert(s[i]);
    }
    return ret;
}*/

//˼·2�����������������
//���������������ͬ��С�����ͼӣ�ͬʱ�������ֵ��������С�����ͼ�
int romanToInt(char* s)
{
    int length = strlen(s);
    int t = 0;
    int ret = 0;
    int i = length - 1;
    for (i = length - 1; i >= 0; --i)
    {
        if (convert(s[i]) >= t)
        {
            ret += convert(s[i]);
            t = convert(s[i]);
        }
        else
        {
            ret -= convert(s[i]);
            //t = convert(s[i]);
        }
    }
    return ret;
}