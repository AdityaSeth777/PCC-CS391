#include <stdio.h>
#include <stdlib.h>

struct PolyNode {
    int coef;
    int exp;
    struct PolyNode *next;
};

typedef struct PolyNode Poly;

Poly *createNode(int coef, int exp) {
    Poly *node = (Poly*)malloc(sizeof(Poly));
    node->coef = coef;
    node->exp = exp;
    node->next = NULL;
    return node;
}

void insertPoly(Poly **headRef, int coef, int exp) {
    Poly *newNode = createNode(coef, exp);
    if (*headRef == NULL) {
        *headRef = newNode;
    }
    else {
        Poly *temp = *headRef;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
//Aditya Seth - setha4195@gmail.com
Poly *addPoly(Poly *poly1, Poly *poly2) {
    Poly *result = NULL;
    Poly **temp = &result;
    while (poly1 && poly2) {
        if (poly1->exp > poly2->exp) {
            *temp = createNode(poly1->coef, poly1->exp);
            poly1 = poly1->next;
        }
        else if (poly1->exp < poly2->exp) {
            *temp = createNode(poly2->coef, poly2->exp);
            poly2 = poly2->next;
        }
        else {
            *temp = createNode(poly1->coef + poly2->coef, poly1->exp);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        temp = &((*temp)->next);
    }
    if (poly1) {
        *temp = poly1;
    }
    if (poly2) {
        *temp = poly2;
    }
    return result;
}

Poly *multiplyPoly(Poly *poly1, Poly *poly2) {
    Poly *result = NULL;
    while (poly1) {
        Poly *temp = poly2;
        while (temp) {
            insertPoly(&result, poly1->coef * temp->coef, poly1->exp + temp->exp);
            temp = temp->next;
        }
        poly1 = poly1->next;
    }
    return result;
}

void displayPoly(Poly *poly) {
    while (poly) {
        printf("%dX^%d ", poly->coef, poly->exp);
        if (poly->next) {
            printf("+ ");
        }
        poly = poly->next;
    }
    printf("\n");
}

int main() {
    Poly *poly1 = NULL;
    Poly *poly2 = NULL;
    Poly *result = NULL;
    int degree1, degree2, coef;
    
    printf("Enter the degree of the first polynomial: ");
    scanf("%d", &degree1);
    
    for (int i = degree1; i >= 0; i--) {
        printf("Enter the coefficient of X^%d: ", i);
        scanf("%d", &coef);
        if (coef != 0) {
            insertPoly(&poly1, coef, i);
        }
    }
    
    printf("Enter the degree of the second polynomial: ");
    scanf("%d", &degree2);
    
    for (int i = degree2; i >= 0; i--) {
        printf("Enter the coefficient of X^%d: ", i);
        scanf("%d", &coef);
        if (coef != 0) {
            insertPoly(&poly2, coef, i);
        }
    }
    
    printf("The first polynomial is: ");
    displayPoly(poly1);
    
    printf("The second polynomial is: ");
    displayPoly(poly2);
    
    result = addPoly(poly1, poly2);
    printf("The sum of the polynomials is: ");
    displayPoly(result);
    
    result = multiplyPoly(poly1, poly2);
    printf("The product of the polynomials is: ");
    displayPoly(result);
    
    return 0;
}
