//Question : https://leetcode.com/problems/sum-of-subarray-minimums/

Solution:
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr)
    {
        stack<pair<int,int>> stk;
        vector<int> left(arr.size(),0);
        vector<int> right(arr.size(),arr.size());
        for(int i = 0; i < arr.size(); i++)
        {
            if(!stk.empty())
            {
                if(stk.top().first < arr[i])
                {
                    left[i] = stk.top().second;
                    stk.push(make_pair(arr[i],i));
                }
                else
                {
                    while(!stk.empty() && stk.top().first >= arr[i])
                    {
                        right[stk.top().second] = i;
                        stk.pop();
                    }
                    if(!stk.empty())
                    {
                        left[i] = stk.top().second;
                    }
                    else
                    {
                        left[i] = -1;
                    }
                    stk.push(make_pair(arr[i],i));
                }
            }
            else
            {
                left[i] = i-1;
                stk.push(make_pair(arr[i],i));
            }
        }
        long ans = 0;
        const int limit = 1000000007;
        for(int i = 0; i < arr.size(); i++)
        {
            ans += long(arr[i])*long((i-left[i])*(right[i]-i));
            ans = ans%limit;
        }
        return ans;
    }
};
