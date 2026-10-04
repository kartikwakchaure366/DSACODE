#include <iostream>
using namespace std;

#define MAX 5

class Stack
{
    int stack[MAX];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    void push()
    {
        if (top == MAX - 1)
        {
            cout << "Stack Overflow" << endl;
        }
        else
        {
            int parcel;
            cout << "Enter Parcel ID: ";
            cin >> parcel;

            top++;
            stack[top] = parcel;

            cout << "Parcel Added Successfully" << endl;
        }
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow" << endl;
        }
        else
        {
            cout << "Delivered Parcel ID: " << stack[top] << endl;
            top--;
        }
    }

    void display()
    {
        if (top == -1)
        {
            cout << "No Parcels" << endl;
        }
        else
        {
            cout << "Parcels in Stack:" << endl;

            for (int i = top; i >= 0; i--)
            {
                cout << stack[i] << endl;
            }
        }
    }
};

int main()
{
    Stack s;
    int choice;

    do
    {
        cout << "\n1. Push Parcel";
        cout << "\n2. Pop Parcel";
        cout << "\n3. Display";
        cout << "\n4. Exit";

        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            s.push();
            break;

        case 2:
            s.pop();
            break;

        case 3:
            s.display();
            break;

        case 4:
            cout << "Program End" << endl;
            break;

        default:
            cout << "Invalid Choice" << endl;
        }

    } while (choice != 4);

    return 0;
}
