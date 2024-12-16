#include <iostream>
using namespace std;

bool isValidString(const char *str)
{
    // Check if the string is empty
    if (str[0] == '\0')
    {
        return false;
    }

    for (int i = 0; str[i] != '\0'; i++)
    {
        // Check if the character is not in the range of A-Z or a-z
        if (!((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122)))
        {
            return false;
        }
    }
    return true;
}

int main()
{
    const char *name = "Anil";

    if (isValidString(name))
    {
        cout << name << " is a valid string." << endl;
    }
    else
    {
        cout << name << " is not a valid string." << endl;
    }

    const char *invalidName = "Anil321";
    if (isValidString(invalidName))
    {
        cout << invalidName << " is a valid string." << endl;
    }
    else
    {
        cout << invalidName << " is not a valid string." << endl;
    }

    return 0;
}
