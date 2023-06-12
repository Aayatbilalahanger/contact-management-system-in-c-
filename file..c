#include<stdio.h>
struct contact{
    char name[50];
    char phone[20];
    char email[50];
};
void addcontact(){
    struct contact cns;
    printf("enter name:\n");
    scanf("%s",cns.name);
    printf("enter phone number:\n");
    scanf("%s",cns.phone);
    printf("enter email\n");
    scanf("%s",cns.email);
    FILE *file = fopen("contact.txt","a");
    if(file != NULL){
        fprintf(file,"%s %s %s",cns.name,cns.phone,cns.email);
        fclose(file);
        printf("contact added sucessfully");

    }
    else{
        printf("failed to open file");
    }
}
void displaycontact(){
    FILE *file = fopen("contact.txt","r");
    if(file != NULL){
        struct contact cns;
        printf("contacts\n");
        while(fscanf(file,"%s %s %s",cns.name,cns.phone,cns.email) == 3){
            printf("name %s, phone : %s , email %s\n",cns.name,cns.phone,cns.email);
        }
        fclose(file);
    }
    else{
        printf("failed to open file");

    }
}

void search(){
    char searchname[50];
    printf("enter name to search:");
    scanf("%s",search);
    FILE *file = fopen("contact.txt","r");
    if(file != NULL){
        struct contact cns;
        int found = 0;
        while(fscanf(file,"%s %s %s\n",cns.name,cns.phone,cns.email)==3){
            printf("contact found");
            printf("name %s , ph %s , email %s",cns.name,cns.phone,cns.email);
            found =1;
            break;
        }
        if(!found){
            printf("contact not found");
        }
        fclose(file);


    }
    else{
        printf("failed to open file");
    }
}
int main(){
    int ch;
    do{
        printf("contact management system\n");
        printf("1.addcontact\n");
        printf("2.display contact\n");
        printf("3.search contact\n");
        printf("4.exit");
        printf("enter your choice\n");
        scanf("%d",&ch);
        switch(ch){
            case 1: addcontact();
            break;
            case 2: displaycontact();
            break;
            case 3: search();
            break;
            case 4:printf("exiting");
        }
        printf("\n");

    } while(ch != 4);
    return 0;
}