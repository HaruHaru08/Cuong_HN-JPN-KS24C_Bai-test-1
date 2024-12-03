#include<stdio.h>

int main(){
    int arr[100];
    int exit = 1;
    int n, currentLength, addlndex, newValue;
    
    while(exit == 1){
        printf("\t\tMenu\n\n\n");
        printf("1.\tNhap so phan tu can nhap va gia tri cac phan tu \n");
        printf("2.\tIn ra gia tri cac phan tu dang quan ly \n");
        printf("3.\tIn ra gia tri lon nhat cua mang \n");
        printf("4.\tIn ra cac phan tu la so nguyen to trong mang \n");
        printf("5.\tThem mot phan tu vao trong mang \n");
        printf("6.\tXoa mot phan tu trong mang \n");
        printf("7.\tSu dung Selection Sort de sap xep mang theo thu tu tang dan \n");
        printf("8.\tSu dung Linear Search(nguoi dung nhap) de tim kiem phan tu va in ra vi tri index cua phan tu do \n");
        printf("9.\tThoat \n");
        printf("Lua chon cua ban: ");
        scanf("%d",&n);
        
        switch(n){
            case 1:
                printf("Nhap so phan tu can nhap: ");
                scanf("%d",&currentLength);
                if(currentLength < 0 || currentLength > 100){
                    printf("So nhap khong hop le");
                    return 1;
                }
                printf("Nhap cac phan tu cho mang: \n");
                for(int i = 0; i < currentLength; i++){
                    scanf("%d",&arr[i]);
                }
                break;
                
            case 2:
                if(currentLength == 0){
                    printf("Mang chua duoc nhap\n");
                } else {
                    printf("Cac phan tu cua mang la: \n");
                    for(int i = 0; i < currentLength; i++){
                        printf("arr[%d]= %d\n", i, arr[i]);
                    }
                }
                break;
                
            case 3:
                if(currentLength == 0){
                    printf("Mang chua duoc nhap\n");
                } else {
                    int max = arr[0];
                    for(int i = 1; i < currentLength; i++){
                        if(arr[i] > max){
                            max = arr[i];
                        }
                    }
                    printf("Gia tri lon nhat cua mang la: %d\n", max);
                }
                break;
                
            case 4:
                if(currentLength == 0){
                    printf("Mang chua duoc nhap\n");
                } else {
                    printf("Cac so nguyen to trong mang la: \n");
                    for(int i = 0; i < currentLength; i++){
                        int prime = 1;
                        if(arr[i] < 2){
                            prime = 0;
                        } else {
                            for(int j = 2; j * j <= arr[i]; j++){
                                if(arr[i] % j == 0){
                                    prime = 0;
                                    break;
                                }
                            }
                        }
                        if(prime == 1){
                            printf("%d\n", arr[i]);
                        }
                    }
                }
                break;
                
            case 5:
                if(currentLength == 0){
                    printf("Mang chua duoc nhap\n");
                } else {
                    printf("Cac phan tu cua mang truoc khi them la: \n");
                    for(int i = 0; i < currentLength; i++){
                        printf("%d ", arr[i]);
                    }
                    printf("\nNhap vi tri muon them phan tu (0 den %d): ", currentLength-1);
                    scanf("%d", &addlndex);
                    if(addlndex < 0 || addlndex > currentLength){
                        printf("Vi tri khong hop le.\n");
                    } else {
                        printf("Nhap phan tu muon them vao mang: ");
                        scanf("%d", &newValue);
                        
                        for(int i = currentLength; i > addlndex; i--){
                            arr[i] = arr[i-1];
                        }
                        arr[addlndex] = newValue;
                        currentLength++;
                        
                        printf("Cac phan tu cua mang sau khi them la: \n");
                        for(int i = 0; i < currentLength; i++){
                            printf("%d ", arr[i]);
                        }
                        printf("\n");
                    }
                }
                break;
                
            case 6:
                if(currentLength == 0){
                    printf("Mang chua duoc nhap\n");
                } else {
                    printf("Cac phan tu cua mang truoc khi xoa la: \n");
                    for(int i = 0; i < currentLength; i++){
                        printf("%d ", arr[i]);
                    }
                    printf("\nNhap vi tri muon xoa (0 den %d): ", currentLength-1);
                    scanf("%d", &addlndex);
                    if(addlndex < 0 || addlndex > currentLength-1){
                        printf("Vi tri khong hop le.\n");
                    } else {
                        for(int i = addlndex; i < currentLength-1; i++){
                            arr[i] = arr[i+1];
                        }
                        currentLength--;
                        
                        printf("Cac phan tu sau khi xoa la: \n");
                        for(int i = 0; i < currentLength; i++){
                            printf("%d ", arr[i]);
                        }
                        printf("\n");
                    }
                }
                break;
                
            case 7:
                if(currentLength == 0){
                    printf("Mang chua duoc nhap\n");
                } else {
                    // Selection sort
                    for(int i = 0; i < currentLength-1; i++){
                        int minArr = i;
                        for(int j = i+1; j < currentLength; j++){
                            if(arr[j] < arr[minArr]){
                                minArr = j;
                            }
                        }
                        int temp = arr[minArr];
                        arr[minArr] = arr[i];
                        arr[i] = temp;
                    }
                    printf("Mang sau khi sap xep la: \n");
                    for(int i = 0; i < currentLength; i++){
                        printf("%d ", arr[i]);
                    }
                    printf("\n");
                }
                break;
                
            case 8:
                if(currentLength == 0){
                    printf("Mang chua duoc nhap\n");
                } else {
                    int number, check = -1;
                    printf("Nhap so can tim: ");
                    scanf("%d", &number);
                    for(int i = 0; i < currentLength; i++){
                        if(arr[i] == number){
                            check = i;
                            break;
                        }
                    }
                    if(check != -1){
                        printf("So can tim nam o vi tri thu %d cua mang.\n", check);
                    } else {
                        printf("So can tim khong co trong mang.\n");
                    }
                }
                break;
                
            case 9:
                printf("Tam biet ban. Hen gap lai!\n");
                exit = 0;
                break;
                
            default:
                printf("So nhap khong hop le.\n");
                break;
        }
    }
    return 0;
}
