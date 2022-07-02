#include <iostream>

using namespace std;
class ListNode
{
public:
    int val;
    ListNode *next;
}; // just initialized to remove error (Below class is soln of Leetcode)
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *temp1 = l1;
        ListNode *temp2 = l2;
        ListNode *prev = NULL;
        bool i = false;
        if (temp1 == NULL && temp2 == NULL)
            return NULL;
        if (temp1 == NULL && temp2 != NULL)
            return l2;
        else if (temp1 != NULL && temp2 == NULL)
            return l1;
        while (temp1 != NULL && temp2 != NULL)
        {
            if (temp1->val <= temp2->val)
            {
                if (i)
                {
                    prev->next = temp1;
                    prev = temp1;
                    temp1 = temp1->next;
                }
                else
                {
                    prev = temp1;
                    l1 = temp1;
                    temp1 = temp1->next;
                }
            }
            else
            {
                if (i)
                {
                    prev->next = temp2;
                    prev = temp2;
                    temp2 = temp2->next;
                }
                else
                {
                    prev = temp2;
                    l1 = temp2;
                    temp2 = temp2->next;
                }
            }
            i = true;
        }
        if (temp1 == NULL && temp2 != NULL)
        {
            prev->next = temp2;
        }
        else if (temp1 != NULL && temp2 == NULL)
        {
            prev->next = temp1;
        }
        return l1;
    }
};
int main()
{

    return 0;
}