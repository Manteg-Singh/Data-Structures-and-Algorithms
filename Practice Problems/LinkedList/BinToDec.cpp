#include <iostream>
#include <string>
#include<cmath>
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

// class Solution {
// public:
//     int getDecimalValue(ListNode* head) {
//         string s;
//         while(head!=NULL)
//         {
//             s.append(head->val);
//             head=head->next;
//         }
//         int ans=0;
//         for(int i=0;i<s.length();i++)
//         {
//             if(s[s.length()-1-i]=='1')
//             {
//                 ans=ans+pow(2,i);
//             }
//         }
//          return ans;
//     } 
// };
int main()
{
    string s{};
    s=s+'1';
    s=s+"0";
    s=s+"1";
    cout<<s;
    return 0;
}