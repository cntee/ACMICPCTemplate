#include<string.h>
#include<stdio.h>
#define N 1050
int boy[N][N];
int girl[N][N];
int ans[N];
int cur[N];
int n;
void getMarry(int g) {
  for (int i=ans[g]+1; i<n; i++) {
    int b=girl[g][i]-1;
    if (cur[b]<0) {
      ans[g]=i;
      cur[b]=g;
      return;
    }
    int og=cur[b];
    if (boy[b][og] > boy[b][g]) {
      cur[b]=g;
      ans[g]=i;
      getMarry(og);
      return;
    }
  }
};
int main() {
  int t,a;
  scanf("%d",&t);
  while(t--) {
    memset(girl,0,sizeof(girl));
    memset(boy,0,sizeof(boy));
    scanf("%d",&n);
    for (int i=0; i<n; i++)
      for (int j=0; j<n; j++)
        scanf("%d",&girl[i][j]);
    for (int i=0; i<n; i++)
      for (int j=0; j<n; j++) {
        scanf("%d",&a);
        boy[i][a-1]=j;
      }
    memset(cur,0xff,sizeof(cur));
    memset(ans,0xff,sizeof(ans));
    for (int i=0; i<n; i++)
      getMarry(i);
    for (int i=0; i<n; i++)
      printf("%d\n",girl[i][ans[i]]);
  }
  return 0;
}

