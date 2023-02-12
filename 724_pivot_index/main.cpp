#include <iostream>
#include <vector>

using std::vector;

class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        int sum = 0;
        for (const auto &n : nums)
        {
            sum += n;
        }
        int left_sum = 0;
        for (size_t i = 0; i < nums.size(); ++i)
        {
            if (sum - left_sum - nums[i] == left_sum)
            {
                return i;
            }
            left_sum += nums[i];
        }
        return -1;
    }
};

int main()
{
    auto s = Solution();
    std::vector<int> v = {2, 1, -1};
    std::cout << s.pivotIndex(v) << '\n';
}