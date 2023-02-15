#include <string>
#include <map>

class Solution
{
public:
    int longestPalindrome(const std::string &s)
    {
        std::map<char, int> count;
        for (const auto &c : s)
        {
            ++count[c];
        }
        int len = 0;
        for (const auto &entry : count)
        {
            auto &c = entry.second;
            len += (c / 2) * 2;
            if (len % 2 == 0 && c % 2 == 1)
            {
                len++;
            }
        }
        return len;
    }
};

int main()
{
    auto s = Solution();
    auto r = s.longestPalindrome("abccccddz");
    return r;
}