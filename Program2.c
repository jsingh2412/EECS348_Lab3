#include <stdio.h>

int main()
{
    int score;
    int cont = 1;
    int td2pnt = 8;
    int td1pnt = 7;
    int td = 6;
    int fg = 3;
    int safety = 2;
    int currentSum;
    while(cont==1)
    {
        printf("Enter 0 or 1 to STOP\n");
        printf("Enter the NFL score: ");
        scanf("%d", &score);
        if(score==0 || score==1)
        {
            cont = 0;
        }
        //x=td2pnt
        //y=td1pnt
        //z=td1pnt
        //i=fg
        //j=safety
        for(int x = 0; x<(score/td2pnt); x++)
        {
            for(int y = 0; y<(score/td1pnt); y++)
            {
                for(int z = 0; z<(score/td); z++)
                {
                    for(int i = 0; i<(score/fg); i++)
                    {
                        for(int j = 0; j<(score/safety); j++)
                        {
                            currentSum = (x*td2pnt)+(y*td1pnt)+(z*td)+(i*fg)+(j*safety);
                            if(score==currentSum)
                            {
                                printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", x, y, z, i, j);;
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}
