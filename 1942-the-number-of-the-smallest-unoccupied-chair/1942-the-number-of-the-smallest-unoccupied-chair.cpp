typedef struct Action
{
    int id;
    int time;
    bool isArrival;

    Action(int id, int time, bool isArrival) : id(id), time(time), isArrival(isArrival) {}
} Action;

class Solution
{
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend)
    {
        vector<unique_ptr<Action>> actions;

        for (int i = 0; i < times.size(); ++i)
        {
            actions.push_back(unique_ptr<Action>(new Action(i, times[i][0], true)));
            actions.push_back(unique_ptr<Action>(new Action(i, times[i][1], false)));
        }

        sort(actions.begin(), actions.end(), [](unique_ptr<Action> &a, unique_ptr<Action> &b)
        {
            if (a -> time == b -> time)
            {
                return !a -> isArrival && b -> isArrival;
            }
            else
            {
                return a -> time < b -> time;
            }
        });

        priority_queue<int, vector<int>, greater<int>> empty_chairs;
        map<int, int> chairs_map;
        int last = 0;

        for (auto &action : actions)
        {
            if (action -> isArrival)
            {
                if (empty_chairs.size() > 0)
                {
                    chairs_map.insert({action -> id, empty_chairs.top()});
                    empty_chairs.pop();
                }
                else
                {
                    chairs_map.insert({action -> id, last});
                    ++last;
                }

                if (action -> id == targetFriend)
                {
                    return chairs_map[action -> id];
                }
            }
            else
            {
                empty_chairs.push(chairs_map[action -> id]);
            }
        }

        return 0;
    }
};
