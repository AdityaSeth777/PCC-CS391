#include <stdio.h>

double horner(double coeff[], int n, double x) {
    if (n == 0) { // Base case
        return coeff[0];
    } else {
        return x * horner(coeff, n-1, x) + coeff[n];
    }
}

int main() {
    int n;
    printf("Enter the degree of the polynomial: ");
    scanf("%d", &n);
    double coeff[n+1];
    printf("Enter the coefficients of the polynomial in ascending order of degree: ");
    for (int i = 0; i <= n; i++) {
        scanf("%lf", &coeff[i]);
    }
    double x;
    printf("Enter the value of x: ");
    scanf("%lf", &x);
    printf("The value of the polynomial at x = %f is %f\n", x, horner(coeff, n, x));
    return 0;
}
