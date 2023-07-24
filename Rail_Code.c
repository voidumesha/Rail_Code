#include<stdio.h>
#include <string.h>
#include <Windows.h>


void banner()
{
    printf("\n\n\t\t\t\t\t ==> TRAIN TICKET BOOKING SYSTEM <== \n\n");
    printf("\t\t\t ____    __    _____  _             _____  ____   _____   _____ \n");
    printf("\t\t\t|    |  |  |     |    |            |      |    |   |   | | \n");
    printf("\t\t\t|____| |____|    |    |            |      |    |   |   | |_____    \n");      //Rail_code Banner
    printf("\t\t\t|_     |    |    |    |            |      |    |   |   | |\n");
    printf("\t\t\t| '_   |    |  __|__  |____        |_____ |____|  _|___| |_____   \n");
    printf("\t\t\t|   '_                      ______                      \n\n\n\n");
}

void Train_schedule()
{
    printf("\t\t-----------------------------------------------------------------------------------------------\n");
    printf("\t\t T-Name                Date:             Time:                 Rute:\n");
    printf("\t\t-----------------------------------------------------------------------------------------------\n");
    printf("\t\t//GALLE EXPRESS            2022 july 30      06.00AM               Kollupitiya To Mount-Levinia\n");
    printf("\t\t//YAL-DEVI EXPRESS         2022 july 30      10.00AM               Mount-Levinia To Kollupitiya\n");
    printf("\t\t//PAHATHARATA EXPRESS      2022 july 30      02.00PM               Kollupitiya To Mount-Levinia\n");
    printf("\t\t//SPIDER EXPRESS           2022 july 30      06.00PM               Mount-Levinia To Kollupitiya\n");
    printf("\t\t//RUHUNU EXPRESS           2022 july 30      10.00PM               Kollupitiya To Mount-Levinia\n");
    printf("\t\t-----------------------------------------------------------------------------------------------\n");
    printf("\t\t-----------------------------------------------------------------------------------------------\n\n");          //Time schedule

    printf("\t\t-----------------------------------------------------------------------------------------------\n");
    printf("\t\t//START_DESTINATONS         END-DESTINATONS             ARRIVING-TIME(DEPEND)\n");
    printf("\t\t-----------------------------------------------------------------------------------------------\n");
    printf("\t\t*KOLLUPITIYA               BAMBALAPITIYA               At Least 5.00 min\n");
    printf("\t\t*BAMBALAPITIYA             WELLAWATHTHA                At Least 6.00 min\n");
    printf("\t\t*WELLAWATHTHA              DEHIWALA                    At Least 8.00 min\n");
    printf("\t\t*DEHIWALA                  MOUNT-LEVINIA               At Least 6.00 min\n");
    printf("\t\t-----------------------------------------------------------------------------------------------\n");
    printf("\t\t-----------------------------------------------------------------------------------------------");



}
/*

void group(){

    printf(

           "__________ _____.___.      __________________ ________    ____ ___ __________     ________ _______ \n"
           "\\______  \\\\__  |   |     /  _____/\\______   \\_____  \\  |    |   \\______   \\    \\_____  \\   _  \\ \n"
            "|    |  _/ /   |   |    /   \\  ___ |       _/ /   |   \\ |    |   / |     ___/     /  ____//  /_\\  \\ \n"
            "|    |   \\ \\____   |    \\    \\_\\  \\|    |   \\/    |    \\|    |  /  |    |        /       \\  \\_/   \\ \n"
            "|______  / / ______|     \\______  /|____|_  /\\_______  /|______/   |____|        \\_______ \\_____  / \n"
            "       \\/  \\/                   \\/        \\/         \\/                                  \\/      \\/ \n"

              );
        /*" __________ _____.___.      __________________ ________    ____ ___ __________     ________ _______ \n"
           "\______   \\__  |   |     /  _____/\______   \\_____  \  |    |   \\______   \    \_____  \\   _  \ \n"
            "|    |  _/ /   |   |    /   \  ___ |       _/ /   |   \ |    |   / |     ___/     /  ____//  /_\  \ \n"
            "|    |   \ \____   |    \    \_\  \|    |   \/    |    \|    |  /  |    |        /       \\  \_/   \ \n"
            "|______  / / ______|     \______  /|____|_  /\_______  /|______/   |____|        \_______ \\_____  / \n"
            "       \/  \/                   \/        \/         \/                                  \/      \/ \n"



}


*/


// Data Initialization


struct userData{ // User data Struct
    char name[100];
    char contact[11];
    char email[50];
    char address[100];
    char nic[13];
    int age;
    char startcode[4];
    char endcode[4];

};


char validNumberPrefixes[7][4] = {"071\x0","072\x0","074\x0","075\x0","076\x0","077\x0","078\x0"}; // Mobile Number Prefixes
char validStationCodes[9][4] = {"001\x0","002\x0","003\x0","004\x0","005\x0","006\x0","007\x0","008\x0","009\x0"}; // Station codes

void printStations(){
    printf("Station Name                 Station Code\n");
    printf("------------------------------------------\n");
    printf(" Maradana                       001\n");
    printf(" Dematagoda                     002\n");
    printf(" Kelaniya                       003\n");
    printf(" Wanawasala                     004\n");
    printf(" Hunupitiya                     005\n");
    printf(" Enderamulla                    006\n");
    printf(" Horape                         007\n");
    printf(" Ragama                         008\n");
    printf(" Walpola                        009\n");
    printf("------------------------------------------\n");

}


int verifyContact(char *number){  // Verify Mobile Number by Checking length and Prefixes
    char prefix[4];
    int flag=0;

    memset(&prefix,0,sizeof(prefix));
    strncpy(prefix,number,3);

    if(strlen(number)== 10){
        for(int i=0;i<7;i++){
            if(strcmp(prefix,validNumberPrefixes[i])==0){
                return 0;
            }
        }
    }

    printf("Mobile Number is incorrect please check again \n");
    Sleep(2000);
    return 1;
}


int verifyNIC(char *nic){
    if(strlen(nic)==12 | strlen(nic)==10){
        return 0;
    }
    printf("NIC number is incorrect please check again \n");
    Sleep(2000);
    return 1;
}


int verifyEmail(char *email){
    int atcount = 0;
    char *pointer = email;
    while(*pointer){
        if(strchr("@",*pointer)){
            atcount++;
        }
        pointer++;
    }
    switch(atcount){
        case 1:
            return 0;
        default:
            printf("Invalid Email , Check email again \n");
            Sleep(2000);
            return 1;
    }

}

int checkValidCodes(char *code){
    int size = sizeof(validStationCodes)/sizeof(validStationCodes[0]);

    if(strlen(code)==3){
    for(int i=0;i<size;i++){
            if(strcmp(code,validStationCodes[i])==0){
                return 0;
            }
        }
    }
    printf("Invalid Station Code.\n");
    Sleep(2000);
    return 1;
}

void clearscrn(){

    system("cls");
    banner();
}

void printUserDetails(struct userData *ptr){

    printf("User Name: %s\n",ptr->name);
    printf("User Address: %s\n",ptr->address);
    printf("User Contact: %s\n",ptr->contact);
    printf("User Email: %s \n",ptr->email);
    printf("User Age: %d\n",ptr->age);
    printf("User NIC: %s\n",ptr->nic);
}


void getUserData(struct userData *ptr){ //Getting users details

    printf("Enter your name: ");
    scanf("%s",&ptr->name);
    clearscrn();

    printf("Enter address: ");
    scanf("%s",&ptr->address);
    clearscrn();

    printf("Enter your mail: ");
    scanf("%49s",ptr->email);
    while(verifyEmail(ptr->email)){
        clearscrn();
        printf("Enter your mail: ");
        scanf("%49s",ptr->email);
    }
    clearscrn();

    printf("Enter your age(int): ");
    scanf("%d",&ptr->age);
    clearscrn();

    printf("Enter your nic: ");
    scanf("%12s",ptr->nic);
    while(verifyNIC(ptr->nic)){
        clearscrn();
        printf("Enter your nic: ");
        scanf("%12s",ptr->nic);
    }
    clearscrn();

    printf("Enter your mobile number: ");
    scanf("%10s",ptr->contact);
    while(verifyContact(ptr->contact)){
        clearscrn();
        printf("Enter your mobile number: ");
        scanf("%10s",ptr->contact);
    }

}

void getStations(struct userData *ptr){

    printf("Enter Start Code : ");
    scanf("%3s",ptr->startcode);
    while(checkValidCodes(ptr->startcode)){
        clearscrn();
        printStations();
        printf("Enter Start Code : ");
        scanf("%3s",ptr->startcode);
    }

    printf("Enter End Code : ");
    scanf("%3s",ptr->endcode);
    while(checkValidCodes(ptr->endcode)){
        clearscrn();
        printStations();
        printf("Enter End Code : ");
        scanf("%3s",ptr->endcode);
    }

}



int main(){

  //  banner();
  //  group();

    /*struct userData User;
    memset(&User, 0, sizeof(struct userData));
    clearscrn();
    getUserData(&User);
    printStations();
    getStations(&User);
    clearscrn();
    Train_schedule();
   // printUserDetails(&User);*/

   FILE* saveData;
   char name[100];
   saveData=fopen("savingData.txt","w");
   printf("Enter saving exaples: ");
   scanf("%s",name);
   fprintf(saveData,name);
   fclose(saveData);



    return 0;
}


