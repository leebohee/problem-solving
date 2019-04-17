class Solution {
private:
    // convert all time units as minutes
    int time_unit[10] = {1, 2, 4, 8, 16, 32, 1, 2, 4, 8};
    
public:
    vector <string> times;
    void AddResult(int hours, int minutes){
        if(hours < 12 && minutes < 60){
            string result = to_string(hours) + ":";
            if(minutes < 10){
                result += '0';
            }
            result += to_string(minutes);
            times.push_back(result);
        }
    }
    void Combination(bool chk[], int cnt, int num, int cur){
        if(cnt == num){
            int minutes = 0, hours = 0;
            for(int i=0; i<10; i++){
                if(chk[i]){
                    if(i <= 5){
                        minutes += time_unit[i];
                    }
                    else{
                        hours += time_unit[i];
                    }
                }
            }
            AddResult(hours, minutes); 
        }
        else{
            for(int i=cur; i<10; i++){
                if(!chk[i]){
                    chk[i] = true;
                    Combination(chk, cnt+1, num, i);
                    chk[i] = false;
                }
            }
        }
    }
    
    vector<string> readBinaryWatch(int num) {
        bool chk[10] = {false};
        Combination(chk, 0, num, 0);
        return times;
    }
};
