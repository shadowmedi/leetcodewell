#define _CRT_SECURE_NO_WARNINGS

//思路1
//从左到右遍历数组，遇到第一个大于target的字母时返回
/*char nextGreatestLetter(char* letters, int lettersSize, char target)
{
    if(target >= letters[lettersSize-1])
    {
        return letters[0];//如果目标值比最后一个字母大，返回第一个字母
    }
    for(int i = 0; i < lettersSize; i++)
    {
        if(letters[i] > target)
        return letters[i];
    }
    return -1;
}*/

//思路2
//二分查找在letter中找第一个大于target的字母
char nextGreatestLetter(char* letters, int lettersSize, char target)
{
    if (target >= letters[lettersSize - 1])
    {
        return letters[0];//如果目标值比最后一个字母大，返回第一个字母
    }
    int left = 0;
    int right = lettersSize - 1;
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (letters[mid] > target)        //如果中间值大于目标值，第一个大于target的字母应该在mid下标和mid下标的左侧找
            right = mid;
        else if (letters[mid] <= target)//如果中间值小于等于目标值，第一个大于target的字母应该在mid下标的右侧找
            left = mid + 1;
    }
    return letters[left];
}