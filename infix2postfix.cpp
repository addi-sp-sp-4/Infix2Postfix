//
// Created by david on 13-5-17.
//

#include "infix2postfix.h"

#include <iostream>
#include <string>
#include <stack>
#include <map>


Infix2Postfix::Infix2Postfix(std::string infix)
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
    result = postfix;
}
