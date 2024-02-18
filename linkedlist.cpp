#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

struct node *createLl()
{
    struct node *head = NULL;
    int n;
    cout << "Enter the Number of nodes that you want to insert: ";
    cin >> n;
    struct node *current = NULL;
    for (int i = 0; i < n; i++)
    {
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        cout << "Enter the data: ";
        cin >> newNode->data;
        newNode->next = NULL;
        if (head == NULL)
        {
            head = newNode;
            current = newNode;
        }
        else
        {
            current->next = newNode;
            current = current->next;
        }
    }
    return head;
}

void insertNodeFirst(struct node *&head)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    cout << "Enter the data: ";
    cin >> newNode->data;
    newNode->next = head;
    head = newNode;
}

void insertNodeLast(struct node *&head)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    cout << "Enter the data: ";
    cin >> newNode->data;
    newNode->next = NULL;
    struct node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = newNode;
}

void insertNodePos(struct node *&head)
{
    int pos;
    cout << "Enter the position at which you want to insert node: ";
    cin >> pos;
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    cout << "Enter the data: ";
    cin >> newNode->data;
    struct node *current = head;
    for (int i = 1; i < pos - 1; i++)
    {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
}

void displayList(struct node *head)
{
    struct node *iter = head;
    cout << "[ ";
    while (iter != NULL)
    {
        cout << iter->data << " , ";
        iter = iter->next;
    }
    cout << "]" << endl;
}

void deleteNodeFirst(struct node *&head)
{
    head = head->next;
}

void deleteNodeLast(struct node *&head)
{
    struct node *current = head;
    while (current->next->next != NULL)
    {
        current = current->next;
    }
    current->next = NULL;
}

void deleteNodePos(struct node *&head)
{
    int pos;
    cout << "Enter the position from which you want to delete the node: ";
    cin >> pos;
    struct node *current = head;
    for (int i = 1; i < pos - 1; i++)
    {
        current = current->next;
    }
    current->next = current->next->next;
}

void updateNodeFirst(struct node *&head)
{
    cout << "Enter the updated data: ";
    cin >> head->data;
}
void updateNodeLast(struct node *&head)
{
    struct node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    cout << "Enter the updated data: ";
    cin >> current->data;
}
void updateNodePos(struct node *&head)
{
    int pos;
    cout << "Enter the postion of the node that you want to update: ";
    cin >> pos;
    struct node *current = head;
    for (int i = 1; i < pos; i++)
    {
        current = current->next;
    }
    cout << "Enter the updated data: ";
    cin >> current->data;
}

void reverse(struct node **head)
{
    struct node *prevNode, *currentNode, *nextNode;
    prevNode = 0;
    currentNode = nextNode = *head;
    while (nextNode != 0)
    {
        nextNode = nextNode->next;
        currentNode->next = prevNode;
        prevNode = currentNode;
        currentNode = nextNode;
    }
    *head = prevNode;
}
void menu()
{
    cout << "\t\tCRUD operations in Linked list" << endl
         << endl;
    cout << "1.Display\n2.Add a node in front\n3.Add a node in back\n4.Add a node at a specified position\n5.Delete a node from front\n6.Delete a node from back\n7.Delete a node from a specified position\n8.Update a node from front\n9.Update a node from back\n10.Update a node from a specified position\n11.Reverse\n12.Exit" << endl;
}

int main()
{
    struct node *head = createLl();
    int choice = 1;
    while (choice != 0)
    {
        menu();
        cout << "Enter choice from above menu: ";
        cin >> choice;
        if (choice == 1)
            displayList(head);
        else if (choice == 2)
        {
            insertNodeFirst(head);
        }
        else if (choice == 3)
        {
            insertNodeLast(head);
        }
        else if (choice == 4)
        {
            insertNodePos(head);
        }
        else if (choice == 5)
        {
            deleteNodeFirst(head);
        }
        else if (choice == 6)
        {
            deleteNodeLast(head);
        }
        else if (choice == 7)
        {
            deleteNodePos(head);
        }
        else if (choice == 8)
        {
            updateNodeFirst(head);
        }
        else if (choice == 9)
        {
            updateNodeLast(head);
        }
        else if (choice == 10)
        {
            updateNodePos(head);
        }
        else if (choice == 11)
        {
            reverse(&head);
        }
        else if (choice == 12)
        {
            cout << "Thank You!" << endl;
            break;
        }
        else
        {
            cout << "Enter valid choice!";
            continue;
        }
    }
}