class Solution {
public:
    string intToRoman(int n) {
        vector<string> ones = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        vector<string> tens = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        vector<string> hundreds = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        vector<string> thousands = {"", "M", "MM", "MMM"};
        string res = thousands[n/1000] + hundreds[(n%1000)/100]+tens[((n%1000)%100)/10]+ones[(((n%1000)%100)%10)];
        return res;
    }
};