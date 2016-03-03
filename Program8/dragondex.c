//James Vanaselja
//11.18.14
//COP 3223 Section 1
//Program 8
//This program adds, removes, searches and lists dragons.
//Dragondex.c
/*
Warning:
Copying and pasting this code is a violation of UCF's Golden Rule.
*/

//Constants
#define MAX_LENGTH 40
#define MAX_TEAM 100


//Libraries
#include <stdio.h>
#include <string.h>

//Structures
struct dragon {
    char name[MAX_LENGTH];
    char color[MAX_LENGTH];
    };
struct collection {
    struct dragon team[MAX_TEAM];
    int num_dragons;
};
//Function Protoypes

void search_dragon(struct collection * team1, char * name);
void add_dragon(struct collection * team1, char * name, char * color);
void list_dragon(struct collection * team1, char * color);
void remove_dragon(struct collection * team1, char * name);



//Main function

int main(){
char color[MAX_LENGTH], name[MAX_LENGTH];
char commands[MAX_LENGTH];
struct collection dteam;
int num_commands=0;
dteam.num_dragons=0;

// Open file
    //make sure the textfile named "dragon.txt" is in the same directory as the program.
    FILE * ifp = fopen("dragon.txt", "r");
    int i;

    if(ifp == NULL) {
        printf("Failure to open file. Verify file path.\n");
            return 1;}

    fscanf(ifp, "%d", &num_commands);


    for (i=0; i<num_commands; i++) {
        fscanf (ifp, "%s", commands);


    //String compare to ADD
    if (strcmp(commands,"ADD")== 0)
            {
                fscanf(ifp,"%s",name);
                fscanf(ifp, "%s", color);
                add_dragon(&dteam, name, color);
            }

    //String Compare to LIST.

    if (strcmp(commands,"LIST")== 0)
            {
                fscanf (ifp, "%s", color);
                list_dragon(&dteam, color);
            }

    //String Compare to SEARCH.

    if (strcmp(commands,"SEARCH")==0)
            {
                fscanf(ifp,"%s", name);
                search_dragon(&dteam, name);
            }

    //String compare to REMOVE.

    if (strcmp(commands,"REMOVE")== 0)
            {
                fscanf(ifp,"%s",name);
                remove_dragon(&dteam, name);
            }

    }
        fclose(ifp);
    return 0;

}

//Add a Dragon

    void add_dragon(struct collection * team1, char * name, char * color)
    {
    int i;

    printf("\n%s the %s dragon has been added to the team.\n\n",name, color);


    strcpy(team1->team[team1->num_dragons].name, name);
    strcpy(team1->team[team1->num_dragons].color, color);

    team1->num_dragons++;


    return;

    }

//Remove a Dragon

  void remove_dragon(struct collection * team1, char * name)
    {
        int i;

    for(i=0; i<team1->num_dragons; i++)
        {
        if (strcmp(team1->team[i].name, name)== 0){

        printf("\n%s the %s dragon has been removed from the team.\n\n",team1->team[i].name, team1->team[i].color);

        strcpy(team1->team[i].name, team1->team[team1->num_dragons-1].name);
        strcpy(team1->team[i].color, team1->team[team1->num_dragons-1].color);
        }

    }
    team1->num_dragons--;
        return;
    }

//Search for a dragon

void search_dragon(struct collection * team1, char * name)
    {
    int i, flag=0;
        for(i=0; i<team1->num_dragons; i++)
        {
            if (strcmp(team1->team[i].name, name)== 0)
            {
                printf("%s the dragon is currently on the team\n\n", name);
                flag=1;
            }
        }
        if (flag==0)
        {
            printf("%s the dragon is NOT currently on the team\n\n", name);
        }
    return;
}


//List dragon

   void list_dragon(struct collection * team1, char * color)
   {
       int i;

    printf("\n%s dragons:\n", color);
        for(i=0; i<team1->num_dragons; i++)
           {
               if (strcmp(team1->team[i].color, color)== 0)

                printf("%s\n", team1->team[i].name);
           }
        return;
    }










