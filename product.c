#include "product.h"

int createProduct(Product *p){
    getchar();
    printf("\n");
    printf("제품을 추가합니다\n"); 
    printf("제품 명은?: ");
    scanf("%[^\n]s",p->name);

    printf("중량은?: ");
    scanf("%d",&p->weight);

    printf("가격은?: ");
    scanf("%d",&p->price);

    p->tenprice=10*(p->price)/(p->weight); 


    printf("별 점수는?(1~5)?: ");
    scanf("%d",&p->stargr);
    
    return 1;
}

void readProduct(Product p){
    printf("\n");
    printf("%6s %2dg \n%3d원  \n(10g 당 %d원)  \n별 점수:%d\n",p.name,p.weight,p.price,p.tenprice,p.stargr);

}
int updateProduct(Product *p){
    getchar();
    printf("\n");
    printf("정보를 수정합니다\n"); 
    printf("제품 명은?: ");
    scanf("%[^\n]s",p->name);

    printf("중량은?: ");
    scanf("%d",&p->weight);

    printf("가격은?: ");
    scanf("%d",&p->price);

    p->tenprice= 10*(p->price)/(p->weight); 


    printf("별 점수는?(1~5)?: ");
    scanf("%d",&p->stargr);
    
    printf("수정됨!");

    return 1;
};

int deleteProdcut(Product *p){
    p->weight=-1;
    p->price=-1;
    p->tenprice=-1;
    printf("삭제 되었습니다!\n");
    return 0;
}

int selectMenu(){
    int menu=0;
    printf("\n");
    printf("**********제품 추가**********\n");
    printf("1. 조회\n");
    printf("2. 추가\n");
    printf("3. 변경\n");
    printf("4. 삭제\n");
    printf("0. 종료\n");
    printf("\n");
    printf("선택:");
    scanf("%d",&menu);
    printf("\n");
    return menu;
}

