#define _CRT_SECURE_NO_WARNINGS
int searchInsert(int* nums, int numsSize, int target)
{
    //¶þ·Ö²éÕÒ
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

}