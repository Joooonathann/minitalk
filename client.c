#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

int signal_received = 0;

void signal_handler(int signum) {
    signal_received = 1;
}

int send_bit(char c, int pid)
{
    int bin = 0;

    signal(SIGUSR1, signal_handler);
    while (bin < 8)
    {
        if ((c & (0x01 << bin)) != 0)
        {
            if (kill(pid, SIGUSR1) == -1)
                return (0);
        }
        else
        {
            if (kill(pid, SIGUSR2) == -1)
                return (0);
        }
        while(signal_received == 0);
        signal_received = 0;
        bin++;
    }
    return (1);
}

int send_message(const char *str, int pid)
{
    while (*str)
    {
        if (!send_bit(*str, pid))
            return (0);
        str++;
    }
    if (!send_bit('\n', pid))
        return (0);
    return (1);
}

int is_valid_pid(int pid)
{
    if (kill(pid, 0) == 0)
        return (1);
    return (0);
}

int main(int argc, char **argv)
{
    int pid;

    if (argc != 3)
    {
        printf("\033[1;31mClient\033[0m -> Format invalide\n\033[1;36m\
Essayez: './client <pid> <message>'\033[0m");
        return (1);
    }
    pid = atoi(argv[1]);
    if (!is_valid_pid(pid))
    {
        printf("\033[1;31mClient\033[0m -> PID incorrect\n\033[1;36m\
Le PID fourni n'est pas correct\033[0m");
        return (1);
    }
    if (!send_message(argv[2], pid))
    {
        printf("\033[1;31mClient\033[0m -> Problème lors de l'envoi du message");
        return (1);
    }
    printf("\033[1;32mClient\033[0m -> Message envoyé %d\n", getpid());
    return (0);
}
