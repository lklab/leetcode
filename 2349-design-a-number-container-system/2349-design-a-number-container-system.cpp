class NumberContainers {
private:
    unordered_map<int, int> container;
    unordered_map<int, set<int>> indexes;

public:
    NumberContainers() {

    }

    void change(int index, int number) {
        int before = container[index];
        if (before != 0) {
            indexes[before].erase(index);
        }
        container[index] = number;
        indexes[number].insert(index);
    }

    int find(int number) {
        if (indexes.find(number) == indexes.end() || indexes[number].empty()) {
            return -1;
        } else {
            return *indexes[number].begin();
        }
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */