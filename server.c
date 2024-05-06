#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_wait
{
    pid_t   pid_client;
    char    *str;
    char    i;
    int     bits;
    struct  s_wait  *next;
}   t_wait;

t_wait *list = NULL;

int client_exist(pid_t client)
{
    t_wait *tmp;

    tmp = list;
    while (tmp)
    {
        if (tmp->pid_client == client)
            return (1);
        tmp = tmp->next;
    }
    return (0);
}

void    add_client(pid_t client)
{
    t_wait  *new_client;
    t_wait  *tmp;

    new_client = malloc(sizeof(t_wait));
    if (!new_client)
    {
        printf("gerer erreur ici");
        return ;
    }
    new_client->pid_client = client;
    new_client->str = NULL;
    new_client->i = 0;
    new_client->bits = 0;
    new_client->next = NULL;
    if (!list)
        list = new_client;
    else
    {
        tmp = list;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = new_client;
    }
}

char    *add_char(char *str, char c)
{
    char    *result;
    int     i;

    result = malloc(sizeof(char) * strlen(str) + 2);
    if (!result)
    {
        printf("gestion erreur");
        return (NULL);
    }
    i = 0;
    while (str[i])
    {
        result[i] = str[i];
        i++;
    }
    result[i] = c;
    result[i + 1] = '\0';
    return (result);
}

int is_valid(char *str)
{
    int i;
    int len;

    i = 0;
    while (str[i])
    {
        if (str[i] == '\n')
            return (1);
        i++;
    }
    return (0);
}

void delete_client(t_wait *client) {
    if (!list || !client)
        return;

    if (list == client) {
        list = list->next;
        free(client);
        return;
    }

    t_wait *tmp = list;
    while (tmp->next && tmp->next != client)
        tmp = tmp->next;
    if (tmp->next == client) {
        tmp->next = client->next;
        free(client);
    }
}

void handle(int sig, siginfo_t *info, void *context) {
    t_wait  *tmp;

    if (!client_exist(info->si_pid))
        add_client(info->si_pid);
    tmp = list;
    while (tmp->pid_client != info->si_pid)
        tmp = tmp->next;
    if (sig == SIGUSR1)
        tmp->i |= (0x01 << tmp->bits);
    tmp->bits++;
    if (!tmp->str)
        tmp->str = strdup("");
    if (tmp->bits == 8)
    {
        tmp->str = add_char(tmp->str, tmp->i);
        tmp->bits = 0;
        tmp->i = 0;
    }
    kill(tmp->pid_client, SIGUSR1);
}

int main()
{
    printf("PID => %d", getpid());
    fflush(stdout);
    struct sigaction sa;
    sa.sa_sigaction = handle;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_SIGINFO;

    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    t_wait  *tmp;
    while (1)
    {
         tmp = list;
        while (tmp)
        {
            if (is_valid(tmp->str))
            {
                printf("Client %d => %s", tmp->pid_client, tmp->str);
                fflush(stdout);
                delete_client(tmp);
            }
            tmp = tmp->next;
        }
    };
    return (0);
}