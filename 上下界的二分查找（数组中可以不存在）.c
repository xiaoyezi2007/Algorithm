int lower_bound(int l, int r, int key) //下界二分查找（找出第一个值不小于key的位置），建议l填区间左端点，r填区间右端点
{
    while(l < r) //条件为小于而非小于等于
    {
        int mid = l + (r - l) / 2;
        if(a[mid] >= key) r = mid; //此处为大于等于
        else l = mid + 1; //此处必须要+1
    }
    return l;
}
int upper_bound(int l, int r, int key) //上界二分查找（找出第一个值大于key的位置）
{
    while(l < r)
    {
        int mid = l + (r - l) / 2;
        if(a[mid] > key) r = mid; //与下界二分查找几乎完全相同，仅有此处需修改为大于
        else l = mid + 1;
    }
    return l;
}
//如果上下界相同则可判定数字不存在于数组中
