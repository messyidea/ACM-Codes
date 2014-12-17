
import java.math.BigInteger;  
import java.io.*;  
import java.util.*;  
public class Main{
    public static void main(String args[]){
        Scanner cin=new Scanner(System.in);
        int cas=cin.nextInt();
        cin.nextLine();
        for(int c=1;c<=cas;c++){
            String s;
            s=cin.nextLine();
            //System.out.println(s);
            String[] sp=s.split("\\s+");
            BigInteger x=new BigInteger(sp[0],2);
            BigInteger y=new BigInteger(sp[1],2);
            BigInteger ans=x.gcd(y);
            System.out.println("Case #"+c+": "+ans.toString(2));
        }
    }
}
