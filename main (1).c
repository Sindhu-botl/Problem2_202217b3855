/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a term in the polynomial
typedef struct Term {
    int coeff; // Coefficient
    int exp;   // Exponent
} Term;

// Function prototypes
void inputPolynomial(Term poly[], int *n);
void displayPolynomial(Term poly[], int n);
void addPolynomials(Term poly1[], int n1, Term poly2[], int n2, Term result[], int *n3);

int main() {
    int n1, n2, n3;
    Term poly1[100], poly2[100], result[100];

    // Input first polynomial
    printf("Enter the total number of terms in the polynomial: ");
    scanf("%d", &n1);
    inputPolynomial(poly1, &n1);

    // Display first polynomial
    printf("First polynomial: ");
    displayPolynomial(poly1, n1);

    // Input second polynomial
    printf("\nEnter the total number of terms in the polynomial: ");
    scanf("%d", &n2);
    inputPolynomial(poly2, &n2);

    // Display second polynomial
    printf("Second polynomial: ");
    displayPolynomial(poly2, n2);

    // Add the polynomials
    addPolynomials(poly1, n1, poly2, n2, result, &n3);

    // Display resultant polynomial
    printf("\nResultant polynomial after addition: ");
    displayPolynomial(result, n3);

    return 0;
}

void inputPolynomial(Term poly[], int *n) {
    for (int i = 0; i < *n; i++) {
        printf("Enter the Coefficient(%d): ", i + 1);
        scanf("%d", &poly[i].coeff);
        printf("Enter the exponent(%d): ", i + 1);
        scanf("%d", &poly[i].exp);
    }
}

void displayPolynomial(Term poly[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d(x^%d)", poly[i].coeff, poly[i].exp);
        if (i < n - 1) {
            printf(" + ");
        }
    }
    printf("\n");
}

void addPolynomials(Term poly1[], int n1, Term poly2[], int n2, Term result[], int *n3) {
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2) {
        if (poly1[i].exp > poly2[j].exp) {
            result[k++] = poly1[i++];
        } else if (poly1[i].exp < poly2[j].exp) {
            result[k++] = poly2[j++];
        } else {
            result[k].exp = poly1[i].exp;
            result[k++].coeff = poly1[i++].coeff + poly2[j++].coeff;
        }
    }

    while (i < n1) {
        result[k++] = poly1[i++];
    }

    while (j < n2) {
        result[k++] = poly2[j++];
    }

    *n3 = k;
}
