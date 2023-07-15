class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        
//         using greedy to give coins of larger denominations first then smaller denominations
        int five=0,ten=0;
        
        int i = 0;
//         while(i<bills.size()){
//             if(bills[i] == 5)five++;
//             else if(bills[i] == 10)
//                 five--;ten++;
            
//             else if(bills[i] == 20 && ten>0){
//                 ten--;five--;
//             }
//             else if(bills[i] == 20 && five>=3)five-=3;
//             else return false;
//             i++;
//         }
//         return five>=0;
        for(auto i:bills){
            if(i == 5)five++;
            else if(i == 10)five--,ten++;
            else if(ten>0)five--,ten--;
            else five-=3;
            if(five<0)return false;
        }
        
        return true;
        
        
    }
};