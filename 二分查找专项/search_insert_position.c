#define _CRT_SECURE_NO_WARNINGS
int searchInsert(int* nums, int numsSize, int target)
{
    //���Ŀ��ֵ�����ڣ��򷵻ص�һ��>=target��ֵ���±�
    if (nums[numsSize - 1] < target)
    {
        return numsSize;
    }
    int left = 0;
    int right = numsSize - 1;
    while (left < right)//��������һ��ʼ��[0, numsSize-1]
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] > target)//��mid�±�ָ��ֵ����target,��ʱ��mid�п����ǵ�һ��>target���±꣬��mid�������ȫ���ų�
        {
            right = mid;
        }
        else if (nums[mid] < target)//��mid�±�ָ��ָС��target,����midǰ�����������������>=target,����mid(����mid)ǰ����ȫ������
        {
            left = mid + 1;
        }
        else
        {
            return mid;
        }
    }
    return left;

}