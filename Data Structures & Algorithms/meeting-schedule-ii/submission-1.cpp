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
    static bool comp(const Interval &a, const Interval &b) {
        return a.start < b.start;
    }

    int minMeetingRooms(vector<Interval>& intervals) {
        if (intervals.empty()) return 0;

        sort(intervals.begin(), intervals.end(), comp);

        priority_queue<int, vector<int>, greater<int>> pq;

        for (auto &it : intervals) {
            if (!pq.empty() && pq.top() <= it.start)
                pq.pop();

            pq.push(it.end);
        }

        return pq.size();
    }
};