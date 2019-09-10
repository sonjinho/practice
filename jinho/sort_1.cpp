#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for (int i = 0; i < commands.size() ; i++)
    {
        vector<int> type;

        for(int j = commands[i][0];  j <= commands[i][1] ; j++)
        {
            type.push_back(array[j-1]);
        }
        sort(type.begin(),type.end());
        
        answer.push_back(type[commands[i][2]-1]);
    }
    return answer;
}