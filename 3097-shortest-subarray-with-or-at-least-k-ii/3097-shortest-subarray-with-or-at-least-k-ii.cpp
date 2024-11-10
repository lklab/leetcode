// source: https://leetcode.com/problems/shortest-subarray-with-or-at-least-k-ii/solutions/6028302/bitset-freq-sliding-window-8ms-beats-98-90/?envType=daily-question&envId=2024-11-10

class Solution
{
public:
    bitset<30> B;
    int k;
    void update(unsigned* freq, unsigned x, bool add=1){
        bitset<30> b(x);
        for(int i=0; i<30; i++)
            freq[i]+=(add)?b[i]:-b[i];
    }

    bool check(unsigned* freq){
        int b=0;
        for(int i=0; i<30; i++)
            if (freq[i]>0) b|=(1<<i);
        return b>=k;
    }

    void print(auto& f){
        for(int i=0; i<30; i++) cout<<f[i]<<",";
        cout<<endl;
    }

    int minimumSubarrayLength(vector<int>& nums, int k)
    {
        if (k==0) return 1;
        this->k=k;
        B=bitset<30>(k);
    //    print(B);
        unsigned freq[30]={0};
        int n=nums.size(), ans=INT_MAX;
        for(int l=0, r=0; r<n; r++){
            int x=nums[r];
            if (x>=k) return 1;
            update(freq, nums[r], 1);
        //    cout<<"r="<<r<<",x="<<nums[r]<<", freq:"; print(freq);
            while(l<n && check(freq)){
            //    cout<<"\tl="<<l<<",x="<<nums[l]<<", freq:";print(freq);
                ans=min(ans, r-l+1);
                update(freq, nums[l++], 0);
            }
        }
        return (ans==INT_MAX)?-1:ans;
    }
};
