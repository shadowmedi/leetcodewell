#define _CRT_SECURE_NO_WARNINGS
/*int removeDuplicates(int* nums, int numsSize)
{
    int index1 = 0;//����˫�±걩��ö��
    int index2 = 0;
    for(index1 = 0;index1 < numsSize - 1; index1++)
    {
        //��һ���±�����ָ��ǰnumsSize-1����
        for(index2 = index1+1; index2 < numsSize; )
        {
            //�ڶ����±���ʼָ���ڵ�һ���±����
            if(nums[index1]==nums[index2])//�������±�ָ���������ͬ���ǾͰ�index2�±���������ǰŲ1��
            {
                for(int i = index2; i < numsSize-1; i++)
                {
                    nums[i] = nums[i+1];
                }
                numsSize--;//Ȼ�������һ������
            }//ע��index2��ʱ��Ȼû�䣬����ָ���Ԫ�ر��ˣ����Բ�Ҫ��index2������
            else
            {
                index2++;
            }
        }
    }
    return numsSize;
}*/
int removeDuplicates(int* nums, int sumsSize)
{
    if (sumsSize == 1)
    {
        return 1;
    }
    int index1 = 1;//���������һ�����ظ�����(��ָ��)
    int index2 = 1;//����������������(��ָ��)
    int ret = 1;
    for (int i = 1; i < sumsSize; i++)
    {
        if (nums[index2 - 1] != nums[index2])
        {
            nums[index1] = nums[index2];
            index1++;
            ret++;
        }
        index2++;
    }
    return ret;

}