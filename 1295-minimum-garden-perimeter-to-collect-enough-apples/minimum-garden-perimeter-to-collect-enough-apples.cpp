class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        long long i=1;
        while(neededApples>0){
            neededApples-=3*i*4; 
            neededApples-=(((2*i)*(2*i-1))/2-(i*(i+1))/2)*8;   
            i++;
        }
        return (i-1)*8;
    
    }
};