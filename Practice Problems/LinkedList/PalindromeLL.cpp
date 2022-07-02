#include <iostream>

using namespace std;

class Solution
{
public:
    @ts-ignore
    
    ListNode *mid(ListNode *head)
    {
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast->next && fast->next->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }
    ListNode *reverseLL(ListNode *head)
    {
        ListNode *prev = NULL;
        ListNode *temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        head->next = prev;
        return head;
    }
    bool isPalindrome(ListNode *head)
    {
        if (head == NULL)
        {
            return false;
        }
        if (head->next == NULL)
        {
            return true;
        }
       
        ListNode *middle = mid(head);
        ListNode *head2 = reverseLL(middle->next);
        ListNode *walker1 = head;
        ListNode *walker2 = head2;
        while (walker1 && walker2)
        {
            if (walker1->val != walker2->val)
            {
                return false;
            }
            walker1 = walker1->next;
            walker2 = walker2->next;
        }

        @ts-ignore
        return true;
    }
};

int main()
{

    return 0;
}