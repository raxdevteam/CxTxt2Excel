#ifndef PASSWORDMASKING_H
#define PASSWORDMASKING_H

#if defined __linux__ || defined __apple__ || defined __bsd__
    #include <termios.h>
    #include <unistd.h>

#elif _WIN32
    #include <windows.h>
#else
  #error "Unknown platform"
#endif

#include <iostream>
#include <string>

class PasswordMasking
{
public:
    PasswordMasking();
    int getch();
    std::string uni_console_getpass(const char *prompt, bool show_asterisk=true);
    std::string win_consnole_getpass(const char *prompt, bool show_asterisk=true);
    void echo_with_mask();
    void echo_hide();
    void echo_no_mask();
};

#endif // PASSWORDMASKING_H
