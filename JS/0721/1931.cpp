
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

bool cmpSecond(pair<int, int> a, pair<int, int> b){
    if(a.second > b.second){
        return a.second<b.second;
    }else{
        return a.second<b.second;
    }
}

int main(){
    vector<pair<int, int>> times;
    int N;
    cin >> N;
    
    int f,s;
    for(int i=0; i<N; i++){
        cin>>f>>s;
        times.push_back(make_pair(f, s));
    }
    sort(times.begin(), times.end());
    sort(times.begin(), times.end(), cmpSecond);
    
    int min = times[0].second;
    int count = 1;
    for(int i=1; i<N; i++){
        if(times[i].first>=min){
            min = times[i].second;
            count++;
        }
    }
    
    cout<<count<<endl;
    return 0;
}
