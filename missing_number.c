#define _CRT_SECURE_NO_WARNINGS
void init(int* pa, int num)//��ʼ������Ԫ��ȫ��Ϊ-1
{
    for (int i = 0; i < num; i++)
    {
        *(pa + i) = -1;
    }
}
/*int missingNumber(int* nums, int numsSize)
{
    //˼·1��mallocһ����СΪ(n+1)�����͵����飬��ԭ�����ֵ�ŵ�������Ķ�Ӧ�±�
    �����ֻʣ��һ���±��Ԫ����-1���Ǹ��±����ȱʧ������
    int n = numsSize;
    int* pa = (int*)malloc((n+1)*sizeof(int));//��СΪ(n+1)������
    init(pa, n+1);//��ʼ������Ԫ��Ϊ-1
    //����һ��ԭ����,����ֵ����������Ķ�Ӧ�±���
    for(int i = 0; i < n; i++)
    {
        pa[nums[i]] = nums[i];
    }
    //����һ�������飬�ĸ��±�Ԫ����-1��ȱʧ�����־����Ǹ��±�
    for(int i = 0; i < n+1; i++)
    {
        if(pa[i] == -1)
        {
            return i;
        }
    }
    return -1;
}*/
/*int missingNumber(int* nums, int numsSize)
{
    //˼·2����λ��������
    //mallocһ����СΪ(numsSize+1)�����͵����飬��ʼ��Ϊ0~numsSize
    //����һ��ֵΪ0�ı���x����λ����������������Ԫ�أ����x��ֵ����ȱʧ������
    //0^x= x
    //x^x = 0
    //��λ������㽻����
    int x = 0;
    int n = numsSize;
    int* pa = (int*)malloc((n+1)*sizeof(int));
    for(int i = 0; i < n+1;i++)
    {
        pa[i] = i;
    }
    for(int i = 0;i < n;i++)
    {
        x ^= nums[i];
    }
    for(int i = 0;i < n+1;i++)
    {
        x ^= pa[i];
    }
    return x;
}*/
int missingNumber(int* nums, int numsSize)
{
    //˼·3����ѧ����
    //��Ϊֻȱһ������
    //(0+1+����+numsSize)-(nums������Ԫ��֮��)=ȱʧ������
    int sum = 0;
    for (int i = 1; i <= numsSize; i++)
    {
        sum += i;
    }
    for (int i = 0; i < numsSize; i++)
    {
        sum -= nums[i];
    }
    return sum;
}