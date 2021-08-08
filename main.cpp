#include <iostream>
#include <stack>
#include <string>
#include <cstring>
#include <set>

/* void plus_and_minus(stack& stosLiczb, const char* lel)
{
    char a = stosLiczb.top();
    cout << a << " ";
    stosLiczb.pop();
    stosLiczb.push(x[i]);
} */

int main()
{
    std::string inputBuffer;
    std::string sym;
    std::cout << "Program Odwortna Notacja Polska" << std::endl;
    std::cout << "Wpisz dzialanie do przekonwertowania na ONP: ";
    std::cin >> inputBuffer;
    std::stack <int> stosLiczb;
    std::cout << "Wprowadziles " << inputBuffer.size() << " znakow!" << std::endl;

    /* std::set <char> signs = {+, -, *, /, ^, (, )}; */

    for(int i=0; i<=inputBuffer.size(); i++)
    {
        if(inputBuffer[i]=='+'||inputBuffer[i]=='-'||inputBuffer[i]=='*'||inputBuffer[i]=='/'||
           inputBuffer[i]=='^'||inputBuffer[i]=='('||inputBuffer[i]==')')
        {
            std::cout << " ";
            if(stosLiczb.empty()==true)
            {
                stosLiczb.push(inputBuffer[i]);
            }
            else if(stosLiczb.top()=='^')
            {
                char a = stosLiczb.top();
                std::cout << a << " ";
                stosLiczb.pop();
                if(stosLiczb.top()=='*'||stosLiczb.top()=='/')
                {
                    char a = stosLiczb.top();
                    std::cout << a << " ";
                    stosLiczb.pop();
                    stosLiczb.push(inputBuffer[i]);
                }
                else
                {
                    stosLiczb.push(inputBuffer[i]);
                }
            }
            else if(inputBuffer[i]=='('||inputBuffer[i]==')')
            {
                std::cout << '\b';
                stosLiczb.push(inputBuffer[i]);
            }
            else if((inputBuffer[i]=='+'||inputBuffer[i]=='-')&&(stosLiczb.top()=='*'||stosLiczb.top()=='/'))
            {
                char a = stosLiczb.top();
                std::cout << a << " ";
                stosLiczb.pop();
                if((inputBuffer[i]=='+'||inputBuffer[i]=='-')&&(stosLiczb.top()=='+'||stosLiczb.top()=='-'))
                {
                    char a = stosLiczb.top();
                    std::cout << a << " ";
                    stosLiczb.pop();
                    stosLiczb.push(inputBuffer[i]);
                }
                else
                {
                    std::cout << inputBuffer[i] << " ";
                }
            }
            else if((inputBuffer[i]=='+'||inputBuffer[i]=='-')&&(stosLiczb.top()=='+'||stosLiczb.top()=='-'))
            {
                char a = stosLiczb.top();
                std::cout << a << " ";
                stosLiczb.pop();
                stosLiczb.push(inputBuffer[i]);
            }
            else if((inputBuffer[i]=='*'||inputBuffer[i]=='/')&&(stosLiczb.top()=='*'||stosLiczb.top()=='/'))
            {
                char a = stosLiczb.top();
                std::cout << a << " ";
                stosLiczb.pop();
                stosLiczb.push(inputBuffer[i]);
            }
            else
            {
                stosLiczb.push(inputBuffer[i]);
            }

        }
        else if(isdigit(inputBuffer[i]))
                {
                    std::cout << inputBuffer[i];
                }
    }
    std::cout << " ";
    while(stosLiczb.empty()==false)
    {
        char a = stosLiczb.top();
        if(a=='('||a==')')
        {
            stosLiczb.pop();
        }
        else
        {
            std::cout << a << " ";
            stosLiczb.pop();
        }
    }
    std::cout << std::endl;

    return 0;
}
