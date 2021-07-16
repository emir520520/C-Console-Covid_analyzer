#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"

int main() {
    char buffer[50];
    int boo;
    int choice;
    int count=0;
    int conti=0;

    srand(time(NULL));

    //---------------------------------------------------Get user input and generate households
    printFront();
    while(count!=3 && conti==0){
        count=userInput(count, &conti);
    }
    generate(count);
    print20();

    //---------------------------------------------------Check results
    conti=0;
    puts("----------------Above household information is obtained from voluntary contributions to the survey-------------------");

    again:
    while(conti==0){
        puts("Main menu:\n");
        puts("Enter your choice to display");
        puts("1. Household records by race, region or town");
        puts("2. Races ranking for Covid-19");
        puts("3. Regions ranking for Covid-19");
        puts("4. Towns ranking for Covid-19");
        puts("5. Races ranking by poverty");
        puts("0. Exit");

        fgets(buffer, sizeof(buffer),stdin);
        boo=sscanf(buffer,"%d",&choice);

        while(boo!=1 || choice<0 || choice >5){
            puts("Please enter valid number of options");
            puts("Main menu:\n");
            puts("Enter your choice to display");
            puts("1. Household records by race, region or town");
            puts("2. Races ranking for Covid-19");
            puts("3. Regions ranking for Covid-19");
            puts("4. Towns ranking for Covid-19");
            puts("5. Races ranking by poverty");
            puts("0. Exit");

            fgets(buffer, sizeof(buffer),stdin);
            boo=sscanf(buffer,"%d",&choice);
        }

        if(choice==0){
            goto exit;
        }else if(choice==1) {
            puts("Enter an integer to see household records of a particular race(0), region(1), or town(2)");
            fgets(buffer, sizeof(buffer), stdin);
            boo = sscanf(buffer, "%d", &choice);

            while(boo!=1 || choice<0 || choice >2){
                puts("Please enter valid number of options");
                puts("Enter an integer to see household records of a particular race(0), region(1), or town(2)");
                fgets(buffer, sizeof(buffer), stdin);
                boo = sscanf(buffer, "%d", &choice);
            }

            if(choice==0){
                puts("Enter an integer Indigenous(0), Caucasian(1), African American(2), Asian(3), Others(4)");
                fgets(buffer, sizeof(buffer), stdin);
                boo = sscanf(buffer, "%d", &choice);

                while(boo!=1 || choice<0 || choice >4){
                    puts("Please enter valid number of options");
                    puts("Enter an integer to see household records of a particular race(0), region(1), or town(2)");
                    fgets(buffer, sizeof(buffer), stdin);
                    boo = sscanf(buffer, "%d", &choice);
                }

                printByRace(choice);
            }else if(choice==1){
                puts("Enter an integer Durham(0), Peel(1), York(2)");
                fgets(buffer, sizeof(buffer), stdin);
                boo = sscanf(buffer, "%d", &choice);

                while(boo!=1 || choice<0 || choice >2){
                    puts("Please enter valid number of options");
                    puts("Enter an integer Durham(0), Peel(1), York(2)");
                    fgets(buffer, sizeof(buffer), stdin);
                    boo = sscanf(buffer, "%d", &choice);
                }

                printByRegion(choice);
            }else if(choice==2){
                puts("Enter an integer Whitby(0), Oshawa(1), Brampton(2), Mississauga(3), Maple(4), Vaughan(5)");
                fgets(buffer, sizeof(buffer), stdin);
                boo = sscanf(buffer, "%d", &choice);

                while(boo!=1 || choice<0 || choice >5){
                    puts("Please enter valid number of options");
                    puts("Enter an integer Whitby(0), Oshawa(1), Brampton(2), Mississauga(3), Maple(4), Vaughan(5)");
                    fgets(buffer, sizeof(buffer), stdin);
                    boo = sscanf(buffer, "%d", &choice);
                }

                printByTown(choice);
            }
            goto again;
        }else if(choice==2){
            puts("Enter 0 to see all Covid-19 cases tested or 1 for only tested positive cases or 9 to go bakc to the main menu");
            fgets(buffer, sizeof(buffer), stdin);
            boo = sscanf(buffer, "%d", &choice);

            if(choice==9){
                goto again;
            }else if(choice==0){
                printByRaces(0);
            }else if(choice==1){
                printByRaces(1);
            }
            goto again;
        }else if(choice==3){
            puts("Enter 0 to see all Covid-19 cases tested or 1 for only tested positive cases or 9 to go bakc to the main menu");
            fgets(buffer, sizeof(buffer), stdin);
            boo = sscanf(buffer, "%d", &choice);

            if(choice==9){
                goto again;
            }else if(choice==0){
                printByRegions(0);
            }else if(choice==1){
                printByRegions(1);
            }
            goto again;
        }else if(choice==4){
            puts("Enter 0 to see all Covid-19 cases tested or 1 for only tested positive cases or 9 to go bakc to the main menu");
            fgets(buffer, sizeof(buffer), stdin);
            boo = sscanf(buffer, "%d", &choice);

            if(choice==9){
                goto again;
            }else if(choice==0){
                printByTowns(0);
            }else if(choice==1){
                printByTowns(1);
            }
            goto again;
        }else if(choice==5){
            printPovertyByRaces();
            goto again;
        }
    }

    exit:
    return 0;
}