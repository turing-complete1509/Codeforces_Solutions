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

public class C2MarenolHardVersion {
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
        String a = sc.next();
        String b = sc.next();
        List<Integer>[] onesA = new ArrayList[2];
        onesA[0] = new ArrayList<>();
        onesA[1] = new ArrayList<>();

        for(int i=0; i<n; i++){
            if(a.charAt(i)=='1'){
                onesA[i%2].add(i);
            }
        }
        List<Integer>[] onesB = new ArrayList[2];
        onesB[0] = new ArrayList<>();
        onesB[1] = new ArrayList<>();
        for(int i=0; i<n; i++){
            if(b.charAt(i)=='1'){
                onesB[i%2].add(i);
            }
        }
        if(onesA[0].size()==onesB[0].size() && onesA[1].size()==onesB[1].size()){
            long res = 0;
            for(int i=0; i<2; i++){
                for(int j=0; j<onesA[i].size(); j++){
                    long diff = Math.abs(onesA[i].get(j) - onesB[i].get(j));
                    res += diff/(long)2;
                }
            }
            sc.out.println(res);
        }else{
            sc.out.println(-1);
        }
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