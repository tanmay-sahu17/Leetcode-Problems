class Solution {
public:

bool check(long long mid,int mountainHeight,vector<int>& workerTimes){
    long long h=0;
    for(auto t:workerTimes){
     h+=(-1 + sqrt(1 + (8.0 * mid) / t)) / 2;
     if(h>=mountainHeight)return true;
    }
    return h>= mountainHeight;

}
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long maxele=*max_element(workerTimes.begin(),workerTimes.end());

        long long l=1;
        long long r=maxele*(1LL*mountainHeight*(mountainHeight+1)/2);
        long long result=INT_MAX;

        while(l<=r){
            long long mid=l+(r-l)/2;
            if(check(mid,mountainHeight,workerTimes)){
              result=mid;
              r=mid-1;
            }
            else l=mid+1;
                    }
        return result;
    }
};