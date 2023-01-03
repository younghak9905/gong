#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/ptrace.h>
#include <sys/wait.h>
#include <sys/user.h>

char c[12];
void flag()
{
    int i = 0;
    c[0] += 53;
    c[1] += 61;
    c[2] -= 26;
    c[3] -= 6;
    c[4] += 51;
    c[5] -= 5;
    c[6] += 19;
    c[7] += 15;
    c[8] -= 15;
    c[9] += 72;
    c[10] += 73;
    c[11] += 27;
    for (i = 0; i < 12; i++)
        printf("%c", c[i]);
    printf("\n");
    system("pause");

}
void match(char b[])
{
    int i = 0;
    for (i = 0; i < 12; i++)
    {
        if (b[i] == c[i])
        {
            if (i == 11)
            {
                flag();
                break;
              
            }
            else continue;
        }
        else
        {
            printf("wrong");
            
            break;
        }
    }
}
int main()
{
    char input[12];
    int i = 0;
    printf("Enter the flag: ");
    scanf("%s", input);
    if (strlen(input) < 12)
    {
        printf("too short\n");
        system("pause");
        return 0;

    }

        // Anti-debugging techniques
        ptrace(PTRACE_TRACEME, 0, 0, 0);
    if (ptrace(PTRACE_TRACEME, 0, 0, 0) == -1) {
        printf("Debugger detected!\n");
        return 0;
    }

    // Anti-disassembly techniques
    char temp;
    c[0] = 'E';

    __asm__ __volatile__(
        "nop\n"  // no operation
        "nop\n"  // no operation
        "nop\n"  // infinite loop
    );

    for (i = 1; i < 6; i++)
    {
        temp = (input[i - 1] * 4 + 3) % 126;
        if (temp < 33)
        {
            c[i] = temp + 34;
        }
        else
        {
            c[i] = temp;
        }
    }
    for (i = 6; i < 12; i++)
    {
        temp = (input[i - 1] * 8 - 10) % 126;
        if (temp < 33)
        {
            c[i] = temp + 34;
        }
        else
        {
            c[i] = temp;
        }
    }
    match(input);
    system("pause");
    return 0;
}