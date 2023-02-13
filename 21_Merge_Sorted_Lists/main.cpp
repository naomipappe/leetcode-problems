
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
    // The trick here is to not create new linked list but simply link against the existing entrees, as this is permitted
    // We should however create a dummy head from which we start, and we delete it later to avoid a memory leak
    // If asked to create a new list, we would simply create new nodes instead of re-linking and copy value
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *head = new ListNode();

        ListNode *iterator = head;

        while (list1 && list2)
        {
            if (list1->val < list2->val)
            {
                iterator->next = list1;
                list1 = list1->next;
            }
            else
            {
                iterator->next = list2;
                list2 = list2->next;
            }
            iterator = iterator->next;
        }

        if (list1)
        {
            iterator->next = list1;
        }
        if (list2)
        {
            iterator->next = list2;
        }

        ListNode *result = head->next;
        delete head;
        return result;
    }
};
int main()
{
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);

    ListNode *l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);

    auto s = Solution();
    s.mergeTwoLists(l1, l2);
}