#include<iostream>
#include<stdio.h>

using namespace std;
int main()
{
    int B[10]= {2,4,6,8,20};
//declaration and initialization
    int A[5];
    A[0]=12;
    A[1]=20;
    A[2]=25;

    cout<<sizeof(A)<<endl;    //20
    cout<<A[1]<<endl;         //15
    printf("%d\n", A[2]);     //25

    printf("%d\n", A[6]);     //0
    // In online GDB compiler, Accessing A[6] is out of bounds and leads to undefined behavior.
    // It may return a garbage value or cause a crash. (-1303713792)
    for(int i=0; i<10;i++)
    {
        cout<<B[i]<<endl;
    }                //2 4 6 8 20 0 0 0 0 0

    for(int x:A)
    {
        cout<<x<<endl;
    }                //12 20 25 0 0

    return 0;
} // namespace std

