#include <stdio.h>
#include <math.h>

int main()
{
    int input;
    int sum;
    double result = 1;
    int counter = 0;

    printf_s("Please, input your integer number\n");
    scanf_s("%d", &input);

    for (int i = 1; !(i > input); i++)
    {
        sum = 0;
        for (int j = 1; !(j > i); j++)
        {
            sum += 2 * j + 1;
            counter += 3;
        }
        result *= 2 * i * log(i + 3) / sum;
        counter += 6;
    }
    printf_s("Result equal: %.7f", result);
    printf_s("\nTotal ammount of counts: %d", counter);

    return 1;
}

#include <stdio.h>
#include <math.h>

int main() 
{
    int input;
    int sum = 0;
    double result = 1;
    int counter = 0;

    printf_s("Please, input your integer number\n");
    scanf_s("%d", &input);

    for (int i = 1; !(i > input); i++)
    {
        sum += 2*i + 1;
        counter += 3;
        result *= 2*i*log(i+3)/sum;
        counter += 6;
    }
    printf_s("Result equal: %.7f", result);
    printf_s("\nTotal ammount of counts: %d", counter);

    return 1;
}
