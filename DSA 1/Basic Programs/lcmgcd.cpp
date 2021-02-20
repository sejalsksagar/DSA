/* Aim: To Find GCD and LCM of two numbers */
#include<iostream>
using namespace std;

//Greatest Common Divisor of two numbers is the largest positive integer that divides each of them. 
int gcd(int m, int n) {
   int r = 0, a, b;
   a = (m > n) ? m : n; //larger no.
   b = (m < n) ? m : n; //smaller no.
   r = b;
   while (a % b != 0) {
      r = a % b;
      a = b;
      b = r;
   }
   return r;
}

//Least Common Multiple of two numbers is the smallest number (not zero) that is a multiple of both numbers.
int lcm(int m, int n) {
   int a;
   a = (m > n) ? m: n;
   while (true) {
      if (a % m == 0 && a % n == 0)
         return a;
         ++a;
   }
}

int main() {
   cout << "Enter the two numbers: ";
   int m, n;
   cin >> m >> n;
   cout << "GCD = " << gcd(m, n) << endl;
   cout << "LCM = " << lcm(m, n) << endl;
   return 0;
}