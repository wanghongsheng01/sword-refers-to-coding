/**
 * 面试题6：从尾到头打印链表
   题目：输入一个链表的头结点，从尾到头反过来打印出每个结点的值。
 */

 #include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using std::vector;
using std::cout;
using std::endl;


struct ListNode{
    public:
        int value;
        ListNode* next;
        ListNode(int val) : value(val), next(nullptr){}
};


ListNode* CreateList(vector<int>& vec){
    ListNode* pHead = new ListNode(vec.at(0));
            ListNode* pTail = pHead;
            for(int i = 1; i<vec.size(); i++){
                ListNode* pNode = new ListNode(vec.at(i));
                pTail->next = pNode;
                pTail = pNode;
            }
            return pHead;
}

void PrintList(ListNode* pHead){
            while(pHead != nullptr){
                std::cout<<pHead->value<<"->";
                pHead = pHead->next;
            }
        }

void PrintListReverse(ListNode* pHead){
    std::stack<int> stack_node;
    while(pHead != nullptr){
        stack_node.push(pHead->value);
        pHead = pHead->next;
    }

    while(!stack_node.empty()){
        std::cout<<stack_node.top()<<"->";
        stack_node.pop();
    }
}



int main(){
    vector<int> vec = {1, 3, 6, 8};
    ListNode* pHead = CreateList(vec);
    PrintList(pHead);
    std::cout<<endl;
    
    PrintListReverse(pHead);
    std::cout<<endl;

    return 0;
}