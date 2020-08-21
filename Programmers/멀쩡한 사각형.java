class Solution {
	public long solution(int w,int h) {
		long answer = (long)w*h;
        int res = gcd(w,h);
        System.out.println(res);
        System.out.println(res*((w/res)+(h/res)-1));
		return answer - res*((w/res)+(h/res)-1);
	}
    private int gcd(int a,int b) {
        if(a%b==0) return b;
        return gcd(b%a,a);
    }
}