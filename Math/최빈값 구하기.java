import java.util.Arrays;

class Solution {
    public int solution(int[] array) {
        int answer = 0;
        int[] cntAry = new int[1001];
        
        for(int i = 0; i<array.length; i++) {
            cntAry[array[i]]++;
        }
        
        int max = 0;
        for(int i = 0; i<cntAry.length; i++) {
            if(cntAry[i]>max) {
                max = cntAry[i];
                answer = i;
            } else if(cntAry[i]==max) {
                answer = -1;
            }
        }
        
        return answer;
    }
}
