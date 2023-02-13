#include <string>
#include <iostream>

class Solution
{
public:
    // Check whether s is subseq of t
    bool isSubsequence(const std::string &s, const std::string &t)
    {
        if (s.length() == 0)
        {
            return true;
        }
        std::size_t idx_s{0};
        for (std::size_t idx_t = 0; idx_t < t.size(); ++idx_t)
        {
            if (t[idx_t] == s[idx_s])
            {
                ++idx_s;
            }
        }
        return idx_s == s.length();
    }
};

int main()
{

    auto s = Solution();
    std::cout << s.isSubsequence("axc", "ahbgdc") << '\n';
    return 0 ;
}