class AllOne {
public:
    // Constructor to initialize the data members
    AllOne() {
        maxIndex = 0;
        minIndex = 0;
    }

    // Increment the count of the key
    void inc(string key) {
        // If the key doesn't exist in the counts map, initialize it
        if (counts.find(key) == counts.end()) {
            counts[key] = 1;
            map[1].insert(key);
            minIndex = 1;  // The minimum index is set to 1 if this is the first key
            if (maxIndex < 1) {
                maxIndex = 1;  // Update maxIndex if necessary
            }
        } else {
            // Remove the key from the current set corresponding to its old count
            map[counts[key]].erase(key);
            // If this was the only key at the minIndex, we increase the minIndex
            if (minIndex == counts[key] && map[counts[key]].empty()) {
                minIndex++;
            }
            counts[key]++;  // Increase the key's count
            map[counts[key]].insert(key);  // Add it to the new set

            // Update maxIndex if the current count exceeds the previous maxIndex
            if (counts[key] > maxIndex) {
                maxIndex = counts[key];
            }
        }
    }

    // Decrement the count of the key
    void dec(string key) {
        map[counts[key]].erase(key);  // Remove the key from its current count set
        // If this key was at the minIndex and it's empty after removal, decrease minIndex
        if (minIndex == counts[key] && map[counts[key]].empty()) {
            minIndex--;
        }
        // If this key was at the maxIndex and it's empty after removal, decrease maxIndex
        if (counts[key] == maxIndex && map[counts[key]].empty()) {
            maxIndex--;
        }
        counts[key]--;  // Decrease the count

        // If the count is still greater than 0, add it to the corresponding set
        if (counts[key] > 0) {
            map[counts[key]].insert(key);
        } else {
            // If the count drops to 0, remove the key from the map
            counts.erase(key);
        }
    }

    // Return the key with the maximum count
    string getMaxKey() {
        // If there are keys at maxIndex, return one of them
        if (!map[maxIndex].empty()) {
            return *map[maxIndex].begin();
        }
        return "";  // If no such key, return an empty string
    }

    // Return the key with the minimum count
    string getMinKey() {
        // If there are keys at minIndex, return one of them
        if (!map[minIndex].empty()) {
            return *map[minIndex].begin();
        }
        // If the minIndex is 0 and there are still counts, we adjust minIndex
        if (minIndex == 0 && !counts.empty()) {
            while (map[minIndex].empty()) {
                minIndex++;
            }
            return *map[minIndex].begin();
        }
        return "";  // If no such key, return an empty string
    }

private:
    // Using an unordered_map to map counts to a set of keys
    unordered_map<int, unordered_set<string>> map;
    // Counts for each key
    unordered_map<string, int> counts;
    // Track the max and min index of the count
    int maxIndex;
    int minIndex;
};