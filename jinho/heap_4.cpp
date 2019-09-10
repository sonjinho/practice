#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;
 
vector<int> solution(vector<string> operations) {

    vector<int> answer;
    deque<int> dq;
    for (int i = 0 ; i <operations.size(); i++) {
        
        string str= operations[i];
                
        if (str == "D 1") {
            if (!dq.empty()) dq.pop_back();     
        }
        else if (str == "D -1") {
            if (!dq.empty()) dq.pop_front();    
        }
        else {
            int t = stoi(str.substr(2));
            dq.push_back(t);  
            sort(dq.begin(), dq.end()); 
        }
    }

    
    if(dq.empty())
    {
       answer.push_back(0);
       answer.push_back(0);

    }else
    {
        answer.push_back(dq.back());
        answer.push_back(dq.front());
        
    }
    return answer;
}