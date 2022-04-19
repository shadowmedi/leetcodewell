#define _CRT_SECURE_NO_WARNINGS
int minwordnum(char** strs, int strsSize)//求所有字符串的字符串最小长度 —— 公共前缀的长度 <= 字符串最小长度
{
    int min = INT_MAX;
    for (int i = 0; i < strsSize; i++)
    {
        min = (strlen(strs[i]) < min ? strlen(strs[i]) : min);
    }
    return min;
}

/*char * longestCommonPrefix(char ** strs, int strsSize)
{
       //1 横向查找
       //思路：每两个相邻字符串比较，找出公共部分
       if(strsSize == 1)//若只有一个字符串，返回该字符串首字符首地址
            return strs[0];
       int minwordnums =minwordnum(strs,strsSize);//求所有字符串的字符串最小长度 —— 公共前缀的长度 <= 字符串最小长度
       char* pa = (char*)calloc(minwordnums+1, 1);//申请动态数组，注意预留一个'\0'
       for(int row = 0; row < strsSize - 1; row++)//因为有strsSize个字符串，那么要比较（strsSize-1）次
       {
           for(int col = 0; col < minwordnums; col++)//起初需要对照minwordnums个字符，
           {
               if(strs[row][col] == strs[row+1][col])//若两个字符串对应位置的字符相同，记录到pa中
               {
                   pa[col] = strs[row][col];
               }

               else                      //一旦两个字符串对应位置的字符不同，此时公共前缀的长度会变短
               {
                   pa[col] = '\0';      //将pa的这个位置改成'\0'
                   minwordnums = col;   //同时下次的字符串比较 不能比较到这个字符，所以把要对照的字符数目改成字符当前下标(下标从0开始)
                   break;
               }
           }
       }
       if(strlen(pa) > 0)
            return pa;//存在公共部分返回
       else
            return "";//不存在公共部分
}*/
char* longestCommonPrefix(char** strs, int strsSize)
{
    //2 纵向查找
    //思路：同时比较所有字符串对应位置的字符，找出公共部分
    if (strsSize == 1)
        return strs[0];
    int minwordnums = minwordnum(strs, strsSize);
    char* pa = (char*)calloc(minwordnums + 1, 1);
    for (int col = 0; col < minwordnums; col++)//一个字符串中要比较的字符数
    {
        char tem = strs[0][col];              //记录第一个字符串的对应列数的字符
        for (int row = 1; row < strsSize; row++)//一一比对（后面字符串的对应列数的字符）和 （第一个字符串的对应列数的字符） 
        {
            if (tem != strs[row][col])//只要有一个字符串对应列数的字符不一样
            {
                tem = '\0';          //该字符不是公共字符
                minwordnums = col;   //公共前缀的长度改变,同时一个字符串要比较的字符数也会改变
                break;
            }
        }
        pa[col] = tem;//若tem不是公共字符，这个位置置为'\0'
    }
    return pa;
}