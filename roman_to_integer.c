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
//思路1：从左到右遍历数组
//每一对相邻的数字若右边数字大于左边数字，则在加上当前数字的同时，减去左边数字的2倍
int romanToInt(char * s)
{
    int ret = 0;
    int t = INT_MAX;//用t记录左边数字的值
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

//思路2：从右往左遍历数组
//遇到更大的数或相同大小的数就加，同时更新最大值，遇到更小的数就减
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