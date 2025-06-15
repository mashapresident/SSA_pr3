#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){ 
        FILE *file = fopen("dice.log", "w");
        if(!file) {return 1;}

        srand(time(NULL));
        while(1){ 
                if(fprintf(file, "%d\n", rand()%6 + 1) < 0){ 
                        perror("write error\n");
                        break;
                }
        }
        fclose(file);
        return 0;
}