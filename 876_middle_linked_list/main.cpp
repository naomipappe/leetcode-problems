#include <iostream>

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        // Obvious solution is to traverse the list twice
        // Less obvious solution would probably involve two pointers that traverl with diff speed
        std::size_t size = 0;
        ListNode *iterator = head;
        while (iterator)
        {
            ++size;
            iterator = iterator->next;
        }
        std::size_t idx = size / 2;
        std::size_t i{0};
        iterator = head;
        while (i < idx)
        {
            iterator = iterator->next;
            ++i;
        }
        return iterator;
    }
};

int main(){

}