#define _CRT_SECURE_NO_WARNINGS

//˼·1
//�����ұ������飬������һ������target����ĸʱ����
/*char nextGreatestLetter(char* letters, int lettersSize, char target)
{
    if(target >= letters[lettersSize-1])
    {
        return letters[0];//���Ŀ��ֵ�����һ����ĸ�󣬷��ص�һ����ĸ
    }
    for(int i = 0; i < lettersSize; i++)
    {
        if(letters[i] > target)
        return letters[i];
    }
    return -1;
}*/

//˼·2
//���ֲ�����letter���ҵ�һ������target����ĸ
char nextGreatestLetter(char* letters, int lettersSize, char target)
{
    if (target >= letters[lettersSize - 1])
    {
        return letters[0];//���Ŀ��ֵ�����һ����ĸ�󣬷��ص�һ����ĸ
    }
    int left = 0;
    int right = lettersSize - 1;
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (letters[mid] > target)        //����м�ֵ����Ŀ��ֵ����һ������target����ĸӦ����mid�±��mid�±�������
            right = mid;
        else if (letters[mid] <= target)//����м�ֵС�ڵ���Ŀ��ֵ����һ������target����ĸӦ����mid�±���Ҳ���
            left = mid + 1;
    }
    return letters[left];
}