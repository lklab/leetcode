class ProductOfNumbers {
private:
    vector<int>& mainGroup;
    vector<int>& subGroup;
    vector<int> group0;
    vector<int> group1;
    int last = 1;

public:
    ProductOfNumbers() : mainGroup(group0), subGroup(group1) {
        mainGroup.push_back(1);
        subGroup.push_back(1);
        last = 1;
    }
    
    void add(int num) {
        if (num == 0) {
            mainGroup.clear();
            subGroup.clear();
            mainGroup.push_back(1);
            subGroup.push_back(1);
            last = 1;
            // cout << "clear" << endl;
        } else {
            if (last > numeric_limits<int>::max() / num) {
            // if (last > (200 / num)) {
                swap(mainGroup, subGroup);

                mainGroup.clear();
                mainGroup.push_back(1);
                last = 1;
                // cout << "swap " << subGroup.size() << endl;
            }

            last *= num;
            mainGroup.push_back(last);
            // cout << "main: " << last << endl;
        }
    }
    
    int getProduct(int k) {
        int mainSize = mainGroup.size() - 1;
        int subSize = subGroup.size() - 1;

        if (mainSize + subSize < k) {
            return 0;
        }

        if (mainSize >= k) {
            return mainGroup[mainSize] / mainGroup[mainSize - k];
        } else {
            return mainGroup[mainSize] * (subGroup[subSize] / subGroup[subSize - (k - mainSize)]);
        }

        return 0;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */  