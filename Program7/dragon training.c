//James Vanaselja
//11.4.14
//Program 7
//COP 3223 Section 1
//Also called dragon training.c
/*
This program uses pass by value and pass by reference functions
as well as loops and if statements to 'train dragons'. Some code
was provided by the professor but the rest was up to me to create.
Warning: Copying this code is a violation of UCF's golden rule. Don't do it.

*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Constants to be used.

// Passing score
#define SCORE 70

// Symbolic constants for true and false.
#define FALSE 0
#define TRUE 1

// Function prototypes - do not change these
void set_stats(int * d_strength, int * d_intel, int * d_agil);
void print_stats(int strength, int intelligence, int agility, char name[]);
int menu();
int weather();
int train_strength(int weather, char name[]);
int train_intelligence(int weather, char name[]);
int train_agility(int weather, char name[]);
int obstacle_course(int weather, int strength, int intel, int agility);
void end_message(int completed, char name[]);

// Main function
int main()
{
    int num_day, ans, weather_value, score = 0, completed = FALSE;
    int dragon_strength, dragon_intelligence, dragon_agility;

    char name[20], answer[4];

    srand(time(0));

    printf("Welcome to Dragon Training!\n");
    printf("You've been assigned a new dragon! Would you like to give it a name? (yes/no)\n");
    scanf("%s", answer);

    if(strcmp(answer, "yes") == 0)
    {
        printf("Great! What would like to call your dragon?\n");
        scanf("%s", name);
    }
    else
        strcpy(name, "Your dragon");

    printf("\nTo complete training, %s must finish the final \nobstacle course with a score of 70 or better.\n", name);
    printf("\nYou may attempt the obstacle course at any time, \nbut you must finish within 10 days.\n");
    printf("\nBetter get started!\n");

    set_stats(&dragon_strength, &dragon_intelligence, &dragon_agility);


    for (num_day = 1; num_day <= 10; num_day++)
    {
        printf("\nIt is Day #%d.\n", num_day);
        print_stats(dragon_strength, dragon_intelligence, dragon_agility, name);
        weather_value = weather();
        ans = menu();

        switch(ans)
        {
        case 1:
            dragon_strength += train_strength(weather_value, name);
            break;
        case 2:
            dragon_intelligence += train_intelligence(weather_value, name);
            break;
        case 3:
            dragon_agility += train_agility(weather_value, name);
            break;
        case 4:
            score = obstacle_course(weather_value, dragon_strength, dragon_intelligence, dragon_agility);
            printf("%s scored a %d on their obstacle course run!\n", name, score);
            break;


        }
        if(score >= SCORE)
        {
            completed = TRUE;
            break;
        }
    }

    end_message(completed, name);

    return 0;
}

// Pre-conditions: d_strength, d_intel, and d_agil are pointers to variables that store
//                 the dragon's strength, intelligence, and agility statistics.
// Post-condition: Each of the dragon's statistics are set to a pseudorandom
//                 initial value.
//
// What to do in this function: Set each of the dragon's values to a
// pseudorandom initial value.
// Strength should be a random value from 0-99.  Then add 5 to make sure the
// dragon has at least 5 strength.
// Intellect should be a random value from 1-10.
// Agility should be a random value from 0-19.  Then add 2 to make sure the
// dragon has at least 2 agility.
//Copyright James Vanaselja (c) 2014. All rights reserved.
void set_stats(int * d_strength, int * d_intel, int * d_agil)
{

    //seeding the random number generator
    srand(time(0));

    //pointers for generating psuedorandom values.

    *d_strength =  rand() % 100 + 5;
    *d_intel  =  1 + rand() % 10;
    *d_agil    =  rand() % 20 + 2;

    //print statements for debugging.
    //printf("d_strength is %d\n", d_strength);
    //printf("d_intel is %d\n", d_intel);
    //printf("d_agil is %d\n", d_agil);


}

// Pre-conditions: There are no parameters for this function.
// Post-condition: The user is presented with a menu and given
//                 the opportunity to respond. If they respond with
//                 a valid menu option, return the user's choice.
//
// What to do in this function: Prompt the user with the menu and
// read in their response.  If their answer is less than 0 or greater
// than 5, continue to prompt them until they provide a valid answer.
// Then, return their answer.

int menu()
{
    int choice=0;

    //While loop for menu.
    while (choice!=4)
    {

        //prints a menu for the user
        printf("What would you like to do today?\n");

        printf("\t 1 - Train Strength.\n");
        printf("\t 2 - Train Knowledge.\n");
        printf("\t 3 - Train Agility.\n");
        printf("\t 4 - Attempt the Obstacle Course.\n");


        /* scans in the user's selection and uses an if statement
        to determine which option from the menu to select. */

        scanf("%d", &choice);

        if(choice>0 && choice<5)
            return choice;
        else
            printf("That is not a valid choice. Please try another selection.");
        printf("\n");
    }


}


// Pre-condition: None
// Post-condition: The weather report for the day is printed and the
//                 corresponding weather status in between 1 and 5,
//                 inclusive, is returned.
int weather()
{
    // Get the weather status value.
    int retval = rand()%5 + 1;

    printf("\nHere is today's weather forecast:\n");

    // Print out the appropriate forecast for that status.\n");
    if (retval == 1)
        printf("It is cloudy with a high chance of rain.\n");
    else if (retval == 2)
        printf("It is partly cloudy and windy.\n");
    else if (retval == 3)
        printf("It is partly sunny with low humidity.\n");
    else if (retval == 4)
        printf("It is warm and sunny with medium winds.\n");
    else
        printf("It's a perfect beach day. Sunny and hot!\n");

    printf("\n");

    return retval; // Return this status value.
}

// Pre-condition: strength, intelligence, agility, and name are variables
//                that represent the name of the dragon and it's stats
// Post-condition: A listing of the dragon's stats are printed
//
// What to do with this function: This is fairly self-explanatory from the
// pre and post conditions. Look to the sample given in the assignment for
// the format.
void print_stats(int strength, int intelligence, int agility, char name[])
{

    printf("Here are %s's current stats:\n", name);
    printf("\tStrength: %d\n", strength);
    printf("\tIntelligence: %d\n", intelligence);
    printf("\tAgility: %d\n", agility);



}

// Pre-condition: weather is an integer from 1-5 that represents the
//                current day's forecast.  name is the dragon's name.
// Post-condition: A day's strength taining is carried out.  The current
//                 gain in strength is printed and returned.
//
// What to do with this function: First, determine the maximum possible
// gain in strength by mutliplying the weather by 3 and adding 5.
// If the maximum possible gain is less than 10, set it to 10.
// Then, determine the actual gain by generation a psuedorandom
// number between 1 and the maximum gain.
// Print the amount of strength gained according to the sample run,
// and return that value
int train_strength(int weather, char name[])
{
    int max_strength, actual_strength;

    max_strength =(weather * 3) + 5;
    if (max_strength<10)
    {
        max_strength = 10;
    }

    actual_strength = rand() % max_strength + 1;


    printf("After lifting weights, %s gained %d strength!\n",name, actual_strength);

    return actual_strength;

}

// Pre-condition: weather is an integer from 1-5 that represents the
//                current day's forecast.  name is the dragon's name.
// Post-condition: A day's knowledge training is carried out.  The current
//                 gain in knowledge is printed and returned.
//
// What to do with this function: First, determine the maximum possible
// gain in knowledge by dividing 15 by the weather and adding 5.
// If the maximum possible gain is less than 10, set it to 10.
// Then, determine the actual gain by generation a psuedorandom
// number between 1 and the maximum gain.
// Print the amount of intellect gained according to the sample run,
// and return that value
int train_intelligence(int weather, char name[])
{

    int max_gain,actual_gain;

    max_gain=(15/weather)+5;
    if (max_gain<10)
    {
        max_gain=10;
    }

    actual_gain = rand() % max_gain + 1;


    printf("After hitting the books, %s gained %d intellect!\n",name, actual_gain);

    return actual_gain;
}

// Pre-condition: weather is an integer from 1-5 that represents the
//                current day's forecast.  name is the dragon's name.
// Post-condition: A day's agility taining is carried out.  The current
//                 gain in agility is printed and returned.
//
// What to do with this function: First, determine the maximum possible
// gain in agility using the following function: 13 + weather%5 + (weather+4)%5
// Then, determine the actual gain by generation a psuedorandom
// number between 1 and the maximum gain.
// Print the amount of agility gained according to the sample run,
// and return that value

int train_agility(int weather, char name[])
{
    int max_agil, actual_agil;

    max_agil = 13 + weather%5 + (weather+4)%5;

    actual_agil = rand() % max_agil + 1;

    printf("After running sprints, %s gained %d agility!\n", name, actual_agil);


    return actual_agil;
}

// Pre-condition: weather is an integer from 1-5 that represents the
//                current day's forecast.  strength, intel, and agility
//                are variables representing the dragon's stats
// Post-condition: A day's obstacle course is run and a score for the
//                 run is returned.
//Do nothing
int obstacle_course(int weather, int strength, int intel, int agility)
{

    return 10 + 2*weather + strength/4 + intel + agility/2;

}

// Pre-condition: completed is an integer that represents either TRUE or FALSE
//                name is the dragon's name.
// Post-condition: The user's overall result is printed out.
//
// What to do with this function: See if the dragon completed the obstacle
// course.  Print the appropriate response according to the sample run.

void end_message(int completed, char name[])
{


    if(completed==TRUE)
    {
        printf("%s completed training! Congrats!", name);
    }

    else
    {
        printf("\nSorry, %s did not complete training. Better luck next time.", name);
    }

}

