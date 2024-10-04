#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int n = nums.size();
        
        if (n < 4) return result;
        
        // Sort the array to use two-pointer technique
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n - 3; ++i) {
            // Skip duplicates for the first number
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            
            for (int j = i + 1; j < n - 2; ++j) {
                // Skip duplicates for the second number
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                
                int left = j + 1;
                int right = n - 1;
                long long target2 = (long long)target - nums[i] - nums[j]; // Avoid overflow
                
                while (left < right) {
                    int sum = nums[left] + nums[right];
                    
                    if (sum == target2) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        
                        // Skip duplicates for the third and fourth numbers
                        while (left < right && nums[left] == nums[left + 1])
                            ++left;
                        while (left < right && nums[right] == nums[right - 1])
                            --right;
                        
                        ++left;
                        --right;
                    } else if (sum < target2) {
                        ++left;
                    } else {
                        --right;
                    }
                }
            }
        }
        
        return result;
    }
};

// Example usage
int main() {
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    Solution sol;
    vector<vector<int>> result = sol.fourSum(nums, target);
    
    // Printing the result
    for (const auto& quad : result) {
        for (int num : quad) {
            cout << num << " ";
        }
        cout << "\n";
    }
    
    return 0;
}
