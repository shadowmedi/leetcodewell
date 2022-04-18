#define _CRT_SECURE_NO_WARNINGS
char* reverse(char* pa)//反转一个字符串
{
    assert(pa);
    int left = 0;
    int right = strlen(pa) - 1;//定义双下标，使两个下标指向的元素互换
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
    //1 字符串逆序(初阶)
    char arr[100] = { 0 };
    sprintf(arr, "%d", x);//将数字x转为字符串，对整个字符串逆序
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
    //2 字符串逆序(进阶)
    //只逆序字符串后半部分的内容
    //比较字符串后半部分与前半部分
    //开辟的空间减小
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
    //3 逆序数字不使用字符串
    //为防止逆序过后的数字超过INT_MAX,考虑只逆序数字的后一半
    if (x < 0)
    {
        return false;
    }
    int sum = 0;
    int tem = x;
    int n = 0;//数字位数
    while (tem)//求该数字有多少位
    {
        n++;
        tem /= 10;
    }
    for (int i = 0; i < n / 2; i++)
    {
        sum = sum * 10 + x % 10;
        x /= 10;
    }//sum取得数字后半部分的逆序数
    if (n % 2 != 0)//如果是奇数位，则x还需自除10才能取得数字的前半部分
    {
        x /= 10;
    }
    if (x == sum)
        return true;
    return false;

}
