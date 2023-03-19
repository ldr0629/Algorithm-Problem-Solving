import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());

        for(int i = 0; i<t; i++) {
            long num = Long.parseLong(br.readLine());
            var bigNum = new BigInteger(String.valueOf(num));
            
            if(bigNum.isProbablePrime(10)) System.out.println(num);
            else System.out.println(bigNum.nextProbablePrime());
        }
    }
}
