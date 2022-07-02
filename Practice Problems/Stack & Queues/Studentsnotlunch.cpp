#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int not_pasand=0,counter=students.size();
        stack<int> s;
        queue<int> q;
        for (int i = 0; i < students.size(); i++)
        {
            q.push(students[i]);
        }
        for (int i = sandwiches.size()-1; i >=0; i++)
        {
            s.push(sandwiches[i]);
        }
        
        
        
        while (not_pasand!=counter)
        {
            if (q.front()==s.top())
            {
                s.pop();
                q.pop();
                counter--;
                not_pasand=0;
            }
            else
            {
                int k=q.front();
                q.pop();
                q.push(k);
                not_pasand++;
            }
        }
        return not_pasand;
        
    }
};

int main()
{
    
    return 0;
}