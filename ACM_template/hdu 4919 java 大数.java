
import java.math.BigInteger;
import java.io.*;
import java.util.*;

public class Main {
    public static HashMap<BigInteger,BigInteger>  h;
    public static BigInteger solve(BigInteger n){
        if(h.containsKey(n)) return h.get(n);
        if (n.equals(BigInteger.ZERO)) return BigInteger.ZERO;
        if (n.equals(BigInteger.ONE)) return BigInteger.ZERO;
        BigInteger tp;
        BigInteger tp1=n.divide(BigInteger.valueOf(2));
        BigInteger er=BigInteger.valueOf(2);
        
        
        if(n.mod(BigInteger.valueOf(2)).equals(BigInteger.ONE)){
            BigInteger tmp=solve(tp1);
            tp=tmp.multiply(BigInteger.valueOf(4)).add(tp1.multiply(BigInteger.valueOf(6)));
        }
        else {
            BigInteger tmp=solve(tp1);
            BigInteger tmp1=solve(tp1.subtract(BigInteger.ONE));
            tp=tmp.multiply(BigInteger.valueOf(2)).add(tmp1.multiply(BigInteger.valueOf(2)))
                    .add(tp1.multiply(BigInteger.valueOf(4))).subtract(BigInteger.valueOf(4));
        }
        h.put(n,tp);
        return tp;
    }
    public static void main(String[] args){
        h=new HashMap<BigInteger, BigInteger>();
        Scanner in=new Scanner(System.in); 
        BigInteger n;
        for(int i=2;i<=10000;i++){
            solve(BigInteger.valueOf(i));
        }
        while (in.hasNext()) {
            n = in.nextBigInteger();
            System.out.println(solve(n));
        }
    }
}
