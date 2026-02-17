class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        // okay so need to return all the times
        // the hour must not contain any leading zeroes??
        // 
        // so basically all combinations of binary that could be amde with n bits
vector<string> rs;
    for (int h = 0; h < 12; h++)
    for (int m = 0; m < 60; m++)
        if (bitset<10>(h << 6 | m).count() == turnedOn)
            rs.emplace_back(to_string(h) + (m < 10 ? ":0" : ":") + to_string(m));
    return rs;



    }
};

// binary watch has 4 leds
// 4 , top represent hours ( 0 -11)
// 6 leds represt minuts
