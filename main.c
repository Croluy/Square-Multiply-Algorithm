#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define BIN_LEN 50  //binary array length - can store numbers as high as 2.251.799.813.685.246 (sum 2^n)
int l=0; //final length of binary array

/** Convert decimal base number to binary base
 * @param n integer decimal number
 * @return binary number
 */
int *dec_to_bin(int n){
    int r;
    static int bin[BIN_LEN];
    for (int i=0; n>0; i++,l++){
        r=n%2;
        bin[i]=r;
        n/=2;
    }
    return bin;
}

/** Convert the binary array into an integer
 * @param bin binary array
 * @return integer number
 */
int arr_to_int(int *bin){
    int n=0;
    for (int i=0; i<l; i++)
        n+=bin[i]*pow(10,i);
    return n;
}

int main(){
    int *p=dec_to_bin(2);
    int t=arr_to_int(p);
    printf("Decimal number 5 is %d in binary", t);
    return 0;
}