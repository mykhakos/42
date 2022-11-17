#include <unistd.h>
#include <stdio.h>

void ft_print_comb(void)
{
    char doz1 = '6';
    char num1 = '9';
    char doz2 = '9';
    char num2 = '8';
    char delim[] = ", ";

    while ((doz1+doz2) <= 57+57)
    {
        write(1, &doz1, 1);
        write(1, &num1, 1);
        write(1, " ", 1);
        write(1, &doz2, 1);
        write(1, &num2, 1);
        write(1, &delim, 2);

        num2 += 1;

        if (num2 > '9')
        {
            doz2 += 1;
            num2 = '0';
        }
        
        if (doz2 > '9')
        {
            num1 += 1;

            if (num1 > '9')
            {
                doz1 += 1;
                num1 = '0';
            }
            
            doz2 = doz1;
            num2 = num1 + 1;

            if (num2 > '9')
            {
                doz2 += 1;
                num2 = '0';
            }
        }



        /*
        printf("\n----\n");
        printf("doz1: %i -> %c\t", doz1, doz1);
        printf("num1: %i -> %c\n", num1, num1);
        printf("doz2: %i -> %c\t", doz2, doz2);
        printf("num2: %i -> %c\n", num2, num2);
        printf("\n");
        */
        

        


    }

}

int main(void)
{
    ft_print_comb();
}