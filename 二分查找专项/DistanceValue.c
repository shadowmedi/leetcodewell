#define _CRT_SECURE_NO_WARNINGS
/*int findTheDistanceValue(int* arr1, int arr1Size, int* arr2, int arr2Size, int d)
{
    int ret = 0;
    for(int i = 0; i < arr1Size; i++)
    {
        int ass = 1;
        for(int k = 0; k < arr2Size; k++)
        {
            if(fabs(arr1[i] - arr2[k]) <= d)
            {
                ass = 0;
                break;
            }
        }
        ret += ass;
    }
    return ret;
}*/

int cmp(const void* elem1, const void* elem2)
{
    return *(int*)elem1 > *(int*)elem2;
}
int findTheDistanceValue(int* arr1, int arr1Size, int* arr2, int arr2Size, int d)
{
    qsort(arr2, arr2Size, sizeof(int), cmp);
    int ret = 0;
    for (int i = 0; i < arr1Size; i++)
    {
        int left = 0;
        int right = arr2Size - 1;
        int key = arr1[i];
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (arr2[mid] <= key + d && arr2[mid] >= key - d)
                break;
            else if (arr2[mid] > d + key)
                right = mid - 1;
            else if (arr2[mid] < key - d)
                left = mid + 1;
        }
        if (left > right)
            ret++;
    }
    return ret;
}
