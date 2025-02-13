#include <iostream>

#include "../include/print.h"

using namespace std;

int main()
{
    vector<string> msg;
    msg.push_back("Hello"); msg.push_back("World");
    printMessage(msg);
}