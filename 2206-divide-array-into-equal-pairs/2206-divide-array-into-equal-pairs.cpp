class Solution {
public:
    bool divideArray(vector<int>& nums) {
        bitset<501> bits;

        for (int num : nums)
        {
            bits.flip(num);
        }

        return bits.none();
    }
};
