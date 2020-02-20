#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    multimap<string,int> m;
    
    for (int i =0; i < participant.size();i++)
    {
        m.insert(make_pair(participant[i],i));
    }
    
    for (int j =0; j < completion.size(); j++)
    {
        m.erase(m.find(completion[j]));
    }
    
    multimap<string,int>::iterator it;
    for (it = m.begin();it != m.end();it++)
    {
        answer = it->first;
    }
    //commit
    return answer;
    // return answer;
}