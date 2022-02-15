#include <bits/stdc++.h>

using namespace std;
using pii=pair<long, long>;

#define MAX 1000001
#define INF 9999999999

vector<pii> vec[MAX];
vector<long> dist(MAX, INF);
long sight[MAX];

long dijkstra(long s, long e){
    priority_queue<pii> pq; pq.push({0, s});
    dist[s]=0;
    
    while(!pq.empty()){
        pii t=pq.top(); 
        pq.pop();
        long c=t.second; 
        long d=t.first*-1;
        
        // 시간초과를 방지하기 위해 최소 가중치의 합이 구해진 경우엔 스킵한다. 
        if(dist[c]<d) continue;
        
        for(int i=0; i<vec[c].size(); i++){
            long nxt = vec[c][i].first;
            long nxt_d = vec[c][i].second + d;
            
            // 시야에 보이면서 마지막 분기점이 아닌 경우 지나칠 수 없다.
            // 마지막 분기점은 상대 넥서스이므로 유일하게 지나칠 수 있기때문에 e-1일 때는 계산한다.
            if(sight[nxt] == 1 && nxt!=e-1) continue;
            
            if(nxt_d<dist[nxt]){
                dist[nxt]=nxt_d;
                pq.push({nxt_d*-1, nxt});
            }
        }
    }
    
    return dist[e-1];
    
}
int main(){
    // 분기점과 길의 수 입력
    long N, M; 
    cin>>N>>M;
    for(int i=0; i<N; i++) cin>>sight[i];
    
    // 각 분기점과 분기점 사이를 지나는 시간 입력
    while(M--){
        long a, b, t; cin>>a>>b>>t;
        vec[a].push_back({b, t});
        vec[b].push_back({a, t});
    }
    
    // 다익스트라를 통해 상대 넥서스(N-1번째 분기점)까지 들키지 않고 가는데 걸리는 최소 시간을 출력해주는데, 
    // 상대 넥서스까지 갈 수 없는 경우엔 -1을 출력
    long ans=dijkstra(0, N);
    if(ans>=INF) cout<<-1;
    else cout<<ans;

    return 0;
}
