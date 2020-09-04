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
map<string, int> genres_cnt;

bool cmp(song a, song b){
    if(genres_sum[a.genre] > genres_sum[b.genre])
        return true;
    else if (genres_sum[a.genre] == genres_sum[b.genre]) {
        if(a.play > b.play)
            return true;
        else if (a.play == b.play) {
            if (a.idx < b.idx)
                return true;
            else
                return false;
        } else
            return false;
    } else
        return false;
}


vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    vector<song> songs;
    for(int i = 0; i < genres.size(); i++){
        songs.push_back({genres[i], plays[i], i});
    }

    for(int i = 0; i < genres.size(); i++){
        genres_sum[genres[i]] += plays[i];
        genres_cnt[genres[i]] += 1;
    }

    sort(songs.begin(), songs.end(), cmp);

    for (int i = 0; i < songs.size(); i ++) {
        if (genres_cnt[songs[i].genre] == 1) {
            answer.push_back(songs[i].idx);
            genres_cnt[songs[i].genre] = 0;
        } else if (genres_cnt[songs[i].genre] >= 2) {
            answer.push_back(songs[i].idx);
            answer.push_back(songs[i + 1].idx);
            genres_cnt[songs[i].genre] = 0;
            i ++;
        } else
            continue;
    }

    return answer;
}
