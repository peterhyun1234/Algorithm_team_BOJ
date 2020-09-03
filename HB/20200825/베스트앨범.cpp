// 장르 별로 가장 많이 재생된 노래를 두 개씩 모아 베스트 앨범을 출시
// 속한 노래가 많이 재생된 장르를 먼저 수록합니다.
// 장르 내에서 많이 재생된 노래를 먼저 수록합니다.
// 장르 내에서 재생 횟수가 같은 노래 중에서는 고유 번호가 낮은 노래
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct song{
    string genre;
    int play;
    int idx;
};

map<string, int> genres_sum;

bool cmp(song a, song b){
    if(genres_sum[a.genre] > genres_sum[b.genre]){
        return true;
    }else{
        if(a.genre == b.genre){
            if(a.play > b.play){
                return true;
            }else{
                return false;
            }
        }else{
            return false;
        }
    }
}


vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    vector<song> songs;
    for(int i = 0; i < genres.size(); i++){
        songs.push_back({genres[i], plays[i], i});
    }
    
    for(int i = 0; i < songs.size(); i++){
        genres_sum[songs[i].genre] += songs[i].play;
    }
    
    /*for(auto it = genres_sum.begin(); it != genres_sum.end(); it++){
        cout << "key : " << it->first << " " << "value : " << it->second << '\n';
    }*/
    
    sort(songs.begin(), songs.end(), cmp);
    
    int second_cnt = 2;
    for(int i = 0; i < songs.size()-1; i++){
        
        if(second_cnt == 0) continue;
        
        if(songs[i].genre != songs[i + 1].genre) {
            answer.push_back(songs[i].idx);
            second_cnt = 2;
            continue;
        }
        
        answer.push_back(songs[i].idx);
        second_cnt--;
    }
    return answer;
}