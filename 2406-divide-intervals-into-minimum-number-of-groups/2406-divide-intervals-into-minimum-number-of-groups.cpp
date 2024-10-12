class Solution
{
public:
    int minGroups(vector<vector<int>>& intervals)
    {
        vector<int> event_positions;
        map<int, int> event_map;

        for (auto &interval : intervals)
        {
            int l = interval[0];
            int r = interval[1] + 1;

            if (event_map.find(l) != event_map.end())
            {
                event_map[l] += 1;
            }
            else
            {
                event_positions.push_back(l);
                event_map.insert({l, 1});
            }

            if (event_map.find(r) != event_map.end())
            {
                event_map[r] -= 1;
            }
            else
            {
                event_positions.push_back(r);
                event_map.insert({r, -1});
            }
        }

        sort(event_positions.begin(), event_positions.end());

        int result = 0;
        int current = 0;

        for (int position : event_positions)
        {
            current += event_map[position];
            if (current > result)
            {
                result = current;
            }
        }

        return result;
    }
};
