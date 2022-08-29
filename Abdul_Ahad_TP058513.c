#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void roomtype();
void booking();
void search_booking();
void update_booking();
void receipt();

int main() 
{
    int choice;
    do
    {    
                        // Main Menu 
        // Asking the user choice what they want to do.
        printf("\nWelcome to the Hotel Room Booking \n");
        printf("\nTo See All Rooms Details <Press 1>\n");
        printf("To Book a Room <Press 2>\n");
        printf("To Search Booking Details <Press 3>\n");
        printf("To Update Booking Details <Press 4>\n");
        printf("To View Receipt <Press 5>\n");
        printf("Exit <Press 6>\n");
        printf("\nEnter a choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                roomtype();
                break;
            case 2:
                booking();
                break;
            case 3:
                search_booking();
                break;
            case 4:
                update_booking();
                break;
            case 5:
                receipt();
                break;
            case 6:
                printf("\nThank you For Choosing Us!\n");
                break;
            default:
                printf("\nIncorrect Input.Try again!\n");
                break;
        }

    } while (choice !=6);
	return 0;
}

                        //(1) Room Types Table: It Shows the Room with RoomID, Price and Type.
void roomtype(){
    printf("\nFloor No.01\n");
	printf("RoomID      Room Type           Price per day\n");
    printf("101         Superior            RM180\n");
    printf("102         Deluxe              RM200\n");
    printf("103         Studio              RM250\n");
    printf("104         Executive Suite     RM400\n");
    printf("105         Deluxe Suite        RM500\n");
    printf("\nFloor No.02\n");
    printf("RoomID      Room Type           Price per day\n");
    printf("201         Superior            RM180\n");
    printf("202         Deluxe              RM200\n");
    printf("203         Studio              RM250\n");
    printf("204         Executive Suite     RM400\n");
    printf("205         Deluxe Suite        RM500\n");

}
                        // (2) Room Booking: Here we ask user the important details like name,passport,email,contact,room,daysofstay etc to get register for the room.

void booking(){    
    char customername[40];
    char ic_passportno[12];
    char contactnumber[12];
    char email[30];
    int roomid;
    int daysofstay;

    int idroom;
    int record=0;
    int record2=0; 

    while (1)
    {
        FILE *f;

        f= fopen("bookingdetails.txt", "a");
    
        while (getchar() != '\n'); 
        printf("\nEnter your Name: "); 
        gets(customername);
        fprintf(f,"\n%s ",customername);

        printf("Enter your IC/Passport: ");
        scanf("%s",ic_passportno);
        fprintf(f,"%s ",ic_passportno);

        printf("Enter your Contact Number: ");
        scanf("%s",contactnumber);
        fprintf(f,"%s ",contactnumber);

        printf("Enter your Email: ");
        scanf("%s",email);
        fprintf(f,"%s ",email);

        printf("Enter the Number of Days of Stay: ");
        scanf("%d",&daysofstay);
        if(daysofstay > 0 && daysofstay <=7 )
        {
            fprintf(f,"%ddays ",daysofstay);
        }
        else{
            printf("\nIncorrect Input. Try Again!\n");
            continue;
        }
        do
        {    
            printf("Enter the Room ID: ");
            scanf("%d",&roomid);

            FILE *fz; 
            fz= fopen("idroom.txt", "r");

            while (!feof(fz))
            {
                fscanf(fz,"%d",&idroom);
                if (roomid == idroom)
                {
                    record++;
                    record2=1;
                    break;
                }
            }
            if (record != 0)
            {
                printf("\nRoom is Booked. Try Another Room!\n");
                continue;
            }
            fclose(fz);
        } while (roomid == idroom);

        FILE *fy; 
        fy= fopen("idroom.txt", "a");
        
        fprintf(f,"%d ",roomid);

        // To Calculate Total Cost of Room including taxes.
        int totalroom101_201 = (180 * daysofstay * 0.1)  + (10 * daysofstay) + (180 * daysofstay);
        int totalroom102_202 = (200 * daysofstay * 0.1)  + (10 * daysofstay) + (200 * daysofstay);
        int totalroom103_203 = (250 * daysofstay * 0.1)  + (10 * daysofstay) + (250 * daysofstay);
        int totalroom104_204 = (400 * daysofstay * 0.1)  + (10 * daysofstay) + (400 * daysofstay);
        int totalroom105_205 = (500 * daysofstay * 0.1)  + (10 * daysofstay) + (500 * daysofstay);
        if (roomid >=101 && roomid <=105 )
        {
            if (roomid==101)
            {
                fprintf(f,"RM%d Total Charges",totalroom101_201);
                printf("\nCongratulations! Booking is Successful\n");
            }
            else if (roomid==102)
            {
                fprintf(f,"RM%d Total Charges",totalroom102_202);
                printf("\nCongratulations! Booking is Successful\n");
            }
            else if (roomid==103)
            {
                fprintf(f,"RM%d Total Charges",totalroom103_203);
                printf("\nCongratulations! Booking is Successful\n");
            }
            else if (roomid==104)
            {
                fprintf(f,"RM%d Total Charges",totalroom104_204);
                printf("\nCongratulations! Booking is Successful\n");
            }
            else if (roomid==105)
            {
                fprintf(f,"RM%d Total Charges",totalroom105_205);
                printf("\nCongratulations! Booking is Successful\n");
            }
        }
        else if (roomid >=201 && roomid <=205 )
        {
            if (roomid==201)
            {
                fprintf(f,"RM%d Total Charges",totalroom101_201);
                printf("\nCongratulations! Booking is Successful\n");
            }
            else if (roomid==202)
            {
                fprintf(f,"RM%d Total Charges",totalroom102_202);
                printf("\nCongratulations! Booking is Successful\n");
            }
            else if (roomid==203)
            {
                fprintf(f,"RM%d Total Charges",totalroom103_203);
                printf("\nCongratulations! Booking is Successful\n");
            }
            else if (roomid==204)
            {
                fprintf(f,"RM%d Total Charges",totalroom104_204);
                printf("\nCongratulations! Booking is Successful\n");
            }
            else if (roomid==205)
            {
                fprintf(f,"RM%d Total Charges",totalroom105_205);
                printf("\nCongratulations! Booking is Successful\n");
            }
            
        }
        else
        {
            printf("\nRoom ID is incorrect. Try Again!\n");
            continue;
        }
        fprintf(fy,"%d\n",roomid);
        fclose(f);
        fclose(fy);
        break;
    }
        
}
                                // (3) Search Booking Details: Here user can search the booking details after booking the room.
void search_booking(){ 

    FILE *f;
    f= fopen("bookingdetails.txt", "r");
    
    int record =0;
    char passport[10];
    
    char customerfirstname[20];
    char customersecname[20];
    char ic_passportno[12];
    char contactnumber[15];
    char email[30];
    char daysofstay[20];
    char roomid[20];
    char price[10];
    char total[10];
    char charges[10];

    printf("Enter IC/Passport: ");
    scanf("%s",passport);
    
    if (f == NULL)
    {
        printf("File is not Found");
    
        exit(0);
    }
    while (!feof(f))
    {
        fscanf(f,"%s %s %s %s %s %s %s %s %s %s\n", customerfirstname,customersecname,ic_passportno,contactnumber,email,daysofstay,roomid,price,total,charges);
        if(strstr(passport,ic_passportno) != NULL){ 
            printf("\nFounded\n");
            printf("Name:%s %s IC/Passport:%s Contact No:%s Email:%s Staying Days:%s Room ID:%s Total Charges:%s \n",customerfirstname,customersecname,ic_passportno,contactnumber,email,daysofstay,roomid,price,total,charges);
            record=1;
        }
    }
    if (record==0)
    {
        printf("\nNot Found\n");
    }
    fclose(f);
}
                            // (4) Update Booking Details: Here user can update the booking details like contactno and email.
void update_booking(){
        
    FILE *f;
    f= fopen("bookingdetails.txt", "r");

    FILE *fnew;
    fnew= fopen("bookingdetailsnew.txt", "a");

    int record =0;
    char passport[10];
    char check[30];

    char customerfirstname[20];
    char customersecname[20];
    char ic_passportno[12];
    char contactnumber[15];
    char email[30];
    char daysofstay[20];
    char roomid[20];
    char price[10];
    char total[10];
    char charges[10];

    printf("Enter IC/Passport to check: ");
    scanf("%s",passport);

    if (f == NULL) 
    {
        printf("File is not Found");
        exit(0);
    }
    while (!feof(f))
    {
        fscanf(f,"%s %s %s %s %s %s %s %s %s %s\n", customerfirstname,customersecname,ic_passportno,contactnumber,email,daysofstay,roomid,price,total,charges);

        if(strstr(passport,ic_passportno) != NULL){ 
            printf("Enter the Phone Number to edit: ");
            scanf("%s",check);
            strcpy(contactnumber,check);
            printf("Enter the Email to edit: ");
            scanf("%s",check);
            strcpy(email,check);;
            record=1;
        }
        fprintf(fnew,"%s %s %s %s %s %s %s %s %s %s\n", customerfirstname,customersecname,ic_passportno,contactnumber,email,daysofstay,roomid,price,total,charges);
    }
    if (record==0)
    {
        printf("\nNot Found\n");
    }
    
    fclose(f);
    fclose(fnew);
    remove("bookingdetails.txt");
    rename("bookingdetailsnew.txt", "bookingdetails.txt");
}
                                // (5) Receipt Details: Here user can see the reciept with all the booking details like name,passport,contact,email,roomid,charges etc. 
void receipt(){ 

    FILE *f;
    f= fopen("bookingdetails.txt", "r");
    int record =0;
    char passport[10];

    char customerfirstname[20];
    char customersecname[20];
    char ic_passportno[12];
    char contactnumber[15];
    char email[30];
    char daysofstay[20];
    char roomid[20];
    char price[10];
    char total[10];
    char charges[10];

    printf("Enter IC/Passport: ");
    scanf("%s",passport);

    if (f == NULL)
    {
        printf("File is not Found");

        exit(0);
    }
    while (!feof(f))
    {
        fscanf(f,"%s %s %s %s %s %s %s %s %s %s\n", customerfirstname,customersecname,ic_passportno,contactnumber,email,daysofstay,roomid,price,total,charges);
        if(strstr(passport,ic_passportno) != NULL){ 
            printf("\n\t\t*******Receipt*******");
            printf("\n\t\tName:%s %s\n\t\tIC/Passport:%s\n\t\tContact No:%s\n\t\tEmail:%s\n\t\tStaying Days:%s\n\t\tRoom ID:%s\n\t\tTotal Charges:%s\n",customerfirstname,customersecname,ic_passportno,contactnumber,email,daysofstay,roomid,price);
            record=1;
        }
    }
    if (record==0)
    {
        printf("\nNot Found\n");
    }
    
    fclose(f);
}
