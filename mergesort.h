#include<stdio.h>
#include<vector>

using namespace std;

class MergeSort{
private:
	vector<int> sort_nums;
public:
	void input_nums(vector<int>& nums);
	vector<int> output_nums();
	void mergesort(int l_cur, int r_cur);
	void merge(int left, int right, int mid);
};

void MergeSort::input_nums(vector<int>& nums){
	sort_nums = nums;
}

void MergeSort::mergesort(int l_cur, int r_cur){
	if(l_cur >= r_cur) return;
	int m_cur = l_cur + (r_cur - l_cur) / 2;
	mergesort(l_cur, m_cur);
	mergesort(m_cur+1, r_cur);
	merge(l_cur, r_cur, m_cur+1);
}

void MergeSort::merge(int left, int right, int mid){
	vector<int> tmp;
	int l = left;
	int r = mid;
	while(l<mid && r<=right){
		if(sort_nums[l] <= sort_nums[r]){
			tmp.push_back(sort_nums[l++]);
		}else{
			tmp.push_back(sort_nums[r++]);
		}
	}
	while(l<mid) tmp.push_back(sort_nums[l++]);
	while(r<=right) tmp.push_back(sort_nums[r++]);

	for(int i=left; i<=right; i++){
		sort_nums[i] = tmp[i-left];
	}
}

vector<int> MergeSort::output_nums(){
	int N = sort_nums.size();
	if(N == 0 || N == 1) return sort_nums;
	mergesort(0, N-1);
	return sort_nums;
}

