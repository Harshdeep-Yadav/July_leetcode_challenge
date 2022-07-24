class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==target)
                    return true;
            }
        }
        return false;
    }
};
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i=0;
        int j=matrix[0].size()-1;
        int m =matrix.size();
        while(i<m&&j>=0)
        {
            if(matrix[i][j]==target)
                return true;
            if(matrix[i][j]<target){
                i++;
            }
            else
                j--;
        }
        return false;
    }
};