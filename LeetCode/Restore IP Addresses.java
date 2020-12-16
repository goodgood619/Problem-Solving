class Solution {
    public List<String> restoreIpAddresses(String s) {
        List<String> ans = new ArrayList<>();
        for(int i=0;i<=3 && i<s.length();i++) {
            String first = s.substring(0,i);
            if(!checkingIp(first)) continue;
            for(int j=i+1; j<=i+3 && j<s.length() ;j++) {
                String second = s.substring(i,j);
                if(!checkingIp(second)) continue;
                for(int k=j+1;k<=j+3 && k<s.length() ;k++) {
                    String third = s.substring(j,k);
                    if(!checkingIp(third)) continue;
                    String fourth = s.substring(k);
                    if(!checkingIp(fourth)) continue;
                    StringBuilder sb = new StringBuilder();
                    sb.append(first);
                    sb.append('.');
                    sb.append(second);
                    sb.append('.');
                    sb.append(third);
                    sb.append('.');
                    sb.append(fourth);
                    ans.add(sb.toString());
                }
            }
        }
        return ans;
    }
    private boolean checkingIp(String s) {
        if(s.length() >=1 && s.length() <=3 &&!(s.startsWith("0") && s.length() > 1) && Integer.parseInt(s)<=255) return true;
        else return false;
    }
}