#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(vector<int> p, int location) {
    int answer = 0;
    deque<pair<int,int>> s;
    deque<int> sorted_p;
    for(int i = 0; i <p.size() ;i++)
    {
        if(i==location)
            s.push_back(make_pair(p[i],1));
        else
            s.push_back(make_pair(p[i],0));
        sorted_p.push_back(p[i]);
    }
    
    sort(sorted_p.begin(),sorted_p.end(),[](int a, int b){return a>b;});
    while(true)
    {
        if(s.front().second == 1)
        {
            if(s.front().first>=sorted_p.front())
            {
                answer++;
                break;
            }else{
                s.push_back(s.front());
                s.pop_front();
            }
        }else if (s.front().second == 0)
        {
            if(s.front().first == sorted_p.front())
            {
                sorted_p.pop_front();
                s.pop_front();
                answer++;
            }else{
                auto t = s.front();
                s.push_back(t);
                s.pop_front();
            }
        }

    }
    
    return answer;
}