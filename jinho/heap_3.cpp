#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

struct Compare
{
    bool operator()(const vector<int> lhs, const vector<int> rhs)
    {
        return lhs[1] > rhs[1];
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    priority_queue<int,vector<vector<int>>, Compare> pq;
    sort(jobs.begin(),jobs.end(),[](vector<int> a, vector<int> b){return a[0]<b[0];});
    int i = 0;
    int w = 0; 
    int task = 0;
    vector<int> temp;
    int total = 0;
    while(true)
    {
        while (i!=jobs.size()) {
			if (jobs[i][0] == w)
			{
				pq.push(jobs[i]);
				i++;
			}
			else 
                break;
		}
        if ( !pq.empty() && task <= 0 )
		{
			temp = pq.top();
			pq.pop();
			task = temp[1];
			total += temp[1];
		}
		
		total += pq.size();
		task--;
		w++;


		if (pq.empty() && task == 0 && i == jobs.size()) {
			break;
		}
    }
    return total/jobs.size();
}