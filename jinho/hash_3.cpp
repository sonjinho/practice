#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
	int value = 0;
	vector<int> temp;
	map<string, int> hash;
	for (int i = 0; i < clothes.size(); i++) {
			hash[clothes[i][1]]++;		
	}
    answer =1;
	for(map<string, int>::iterator ihash=hash.begin(); ihash != hash.end();ihash++)
    {
        answer = answer*(ihash->second+1);
    }
    return answer -1;

	
}