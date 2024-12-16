#include <iostream>
#include <cctype>
using namespace std;

int main()
{
    char *name = "Anil321";
    int vowels = 0, words = 0;

    // Count vowels and words
    for (int i = 0; name[i] != '\0'; i++)
    {
        // Check for vowels
        if (name[i] == 'A' || name[i] == 'E' || name[i] == 'I' ||
            name[i] == 'O' || name[i] == 'U' || name[i] == 'a' ||
            name[i] == 'e' || name[i] == 'i' || name[i] == 'o' ||
            name[i] == 'u')
        {
            vowels++;
        }
        // Check for words (assuming words are separated by spaces)
        if (i == 0 || (name[i - 1] == ' ' && name[i] != ' '))
        {
            words++;
        }
    }

    printf("Vowels: %d\n", vowels);
    printf("Words: %d\n", words);
    return 0;
}
