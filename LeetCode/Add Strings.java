import java.util.*;
import java.math.*;
class Solution {
    public String addStrings(String num1, String num2) {
        BigInteger a= new BigInteger(num1,10);
        BigInteger b= new BigInteger(num2,10);
        a = a.add(b);
        return a.toString(10);
    }
}