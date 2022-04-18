#define _CRT_SECURE_NO_WARNINGS
void init(int* pa, int num)//初始化数组元素全部为-1
{
    for (int i = 0; i < num; i++)
    {
        *(pa + i) = -1;
    }
}
/*int missingNumber(int* nums, int numsSize)
{
    //思路1：malloc一个大小为(n+1)个整型的数组，将原数组的值放到该数组的对应下标
    ，最后只剩下一个下标的元素是-1，那个下标就是缺失的数字
    int n = numsSize;
    int* pa = (int*)malloc((n+1)*sizeof(int));//大小为(n+1)个整型
    init(pa, n+1);//初始化数组元素为-1
    //遍历一遍原数组,它的值放在新数组的对应下标上
    for(int i = 0; i < n; i++)
    {
        pa[nums[i]] = nums[i];
    }
    //遍历一遍新数组，哪个下标元素是-1，缺失的数字就是那个下标
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
    //思路2：按位异或的特性
    //malloc一个大小为(numsSize+1)个整型的数组，初始化为0~numsSize
    //创建一个值为0的变量x，按位异或两个数组的所有元素，最后x的值就是缺失的数字
    //0^x= x
    //x^x = 0
    //按位异或满足交换律
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
    //思路3：数学方法
    //因为只缺一个数字
    //(0+1+……+numsSize)-(nums中所有元素之和)=缺失的数字
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