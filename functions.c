#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "functions.h"

typedef struct hh{
    char race[17];
    char region[7];
    char town[12];
    int income;
    int people;
    int tested;
    int positive;
}Household;

Household array[100];

void printFront(int numberOf){
    puts("-----------------This program analyzes and stores information related to Covid-19 cases---------------");
    puts("------------------------and its impact on various races, regions and towns of GTA---------------------");
    puts("--------------------------------------Manual data entry module----------------------------------------");
}

int userInput(int count, int *conti){
    int buffer[15];
    int boo;

    int race;
    int region;
    int town;
    int income;
    int people;
    int tested;
    int positive;

    //-------------------------------------------------------header
    puts("Provide data of up to three households or enter 9 to skip manual data entry to generate records randomly");
    printf("Data entry for household# %d\n",count==0? 1 : count);

    //-------------------------------------------------------race
    puts("race: enter an integer: Indigenous(0), Caucasian(1), African American(2), Asian(3), Others(4)");
    fgets(buffer, sizeof(buffer),stdin);
    boo=sscanf(buffer,"%d",&race);

    if(race==9){
        puts("Skipping manual data entry and generating records randomly......");
        (*conti)=1;
        return count;
    }

    while(boo!=1 || race<0 || (race>4) ){
        puts("Please enter correct index of options");
        puts("race: enter an integer: Indigenous(0), Caucasian(1), African American(2), Asian(3), Others(4)");
        fgets(buffer, sizeof(buffer),stdin);
        boo=sscanf(buffer,"%d",&race);
    }

    if(race==0){
        strcpy(array[count].race,"Indigenous");
    }else if(race==1){
        strcpy(array[count].race,"Caucasian");
    }
    else if(race==2){
        strcpy(array[count].race,"African American");
    }else if(race==3){
        strcpy(array[count].race,"Asian");
    }else if(race==4){
        strcpy(array[count].race,"Others");
    }

    //------------------------------------------------------region
    puts("region: enter an integer: Durham(0), Peel(1), York(2)");
    fgets(buffer, sizeof(buffer),stdin);
    boo=sscanf(buffer,"%d",&region);

    while(boo!=1 || region<0 || region>2){
        puts("Please enter correct index of options");
        puts("region: enter an integer: Durham(0), Peel(1), York(2)");
        fgets(buffer, sizeof(buffer),stdin);
        boo=sscanf(buffer,"%d",&region);
    }

    if(region==0){
        strcpy(array[count].region,"Durham");
    }else if(region==1){
        strcpy(array[count].region,"Peel");
    }
    else if(region==2){
        strcpy(array[count].region,"York");
    }

    //------------------------------------------------------town
    if(region==0){
        puts("town: enter an integer: Whitby(0), Oshawa(1)");
    }else if(region==1){
        puts("town: enter an integer: Brampton(0), Mississauga(1)");
    }else if(region==2){
        puts("town: enter an integer: Maple(0), Vaughan(1)");
    }

    fgets(buffer, sizeof(buffer),stdin);
    boo=sscanf(buffer,"%d",&town);

    while(boo!=1 || town<0 || town>2){
        puts("Please enter correct index of options");
        if(region==0){
            puts("town: enter an integer: Whitby(0), Oshawa(1)");
        }else if(region==1){
            puts("town: enter an integer: Brampton(0), Mississauga(1)");
        }else if(region==2){
            puts("town: enter an integer: Maple(0), Vaughan(1)");
        }
        fgets(buffer, sizeof(buffer),stdin);
        boo=sscanf(buffer,"%d",&town);
    }

    if(region==0){
        if(town==0){
            strcpy(array[count].town,"Whitby");
        }else if(town==1){
            strcpy(array[count].town,"Oshawa");
        }
    }else if(region==1){
        if(town==0){
            strcpy(array[count].town,"Brampton");
        }else if(town==1){
            strcpy(array[count].town,"Mississauga");
        }
    }else if(region==2){
        if(town==0){
            strcpy(array[count].town,"maple");
        }else if(town==1){
            strcpy(array[count].town,"Vaughan");
        }
    }

    //-------------------------------------------------------income
    puts("Enter annual household income:");
    puts("Note! It will be rounded down to the nearest hundred");
    fgets(buffer, sizeof(buffer),stdin);
    boo=sscanf(buffer,"%d",&income);

    while(boo!=1 || income<0 || income >INT_MAX){
        puts("Please enter valid income");
        puts("Enter annual household income:");
        puts("Note! It will be rounded down to the nearest hundred");
        fgets(buffer, sizeof(buffer),stdin);
        boo=sscanf(buffer,"%d",&income);
    }

    income=income/100*100;
    array[count].income=income;

    //------------------------------------------------------people, tested, positive
    puts("Enter number of household members, members tested for Covid-19 and members tested positive for Covid-19 respectively as three integers separated by space or tab:");
    fgets(buffer, sizeof(buffer),stdin);
    boo=sscanf(buffer,"%d %d %d",&people, &tested, &positive);

    while(boo!=3 || people <0 || tested <0 || positive <0 || tested > people || positive > tested){
        puts("Make sure you enter three positive integers in descending order, try again");
        fgets(buffer, sizeof(buffer),stdin);
        boo=sscanf(buffer,"%d %d %d",&people, &tested, &positive);
    }

    array[count].people=people;
    array[count].tested=tested;
    array[count].positive=positive;

    return count+1;
}

void generate(int count){
    for(int i=count;i<100;i++){
        //---------------------------------race
        int index=(rand()%(4+1))+0;

        if(index==0){
            strcpy(array[i].race,"Indigenous");
        }else if(index==1){
            strcpy(array[i].race,"Caucasian");
        }else if(index==2){
            strcpy(array[i].race,"African American");
        }else if(index==3){
            strcpy(array[i].race,"Asian");
        }else if(index==4){
            strcpy(array[i].race,"Others");
        }

        //--------------------------------region
        index=(rand()%(2+1))+0;

        if(index==0){
            strcpy(array[i].region,"Durham");
        }else if(index==1){
            strcpy(array[i].region,"Peel");
        }else if(index==2){
            strcpy(array[i].region,"York");
        }

        //--------------------------------town
        index=(rand()%(1+1))+0;

        if(strcmp(array[i].region, "Durham")==0){
            if(index==0){
                strcpy(array[i].town,"Whitby");
            }else if(index==1){
                strcpy(array[i].town,"Oshawa");
            }
        }else if(strcmp(array[i].region, "Peel")==0){
            if(index==0){
                strcpy(array[i].town,"Brampton");
            }else if(index==1){
                strcpy(array[i].town,"Mississauga");
            }
        }else if(strcmp(array[i].region, "York")==0){
            if(index==0){
                strcpy(array[i].town,"Maple");
            }else if(index==1){
                strcpy(array[i].town,"Vaughan");
            }
        }

        //--------------------------------income
        index=(rand()%(150000+1))+11111;

        index=index/100*100;
        array[i].income=index;

        //--------------------------------people
        index=(rand()%(10+1))+0;
        int temp=index;
        array[i].people=index;

        //--------------------------------tested
        index=(rand()%(temp+1))+0;
        array[i].tested=index;
        //--------------------------------positive
//        int arr[array[i].tested+1];
//        for(int i=0;i<array[i].tested+1;i++){
//            arr[i]=i;
//        }

        index=(rand()%(array[i].tested+1))+0;
        array[i].positive=index;
    }

    puts("Contents to file written successfully!");
}

void print20(){
    printf("%-4s \t %-14s \t %-9s \t %-11s \t %-8s \t %-3s \t %-3s \t %-3s\n","S.no","Race","Region","Town","Income","Family Size","Covid Tested", "Covid Positive");
    for(int i=0;i<100;i++){
        printf("%-4d \t %-14s \t %-9s \t %-11s \t %-10d \t %-7d \t %-7d \t %-3d\n",i+1,array[i].race,array[i].region,array[i].town,array[i].income,array[i].people,array[i].tested,array[i].positive);
    }
    puts("");
}

void printByRace(int choice){
    char filter[18];
    int count=1;
    printf("%-4s \t %-14s \t %-9s \t %-11s \t %-8s \t %-3s \t %-3s \t %-3s\n","S.no","Race","Region","Town","Income","Family Size","Covid Tested", "Covid Positive");

    if(choice==0){
        strcpy(filter,"Indigenous");
    }else if(choice==1){
        strcpy(filter,"Caucasian");
    }else if(choice==2){
        strcpy(filter,"African American");
    }else if(choice==3){
        strcpy(filter,"Asian");
    }else if(choice==4){
        strcpy(filter,"Others");
    }

    for(int i=0;i<100;i++){
        if(strcmp(array[i].race,filter)==0){
            printf("%-4d \t %-14s \t %-9s \t %-11s \t %-10d \t %-7d \t %-7d \t %-3d\n",count++,array[i].race,array[i].region,array[i].town,array[i].income,array[i].people,array[i].tested,array[i].positive);
        }
    }
    puts("----------------Above household information is obtained from voluntary contributions to the survey-------------------");
}

void printByRegion(int choice){
    char filter[7];
    int count=1;
    printf("%-4s \t %-14s \t %-9s \t %-11s \t %-8s \t %-3s \t %-3s \t %-3s\n","S.no","Race","Region","Town","Income","Family Size","Covid Tested", "Covid Positive");

    if(choice==0){
        strcpy(filter,"Durham");
    }else if(choice==1){
        strcpy(filter,"Peel");
    }else if(choice==2){
        strcpy(filter,"York");
    }

    for(int i=0;i<100;i++){
        if(strcmp(array[i].region,filter)==0){
            printf("%-4d \t %-14s \t %-9s \t %-11s \t %-10d \t %-7d \t %-7d \t %-3d\n",count++,array[i].race,array[i].region,array[i].town,array[i].income,array[i].people,array[i].tested,array[i].positive);
        }
    }
    puts("----------------Above household information is obtained from voluntary contributions to the survey-------------------");
}

void printByTown(int choice){
    char filter[18];
    int count=1;
    printf("%-4s \t %-14s \t %-9s \t %-11s \t %-8s \t %-3s \t %-3s \t %-3s\n","S.no","Race","Region","Town","Income","Family Size","Covid Tested", "Covid Positive");

    if(choice==0){
        strcpy(filter,"Whitby");
    }else if(choice==1){
        strcpy(filter,"Oshawa");
    }else if(choice==2){
        strcpy(filter,"Brampton");
    }else if(choice==3){
        strcpy(filter,"Mississauga");
    }else if(choice==4){
        strcpy(filter,"Maple");
    }else if(choice==5){
        strcpy(filter,"Vaughan");
    }

    for(int i=0;i<100;i++){
        if(strcmp(array[i].town,filter)==0){
            printf("%-4d \t %-14s \t %-9s \t %-11s \t %-10d \t %-7d \t %-7d \t %-3d\n",count++,array[i].race,array[i].region,array[i].town,array[i].income,array[i].people,array[i].tested,array[i].positive);
        }
    }
    puts("----------------Above household information is obtained from voluntary contributions to the survey-------------------");
}

void printByRaces(int option){
    int Indigenous=0;
    int Caucasian=0;
    int AfricanAmerican=0;
    int Asian=0;
    int Others=0;
    char rank[5][18];


    //-------------------------------------------------------------------------------Get data
    puts("----------------Races ranking of Covid-19---------------");
    puts("");

    if(option==0){
        printf("%20s :%15s\n","Races", "Covid Tested");
        for(int i=0;i<100;i++){
            if(strcmp(array[i].race,"Indigenous")==0){
                Indigenous=Indigenous+array[i].tested;
            }else if(strcmp(array[i].race,"Caucasian")==0){
                Caucasian=Caucasian+array[i].tested;
            }else if(strcmp(array[i].race,"African American")==0){
                AfricanAmerican=AfricanAmerican+array[i].tested;
            }else if(strcmp(array[i].race,"Asian")==0){
                Asian=Asian+array[i].tested;
            }else if(strcmp(array[i].race,"Others")==0){
                Others=Others+array[i].tested;
            }
        }
    }else if(option==1){
        printf("%20s :%15s\n","Races", "Covid Positive");
        for(int i=0;i<100;i++){
            if(strcmp(array[i].race,"Indigenous")==0){
                Indigenous=Indigenous+array[i].positive;
            }else if(strcmp(array[i].race,"Caucasian")==0){
                Caucasian=Caucasian+array[i].positive;
            }else if(strcmp(array[i].race,"African American")==0){
                AfricanAmerican=AfricanAmerican+array[i].positive;
            }else if(strcmp(array[i].race,"Asian")==0){
                Asian=Asian+array[i].positive;
            }else if(strcmp(array[i].race,"Others")==0){
                Others=Others+array[i].positive;
            }
        }
    }
    strcpy(rank[0],"Indigenous");
    strcpy(rank[1],"Caucasian");
    strcpy(rank[2],"African American");
    strcpy(rank[3],"Asian");
    strcpy(rank[4],"Others");

    //---------------------------------------------------------------------Sort data
    int lowest=0;
    int lowestAmount=Indigenous;
    int currentAmount;
    char temp[18];
    int change=1;

    for(int i=0;i<5;i++){
        for(int k=i;k<5;k++){
            if(strcmp(rank[k],"Indigenous")==0){
                currentAmount=Indigenous;
            }else if(strcmp(rank[k],"Caucasian")==0){
                currentAmount=Caucasian;
            }else if(strcmp(rank[k],"African American")==0){
                currentAmount=AfricanAmerican;
            }else if(strcmp(rank[k],"Asian")==0){
                currentAmount=Asian;
            }else if(strcmp(rank[k],"Others")==0){
                currentAmount=Others;
            }

            if(currentAmount<lowestAmount){
                lowestAmount=currentAmount;
                lowest=k;
                change=0;
            }
        }
        if(change==0){
            strcpy(temp,rank[i]);
            strcpy(rank[i],rank[lowest]);
            strcpy(rank[lowest],temp);
        }
        change=1;
        lowest=i+1;
        if(strcmp(rank[i+1],"Indigenous")==0){
            lowestAmount=Indigenous;
        }else if(strcmp(rank[i+1],"Caucasian")==0){
            lowestAmount=Caucasian;
        }else if(strcmp(rank[i+1],"African American")==0){
            lowestAmount=AfricanAmerican;
        }else if(strcmp(rank[i+1],"Asian")==0){
            lowestAmount=Asian;
        }else if(strcmp(rank[i+1],"Others")==0){
            lowestAmount=Others;
        }
    }

    //--------------------------------------------------------------------Print
    for(int i=0;i<5;i++){
        if(strcmp(rank[i],"Indigenous")==0){
            printf("%20s :%15d\n","Indigenous", Indigenous);
        }else if(strcmp(rank[i],"Caucasian")==0){
            printf("%20s :%15d\n","Caucasian", Caucasian);
        }else if(strcmp(rank[i],"African American")==0){
            printf("%20s :%15d\n","African American", AfricanAmerican);
        }else if(strcmp(rank[i],"Asian")==0){
            printf("%20s :%15d\n","Asian", Asian);
        }else if(strcmp(rank[i],"Others")==0){
            printf("%20s :%15d\n","Others", Others);
        }
    }
    puts("");
}

void printByTowns(int option){
    int Whitby=0;
    int Oshawa=0;
    int Brampton=0;
    int Mississauga=0;
    int Maple=0;
    int Vaughan=0;
    char rank[6][18];


    //-------------------------------------------------------------------------------Get data
    puts("----------------Regions ranking of Covid-19---------------");
    puts("");

    if(option==0){
        printf("%20s :%15s\n","Regions", "Covid Tested");
        for(int i=0;i<100;i++){
            if(strcmp(array[i].town,"Whitby")==0){
                Whitby=Whitby+array[i].tested;
            }else if(strcmp(array[i].town,"Oshawa")==0){
                Oshawa=Oshawa+array[i].tested;
            }else if(strcmp(array[i].town,"Brampton")==0){
                Brampton=Brampton+array[i].tested;
            }else if(strcmp(array[i].town,"Mississauga")==0){
                Mississauga=Mississauga+array[i].tested;
            }else if(strcmp(array[i].town,"Maple")==0){
                Maple=Maple+array[i].tested;
            }else if(strcmp(array[i].town,"Vaughan")==0){
                Vaughan=Vaughan+array[i].tested;
            }

        }
    }else if(option==1){
        printf("%20s :%15s\n","Regions", "Covid Positive");
        for(int i=0;i<100;i++){
            if(strcmp(array[i].town,"Whitby")==0){
                Whitby=Whitby+array[i].positive;
            }else if(strcmp(array[i].town,"Oshawa")==0){
                Oshawa=Oshawa+array[i].positive;
            }else if(strcmp(array[i].town,"Brampton")==0){
                Brampton=Brampton+array[i].positive;
            }else if(strcmp(array[i].town,"Mississauga")==0){
                Mississauga=Mississauga+array[i].positive;
            }else if(strcmp(array[i].town,"Maple")==0){
                Maple=Maple+array[i].positive;
            }else if(strcmp(array[i].town,"Vaughan")==0){
                Vaughan=Vaughan+array[i].positive;
            }
        }
    }
    strcpy(rank[0],"Whitby");
    strcpy(rank[1],"Oshawa");
    strcpy(rank[2],"Brampton");
    strcpy(rank[3],"Mississauga");
    strcpy(rank[4],"Maple");
    strcpy(rank[5],"Vaughan");

    //---------------------------------------------------------------------Sort data
    int lowest=0;
    int lowestAmount=Whitby;
    int currentAmount;
    char temp[18];
    int change=1;

    for(int i=0;i<6;i++){
        for(int k=i;k<6;k++){
            if(strcmp(rank[k],"Whitby")==0){
                currentAmount=Whitby;
            }else if(strcmp(rank[k],"Oshawa")==0){
                currentAmount=Oshawa;
            }else if(strcmp(rank[k],"Brampton")==0){
                currentAmount=Brampton;
            }else if(strcmp(rank[k],"Mississauga")==0){
                currentAmount=Mississauga;
            }else if(strcmp(rank[k],"Maple")==0){
                currentAmount=Maple;
            }else if(strcmp(rank[k],"Vaughan")==0){
                currentAmount=Vaughan;
            }

            if(currentAmount<lowestAmount){
                lowestAmount=currentAmount;
                lowest=k;
                change=0;
            }
        }
        if(change==0){
            strcpy(temp,rank[i]);
            strcpy(rank[i],rank[lowest]);
            strcpy(rank[lowest],temp);
        }
        change=1;
        lowest=i+1;
        if(strcmp(rank[i+1],"Whitby")==0){
            lowestAmount=Whitby;
        }else if(strcmp(rank[i+1],"Oshawa")==0){
            lowestAmount=Oshawa;
        }else if(strcmp(rank[i+1],"Brampton")==0){
            lowestAmount=Brampton;
        }else if(strcmp(rank[i+1],"Mississauga")==0){
            lowestAmount=Mississauga;
        }else if(strcmp(rank[i+1],"Maple")==0){
            lowestAmount=Maple;
        }else if(strcmp(rank[i+1],"Vaughan")==0){
            lowestAmount=Vaughan;
        }
    }

    //--------------------------------------------------------------------Print
    for(int i=0;i<6;i++){
        if(strcmp(rank[i],"Whitby")==0){
            printf("%20s :%15d\n","Whitby", Whitby);
        }else if(strcmp(rank[i],"Oshawa")==0){
            printf("%20s :%15d\n","Oshawa", Oshawa);
        }else if(strcmp(rank[i],"Brampton")==0){
            printf("%20s :%15d\n","Brampton", Brampton);
        }else if(strcmp(rank[i],"Mississauga")==0){
            printf("%20s :%15d\n","Mississauga", Mississauga);
        }else if(strcmp(rank[i],"Maple")==0){
            printf("%20s :%15d\n","Maple", Maple);
        }else if(strcmp(rank[i],"Vaughan")==0){
            printf("%20s :%15d\n","Vaughan", Vaughan);
        }
    }
    puts("");
}

void printByRegions(int option){
    int Durham=0;
    int Peel=0;
    int York=0;
    char rank[3][7];


    //-------------------------------------------------------------------------------Get data
    puts("----------------Regions ranking of Covid-19---------------");
    puts("");

    if(option==0){
        printf("%20s :%15s\n","Regions", "Covid Tested");
        for(int i=0;i<100;i++){
            if(strcmp(array[i].region,"Durham")==0){
                Durham=Durham+array[i].tested;
            }else if(strcmp(array[i].region,"Peel")==0){
                Peel=Peel+array[i].tested;
            }else if(strcmp(array[i].region,"York")==0){
                York=York+array[i].tested;
            }
        }
    }else if(option==1){
        printf("%20s :%15s\n","Regions", "Covid Positive");
        for(int i=0;i<100;i++){
            if(strcmp(array[i].region,"Durham")==0){
                Durham=Durham+array[i].positive;
            }else if(strcmp(array[i].region,"Peel")==0){
                Peel=Peel+array[i].positive;
            }else if(strcmp(array[i].region,"York")==0){
                York=York+array[i].positive;
            }
        }
    }
    strcpy(rank[0],"Durham");
    strcpy(rank[1],"Peel");
    strcpy(rank[2],"York");

    //---------------------------------------------------------------------Sort data
    int lowest=0;
    int lowestAmount=Durham;
    int currentAmount;
    char temp[7];
    int change=1;

    for(int i=0;i<5;i++){
        for(int k=i;k<5;k++){
            if(strcmp(rank[k],"Durham")==0){
                currentAmount=Durham;
            }else if(strcmp(rank[k],"Peel")==0){
                currentAmount=Peel;
            }else if(strcmp(rank[k],"York")==0){
                currentAmount=York;
            }

            if(currentAmount<lowestAmount){
                lowestAmount=currentAmount;
                lowest=k;
                change=0;
            }
        }
        if(change==0){
            strcpy(temp,rank[i]);
            strcpy(rank[i],rank[lowest]);
            strcpy(rank[lowest],temp);
        }
        change=1;
        lowest=i+1;
        if(strcmp(rank[i+1],"Durham")==0){
            lowestAmount=Durham;
        }else if(strcmp(rank[i+1],"Peel")==0){
            lowestAmount=Peel;
        }else if(strcmp(rank[i+1],"York")==0){
            lowestAmount=York;
        }
    }

    //--------------------------------------------------------------------Print
    for(int i=0;i<5;i++){
        if(strcmp(rank[i],"Durham")==0){
            printf("%20s :%15d\n","Durham", Durham);
        }else if(strcmp(rank[i],"Peel")==0){
            printf("%20s :%15d\n","Peel", Peel);
        }else if(strcmp(rank[i],"York")==0){
            printf("%20s :%15d\n","York", York);
        }
    }
    puts("");
}

void printPovertyByRaces(){
    double Indigenous=0;
    double Caucasian=0;
    double AfricanAmerican=0;
    double Asian=0;
    double Others=0;

    double PoorIndigenous=0;
    double PoorCaucasian=0;
    double PoorAfricanAmerican=0;
    double PoorAsian=0;
    double PoorOthers=0;

    double percentIndigenous;
    double percentCaucasian;
    double percentAfricanAmerican;
    double percentAsian;
    double percentOthers;

    char rank[5][30];

    //------------------------------------------------------------------Get data
    for(int i=0;i<100;i++){
        if(strcmp(array[i].race,"Indigenous")==0){
            Indigenous++;
            if((array[i].people==1) && (array[i].income<20000)){
                PoorIndigenous++;
            }else if((array[i].people==2) && (array[i].income<25000)){
                PoorIndigenous++;
            }else if((array[i].people==3) && (array[i].income<30000)){
                PoorIndigenous++;
            }else if((array[i].people==4) && (array[i].income<35000)){
                PoorIndigenous++;
            }else if((array[i].people>=5) && (array[i].income<40000)){
                PoorIndigenous++;
            }
        }else if(strcmp(array[i].race,"Caucasian")==0){
            Caucasian++;
            if((array[i].people==1) && (array[i].income<20000)){
                PoorCaucasian++;
            }else if((array[i].people==2) && (array[i].income<25000)){
                PoorCaucasian++;
            }else if((array[i].people==3) && (array[i].income<30000)){
                PoorCaucasian++;
            }else if((array[i].people==4) && (array[i].income<35000)){
                PoorCaucasian++;
            }else if((array[i].people>=5) && (array[i].income<40000)){
                PoorCaucasian++;
            }
        }else if(strcmp(array[i].race,"African American")==0){
            AfricanAmerican++;
            if((array[i].people==1) && (array[i].income<20000)){
                PoorAfricanAmerican++;
            }else if((array[i].people==2) && (array[i].income<25000)){
                PoorAfricanAmerican++;
            }else if((array[i].people==3) && (array[i].income<30000)){
                PoorAfricanAmerican++;
            }else if((array[i].people==4) && (array[i].income<35000)){
                PoorAfricanAmerican++;
            }else if((array[i].people>=5) && (array[i].income<40000)){
                PoorAfricanAmerican++;
            }
        }else if(strcmp(array[i].race,"Asian")==0){
            Asian++;
            if((array[i].people==1) && (array[i].income<20000)){
                PoorAsian++;
            }else if((array[i].people==2) && (array[i].income<25000)){
                PoorAsian++;
            }else if((array[i].people==3) && (array[i].income<30000)){
                PoorAsian++;
            }else if((array[i].people==4) && (array[i].income<35000)){
                PoorAsian++;
            }else if((array[i].people>=5) && (array[i].income<40000)){
                PoorAsian++;
            }
        }else if(strcmp(array[i].race,"Others")==0){
            Others++;
            if((array[i].people==1) && (array[i].income<20000)){
                PoorOthers++;
            }else if((array[i].people==2) && (array[i].income<25000)){
                PoorOthers++;
            }else if((array[i].people==3) && (array[i].income<30000)){
                PoorOthers++;
            }else if((array[i].people==4) && (array[i].income<35000)){
                PoorOthers++;
            }else if((array[i].people>=5) && (array[i].income<40000)){
                PoorOthers++;
            }
        }
    }

    percentIndigenous=PoorIndigenous/Indigenous;
    percentCaucasian=PoorCaucasian/Caucasian;
    percentAfricanAmerican=PoorAfricanAmerican/AfricanAmerican;
    percentAsian=PoorAsian/Asian;
    percentOthers=PoorOthers/Others;

    percentIndigenous=round(percentIndigenous * 100.0);
    percentCaucasian=round(percentCaucasian * 100.0);
    percentAfricanAmerican=round(percentAfricanAmerican * 100.0);
    percentAsian=round(percentAsian * 100.0);
    percentOthers=round(percentOthers * 100.0);

    strcpy(rank[0],"Indigenous");
    strcpy(rank[1],"Caucasian");
    strcpy(rank[2],"African American");
    strcpy(rank[3],"Asian");
    strcpy(rank[4],"Others");

    //-------------------------------------------------------------------Sort data
    int lowest=0;
    int lowestAmount=percentIndigenous;
    int currentAmount;
    char temp[18];
    int change=1;

    for(int i=0;i<5;i++){
        for(int k=i;k<5;k++){
            if(strcmp(rank[k],"Indigenous")==0){
                currentAmount=percentIndigenous;
            }else if(strcmp(rank[k],"Caucasian")==0){
                currentAmount=percentCaucasian;
            }else if(strcmp(rank[k],"African American")==0){
                currentAmount=percentAfricanAmerican;
            }else if(strcmp(rank[k],"Asian")==0){
                currentAmount=percentAsian;
            }else if(strcmp(rank[k],"Others")==0){
                currentAmount=percentOthers;
            }

            if(currentAmount<lowestAmount){
                lowestAmount=currentAmount;
                lowest=k;
                change=0;
            }
        }
        if(change==0){
            strcpy(temp,rank[i]);
            strcpy(rank[i],rank[lowest]);
            strcpy(rank[lowest],temp);
        }
        change=1;
        lowest=i+1;
        if(strcmp(rank[i+1],"Indigenous")==0){
            lowestAmount=percentIndigenous;
        }else if(strcmp(rank[i+1],"Caucasian")==0){
            lowestAmount=percentCaucasian;
        }else if(strcmp(rank[i+1],"African American")==0){
            lowestAmount=percentAfricanAmerican;
        }else if(strcmp(rank[i+1],"Asian")==0){
            lowestAmount=percentAsian;
        }else if(strcmp(rank[i+1],"Others")==0){
            lowestAmount=percentOthers;
        }
    }

    //--------------------------------------------------------------------Print
    printf("%20s :%15s\n","Race", "Percent household below poverty line");
    for(int i=0;i<5;i++){
        if(strcmp(rank[i],"Indigenous")==0){
            printf("%20s :%15.f%%\n","Indigenous", percentIndigenous);
        }else if(strcmp(rank[i],"Caucasian")==0){
            printf("%20s :%15.f%%\n","Caucasian", percentCaucasian);
        }else if(strcmp(rank[i],"African American")==0){
            printf("%20s :%15.f%%\n","African American", percentAfricanAmerican);
        }else if(strcmp(rank[i],"Asian")==0){
            printf("%20s :%15.f%%\n","Asian", percentAsian);
        }else if(strcmp(rank[i],"Others")==0){
            printf("%20s :%15.f%%\n","Others", percentOthers);
        }
    }
    puts("");
}