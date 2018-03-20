#pragma once

template <typename T>
class Stack
{
private:
    enum {MAX = 100}; 
    T items[MAX];
    int top;
public:
    Stack();
    bool isempty() { return top == 0; }
    bool isfull() { return top == MAX; }    /// MOŻNA METODY DEFINIOWAĆ W KLASIE
    int getSize() { return top; }

    bool push(const T & item);
    inline bool pop(T & item);
};
/////////////////////////////////////////// MOŻNA TEŻ DEFINIOWAĆ POZA KLASĄ


template<typename T>
Stack<T>::Stack() { top = 0; }


template<typename T>
bool Stack<T>::push(const T & item) 
{
    if (top < MAX)
    {
        items[top++] = item;
        return true;
    }
    else
        return false;
}

template<typename T>
bool Stack<T>::pop(T &item)
{
    if (top > 0)
    {
        item = items[--top];
        return true;
    }
    else
        return false;
}

///////////////////////////////////////////