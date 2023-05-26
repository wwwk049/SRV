#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <cstring> 
#include <errno.h> 

int main()
{
    pid_t pid = fork();
    if (pid == -1)
    {
        std::cerr << "fork error: " << strerror(errno) << std::endl; // Используем strerror для вывода сообщения об ошибке
        exit(1);
    }
    if (pid != 0)
        std::cout << "Parent: Kalaganov " << getpid() << std::endl;
    else
        std::cout << "Child: Kirill I993 " << getpid() << std::endl;
    sleep(20);
    return 0;
}
