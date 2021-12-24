#include <iostream>
#include <vector>
#include <algorithm>

using std::cout; 
using std::endl;
using std::string; 
using std::vector;

void printVec(vector<int>& vec){
	for(auto& x : vec){
		std::cout<<x<<",";
	}
	std::cout<<std::endl;

}
//快速排序（从小到大）
void quickSort(int left, int right, vector<int>& arr)
{
	if(left >= right)
		return;
	int i, j, base, temp;
	i = left, j = right;
	base = arr[left];  //取最左边的数为基准数
	while (i < j)
	{
		while (arr[j] >= base && i < j)
			j--;
		while (arr[i] <= base && i < j)
			i++;
		if(i < j)
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	//基准数归位
	arr[left] = arr[i];
	arr[i] = base;
	quickSort(left, i - 1, arr);//递归左边
	quickSort(i + 1, right, arr);//递归右边
}

int main()
{
    vector<int> vec1 = {10, 4, 1, 2, 0,  5, 3, 8, -1};
	std::cout<<"排序前："<<std::endl;
	printVec(vec1);
    quickSort(0, vec1.size()-1, vec1);
	std::cout<<"排序后："<<std::endl;
	printVec(vec1);
    return 0;
}