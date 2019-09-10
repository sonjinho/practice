#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    for(int i = 0 ; i < prices.size() ; i++)
    {
        int c = prices[i];
        int count = 0;
        for(int j = i+1; j <prices.size(); j++)
        {
            if(c > prices[j])
            {
                c = prices[j];  
                count++;
                break;
            }else if (c <=prices[j])
            {
                count++;
            }
        }
        answer.push_back(count);
    }
    return answer;
}