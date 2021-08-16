#include <iostream> //input-output operations
#include <vector>   //vectors
#include <stack>    //stacks
#include <string>   //stod (string to double) operations


void to_vector(const std::string orgData, std::vector<std::string> &divData)
{
    std::vector<std::string> result{};
    std::string signData{};
    
    
    for (int i = 0; i < orgData.size(); ++i)
    {
        if (!isdigit(orgData[i]))
        {
            if(!signData.empty())
                result.push_back(signData);

            signData = orgData[i];
            result.push_back(signData);
            signData.erase();
        }
        else
        {
            signData += orgData[i];
        }
    }

    if(!signData.empty())
        result.push_back(signData);

    divData = result;
}

int numChar(const char character)
{
    if (character == '+' || character == '-')
        return 1;
    else if (character == '*' || character == '/')
        return 2;
    else if (character == '^')
        return 3;
    else
        return 0;
}

void conventer(std::vector<std::string> &divData)
{
    std::stack <char> stos{};
    std::vector<std::string> Data{};


    for (int i = 0; i < divData.size(); ++i)
    {
        std::string trial{ divData[i] };

        if (!isdigit(trial.front()))
        {
            if (stos.empty())
            {
                stos.push(trial.front());
                continue;
            }
            
            int num1 = numChar(trial.front());
            int num2 = numChar(stos.top());

            if (trial.front() == '(')
            {
                stos.push(trial.front());
            }
            else if (trial.front() == ')')
            {
                while (stos.top() != '(')
                {
                    std::string trial2{ stos.top() };
                    Data.push_back(trial2);
                    stos.pop();
                }

                //remove '('
                stos.pop();
            }
            else if (num1 < num2)
            {
                while (num1 <= num2)
                {
                    std::string trial2{ stos.top() };
                    Data.push_back(trial2);
                    stos.pop();

                    if (stos.empty())
                        break;

                    num2 = numChar(stos.top());
                }

                //add to the stack new char
                stos.push(trial.front());
            }
            else if (num1 == num2)
            {
                //remove old
                std::string trial2{ stos.top() };
                Data.push_back(trial2);
                stos.pop();

                //add to the stack new char
                stos.push(trial.front());
            }
            else
            {
                stos.push(trial.front());
            }
        }
        else
        {
            Data.push_back(divData[i]);
        }
    }


    while (!stos.empty())
    {
        std::string trial2{ stos.top() };
        Data.push_back(trial2);
        stos.pop();
    }
        
    divData = Data;

    for (int i = 0; i < Data.size(); ++i)
    {
        std::cout << Data[i] << " ";
    }
    std::cout << std::endl;
}

double counter(std::vector<std::string> divData)
{
    std::stack<std::string> stos{};

    for (int i = 0; i < divData.size(); ++i)
    {
        std::string trial{ divData[i] };


        if (!isdigit(trial.back()))
        {
            double num1 = std::stod(stos.top());
            stos.pop();
            double num2 = std::stod(stos.top());
            stos.pop();

            std::swap(num1, num2);

            
            if (trial.front() == '+')
            {
                stos.push(std::to_string(num1 + num2));
            }
            else if (trial.front() == '-')
            {
                stos.push(std::to_string(num1 - num2));
            }
            else if (trial.front() == '*')
            {
                stos.push(std::to_string(num1 * num2));
            }
            else if (trial.front() == '/')
            {
                stos.push(std::to_string(num1 / float(num2)));
            }
            else if (trial.front() == '^')
            {
                stos.push(std::to_string(pow(num1, num2)));
            }
            else
                exit(-1);
        }
        else
        {
            stos.push(trial);
        }
    }
    
    
    double result = std::stod(stos.top());
    

    if (result == int(result))
        return int(result);
    else
        return result;
}

double instructions(const std::string orgData)
{
    std::vector<std::string> divData{};

    to_vector(orgData, divData);
    conventer(divData);

    return (counter(divData));
}


int main()
{
    std::string equation{};

    std::cout << "Give the equation: ";
    std::cin >> equation;

    std::cout << "The Result: " << instructions(equation) << std::endl;
}