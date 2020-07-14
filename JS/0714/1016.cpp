#include <iostream>
#include <cmath>

using namespace std;


long long jegob[10000002]={0,};
bool jegobnono[10000002]={false,};
int main(){
    long long minimum, maximum;
    cin >> minimum >> maximum;
    
    long long max_sq = sqrt(maximum);
    
    long long jegobCount = 0;
    for(long long i=2; i<=max_sq; i++){
        jegob[i] = i*i;
        jegobCount++;
    }

    for(long long i = 2; i<=jegobCount+1; i++){
        long long temp = minimum;
        if(temp%jegob[i] !=0){
            temp = (minimum/jegob[i] +1)*jegob[i];
        }
        for(long long j =temp; j<=maximum; j+=jegob[i]){
            if(jegobnono[j - minimum] == false){
                jegobnono[j - minimum] = true;
            }
        }
    }
    
    long long jegobnonoCount = 0;
    for(long long i=0; i<=maximum-minimum; i++){
        if(jegobnono[i] == false)jegobnonoCount++;
    }
    
    cout <<jegobnonoCount;
    
    return 0;
}
