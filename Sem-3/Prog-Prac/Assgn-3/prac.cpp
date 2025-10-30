class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // keep prefix xor 
        // pre[j] ^ pre[i - 1] = k
        // pre[j] = pre[i - 1] ^ k, i <= j
        // pre[i - 1] = pre[j] ^ k
        int t = arr.size();
        vector<int> pre(t + 1);
        pre[0] = 0;
        for (int i = 0; i < t; i++) {
            pre[i + 1] = pre[i] ^ arr[i];
        }
        map<int, long> m;
        m[0] = 1;
        long ans = 0;
        for (int i = 1; i <= k; i++) {
            ans += m[pre[i] ^ k];
            m[pre[i]]++;
        }
        return ans;
        // 0 1 0 1 0
    }
};