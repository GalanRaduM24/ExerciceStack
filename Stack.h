#include <iostream>
using namespace std;
#define NMAX 10

template<typename T>
class Stack {
private:
    T stackArray[NMAX];
    int topLevel;

public:
    void push(T x)
    {
        if (topLevel >= NMAX - 1)
        {
            cout << "The stack is full: we have already NMAX elements!\n";
            return;
        }
        stackArray[++topLevel] = x;
    }

    int isEmpty()
    {
        return (topLevel < 0);
    }

    T pop()
    {
        if (isEmpty()) {
            cout << "The stack is empty! \n";
            T x = T();
            return x;
        }
        return stackArray[topLevel--];
    }


    Stack()
    { 
        topLevel = -1;
    }

    ~Stack() 
    {
    }
};