#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& m) {
        vector<int> o;
        int h = m.size();
        int w = m[0].size();
        int r = 0;
        
        while(r < h) {
            int c = (r % 2 == 0) ? 0 : w - 1;
            
            while((r % 2 == 0 && c < w) || (r % 2 != 0 && c >= 0)) {
                ((r + c) % 2 == 0) ? o.push_back(m[r][c]) : void();
                c = (r % 2 == 0) ? c + 1 : c - 1;
            }
            r++;
        }
        return o;
    }
};