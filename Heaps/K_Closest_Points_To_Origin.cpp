/* https://leetcode.com/problems/k-closest-points-to-origin/

Question:- We have a list of points on the plane.  Find the K closest points to the origin (0, 0).
(Here, the distance between two points on a plane is the Euclidean distance.)
You may return the answer in any order.  The answer is guaranteed to be unique (except for the order that it is in.)

Approach:- 
As we have to find the k closest points so we will calculate the distance of point from origin using distance formula and for closest point , the distance should be minimum
so we will make a maximum heap for it and we will take a pair in it and we will take the distance as its first and the points as its second.

*/

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>>ans;
        priority_queue<pair<int,int> >q;
        
        for(int i = 0,n = points.size(); i < n; ++i)
        {
            q.push({points[i][0]*points[i][0] + points[i][1]*points[i][1], i } );
            
            if(i+1 > K)
                q.pop();
        }
        
        while(!q.empty())
        {
            ans.push_back({points[q.top().second][0], points[q.top().second][1]});
            q.pop();
        }
        
        return ans;
    }
};