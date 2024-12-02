class Solution
{
public:
    int isPrefixOfWord(string sentence, string searchWord)
    {
        int n1 = sentence.size();
        int n2 = searchWord.size();
        int i1 = 0;
        int i2 = 0;
        int word = 1;

        while (i1 < n1)
        {
            while (i1 < n1 && i2 < n2 && sentence[i1] == searchWord[i2])
            {
                ++i1;
                ++i2;
            }

            if (i2 == n2)
            {
                return word;
            }

            i2 = 0;
            ++word;

            while (i1 < n1 && sentence[i1] != ' ')
            {
                ++i1;
            }
            ++i1;
        }

        return -1;
    }
};
