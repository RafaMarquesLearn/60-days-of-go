#include <stdio.h>
// import header generated by Go
#include "awesome.h"

int main(int argc, char *argv[])
{
    printf("Using awesome lib from C: \n");

    // Call add() - passing integers params, integer result
    // Yes, we have to use go types, because behind the scene, they are long long int
    GoInt a = 12;
    GoInt b = 99;
    printf("awesome.add(12,99) = %lu\n", add(a,b));

    // Call cosine() - passing GoFloat64(double) param- GoFloat64(double) returned
    // GoFloat64 - double
    printf("awesome.cosine(1) = %.1f\n", cosine(1.0));

    // Call Sort() - passing an array pointer
    // Create a go slice, implemented in C
    GoInt data[6] = {77, 12, 5, 99, 28, 23};
    // GoSlice {data, len, cap}
    GoSlice nums = {data, 6, 6};
    sortints(nums);
    printf("awesome.sortints(77,12,5,99,28,23): ");
    for (int i = 0; i < 6; ++i) {
        // each element in nums.data is a pointer to Goint but cast is necessary
        // then we catch the value to sort
        printf("%lu,",*((GoInt *)nums.data + i));
    }
    printf("\n");

    // Call logmsg() - passing string value
    // GoString {string, len}
    // len without \0
    GoString msg = {"Hello from C!", 13};
    logmsg(msg);

    return 0;
}
