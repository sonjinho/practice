#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string arrangement) {
    int answer = 0;
    stack<char> s;
    int counter = 0 ;
    for (int i = 0; i < arrangement.size(); i++)
	{
        if (arrangement[i] == '(')
        {
		    s.push(arrangement[i]);
            counter = 0;
        }
        else{
            s.pop();
            if(counter == 0)
            {
                answer+=s.size();
            }else if(counter>0){
                
                answer+=1;
            }
            counter++;
                
        }
	}
    return answer;
}