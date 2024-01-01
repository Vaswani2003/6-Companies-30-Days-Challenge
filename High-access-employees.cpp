/*
2933. High-Access Employees

You are given a 2D 0-indexed array of strings, access_times, with size n. For each i where 0 <= i <= n - 1, access_times[i][0] represents the name of an employee, and access_times[i][1] represents the access time of that employee. All entries in access_times are within the same day.

The access time is represented as four digits using a 24-hour time format, for example, "0800" or "2250".

An employee is said to be high-access if he has accessed the system three or more times within a one-hour period.

Times with exactly one hour of difference are not considered part of the same one-hour period. For example, "0815" and "0915" are not part of the same one-hour period.

Access times at the start and end of the day are not counted within the same one-hour period. For example, "0005" and "2350" are not part of the same one-hour period.

Return a list that contains the names of high-access employees with any order you want.

*/

class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        unordered_map<string, vector<int>> map;
        vector<string> ans;
        int time, i;

        for(auto& it : access_times){
            time = stoi(it[1]);
            map[it[0]].push_back(time);
        }

        for(auto& it: map){
            sort(it.second.begin(), it.second.end());
        }

        for(auto& it: map){
            vector<int>& times = it.second;
            for(i = 2; i < times.size();i++){
                if(times[i-2] + 99 >= times[i]){
                    ans.push_back(it.first);
                    break;
                }
                    }
            }
        
        return ans;
    }
};
