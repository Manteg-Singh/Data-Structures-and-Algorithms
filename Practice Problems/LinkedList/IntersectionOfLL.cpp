#include <iostream>
#include<vector>
#include<stack>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class ListNode{
    ListNode* next;
    int val;
    };
class Solution {
public:
    
    ListNode* rev(ListNode* head)
    {
        ListNode* prev=NULL;
        ListNode* temp=head;
        while(temp)
        {
            temp=temp->next;
            head->next=prev;
            prev=head;
            head=temp;
            
        }
        return head;
    
    }
    vector<int> nextLargerNodes(ListNode* head) {
        stack<int> s;
        head=rev(head);
        ListNode* temp=head;
        vector<int> ans;
        while(temp)
        {
           while(s.empty()&&temp->val<s.top())
           {
               s.pop();
           }
            if(s.empty())
            {
                ans.push_back(0);
                
            }
            else
            {
                ans.push_back(s.top());
                
            }
            s.push(temp->val);
            temp=temp->next;
        }
        reverse(ans.begin(),ans.end());
            return ans;
        
    }
};
int main()
{
    
    return 0;
}