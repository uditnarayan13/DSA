class Solution {
public:
    int totalMoney(int n) {
        int numberOfDays=7;
        vector<int>days;
        vector<int>totalMoney;
        for(int i=1;i<=numberOfDays;i++){
            days.push_back(i);
        }
    totalMoney.push_back(0);
    for(int i=0;i<days.size();i++){
        int amount=totalMoney[i]+days[i];
        totalMoney.push_back(amount);
    }

    // for(int i=0;i<totalMoney.size();i++){
    //     cout<<totalMoney[i]<<" ";
    // }
        
    int c= n/numberOfDays;
    int d=n%numberOfDays;
    int sum=c*totalMoney[numberOfDays]+d*c+totalMoney[d];
    if(c-1>0){
        sum+=((c*numberOfDays)*(c-1))/2;
    }
     return sum;
    }
};