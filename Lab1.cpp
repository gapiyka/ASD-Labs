#include <stdio.h>


int main()
{
    //   4x^2 + 2       x (-15; 3]
    //y=
    //   3x^3 / 4 - 5       x (-N; -30] U (20; +N)

    float input;
    float y_value = 0;

    printf("Please input your X-number\n");
    scanf_s("%f", &input);
    if (input > -15) {
        if (input <= 3) {
            y_value = (4 * input * input) + 2;
            printf("%f", y_value);
        }
        else if (input > 20) {
            y_value = ((3 * input * input * input) / 4) - 5;
            printf("%f", y_value);
        }
        else
            printf("Sorry but your number is outside of possible values");
    }
    else if (input <= -30) {
        y_value = ((3 * input * input * input) / 4) - 5;
        printf("%f", y_value);
    }
    else
        printf("Sorry but your number is outside of possible values");


    return 1;
}


/*int main()
{
    float input = 0;
    printf("Please input your X-number\n");
    scanf_s("%f", &input);
    if(input > -15 && input <= 3){
        printf("Result: %f", (4 * input * input) + 2);
    }
    else if (input <= -30 || input > 20){
        printf("Result: %f", ((3 * input * input * input) / 4) - 5);
    }
    else {
        printf("Smthing get wrong");
    }
    return 1;
}*/