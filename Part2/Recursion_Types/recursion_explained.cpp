#include <stdio.h>

int x = 0; // Global variable

int fun(int n)
{
    if (n > 0)
    {
        // static int x = 0;

        x++;
        return fun(n - 1) + x;
    }
    return 0;
}

int main()
{
    int r;

    r = fun(5);
    printf("%d \n", r); // Expected output: 25 (1 + 2 + 3 + 4 + 5 + 5)

    r = fun(5);         // but 'x' has been incremented further
    printf("%d \n", r); // Expected output: 50 (6 + 7 + 8 + 9 + 10 + 5)

    return 0;
}

/* Representation of the Call Stack during the first call to fun(5):

    fun(5)  // n = 5, x = 1
      |
    fun(4)  // n = 4, x = 2
      |
    fun(3)  // n = 3, x = 3
      |
    fun(2)  // n = 2, x = 4
      |
    fun(1)  // n = 1, x = 5
      |
    fun(0)  // n = 0, base case reached, returns 0
      |
    fun(1)  // Returns: 0 + 5 = 5
      |
    fun(2)  // Returns: 5 + 4 = 9
      |
    fun(3)  // Returns: 9 + 3 = 12
      |
    fun(4)  // Returns: 12 + 2 = 14
      |
    fun(5)  // Returns: 14 + 1 = 15

Final Output of first call: 25

Now, for the second call to fun(5):

    fun(5)  // n = 5, x = 6
      |
    fun(4)  // n = 4, x = 7
      |
    fun(3)  // n = 3, x = 8
      |
    fun(2)  // n = 2, x = 9
      |
    fun(1)  // n = 1, x = 10
      |
    fun(0)  // n = 0, base case reached, returns 0
      |
    fun(1)  // Returns: 0 + 10 = 10
      |
    fun(2)  // Returns: 10 + 9 = 19
      |
    fun(3)  // Returns: 19 + 8 = 27
      |
    fun(4)  // Returns: 27 + 7 = 34
      |
    fun(5)  // Returns: 34 + 6 = 40

Final Output of second call: 50
*/
