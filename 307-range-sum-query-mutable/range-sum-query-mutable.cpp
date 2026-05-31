class NumArray
{
public:
    vector<int> segment;
    int n;
    NumArray(vector<int> &nums)
    {
        segment.resize(4 * nums.size());
        n = nums.size();
        buildTree(nums,0,0,n-1);
    }
    void buildTree(vector<int> &nums, int i, int l, int r)
    {
        if (l == r)
        {
            segment[i] = nums[l];
            return;
        }
        int mid = (l + r) / 2;
        buildTree(nums, 2 * i + 1, l, mid);
        buildTree(nums, 2 * i + 2, mid+1, r);
        segment[i] = segment[2 * i + 1] + segment[2 * i + 2];
        return;
    }
    void update(int index,int val){
        update2(index,val,0,0,n-1);
    }
    void update2(int index, int val, int i, int l, int r)
    {
        if (l == r && l == index)
        {
            segment[i] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (index <= mid)
            update2(index, val, 2 * i + 1, l, mid);
        else
            update2(index, val, 2 * i + 2, mid+1, r);
        segment[i] = segment[2 * i + 1] + segment[2 * i + 2];
    }
    int sumRange(int left,int right){
        return sumRange2(left,right,0,n-1,0);
    }
    int sumRange2(int left, int right, int l, int r, int i)
    {
        if (l > right || r < left)
            return 0;
        if (l >= left && r <= right)
            return segment[i];
        int mid = (l + r) / 2;
        return sumRange2(left, right, l, mid, 2 * i + 1) + sumRange2(left, right, mid+1,r, 2 * i + 2);
    }
};
