#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_LEN 4096

void recovery(char *homework)
{
    char *token = malloc(sizeof(char) * MAX_LEN);
    char *after = malloc(sizeof(char) * MAX_LEN);
    char *tempr = malloc(sizeof(char));
    char *tempf = malloc(sizeof(char));

    int i = 0, fail = 0, last;

    token = strtok(homework, " \n"); //fgets will read \n we need to transform it to '\0'

    while (1)
    {
        for (; token[i]; i++)
        {
            if ((token[i] >= 'A' && token[i] <= 'Z') || (token[i] >= 'a' && token[i] <= 'z'))
            {
            }
            else if (token[i] == '.' || token[i] == ',' || token[i] == '!' || token[i] == '?' || token[i] == ' ' || token[i] == '\n')
            {

                if (i == 0)
                    fail++; // punctuation mark along
            }
            else
                fail++;
        }

        last = i - 1;
        tempf = strchr(token, '!');
        tempr = strrchr(token, '!');
        if (tempr == NULL || tempf == NULL)
        {
        }
        else
        {
            if (tempf == tempr && &token[last] == tempr && &token[last] == tempf)
            {
            }
            else
            {
                fail++;
            }
        }

        tempf = strchr(token, '?');
        tempr = strrchr(token, '?');
        if (tempr == NULL || tempf == NULL)
        {
        }
        else
        {
            if (tempf == tempr && &token[last] == tempr && &token[last] == tempf)
            {
            }
            else
            {
                fail++;
            }
        }
        tempf = strchr(token, ',');
        tempr = strrchr(token, ',');
        if (tempr == NULL || tempf == NULL)
        {
        }
        else
        {
            if (tempf == tempr && &token[last] == tempr && &token[last] == tempf)
            {
            }
            else
            {
                fail++;
            }
        }
        tempf = strchr(token, '.');
        tempr = strrchr(token, '.');
        if (tempr == NULL || tempf == NULL)
        {
        }
        else
        {
            if (tempf == tempr && &token[last] == tempr && &token[last] == tempf)
            {
            }
            else
            {
                fail++;
            }
        }

        if (i > 21 || i == 0)
        { //#characters
            fail++;
        }

        if (fail == 0)
        {

            strcat(after, token);
            strcat(after, " ");
        }
        token = strtok(NULL, " \n");

        if (token == NULL)
            break;
        i = 0;
        fail = 0;
    }

    strcpy(homework, after);
    tempr = strrchr(homework, ' ');

    if (tempr != NULL)
    {
        *tempr = '\0';
    }
}


int main () {
    char homework[MAX_LEN + 1];

    // Get the homework content.
    fgets(homework, MAX_LEN , stdin);
    //recovery(homework);
    recovery(homework);
    // Print the recovered homework.
    fputs(homework, stdout);

    return 0;
}