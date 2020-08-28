from collections import defaultdict
import heapq
def solution(genres, plays):
    ans = []
    n = len(plays)
    genres_plays = defaultdict(int)
    genres_music = defaultdict(list)
    for i in range(n):
        g, p = genres[i], plays[i]
        genres_plays[g] += p
        heapq.heappush(genres_music[g], [-p,i])
    for g, _ in sorted(genres_plays.items(), key=lambda x: x[1], reverse=True):
        tmp1 = 0
        if genres_music[g]:
            tmp1 = heapq.heappop(genres_music[g])
            ans.append(tmp1[1])
        if genres_music[g]:
            tmp1 = heapq.heappop(genres_music[g])
            ans.append(tmp1[1])
    
    return ans