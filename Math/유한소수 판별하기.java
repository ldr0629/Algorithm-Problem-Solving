class Solution {
    public int solution(int a, int b) {
        b/= getGcd(a, b);

        while(b!=1) {
            if(b%2==0) {
                b/=2;
                continue;
            }
            if(b%5==0) {
                b/=5;
                continue;
            }
            return 2;
        }
        return 1;
    }
    
    private int getGcd(int a, int b) {
        while(b!=0) {
            int res = a % b;
            a = b;
            b = res;
        }
        return a;
    }
}