class Solution{
public:
 int minMoves(vector<string>&g,int E){
  int m=g.size(),n=g[0].size(),k=0,x,y;
  vector<vector<int>>z(m,vector<int>(n));
  for(int i=0;i<m;i++)for(int j=0;j<n;j++){
   if(g[i][j]=='S')x=i,y=j;
   if(g[i][j]=='L')z[i][j]=k++;
  }
  int f=(1<<k)-1,N=(1<<k);
  vector<char>v(m*n*(E+1)*N);
  queue<array<int,4>>q;
  auto id=[&](int a,int b,int c,int d){
   return (((a*n+b)*(E+1)+c)*N+d);
  };
  q.push({x,y,E,f});
  v[id(x,y,E,f)]=1;
  int answer=0,dx[]={1,-1,0,0},dy[]={0,0,1,-1};
  while(q.size()){
   int h=q.size();
   while(h--){
    auto [a,b,c,d]=q.front();q.pop();
    if(!d)return answer;
    if(!c&&g[a][b]!='R')continue;
    if(g[a][b]=='R')c=E;
    for(int i=0;i<4;i++){
     int x=a+dx[i],y=b+dy[i];
     if(x<0||x>=m||y<0||y>=n||g[x][y]=='X')continue;
     int e=c-1,f=d;
     if(g[x][y]=='R')e=E;
     if(g[x][y]=='L')f&=~(1<<z[x][y]);
     if(v[id(x,y,e,f)])continue;
     v[id(x,y,e,f)]=1;
     q.push({x,y,e,f});
    }
   }
   answer++;
  }
  return -1;
 }
};