#include <iostream>
#include "about.h"

using namespace std;

void print_footer();

int main(int argc, char *argv[])
{
    print_footer();
    return 0;
}

void print_footer()
{
    cout << endl
         << app_footer << endl;
}
