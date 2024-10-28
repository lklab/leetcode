struct Node
{
    int val;
    Node* next;

    Node() : val(0), next(nullptr) { }
    Node(int val) : val(val), next(nullptr) { }
};

class Solution
{
public:
    int longestSquareStreak(vector<int>& nums)
    {
        unordered_map<int, Node> nodeMap;
        unordered_map<int, Node*> sqrNodeMap;
        unordered_set<Node*> rootNodes;

        for (int num : nums)
        {
            nodeMap.emplace(num, num);
            Node* node = &nodeMap[num];

            if (num < 317)
            {
                int sqr = num * num;
                sqrNodeMap[sqr] = node;

                auto nodeIt = nodeMap.find(sqr);
                if (nodeIt != nodeMap.end())
                {
                    Node* sqrNode = &(nodeIt -> second);
                    node -> next = sqrNode;
                    rootNodes.erase(sqrNode);
                }
            }

            auto sqrIt = sqrNodeMap.find(num);
            if (sqrIt != sqrNodeMap.end())
            {
                Node* sqrtNode = sqrIt -> second;
                sqrtNode -> next = node;
            }
            else
            {
                rootNodes.insert(node);
            }
        }

        int maxCount = 1;

        for (Node* head : rootNodes)
        {
            int count = 0;
            Node* node = head;

            while (node != nullptr)
            {
                ++count;
                node = node -> next;
            }

            maxCount = max(maxCount, count);
        }

        return maxCount == 1 ? -1 : maxCount;
    }
};
