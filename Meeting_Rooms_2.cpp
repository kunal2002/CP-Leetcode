/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: the minimum number of conference rooms required
     */
    int minMeetingRooms(vector<Interval> &intervals) {
        // Write your code here
        vector<int> inp, out;
        for(auto x: intervals)
        {
            inp.push_back(x.start);
            out.push_back(x.end);
        }
        sort(inp.begin(), inp.end());
        sort(out.begin(), out.end());
        int best = -1, cnt = 0;
        int sz = intervals.size(), i = 0, k = 0;
        while(i < sz && k < sz)
        {
            if(inp[k] < out[i])
            {
                cnt++;
                best = max(best, cnt);
                k++;
            }
            else
            {
                cnt--;
                i++;
            }   
        }
        return best;
    }
};
