public class Solution
{
    public int MinAddToMakeValid(string s)
    {
        int sum = 0;
        int result = 0;

        for (int i = 0; i < s.Length; ++i)
        {
            sum += s[i] == '(' ? 1 : -1;

            if (sum == -1)
            {
                ++result;
                sum = 0;
            }
        }

        return result + sum;
    }
}
