class Solution {
public:
    int fib(int n) {  //return an integer always
        int count=0;
        if(n==0 || n==1){
            count=count+1;
            return n;
        }
        if(n>1){
            count=count+1;
            return (fib(n-1)+fib(n-2));
        }
        return 0;
    }
};