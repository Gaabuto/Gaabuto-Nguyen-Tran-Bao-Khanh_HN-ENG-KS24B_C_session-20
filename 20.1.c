#include <stdio.h>
#include <string.h>

typedef struct {
	char maSach[20];
	char tenSach[50];
	char tacGia[20];
	int giaTien;
}mangSach;
	


void setBook( mangSach sach[], int *n);
void printBook(mangSach sach[], int *n);
void addBook(mangSach sach[], int *n);
void deleteBook(mangSach sach[], int *m);
void updateBook(mangSach sach[], int *m);
void sortBook(mangSach sach[], int *m);
void findBook(mangSach sach[], int *m);

int main(){
	mangSach sach[100];
	int choose,size,length;
	do{
		
		printf("\tMENU\n1.Nhap so luong va ttin sach\n2.Hien thi thong tin sach\n3.Them sach vao vi tri\n4.Xoa theo ma sach\n5.cap nhat ttin sach theo ma sach\n6.Sap xep sach theo gia\n7.Tim kiem sach theo ten\n8.Thoat\nMoi nhap lua chon cua ban:");
		scanf("%d",&choose);
		getchar();
		switch(choose){
			case 1:{
	printf("Moi ban nhap so sach co trong mang: ");	
	scanf("%d",&size);
	getchar();
				setBook(sach,&size);
				break;
			}
			case 2:{
				printBook(sach,&size);
				break;
			}
			case 3:{
				addBook(sach,&size);
				break;
			}
			case 4:{
				deleteBook(sach, &size);
				break;
			}
			case 5:{
				updateBook(sach,&size);
				break;
			}
			case 6:{
				sortBook(sach,&size);
				break;
			}
			/*case 7:{
				findBook(sach,&size);
				break;
			}*/
			default:{
				printf("Sai dinh dang, moi ban nhap lai!\n");
				break;
			}
		}
		
	}while( choose !=8);
	printf("Goodbye !");
	return 0;
}

void setBook(mangSach sach[], int *n){
	
	for ( int i = 0; i < *n; i ++){
		printf("Nhap thong tin sach thu %d:\n",i + 1);
		printf("Ma sach: ");
		fgets(sach[i].maSach,20,stdin);
		sach[i].maSach[strcspn(sach[i].maSach, "\n")] = '\0';
		printf("Ten sach: ");
		fgets(sach[i].tenSach,50,stdin);
		sach[i].tenSach[strcspn(sach[i].tenSach, "\n")] = '\0';
		printf("Tac gia: ");
		fgets(sach[i].tacGia,50,stdin);
		sach[i].tacGia[strcspn(sach[i].tacGia, "\n")] = '\0';
		printf("Gia tien: ");
		scanf("%d", &sach[i].giaTien);
		getchar();
	}
}

void printBook(mangSach sach[], int *n)	{
	for ( int i = 0; i < *n; i ++){
		printf("STT: %d\nMa: %s\nTen sach: %s\nTac gia: %s\nGia tien: %d\n",i+1,sach[i].maSach,sach[i].tenSach,sach[i].tacGia,sach[i].giaTien);
	}
}		

void addBook(mangSach sach[], int *n){
	int position, flag = 1;
	printf("moi nhap vi tri them sach: ");
	scanf("%d",&position);
	getchar();
	position = position - 1;
	if( position < 0 || position > *n + 1){
		printf("vi tri k hop le");}
	
	
	for ( int i = *n; i > position; i -- ){
		sach[i] = sach[i -1];
	}
	(*n)++;
	printf("Nhap thong tin sach:\n");
		printf("Ma sach: ");
		fgets(sach[position].maSach,20,stdin);
		sach[position].maSach[strcspn(sach[position].maSach, "\n")] = '\0';
		printf("Ten sach: ");
		fgets(sach[position].tenSach,50,stdin);
		sach[position].tenSach[strcspn(sach[position].tenSach, "\n")] = '\0';
		printf("Tac gia: ");
		fgets(sach[position].tacGia,50,stdin);
		sach[position].tacGia[strcspn(sach[position].tacGia, "\n")] = '\0';
		printf("Gia tien: ");
		scanf("%d", &sach[position].giaTien);
		getchar();
	
	}			
	
	void deleteBook(mangSach sach[], int *n){
		int position;
		printf("moi ban nhap vi tri can xoa: ");
		scanf("%d",&position);
	getchar();
	position = position - 1;
	if( position < 0 || position > *n + 1){
		printf("vi tri k hop le");}
		
		for ( int i = position; i < *n; i ++){
			sach[i] = sach[i + 1];
		}
		(*n)--;
	}
	
	void updateBook(mangSach sach[], int *m){
		int position;
		printf("moi ban nhap vi tri can chinh sua: ");
		scanf("%d",&position);
	getchar();
	position = position - 1;
	printf("Nhap thong tin sach:\n");
		printf("Ma sach: ");
		fgets(sach[position].maSach,20,stdin);
		sach[position].maSach[strcspn(sach[position].maSach, "\n")] = '\0';
		printf("Ten sach: ");
		fgets(sach[position].tenSach,50,stdin);
		sach[position].tenSach[strcspn(sach[position].tenSach, "\n")] = '\0';
		printf("Tac gia: ");
		fgets(sach[position].tacGia,50,stdin);
		sach[position].tacGia[strcspn(sach[position].tacGia, "\n")] = '\0';
		printf("Gia tien: ");
		scanf("%d", &sach[position].giaTien);
		getchar();
	}
	
	void sortBook(mangSach sach[], int *n){
		int a;
		printf("Moi ban chon:\n1.Tang dan\n2.Giam dan\nLua chon cua ban: ");
		scanf("%d",&a);
		
		for (int i = 0; i < *n - 1; i ++){
			for ( int j = i +1; j < *n - 1; i ++){
				if( a == 1 && sach[i].giaTien > sach[j].giaTien|| a == 2 && sach[i].giaTien < sach[j].giaTien){
					mangSach temp = sach[i];
					sach[i] = sach[j];
					sach[j] = temp;
				}
			}
		}
	}
	
	
