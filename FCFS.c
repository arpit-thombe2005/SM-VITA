#include <stdio.h>

int main()
{
    const char *Processes[50] = {"P1", "P2", "P3", "P4"};
    int AT[50] = {0, 2, 4, 6};
    int BT[50] = {5, 9, 2, 3}; 
    int CT[50];            
    int TAT[50];           
    int WT[50];          
    int n = 4; 
    
    // Initialize sums for average calculations
    int totalTAT = 0;
    int totalWT = 0;

    // First process calculations
    CT[0] = AT[0] + BT[0];
    TAT[0] = CT[0] - AT[0];
    WT[0] = TAT[0] - BT[0];

    totalTAT += TAT[0];
    totalWT += WT[0];

    // Calculations for the rest of the processes
    for (int i = 1; i < n; i++)
    {
        if (CT[i - 1] < AT[i])
        {
            CT[i] = AT[i] + BT[i]; 
        }
        else
        {
            CT[i] = CT[i - 1] + BT[i]; 
        }
        TAT[i] = CT[i] - AT[i];
        WT[i] = TAT[i] - BT[i];

        totalTAT += TAT[i];
        totalWT += WT[i];
    }

    // Print the process details
    printf("Processes\t\tAT\t\tBT\t\tCT\t\tTAT\t\tWT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s\t\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", Processes[i], AT[i], BT[i], CT[i], TAT[i], WT[i]);
    }

    // Calculate and print average TAT and WT
    float avgTAT = (float)totalTAT / n;
    float avgWT = (float)totalWT / n;

    printf("\nAverage Turnaround Time: %.2f\n", avgTAT);
    printf("Average Waiting Time: %.2f\n", avgWT);

    return 0;
}