#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> c;
    for(int i = 0 ; i < progresses.size() ; i++)
    {
        int result = progresses[i] ;
        int count = 0;
        while(result<100)
        {
            result +=speeds[i];
            count++;
        }
        
        c.push(count);
    }
    int counter =1;
    int current = c.front();
    c.pop();
    while(!c.empty())
    {
        if(c.front() <= current)
        {
            c.pop();
            counter++;
        }else{
            answer.push_back(counter);
            counter =1;
            current = c.front();
            c.pop();
        }
    }
    
	answer.push_back(counter);


    return answer;
}