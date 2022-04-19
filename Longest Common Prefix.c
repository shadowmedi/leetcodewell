#define _CRT_SECURE_NO_WARNINGS
int minwordnum(char** strs, int strsSize)//�������ַ������ַ�����С���� ���� ����ǰ׺�ĳ��� <= �ַ�����С����
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
       //1 �������
       //˼·��ÿ���������ַ����Ƚϣ��ҳ���������
       if(strsSize == 1)//��ֻ��һ���ַ��������ظ��ַ������ַ��׵�ַ
            return strs[0];
       int minwordnums =minwordnum(strs,strsSize);//�������ַ������ַ�����С���� ���� ����ǰ׺�ĳ��� <= �ַ�����С����
       char* pa = (char*)calloc(minwordnums+1, 1);//���붯̬���飬ע��Ԥ��һ��'\0'
       for(int row = 0; row < strsSize - 1; row++)//��Ϊ��strsSize���ַ�������ôҪ�Ƚϣ�strsSize-1����
       {
           for(int col = 0; col < minwordnums; col++)//�����Ҫ����minwordnums���ַ���
           {
               if(strs[row][col] == strs[row+1][col])//�������ַ�����Ӧλ�õ��ַ���ͬ����¼��pa��
               {
                   pa[col] = strs[row][col];
               }

               else                      //һ�������ַ�����Ӧλ�õ��ַ���ͬ����ʱ����ǰ׺�ĳ��Ȼ���
               {
                   pa[col] = '\0';      //��pa�����λ�øĳ�'\0'
                   minwordnums = col;   //ͬʱ�´ε��ַ����Ƚ� ���ܱȽϵ�����ַ������԰�Ҫ���յ��ַ���Ŀ�ĳ��ַ���ǰ�±�(�±��0��ʼ)
                   break;
               }
           }
       }
       if(strlen(pa) > 0)
            return pa;//���ڹ������ַ���
       else
            return "";//�����ڹ�������
}*/
char* longestCommonPrefix(char** strs, int strsSize)
{
    //2 �������
    //˼·��ͬʱ�Ƚ������ַ�����Ӧλ�õ��ַ����ҳ���������
    if (strsSize == 1)
        return strs[0];
    int minwordnums = minwordnum(strs, strsSize);
    char* pa = (char*)calloc(minwordnums + 1, 1);
    for (int col = 0; col < minwordnums; col++)//һ���ַ�����Ҫ�Ƚϵ��ַ���
    {
        char tem = strs[0][col];              //��¼��һ���ַ����Ķ�Ӧ�������ַ�
        for (int row = 1; row < strsSize; row++)//һһ�ȶԣ������ַ����Ķ�Ӧ�������ַ����� ����һ���ַ����Ķ�Ӧ�������ַ��� 
        {
            if (tem != strs[row][col])//ֻҪ��һ���ַ�����Ӧ�������ַ���һ��
            {
                tem = '\0';          //���ַ����ǹ����ַ�
                minwordnums = col;   //����ǰ׺�ĳ��ȸı�,ͬʱһ���ַ���Ҫ�Ƚϵ��ַ���Ҳ��ı�
                break;
            }
        }
        pa[col] = tem;//��tem���ǹ����ַ������λ����Ϊ'\0'
    }
    return pa;
}