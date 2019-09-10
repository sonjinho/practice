#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> T ;
    for(int i = 0 ; i< numbers.size(); i++)
    {
        T.push_back(to_string(numbers[i]));
    }
    sort(T.begin(),T.end(),[](string t1, string t2)
         {
            return t1+t2>t2+t1;   
         });
    for(int i = 0 ; i< numbers.size(); i++)
    {
        answer+=T[i];
    }
    if(T[0]==to_string(0))
    {
        return "0";
    }
    return answer;
}