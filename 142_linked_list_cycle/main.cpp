
// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
    // Here we should use classic hare and turtle approach with one pointer travelling twice as fast as the other
public:
    ListNode *detectCycle(ListNode *head)
    {
        if (!head)
        {
            return nullptr;
        }
        ListNode *turtle = head;
        ListNode *hare = head;

        // While there is where to move, hare and turtle move
        while (hare && hare->next)
        {
            hare = hare->next->next;
            turtle = turtle->next;
            if (turtle == hare)
            {
                break;
            }
        }

        // check that we ended the while not because the list has ended
        if (!hare || !hare->next)
        {
            return nullptr;
        }

        while (head != turtle)
        {
            head = head->next;
            turtle = turtle->next;
        }
        return head;
    }
};

int main()
{
}