/*int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
   //1 ������⣬��2��ѭ��ö�����п��ܵ����
   int* pa = (int*)calloc(2,sizeof(int));
   *returnSize = 2;
   int length = numsSize;
   for(int i = 0; i <= length - 2; i++)
   {
       for(int k = i+1; k <= length - 1; k++)
       {
           if(nums[i] + nums[k] == target)
           {
               pa[0] = i;
               pa[1] = k;
               return pa;
           }
       }
   }
    *returnSize = 0;
    return NULL;
}*/
typedef struct hash
{
    int value;//��¼�Ѿ���������ֵ
    int index;//�±�
}hash;

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int num = numsSize;
    hash* list = (hash*)malloc(num * sizeof(hash));
    int* pa = (int*)malloc(sizeof(int) * 2);
    for (int i = 0; i < num; i++)
    {
        //����nums����
        //�����������
        list[i].value = nums[i];
        list[i].index = i;
        for (int k = 0; k < i; k++)//������֮ǰ�ŵ��������ҵ� (�����ڵ�Ԫ��֮��Ϊtarget��ֵ)
        {
            if (nums[i] == target - list[k].value)
            {
                free(list);
                list = NULL;
                *returnSize = 2;
                pa[0] = k;
                pa[1] = i;
                return pa;
            }
        }
    }
    *returnSize = 0;
    free(pa);
    pa = NULL;
    return pa;
}