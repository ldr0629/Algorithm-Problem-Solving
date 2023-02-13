import java.util.Arrays;
import java.util.HashSet;

class Solution {
    public int solution(String[] s1, String[] s2) {
        int answer = 0;
        HashSet<String> filter_set = new HashSet<>(Arrays.asList(s1));
        for(String str : s2) { 
            if(filter_set.contains(str)) answer++; 
        }
        
        return answer;
    }
}