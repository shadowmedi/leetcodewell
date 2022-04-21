#define _CRT_SECURE_NO_WARNINGS
//思路1：遍历1遍数组，判断遍历到的数字是否和之前遍历的数相同，若相同则把该数字后面的所有数字往前挪一位，
//以覆盖当前数字，同时要返回的数字数目-1
/*int removeElement(int* nums, int numsSize, int val)
{
    for(int i = 0; i < numsSize; )//要遍历完所有元素一定需要原numsSize次
    {
        if(val == nums[i])
        {
            for(int k = i; k < numsSize-1; k++)
            {
                nums[k] = nums[k+1];
            }
            numsSize--;
            //覆盖该下标的值之后，此时i将是下一个元素的下标，所以i不能++,但numsSize--使遍历的数字个数一定是起初 的numsSize个
        }
        else
        {
            i++;
        }
    }
    return numsSize;
}*/

//思路2：双下标/双指针
//定义2个下标：1个慢下标负责标注(存放下一个不为value的值)的位置；1个快下标负责遍历整个数组
int removeElement(int* nums, int numsSize, int val)
{
    int slowindex = 0;
    int fastindex = 0;
    int ret = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[fastindex] != val)
        {
            nums[slowindex] = nums[fastindex];
            slowindex++;
            ret++;
        }
        fastindex++;
    }
    return ret;

}