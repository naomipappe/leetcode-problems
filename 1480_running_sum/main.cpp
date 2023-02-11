#include <vector>
#include <iostream>

using std::vector;

class Solution
{
public:
    // Running sum is an array of elements where each n-th element is the sum of first n-elements of the input array
    vector<int> runningSum(vector<int> &nums)
    {
        std::vector<int> result;
        result.resize(nums.size());
        result[0] = nums[0];
        if (nums.size() == 1)
        {
            return result;
        }
        for (size_t idx = 1; idx < nums.size(); ++idx)
        {
            result[idx] = result[idx - 1] + nums[idx];
        }
        return result;
    }
};

int main()
{
    auto s = Solution();
    std::vector<int> v = {1, 2, 3, 4};
    auto r = s.runningSum(v);
    for (const auto n : r)
    {
        std::cout << n << ' ';
    }
    std::cout << '\n';
}