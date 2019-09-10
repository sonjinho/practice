#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<int> q;
 
    int sum=0;
    int count=0; 
    
    for(int i=0; i<truck_weights.size(); i++) {
        int truck_weight = truck_weights[i];
 
        while (true) {
 
            if (q.empty()) {
                q.push(truck_weight);
                count++;
                sum += truck_weight;
                break;
            }
            else if (q.size() == bridge_length) {
                sum -= q.front(); q.pop();
            }
            else {
 
                if (sum + truck_weight > weight) {
                    q.push(0);
                    count++;
                }
                else {
                    q.push(truck_weight);
                    count++;
                    sum += truck_weight;
                    break;
                }
            }
        }
    }
    
    return count + bridge_length;
}