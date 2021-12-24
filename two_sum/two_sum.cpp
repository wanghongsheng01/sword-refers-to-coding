/**
 * 面试题:两个数之和等于第三个数
*/
#include<iostream>
#include<vector>
#include<algorithm>

using std::vector;
using std::string;
using std::cout;
using std::endl;

template<typename T>
bool TwoSum(vector<T>& vec, const int& target){
    int left = 0;
    int right = vec.size() - 1;

    while( left <= right){
        T tmp = vec.at(left) + vec.at(right) - target;
        if(tmp == 0){
            return true;

        }else if(tmp > 0){
            right--;
        }else{
            left++;
        }
    }
    return false;
}

int main(){
    vector<int> v = {1, 2, 4, 8};
    bool res = TwoSum(v, 19);
    std::cout<<res<<std::endl;
    return 0;
}