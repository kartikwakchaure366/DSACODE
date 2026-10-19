
#include <iostream>
#include <string>
#include <limits>
using namespace std;

// Node structure
struct Node
{
    int complaintID;
    string studentName;
    string department;
    string category;
    string description;
    string status;

    Node* next;
};

// Head pointer
Node* head = NULL;

// Function to register a complaint
void addComplaint()
{
    Node* newNode = new Node();

    cout << "\nEnter Complaint ID: ";
    cin >> newNode->complaintID;

    // Check duplicate Complaint ID
    Node* temp = head;

    while (temp != NULL)
    {
        if (temp->complaintID == newNode->complaintID)
        {
            cout << "Complaint ID already exists!\n";
            delete newNode;
            return;
        }

        temp = temp->next;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter Student Name: ";
    getline(cin, newNode->studentName);

    cout << "Enter Department: ";
    getline(cin, newNode->department);

    cout << "Enter Complaint Category: ";
    getline(cin, newNode->category);

    cout << "Enter Complaint Description: ";
    getline(cin, newNode->description);

    newNode->status = "Pending";
    newNode->next = NULL;

    // Insert node into the linked list
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    cout << "\nComplaint registered successfully!\n";
}

// Function to display all complaints
void displayComplaints()
{
    if (head == NULL)
    {
        cout << "\nNo complaints found.\n";
        return;
    }

    Node* temp = head;

    cout << "\n========== ALL COMPLAINTS ==========\n";

    while (temp != NULL)
    {
        cout << "\nComplaint ID    : " << temp->complaintID;
        cout << "\nStudent Name    : " << temp->studentName;
        cout << "\nDepartment      : " << temp->department;
        cout << "\nCategory        : " << temp->category;
        cout << "\nDescription     : " << temp->description;
        cout << "\nStatus          : " << temp->status;
        cout << "\n------------------------------------\n";

        temp = temp->next;
    }
}

// Function to search for a complaint
void searchComplaint()
{
    if (head == NULL)
    {
        cout << "\nNo complaints available.\n";
        return;
    }

    int id;

    cout << "\nEnter Complaint ID to search: ";
    cin >> id;

    Node* temp = head;

    while (temp != NULL)
    {
        if (temp->complaintID == id)
        {
            cout << "\n========== COMPLAINT FOUND ==========\n";
            cout << "Complaint ID    : " << temp->complaintID << endl;
            cout << "Student Name    : " << temp->studentName << endl;
            cout << "Department      : " << temp->department << endl;
            cout << "Category        : " << temp->category << endl;
            cout << "Description     : " << temp->description << endl;
            cout << "Status          : " << temp->status << endl;

            return;
        }

        temp = temp->next;
    }

    cout << "\nComplaint not found!\n";
}

// Function to update a complaint
void updateComplaint()
{
    if (head == NULL)
    {
        cout << "\nNo complaints available.\n";
        return;
    }

    int id;

    cout << "\nEnter Complaint ID to update: ";
    cin >> id;

    Node* temp = head;

    while (temp != NULL)
    {
        if (temp->complaintID == id)
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "\nEnter New Student Name: ";
            getline(cin, temp->studentName);

            cout << "Enter New Department: ";
            getline(cin, temp->department);

            cout << "Enter New Category: ";
            getline(cin, temp->category);

            cout << "Enter New Description: ";
            getline(cin, temp->description);

            cout << "\nComplaint updated successfully!\n";
            return;
        }

        temp = temp->next;
    }

    cout << "\nComplaint not found!\n";
}

// Function to resolve a complaint
void resolveComplaint()
{
    if (head == NULL)
    {
        cout << "\nNo complaints available.\n";
        return;
    }

    int id;

    cout << "\nEnter Complaint ID to resolve: ";
    cin >> id;

    Node* temp = head;

    while (temp != NULL)
    {
        if (temp->complaintID == id)
        {
            temp->status = "Resolved";

            cout << "\nComplaint marked as Resolved!\n";
            return;
        }

        temp = temp->next;
    }

    cout << "\nComplaint not found!\n";
}

// Function to delete a complaint
void deleteComplaint()
{
    if (head == NULL)
    {
        cout << "\nNo complaints available.\n";
        return;
    }

    int id;

    cout << "\nEnter Complaint ID to delete: ";
    cin >> id;

    Node* temp = head;
    Node* previous = NULL;

    // If the first node has the required ID
    if (head->complaintID == id)
    {
        head = head->next;
        delete temp;

        cout << "\nComplaint deleted successfully!\n";
        return;
    }

    // Search for the required node
    while (temp != NULL && temp->complaintID != id)
    {
        previous = temp;
        temp = temp->next;
    }

    // Complaint not found
    if (temp == NULL)
    {
        cout << "\nComplaint not found!\n";
        return;
    }

    // Remove the node
    previous->next = temp->next;
    delete temp;

    cout << "\nComplaint deleted successfully!\n";
}

// Function to count complaints
void countComplaints()
{
    int pending = 0;
    int resolved = 0;

    Node* temp = head;

    while (temp != NULL)
    {
        if (temp->status == "Pending")
            pending++;
        else if (temp->status == "Resolved")
            resolved++;

        temp = temp->next;
    }

    cout << "\n========== COMPLAINT SUMMARY ==========\n";
    cout << "Pending Complaints  : " << pending << endl;
    cout << "Resolved Complaints : " << resolved << endl;
    cout << "Total Complaints    : " << pending + resolved << endl;
}

// Function to free allocated memory
void freeMemory()
{
    Node* temp;

    while (head != NULL)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
}

// Main function
int main()
{
    int choice;

    do
    {
        cout << "\n========================================\n";
        cout << "   COLLEGE COMPLAINT TRACKING SYSTEM\n";
        cout << "========================================\n";
        cout << "1. Register Complaint\n";
        cout << "2. Display All Complaints\n";
        cout << "3. Search Complaint\n";
        cout << "4. Update Complaint\n";
        cout << "5. Resolve Complaint\n";
        cout << "6. Delete Complaint\n";
        cout << "7. Complaint Summary\n";
        cout << "8. Exit\n";
        cout << "========================================\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                addComplaint();
                break;

            case 2:
                displayComplaints();
                break;

            case 3:
                searchComplaint();
                break;

            case 4:
                updateComplaint();
                break;

            case 5:
                resolveComplaint();
                break;

            case 6:
                deleteComplaint();
                break;

            case 7:
                countComplaints();
                break;

            case 8:
                freeMemory();
                cout << "\nThank you for using the system!\n";
                break;

            default:
                cout << "\nInvalid choice! Please try again.\n";
        }

    } while (choice != 8);

    return 0;
}
