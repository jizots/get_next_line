#include <stdlib.h>

# ifdef EXE_BONUS
#include "includes/get_next_line_bonus.h"
int main(void)
{
    int fd1;
    int fd2;
    char* line;

    fd1 = open("./test_files/short_text1", O_RDONLY);
    fd2 = open("./test_files/short_text2", O_RDONLY);
    if (fd1 == -1 || fd2 == -1)
        return (printf("Error: file not found\n"), 1);
    while(1)
    {
        line = get_next_line(fd1);
        if (line == NULL)
            break;
        printf("%s", line);
        free(line);
        line = get_next_line(fd2);
        if (line == NULL)
            break;
        printf("%s", line);
        free(line);
    }
    system("leaks a.out");
}
# else
#include "includes/get_next_line.h"
int main(void)
{
    int fd;
    char* line;

    fd = open("./test_files/long_text", O_RDONLY);
    if (fd == -1)
        return (printf("Error: file not found\n"), 1);
    while(1)
    {
        line = get_next_line(fd);
        if (line == NULL)
            break;
        printf("%s\n", line);
        free(line);
    }
    system("leaks a.out");
}

# endif

