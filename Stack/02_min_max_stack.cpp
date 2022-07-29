#include<iostream>
#include<vector>
using namespace std;

template<class T>
class minMaxStack
{
    vector<T> stack;
    vector<T> minStack;
    vector<T> maxStack;

    public:
    void push(T data);
    void pop();
    T top();
    bool empty();
    T getMin();
    T getMax();
};

template<class T>
void minMaxStack<T>::push(T data)
{
    T currentMin = data;
    T currentMax = data;

    if(stack.size())
    {
        currentMin = min(data, minStack[minStack.size()-1]);
        currentMax = max(data, maxStack[maxStack.size()-1]);
    }
    stack.push_back(data);
    minStack.push_back(currentMin);
    maxStack.push_back(currentMax);
}

template<class T>
void minMaxStack<T>::pop()
{
    stack.pop_back();
    minStack.pop_back();
    maxStack.pop_back();
}

template<class T>
T minMaxStack<T>::top()
{
    return stack.size() == 0 ? -1 : stack[stack.size()-1];
}

template<class T>
T minMaxStack<T>::getMax()
{
    return maxStack.size() == 0 ? -1 : maxStack[maxStack.size()-1];
}

template<class T>
T minMaxStack<T>::getMin()
{
    return minStack.size() == 0 ? -1 : minStack[minStack.size()-1];
}

template<class T>
bool minMaxStack<T>::empty()
{
    return stack.size() == 0;
}

int main()
{
    minMaxStack<int> s;
    s.push(1);
    s.push(5);
    s.push(3);
    s.push(8);

    cout << s.top() << endl;
    cout << s.empty() << endl;
    cout << s.getMax() << endl;
    cout << s.getMin() << endl;
    s.pop();
    cout << s.top() << endl;
    cout << s.empty() << endl;
    cout << s.getMax() << endl;
    cout << s.getMin() << endl;
    s.pop();
        cout << s.top() << endl;
    cout << s.empty() << endl;
    cout << s.getMax() << endl;
    cout << s.getMin() << endl;
    s.pop();
        cout << s.top() << endl;
    cout << s.empty() << endl;
    cout << s.getMax() << endl;
    cout << s.getMin() << endl;
    s.pop();
        cout << s.top() << endl;
    cout << s.empty() << endl;
    cout << s.getMax() << endl;
    cout << s.getMin() << endl;

}