#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_PRODUCTS 100
#define MAX_CATEGORIES 20

typedef struct {
    int id;
    char category[31];
    int price;
} Product;

typedef struct {
    char name[31];
    int quantity;
    int revenue;
} Category;

int main() {
    Product products[MAX_PRODUCTS];
    Category categories[MAX_CATEGORIES];
    int np=0, nc=0, id, quantity;
    char line[100];
    FILE *fp = fopen("products.csv", "r");
    if(fp == NULL) {
        fprintf(stderr, "Cannot open products.csv.\n");
        return 1;
    }
    while(np < MAX_PRODUCTS && fgets(line, sizeof line, fp) != NULL) {
        products[np].id = atoi(strtok(line, ","));
        strcpy(products[np].category, strtok(NULL, ","));
        products[np].price = atoi(strtok(NULL, ","));
        np++;
    }
    fclose(fp);

    fp = fopen("sales.csv", "r");
    if(fp == NULL) {
        fprintf(stderr, "Cannot open sales.csv.\n");
        return 1;
    }
    while(fscanf(fp, "%d,%d", &id, &quantity) == 2) {
        int p=-1;

        for(int i=0; i<np; i++) {
            if(products[i].id == id) {
                p=i;
                break;
            }
        }

        if(p == -1) continue;

        int c=-1;

        for(int i=0; i<nc; i++) {
            if(strcmp(categories[i].name, products[p].category) == 0) {
                c=i;
                break;
            }
        }

        if(c == -1) {
            if (nc >= MAX_CATEGORIES) {
                fclose(fp);
                return 1;
            }

            c = nc++;
            strcpy(categories[c].name, products[p].category);
            categories[c].quantity = 0;
            categories[c].revenue = 0;
        }

        categories[c].quantity += quantity;
        categories[c].revenue += (quantity*products[p].price);
    }

    for(int i=0; i<nc-1; i++) {
        for(int j=0; j<nc-1-i; j++) {
            int swap=0;

            if(categories[j].revenue < categories[j+1].revenue) swap=1;
            else if((categories[j].revenue == categories[j+1].revenue) && 
            strcmp(categories[j].name, categories[j+1].name)>0) swap=1;

            if(swap) {
                Category temp = categories[j];
                categories[j] = categories[j+1];
                categories[j+1] = temp;
            }
        }
    }

    fp = fopen("summary.csv", "w");
    if(fp == NULL) {
        fprintf(stderr, "Cannot create summary.csv.\n");
        return 1;
    }
    fprintf(fp, "Category,TotalQuantity,TotalRevenue\n");
    for(int i=0; i<nc; i++) {
        fprintf(fp, "%s,%d,%d\n", categories[i].name, categories[i].quantity, categories[i].revenue);
    }
    fclose(fp);
    return 0;
}