int st[400020];
void insertit(int val,int i,int ind,int low,int high)
{
    if(low>high)
    {
        return ;
    }
    if(low==high)
    {
        st[ind]=val;
        return ;
    }
    int mid=(low+high)>>1;
    if(i<=mid)
    {
        insertit(val,i,ind*2,low,mid);
    }
    else
    {
        insertit(val,i,(ind*2)+1,mid+1,high);
    }
    st[ind]=max(st[ind*2],st[(ind*2)+1]);
}
int query(int ind,int low,int high,int ql,int qh)
{
    if(low>qh || high<ql || low>high)
    {
        return INT_MIN;
    }
    if(ql<=low && qh>=high)
    {
        return st[ind];
    }
    int mid=(low+high)>>1;
    if(ql>mid)
    {
        return query(ind*2+1,mid+1,high,ql,qh);
    }
    else if(qh<=mid)
    {
        return query((ind*2),low,mid,ql,qh);
    }
    else
    {
        return max(query(2*ind,low,mid,ql,qh),query(2*ind+1,mid+1,high,ql,qh));
    }
}
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        int i;
           vector <int> ans;
        if(k==0)
        {
            return ans;
        }
        
        for(i=0;i<=n*4;i++)
        {
        st[i]= INT_MIN;
        }
        for(i=0;i<n;i++)
        {
            insertit(nums[i],i+1,1,1,n);
        }
        int l=1,r=k;
        /*for(i=1;i<=4*n;i++)
        {
            printf("%d ",st[i]);
        }*/
        for(;r<=n;r++,l++)
        {
            ans.push_back(query(1,1,n,l,r));
        }
        return ans;
    }
};