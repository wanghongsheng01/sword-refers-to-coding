#include<iostream>
#include<vector>
#include<algorithm>

using std::vector;
using std::string;
using std::endl;
using std::cout;

template<typename T>
void PrintVec(vector<T>& v){
    for(auto& x : v){
        std::cout<< x <<",";
    }
}
    
void QuickSort(vector<int>& vec, int left, int right){

    if(left >= right){
        return;
    }

    int base = vec[left];
    int i = left; 
    int j = right;

    while(i < j){
        while(i < j && vec[j] >= base)
            j--;
        while(i < j && vec[i] <= base)
            i++;

        if(i < j){
            int tmp = vec[i];
            vec[i] = vec[j];
            vec[j] = tmp;
        }
    }

    vec[left] = vec[i];
    vec[i] = base;

    QuickSort(vec, left, i-1);
    QuickSort(vec, i+1, right);

}

int main(){
    vector<int> v = {10, 4, 1, 2, 0,  5, 3, 8, -1};
    std::cout<<"before sort:"<<std::endl;
    PrintVec(v);
    QuickSort(v, 0, v.size()-1);
    std::cout<<std::endl<<"after sort:"<<std::endl;
    PrintVec(v);
    std::cout<<std::endl;
    
    return 0;
}