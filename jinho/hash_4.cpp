#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;


vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    vector<string> u = genres;
    vector<pair<int,string>> f;
    map<string,int> m;
    
    
    for(int i = 0 ; i < genres.size(); i++)
    {
        m[genres[i]] += plays[i];
    }
    
    for(auto it = m.begin(); it != m.end(); it++){
        f.push_back(make_pair(it->second,it->first));
	}
    
    sort(f.begin(),f.end(),[](pair<int,string> p1, pair<int,string> p2){return p1.first>p2.first;});
    
    for(int i = 0 ; i < f.size() ; i++ )
    {

        int max1=0;
        int max2=0;
        int num1=-1;
        int num2=-1;
        
        for(int j = 0 ; j <plays.size() ; j++)
        {
            if(f[i].second == genres[j])
            {
                if(max1<plays[j])
                {
                    max2 = max1;
                    num2 = num1;
                    max1 = plays[j];
                    num1 = j;
                }else if (max1==plays[j])
                {
                    max2 = plays[j];
                    num2 = j;
                }
                else if (max2 < plays[j])
                {
                    max2 = plays[j];
                    num2 = j;
                }
            }    
        }
        answer.push_back(num1);
        if(num2 != -1)
            answer.push_back(num2);
    }

    return answer;
}