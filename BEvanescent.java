/*
 * _________________________________________________________________________________________________________________________________
 * |                                                                                                                               |
 * |    ___   __   __ _   _   _____  _   _    ______ ______   ___   _____   ___   ______     _____  _____  _   _  _____  _   _     |
 * |   / _ \  \ \ / /| | | | /  ___|| | | |   | ___ \| ___ \ / _ \ |_   _| / _ \  | ___ \   /  ___||_   _|| \ | ||  __ \| | | |    |
 * |  / /_\ \  \ V / | | | | \ `--. | |_| |   | |_/ /| |_/ // /_\ \  | |  / /_\ \ | |_/ /   \ `--.   | |  | \| || |  \/| |_| |    |
 * |  |  _  |   | |  | | | |  `--. \|  _  |   |  __/ |    / |  _  |  | |  |  _  | |  __/     `--. \  | |  | . ` || | __ |  _  |    |
 * |  | | | |   | |  | |_| | /\__/ /| | | |   | |    | |\ \ | | | |  | |  | | | | | |        /\__/ / _| |_ | |\  || |_\ \| | | |    |
 * |  \_| |_/   \_/   \___/  \____/ \_| |_/   \_|    \_| \_\_| |_/  \_/  \_| |_/ \_|        \____/  \___/ \_| \_/\_____/|_| |_|    |
 * |                                                                                                                               |
 * |  "Talk is cheap. Show me the code." - Linus Torvalds                                                                           |
 * |_______________________________________________________________________________________________________________________________|
 */

import java.util.*;
import java.io.*;

public class BEvanescent {
    static FastScanner sc = new FastScanner();

    public static void main(String[] args) {
        int t = 1;
        t = sc.nextInt();
        while (t-- > 0) {
            solve();
        }
        sc.out.close();
    }

    static void solve() {
        int n;
        n = sc.nextInt();
        String s;
        s = sc.next();
        int[] prefix = new int[n];
        int[] suffix = new int[n];
        prefix[0] = 1;
        for(int i=1; i<n; i++){
            if(s.charAt(i)==s.charAt(i-1)){
                prefix[i] = prefix[i-1];
            }else{
                prefix[i] = prefix[i-1]+1;
            }
        }
        suffix[n-1] = 1;
        for(int i=n-2; i>=0; i--){
            if(s.charAt(i)==s.charAt(i+1)){
                suffix[i] = suffix[i+1];
            }else{
                suffix[i] = suffix[i+1]+1;
            }
        }
        int res = n;
        for(int i=1; i<n-1; i++){
            int len = prefix[i-1] + suffix[i+1];
            res = Math.min(res, len);
            if(s.charAt(i-1)==s.charAt(i+1)){
                len--;
                res = Math.min(res, len);
            }
        }
        sc.out.println(res);
    }

    static long gcd(long a, long b) { return b == 0 ? a : gcd(b, a % b); }
    static long lcm(long a, long b) { return (a / gcd(a, b)) * b; }
    static void debug(int[] arr) { for(int i=0; i<arr.length; i++) { sc.out.print(arr[i] + " "); } sc.out.println();}
    static void debug(long[] arr) { for(int i=0; i<arr.length; i++) { sc.out.print(arr[i] + " "); } sc.out.println();}
    static void debug(char[] arr) { for(int i=0; i<arr.length; i++) { sc.out.print(arr[i] + " "); } sc.out.println();}
    static void debug(String[] arr) { for(int i=0; i<arr.length; i++) { sc.out.print(arr[i] + " "); } sc.out.println();}
    static class FastScanner {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer("");
        public PrintWriter out = new PrintWriter(System.out);
        String next() { while (!st.hasMoreTokens()) try { st = new StringTokenizer(br.readLine()); } catch (IOException e) {} return st.nextToken(); }
        int nextInt() { return Integer.parseInt(next()); }
        long nextLong() { return Long.parseLong(next()); }
        double nextDouble() { return Double.parseDouble(next()); }
        int[] readArray(int n) { int[] a = new int[n]; for (int i=0; i<n; i++) a[i]=nextInt(); return a; }
    }
}