#include <stdio.h>

#define max(a,b) (a > b ? a : b)

int matrix[100][100] = {0};
int picks[100][100] = {0};

int knapsack(int nItems, int size, int weights[], int values[]){
    int i,j;

    for (i=1;i<=nItems;i++){
        for (j=0;j<=size;j++){
            if (weights[i-1]<=j){
                matrix[i][j] = max(matrix[i-1][j],values[i-1]+matrix[i-1][j-weights[i-1]]);
                if (values[i-1]+matrix[i-1][j-weights[i-1]]>matrix[i-1][j])
                    picks[i][j]=1;
                else
                    picks[i][j]=-1;
            }
            else{
                picks[i][j] = -1;
                matrix[i][j] = matrix[i-1][j];
            }
        }
    }

    return matrix[nItems][size];

}

void printPicks(int item, int size, int weights[]){

    while (item>0){
        if (picks[item][size]==1){
            printf("%d ",weights[item-1]);
            item--;
            size -= weights[item];
        }
        else{
            item--;
        }
    }

    printf("\n");

return;
}

int main(){
    int nItems = 6;
    int knapsackSize = 18;
    int weights[6] = {2,4,5,6,7,12};
    int values[6] = {1,1,1,1,1,1};

    printf("Max value = %d\n",knapsack(nItems,knapsackSize,weights,values));
    printf("Picks were: ");
    printPicks(nItems,knapsackSize, weights);

    return 0;
}