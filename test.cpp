#include "array.h"
#include <Windows.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>

using namespace std;

int main ( )
{
    vurm::array<int> test ( 5U, { 1, 2, 3, 4, 5 } );
    test._print ( );
    printf ( "\n%d\n", test.size ( ) );
    system ( "pause" );
    return 0;
}