class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {       
        vector<vector<int>> ret;
        int i = 0;
        
        while (i < intervals.size() && newInterval[0] > intervals[i][1]) {
            ret.push_back(intervals[i]);
            i++;
        }
        
        while (i < intervals.size() && newInterval[1] >= intervals[i][0]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        ret.push_back(newInterval);
        
        while (i < intervals.size()) {
            ret.push_back(intervals[i]);
            i++;
        }
        
        return ret;
    
    }
};
