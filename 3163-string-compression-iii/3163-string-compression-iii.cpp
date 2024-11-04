class Solution
{
public:
    string compressedString(string word)
    {
        string comp = "";
        int count = 1;
        char prefix = word[0];

        for (int i = 1; i < word.size(); ++i)
        {
            if (word[i] != prefix || count == 9)
            {
                comp += (count + '0');
                comp += prefix;

                count = 1;
                prefix = word[i];
            }
            else
            {
                ++count;
            }
        }

        comp += (count + '0');
        comp += prefix;

        return comp;
    }
};
