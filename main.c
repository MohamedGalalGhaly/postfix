#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct NODE
{
    int data;
    struct Node* link;
}Node;

Node *stackPtr = NULL;

void push(int);
int pop();
void print();
int perform (char, int, int);

int main()
{
    char exp[20];
    int i, num1, num2, result;

    scanf("%s", exp);
    for (i=0; i<strlen(exp); i++)
    {
        if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/')
        {

            num2 = pop();
            num1 = pop();

            result = perform (exp[i], num1, num2);
            push(result);

        }

        else
        {
            push (exp[i]-'0');
        }
    }

    print();

    return 0;
}

void push (int num)
{
    Node *current = (Node*) malloc(sizeof(Node));

    if (stackPtr == NULL)
    {
        stackPtr = current;
        current->data = num;
        current->link = NULL;
    }

    else
    {
        current->data = num;
        current->link = stackPtr;
        stackPtr = current;
    }
}

int pop ()
{
    int num;

    Node *temp = NULL;
    temp = stackPtr;
    num = stackPtr->data;
    stackPtr = stackPtr->link;
    free(temp);

    return num;
}

void print()
{
    Node *temp = stackPtr;

    while (temp != NULL)
    {
        printf("%i\n", temp->data);
        temp = temp->link;
    }
}


int perform (char operation, int num1, int num2)
{
    int result;

    switch (operation)
    {
        case '+':
            result = num1 + num2;
            break;

        case '-':
            result = num1 - num2;
            break;

        case '*':
            result = num1 * num2;
            break;

        case '/':
            result = num1 / num2;
            break;
    }
    return result;

}
