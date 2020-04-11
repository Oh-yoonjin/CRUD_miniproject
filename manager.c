#include <string.h>
#include <stdio.h>
#include "manager.h"

int createProduct2(Product2 *p){

 printf("제품명은?");
    getchar();
    scanf("%[^\n]s",p->name);
    printf("중량은?");
    scanf("%d",&p->weight);
    printf("가격은?");
    scanf("%d",&p->price);
    p->tenprice=10*(p->price)/(p->weight); 
    printf("별점수는?");
    scanf("%d",&p->stargr);
    return 1;
}

void readProduct2(Product2 p){
if(p.weight == -1 && p.price == -1 && p.stargr == -1) return; 
   
    printf("%6s %2dg \n%3d원  \n(10g 당 %d원)  \n별 점수:%d\n",p.name,p.weight,p.price,p.tenprice,p.stargr);

}

int updateProduct2(Product2 *p){
printf("제품명은?");
    getchar();
    scanf("%[^\n]s",p->name);

    printf("중량은?");
    scanf("%d",&p->weight);

    printf("가격은?");
    scanf("%d",&p->price);
    p->tenprice=10*(p->price)/(p->weight); 

    printf("별점수는?");
    scanf("%d",&p->stargr);

    printf("=> 수정 성공!\n");
    return 1;
}
int deleteProduct2(Product2 *p){
    p->weight= -1;
    p->price= -1;
    p->tenprice= -1;
    p->stargr= -1;
    printf("=>삭제됨");
    return 1;
}
int selectMenu2(){

int menu;
    printf("\n*** 제품 관리 ***\n");
    printf("1. 조회\n");
    printf("2. 추가\n");
    printf("3. 수정\n");
    printf("4. 삭제\n");
    printf("5. 데이터 저장\n");
    printf("6. 제품명 검색\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    return menu;
}
void listProduct2(Product2 *p,int count){

printf("\nNo Name  weight price tenprice stargrade\n");
    printf("================================\n");
    for(int i=0; i<count; i++){
        if( p[i].weight == -1 || p[i].price == -1 || p[i].stargr == -1) continue;
        printf("%2d.\n", i+1);
        readProduct2(p[i]);

    }
    printf("\n");

}
int selectDataNo2(Product2 *p, int count){
    int no;
    listProduct2(p,count);
    printf("번호는 (취소:0)?");
    scanf("%d",&no);
    return no;
}

	
void saveData(Product2 p[], int count){
	FILE* fp;
	fp= fopen("product.txt","wt");
	for(int i=0; i<count; i++){
		fprintf(fp,"%d %d %d %d %s \n",p[i].weight,p[i].price,p[i].tenprice,p[i].stargr, p[i].name);
		}
	fclose(fp);
	printf("저장됨!\n");
}

int loadData(Product2 p[]){
	int count=0;
	FILE*fp;
	fp=fopen("product.txt","rt");
	if(fp==NULL){
		printf("=>파일 없음\n");
	return 0;	
	}
	for(; ; count++){
	fscanf(fp,"%d %d %d %d %[^\n]s",&p[count].weight, &p[count].price, &p[count].tenprice, &p[count].stargr,p[count].name);
	if(feof(fp)) break;
	}
	fclose(fp);
	printf("=> 로딩 성공!\n");

	return count;
}
void searchName(Product2 *p, int count){
	int scount=0;
	char search[100];

	printf("검색할 제품 명은?\n");
	getchar();
	scanf("%[^\n]s",search);

	printf("\nNo Name  weight price tenprice stargrade\n");
	printf("================================\n");
	for(int i=0; i<count; i++){
		if(p[i].price != -1){
		if(strstr(p[i].name,search)){  
                	printf("%2d",i+1);
               	 readProduct2(p[i]);
              	 scount++;
            		}
		}
    	}
	if(scount == 0) printf("=> 검색된 데이터 없음! \n");

}
//void searchTenprice(Product *s, int count);
//void searchPrice(Product *s, int count);
