#include<iostream>
#include<stack>
using namespace std;

{
    
} // namespace std;


template<typename T>
class Queue{
    public:
    Queue(stack<T> s1, stack<T> s2);
    ~Queue(){};

    T DeleteHead();
    void AddTail(const T& data);

    private:
    stack<T> stack1;
    stack<T> stack2;
};

template<typename T>
Queue::Queue(stack<T> s1, stack<T> s2) : stack1(s1), stack2(s2){
    if(stack2.size() == 0){
        while(stack1.size() > 0){
            T tmp = stack1.top();
            stack1.pop();
            stack2.push(tmp);
        }
    }
}

template<typename T>
T Queue::DeleteHead(){
    if (stack2.size() != 0){
        T res = stack2.top();
        stack2.pop();  
        }   
    return res;
}

template<typename T>
void Queue::AddTail(const T& data){
    stack1.push(data);
}
    

