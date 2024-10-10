public class Solution
{
    public int MaxWidthRamp(int[] nums)
    {
        int n = nums.Length;
        int[] indexes = new int[n];
        for (int i = 0; i < n; ++i)
        {
            indexes[i] = i;
        }

        Array.Sort(indexes, (a, b) =>
        {
            if (nums[a] == nums[b])
            {
                if (a < b)
                {
                    return -1;
                }
                else
                {
                    return 1;
                }
            }
            else if (nums[a] < nums[b])
            {
                return -1;
            }
            else
            {
                return 1;
            }
        });

        int min = indexes[0];
        int result = 0;

        for (int i = 0; i < n; ++i)
        {
            int index = indexes[i];
            if (min > index)
            {
                min = index;
            }

            int temp = index - min;
            if (result < temp)
            {
                result = temp;
            }
        }

        return result;

        // int n = nums.Length;
        // int result = 1;

        // for (; result < n; ++result)
        // {
        //     bool found = false;
        //     for (int i = result; i < n; ++i)
        //     {
        //         if (nums[i - result] <= nums[i])
        //         {
        //             found = true;
        //             break;
        //         }
        //     }

        //     if (!found)
        //     {
        //         --result;
        //         break;
        //     }
        // }

        // return result;
    }
}
