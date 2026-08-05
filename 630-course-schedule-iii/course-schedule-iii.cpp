class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int n=courses.size();
        sort(courses.begin(),courses.end(),[&](const vector<int>&a,vector<int>&b){
            return a[1]<b[1];
        });
        priority_queue<int>pq;
        int t=0;
        for(int i=0;i<n;i++){
            if(t+courses[i][0]<=courses[i][1]){
                pq.push(courses[i][0]);
                t +=courses[i][0];
            }else if(!pq.empty() && pq.top()>courses[i][0]){
                t-=pq.top();
                t+=courses[i][0];
                pq.pop();
                pq.push(courses[i][0]);
            }
        }
        return pq.size();
    }
};