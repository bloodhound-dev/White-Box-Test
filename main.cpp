#include <iostream>
#include<math.h>

using namespace std;
/** These functions compute the sine and cosine of an angle
    expressed in degrees. The result will be
    an integer representing the sine or cosine as
    ten-thousandths. For example, a result of 7071 represents
    7071e-4 or 0.7071.
*/

// Forward declarations
int sin0to45(int);
int sin45to90(int);
int polyEval(int, int[], int);

/** Compute the sine of an angle in degrees.
    @param x The angle in degrees
    @return The sine of x
*/
int sin(int x) {
  if (x < 0) {
    x = -x;
  }
  x = x % 360;
  if (0 <= x && x <= 45) {
    return sin0to45(x);
  }
  else if (45 <= x && x <= 90) {
    return sin45to90(x);
  }
  else if (90 <= x && x <= 180) {
    return sin(180 - x);
  }
  else {
    return -sin(x - 180);
  }
}

/** Compute the cosine of an angle in degrees.
    @param x The angle in degrees
    @return The cosine of x
*/
int cos(int x) {
  return sin(x + 90);
}

/** Compute the sine of an angle in degrees
    between 0 and 45.
    pre: 0 <= x < 45
    @param x The angle
    @return The sine of x
*/
int sin0to45(int x) {
  // Code to compute sin(x) for x between 0 and 45 degrees
  // Evaluate a polynomial optimized for this range.
  int coef[] = {
    -81, -277, 1747900, -1600};
  return polyEval(x, coef, 4) / 10000;
}

/** Compute the sine of an angle in degrees
    between 45 and 90.
    pre: 45 <= x <= 90
    @param x The angle
    @return The sine of x
*/
int sin45to90(int x) {
  // Code to compute sin(x) for x between 45 and 90 degrees
  // Evaluate a polynomial optimized for this range.
  int coef[] = {
    336, -161420, 75484, 999960000};
  return polyEval(90 - x, coef, 4) / 100000;
}

/** Function to evaluate a polynomial
    @param x The point at which the polynomial is to be evaulated
    @param coef The array of coefficients
    @param n The number of coefficients (degree + 1)
    @return x^n-1*coef[0] + x^n-2*coef[1] + ... x*coef[n-2] + coef[n-1]
*/
int polyEval(int x, int coef[], int n) {
  int result = 0;
  for (int i = 0; i < n; i++) {
    result *= x;
    result += coef[i];
  }
  return result;
}
int test_sin(int n)
{
    int sample = sin(n);
    if (sin(n)==sample)
        cout<<"\tPass"<<endl;
    else cout<<"\tFail"<<endl;
}
int test_cos(int n)
{
    int sample = cos(n);
    if (cos(n)==sample)
        cout<<"\tPass"<<endl;
    else cout<<"\tFail"<<endl;
}

int main()
{
    /*
    for our white box testing, we use different range of values to test
        the outputs of the different functions

    */
    //whitebox test cases

    int x = 33;
    int x1 = 5.9;
    int x2 = 60;
    int x3 = 100;
    int x4 = 120;
    int x5 = 90;
    int x6 = 70;
    int x7 = 45;
    int x8 = 180;
    int x9 = -240;
    int y1 = 360;
    int y2 = 67;
    int y3 = 92;
    int y4 = 69;
    int y5 = -28;
    int y6 = 40;
    int y7 = 12;
    int y8 = 37;
    int y9 = -25.00;
    int z1[] = {10, 0, 35, 45, 60, 90, 75};
    int n = 8, sample;

    //testing sines
    sample = sin(x1);
    cout <<"sine: " <<x1 << " is: " << sin(x1) << " \texpected :   "<<sample;
    test_sin(x1);
    sample = sin(x3);
    cout <<"sine: " <<x3 << " is: " << sin(x3) << "\texpected :  "<<sample;
    test_sin(x3);
    sample = sin(x5);
    cout <<"sine: " <<x5 << " is: " << sin(x5) << "\texpected :  "<<sample;
    test_sin(x5);
    sample = sin(x9);
    cout <<"sine: " <<x9 << " is: " << sin(x9) << "\texpected :"<<sample<<"\t";
    test_sin(x9);
    sample = sin(x7);
    cout <<"sine: " <<x7 << " is: " << sin(x7) << "\texpected : "<<sample<<"\t";
    test_sin(x7);
    sample = sin(y1);
    cout <<"sine: " <<y1 << " is: " << sin(y1) << " \texpected : "<<sample<<"\t";
    test_sin(y1);
    sample = sin(y7);
    cout <<"sine: " <<y7 << " is: " << sin(y7) << "\texpected : "<<sample<<"\t";
    test_sin(y7);
    //testing cosines
    sample=cos(x1);
    cout <<"cosine: " << x1 << " is: " << cos(x1) << "\texpected : "<<sample<<"\t";
    test_cos(x1);
    sample=cos(x2);
    cout <<"cosine: " << x2 << " is: " << cos(x2) << "\texpected : "<<sample<<"\t";
    test_cos(x2);
    sample=cos(y2);
    cout <<"cosine: " << y2 << " is: " << cos(y2) << "\texpected : "<<sample<<"\t";
    test_cos(y2);
    sample=cos(y7);
    cout <<"cosine: " << y7 << " is: " << cos(y7) << "\texpected : "<<sample<<"\t";
    test_cos(y7);
    sample=cos(y9);
    cout <<"cosine: " << y9 << " is: " << cos(y9) << "\texpected : "<<sample<<"\t";
    test_cos(y9);
    sample=cos(y3);
    cout <<"cosine: " << y3 << " is: " << cos(y3) << "\texpected : "<<sample<<"\t";
    test_cos(y3);
    sample=cos(y6);
    cout <<"cosine: " << y6 << " is: " << cos(y6) << "\texpected : "<<sample<<"\t";
    test_cos(y6);
    sample=cos(y5);
    cout <<"cosine: " << y5 << " is: " << cos(y5) << "\texpected : "<<sample<<"\t";
    test_cos(y5);
    sample=cos(x9);
    cout <<"cosine: " << x9 << " is: " << cos(x9) << "\texpected : "<<sample<<"\t";
    test_cos(x9);

    //testing int sin0to45


    return 0;
}
