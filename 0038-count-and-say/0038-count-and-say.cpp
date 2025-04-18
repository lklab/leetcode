// source: https://leetcode.com/problems/count-and-say/solutions/6661661/do-as-said-using-iterative-approach/?envType=daily-question&envId=2025-04-18

class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        string s2;
        for(int i = 0;i<n-1;i++){
            char prev = s[0];
            int cnt = 1;
            for(int j = 1;j<s.length();j++){
                if(s[j] == prev)
                    cnt++;
                else{
                    s2.append(to_string(cnt));
                    s2.push_back(prev);
                    cnt = 1;
                }
                prev = s[j];
            }
            s2.append(to_string(cnt));
            s2.push_back(prev);
            s = s2;
            s2.clear();
        }
        return s;
    }
};
