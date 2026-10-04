#include <iostream>
using namespace std;

void display(int a[])
{
    for (int i = 0; i < 5; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    int a[5] = {252, 23, 34, 110, 9};
    int b[5], c[5], temp;

    // Copy original array
    for (int i = 0; i < 5; i++)
    {
        b[i] = a[i];
        c[i] = a[i];
    }

    
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
            }
        }
    }

    
    for (int i = 0; i < 4; i++)
    {
        int min = i;

        for (int j = i + 1; j < 5; j++)
        {
            if (b[j] < b[min])
            {
                min = j;
            }
        }

        swap(b[i], b[min]);
    }

    
    for (int i = 1; i < 5; i++)
    {
        temp = c[i];
        int j = i - 1;

        while (j >= 0 && c[j] > temp)
        {
            c[j + 1] = c[j];
            j--;
        }

        c[j + 1] = temp;
    }

    
    cout << "\nBubble Sort: ";
    display(a);

    cout << "Selection Sort: ";
    display(b);

    cout << "Insertion Sort: ";
    display(c);

    return 0;
}
