#include <stdio.h>
#include <string.h>
#include "product.h"
#include "manager.h"

int main(void){
    
    Product2 slist[100];
    int curcount=0;

    int count = 0, menu;
    count = loadData(slist);
    curcount=count; 

    while (1){
        menu = selectMenu2();
        if (menu == 0) break;
        if(menu ==3 || menu == 4){	
		if (count==0){
        		printf(" 데이터가 없습니다!\n");
			continue;
			}
		}
        if (menu == 1){

            if (count > 0) listProduct2(slist,curcount); 
            else printf("데이터가 없습니다\n");           
            
        }
        else if (menu == 2) {
            
            count+=createProduct2(&slist[curcount++]); 
            printf("추가됨!\n");

        }
        else if (menu == 3) {
            int no=selectDataNo2(slist, curcount);
            if(no==0){
                printf("=>취소됨!");
                continue;
            }
            updateProduct2(&slist[no-1]);
        
        }

        else if (menu == 4) {
            int no=selectDataNo2(slist, curcount);
            if(no==0){
                printf("=>취소됨!");
                continue;
            }
            int deleteok;
            printf("정말로 삭제하시겠습니까?(삭제:1)");
            scanf("%d",&deleteok);
            if(deleteok == 1){
                if(deleteProduct2(&slist[no-1])) count --;
                
           	 }
            
              }
	else if (menu == 5){
		if (count==0) printf("데이터가 없습니다!\n");
		else saveData(slist,curcount);
	
	}
	else if (menu == 6){
		if (curcount==0){
			printf("파일이  없습니다!\n");
			continue;
		}
		else searchName(slist,curcount);
	}
	else if (menu == 7){
		if (curcount==0){
			printf("파일이  없습니다!\n");
			continue;
		}
		else searchPrice(slist,curcount);
	}
	else if (menu == 8){
		if (curcount==0){
			printf("파일이  없습니다!\n");
			continue;
		}
		else searchTenprice(slist,curcount);
	}
   }
	printf("\n종료됨!\n");
   	return 0;


}
