#define _CRT_SECURE_NO_WARNINGS
//˼·1������1�����飬�жϱ������������Ƿ��֮ǰ����������ͬ������ͬ��Ѹ����ֺ��������������ǰŲһλ��
//�Ը��ǵ�ǰ���֣�ͬʱҪ���ص�������Ŀ-1
/*int removeElement(int* nums, int numsSize, int val)
{
    for(int i = 0; i < numsSize; )//Ҫ����������Ԫ��һ����ҪԭnumsSize��
    {
        if(val == nums[i])
        {
            for(int k = i; k < numsSize-1; k++)
            {
                nums[k] = nums[k+1];
            }
            numsSize--;
            //���Ǹ��±��ֵ֮�󣬴�ʱi������һ��Ԫ�ص��±꣬����i����++,��numsSize--ʹ���������ָ���һ������� ��numsSize��
        }
        else
        {
            i++;
        }
    }
    return numsSize;
}*/

//˼·2��˫�±�/˫ָ��
//����2���±꣺1�����±긺���ע(�����һ����Ϊvalue��ֵ)��λ�ã�1�����±긺�������������
int removeElement(int* nums, int numsSize, int val)
{
    int slowindex = 0;
    int fastindex = 0;
    int ret = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[fastindex] != val)
        {
            nums[slowindex] = nums[fastindex];
            slowindex++;
            ret++;
        }
        fastindex++;
    }
    return ret;

}