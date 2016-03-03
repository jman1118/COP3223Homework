//James Vanaselja
//COP 3223 Section 0001
//Program 5
//10.1.14
/*This program reads in a text file containing
the number of sets and reps and outpust the results using a * for
visual representation for each completed set.
*/
//Warning: Copying this code is prohibited under UCF's Golden Rule.
#include <stdio.h>

//intitialize variables.
int main ()
{

    int num_weeks,workout,sets,reps,i,j,k,m=0,sum=0;
    int average_reps=0,best_workout=0,best_week=0;
    char name [20];

//Open file.
    FILE * ifp = fopen ("input.txt", "r");

    if(ifp == NULL)
    {
        printf("Failure to open file. Verify file path.\n");
        return 1;
    }

//Name output onto screen

    fscanf (ifp, "%s", &name);
    printf("%s\n", name);

//Number of weeks

    fscanf (ifp, "%d", &num_weeks);
//For loop to calculate number of weeks.

    for (i=0; i<num_weeks; i++)
    {
        printf("\nWeek %d\n",i+1,num_weeks);

        fscanf (ifp, "%d",&workout);
//For loop to calculate number of workouts.

        for(j=0; j<workout; j++)
        {
            printf("\nWorkout %d:",j+1,workout);

//Number of sets. Variables are zeroed out again.
            fscanf(ifp,"%d", &sets);
            sum = 0;
            m = 0;
//For loop to calculate reps.
            for(k=0; k<sets; k++)
            {
                fscanf(ifp, "%d", &reps);
                sum += reps;

//if statement to print * ane
                if (reps >= 10)
                {
                    printf("*");
                    m++;
                }
//if statement for calculating the average, best week, and best workout
                if (m>best_workout)
                {
                    best_workout = m;
                    best_week = i+1;
                    average_reps = sum/m;
                }
//printf("%d");
            }   //close the inner most for loop calulating # of reps.
        }  //close inner for loop for calulating # of workouts
    } //close outer for loop for calculating weeks
//Printed average.
    printf("\nYour best workout was in week %d and contained %d sets of an average of %d reps\n", best_week, best_workout,average_reps);

//Close file.
    fclose (ifp);
    return 0;
}
