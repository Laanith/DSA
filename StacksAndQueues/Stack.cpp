#include <bits/stdc++.h>
#include <algorithm>
#define ll long long
#define PYES cout << "YES" << endl
#define PNO cout << "NO" << endl
#define PMINUS cout << -1 << endl
#define vi vector<int>
#define vpi vector<pair<int, int>>
#define vs vector<string>
#define qi queue<int>
#define si stack<int>
#define seti set<int>
#define pi pair<int, int>
#define ima INT_MAX
#define imi INT_MIN
#define siz size
#define vvi vector<vector<int>>
#define pb push_back
#include <stdexcept> // For std::overflow_error

using namespace std;
void pv(vi A)
{
    cout << endl;
    for (auto x : A)
        cout << x << ' ';
    cout << endl;
}
void pint(int A) { cout << endl
                        << A << endl; }
void pp(pair<int, int> p) { cout << p.first << ' ' << p.second << endl; }
void pvvi(vvi A)
{
    for (auto v : A)
    {
        pv(v);
    }
}

/*!SECTION : Problem Description ::
Basic Implementation of stack using array
*/

typedef class Stack
{
private:
    int *stack_arr;
    int topIndex;
    int max_size;

public:
    int size = 0;

    Stack(int size) : max_size(size), topIndex(-1)
    {
        stack_arr = new int[max_size];
    }

    ~Stack()
    {
        delete[] stack_arr;
    }

    void push(int value)
    {
        if (topIndex >= max_size - 1)
        {
            throw std::overflow_error("Stack overflow: exceeded max size");
        }
        stack_arr[++topIndex] = value;
        size++;
    }

    int pop()
    {
        if (topIndex < 0)
        {
            throw std::underflow_error("Stack underflow: no elements to pop");
        }
        size--;
        return stack_arr[topIndex--];
    }

    int top()
    {
        return stack_arr[topIndex];
    }

    bool isEmpty() const
    {
        return topIndex == -1;
    }

    bool isFull() const
    {
        return topIndex >= max_size - 1;
    }
} Stack;

class Solution
{
public:
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    Stack S(10);
    for (int i = 0; i < 10; i++)
    {
        S.push(i);
    }

    cout << S.top() << endl;

    cout << S.size << endl;

    try {
    S.push(69);
    }
    catch (const std::overflow_error &e){
        cout<<"Overflow exception caught :: "<<e.what()<<endl;
    }

    cout<<S.pop()<<endl;




    return 0;
}