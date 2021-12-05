/*
    This program is a library of functions to be used in conjunction with a GPS receiver
    Written By: William Rocheleau, Gabe Bigas
    Date: 5/12/21
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct user_t{
    double latitude;
    double longitude;
    double altitude;
    char name[20];
};

struct rel_dist{
    double distance;
    char name[20];
};

static struct user_t our_user;
static struct user_t other_users[1];

int numOthers;

struct rel_dist distances[1];

struct user_t scan_user(struct user_t user){
    printf("Name: ");
    scanf("%s", &user.name);
    printf("Latitude: ");
    scanf("%lf", &user.latitude);
    printf("Longitude: ");
    scanf("%lf", &user.longitude);
    printf("Altitude: ");
    scanf("%lf", &user.altitude);

    printf("\n%s's position is %lf meters south, %lf meters west, and %lf meters up\n", user.name, user.latitude, user.longitude, user.altitude);

    return user;
}

void scan_user_file(){
    char filename[20];
    FILE *input;
    //int numOthers;

    printf("\nPlease enter your file name\n--------------------------------\n");
    scanf("%s", &filename);

    input = fopen(filename, "r");

    char line[120];

    if (input == NULL){
        printf("ERROR: the file %s does not exist, reading from default file instead\n\n", &filename);
        input = fopen("users.txt", "r");
    }
    numOthers = atoi(fgets(line, 120, input));

    other_users[numOthers];

    char* token;
    char *ptr;

    for (int i = 0; i < numOthers; i++){
        fgets(line, 120, input);

        token = strtok(line, ",");
        strcpy(other_users[i].name, token);

        token = strtok(NULL, ",");
        other_users[i].latitude = strtod(token, &ptr);

        token = strtok(NULL, ",");
        other_users[i].longitude = strtod(token, &ptr);

        token = strtok(NULL, ",");
        other_users[i].altitude = strtod(token, &ptr);

        printf("\n%s's position is %lf meters south, %lf meters west, and %lf meters up\n", other_users[i].name, other_users[i].latitude, other_users[i].longitude, other_users[i].altitude);
    }

    fclose(input);
}

void fillData(){
    int inputChoice;

    printf("Please enter your data\n--------------------------------\n");
    
    our_user = scan_user(our_user);
    
    printf("\nHow would you like to enter the other user's data?\nmanually (1)\nusing a file (2)\n--------------------------------\n");
    scanf("%d", &inputChoice);

    if (inputChoice == 1){
        //int numOthers;

        printf("\nHow many other users are there?\n");
        scanf("%d", &numOthers);
        other_users[numOthers];

        for (int i = 0; i < numOthers; i++){
            printf("\nPlease enter the data for other user %d\n--------------------------------\n", i+1);
            
            other_users[i] = scan_user(other_users[i]);
        }
    }
    else{
        scan_user_file();
    }
}

void distCalc(){
    //int size = (int)(sizeof(other_users)/sizeof(other_users[0]));
    int size = numOthers;
    distances[size];

    for (int i=0; i<size; i++){
        strcpy(distances[i].name, other_users[i].name);
        distances[i].distance = sqrt((pow((our_user.latitude-other_users[i].latitude), 2)+pow((our_user.longitude-other_users[i].longitude), 2)+pow((our_user.altitude-other_users[i].altitude), 2)));
        printf("\n%s is %lf meters away from %s\n", distances[i].name, distances[i].distance, our_user.name);
    }
}

int closest_other(int number){
    int indexOfClosest=0;

    for (int i = 0; i < number; i++){
        if (distances[i].distance <= distances[indexOfClosest].distance){
            indexOfClosest = i;
        }
    }

    return indexOfClosest;
}

int main(){
    int number;

    printf("\nWelcome to positionCalculation.exe\n");
    fillData();

    number = numOthers;

    printf("\n--------------------------------\n\nCalculating distances relative to %s...\n", our_user.name);
    distCalc();

    printf("\n--------------------------------\n\nFinding closest other user to %s...\n", our_user.name);
    int index = closest_other(number);
    printf("\n%s is the closest other user to %s\n", other_users[index].name, our_user.name);

    return 0;
}