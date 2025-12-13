class Solution {
public:
    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& businessLine,
                                   vector<bool>& isActive) {
        int n = code.size();
        unordered_map<string, int> priority = {{"electronics", 0},
                                               {"grocery", 1},
                                               {"pharmacy", 2},
                                               {"restaurant", 3}};

        vector<pair<int, string>> valid; // (business priority, code)

        for (int i = 0; i < n; i++) {
            if (!isActive[i]) {
                continue;
            }

            if (!priority.count(businessLine[i])) {
                continue;
            }

            if (code[i].empty()) {
                continue;
            }

            bool ok = true;
            for (char c : code[i]) {
                // must not be _ and only be alphanumeric
                if (!isalnum(c) && c != '_') {
                    ok = false;
                    break;
                }
            }
            if (!ok) {
                continue;
            }

            valid.push_back({priority[businessLine[i]], code[i]});
        }

        sort(valid.begin(), valid.end(), [](auto& a, auto& b) {
            if (a.first != b.first)
                return a.first < b.first;
            return a.second < b.second;
        });

        vector<string> result;
        for (auto& it : valid) {
            result.push_back(it.second);
        }

        return result;
    }
};
