#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int productNo;
    char name[100];
    int cost;
} Product;

void inputProducts(Product **products, int *n);
void displayProductsInPriceRange(Product *products, int n, int minPrice, int maxPrice);

int main() {
    Product *products = NULL;
    int n;

    inputProducts(&products, &n);

    printf("\nProducts with cost between 100 and 1000 rupees:\n");
    displayProductsInPriceRange(products, n, 100, 1000);

    free(products);
    return 0;
}

void inputProducts(Product **products, int *n) {
    printf("Enter total number of products: ");
    scanf("%d", n);

    *products = (Product *)malloc((*n) * sizeof(Product));

    if (*products == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    for (int i = 0; i < *n; i++) {
        printf("\nProduct %d:\n", i + 1);
        printf("Product no: ");
        scanf("%d", &(*products)[i].productNo);
        printf("Name: ");
        scanf(" %[^\n]", (*products)[i].name);
        printf("Cost: ");
        scanf("%d", &(*products)[i].cost);
    }
}

void displayProductsInPriceRange(Product *products, int n, int minPrice, int maxPrice) {
    int found = 0;

    for (int i = 0; i < n; i++) {
        if (products[i].cost >= minPrice && products[i].cost <= maxPrice) {
            printf("\nProduct no: %d\n", products[i].productNo);
            printf("Name: %s\n", products[i].name);
            printf("Cost: %d\n", products[i].cost);
            found = 1;
        }
    }

    if (!found)
        printf("No products found in the price range.\n");
}
