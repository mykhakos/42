#include <unistd.h>

void ft_print_comb(void)
{
    char hundr = '0';
    char doz = '1';
    char ones = '2';
    char delim[] = ", ";

    while (hundr <= '7')
    {
        write(1, &hundr, 1);
        write(1, &doz, 1);
        write(1, &ones, 1);

        ones += 1;

        if (ones > '9')
        {
            doz += 1;

            if (doz > '8')
            {
                
                hundr += 1;
                doz = hundr + 1;
            }

            ones = doz + 1;
        }

        write(1, &delim, 2);
        
    }
}

int main(void)
{
    ft_print_comb();
}