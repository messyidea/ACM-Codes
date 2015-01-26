import java.*;
import java.io.*;
import java.math.BigInteger;
import java.util.*;
public class Main {
    public static void main(String args[]) {
        Scanner cin = new Scanner(System.in);
        int cas = cin.nextInt();
        for(int c = 1;c <= cas; ++c) {
            if(c != 1) System.out.println("");
            String s;
            BigInteger t = cin.nextBigInteger();
            BigInteger ans;
            if (t.remainder(BigInteger.valueOf(2)).equals(BigInteger.ONE)) {
				ans = t.divide(BigInteger.valueOf(2));
			}
			else if (t.remainder(BigInteger.valueOf(4)).equals(BigInteger.ZERO))
				ans = t.divide(BigInteger.valueOf(2)).subtract(BigInteger.ONE);
			else
				ans = t.divide(BigInteger.valueOf(2)).subtract(BigInteger.valueOf(2));
            System.out.println(ans);
            cin.nextLine();
        }
    }
}
