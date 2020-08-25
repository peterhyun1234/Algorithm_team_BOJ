#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
// 모든 음식의 스코빌 지수가 K 이상이 될 때
// 가장 맵지 않은 음식의 스코빌 지수 + (두 번째로 맵지 않은 음식의 스코빌 지수 * 2)
// 모든 음식의 스코빌 지수를 K 이상으로 만들기 위해 섞어야 하는 최소 횟수
int solution(vector<int> scoville, int K) {
    int answer;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    
    for(int i =0 ; i < scoville.size(); i ++){
        min_heap.push(scoville[i]);       
    }
    
    int shacking_degree = 0;
    int curr_scovile;

    while(!min_heap.empty()){
        curr_scovile = min_heap.top();
        min_heap.pop();
        
        if(curr_scovile >= K){
            break;
        }else{
            if(!min_heap.empty()){
                int second_scovile = min_heap.top();
                min_heap.pop();
                min_heap.push(curr_scovile + (second_scovile*2));
                shacking_degree++;   
            }
        }
        //cout << curr_scovile << "\n";
    }
    
    if (curr_scovile < K){
        answer = -1;
    }else{
        answer = shacking_degree;
    }
    
    return answer;
}