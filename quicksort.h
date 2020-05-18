#include<vector>
#include<iostream>

using namespace std;

class QuickSort{
private:
	vector<int> sort_nums;

public:
	void input_nums(vector<int>& nums);
	vector<int> output_nums();
	void quicksort(int low, int high);
	int getindex(int low, int high);
};

void QuickSort::input_nums(vector<int>& nums){
	sort_nums = nums;
}

void QuickSort::quicksort(int low, int high){
	if(low < high){
		int index = getindex(low, high);

		quicksort(low, index-1);
		quicksort(index+1, high);
	}
}

int QuickSort::getindex(int low, int high){
	int base = sort_nums[low];
	while(low<high){
		while(low<high && sort_nums[high]>=base) high--;
		sort_nums[low] = sort_nums[high];
		while(low<high && sort_nums[low]<=base) low++;
		sort_nums[high] = sort_nums[low];
	}
	sort_nums[low] = base;
	return low;
}

vector<int> QuickSort::output_nums(){
	int N = sort_nums.size();
	if(N == 0 || N == 1) return sort_nums;
	quicksort(0, N-1);
	return sort_nums;
}
