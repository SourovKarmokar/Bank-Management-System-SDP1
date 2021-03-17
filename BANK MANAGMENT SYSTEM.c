
               #include<stdio.h>
#include<stdlib.h>
#include<windows.h>
int i,j;
int main_exit;
void menu();
struct date{
    int month,day,year;
};
struct{

    char name[60];
    int account_nong,age;
    char address[60];
    char citizenship[15];
    double phone;
    char acc_type[10];
    float amt;
    struct date dob;
    struct date deposit;
    struct date withdraw;

}
add,upd,check,rem,transaction;
float interest(float t,float amount,int rate)
{
    float SI;
    SI=(rate*t*amount)/100.0;
    return (SI);
}
void fordelay(int j){
    int i,k;
    for(i=0;i<j;i++)
         k=i;
}
void new_acc(){
    int choice;
    FILE *ptr;
    ptr=fopen("record.txt","w");
    account_no:
    system("cls");
    printf("\t\t\t\xB2\xB2\xB2\xB2 ADD RECORD \xB2\xB2\xB2\xB2");
    printf("\n\n\nEnter today's date(mm/dd/yyyy): ");
    scanf("%d/%d/%d",&add.deposit.month,&add.deposit.day,&add.deposit.year);
    printf("\nEnter the account number: ");
    scanf("%d",&check.account_nong);
    while(fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",&add.account_nong,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF){
        if (check.account_nong==add.account_nong){
            printf("Account no. already in use!");
            fordelay(1000000000);
                goto account_no;
            }
}
    add.account_nong=check.account_nong;
    printf("\nEnter the name: ");
    scanf("%s",add.name);
    printf("\nEnter the date of birth(mm/dd/yyyy): ");
    scanf("%d/%d/%d",&add.dob.month,&add.dob.day,&add.dob.year);
    printf("\nEnter the age: ");
    scanf("%d",&add.age);
    printf("\nEnter the address: ");
    scanf("%s",add.address);
    printf("\nEnter the citizenship number: ");
    scanf("%s",add.citizenship);
    printf("\nEnter the phone number: ");
    scanf("%lf",&add.phone);
    printf("\nEnter the amount to deposit:BDT");
    scanf("%f",&add.amt);
    printf("\nType of account:\n\t#Saving\n\t#Current\n\t#Fixed1(for 2 year)\n\t#Fixed2(for 3 years)\n\t#Fixed3(for 4 years)\n\n\tEnter your choice: ");
    scanf("%s",add.acc_type);
    fprintf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.account_nong,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
    fclose(ptr);
    printf("\nAccount created successfully!");
    add_invalid:
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit: ");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
        menu();
    else if(main_exit==0)
            close();
    else{
            printf("\nInvalid!\a");
            goto add_invalid;
        }
}
void view_list(){
    FILE *view;
    view=fopen("record.txt","r");
    int test=0;
    system("cls");
    printf("\nACC. NO.\tNAME\t\t\tADDRESS\t\t\tPHONE\t\t\tAmmount\n");

    while(fscanf(view,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.account_nong,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF){
           printf("\n%6d\t %10s\t\t\t%10s\t\t%.0lf\t\t\t\t%0.2f",add.account_nong,add.name,add.address,add.phone,add.amt);
           test++;
       }

    fclose(view);
    if (test==0){
            system("cls");
            printf("\nNO RECORDS!\n");}

    view_list_invalid:
    printf("\n\nEnter 1 to go to the main menu and 0 to exit: ");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else if(main_exit==0)
            close();
        else{
            printf("\nInvalid!\a");
            goto view_list_invalid;
        }
}
void edit(void){

    int choice,test=0;
    FILE *old,*newrec;
    old=fopen("record.txt","r");
    newrec=fopen("new.txt","w");
    printf("\nEnter the account no. of the customer whose info you want to change: ");
    scanf("%d",&upd.account_nong);
    while(fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.account_nong,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF){
        if (add.account_nong==upd.account_nong){

            test=1;
            printf("\nWhich information do you want to change?\n1.Address\n2.Phone\n\nEnter your choice(1 for address and 2 for phone): ");
            scanf("%d",&choice);
            system("cls");
            if(choice==1){

                printf("Enter the new address: ");
                scanf("%s",upd.address);
                fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.account_nong,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,upd.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                system("cls");
                printf("Changes saved!");
                }
            else if(choice==2){

                printf("Enter the new phone number: ");
                scanf("%lf",&upd.phone);
                fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.account_nong,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,upd.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                system("cls");
                printf("Changes saved!");
                }

        }
        else
            fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.account_nong,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
}
    fclose(old);
    fclose(newrec);
    remove("record.txt");
    rename("new.txt","record.txt");

if(test!=1){
        system("cls");
        printf("\nRecord not found!\a\a\a");
        edit_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit: ");
              scanf("%d",&main_exit);
              system("cls");
                 if (main_exit==1)
                    menu();
                else if (main_exit==2)
                    close();
                else if(main_exit==0)
                    edit();
                else{
                    printf("\nInvalid!\a");
                    goto edit_invalid;
      }
 }
    else{
        printf("\n\n\nEnter 1 to go to the main menu and 0 to exit: ");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else
            close();
        }
}

void transact(void){
    int choice,test=0;
    FILE *old,*newrec;
    old=fopen("record.txt","r");
    newrec=fopen("new.txt","w");

    printf("Enter the account no. of the customer: ");
    scanf("%d",&transaction.account_nong);
    while (fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.account_nong,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF){

            if(add.account_nong==transaction.account_nong){
            test=1;
                if(strcmpi(add.acc_type,"fixed1")==0||strcmpi(add.acc_type,"fixed2")==0||strcmpi(add.acc_type,"fixed3")==0){

                    printf("\a\a\a\n\nYOU CANNOT DEPOSIT OR WITHDRAW CASH IN FIXED ACCOUNTS!");
                    fordelay(1000000000);
                    system("cls");
                    menu();
                }
                printf("\n\nDo you want to\n1.Deposit\n2.Withdraw?\n\nEnter your choice(1 for deposit and 2 for withdraw): ");
                scanf("%d",&choice);
                if (choice==1){

                    printf("Enter the amount you want to deposit:BDT ");
                    scanf("%f",&transaction.amt);
                    add.amt+=transaction.amt;
                    printf("\n new balnce=%f\n\n",add.amt);
                    fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.account_nong,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                    printf("\n\nDeposited successfully!");
                }
                else{

                    printf("Enter the amount you want to withdraw:BDT ");
                    scanf("%f",&transaction.amt);
                    add.amt-=transaction.amt;
                    printf("\n new balnce=%f\n\n",add.amt);
                    fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.account_nong,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                    printf("\n\nWithdrawn successfully!");
                }

}
            else{

               fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.account_nong,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
            }
}
   fclose(old);
   fclose(newrec);
   remove("record.txt");
   rename("new.txt","record.txt");
   if(test!=1){

    printf("\n\nRecord not found!");
    transact_invalid:
    printf("\n\n\nEnter 0 to try again,1 to return to main menu and 2 to exit: ");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==0)
        transact();
    else if (main_exit==1)
        menu();
    else if (main_exit==2)
        close();
    else{
        printf("\nInvalid!");
        goto transact_invalid;
    }
   }
   else{
        printf("\nEnter 1 to go to the main menu and 0 to exit: ");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else
            close();
   }

}
void erase(void){

    FILE *old,*newrec;
    int test=0;
    old=fopen("record.txt","r");
    newrec=fopen("new.txt","w");
    printf("Enter the account no. of the customer you want to delete: ");
    scanf("%d",&rem.account_nong);
    while (fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.account_nong,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF){
        if(add.account_nong!=rem.account_nong)
            fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.account_nong,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);

        else{
            test++;
            printf("\nRecord deleted successfully!\n");
            }
}
   fclose(old);
   fclose(newrec);
   remove("record.txt");
   rename("new.txt","record.txt");
   if(test==0){

            printf("\nRecord not found!\a\a\a");
            erase_invalid:
            printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit: ");
            scanf("%d",&main_exit);
                 if (main_exit==1)
                    menu();
                else if (main_exit==2)
                    close();
                else if(main_exit==0)
                    erase();
                else{
                    printf("\nInvalid!\a");
                    goto erase_invalid;}
}
    else{
        printf("\nEnter 1 to go to the main menu and 0 to exit: ");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else
            close();
        }

}

void see(void){

    FILE *ptr;
    int test=0,rate;
    int choice;
    float time;
    float intrst;
    ptr=fopen("record.txt","r");
    printf("Do you want to check by\n1.Account no\n2.Name\nEnter your choice: ");
    scanf("%d",&choice);
    if (choice==1){
        printf("Enter the account number: ");
        scanf("%d",&check.account_nong);
        while (fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.account_nong,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF){
            if(add.account_nong==check.account_nong){
                system("cls");
                test=1;
                printf("\nAccount NO.: %d\nName: %s \nDOB: %d/%d/%d \nAge: %d \nAddress: %s \nCitizenship No: %s \nPhone number: %f \nType Of Account: %s \nAmount deposited: BDT %.2f \nDate Of Deposit: %d/%d/%d\n\n",add.account_nong,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,
                add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                if(strcmpi(add.acc_type,"fixed1")==0){
                        time=1.0;
                        rate=9;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get BDT.%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+1);
    }
                else if(strcmpi(add.acc_type,"fixed2")==0){
                        time=2.0;
                        rate=11;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get BDT.%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+2);
    }
                else if(strcmpi(add.acc_type,"fixed3")==0){
                        time=3.0;
                        rate=13;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get BDT.%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+3);
    }
                 else if(strcmpi(add.acc_type,"saving")==0){
                        time=(1.0/12.0);
                        rate=8;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get BDT.%.2f as interest on %d of every month",intrst,add.deposit.day);
    }
                 else if(strcmpi(add.acc_type,"current")==0){
                        printf("\n\nYou will get no interest\a\a");

                     }

            }
        }
    }
    else if (choice==2){
        printf("Enter the name: ");
        scanf("%s",&check.name);
        while (fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.account_nong,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF){
            if(strcmpi(add.name,check.name)==0){

                system("cls");
                test=1;
                printf("\nAccount No.: %d\nName: %s \nDOB: %d/%d/%d \nAge: %d \nAddress: %s \nCitizenship No: %s \nPhone number: %f \nType Of Account: %s \nAmount deposited: BDT.2f \nDate Of Deposit: %d/%d/%d\n\n",add.account_nong,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,
                add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                if(strcmpi(add.acc_type,"fixed1")==0){
                        time=1.0;
                        rate=9;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get BDT.%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+1);
 }
                else if(strcmpi(add.acc_type,"fixed2")==0){
                        time=2.0;
                        rate=11;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get BDT.%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+2);
 }
                else if(strcmpi(add.acc_type,"fixed3")==0){
                        time=3.0;
                        rate=13;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get BDT.%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+3);
 }
                 else if(strcmpi(add.acc_type,"saving")==0){
                        time=(1.0/12.0);
                        rate=8;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get BDT.%.2f as interest on %d of every month",intrst,add.deposit.day);
 }
                 else if(strcmpi(add.acc_type,"current")==0){
                        printf("\n\nYou will get no interest\a\a");

                     }

            }
        }
    }


    fclose(ptr);
     if(test!=1){
            system("cls");
            printf("\nRecord not found!\a\a\a");
            see_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit: ");
              scanf("%d",&main_exit);
              system("cls");
                 if (main_exit==1)
                    menu();
                else if (main_exit==2)
                    close();
                else if(main_exit==0)
                    see();
                else{
                        system("cls");
                        printf("\nInvalid!\a");
                        goto see_invalid;
     }
}
    else{
        printf("\nEnter 1 to go to the main menu and 0 to exit: ");
        scanf("%d",&main_exit);
    }
        if (main_exit==1){
            system("cls");
            menu();
        }

        else{
            system("cls");
            close();
            }

}

void close(void){
    printf("\n\nThis Project is developed by Sourav Karmokar  Wakibul Zaman , MD. Monzurul Alam Sajal");
    printf("\n\n");
    }
void menu(void){
    int choice;
    system("cls");
    system("color 9");
    printf("\n\n\t\t\t\tBANKING MANAGEMENT SYSTEM");
    printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t1.Create new account\n\t\t2.Update information of existing account\n\t\t3.For transactions\n\t\t4.Check the details of existing account\n\t\t5.Removing existing account\n\t\t6.View customer's list\n\t\t7.Exit\n\n\n\n\n\t\t Enter your choice:");
    scanf("%d",&choice);
    system("cls");
    switch(choice){

        case 1:new_acc();
        break;
        case 2:edit();
        break;
        case 3:transact();
        break;
        case 4:see();
        break;
        case 5:erase();
        break;
        case 6:view_list();
        break;
        case 7:close();
        break;
    }
}
int main()
{
    char pass[15],password[15]="TeamHydra";
    int i=0;
    printf("\n\n\t\tEnter the password to login: ");
    scanf("%s",pass);
    if (strcmp(pass,password)==0){
        printf("\n\nPassword Match!\nLOADING");
        for(i=0;i<=6;i++){
            fordelay(100000000);
            printf(".");
        }
            system("cls");
            menu();
 }
    else{
            printf("\n\nWrong password!\a\a\a");
            login_try:
            printf("\nEnter 1 to try again and 0 to exit: ");
            scanf("%d",&main_exit);
            if (main_exit==1){
                    system("cls");
                    main();
                    }
            else if (main_exit==0){
                    system("cls");
                    close();
                    }
            else{
                    printf("\nInvalid!");
                    fordelay(1000000000);
                    system("cls");
                    goto login_try;
            }
        }
        return 0;
}


