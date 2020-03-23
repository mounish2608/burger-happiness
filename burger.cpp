#include<iostream>
#include<map>
using namespace std;
int main(){
  int N;
  cin>>N;
  int X[100000],A[100000],B[100000];
  map<int,int> m;
  for(int i=0;i<N;i++){
    cin>>X[i]>>A[i]>>B[i];
    m[X[i]]=i;
  }
  map<int,int> dp;
  for(int i=0;i<N;i++)
    {
        dp[X[i]]=A[i];
        auto it=dp.find(X[i]);
        int l=0;
        map<int,int>::iterator itrr;
        for(itrr=dp.begin();itrr!=dp.end();itrr++)
        {
            if(it==dp.begin())
            {
                break;
            }
            it--;
            l+=B[m[it->first]];
            dp[X[i]]=max(dp[X[i]],it->second-l+A[i]);
        }
        it=dp.find(X[i]);
        int r=0;
        for(itrr=dp.begin();itrr!=dp.end();itrr++)
        {
            it++;
            if(it==dp.end())
            {
                break;
            }
            r+=B[m[it->first]];
            dp[X[i]]=max(dp[X[i]],it->second-r+A[i]);
        }
    }
    int ans=0;
    for(auto e:dp)  //for (range_declaration:range_expression)
    {
        ans=max(ans,e.second);
    }
    cout<<ans<<endl;
}
