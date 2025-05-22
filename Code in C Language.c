#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct details 
{
    char d_name[100];
    int  d_age;
    char d_password[100];
    char d_email[100];
    char d_mobile[10];
};
struct hotels 
{
    char hotel[100];
    char first_food[20];
    char second_food[20];
    char third_food[20];
    char fourth_food[20];
    char fifth_food[20];
    int first, second, third, fourth, fifth;
};
struct card
{
	char c_name[20];
	char c_bank[20];
	int c_num,cvv;	
};
struct hotels m[5];
struct details s[100];
struct card a[20];

void signup();
void account_check();
int validate();
void login();
void cart();
void payment();
void rating();
void search_by_hotels();
void search_by_food();
void food_order(int food);
void hotel_initialize();
void hotels(int hotel_choice);
char c_name[20],c_bank[20];
int c_num,cvv;
int flag = 1, i, j = 0, count = 0, caps = 0;
int small = 0, special = 0, numbers = 0;
int success = 0, x, choice;
char name[100],password1[100];
char password2[100],email[100];
char mobile[100];
int age, total = 0, food_choice, n;
int hotel_choice, search_choice, confirm;
int ch, food, hotel_id;
int ds,as;
int choice;
int main()
{
    while (1) 
	{
        printf("\n\n******Welcome to Online Food Ordering System**** \n");
        printf("1)  SIGNUP\n");
        printf("2)  LOGIN\n ");
		printf("3)  EXIT\n");
        printf("Enter your choice:");
        scanf("%d", &choice);
        switch (choice) 
		{
        case 1: 
		{
            signup();
            break;
        }
        case 2: 
		{
            login();
            break;
        }
        case 3: 
		{
            printf("\n********Thank You Visit Again*****\n");
            exit(0);
            return 0;
        }
        default: 
		{
            printf("\nPlease Enter the valid choice\n");
            break;
        }
        }
    }
}

void signup()
{
    printf("\n\n****Welcome to Signup Page***\n");
    printf("\tEnter Your name: ");
    scanf("%s", name);
 
    printf("\tEnter Your Age: ");
    scanf("%d", &age);
 
    printf("\tEnter Your Email: ");
    scanf("%s",&email);
 
    printf("\tEnter Password: ");
    scanf("%s",&password1);
 
    printf("\tConfirm Password:");
    scanf("%s",&password2);
 
    printf("\nEnter Your Mobile Number: ");
    scanf("%s", mobile);

    x = validate();
    if (x == 1)
	{
        account_check();
        login();
    }
}

int validate()
{
    for (i = 0; name[i] != '\0'; i++) 
	{
        if (!((name[i] >= 'a' && name[i] <= 'z')|| (name[i] >= 'A'&& name[i] <= 'Z'))) 
		{
            printf("\nPlease Enter the valid Name\n");
            flag = 0;
            break;
        }
    }
    if (flag == 1) 
	{
        count = 0;
         for (i = 0;email[i] != '\0'; i++) 
		{
            if (email[i] == '@'|| email[i] == '.')
                count++;
        }
        if (count >= 2&& strlen(email) >= 5) 
		{
            if (!strcmp(password1,password2)) 
			{
                if (strlen(password1) >= 8 && strlen(password1) <= 12) 
					{
                    caps = 0;
                    small = 0;
                    numbers = 0;
                    special = 0;
                    for (i = 0; password1[i] != '\0';i++) 
					{
                        if (password1[i] >= 'A'&& password1[i] <= 'Z')
                            caps++;
                        else if (password1[i] >= 'a'&& password1[i]<= 'z')
                            small++;
                        else if (password1[i] >= '0'&& password1[i]<= '9')
                            numbers++;
                        else if (password1[i] == '@'|| password1[i] == '&'|| password1[i] == '#'|| password1[i]== '*')
                            special++;
                    }
                    if (caps >= 1 && small >= 1
                        && numbers >= 1 && special >= 1) 
						{
                        if (age != 0 && age > 0) 
						{
                            if (strlen(mobile) == 10) 
							{
                                for (i = 0; i < 10; i++) 
								{
                                    if (mobile[i]>= '0'&& mobile[i]<= '9') 
									{
                                        success = 1;
                                    }
                                    else 
									{
                                        printf("\nPlease Enter Valid mobile Number\n\n");
                                        return 0;
                                        break;
                                    }
                                }
                                if (success == 1)
                                    return 1;
                            }
                            else 
							{
                                printf("\nPlease Enter the 10 digit mobile number\n");
                                return 0;
                            }
                        }
                        else 
						{
                            printf("\nPlease Enter the valid age\n");
                            return 0;
                        }
                    }
                    else 
					{
                        printf("\nPlease Enter the Strong Password \n");
                        printf("Your Password must contain-\n");
                        printf("Atleast one Uppercase and Lowercase Number");
						printf("and also a Special Character \n");
                        return 0;
                    }
                }
                else 
				{
                    printf("\nYour Password is very short\n");
					printf("Length must between 8 to 12\n\n");
                    return 0;
                }
            }
            else 
			{
                printf("\nPassword Mismatch\n\n");
                return 0;
            }
        }
        else 
		{
            printf("\nPlease Enter Valid E-Mail\n\n");   
            return 0;
        }
    }
}

void account_check()
{
    for (i = 0; i < 100; i++) 
	{
        if (!(strcmp(email, s[i].d_email) && strcmp(password1,s[i].d_password))) 
		{
            printf("\n\nAccount Already Existed. Please Login !!\n\n");
            main();
            break;
        }
    }
    if (i == 100) 
	{
        strcpy(s[j].d_name,name);
        s[j].d_age =age;
        strcpy(s[j].d_password,password1);
        strcpy(s[j].d_email,email);
        strcpy(s[j].d_mobile,mobile);
        j++;
        printf("\n\n\nAccount Successfully Created!!\n\n");
    }
}
 
void login()
{
    printf("\n\n*****Welcome to Login page *******\n\n");  
    printf("Enter Your Email:");
    scanf("%s",email);
    printf("Enter Your Password:");
    scanf("%s",password1);
    for (i = 0; i < 100; i++) 
	{
        if (!strcmp(s[i].d_email,email)) 
		{
            if (!strcmp(s[i].d_password,password1)) 
			{
                printf("\n\nWelcome %s, ", s[i].d_name);
                printf("Your are successfully logged in\n\n");
                printf("We Provide two ways of search\n ");
                printf("1) Search By Restaurants\n ");
                printf("2) Search by Food\n ");
                printf("3) Exit\n");
                printf("Please Enter your choice:");
                scanf("%d", &search_choice);
                switch (search_choice) 
				{
                case 1: 
				{
                    search_by_hotels();
                    break;
                }
                case 2: 
				{
                    search_by_food();
                    break;
                }
                case 3: 
				{
                    main();
                    return;
                }
                default: 
				{
                    printf("Please Enter the valid choice\n\n ");
                    break;
                }
                }
                break;
            }
            else 
			{
                printf("\n\nInvalid Password! ");
                printf("Please Enter the correct password\n\n");
                main();
                break;
            }
        }
        else 
		{
            printf("\n\nAccount doesn't exist,Please Sign Up!!\n\n ");
            main();
            break;
        }
    }
}
 
void hotel_initialize()
{
	printf("\n\n***Welcome to Hotel Initialize Page****\n");
    strcpy(m[1].hotel, "Mandi.Com");
    strcpy(m[1].first_food, "Fried Mandi");
    strcpy(m[1].second_food, "Faham Mandi");
    strcpy(m[1].third_food, "Juciy mandi");
    strcpy(m[1].fourth_food,"Tandoori Mandi");
    strcpy(m[1].fifth_food,"Mixed Mandi");
    m[1].first = 499;
    m[1].second = 549;
    m[1].third = 599;
    m[1].fourth = 649;
    m[1].fifth = 699;
 
    strcpy(m[2].hotel, "Haritha Hotel");
    strcpy(m[2].first_food, "Veg Biryani");
    strcpy(m[2].second_food, "Manchuriya");
    strcpy(m[2].third_food, "Veg Lollipops");
    strcpy(m[2].fourth_food,"Noodles");
    strcpy(m[2].fifth_food,"Rumall Roti with Punner");
    m[2].first = 270;
    m[2].second = 200;
    m[2].third = 180;
    m[2].fourth =150;
    m[2].fifth = 499; 
 
    strcpy(m[3].hotel, "Badsha Milkshake");
    strcpy(m[3].first_food, "Classic Vanilla");
    strcpy(m[3].second_food, "Chocolate Fudge");
    strcpy(m[3].third_food, "Strawberry Banana");
    strcpy(m[3].fourth_food,"Mint Chocolate Chip");
    strcpy(m[3].fifth_food,"Salted Caramel");
    m[3].first = 90;
    m[3].second = 120;
    m[3].third = 150;
    m[3].fourth = 200;
    m[3].fifth = 250;
    
    strcpy(m[4].hotel, "Rice Fusion");
    strcpy(m[4].first_food, "Chicken Curry");
    strcpy(m[4].second_food, "Grilled Chicken");
    strcpy(m[4].third_food, "Chicken Tikka");
    strcpy(m[4].fourth_food,"Vegetable Pulao");
    strcpy(m[4].fifth_food,"Paneer Masala");
    m[4].first = 250;
    m[4].second = 320;
    m[4].third = 499;
    m[4].fourth = 399;
    m[4].fifth = 439;
    
    strcpy(m[5].hotel, "Ram kii Bandi");
    strcpy(m[5].first_food, "Idli");
    strcpy(m[5].second_food, "Vada");
    strcpy(m[5].third_food, "Dosa");
    strcpy(m[5].fourth_food,"Uttapam");
    strcpy(m[5].fifth_food," Bonda");
    m[5].first = 40;
    m[5].second = 50;
    m[5].third = 60;
    m[5].fourth = 50;
    m[5].fifth = 50;
}
 
void search_by_hotels()
{
	printf("\n\n***Welcome to Restaurants Page****\n");
    hotel_initialize();
    printf("""\n\nHere are few Restaurants to choose");
    printf("\n1) %s\n",m[1].hotel);
    printf("\n2) %s\n",m[2].hotel);
    printf("\n3) %s\n",m[3].hotel);
    printf("\n4) %s\n",m[4].hotel);
    printf("\n5) %s\n",m[5].hotel);
	printf("\n6) Exit\n");
    printf(" Please Select the Restaurant you want:\t");
    scanf("%d", &hotel_choice);
    if (hotel_choice > 7) 
	{
        printf("Please Enter the valid choice\n");
        search_by_hotels();
    }
    else if (hotel_choice == 7)
        return;
    else
        hotels(hotel_choice);
}
 
void hotels(int hotel_choice)
{
    total = 0;
    while (1) 
	{
		printf("\n\n***Welcome to Food Order Page****\n");
        printf("\n\nList of foods available in \n");
		printf("%s\n",m[hotel_choice].hotel);
		printf("1) %s\tRs: %d\n",m[hotel_choice].first_food,m[hotel_choice].first);
		printf("2)%s\tRs: %d\n",m[hotel_choice].second_food,m[hotel_choice].second);
		printf("3) %s\tRs: %d\n",m[hotel_choice].third_food,m[hotel_choice].third);
		printf("4) %s\tRs: %d\n",m[hotel_choice].fourth_food,m[hotel_choice].fourth);
		printf("5) %s\tRs: %d\n",m[hotel_choice].fifth_food,m[hotel_choice].fifth);
		printf("6) Cart\n");
        printf("7) Exit\n");
        printf("Please Enter Your Choice\t");
        scanf("%d", &food_choice);
        if (food_choice == 1) 
		{
            printf("Please Enter the Count of ");
            printf("%s\t",m[hotel_choice].first_food);
            scanf("%d", &n);
            total = total+ (n * m[hotel_choice].first);
        }
        else if (food_choice == 2) 
		{
            printf("Please Enter the Count of ");
            printf("%s\t",m[hotel_choice].second_food);
            scanf("%d", &n);
            total = total+ (n * m[hotel_choice].second);
        }
        else if (food_choice == 3) 
		{
            printf("Please Enter the Count of ");
            printf("%s\t",m[hotel_choice].third_food);
            scanf("%d", &n);
            total = total+ (n * m[hotel_choice].third);
        }
        else if (food_choice == 4) 
		{
            printf("Please Enter the Count of ");
            printf("%s\t",m[hotel_choice].fourth_food);
            scanf("%d", &n);
            total = total+ (n * m[hotel_choice].fourth);
        }
        else if (food_choice == 5) 
		{
            printf("Please Enter the Count of ");
            printf("%s\t",m[hotel_choice].fifth_food);
            scanf("%d", &n);
            total = total+ (n * m[hotel_choice].fifth);
        }
        else if (food_choice == 6) 
		{
            cart();
        }
        else if (food_choice == 7) 
		{
            exit(0);
        }
        else 
		{
            printf("Please Enter the valid Choice\n");
        }
    }
}
 
void search_by_food()
{
    total = 0;
    hotel_initialize();
    while (1)
	{
		printf("\n\n***Welcome to Search by Food page****\n");
        printf("\n\nPlease choose the food:\n");
        printf("1) %s\t%d\n",m[1].first_food, m[1].first);
		printf("2) %s\t%d\n",m[1].second_food, m[1].second); 
        printf("3) %s\t%d\n",m[1].third_food, m[1].third);
		printf("4) %s\t%d\n",m[2].first_food, m[2].first); 
        printf("5) %s\t%d\n",m[2].second_food, m[2].second);
		printf("6) %s\t%d\n",m[2].third_food, m[2].third);
        printf("7) %s\t%d\n",m[3].first_food, m[3].first);
		printf("8) %s\t%d\n",m[3].second_food, m[3].second);
        printf("9) %s\t%d\n",m[3].third_food,m[3].third);
        printf("10) %s\t%d\n",m[4].first_food,m[4].first);
        printf("11) %s\t%d\n",m[4].second_food,m[4].second);
        printf("12) %s\t%d\n",m[4].third_food,m[4].third);
        printf("13) %s\t%d\n",m[5].first_food,m[5].first);
        printf("14) %s\t%d\n",m[5].second_food,m[5].second);
        printf("15) %s\t%d\n",m[5].third_food,m[5].third);
		printf("16) Cart\n");
        printf("17) Exit");
        printf("\nPlease Enter Your Choice\t");
        scanf("%d",&food);
        if (food < 16) 
		{
            printf("Please Enter the ");
            printf("valid choice\n\n");
            search_by_food();
        }
        else if (food == 6)
            cart();
        else if (food == 7)
        	exit(0);
        else
            food_order(food);
    }
}

void food_order(int food)
{
	printf("\n\n***Welcome to Food Order Page****\n");
    if (food >= 1 && food <= 3)
        hotel_id = 1;
    else if (food >= 4 && food <= 6)
        hotel_id = 2;
    else
        hotel_id = 3;
    if ((food % 3) == 1) 
	{
        printf("Please Enter the Count of ");
        printf("%s\t",m[hotel_id].first_food);
        scanf("%d", &n);
        total = total + (n * m[hotel_id].first);
    }
    else if ((food % 3) == 2) 
	{
        printf("Please Enter the Count of ");
        printf("%s\t",m[hotel_id].second_food);
        scanf("%d", &n);
        total = total + (n * m[hotel_id].second);
    }
    else if ((food % 3) == 0) 
	{
        printf("Please Enter the Count of ");
        printf("%s\t",m[hotel_id].third_food);
        scanf("%d", &n);
        total = total + (n * m[hotel_id].third);
    }
}

void cart()
{
	printf("\n\n***Welcome to Cart Page****\n");
    printf("\n*****Cart*****");
    printf("\nYour Total Order Amount is: %d\n", total);
    printf("\nDo You wish to order (y = 1/n = 0): ");
    scanf("%d", &ch);
    if (ch == 1) 
	{
		payment();
        printf("\n\nThank You for your order!!\n");
		printf("Your Food is on the way\n.");
		printf(" Order again!!\n\n");
		rating();
		printf("Thank You for your Order\n");
		printf("Please Visit Again\n");
        return;
    }
    else if (ch == 0) 
	{
        printf("Do You want to exit = -1 or Go back = 0");
        scanf("%d", &confirm);
        if (confirm == 1) 
		{
            printf("\n\nOops! Your order is cancelled!! Exiting..");
            printf("Thank You visit again!\n");
            rating();
            return;
        }
        else 
		{
            printf("\n\nThank You\n\n");
            login();
        }
    }
    else 
	{
        printf("\n\nPlease Enter the correct choice\n");
        cart();
    }
}

void payment()
{
	printf("\n\n***Welcome to Payment Page****\n");
	printf("Please select the Payment Method to Pay the Bill:\n");
	printf("1.Cash on Delivery\n");
	printf("2.Pay through ATM Card\n");
	scanf("%d",&choice);
	if(choice==1)
		printf("You can the pay the Amount on Cash on Delivery(COD)\n");
	else if(choice==2)
	{
		printf("Enter the Bank Name:\n");
		scanf("%s\n",c_bank);
		printf("\nEnter the Card Number:");
		scanf("%s\n",c_name);
		printf("\nEnter the Card Pin Number:");
		scanf("%d\n",&c_num);
		printf("\nEnter the CVV Number of the Card:");
		scanf("%d\n",&cvv);
		printf("Your Payment is Done from the Bank %s\n",c_bank);
		printf("Holding with ATM Card Number %d\n",c_num);
		printf("And with the Name of the Holder of the Bank %s\n",c_name);
		printf("\nYour Payment is done\n");
		printf("From the Bank %s\n",c_bank);
	}
	else
	{
   	    printf("Invalid Payment Method Selected.\n");
        printf("Please Enter the Valid Payment Methond to Pay the Amount\n");
        printf("Thank You\n");
	}
}

void rating()
{
	printf("\n\n***Welcome to Delivery Rating Page****\n");
	printf("Enter number of stars for the Delivery\n");
	scanf("%d",&as);
	if(as==5)
		printf("Thankyou for Five Star Rating\n");
	else if(as==4)
		printf("Thankyou for Four Star Rating\n");
	else 
		printf("Thankyou for your Rating\n");
		
	printf("\n\n***Welcome to Project Rating Page****\n");
	printf("\nEnter number of stars for the Project\n");
	scanf("%d",&as);
	if(as==5)
		printf("Thankyou for Five Star Rating\n");
	else if(as==4)
		printf("Thankyou for Four Star Rating\n");
	else
		printf("Thankyou for your Rating\n");
}
