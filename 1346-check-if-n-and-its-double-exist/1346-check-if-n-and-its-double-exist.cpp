class Solution
{
public:
    bool checkIfExist(vector<int>& arr)
    {
        unordered_set<int> wants;

        for (int num : arr)
        {
            if (wants.find(num) != wants.end())
            {
                return true;
            }

            wants.insert(num * 2);
            if (num % 2 == 0)
            {
                wants.insert(num / 2);
            }
        }

        return false;
    }
};
