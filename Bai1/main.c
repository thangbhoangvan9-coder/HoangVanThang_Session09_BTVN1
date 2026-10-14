#include <stdio.h>
#include <string.h>

#define MAX_SIZE 50

struct VeMayBay {
    char maPNR[10];
    char tenHanhKhach[50];
    char hangVe[15];
    float trongLuongHanhLy;
    long phiPhuThu;
};

int main() {
    struct VeMayBay danhSach[MAX_SIZE];
    int n;
    int i;
    int j;
    int viTri = -1;
    char maCanTim[10];

    printf("=== HE THONG CHECK-IN VE MAY BAY ===\n");

    do {
        printf("Nhap so luong ve (1 - 50): ");
        scanf("%d", &n);
        while (getchar() != '\n');

        if (n < 1 || n > MAX_SIZE) {
            printf("So luong khong hop le! Vui long nhap lai.\n");
        }
    } while (n < 1 || n > MAX_SIZE);

    for (i = 0; i < n; i++) {
        printf("\n--- Nhap thong tin ve thu %d ---\n", i + 1);

        printf("Nhap ma PNR: ");
        fgets(danhSach[i].maPNR, sizeof(danhSach[i].maPNR), stdin);

        for (j = 0; danhSach[i].maPNR[j] != '\0'; j++) {
            if (danhSach[i].maPNR[j] == '\n') {
                danhSach[i].maPNR[j] = '\0';
                break;
            }
        }

        printf("Nhap ho ten hanh khach: ");
        fgets(danhSach[i].tenHanhKhach,
              sizeof(danhSach[i].tenHanhKhach), stdin);

        for (j = 0; danhSach[i].tenHanhKhach[j] != '\0'; j++) {
            if (danhSach[i].tenHanhKhach[j] == '\n') {
                danhSach[i].tenHanhKhach[j] = '\0';
                break;
            }
        }

        printf("Nhap hang ve (Eco/Deluxe/Business): ");
        fgets(danhSach[i].hangVe,
              sizeof(danhSach[i].hangVe), stdin);

        for (j = 0; danhSach[i].hangVe[j] != '\0'; j++) {
            if (danhSach[i].hangVe[j] == '\n') {
                danhSach[i].hangVe[j] = '\0';
                break;
            }
        }

        printf("Nhap trong luong hanh ly (kg): ");
        scanf("%f", &danhSach[i].trongLuongHanhLy);
        while (getchar() != '\n');

        if (danhSach[i].trongLuongHanhLy > 7.0) {
            danhSach[i].phiPhuThu =
                (long)((danhSach[i].trongLuongHanhLy - 7.0) * 50000);
        } else {
            danhSach[i].phiPhuThu = 0;
        }
    }

    printf("\n=== DANH SACH VE MAY BAY CHUYEN BAY ===\n");
    printf("-----------------------------------------------------------------------------------------\n");

    printf("%-5s %-10s %-25s %-12s %-12s %-15s\n",
           "STT", "MA PNR", "HO TEN HANH KHACH",
           "HANG VE", "HANH LY(KG)", "PHI PHU THU");

    printf("-----------------------------------------------------------------------------------------\n");

    for (i = 0; i < n; i++) {
        printf("%-5d %-10s %-25s %-12s %-12.1f %-15ld\n",
               i + 1,
               danhSach[i].maPNR,
               danhSach[i].tenHanhKhach,
               danhSach[i].hangVe,
               danhSach[i].trongLuongHanhLy,
               danhSach[i].phiPhuThu);
    }

    printf("-----------------------------------------------------------------------------------------\n");

    printf("\n=== CAP NHAT THONG TIN HANH LY ===\n");
    printf("Nhap ma PNR can cap nhat: ");

    fgets(maCanTim, sizeof(maCanTim), stdin);

    for (j = 0; maCanTim[j] != '\0'; j++) {
        if (maCanTim[j] == '\n') {
            maCanTim[j] = '\0';
            break;
        }
    }

    for (i = 0; i < n; i++) {
        if (strcmp(danhSach[i].maPNR, maCanTim) == 0) {
            viTri = i;
            break;
        }
    }

    if (viTri != -1) {
        printf("Tim thay ve cua hanh khach: %s\n",
               danhSach[viTri].tenHanhKhach);

        printf("Nhap trong luong hanh ly moi (kg): ");
        scanf("%f", &danhSach[viTri].trongLuongHanhLy);

        if (danhSach[viTri].trongLuongHanhLy > 7.0) {
            danhSach[viTri].phiPhuThu =
                (long)((danhSach[viTri].trongLuongHanhLy - 7.0) * 50000);
        } else {
            danhSach[viTri].phiPhuThu = 0;
        }

        printf("Cap nhat thanh cong! Phi phu thu moi: %ld VND\n",
               danhSach[viTri].phiPhuThu);

        printf("\n=== DANH SACH VE MAY BAY SAU CAP NHAT ===\n");
        printf("-----------------------------------------------------------------------------------------\n");

        printf("%-5s %-10s %-25s %-12s %-12s %-15s\n",
               "STT", "MA PNR", "HO TEN HANH KHACH",
               "HANG VE", "HANH LY(KG)", "PHI PHU THU");

        printf("-----------------------------------------------------------------------------------------\n");

        for (i = 0; i < n; i++) {
            printf("%-5d %-10s %-25s %-12s %-12.1f %-15ld\n",
                   i + 1,
                   danhSach[i].maPNR,
                   danhSach[i].tenHanhKhach,
                   danhSach[i].hangVe,
                   danhSach[i].trongLuongHanhLy,
                   danhSach[i].phiPhuThu);
        }

        printf("-----------------------------------------------------------------------------------------\n");
    } else {
        printf("Khong tim thay ma PNR hop le!\n");
    }

    return 0;
}
