class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        // Using uint64_t to naturally handle integer overflow instead of modulo math.
        // This makes the hash extremely fast and minimizes collisions.
        unordered_map<uint64_t, int> mp;
        const uint64_t BASE = 313; // A prime base for our rolling hash

        // 1. Find the best default match (shortest length, earliest index)
        int default_idx = 0;
        for (int i = 1; i < wordsContainer.size(); i++) {
            if (wordsContainer[i].size() < wordsContainer[default_idx].size()) {
                default_idx = i;
            }
        }
        
        // Map hash 0 to our best default index to cover cases with 0 matching characters
        mp[0] = default_idx;

        // 2. Hash all suffixes in wordsContainer
        for (int i = 0; i < wordsContainer.size(); i++) {
            uint64_t h = 0;
            int len = wordsContainer[i].size();

            // Iterate backwards to compute hashes of suffixes natively
            for (int j = len - 1; j >= 0; j--) {
                h = h * BASE + wordsContainer[i][j];

                if (mp.find(h) == mp.end()) {
                    mp[h] = i;
                } else {
                    int prevFound = mp[h];
                    // Update if the current word has a strictly smaller length.
                    // Tie-breaking by smallest index is naturally handled because 
                    // our loop goes from 0 to N-1, meaning we see earlier indices first.
                    if (len < wordsContainer[prevFound].size()) {
                        mp[h] = i;
                    }
                }
            }
        }

        // 3. Process Queries
        int n = wordsQuery.size();
        vector<int> ans(n);
        
        for (int i = 0; i < n; i++) {
            uint64_t h = 0;
            int best_match = mp[0]; // Start with the empty suffix match
            int len = wordsQuery[i].size();

            for (int j = len - 1; j >= 0; j--) {
                h = h * BASE + wordsQuery[i][j];
                
                if (mp.find(h) != mp.end()) {
                    best_match = mp[h]; // Update to the deeper matching suffix
                } else {
                    // Since we build suffixes from the end, if this length isn't found,
                    // a longer suffix definitely won't be found. We can break early.
                    break;
                }
            }
            ans[i] = best_match;
        }

        return ans;
    }
};