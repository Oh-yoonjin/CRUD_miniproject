#include <stdio.h>

typedef struct{
	char name[60];
	int weight;
	int price;
	int tenprice;
	int stargr;
} Product2;

int createProduct2(Product2 *p);
void readProduct2(Product2 p);
int updateProduct2(Product2 *p);
int deleteProduct2(Product2 *p);
int selectMenu2();
void listProduct2(Product2 *p,int count);
int selectDataNo2(Product2 *p, int count);
void saveData(Product2 p[], int count);
int loadData(Product2 p[]);
void searchName(Product2 *s, int count); //이름 검색 함수
void searchTenprice(Product2 *s, int count);//표준 가격 검색 함수
void searchPrice(Product2 *s, int count);// 가격대 검색 함수
	
