#include <iostream>
#include <vector>
#include "sort_h.h"
using namespace std;
class Solution {
	int ret;
public:
	int threeSumClosest(vector<int>& nums, int target) {
		if(nums.size() == 3) return nums[0]+nums[1]+nums[2];
		sort(nums.begin(),nums.end());
		ret = nums[0]+nums[1]+nums[2];
		for(int i = 0; i < nums.size()-2; i++){
			for(int j = i+1; j < nums.size()-1; j++){
				int sum = nums[i]+nums[j];
				for(int k = j+1; k < nums.size(); k++){
					if(abs(sum+nums[k]-target) > abs(ret=target)){
						if(sum+nums[k] > target)
							break;
					}else{
						ret = sum+nums[k];
					}
				}
			}
		}
		return ret;
	}
};

int main(){
	int a[] = {13,2,0,-14,-20,19,8,-5,-13,-3,20,15,20,5,13,14,-17,-7,12,-6,0,20,-19,-1,-15,-2,8,-2,-9,13,0,-3,-18,-9,-9,-19,17,-14,-19,-4,-16,2,0,9,5,-7,-4,20,18,9,0,12,-1,10,-17,-11,16,-13,-14,-3,0,2,-18,2,8,20,-15,3,-13,-12,-2,-19,11,11,-10,1,1,-10,-2,12,0,17,-19,-7,8,-19,-17,5,-5,-10,8,0,-12,4,19,2,0,12,14,-9,15,7,0,-16,-5,16,-12,0,2,-16,14,18,12,13,5,0,5,6};
	vector<int> vec(a,a+(sizeof(a)/sizeof(int)));
	Solution ss;
	int i = ss.threeSumClosest(vec,-59);
	cout<<i;
};