import java.util.Arrays;

class Solution {
    public String solution(String my_string) {
        
        char[] chars = my_string.toLowerCase().toCharArray();
        Arrays.sort(chars);
        String result = new String(chars);
        return result;
    }
}
