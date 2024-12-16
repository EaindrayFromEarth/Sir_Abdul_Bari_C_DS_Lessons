#include <iostream>
#include <cstring>
using namespace std;

// Function to reverse a string
void reverseString(const char *str, char *reversed)
{
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        reversed[i] = str[len - i - 1]; // Copy characters in reverse order
    }
    reversed[len] = '\0'; // Null-terminate the reversed string
}

int main()
{
    char str[100];
    char reversed[100];

    cout << "Enter a string: ";
    cin.getline(str, 100);

    reverseString(str, reversed);

    if (strcmp(str, reversed) == 0)
    {
        cout << "\"" << str << "\" is a palindrome." << endl;
    }
    else
    {
        cout << "\"" << str << "\" is not a palindrome." << endl;
    }

    return 0;
}

// Enter a string: racecar
// "racecar" is a palindrome.
