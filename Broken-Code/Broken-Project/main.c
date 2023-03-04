#include <stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>

int main() {

    char letters[100];
    char phoneNumber[8];

    while (true) {
        printf("Enter a telephone number using letters (EXIT to quit): \n");
        fgets(letters, 100, stdin);
        for (unsigned long i = 0; i < 95; i++) {
            letters[i] = (char) toupper(letters[i]);
        }
        if (strcmp(letters, "EXIT\n") == 0) {
            printf("ending");
            break;
        }
//        printf("%s\n", letters);
       // printf("%d",strlen(letters)-1);
        for (unsigned long i = 0; i < 95; i++) {
            if(strlen(phoneNumber)==7){
                break;
            }
            switch (letters[i]) {
                case 'A':
                case 'B':
                case 'C':
                    phoneNumber[i] = '2';
                    break;
                case 'D':
                case 'E':
                case 'F':
                    phoneNumber[i] = '3';
                    break;
                case 'G':
                case 'H':
                case 'I':
                    phoneNumber[i] = '4';
                    break;
                case 'J':
                case 'K':
                case 'L':
                    phoneNumber[i] = '5';
                    break;
                case 'M':
                case 'N':
                case 'O':
                    phoneNumber[i] = '6';
                    break;
                case 'P':
                case 'Q':
                case 'R':
                case 'S':
                    phoneNumber[i] = '7';
                    break;
                case 'T':
                case 'U':
                case 'V':
                    phoneNumber[i] = '8';
                    break;
                case 'W':
                case 'X':
                case 'Y':
                case 'Z':
                    phoneNumber[i] = '9';
                    break;
                default:
                    break;

            }

        }
        printf("The corresponding telephone number is: ");
        for(int i = 0; i<strlen(phoneNumber); i++){
            printf("%c",phoneNumber[i]);
        }

        printf("\n");
    }

    return 0;
}
