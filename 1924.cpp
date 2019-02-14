#include <iostream>
#include <string>

using namespace std;

string Weekday(int month, int day){
    int num_day[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if(month != 1)
        for(int i = 0; i < month-1; ++i)
            day += num_day[i];
    switch(day % 7){
        case 0 : return "SUN";
        case 1 : return "MON";
        case 2 : return "TUE";
        case 3 : return "WED";
        case 4 : return "THU";
        case 5 : return "FRI";
        case 6 : return "SAT";
    }
}


int main(int argc, char **argv){
	int month, day;
	
    cin >> month >> day;
    cout << Weekday(month, day) << endl;
    return 0;
}
