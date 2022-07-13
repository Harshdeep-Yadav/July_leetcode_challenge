class Solution { // nahi ata hai bsdke
public:
       bool helper(vector<int>& m,vector<bool>& vis,int target, int curr,int i, int k){
        if(k == 1)
            return true;
        if(curr == target){
            return helper(m,vis,target,0,0,k-1);
        }
         for (int j = i; j < m.size(); j++) {
            if (vis[j] || curr + m[j] > target) 
                continue;
               vis[j] = true;
            if(helper(m,vis,target, curr+m[j], j+1, k))
                 return true;
            vis[j] = false;
    }
        return false;
    }
    
        
    bool makesquare(vector<int>& m) {
        int n = m.size();
        int sum = 0;
        sum = accumulate(m.begin(),m.end(),sum);
        if(n < 4 || sum%4) return false;
        vector<bool>vis(n,false);
       return helper(m,vis,sum/4,0,0,4);
    }
};