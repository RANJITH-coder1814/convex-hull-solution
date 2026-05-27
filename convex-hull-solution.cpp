class Solution {
public:
    
    int crossProduct(vector<int>& O, vector<int>& A, vector<int>& B) {
        return (A[0] - O[0]) * (B[1] - O[1]) -
               (A[1] - O[1]) * (B[0] - O[0]);
    }

    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        
        int n = trees.size();

        if(n <= 3) return trees;

        sort(trees.begin(), trees.end());

        vector<vector<int>> hull;

        // Lower Hull
        for(auto &p : trees) {

            while(hull.size() >= 2 &&
                  crossProduct(hull[hull.size()-2],
                               hull[hull.size()-1],
                               p) < 0) {
                hull.pop_back();
            }

            hull.push_back(p);
        }

        int lowerSize = hull.size();

        // Upper Hull
        for(int i = n - 2; i >= 0; i--) {

            while(hull.size() > lowerSize &&
                  crossProduct(hull[hull.size()-2],
                               hull[hull.size()-1],
                               trees[i]) < 0) {
                hull.pop_back();
            }

            hull.push_back(trees[i]);
        }

        // Remove duplicate points
        set<vector<int>> uniquePoints(hull.begin(), hull.end());

        return vector<vector<int>>(uniquePoints.begin(), uniquePoints.end());
    }
};
