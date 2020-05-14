#include <iostream>
#include <vector>

#define GEAR_SIZE 8
#define CLOCKWISE 1
#define LEFT_IDX 6
#define RIGHT_IDX 2

using namespace std;

class Gear{
public:
    Gear(char* init_value){
        for(int i=0; i<GEAR_SIZE; i++){
            value[i] = init_value[i];
        }
    };

    void rotate(int dir){
        int tmp;
        if(dir == CLOCKWISE){
            tmp = value[GEAR_SIZE-1];
            for(int i=GEAR_SIZE-1; i>0; i--){
                value[i] = value[i-1];
            }
            value[0] = tmp;
        }
        else{
            tmp = value[0];
            for(int i=0; i<GEAR_SIZE-1; i++){
                value[i] = value[i+1];
            }
            value[GEAR_SIZE-1] = tmp;    
        }
    }

    char get_right(){
        return value[RIGHT_IDX];
    }

    char get_left(){
        return value[LEFT_IDX];
    }

    char get_top(){
        return value[0];
    }

private:
    char value[GEAR_SIZE];
};

vector<Gear> gears;
bool check[4];

void move(int num, int dir){
    check[num] = true;
    if(num > 0 && gears[num-1].get_right() != gears[num].get_left() && !check[num-1]){
        move(num-1, -1*dir);
    }
    if(num < GEAR_SIZE-1 && gears[num+1].get_left() != gears[num].get_right() && !check[num+1]){
        move(num+1, -1*dir);
    }
    gears[num].rotate(dir);
}

int main(){
    char input[GEAR_SIZE];
    int K, num, dir, result = 0;

    for(int i=0; i<4; i++){
        for(int j=0; j<GEAR_SIZE; j++){
            cin >> input[j];
        }
        gears.push_back(Gear(input));
    }
    cin >> K;
    for(int i=0; i<K; i++){
        cin >> num >> dir;
        for(int j=0; j<4; j++) check[j] = false;
        move(num-1, dir);
    }
    for(int i=0; i<4; i++){
        if(gears[i].get_top() == '1'){
            result += (1 << i);
        }
    }
    cout << result;

    return 0;
}
