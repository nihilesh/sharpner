// Copyright (c) 2015 Arista Networks, Inc.  All rights reserved.
// Arista Networks, Inc. Confidential and Proprietary.

#include <sstream>
#include <iostream>
#include <stdint.h>
#include <inttypes.h>
#include <stdio.h>

using namespace std;

typedef struct arr_def {
   uint32_t array[4];
}bitmap;

string toStream( bitmap&  b );

int main() {
   bitmap b;
   b.array[0] = 0x1234;
   b.array[1] = 0x1234;
   b.array[2] = 0x1234;
   b.array[3] = 0x1234;
   cout << toStream( b ) << endl;
}

string toStream( bitmap&  b ) {
   stringstream ss;
   ss << hex << b.array[3] << b.array[2] << b.array[1] << b.array[0];
   return ss.str();
}

