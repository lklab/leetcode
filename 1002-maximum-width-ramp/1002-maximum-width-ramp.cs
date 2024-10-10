public class Solution
{
    public int MaxWidthRamp(int[] nums)
    {
        int n = nums.Length;
        Stack<int> stack = new Stack<int>();

        for (int i = 0; i < n; ++i)
        {
            if (stack.Count == 0 || nums[stack.Peek()] > nums[i])
            {
                stack.Push(i);
            }
        }

        int result = 0;
        for (int i = n - 1; i >= 0; --i)
        {
            while (stack.Count > 0 && i - stack.Peek() <= result)
            {
                stack.Pop();
            }

            while (stack.Count > 0 && nums[stack.Peek()] <= nums[i])
            {
                result = Math.Max(result, i - stack.Pop());
            }

            if (stack.Count == 0)
            {
                break;
            }
        }

        return result;

        // int n = nums.Length;
        // int[] indexes = new int[n];
        // for (int i = 0; i < n; ++i)
        // {
        //     indexes[i] = i;
        // }

        // Array.Sort(indexes, (a, b) =>
        // {
        //     if (nums[a] == nums[b])
        //     {
        //         if (a < b)
        //         {
        //             return -1;
        //         }
        //         else
        //         {
        //             return 1;
        //         }
        //     }
        //     else if (nums[a] < nums[b])
        //     {
        //         return -1;
        //     }
        //     else
        //     {
        //         return 1;
        //     }
        // });

        // int min = indexes[0];
        // int result = 0;

        // for (int i = 0; i < n; ++i)
        // {
        //     int index = indexes[i];
        //     if (min > index)
        //     {
        //         min = index;
        //     }

        //     int temp = index - min;
        //     if (result < temp)
        //     {
        //         result = temp;
        //     }
        // }

        // return result;

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
