#include <stdio.h>
#include "address.h"

int main(void){
    ADDRESS person[NUM_PERSON] = {0,};
    ADDRESS* struct_ptr = &person;
    int load_num = 0;  // Index of top blank memory
    int input = 0;
    int index = 0;

    printf("Welcome to YHS's address book v1.0.0");
    load_num = loadAdrress(struct_ptr);
    listAddress(struct_ptr, load_num);
    while(1){
        printf("Input number as following\n");
        printf("1: Watch list of members\n");
        printf("2: Watch information of the member\n");
        printf("3: Add a member and info\n");
        printf("4: Delete a member and info\n");
        printf("5: Sort list of members in descending order\n");
        printf("6: End program\n>> ");
        scanf_s("%d", &input);

        switch(input){
            case 1:
                listAddress(struct_ptr, load_num);
                break;
            case 2:
                printf("Input index of member you want >>");
                scanf_s("%d", &index);
                if((index >= load_num) || (index < 1)){
                    index = 0;
                    printf("Out of range\n");
                }
                else{
                    printAddress(person[index]);
                }
                break;
            case 3:
                getchar();  // clear buffer
                addAddress(struct_ptr, load_num);
                load_num ++;
                break;
            case 4:
                printf("Input index of member you want >>");
                    scanf_s("%d", &index);
                    if((index >= load_num) || (index < 1)){
                        index = 0;
                        printf("Out of range\n");
                    }
                    else{
                        deleteAddress(struct_ptr, index, load_num);
                        load_num --;
                    }
                break;
            case 5:
                sortAddress(struct_ptr, load_num);
                break;
            case 6:
                index = -1;
                break;
            default:
                printf("Out of range\n");
                break;
        }
        if(index == -1){
            break;
        }
    }
    saveAddress(struct_ptr, load_num);  

    return 0;
}