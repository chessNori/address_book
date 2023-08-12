#define NUM_BUFFER 41
#define NUM_PERSON 11

typedef struct yhs_address{
    char name[NUM_BUFFER];
    char phone_number[NUM_BUFFER];
    char e_mail_adrress[NUM_BUFFER];
}ADDRESS;

extern int loadAdrress(ADDRESS* person);
extern void listAddress(ADDRESS* person, int number_data);
extern void printAddress(ADDRESS person);
extern void addEnter(char* not_enter);
extern void addAddress(ADDRESS* person, int last_num);
extern void changeAddress(ADDRESS* person, int num1, int num2);
extern void sortAddress(ADDRESS* person, int last_num);
extern void deleteAddress(ADDRESS* person, int delete_num, int last_num);
extern void saveAddress(ADDRESS* person, int save_num);