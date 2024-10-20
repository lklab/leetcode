class Solution
{
private:
    bool parseExpr(const string &exp, int start, int end)
    {
        int s = start + 2;
        int e = end - 1;
        // cout << "call " << start << " " << end << endl;

        switch (exp[start])
        {
            case 't':
                // cout << start << " " << end << " t" << endl;
                return true;

            case 'f':
                // cout << start << " " << end << " f" << endl;
                return false;

            case '!':
            {
                switch (exp[s])
                {
                    case 't':
                        // cout << start << " " << end << " !t" << endl;
                        return false;
                    case 'f':
                        // cout << start << " " << end << " !f" << endl;
                        return true;
                    default :
                        return !parseExpr(exp, s, e);
                }
            }

            case '&':
            {
                int i = s;
                while (i < e)
                {
                    switch (exp[i])
                    {
                        case 't':
                            break;

                        case 'f':
                            // cout << start << " " << end << " &f" << endl;
                            return false;

                        default :
                            int parentheses = 0;
                            for (int j = i + 1; j < e; ++j)
                            {
                                switch (exp[j])
                                {
                                    case '(': ++parentheses; break;
                                    case ')': --parentheses; break;
                                }

                                if (parentheses == 0)
                                {
                                    if (!parseExpr(exp, i, j + 1))
                                    {
                                        // cout << start << " " << end << " &exp" << endl;
                                        return false;
                                    }
                                    i = j;
                                    break;
                                }
                            }
                    }

                    i += 2;
                }

                // cout << start << " " << end << " &t" << endl;
                return true;
            }

            case '|':
            {
                int i = s;
                while (i < e)
                {
                    switch (exp[i])
                    {
                        case 't':
                            // cout << start << " " << end << " |t" << endl;
                            return true;

                        case 'f':
                            break;

                        default :
                            int parentheses = 0;
                            for (int j = i + 1; j < e; ++j)
                            {
                                switch (exp[j])
                                {
                                    case '(': ++parentheses; break;
                                    case ')': --parentheses; break;
                                }

                                if (parentheses == 0)
                                {
                                    if (parseExpr(exp, i, j + 1))
                                    {
                                        // cout << start << " " << end << " |exp" << endl;
                                        return true;
                                    }
                                    i = j;
                                    break;
                                }
                            }
                    }

                    i += 2;
                }

                // cout << start << " " << end << " |f" << endl;
                return false;
            }
        }

        return true;
    }

public:
    bool parseBoolExpr(string expression)
    {
        return parseExpr(expression, 0, expression.size());
    }
};
