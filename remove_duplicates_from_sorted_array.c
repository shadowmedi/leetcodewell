#define _CRT_SECURE_NO_WARNINGS
/*int removeDuplicates(int* nums, int numsSize)
{
    int index1 = 0;//定义双下标暴力枚举
    int index2 = 0;
    for(index1 = 0;index1 < numsSize - 1; index1++)
    {
        //第一个下标依次指向前numsSize-1个数
        for(index2 = index1+1; index2 < numsSize; )
        {
            //第二个下标起始指向在第一个下标后面
            if(nums[index1]==nums[index2])//若两个下标指向的数字相同，那就把index2下标后面的数往前挪1格
            {
                for(int i = index2; i < numsSize-1; i++)
                {
                    nums[i] = nums[i+1];
                }
                numsSize--;//然后丢弃最后一个数字
            }//注意index2此时虽然没变，但是指向的元素变了，所以不要把index2往后移
            else
            {
                index2++;
            }
        }
    }
    return numsSize;
}*/
int removeDuplicates(int* nums, int sumsSize)
{
    if (sumsSize == 1)
    {
        return 1;
    }
    int index1 = 1;//用来存放下一个不重复的数(慢指针)
    int index2 = 1;//用来遍历整个数组(快指针)
    int ret = 1;
    for (int i = 1; i < sumsSize; i++)
    {
        if (nums[index2 - 1] != nums[index2])
        {
            nums[index1] = nums[index2];
            index1++;
            ret++;
        }
        index2++;
    }
    return ret;

}