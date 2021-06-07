#include "passwordmasking.h"

PasswordMasking::PasswordMasking()
{

}

#if defined __linux__ || defined __apple__ || defined __bsd__
int PasswordMasking :: getch()
{
    int ch;
    struct termios t_old, t_new;

    tcgetattr(STDIN_FILENO, &t_old);
    t_new = t_old;
    t_new.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &t_new);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &t_old);
    return ch;
}

std::string PasswordMasking :: uni_console_getpass(const char *prompt, bool show_asterisk)
{
  const char BACKSPACE=127;
  const char RETURN=10;

  std::string password;
  unsigned char ch=0;

  std::cout <<prompt<<std::endl;

  while((ch=getch())!=RETURN)
    {
       if(ch==BACKSPACE)
         {
            if(password.length()!=0)
              {
                 if(show_asterisk)
                 std::cout <<"\b \b";
                 password.resize(password.length()-1);
              }
         }
       else
         {
             password+=ch;
             if(show_asterisk)
                 std::cout <<'*';
         }
    }
  std::cout << std::endl;
  return password;
}
#endif

#if defined _WIN32
std::string win_consnole_getpass(const char *prompt, bool show_asterisk=true)
{
  const char BACKSPACE=8;
  const char RETURN=13;

  std::string password;
  unsigned char ch=0;

  std::cout <<prompt<< std::endl;

  DWORD con_mode;
  DWORD dwRead;

  HANDLE hIn=GetStdHandle(STD_INPUT_HANDLE);

  GetConsoleMode( hIn, &con_mode );
  SetConsoleMode( hIn, con_mode & ~(ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT) );

  while(ReadConsoleA( hIn, &ch, 1, &dwRead, NULL) && ch !=RETURN)
    {
       if(ch==BACKSPACE)
         {
            if(password.length()!=0)
              {
                 if(show_asterisk)
                     std::cout <<"\b \b";
                 password.resize(password.length()-1);
              }
         }
       else
         {
             password+=ch;
             if(show_asterisk)
                 std::cout <<'*';
         }
    }
  std::cout << std::endl;
  return password;
}
#endif

void PasswordMasking :: echo_with_mask()
{
    const char *correct_password="null";
    std::string password;
#if defined __linux__ || defined __apple__ || defined __bsd__
    password = uni_console_getpass("Please enter the password: ",true); // Show asterisks
    if(password==correct_password)
        std::cout <<"Correct password"<<std::endl;
    else
        std::cout <<"Incorrect password. Try again"<<std::endl;
#elif _WIN32
    password = win_console_getpass("Please enter the password: ",true); // Show asterisks
    if(password==correct_password)
        std::cout <<"Correct password"<<std::endl;
    else
        std::cout <<"Incorrect password. Try again"<<std::endl;
#else
  #error "Unknown platform"
  std::cout<<"Your platform did not support masking"<< std::endl;
#endif


}

void PasswordMasking :: echo_hide()
{
    const char *correct_password="null";
    std::string password;
#if defined __linux__ || defined __apple__ || defined __bsd__
    password = uni_console_getpass("Please enter the password: ", false); // Show asterisks
    if(password==correct_password)
        std::cout <<"Correct password"<<std::endl;
    else
        std::cout <<"Incorrect password. Try again"<<std::endl;
#elif _WIN32
    password = win_console_getpass("Please enter the password: ", false); // Show asterisks
    if(password==correct_password)
        std::cout <<"Correct password"<<std::endl;
    else
        std::cout <<"Incorrect password. Try again"<<std::endl;
#else
  #error "Unknown platform"
  std::cout<<"Your platform did not support masking"<< std::endl;
#endif

}

