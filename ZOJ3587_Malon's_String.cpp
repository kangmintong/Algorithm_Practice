#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long lld;
const int maxn = 100001;
int n,m;
char a[maxn],b[maxn];
int p[maxn],cnt[maxn],cnt2[maxn];
void getp(){
    p[1]=0;
    int i,j=0;
    for(i=2;i<=m;i++){
        while(j>0&&b[j+1]!=b[i]) j=p[j];
        if(b[j+1]==b[i]) j+=1;
        p[i]=j;
    }
}
void kmp(int cnt[])
{
    int i,j=0;
    for(i=1;i<=n;i++){
        while(j>0&&b[j+1]!=a[i]) j=p[j];
        if(b[j+1]==a[i]) j+=1,cnt[j]++;
        if(j==m)    j=p[j];
    }
	for(i=m;i>=1;i--){
		if(p[i]!=0) cnt[p[i]]+=cnt[i];
	}
}
void RE(char s[]){
	int len=strlen(s+1);
	for(int i=1;i<=len/2;i++){
		swap(s[i],s[len-i+1]);
	}
}
lld solve()
{
	lld ans=0;
	for(int i=1;i<=m;i++)
		ans+=(lld)cnt[i]*cnt2[m-i];
	return ans;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
    {
		scanf("%s",a+1);
		scanf("%s",b+1);
        m=strlen(b+1);
        n=strlen(a+1);
 
		memset(cnt,0,sizeof(cnt));
        getp();
        kmp(cnt);
 
		RE(a);
		RE(b);
		memset(cnt2,0,sizeof(cnt2));
		getp();
		kmp(cnt2);
		printf("%lld\n",solve());
    }
}


