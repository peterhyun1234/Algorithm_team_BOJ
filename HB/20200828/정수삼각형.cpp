#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    int dp[500][500];
    int n = triangle.size();
    
    for(int i = 1; i < n; i++){
        for(int j = 0; j < triangle[i].size(); j++){
            if(j == 0){
                triangle[i][j] = triangle[i][j] + triangle[i-1][j];
            }else if(j == triangle[i].size() - 1){
                triangle[i][j] = triangle[i][j] + triangle[i-1][j-1];
            }else{
                triangle[i][j] += max(triangle[i-1][j], triangle[i-1][j-1]);
            }
        }
    }
    
    answer = *max_element(triangle[n-1].begin(), triangle[n-1].end());
    
    return answer;
}