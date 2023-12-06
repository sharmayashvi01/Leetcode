class Solution {
public:
    int totalMoney(int n) 
    {        
        int sum=0;  
        if(n<7)                     // for n=1 to 6
            return (sum+(n*(n+1)/2));
        if(n>=7)                    // for n =7 and more
        {
            int week=(n/7)+1;       // detrmine week no
            int rem_days=(n-(week-1)*7);// if (n%7!=0), then remaining days to calculate
            //cout<<"rem_days = "<<rem_days;
            
            
            
            // this while will calculate saving for a whole week
            // for example if n=24, then week=4, then sum+=49, then n--
            //                n=17, then sum+=42, then n--
            //                n=10, then sum+=35, then n--
            //                n=3, n<7 now second while will run
            // Now n is also denoting remaining days
            while(n>=7){
                sum+=(7*((n/7)+3));
                n=n-7;
            }
            //cout<<"sum till first while is "<<sum<<endl;
            //cout<<"n after first while is "<<n;
            
            // week = first saving if that particular week
            while(n){
                sum+=week;
                week++;
                n--;
            }            
        }
        return sum;
    }
};

 // M    T   W   Th  F   S   Su  
 // 1    2   3   4   5   6    7  =  28  =  7*4  = 7*(1+3) i.e 7*(week+3)  
 // 2    3   4   5   6   7    8  =  35  =  7*5  = 7*(2+3) i.e 7*(week+3)
 // 3    4   5   6   7   8    9  =  42  =  7*6  = 7*(3+3) i.e 7*(week+3)
 // 4    5   6   7   8   9   10  =  49  =  7*7  = 7*(4+3) i.e 7*(week+3)
//  5    6   7   8   9  10   11  =  56  =  7*8  = 7*(5+3) i.e 7*(week+3)
//  ''   ''  ''  ''  '' ''   ''
//  ''   ''  ''  ''  '' ''   ''
//  ''   ''  ''  ''  '' ''   ''
//  ''   ''  ''  ''  '' ''   ''
//  ''   ''  ''  ''  '' ''   ''
//  ''   ''  ''  ''  '' ''   ''
//  11  12  13  14  15  16   17  =  98  =  7*14 = 7*(11+3) i.e 7*(week+3)
//  12  13  14  15  16  17   18  = 105  =  7*15 = 7*(12+3) i.e 7*(week+3)
//  week no. is same as the weeks's first day saving
