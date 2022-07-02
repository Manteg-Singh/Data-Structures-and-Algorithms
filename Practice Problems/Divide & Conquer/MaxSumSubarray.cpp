#include <iostream>
#include<vector>
using namespace std;
int maxCrossSum(vector<int> a,int mid)
{
    int leftCrossSum=0,rightCrossSum=0,sum=0;
    for (int i = mid; i >=0 ; i--)
    {
        sum+=a[i];
        if (sum>leftCrossSum)
        {
            leftCrossSum=sum;
        }       
    }
    sum=0;
    for (int i = mid+1; i <a.size() ; i++)
    {
        sum+=a[i];
        if (sum>rightCrossSum)
        {
            rightCrossSum=sum;
        }
        
    }
    return (leftCrossSum+rightCrossSum);
    
}
int max(int a,int b)
{
    if (a>=b)
    {
        return a;
    }
    return b;
}
int maxSumSubarray(vector<int> a,int low, int high)
{
    int mid;
    if (high==low)
    {
        return a[low];
    }
    mid=(low+high)/2;
    int left_sum=maxSumSubarray(a,low,mid);
    int right_sum=maxSumSubarray(a,mid+1,high);
    int cross_sum = maxCrossSum(a,mid);
    int maxi= max(left_sum,right_sum);
    return(max(maxi,cross_sum));
}

int main()
{
    int n,x;
    vector<int> arr;
    cin>>n;
    for (int i = 0; i <n; i++)
    {
        cin>>x;
        arr.push_back(x);

    }
    // cout<<arr[0];
    cout<<maxSumSubarray(arr,0,arr.size()-1);

    return 0;
}