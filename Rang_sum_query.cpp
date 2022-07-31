class NumArray {
public:
    NumArray(vector<int> &nums) {
        sz = nums.size();
        num = vector<int>(sz+1, 0);
        sum = vector<int>(sz+1, 0);
        for(int i=0; i<sz; i++) {
            update(i, nums[i]);
        }
        
    }

    void update(int idx, int val) {
        int oldv = num[idx+1];
        for(int i = idx+1; i<=sz; i+= (i&-i)) {
            sum[i] = sum[i] - oldv + val;
        }
        num[idx+1] = val;
    }

    int sumRange(int i, int j) {
        return getSum(j+1) - getSum(i);
    }
    
    int getSum(int idx) {
        int ret = 0;
        for(int i=idx; i>0; i-=(i&-i)) {
            ret += sum[i];
        }
        return ret;
    }
private :
    int sz;
    vector<int> num;
    vector<int> sum;
};