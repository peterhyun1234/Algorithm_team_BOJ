#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>

using namespace std;

struct truck {
    int time, weight;
    truck (int a, int b) {
        time = a;
        weight = b;
    }
};

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0, truck_num = truck_weights.size();
    vector<truck> crossed_trucks;
    deque<truck> crossing_trucks;
    queue<truck> trucks;

    for (int i = 0; i < truck_num; i ++) {
        trucks.push(truck(bridge_length, truck_weights[i]));
    }

    while(crossed_trucks.size() != truck_num) {
        answer ++;
        int now_weight = 0;

        for (int i = 0; i < crossing_trucks.size(); i ++) {
            now_weight += crossing_trucks[i].weight;
            crossing_trucks[i].time --;
        }

        if (!crossing_trucks.empty() && crossing_trucks.front().time <= 0) {
            now_weight -= crossing_trucks.front().weight;
            crossed_trucks.push_back(crossing_trucks.front());
            crossing_trucks.pop_front();
        }

        if (!trucks.empty() && now_weight + trucks.front().weight <= weight) {
            crossing_trucks.push_back(trucks.front());
            trucks.pop();
        }

    }

    return answer;
}
