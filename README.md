#  College Complaint Tracking System

## 1. Introduction

The College Complaint Tracking System is a simple C++ project that helps colleges manage student complaints. Users can register, view, search, update, resolve, and delete complaints. Each complaint contains the student's name, Complaint ID, department, category, description, and status.

## 2. Objectives

- To manage student complaints easily.
- To store complaint details in an organized way.
- To search and update complaints using Complaint ID.
- To track pending and resolved complaints.
- To display the total number of complaints.

## 3. Features

1. Register Complaint: Add a new complaint.
2. Display Complaints: View all complaints.
3. Search Complaint: Find a complaint using its ID.
4. Update Complaint: Change complaint details.
5. Resolve Complaint: Mark a complaint as resolved.
6. Delete Complaint: Remove a complaint.
7. Complaint Summary: Count pending and resolved complaints.
8. Exit: Close the program.

## 4. Technologies Used

- Programming Language: C++
- Data Structure: Singly Linked List
- Concepts: Structures, pointers, functions, loops, and dynamic memory allocation.
- Header Files: `iostream`, `string`, and `limits`.

## 5. Working of the Project

The program displays a menu with different options. The user selects an option to perform an operation. Complaint details are stored in a linked list. Users can manage complaints and check their status. When the program exits, the allocated memory is freed.

## 6. Data Structure Used

The project uses a singly linked list. Each node stores the complaint details and a pointer to the next node. This allows complaint records to be added and deleted dynamically.

## 7. Advantages

- Easy to use.
- Organizes complaints properly.
- Prevents duplicate Complaint IDs.
- Makes searching and updating records simple.
- Shows complaint status and summary.

## 8. Limitations

- Data is lost when the program closes.
- No login system is available.
- The program works only through a console interface.
- Multiple users cannot access the system simultaneously.

## 9. Future Enhancements

In the future, a database can be added to save records permanently. A login system, graphical interface, and notifications can also be included to improve the project.

## 10. Conclusion

The College Complaint Tracking System makes it easier to manage student complaints. It helps users register, search, update, resolve, and delete complaints. This project also helps students understand C++ programming, linked lists, pointers, and memory management.
