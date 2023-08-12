#include <stdio.h>
#include <string.h>
#include "address.h"

int loadAdrress(ADDRESS* person){
    char inputs[NUM_BUFFER];
    int i = 0;
    FILE* text = NULL;
    fopen_s(&text, "address_book.dat", "rt");
    if(text != NULL){
        while(1){
            fgets(inputs, NUM_BUFFER, text);
            if((inputs[0] == '-') && (inputs[1] == '1')){
                break;
            }
            strcpy((person + i)->name, inputs);
            fgets(inputs, NUM_BUFFER, text);
            strcpy((person + i)->phone_number, inputs);
            fgets(inputs, NUM_BUFFER, text);
            strcpy((person + i)->e_mail_adrress, inputs);
            i ++;
        }
    }
    fclose(text);

    return i;
}

void listAddress(ADDRESS* person, int number_data){
    int i = 0;

    for(i = 0; i < 30; i++){
        printf("*");
    }
    printf("\n");
    for(i = 1; i < number_data; i++){
        printf("%d: %s\n", i, (person + i)->name);
    }    
    for(i = 0; i < 30; i++){
        printf("*");
    }
    printf("\n");
}

void printAddress(ADDRESS person){
    int i = 0;
    for(i = 0; i < 30; i++){
        printf("*");
    }
    printf("\nName: %s\n", person.name);
    printf("Phone Number: %s\n", person.phone_number);
    printf("E-Mail: %s\n", person.e_mail_adrress);
    for(i = 0; i < 30; i++){
        printf("*");
    }
    printf("\n");
}

void addEnter(char* not_enter){
    int i = 0;
    for(i = 0; i < NUM_BUFFER; i++){
        if(*(not_enter + i) == '\0'){
            *(not_enter + i) = '\n';
            *(not_enter + i + 1) = '\0';
            break;
        }
    }
}

void addAddress(ADDRESS* person, int last_num){
    char inputs[NUM_BUFFER] = {0,};

    printf("Input him or her name(Up to 40 characters): ");
    gets(inputs);
    addEnter(inputs);
    strcpy((person + last_num)->name, inputs);
    printf("Input him or her phone number(Up to 40 characters): ");
    gets(inputs);
    addEnter(inputs);
    strcpy((person + last_num)->phone_number, inputs);
    printf("Input him or her e-mail(Up to 40 characters): ");
    gets(inputs);
    addEnter(inputs);
    strcpy((person + last_num)->e_mail_adrress, inputs);
}

void changeAddress(ADDRESS* person, int num1, int num2){  // Push person[num2] at person[num1]
    strcpy((person + num1)->name, (person + num2)->name);
    strcpy((person + num1)->phone_number, (person + num2)->phone_number);
    strcpy((person + num1)->e_mail_adrress, (person + num2)->e_mail_adrress);
}

void sortAddress(ADDRESS* person, int last_num){
    int i = 0;
    int j = 0;
    int k = 0;
    int state = 0;

    for(i = 0; i < last_num - 2; i++){
        for(j = 1; j < last_num - i - 1; j++){
            if(person[j].name[0] > person[j + 1].name[0]){
                changeAddress(person, 0, j + 1);
                changeAddress(person, j + 1, j);
                changeAddress(person, j, 0);
                continue;
            }
            for(k = 0; k < NUM_BUFFER; k++){
                state = (person[j].name[k] == person[j + 1].name[k]);
                if(!state){
                    break;
                }
            }
            if((k == 0) || (k == NUM_BUFFER)){  // Totally different word or totally same word.
                continue;
            }
            else{
                if(person[j].name[k] > person[j + 1].name[k]){
                changeAddress(person, 0, j + 1);
                changeAddress(person, j + 1, j);
                changeAddress(person, j, 0);
                }
            }
        }
    }
}

void deleteAddress(ADDRESS* person, int delete_num, int last_num){
    changeAddress(person, delete_num, last_num - 1);
}

void saveAddress(ADDRESS* person, int save_num){
    int i = 0;
    FILE* text = NULL;
    fopen_s(&text, "address_book.dat", "wt");

    for(i = 0; i < save_num; i++){
        fputs((person + i)->name, text);
        fputs((person + i)->phone_number, text);
        fputs((person + i)->e_mail_adrress, text);
    }
    fputs("-1", text);
    fclose(text);
}