#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

int main()
{
    Node *top = NULL;
    int choice, value;

    do
    {
        cout << "\n--- Stack Using Linked List ---";
        cout << "\n1. Push";
        cout << "\n2. Pop";
        cout << "\n3. Display";
        cout << "\n4. Exit";

        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            // Push
            cout << "Enter value: ";
            cin >> value;

            {
                Node *newNode = new Node();

                newNode->data = value;
                newNode->next = top;
                top = newNode;
            }

            cout << "Value Added Successfully";
            break;

        case 2:
            // Pop
            if (top == NULL)
            {
                cout << "Stack Underflow";
            }
            else
            {
                Node *temp = top;

                cout << "Deleted Value: " << top->data;

                top = top->next;

                delete temp;
            }
            break;

        case 3:
            // Display
            if (top == NULL)
            {
                cout << "Stack is Empty";
            }
            else
            {
                Node *temp = top;

                cout << "\nStack Elements:\n";

                while (temp != NULL)
                {
                    cout << temp->data << " ";
                    temp = temp->next;
                }
            }
            break;

        case 4:
            cout << "Program End";
            break;

        default:
            cout << "Invalid Choice";
        }

    } while (choice != 4);

    return 0;
}
