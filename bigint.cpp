<snippet>
	<content><![CDATA[
///big int*****************************************************
import java.math.BigInteger;
import java.util.Scanner;

public class Main
{
    public static void main (String[] args) throws java.lang.Exception
    {
        BigInteger sum= a.add(b); ///sum=a+b

        BigInteger sub= a.substract(b); ///sub=a-b

        BigInteger mul= a.multiply(b); ///mul=a*b

        BigInteger div= a.divide(b); ///div=a/b

        BigInteger moduls= a.mod(b); ///mod=a%b

        BigInteger val= BigInteger.valueOf(a); ///int a to bigint val

        BigInteger b = new BigInteger("1"); ///declaring a bigint

        Scanner in = new Scanner(System.in); ///declare scanner only once

        int a=in.nextint(); ///take input

        System.out.println(num+"!\n"+b); ///print something

        while(a>1)
        {
            a--;   ///loop
        }

        while(in.hasNextint()) ///take input untill end of file
            ******/// can create fun inside main class with the name --> public static return_type name(parameters)
        }
}
]]></content>
	<!-- Optional: Set a tabTrigger to define how to trigger the snippet -->
	<tabTrigger>bigint</tabTrigger>
	<!-- Optional: Set a scope to limit where the snippet will trigger -->
	<!-- <scope>source.python</scope> -->
</snippet>
