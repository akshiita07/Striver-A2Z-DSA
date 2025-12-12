vector<int> mentions(numberOfUsers, 0);
        vector<int> offlineUntil(numberOfUsers, 0);
        vector<bool> online(numberOfUsers, true);
        sort(events.begin(), events.end(), [](const auto &a, const auto &b) {
            int ta = stoi(a[1]), tb = stoi(b[1]);
            if (ta != tb) return ta < tb;
            if (a[0] == b[0]) return false;
            if (a[0] == "OFFLINE") return true;
            return false;
        });
        for (auto &e : events) {
            int t = stoi(e[1]);
            for (int u = 0; u < numberOfUsers; ++u) {
                if (!online[u] && offlineUntil[u] <= t) online[u] = true;
            }
            if (e[0] == "OFFLINE") {
                int u = stoi(e[2]);
                online[u] = false;
                offlineUntil[u] = t + 60;
            } else {
                string msg = e[2];
                if (msg == "ALL") {
                    for (int u = 0; u < numberOfUsers; ++u) mentions[u]++;
                } else if (msg == "HERE") {
                    for (int u = 0; u < numberOfUsers; ++u) if (online[u]) mentions[u]++;
                } else {
                    stringstream ss(msg);
                    string tok;
                    while (ss >> tok) {
                        if (tok.size() >= 3 && tok[0]=='i' && tok[1]=='d') {
                            int u = stoi(tok.substr(2));
                            mentions[u]++;
                        }
                    }
                }
            }
        }
        return mentions;
