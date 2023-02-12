#include <map>
#include <string>

using std::string;

class Solution
{
public:

    // The trick here is to track mapping for both of the words
    // For instance "paper" and "title"
    // Here, it is possible for 'e' from first world to map to 'l' in second, and for 'e' in second to map to 'r' in first
    // Therefore, we need to track both mappings, to avoid the case for
    // "bads" and "baba"
    // If we track only the mapping from first to second, then 'b'maps to 'b', 'a' to 'a', 'd' to 'b' and 's' to 'a'
    // but here we already see that while for the first word only the check would pass, there would be already mapping for 
    // 'b' to 'b' and 'a' to 'a' from the second world, which prevents the strings from being isomorphic
    bool isIsomorphic(const string &s, const string &t)
    {
        std::map<char, char> mapping_s_t;
        std::map<char, char> mapping_t_s;

        for (size_t i = 0; i < s.size(); ++i)
        {
            if (mapping_s_t.count(s[i]) == 0 && mapping_t_s.count(t[i]) == 0)
            {
                mapping_s_t[s[i]] = t[i];
                mapping_t_s[t[i]] = s[i];
            }
            else
            {
                if (mapping_s_t[s[i]] != t[i] || mapping_t_s[t[i]] != s[i])
                {
                    return false;
                }
            }
        }
        return true;
    }
};

int main()
{
    auto s = Solution();
    auto r = s.isIsomorphic("bads", "baba");
    return r;
}