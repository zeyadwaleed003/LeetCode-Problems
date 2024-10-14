class Solution {
public:
    long long maxKelements(vector<int>& nums, int k)
    {
        int n = nums.size();

        priority_queue<int>pq;
        for( int i = 0; i < n; i++ )
            pq.push(nums[i]);

        long long ans = 0;
        while( k-- )
        {
            int num = pq.top();
            ans += num;
            pq.pop();
            pq.push(ceil(1.0 * num / 3.0));
        }

        return ans;
    }
};