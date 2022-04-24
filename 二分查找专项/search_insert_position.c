<<<<<<< HEAD
#define _CRT_SECURE_NO_WARNINGS
int searchInsert(int* nums, int numsSize, int target)
{
    //如果目标值不存在，则返回第一个>=target的值的下标
    if (nums[numsSize - 1] < target)
    {
        return numsSize;
    }
    int left = 0;
    int right = numsSize - 1;
    while (left < right)//搜索区间一开始是[0, numsSize-1]
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] > target)//若mid下标指的值大于target,此时的mid有可能是第一个>target的下标，而mid后面的数全部排除
        {
            right = mid;
        }
        else if (nums[mid] < target)//若mid下标指的指小于target,包含mid前面的所有数都不可能>=target,所以mid(包含mid)前的数全部舍弃
        {
            left = mid + 1;
        }
        else
        {
            return mid;
        }
    }
    return left;

=======
#define _CRT_SECURE_NO_WARNINGS
int searchInsert(int* nums, int numsSize, int target)
{
    //二分查找
    int left = 0;
    int right = numsSize - 1;
    int mid = left + (right - left) / 2;
    while (left <= right)
    {

        if (nums[mid] == target)
            return mid;
        else if (nums[mid] > target)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
        mid = left + (right - left) / 2;
    }
    return mid;

>>>>>>> 098351dd52633bb3bc2fb2d0480a43cc16ae4b95
}