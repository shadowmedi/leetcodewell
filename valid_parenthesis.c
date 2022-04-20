#define _CRT_SECURE_NO_WARNINGS

//栈的特点：先入后出，后入先出
char match(char matchcharacter)   //用于匹配左右括号
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
    char* leftParentheses = (char*)calloc(length + 1, 1);//记录按顺序出现的左括号
    int leftnum = 0;                //记录待匹配的左括号数量，同时也是接下来的左括号要记录到的下标位置
    for (int i = 0; i < length; i++)
    {
        //遍历一遍数组
        char ch = match(s[i]);//判断是左括号还是右括号

        if (ch == 0)//如果是左括号
        {
            //说明待匹配的左括号数目增加1,同时记录左括号，记录优先
            leftParentheses[leftnum] = s[i];
            leftnum++;
        }
        else//如果是右括号，立刻与最后出现的左括号进行匹配
        {
            if (leftnum == 0)//若没出现可匹配的左括号，直接false
            {
                return false;
            }
            else if (leftParentheses[--leftnum] != match(s[i]))//若最后出现的左括号不能匹配刚出现的右括号
            {
                return false;
            }
            //注意：如果可以匹配，此时leftnum已经-1
            else
            {
                //匹配成功后，应去掉最后出现的那个左括号
                leftParentheses[leftnum] = '\0';
            }
        }
    }
    if (strlen(leftParentheses) == 0)//最后不存在未匹配的左括号，就返回true
    {
        return true;
    }
    else
        return false;
}