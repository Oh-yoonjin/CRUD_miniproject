#include <stdio.h>
#include <string.h>
typedef struct{
    char name[20]; 
    int weight;
    int price;  
    int tenprice; 
    int stargr; 
} Product;

int createProduct(Product *p);
void readProduct(Product p); 
int updateProduct(Product *p);   
int deleteProdcut(Product *p);       

//void saveData(Product p[], int count); 
//int loadData(Product p[]);       
//void searchName(Product *p, int count); 
//void searchTenprice(Product *p, int count);
//void searchPrice(Product *p, int count);

void listProduct(Product *p,int count); 
int selectDataNo(Product *p, int count); 
int selectMenu();
