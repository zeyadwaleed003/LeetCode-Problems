class MinStack {
private:
    stack<int> s1;
    stack<int> s2;
public:
    void push(int x) 
    {
\t    s1.push(x);
\t    if(s2.empty() || x <= getMin())  s2.push(x);\t    
    }
    void pop() 
    {
\t    if (s1.top() == getMin())  s2.pop();
\t    s1.pop();
    }
    int top() 
    {
\t    return s1.top();
    }
    int getMin() {
\t    return s2.top();
    }
};