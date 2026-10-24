class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {
        vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        int Aarrmonth = stoi(arriveAlice.substr(0, 2));
        int Barrmonth = stoi(arriveBob.substr(0, 2));
        int Aarrdate = stoi(arriveAlice.substr(3, 2));
        int Barrdate = stoi(arriveBob.substr(3, 2));
        int Adepmonth = stoi(leaveAlice.substr(0, 2));
        int Bdepmonth = stoi(leaveBob.substr(0, 2));
        int Adepdate = stoi(leaveAlice.substr(3, 2));
        int Bdepdate = stoi(leaveBob.substr(3, 2));

        vector<int> start;
        vector<int> end;
        if (Aarrmonth > Barrmonth) {
            start = {Aarrmonth, Aarrdate};
        }else if(Aarrmonth < Barrmonth){
            start = {Barrmonth, Barrdate};
        }else{
            if(Aarrdate < Barrdate){
                start = {Barrmonth, Barrdate};
            }else{
                start = {Aarrmonth, Aarrdate};
            }
        }


        if(Adepmonth < Bdepmonth){
            end = {Adepmonth , Adepdate};
        }else if(Adepmonth > Bdepmonth){
            end = {Bdepmonth, Bdepdate};
        }else{
            if(Adepdate < Bdepdate){
                end = {Adepmonth, Adepdate};
            }else{
                end = {Bdepmonth, Bdepdate};
            }
        }

        if(start[0] > end[0]) return 0;
        if(start[0] == end[0] && start[1] > end[1]) return 0;


        int auxdays = 0;

        for(int i = start[0] ; i < end[0]; i++){
            auxdays += days[i-1];
        }

        return max(0, auxdays - start[1] + end[1] + 1);

    }
};

// take out substring
//  sub min, check days for correspondence days in month