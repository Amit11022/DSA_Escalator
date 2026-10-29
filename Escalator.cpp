#include <iostream>
using namespace std;

// Base class
class StackOperations {
public:
    virtual void push(int value) = 0;
    virtual void pop() = 0;
    virtual void top() = 0;
    virtual bool isEmpty() = 0;
    virtual bool isFull() = 0;

    virtual ~StackOperations() {}
};

// Derived class
class Stack : public StackOperations {
private:
    int arr[5];      // Array to store stack elements
    int topIndex;    // Index of the top element
    int capacity;    // Maximum stack size

public:
    // Constructor
    Stack() {
        topIndex = -1;
        capacity = 5;
    }

    // Push an element
    void push(int value) override {
        if (isFull()) {
            cout << "Stack is full! Cannot push element.\n";
        } else {
            topIndex++;
            arr[topIndex] = value;
            cout << value << " pushed into the stack.\n";
        }
    }

    // Pop an element
    void pop() override {
        if (isEmpty()) {
            cout << "Stack is empty! Cannot pop element.\n";
        } else {
            cout << arr[topIndex] << " popped from the stack.\n";
            topIndex--;
        }
    }

    // Display top element
    void top() override {
        if (isEmpty()) {
            cout << "Stack is empty! No top element.\n";
        } else {
            cout << "Top element: " << arr[topIndex] << endl;
        }
    }

    // Check if stack is empty
    bool isEmpty() override {
        return topIndex == -1;
    }

    // Check if stack is full
    bool isFull() override {
        return topIndex == capacity - 1;
    }
};

int main() {
    // Base-class pointer referring to a derived-class object
    Stack stack;
    StackOperations* ptr = &stack;

    int choice, value;

    do {
        cout << "\n===== STACK MENU =====\n";
        cout << "1. Push Element\n";
        cout << "2. Pop Element\n";
        cout << "3. Display Top Element\n";
        cout << "4. Check if Stack is Empty\n";
        cout << "5. Check if Stack is Full\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                ptr->push(value);
                break;

            case 2:
                ptr->pop();
                break;

            case 3:
                ptr->top();
                break;

            case 4:
                if (ptr->isEmpty()) {
                    cout << "Stack is empty.\n";
                } else {
                    cout << "Stack is not empty.\n";
                }
                break;

            case 5:
                if (ptr->isFull()) {
                    cout << "Stack is full.\n";
                } else {
                    cout << "Stack is not full.\n";
                }
                break;

            case 6:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 6);

    return 0;
}

