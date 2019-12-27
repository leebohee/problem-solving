#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

long long dist[1000][1000];
long long islands[1000][2];
int N;
double E;

long long min_tax(){
	double tax = 0.0;
	long long d, min_v, min;
	long long d_vector[1000];
	bool visit[1000] = {false, };

	// compute distance between islands
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(i == j) dist[i][j] = dist[j][i] = LLONG_MAX;
			else{
				d = (islands[i][0]-islands[j][0])*(islands[i][0]-islands[j][0]) + (islands[i][1]-islands[j][1])*(islands[i][1]-islands[j][1]);
				dist[i][j] = dist[j][i] = d;
			}
		}
	}

	// find MST using Prim
	for(int i=0; i<N; i++){ // initialize d_vector
		d_vector[i] = dist[0][i];
	}
	visit[0] = true;
	for(int i=1; i<N; i++){
        min = LLONG_MAX;
		// find min vertex
		for(int j=0; j<N; j++){
			if(!visit[j] && min > d_vector[j]){
				min = d_vector[j];
				min_v = j;
			}
		}
		// add dist to tax
		visit[min_v] = true;
		tax += d_vector[min_v];

		// update d_vector
		for(int j=0; j<N; j++){
			if(d_vector[j] > dist[min_v][j]) d_vector[j] = dist[min_v][j];
		}
	}
	return (long long)(round(tax*E));
}

int main(){
	int T;
	cin >> T;
    //T = 1;
	for(int t=1; t<=T; t++){
		cin >> N;
		for(int i=0; i<N; i++){
			cin >> islands[i][0];
		}
		for(int i=0; i<N; i++){
			cin >> islands[i][1];
		}
		cin >> E;
		cout << '#' << t << ' ' << min_tax() << '\n';
	}
	return 0;
}
