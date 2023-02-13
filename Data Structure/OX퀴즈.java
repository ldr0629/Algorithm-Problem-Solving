class Solution {
    public String[] solution(String[] quiz) {
        String[] answer = new String[quiz.length];
        for(int i = 0; i<quiz.length; i++) {
            String[] tmp = quiz[i].split(" ");
            answer[i] = tmp[1].equals("+") ? (Integer.parseInt(tmp[0]) + Integer.parseInt(tmp[2]) == Integer.parseInt(tmp[4]) ? "O" : "X") : (Integer.parseInt(tmp[0]) - Integer.parseInt(tmp[2]) == Integer.parseInt(tmp[4]) ? "O" : "X");
        }
        return answer;
    }
}