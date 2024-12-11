#include <stdio.h>

// Head and Tail Recursion
void fun(int n)
{
    if (n > 0)
    {
        // printf("%d ", n); // 321 //Head recursion: prints n before the recursive call
        fun(n - 1);
        printf("%d ", n); // 123 // Tail recursion: prints n after the recursive call
    }
}

int main()
{
    fun(3);
    return 0;
}

/*
Step-by-step execution of fun(3):

Initial Call: fun(3)
┌───────────────┐
│   fun(3)      │
│   n = 3      │
│   Calls fun(2)│
└───────────────┘
        │
        ▼
Second Call: fun(2)
┌───────────────┐
│   fun(2)      │
│   n = 2      │
│   Calls fun(1)│
└───────────────┘
        │
        ▼
Third Call: fun(1)
┌───────────────┐
│   fun(1)      │
│   n = 1      │
│   Calls fun(0)│
└───────────────┘
        │
        ▼
Fourth Call: fun(0)
┌───────────────┐
│   fun(0)      │
│   n = 0      │
│   Base case   │
│   reached     │
└───────────────┘
        │
        ▼
Returning to fun(1)
- Prints: 1
┌───────────────┐
│   fun(1)      │
│   Returns to  │
│   fun(2)      │
└───────────────┘
        │
        ▼
Returning to fun(2)
- Prints: 2
┌───────────────┐
│   fun(2)      │
│   Returns to  │
│   fun(3)      │
└───────────────┘
        │
        ▼
Returning to fun(3)
- Prints: 3
┌───────────────┐
│   fun(3)      │
│   Ends the    │
│   program      │
└───────────────┘

Final Output: "1 2 3 "
(Note: If the head recursion print statement is uncommented, the output will be "3 2 1 ")
*/