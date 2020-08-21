import java.util.*;
class Solution {
    public int solution(String str1, String str2) {
        Map<String,Integer> map1 = new TreeMap<>();
        Map<String,Integer> map2 = new TreeMap<>();
        Map<String,Integer> hapset = new TreeMap<>();
        int cnt=0;
        for(int i=0;i<str1.length()-1;i++) {
            String a = str1.substring(i,i+2);
            if(check(a)) {
                a= a.toLowerCase();
                if(map1.get(a)==null) {
                    map1.put(a,1);
                }
                else {
                    int value = map1.get(a);
                    value++;
                    map1.remove(a);
                    map1.put(a,value);
                }
            }
        }
        for(int i=0;i<str2.length()-1;i++) {
            String b = str2.substring(i,i+2);
            if(check(b)) {
                b = b.toLowerCase();
                if(map2.get(b)==null) map2.put(b,1);
                else {
                    int value = map2.get(b);
                    value++;
                    map2.remove(b);
                    map2.put(b,value);
                }
            }
        }
        Iterator it1 = map1.keySet().iterator();
        Iterator it3 = map2.keySet().iterator();
        int total=0;
        while(it3.hasNext()) {
            String key3 = (String) it3.next();
            int value3 = map2.get(key3);
            total += value3;
        }
        int same=0;
        while(it1.hasNext()) {
            String key1 = (String) it1.next();
            int value1 = map1.get(key1);
            total +=value1;
            Iterator it2 = map2.keySet().iterator();
            while(it2.hasNext()) {
                String key2 = (String) it2.next();
                int value2 = map2.get(key2);
                if(key1.equals(key2)) {
                    same += Math.min(value1, value2);
                    break;
                }
            }
        }
        total-=same;
        if(total==0 && same==0) return 65536;
        return (int) ((double)same/total * 65536);
    }
    private boolean check(String s) {
        char first = s.charAt(0);
        char second = s.charAt(1);
        if((first>='a' && first<='z' || first>='A' && first<='Z') && (second>='a' && second<='z'|| second>='A' && second<='Z')) return true;
        return false;
    }
}