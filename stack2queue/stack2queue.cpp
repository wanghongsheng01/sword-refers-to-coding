#include<iostream>
#include<queue>
using namespace  std;

template<type T>
class Stack{
    public:
    Stack(queue<T> q1, queue<T> q2);
    ~Stack(){}

    T DeleteHead();
    void AppendTail(const T& data);

    private:
    queue<T> queue1;
    queue<T> queue2;
};

template<typename T>
T Stack::DeleteHead(){
    if(queue2.size() == 0){
        while(queue1.size() != 0){
            T tmp = queue1.top();
            queue1.pop();
            while(queue1.size() != 1){
                queue2.push(tmp);
            }
            T res = tmp;
            return res;
        }

    }
}

template<typename T>
void Stack::AppendTail(const T& data){
    queue1.push(data);
}