#include <iostream>
using namespace std;

int main()
{
    int arr[5] = {10, 20, 30, 40, 50};
    int key;
    int found = 0;

    cout << "Enter number to search: ";
    cin >> key;

    // Check each element one by one
    for (int i = 0; i < 5; i++)
    {
        if (arr[i] == key)
        {
            cout << "Element found at position " << i + 1;
            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        cout << "Element not found";
    }

    return 0;
}
