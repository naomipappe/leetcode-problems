#include <vector>

using std::vector;
using std::max;

//TODO convert to single-pass
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        for(std::size_t idx = 1; idx < prices.size(); ++idx){
           prices[idx-1] = prices[idx] - prices[idx-1];
        }
        // Now, compute the maximum sub-array sum and return it
        int sum = 0;
        int max_sum = 0;
        for(std::size_t idx = 0; idx < prices.size()-1; ++idx){
            // track the current sum. If we get below zero (loss), reset the sum to 0
            sum = max(0, sum + prices[idx]);
            // Track the best sum so far
            max_sum = max(sum,max_sum);
        }
        return max_sum;
    }
};

int main(){

}