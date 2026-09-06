class Solution {
public:
    int fib(int n) {  //return an integer always
        if(n==0 || n==1){ //base cases 
            return n;
        }  
        if(n>1){
            return (fib(n-1)+fib(n-2)); //recursive cases
        }
        return 0;
    }
};