#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
using std::vector;
using std::string;
using std::endl;
using std::cout;

void swap(int m, int n){
    int tmp = m;
    m = n;
    n = tmp;
}

void print(vector<int>& v){
    for(auto& x : v){
        std::cout<< x <<std::endl;
    }

}

int duplication_array(vector<int>& vec){
    for(int i = 0; i < vec.size(); ++i){
        if(vec.at(i) == i) continue;
        while(vec[i] != i){
            if(vec.at(i) == vec.at(vec[i])){
                return vec[i];
            }
            swap(vec[i], vec.at(vec[i]));
        }
    }
    return -1;
}

int main(){

    vector<int> v = {1, 2, 4, 2, 3};
    int res = duplication_array(v); // &res_tmp 把变量的地址传给指针变量
    std::cout<<"res:"<<res<<std::endl;

    // print(v);
    return 0;
}