#define _CRT_SECURE_NO_WARNINGS


//����һ������ 1 ~ x/2����������������������
/*int mySqrt(int x)
{
    if(x == 0 || x == 1)//�������
    return x;
    for(long long i = 1; i <= x/2; i++)
    {
        if(i*i == x)
        return i;
        else if(i*i < x && (i+1)*(i+1) > x)//˵��x������ƽ��������С������
        return i;
    }
    return -1;  //�պ��õ�
}*/
int mySqrt(int x)
{
    if (x == 0 || x == 1)
        return x;
    int left = 1;
    int right = x / 2;//��ʼ��������[1, x/2]     
    while (left < right)
    {
        long long mid = left + (right - left) / 2;//��ֹԽ��         
        if (mid * mid == x || (mid * mid<x && (mid + 1) * (mid + 1)>x))
            return mid;//���x������ƽ���������� �� ����С������
        else if (mid * mid < x)
            left = mid + 1; //˵��x������ƽ����һ����mid�Ҳ�,��Ϊmid+1һ��С�ڵ���x            
        else if (mid * mid > x)
            right = mid - 1;    //˵��x������ƽ����һ����mid���
    }
    return left;
}