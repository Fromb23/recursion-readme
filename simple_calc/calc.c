#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_HISTORY 10

typedef struct
{
    char operator;
    double num1;
    double num2;
    double result;
} Calculation;

Calculation history[MAX_HISTORY];
int history_count = 0;

void addToHistory(char operator, double num1, double num2, double result)
{
    if (history_count < MAX_HISTORY)
    {
        history[history_count].operator = operator;
        history[history_count].num1 = num1;
        history[history_count].num2 = num2;
        history[history_count].result = result;
        history_count++;
    }
    else
    {
        for (int i = 1; i < MAX_HISTORY; i++)
        {
            history[i - 1] = history[i];
        }
        history[MAX_HISTORY - 1].operator = operator;
        history[MAX_HISTORY - 1].num1 = num1;
        history[MAX_HISTORY - 1].num2 = num2;
        history[MAX_HISTORY - 1].result = result;
    }
}

void showHistory()
{
    printf("\nCalculation History:\n");
    if (history_count == 0)
    {
        printf("No calculations performed yet.\n");
        return;
    }
    printf("-------------------\n\n");
    for (int i = 0; i < history_count; i++)
    {
        printf("%d: %.2lf %c %.2lf = %.2lf\n",
               i + 1,
               history[i].num1,
               history[i].operator,
               history[i].num2,
               history[i].result);
    }
    printf("-------------------\n\n");
    printf("Total calculations: %d\n", history_count);
    if (history_count == MAX_HISTORY)
    {
        printf("Note: History is limited to the last %d calculations.\n", MAX_HISTORY);
    }
}

void printMenu()
{
    printf("\nScientific Calculator Menu:\n");
    printf("+ : Addition\n");
    printf("- : Subtraction\n");
    printf("* : Multiplication\n");
    printf("/ : Division\n");
    printf("^ : Exponentiation\n");
    printf("s : Square root\n");
    printf("l : Logarithm (base 10)\n");
    printf("e : Natural logarithm (base e)\n");
    printf("c : Cosine (radians)\n");
    printf("t : Tangent (radians)\n");
    printf("h : Show history\n");
    printf("m : Memory functions\n");
    printf("q : Quit\n");
}

void memoryMenu(double *memory)
{
    char choice;
    double value;

    printf("\nMemory Functions:\n");
    printf("1 : Store value in memory\n");
    printf("2 : Recall value from memory\n");
    printf("3 : Clear memory\n");
    printf("4 : Add value to memory\n");
    printf("5 : Subtract value from memory\n");
    printf("b : Return to main menu\n");
    printf("Enter your choice: ");
    scanf(" %c", &choice);

    switch (choice)
    {
    case '1':
        printf("Enter value to store: ");
        scanf("%lf", &value);
        *memory = value;
        printf("Value %.2lf stored in memory.\n", value);
        break;
    case '2':
        printf("Memory value: %.2lf\n", *memory);
        break;
    case '3':
        *memory = 0;
        printf("Memory cleared.\n");
        break;
    case '4':
        printf("Enter value to add: ");
        scanf("%lf", &value);
        *memory += value;
        printf("Memory is now %.2lf\n", *memory);
        break;
    case '5':
        printf("Enter value to subtract: ");
        scanf("%lf", &value);
        *memory -= value;
        printf("Memory is now %.2lf\n", *memory);
        break;
    case 'b':
        return;
    default:
        printf("Invalid choice.\n");
    }
}

int main()
{
    char input[20];
    double num1, num2, result;
    char operator;
    double memory = 0.0;
    double useMemory = 0.0;

    printf("Welcome to the Scientific Calculator!\n");
    printf("\n..........................................\n");

    while (1)
    {
        printMenu();
        printf("Enter your operation (or 'h' for history, 'm' for memory functions, 'q' to quit): ");
        scanf(" %s", input);
        if (strlen(input) == 0)
        {
            printf("No input provided. Please try again.\n");
            continue;
        }
        if (strlen(input) == 1)
        {
            char op = input[0];
            if (op == 'q')
            {
                printf("Exiting calculator. Bye!\n");
            }
            else if (op == 'h')
            {
                showHistory();
                continue;
            }
            else if (op == 'm')
            {
                memoryMenu(&memory);
                continue;
            }
            else
            {
                printf("Invalid operation. Please try again.\n");
                continue;
            }

            if (op == 's' || op == 'l' || op == 'e' || op == 'c' || op == 't')
            {
                printf("Enter number: ");
                scanf("%lf", &num1);
                switch (op)
                {
                case 's':
                    result = sqrt(num1);
                    operator = '√';
                    break;
                case 'l':
                    result = log10(num1);
                    operator = 'l';
                    break;
                case 'e':
                    result = log(num1);
                    operator = 'e';
                    break;
                case 'c':
                    result = cos(num1);
                    operator = 'c';
                    break;
                case 't':
                    result = tan(num1);
                    operator = 't';
                    break;
                default:
                    continue;
                }
            }
            else
            {
                printf("Enter first number: ");
                scanf("%lf", &num1);
                printf("Enter second number: ");
                scanf("%lf", &num2);

                switch (op)
                {
                case '+':
                    result = num1 + num2;
                    operator = '+';
                    break;
                case '-':
                    result = num1 - num2;
                    operator = '-';
                    break;
                case '*':
                    result = num1 * num2;
                    operator = '*';
                    break;
                case '/':
                    if (num2 == 0)
                    {
                        printf("Error: Division by zero.\n");
                        continue;
                    }
                    result = num1 / num2;
                    operator = '/';
                    break;
                case '^':
                    result = pow(num1, num2);
                    operator = '^';
                    break;
                default:
                    printf("Invalid operation. Please try again.\n");
                    continue;
                }
            }
        }
    }
}