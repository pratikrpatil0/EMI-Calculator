//---------------------------------|
// Programmed By:- Pratik_Patil   ||
// Last Edited:- 26/09/2023      |||
//------------------------------||||


#include <stdio.h>
#include <math.h>

// EMI calculation (function)
double calculateEMI(double P, double R, int N) {

    // Monthly interest rate (r)
    double r = R / 12.0;

    // EMI calculation (by formulae)
    double E = (P * r * pow(1 + r, N)) / (pow(1 + r, N) - 1);

    return E;
}

int main() {

    double P = 5000000.0; // principal
    double R = 0.09;      // Annual interest rate 
    int N = 10;           // Laon in years 

    // Convert the loan to months
    int N_months = N * 12;

    // monthly interest rate (r)
    double r = R / 12.0;

    // EMI calculation
    double E = calculateEMI(P, R, N_months);

    // calculated EMI
    printf("Pratik's EMI: Rs. %.2lf\n", E);

    // Repayment schedule
    printf("\nRepayment Schedule:\n");
    double principalBalance = P;
    for (int month = 1; month <= N_months; month++) {
        double interestPayment = principalBalance * r;
        double principalPayment = E - interestPayment;
        principalBalance -= principalPayment;

        // values for each month
        printf("Month %d (Date: %d-%02d-%02d):\n", month, 2024, (month + 4) / 12, (month + 4) % 12 + 1);
        printf("Total Payment (EMI): Rs. %.2lf\n", E);
        printf("Interest Payment: Rs. %.2lf\n", interestPayment);
        printf("Principal Payment: Rs. %.2lf\n", principalPayment);
        printf("Remaining Principal Balance: Rs. %.2lf\n", principalBalance);

        if (month < N_months) {
            printf("\n");
        }
    }

    return 0;
}

