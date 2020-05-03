#include <iostream>
#include <vector>
#include <climits>

#define MAX_N 50
#define MAX_M 13

using namespace std;

typedef struct pos{
    int r;
    int c;
    pos(int r_, int c_): r(r_), c(c_) {};
} Pos;

int N, M, chicken_cnt, house_cnt, result = INT_MAX;
int city[MAX_N][MAX_N];
vector<Pos> chicken;
vector<Pos> house;
bool choose[MAX_M] = {false, };

int chicken_distance(){
    int d, chicken_d = 0;
    for(int i=0; i<house_cnt; i++){
        d = INT_MAX;
        for(int k=0; k<chicken_cnt; k++){
            if(choose[k]){
                d = min(d, abs(house[i].r-chicken[k].r)+abs(house[i].c-chicken[k].c));
            }
        }
        chicken_d += d;
        if(chicken_d > result) return INT_MAX;
    }
    return chicken_d;
}

int min_chicken_distance(int n, int idx){
    if(n <= M){
        if(n > 0){
            result = min(result, chicken_distance());
        }
        for(int i=idx; i<chicken_cnt; i++){
            if(!choose[i]){
                choose[i] = true;
                min_chicken_distance(n+1, i+1);
                choose[i] = false;
            }
        }
    }
    return result;
}

int main(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> city[i][j];
            if(city[i][j] == 1){ // house
                house.push_back(Pos(i, j));
            }
            else if(city[i][j] == 2){ // chicken
                chicken.push_back(Pos(i, j));
            }
        }
    }
    house_cnt = house.size();
    chicken_cnt = chicken.size();
    cout << min_chicken_distance(0, 0);
}
