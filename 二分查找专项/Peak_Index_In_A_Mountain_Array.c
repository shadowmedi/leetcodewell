#define _CRT_SECURE_NO_WARNINGS
int peakIndexInMountainArray(int* arr, int arrSize)
{
    int left = 0;
    int right = arrSize - 1;
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        //��Ϊ������
        if (arr[mid] > arr[mid + 1])
        {
            //�������£�mid�����Ƿ嶥
            //��С��Χ
            right = mid;
        }
        else if (arr[mid] < arr[mid + 1])
        {
            //�������£�mid�������Ƿ嶥
            //��С��Χ
            left = mid + 1;
        }

    }
    return left;
}