#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// Komut geçmişini temizleyen bir işlev
void clearCommandHistory() 
{
    clear_history();
    printf("Komut geçmişi temizlendi.\n");
}

// Kullanıcının girdisini işleyen bir işlev
void processInput(char *input, char *envp[]) 
{
    if (strcmp(input, "clear") == 0) 
    {
        char *args[] = { "/usr/bin/clear", NULL };
        execve("/usr/bin/clear", args, envp);
        perror("execve");
    }
    else if(strcmp(input, "ls") == 0)
    {
        // ls komutu
        char *args[] = { "/bin/ls", NULL };
        execve("/bin/ls", args, envp);
        perror("execve");
    }
    else if (strcmp(input, "clearall") == 0) 
    {
        clearCommandHistory();
    } 
    else if (strcmp(input, "history") == 0) 
    {
        HIST_ENTRY **historyList = history_list();
        if (historyList != NULL) 
        {
            for (int i = 0; historyList[i] != NULL; i++) 
            {
                printf("%d: %s\n", i + 1, historyList[i]->line);
            }
        }
    } 
    else 
    {
        // Kullanıcının girdisini ekrana yazdırın
        printf("Girdiğiniz komut: %s\n", input);
    }
}

int main(int argc, char *argv[], char *envp[]) 
{
    // argc ve argv voidliyoruz
    (void)argc;
    (void)argv;

    // Kullanıcıdan girdi almak için readline'ı başlatın
    while (1) 
    {
        char *input = readline("Komut girin (çıkmak için 'exit', 'clear', 'clearall' veya 'history' yazın): ");
        
        pid_t pid = fork();

        if (pid == -1) 
        {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if(!pid)
        {
            processInput(input, envp);
            exit(EXIT_SUCCESS);
        }
        else
        {
            wait(NULL);
        }
        // Kullanıcının girdisini komut geçmişine ekleyin
        add_history(input);


        // Kullanıcının "exit" komutunu kullanarak çıkmasını kontrol edin
        if (strcmp(input, "exit") == 0) 
        {
            printf("Çıkılıyor...\n");
            free(input); // Belleği serbest bırakın ve döngüyü sonlandırın
            break;
        }

        // readline tarafından tahsis edilen belleği serbest bırakın
        free(input);
    }

    return 0;
}


-------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>

// Komut geçmişini temizleyen bir işlev
void clearCommandHistory() 
{
    clear_history();
    printf("Komut geçmişi temizlendi.\n");
}

// Kullanıcının girdisini işleyen bir işlev
void processInput(char *input) 
{ 
    if (strcmp(input, "clear") == 0) 
    {
        clearCommandHistory();
    } 
    else if (strcmp(input, "clearall") == 0) 
    {
        clearCommandHistory();
    } 
    else if (strcmp(input, "history") == 0) 
    {
        HIST_ENTRY **historyList = history_list();
        if (historyList != NULL) 
        {
            for (int i = 0; historyList[i] != NULL; i++) 
            {
                printf("%d: %s\n", i + 1, historyList[i]->line);
            }
        }
    } 
    else 
    {
        // Kullanıcının girdisini ekrana yazdırın
        printf("Girdiğiniz komut: %s\n", input);
    }
}

int main() 
{
    while (1) 
    {
        char *input = readline("Komut girin (çıkmak için 'exit', 'clear', 'clearall' veya 'history' yazın): ");

        // Kullanıcının girdisini komut geçmişine ekleyin
        add_history(input);

        // Kullanıcının girdisini işleyin
        processInput(input);

        // Kullanıcının "exit" komutunu kullanarak çıkmasını kontrol edin
        if (strcmp(input, "exit") == 0) 
        {
						printf("Çıkılıyor...\n");
            free(input); // Belleği serbest bırakın ve döngüyü sonlandırın
            break;
        }

        // readline tarafından tahsis edilen belleği serbest bırakın
        free(input);
    }

    return 0;
}