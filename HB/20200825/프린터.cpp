//중요도가 높은 문서를 먼저 인쇄하는 프린터
#include <string>
#include <vector>

using namespace std;

struct document{
  int priority, idx;
};

vector<document> documents;

bool find_higher_priority(int priority){
    int remain_doc = documents.size();
    for(int i =0; i < remain_doc; i++){
        if(priority < documents[i].priority) return true;
    }
    return false;
}

int solution(vector<int> priorities, int location) {
    int answer = 0;
    vector<int> orders;
    int degree_of_document = priorities.size();
    
    for(int i =0 ; i < degree_of_document; i++)
        documents.push_back({priorities[i], i});
        
    int task_order = 0;
    bool end_flag = false;
    
    while(!end_flag){
        document front_doc = documents.front();
        documents.pop_back();
        
        if(find_higher_priority(front_doc.priority)) {
            documents.push_back(front_doc);
        }else{
            task_order ++;
            if(front_doc.idx == location){
                answer = task_order;
                end_flag = true;
            }
        }
    }
    
    return answer;
}