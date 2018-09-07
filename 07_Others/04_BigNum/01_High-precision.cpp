import java.io.*;
import java.math.BigInteger;
  
public class Main {
    public static void main(String args[]) throws IOException {
        StreamTokenizer in = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
        PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
 
        BigInteger a;
        BigInteger b;
        in.nextToken();
        int A=(int) in.nval;
        in.nextToken();
        int B=(int) in.nval;
 
        a=BigInteger.valueOf(A);
        b=BigInteger.valueOf(B);
        out.println(a.pow(B).subtract(b.pow(A)));
        out.flush();
    }
}
