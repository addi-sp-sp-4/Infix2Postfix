//
// Created by david on 13-5-17.
//

#include "infix2postfix.h"
#include <iostream>
#include <stack>
#include <map>

Infix2Postfix::Infix2Postfix()
{

}

std::string Infix2Postfix::evaluate(std::string infix)
{
    std::string postfix;
    std::stack<char> operators;
    std::map<char, int> precedence;

    precedence['*'] = 2;
    precedence['/'] = 2;
    precedence['-'] = 1;
    precedence['+'] = 1;


    for(unsigned i = 0; i < infix.length(); i++)
    {
        char current_char = infix[i];

        if(isdigit(current_char) && current_char != '-' && current_char != '+')
        {
            postfix += current_char;
        }
        else if(operators.empty())
        {
            operators.push(current_char);
        }
        else if(precedence[operators.top()] < precedence[current_char])
        {
            operators.push(current_char);
        }
        else
        {

            while(true)
            {
                if(precedence[operators.top()] >= precedence[current_char])
                {
                    postfix += operators.top();
                    operators.pop();
                    if(operators.empty())
                    {
                        operators.push(current_char);
                        break;
                    }
                }
                else
                {
                    operators.push(current_char);
                    break;
                }
            }
        }


    }

    while(!operators.empty())
    {
        postfix += operators.top();
        operators.pop();
    }
    return postfix;
}

void Infix2Postfix::example()
{
    std::array<std::string, 5> infixes = {"5+6", "5*6-3", "9+4*7/6", "4-5-6-7", "4*6*4*0*9"};

    for(unsigned i = 0; i < infixes.size(); i++)
    {
        std::cout << infixes[i] << " : " << evaluate(infixes[i]) << std::endl;
    }
}