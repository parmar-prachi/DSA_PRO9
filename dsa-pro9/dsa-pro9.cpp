#include <iostream>
using namespace std;

// Base class 

class StackBase
{
public:
    virtual void push(int value) = 0;
    virtual void pop() = 0;
    virtual void top() = 0;
    virtual void isEmpty() = 0;
    virtual void isFull() = 0;
};

// Derived class

class Stack : public StackBase
{
private:
    int *arr;    
    int capacity; 
    int topIndex;

public:
    // Constructor 

    Stack(int size)
    {
        capacity = size;
        arr = new int[capacity];
        topIndex = -1;
    }

    // Push element

    void push(int value)
    {
        if (topIndex == capacity - 1)
        {
            cout << "Stack is full! Cannot push." << endl;
        }
        else
        {
            arr[++topIndex] = value;
            cout << value << " pushed into stack." << endl;
        }
    }

    // Pop element

    void pop()
    {
        if (topIndex == -1)
        {
            cout << "Stack is empty! Nothing to pop." << endl;
        }
        else
        {
            cout << arr[topIndex--] << " popped from stack." << endl;
        }
    }

    // Display top element

    void top()
    {
        if (topIndex == -1)
        {
            cout << "Stack is empty!" << endl;
        }
        else
        {
            cout << "Top element is: " << arr[topIndex] << endl;
        }
    }

    // Check if empty

    void isEmpty()
    {
        if (topIndex == -1)
            cout << "Stack is empty." << endl;
        else
            cout << "Stack is not empty." << endl;
    }

    // Check if full

    void isFull()
    {
        if (topIndex == capacity - 1)
            cout << "Stack is full." << endl;
        else
            cout << "Stack is not full." << endl;
    }

    // Destructor (to free memory)

    ~Stack()
    {
        delete[] arr;
    }
};

// Main function

int main()
{
    int size;
    cout << "Enter stack size: ";
    cin >> size;

    Stack s(size); 

    int choice, value;
    do
    {
        cout << "\n--- Stack Menu ---" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Display Top" << endl;
        cout << "4. Check if Empty" << endl;
        cout << "5. Check if Full" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            s.push(value);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            s.top();
            break;
        case 4:
            s.isEmpty();
            break;
        case 5:
            s.isFull();
            break;
        case 6:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 6);

    return 0;
}
