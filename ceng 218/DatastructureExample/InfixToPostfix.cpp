#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    stack <char> datas;

    string sentence;
    cin >> sentence;

    int size = sentence.size();

    stack <char> operands;
    int sizeDatas = 0;

    int leftNumber = -1;
    int rightNumber = -1;

    for(int i = 0; i < size; i++)
    {
        if(sentence[i] != '+' && sentence[i] != '*')
        {
            datas.push(sentence[i]);
            sizeDatas++;
        }

        else
        {
            char operand = sentence[i];

            if(leftNumber == -1)
            {
                char temp1 = datas.top();
                char temp2 = datas.top();
                datas.pop();
                datas.pop();

                leftNumber = temp1 - '0';
                rightNumber = temp2 - '0';            
            }

            else
            {
                char temp = datas.top();
                datas.pop();
                rightNumber = temp - '0';
            }

            if(operand == '+')
            {
                leftNumber = leftNumber + rightNumber;
                char leftNumberChar = leftNumber + '0';
                datas.push(leftNumberChar);
            }

            else if(operand == '*')
            {
                leftNumber = leftNumber * rightNumber;
                char leftNumberChar = leftNumber + '0';
                datas.push(leftNumberChar);
            }
        }
    }

    while(!datas.empty())
    {
        cout << datas.top();
    }





}