#include <iostream>

#define MAX_N 100
#define MAX_SUM 20

#define PLUS 1
#define MINUS -1

using namespace std;

int N;
long long count = 0;
int nums[MAX_N];
// dp[sum][index]: nums[0-index] 까지의 계산결과가 sum일 때, 올바른 등식의 개수
// dp[sum][index] == -1이면 아직 계산되지 않은 경우
// dp[sum][index] == 0이면 가능한 등식이 생성 안 되는 경우
long long dp[MAX_SUM+1][MAX_N]; 

long long dfs(int index, int op, int result){
	long long ret;
	result += nums[index] * op;

	if(result < 0 || result > 20) return -1;

	if(index == N-2){
		if(result == nums[N-1]) return 1;
		else return -1;
		
	}
	else{
		if(dp[result][index] < 0){
			ret = dfs(index+1, PLUS, result);
			if(ret > 0) dp[result][index] += ret;
			ret = dfs(index+1, MINUS, result);
			if(ret > 0) dp[result][index] += ret;

			if(dp[result][index] < 0) dp[result][index] = 0;
			else dp[result][index]++;
		}
		return dp[result][index];
	}

}


int main(){
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> nums[i];
	}

	for (int i = 0; i <= MAX_SUM; i++)
	{
		for (int j = 0; j < MAX_N; j++)
		{
			dp[i][j] = -1;
		}
	}

	dfs(0, PLUS, 0);

	cout << dp[nums[0]][0];
	return 0;
}