#define _CRT_SECURE_NO_WARNINGS
int singleNumber(int* nums, int numsSize)
{
    //˼·1����������ҵ���
    //0 ^ n = n
    //n ^ n = 0
    int num = 0;
    int length = numsSize;
    for (int i = 0; i < length; i++)
    {
        num ^= nums[i];
    }
    return num;
}