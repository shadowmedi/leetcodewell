#define _CRT_SECURE_NO_WARNINGS
char* reverse(char* pa)//��תһ���ַ���
{
    assert(pa);
    int left = 0;
    int right = strlen(pa) - 1;//����˫�±꣬ʹ�����±�ָ���Ԫ�ػ���
    while (left < right)
    {
        char tem = pa[left];
        pa[left] = pa[right];
        pa[right] = tem;
        left++;
        right--;
    }
    return pa;
}
/*bool isPalindrome(int x)
{
    //1 �ַ�������(����)
    char arr[100] = { 0 };
    sprintf(arr, "%d", x);//������xתΪ�ַ������������ַ�������
    char temp[100] = { 0 };
    strcpy(temp, arr);
    reverse(temp);
    if(strcmp(temp, arr)== 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}*/
/*bool isPalindrome(int x)
{
    //2 �ַ�������(����)
    //ֻ�����ַ�����벿�ֵ�����
    //�Ƚ��ַ�����벿����ǰ�벿��
    //���ٵĿռ��С
    char arr[100] = { 0 };
    sprintf(arr, "%d", x);
    int length = strlen(arr);
    if(length % 2 == 0)
    {
        char *begin = arr+length/2;
        reverse(begin);
        for(int i = 0; i < length/2; i++)
        {
            if(arr[i] != arr[i+length/2])
            {
                return false;
            }
        }
        return true;
    }
    else
    {
        char* begin = arr+length/2+1;
        reverse(begin);
        for(int i = 0; i < length/2;i++)
        {
            if(arr[i] != arr[i+length/2+1])
            {
                return false;
            }
        }
        return true;
    }
}*/
bool isPalindrome(int x)
{
    //3 �������ֲ�ʹ���ַ���
    //Ϊ��ֹ�����������ֳ���INT_MAX,����ֻ�������ֵĺ�һ��
    if (x < 0)
    {
        return false;
    }
    int sum = 0;
    int tem = x;
    int n = 0;//����λ��
    while (tem)//��������ж���λ
    {
        n++;
        tem /= 10;
    }
    for (int i = 0; i < n / 2; i++)
    {
        sum = sum * 10 + x % 10;
        x /= 10;
    }//sumȡ�����ֺ�벿�ֵ�������
    if (n % 2 != 0)//���������λ����x�����Գ�10����ȡ�����ֵ�ǰ�벿��
    {
        x /= 10;
    }
    if (x == sum)
        return true;
    return false;

}
