#define _CRT_SECURE_NO_WARNINGS


//方法一：遍历 1 ~ x/2的所有数，满足条件返回
/*int mySqrt(int x)
{
    if(x == 0 || x == 1)//特殊情况
    return x;
    for(long long i = 1; i <= x/2; i++)
    {
        if(i*i == x)
        return i;
        else if(i*i < x && (i+1)*(i+1) > x)//说明x的算术平方根存在小数部分
        return i;
    }
    return -1;  //凑合用的
}*/
int mySqrt(int x)
{
    if (x == 0 || x == 1)
        return x;
    int left = 1;
    int right = x / 2;//初始搜索区间[1, x/2]     
    while (left < right)
    {
        long long mid = left + (right - left) / 2;//防止越界         
        if (mid * mid == x || (mid * mid<x && (mid + 1) * (mid + 1)>x))
            return mid;//如果x的算术平方根是整数 或 存在小数部分
        else if (mid * mid < x)
            left = mid + 1; //说明x的算术平方根一定在mid右侧,因为mid+1一定小于等于x            
        else if (mid * mid > x)
            right = mid - 1;    //说明x的算术平方根一定在mid左侧
    }
    return left;
}