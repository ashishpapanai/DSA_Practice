/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef {
	public static void main(String[] args) throws java.lang.Exception {
		try {
			Scanner sc = new Scanner(System.in);
			int testCase = sc.nextInt();
			int finAns[] = new int[testCase];
			int x = 0;
			while (testCase > 0) {
				int n = sc.nextInt();
				int m = sc.nextInt();
				int f[] = new int[n];
				int p[] = new int[n];
				for (int i = 0; i < n; i++) {
					f[i] = sc.nextInt();
				}
				for (int i = 0; i < n; i++) {
					p[i] = sc.nextInt();
				}
				int ans[] = new int[m];
				for (int i = 0; i < n; i++) {
					int a = f[i] - 1;
					ans[a] += p[i];
				}
				int min = Integer.MAX_VALUE;
				for (int i = 0; i < m; i++) {
					if (ans[i] < min && ans[i] != 0)
						min = ans[i];
				}
				finAns[x] = min;
				x++;
				testCase--;
			}
			for (int i = 0; i < finAns.length; i++) {
				System.out.println(finAns[i]);
			}
		} 
		catch (Exception e) {
			return;
		}
	}
}
