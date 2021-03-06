<<<<<<< HEAD
#define _CRT_SECURE_NO_WARNINGS
/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

int guessNumber(int n)
{
    int left = 1;
    int right = n;
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (guess(mid) > 0)
            left = mid + 1;
        else if (guess(mid) < 0)
            right = mid - 1;
        else if (guess(mid) == 0)
            return mid;
    }
    return left;

=======
#define _CRT_SECURE_NO_WARNINGS
/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

int guessNumber(int n)
{
    int left = 1;
    int right = n;
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (guess(mid) > 0)
            left = mid + 1;
        else if (guess(mid) < 0)
            right = mid - 1;
        else if (guess(mid) == 0)
            return mid;
    }
    return left;

>>>>>>> 098351dd52633bb3bc2fb2d0480a43cc16ae4b95
}