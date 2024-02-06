#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>


// Function declaration
int menu(struct vehicles &v);
void status(struct vehicles &v);
void data_to_file(struct vehicles &v);
void displayCounts(struct vehicles &v);
void r(struct vehicles &v);
void two(struct vehicles &v);
void c(struct vehicles &v);
void b(struct vehicles &v);
void t(struct vehicles &v);
int admin_login();
void reciept(struct vehicles &v,const char *vehicle_type,int vehicle_amount);
void payment_option(struct vehicles &v,int c);
void assign_choice(struct vehicles &v,int c);
void display_status(struct vehicles &v);
void bicycle(struct vehicles &v);

// Defining username and password
#define user "moin"
#define pass "moin"

// LIMIT OF NUMBER OF VEHICLES
#define MAX_RICKSHAW 3
#define MAX_TWO_WHEELER 8
#define MAX_CAR 5
#define MAX_BUS 2
#define MAX_TRUCK 2
#define MAX_BICYCLE 5

//STRUCTURE DECLARATION FOR VARIABLE
struct vehicles{
	int bicycle;
	int rickshaw;
	int two_wheeler;
	int car;
	int bus;
	int truck;
	int amount;
	int count;
	char vehicle_no[10];
	int amount_cash;
	int amount_online;
	int menu_choice;
	int reciept;
	char date[11];
};

//MAIN FUNCTION STARTS

int main()
{
	struct vehicles v1={0};
	system("cls");
	printf("\n\n\n\n\n");
	 printf("\t\t\t         WELCOME TO MV PARKING PLOT \n");
	 printf("\n");
	 printf("\t\t---------------------------------------------------- ");
	 printf("\n\n");
	 printf("\t\t\t                ADMIN LOGIN                   \n");
	 printf("\t\t\t               -------------                  \n\n");
	if(!admin_login())
	{
		printf("\t\t\t AUTHENTICATION FAILED EXITING....\t\t\t ");
		printf("\n\n\t\t\t PRESS ANY KEY TO EXIT.....");
		printf("\n\t\t---------------------------------------------------- ");
		getch();
	}
	else
	{
    system("cls");
    while (1)
    {
	 printf("\n");
	 printf("\t\t\t          WELCOME  TO  MV  PARKING  PLOT \n");
	 printf("\t\t\t---------------------------------------------------");
	 printf("\n");
	 printf("\t\t\t            PARKING  AT  OWNER'S  RISK              ");
	 display_status(v1);
	switch (menu(v1))
	{
	case 0:
	{
		bicycle(v1);
		printf("\nTO PROMOTE CYCLING PARKING FEE FOR BICYCLE IS ZERO...\n");
		printf("PRESS ANY KEY TO CONTINUE........");
		getch();
		system("cls");
		break;
	}
	case 1:
	{
		two(v1);
		getch();
	    system("cls");
	    break;
	}
	case 2:
	{
		r(v1);
	    getch();
	    system("cls");
	    break;
	}
	case 3:
	{
		c(v1);
	    getch();
	    system("cls");
	    break;
	}
	case 4:
	{
		b(v1);
	    getch();
	    system("cls");
	    break;
	}
	case 5:
	{
		t(v1);
	    getch();
	    system("cls");
	    break;
	}
	case 6:
	{
		status(v1);
	    getch();
	    system("cls");
	    break;
	}
	case 7:
	{
	    displayCounts(v1);
	    getch();
	    system("cls");
	    break;
	}
	case 8:
	{
		data_to_file(v1);
	    getch();
	    system("cls");
	    break;
	}
	case 9:
	{
	    printf("EXITING......");
		exit(0);
	    break;
	}
	default:
	{
	    printf("INVALID INPUT\n");
		getch();
	    system("cls");
	    break;
	}
	}
    }
    }
    return 0;
}

// MAIN FUNCTION ENDS


//FUNCTION DEFINITION
void bicycle(struct vehicles &v)
{
	 if (v.rickshaw < MAX_RICKSHAW)
    {
		v.bicycle++;
	}
	else
	{
		printf("Parking lot for BICYCLE  is full.\n");
	}
}
void display_status(struct vehicles &v)
{
	printf("\n\n");
	printf("\t\t|-----------------------------------------------------------------------------|\n");
	printf("\t\t|                                SLOTS REMAINING                              |\n");
	printf("\t\t|-----------------------------------------------------------------------------|\n");
	printf("\t\t|BICYCLE     TWO-WHEELER        RICKSHAW         CAR         BUS        TRUCK |\n");
	printf("\t\t|    %d                %d               %d           %d           %d         %d     |\n",MAX_BICYCLE-v.bicycle,MAX_TWO_WHEELER-v.two_wheeler,
	MAX_RICKSHAW-v.rickshaw,MAX_CAR-v.car,MAX_BUS-v.bus,MAX_TRUCK-v.truck);
	printf("\t\t|-----------------------------------------------------------------------------|\n");
}
void assign_choice(struct vehicles &v,int c)
{
	v.menu_choice=c;
}
void payment_option(struct vehicles &v,int c)
{
	switch(v.menu_choice)
	{
		case 1 :
		{
			if(c==1)
			{
				v.amount_cash+=20;
			}
			else
			{
				v.amount_online+=20;
			}
			break;
		}
		case 2 :
		{
			if(c==1)
			{
				v.amount_cash+=50;
			}
			else
			{
				v.amount_online+=50;
			}
			break;
		}
		case 3 :
		{
			if(c==1)
			{
				v.amount_cash+=70;
			}
			else
			{
				v.amount_online+=70;
			}
			break;
		}
		case 4 :
		{
			if(c==1)
			{
				v.amount_cash+=100;
			}
			else
			{
				v.amount_online+=100;
			}
			break;
		}
		case 5 :
		{
			if(c==1)
			{
				v.amount_cash+=100;
			}
			else
			{
				v.amount_online+=100;
			}
			break;
		}
	}
}

void reciept(struct vehicles &v,const char *vehicle_type,int vehicle_amount)
{
	int paymentOption;
	do
	{	
		system("cls");
		v.reciept++;
		printf("\n\n\n");
		printf("\t\t\t-----------------------------------------------------\n");
		printf("\t\t\t               PAYMENT RECEIPT                       \n ");
		printf("\t\t\t-----------------------------------------------------\n");
		printf("\t\t\t  RECIEPT NO        : %d                          \n",v.reciept);
		printf("\t\t\t  VEHICLE TYPE      : %s                          \n",vehicle_type);
		printf("\t\t\t  VEHICLE NO        : %s                          \n",v.vehicle_no);
		printf("\t\t\t  AMOUNT TO BE PAID : Rs. %d                         \n",vehicle_amount);
		printf("\t\t\t-----------------------------------------------------\n");
		printf("\t\t\t  PAYMENT OPTIONS:                                   \n");
		printf("\t\t\t  1. CASH                                            \n");
		printf("\t\t\t  2. ONLINE                                          \n");
		printf("\t\t\t-----------------------------------------------------\n");
		printf("\t\t\t  Please select a payment option: ");
		scanf("%d", &paymentOption);
		printf("\t\t\t----------------------------------------------------\n");


		printf("\n\n\t\t\t----------------------------------------------\n");
		switch (paymentOption) {
			case 1:
				printf("\t\t\tThank you! Please pay in cash at the counter.\n");
				break;
			case 2:
				printf("\t\t\tThank you! Your online payment has been processed.\n");
				break;
			default:
				printf("\t\t\t  Invalid payment option.\n");
				printf("\t\t\tPRESS ANY KEY TO RE-ENTER PAYMENT MODE.\n");
				getch();
				break;
		}
	}while(paymentOption>2);
		payment_option(v,paymentOption);

		printf("\t\t\t------------------------------------------------\n");
		printf("PRESS ANY KEY TO CONTINUE");
		v.count++;
}

int admin_login()
{
	char username[20];
	char password[8];

	printf("\t\t\t ENTER USERNAME : ");
	scanf("\t\t\t %s",username);
	printf("\t\t\t ENTER PASSWORD : ");
	scanf("\t\t\t %s",password);

	if((strcmp(username,user)==0)&&(strcmp(password,pass)==0))
	{
		printf("\t\t\t AUTHENTICATION SUCCESSFULL\t\t\t");
		printf("\n\n\t\t\t PRESS ANY KEY TO CONTINUE....");
		printf("\n\t\t---------------------------------------------------- ");
		getch();
		return 1;
	}
	else
	{
		return 0;
	}
}
int menu(struct vehicles &v)
{	
	int choice;
	printf("\n\t\t\t============================================");
	printf("\n\t\t\t|                     MENU                 |");
	printf("\n\t\t\t============================================");
    printf("\n\t\t\t|          0. BICYCLE [FREE]               |");
    printf("\n\t\t\t|          1. TWO WHEELER [RS : 20]        |");
    printf("\n\t\t\t|          2. RICKSHAW [RS : 50]           |");
    printf("\n\t\t\t|          3. CAR [RS : 70]                |");
    printf("\n\t\t\t|          4. BUS [RS : 100]               |");
    printf("\n\t\t\t|          5. TRUCK [RS : 100]             |");
    printf("\n\t\t\t|          6. STATUS                       |");
    printf("\n\t\t\t|          7. DISPLAY COUNTS               |");
    printf("\n\t\t\t|          8. END THE DAY                  |");
    printf("\n\t\t\t|          9. EXIT                         |");
	printf("\n\t\t\t============================================");
    printf("\n\t\t\t         ENTER CHOICE  : ");
    scanf("%d",&choice);
	printf("\n\t\t\t============================================");
	
	assign_choice(v,choice);
    printf("\n\n");
    return choice;
}

void status(struct vehicles&v)
{
	system("cls");
    printf("\n-----------------------------------------------");
    printf("\n\t\t Parking Lot Status");
    printf("\n-----------------------------------------------");
    printf("\n BICYCLE        : %d / %d", v.bicycle, MAX_BICYCLE);
    printf("\n Rickshaws      : %d / %d", v.rickshaw, MAX_RICKSHAW);
    printf("\n Two-Wheelers   : %d / %d", v.two_wheeler, MAX_TWO_WHEELER);
    printf("\n Cars           : %d / %d", v.car, MAX_CAR);
    printf("\n Buses          : %d / %d", v.bus, MAX_BUS);
    printf("\n Trucks         : %d / %d", v.truck, MAX_TRUCK);
    printf("\n------------------------------------------------");
	printf("\n TOTAL RECIEPT GENERATED   : %d",v.reciept);
	printf("\n AMOUNT RECIEVED [CASH]    : RS.%d",v.amount_cash);
	printf("\n AMOUNT RECIEVED [ONLINE]  : RS.%d",v.amount_online);
    printf("\n TOTAL EARNINGS            : RS.%d",v.amount);
    printf("\n-------------------------------------------------\n");
	printf("\n         PRESS ANY TO CONTINUE........");
}

void data_to_file(struct vehicles &v)
{

	FILE *fp;
	fp=fopen("parking.txt","a+");

	if(fp==NULL)
	{
		fprintf(stderr,"FILE CANNOT BE OPENED");
	}
	fprintf(fp,"BICYCLE : %d\n",v.bicycle);
	fprintf(fp,"TWO_WHEELER : %d\n",v.two_wheeler);
	fprintf(fp, "RICKSHAW : %d\n",v.rickshaw);
	fprintf(fp,"CAR : %d\n",v.car);
	fprintf(fp,"TRUCK : %d\n",v.truck);
	fprintf(fp,"BUS : %d\n",v.bus);
	fprintf(fp,"TOTAL RECIEPT GENERATED : %d\n",v.reciept);
	fprintf(fp,"AMOUNT RECIEVED IN CASH : %d\n",v.amount_cash);
	fprintf(fp,"AMOUNT RECIEVED ONLINE : %d\n",v.amount_online);
	fprintf(fp,"TOTAL EARNING : %d\n",v.amount);
	fprintf(fp,"-----------------------------------------------\n");

	fclose(fp);

    v.bicycle=0;
	v.rickshaw = 0;
    v.two_wheeler = 0;
    v.car = 0;
    v.bus = 0;
    v.truck = 0;
    v.amount = 0;
    v.count = 0;

    printf("Data saved to file successfully.\n");

}


void r(struct vehicles &v)
{
    if (v.rickshaw < MAX_RICKSHAW)
    {
	printf("\t\t ENTER VEHICLE NO IN THIS FORMAT [GJ01XC7394] : ");
	scanf("%s",v.vehicle_no);
	for(int i=0;v.vehicle_no[i]!='\0';i++)
	{
		v.vehicle_no[i] = toupper(v.vehicle_no[i]);
	}

	v.rickshaw++;
	v.amount = v.amount + 50;
	reciept(v,"RICKSHAW",50);
    }
    else
    {
	printf("Parking lot for Rickshaws is full.\n");
    }
}

void two(struct vehicles &v)
{
    if (v.two_wheeler < MAX_TWO_WHEELER)
    {
	printf("\t\t ENTER VEHICLE NO IN THIS FORMAT [GJ01XC7394] : ");
	scanf("%s",v.vehicle_no);
	for(int i=0;v.vehicle_no[i]!='\0';i++)
	{
		v.vehicle_no[i] = toupper(v.vehicle_no[i]);
	}
	v.two_wheeler++;
	v.amount = v.amount + 20;
	reciept(v,"TWO WHEELER",20);
    }
    else
    {
	printf("Parking lot for Two-Wheelers is full.\n");
    }
}

void c(struct vehicles &v)
{
    if (v.car < MAX_CAR)
    {
	printf("\t\t ENTER VEHICLE NO IN THIS FORMAT [GJ01XC7394] : ");
	scanf("%s",v.vehicle_no);
	for(int i=0;v.vehicle_no[i]!='\0';i++)
	{
		v.vehicle_no[i] = toupper(v.vehicle_no[i]);
	}
	v.car++;
	v.amount = v.amount + 70;
	reciept(v,"CAR",70);
    }
    else
    {
	printf("Parking lot for Cars is full.\n");
    }
}

void b(struct vehicles &v)
{
    if (v.bus < MAX_BUS)
    {
	printf("\t\t ENTER VEHICLE NO IN THIS FORMAT [GJ01XC7394] : ");
	scanf("%s",v.vehicle_no);
	for(int i=0;v.vehicle_no[i]!='\0';i++)
	{
		v.vehicle_no[i] = toupper(v.vehicle_no[i]);
	}
	v.bus++;
	v.amount = v.amount + 100;
	reciept(v,"BUS",100);
    }
    else
    {
	printf("Parking lot for Buses is full.\n");
    }
}

void t(struct vehicles &v)
{
    if (v.truck < MAX_TRUCK)
    {
	printf("\t\t ENTER VEHICLE NO IN THIS FORMAT [GJ01XC7394] : ");
	scanf("%s",v.vehicle_no);
	for(int i=0;v.vehicle_no[i]!='\0';i++)
	{
		v.vehicle_no[i] = toupper(v.vehicle_no[i]);
	}
	v.truck++;
	v.amount = v.amount + 100;
	reciept(v,"TRUCK",100);
    }
    else
    {
	printf("Parking lot for Trucks is full.\n");
    }
}

void displayCounts(struct vehicles &v)
{
    system("cls");
	printf("\n------------------------------------------");
    printf("\n\t\t Vehicle Counts");
    printf("\n------------------------------------------");
    printf("\n Rickshaws\t: %d", v.rickshaw);
    printf("\n Two-Wheelers\t: %d", v.two_wheeler);
    printf("\n Cars\t\t: %d", v.car);
    printf("\n Buses\t\t: %d", v.bus);
    printf("\n Trucks\t\t: %d", v.truck);
    printf("\n------------------------------------------\n");
}
