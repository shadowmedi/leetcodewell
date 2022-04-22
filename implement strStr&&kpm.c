#define _CRT_SECURE_NO_WARNINGS
//暴力法
/*int strStr(char * haystack, char * needle)
{
    int length = strlen(haystack);
    for(int i = 0; i < length; i++)
    {
        //遍历haystack的所有元素
        if(*(haystack+i) == *needle)//如果遍历到的元素与needle的首字符相同
        {
            //开始和needle的所有元素对照
            char* tem2 = needle;
            char* tem1 = haystack+i;//为了不改变needle和haystack,创建临时值
            while(*tem2 !='\0' && *tem1 == *tem2)//当要找的字符串全部成功对照——*tem2=='\0'
            {                                    //或*tem1!=*tem2时对照失败  即可退出循环
                tem2++;
                tem1++;
            }
            if(*tem2 == '\0')//全部对照成功
            {
                return i;
            }
        }
        //否则继续遍历后面的元素
    }
    return -1;
}*/
//KMP算法
int getNEXTnum(char* needle, int index)
{
    int i = 0;          //前缀的开头部分，同时也是前后缀相同部分的最大长度
    int j = 1;          //后缀的开头部分
    if (index == 0)      //如果next数组下标为0，needle第一个元素之前无前后缀，返回0
        return 0;         //即从needle第一个元素开始没有和haystack当前遍历到的元素成功匹配，下一个遍历的字符仍然与needle的第一个字符对照
    else if (index == 1)//如果next数组下标为1，needle第二个元素之前无相同前后缀，返回0
        return 0;          //即从needle第二个元素开始没有和haystack当前遍历到的元素成功匹配，
    else
    {
        for (int j = 1; j <= index - 1; )
        {
            if (needle[i] != needle[j])//若该前缀部分与后缀部分不同，i返回前缀起始位置 重新对照
            {
                if (i > 0)//当i > 0说明前缀和后缀已经匹配一部分，此时应让j回退到之前一开始与i匹配的下一个位置
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
                ++j; //i也记录前后缀相同部分的最大长度
            }
        }
        return i;
    }
}
void initNEXT(int* next, char* needle)    //初始化next表
{
    for (int k = 0; k < strlen(needle); k++)//赋值
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
            if (k > 0 && k < length2)//如果已经匹配了k个字符中断，此时应在next表上找needle的下一个下标值与中段的地方匹配，所以i不能变
            {
                i--;
                k = next[k];
            }
            else if (k == 0)
            {
                k = next[k];
            }
        }
        if (k == length2)//匹配成功后，返回第一次匹配成功的首字符下标
            return i - k + 1;
    }
    return -1;
}