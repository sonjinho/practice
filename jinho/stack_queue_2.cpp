#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;
    for(int i = 0 ; i < heights.size() ; i++)
    {
        int result =0;
        int c = heights[i];
        for(int j = i ; j >=0; j--)
        {
            if(c<heights[j])
            {
                result = j+1;
                break;
            }
        }
        answer.push_back(result);
    }
    
    return answer;
}