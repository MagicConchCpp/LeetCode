#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> v1;
    int l = sizeof(nums) / sizeof(nums[0]);
    for (int i = 0; i != l; ++i) {
    	for (int j = i+1; j != l; ++i) {
    		if (nums[i] + nums[j] == target) {
    			v1.push_back(i);
    			v1.push_back(j);
    			break;
    		}
    	}
    }
    return v1;    
    }
};
	Solution a;
	vector<int> v{2, 3, 5, 6};
	cout << a.twoSum(v, 5);
	return 0;
}