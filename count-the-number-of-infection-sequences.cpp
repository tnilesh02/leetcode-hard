class Solution {

    int power(int x, int y, int p)
    {   
        if(x <=1)return 1;
        // Initialize answer
        int res = 1;
    
        // Check till the number becomes zero
        while (y > 0) {
    
            // If y is odd, multiply x with result
            if (y % 2 == 1)
                res = (1LL* res * x)%p;
    
            // y = y/2
            y = y >> 1;
    
            // Change x to x^2
            x = (1LL * x * x)%p;
        }
        return res % p;
    }

public:
    int numberOfSequence(int n, vector<int>& sick) {
        int m = 1000000007;
        int f[n+1];
        f[0]=1;
        f[1] = 1;
        int po[n+1];
        po[0]=1;
        po[1]=2;
        for (int i=2; i<=n; ++i)
	    { 
            f[i] = (1LL*f[i-1]*i)%m;
            po[i] = (1LL*po[i-1]*2)%m;
        }


        int ans = f[n - sick.size()];
        //cout<<ans<<endl;
        for(int i=0;i<sick.size();i++){
            if(i == 0){
                ans = (1LL* ans * power(f[sick[i]],m-2,m))%m;
                //cout<<ans<<" r"<<endl;
            }
            else {
                ans = (1LL* ans * power(f[sick[i]-sick[i-1]-1],m-2,m))%m;
                //cout<<ans<<" r"<<endl;
                int x = sick[i] - sick[i-1] - 2;
                if(x>=1)ans = (1LL* ans * po[x])%m;
                //cout<<ans<<" p"<<endl;
            }

            if(i == (sick.size() - 1)){
                ans = (1LL * ans * power(f[n-1-sick[i]],m-2,m))%m;
                //cout<<ans<<" r"<<endl;
            }
        }
        return ans;
    }
};