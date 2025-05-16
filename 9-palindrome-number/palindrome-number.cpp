class Solution {
public:
bool isPalindrome(int x){
    if(x < 0){
    return false;
    }
    long  temp = x;
    long  rem = 0;
    long  num = 0;
while(x !=0){
    rem = x % 10;
    x  = x / 10;
    num = num*10 + rem;



}
if(num == temp){
    return true;
}
else 
return false;

}
};