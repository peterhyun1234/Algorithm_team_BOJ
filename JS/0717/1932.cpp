#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    int d[501][501]={0,};
    vector<vector<int>> triangle;
    for(int i=0; i<n; i++){
        vector<int> row;
        int num;
        for(int j=0; j<i+1; j++){
            cin>>num;
            row.push_back(num);
        }
        triangle.push_back(row);
    }
    
    d[0][0] = triangle[0][0];
    for(int i=1; i<n; i++){
        d[i][0] =d[i-1][0]+triangle[i][0];
    }
    for(int i=1; i<n; i++){
        d[i][i] =d[i-1][i-1]+triangle[i][i];
    }
    
    
    for(int i=2; i<n; i++){
        for(int j=1;j<i; j++){
            d[i][j] = max(d[i-1][j-1] + triangle[i][j], d[i-1][j]+triangle[i][j]);
        }
    }
    int max=-1;
    for(int i=0; i<n; i++){
        if(max<d[n-1][i])max = d[n-1][i];
    }
    
    cout<<max;
    return 0;
}
