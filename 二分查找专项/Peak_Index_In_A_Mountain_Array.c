#define _CRT_SECURE_NO_WARNINGS
int peakIndexInMountainArray(int* arr, int arrSize)
{
    int left = 0;
    int right = arrSize - 1;
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        //分为上下坡
        if (arr[mid] > arr[mid + 1])
        {
            //正在下坡，mid可能是峰顶
            //缩小范围
            right = mid;
        }
        else if (arr[mid] < arr[mid + 1])
        {
            //正在上坡，mid不可能是峰顶
            //缩小范围
            left = mid + 1;
        }

    }
    return left;
}