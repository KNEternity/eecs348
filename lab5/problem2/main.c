#include <stdio.h>


//define different scoring plays 

#define twoPointConversion 8 
#define onePointConversion 7 
#define Touchdown 6
#define fieldGoal 3
#define Saftey 2

int calculateScoreFromCombination(int *combination){
    return combination[0] * twoPointConversion + combination[1] * onePointConversion + combination[2] *Touchdown + combination[3] *fieldGoal + combination[4] *Saftey;
}

// Print all possible scores from one score 

void printCombinations(int score)
{
    int combination[5]; 
    combination[0] = 0; // TD + 2conversion
    combination[1] = 0; // TD + 1conversion 
    combination[2] = 0; // TD 
    combination[3] = 0; // FG
    combination[4] = 0; // Saftey 

    //iterate over possible scoring plays
    printf("Possible scoring plays:\n");
    while (1)
    {
        if (calculateScoreFromCombination(combination) == score)
        {
            printf("%d TD+2pt, %d TD + FG, %d TD, %d FG, %d Saftey\n", combination[0],combination[1],combination[2],combination[3],combination[4]);
        }
        //increment saftey by 1 then shift scores down until over max
        combination[4]++; 

        if (combination[4] * Saftey > score)
        {
            combination[4] = 0;
            combination[3]++; 
        }
        if (combination[3] * fieldGoal > score)
        {
            combination[3] = 0; 
            combination[2] ++; 
        }
        if (combination[2] * Touchdown > score)
        {
            combination[2] = 0; 
            combination[1]++; 
        }
        if (combination[1] * onePointConversion > score)
        {
            combination[1] = 0; 
            combination[0]++; 

        }
        if (combination[0] * twoPointConversion > score)
        {
            break;//since this the largest possible combination 
        }
    }
}

int main(){
    while (1)
    {
        int score; 
        printf("Enter 0 or 1 to Exit\n");
        printf("Enter NFL score: ");
        scanf("%d", &score); 

        if (score < 0)
        { 
            printf("Invalid score\n");
            return 1; 
        }
        else if (score <= 1)
        {
            return 0; 
        }
        printCombinations(score);
        printf("\n");
    }
    return 0; 
}
