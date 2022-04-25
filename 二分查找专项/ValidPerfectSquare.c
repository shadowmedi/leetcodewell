#define _CRT_SECURE_NO_WARNINGS
bool isPerfectSquare(int num)
{
    if (num == 1)
        return true;

    long left = 1;
    long right = num / 2;
    while (left <= right)
    {
        long long mid = left + (right - left);
        if (mid * mid == num)
            return true;
        else if (mid * mid > num)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return false;
}