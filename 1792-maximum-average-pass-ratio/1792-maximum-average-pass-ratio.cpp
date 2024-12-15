class Solution
{
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents)
    {
        int n = classes.size();
        priority_queue<pair<double, int>> heap;
        vector<int> extras(n);
        double sum = 0.0;

        // setup the heap
        for (int i = 0; i < n; ++i)
        {
            double ratio = (double)classes[i][0] / classes[i][1];
            double diff = (classes[i][0] + 1.0) / (classes[i][1] + 1.0) - ratio;
            heap.emplace(diff, i);
            sum += ratio;
            extras[i] = 1;
        }

        // put extra students
        for (int i = 0; i < extraStudents; ++i)
        {
            auto [diff, index] = heap.top();
            heap.pop();
            sum += diff;

            int ext = extras[index];
            ++extras[index];
            diff = (classes[index][0] + ext + 1.0) / (classes[index][1] + ext + 1.0) -
                (double)(classes[index][0] + ext) / (classes[index][1] + ext);

            heap.emplace(diff, index);
        }

        // get result
        return sum / n;
    }
};
