#include <stdio.h>

int main(void){
    int H1, M1, H2, M2, HT, MT;
    scanf("%d %d %d %d", &H1, &M1, &H2, &M2);

    while (H1 != 0 || M1 != 0 || H2 != 0 || M2 != 0){
        MT = 60 - M1 + M2;
        if (H2 > H1)
            HT = H2 - H1 -1;
        else if (H1 > H2)
            HT = 23 - H1 + H2;
        else if (H1 == H2){
            if (M2 > M1){
                HT = 24;
	            MT = M2 - M1;
            }else if (M1 > M2){
                HT = 23;
	            MT = 60 - M1 + M2;
            }
        }
        printf("%d \n",(HT * 60) + MT);
        scanf("%d %d %d %d", &H1, &M1, &H2, &M2);
    }
    return 1;
}