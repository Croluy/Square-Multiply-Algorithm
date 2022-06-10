#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define BIN_LEN 50  //binary array length - can store numbers as high as 2.251.799.813.685.246 (sum 2^n ; n 1 to 50)
int l=0; //final length of binary array

/** Convert decimal base number to binary base
 * @param n integer decimal number
 * @return binary number
 */
int *dec_to_bin(int n);

/** Convert the binary array into an integer
 * @param bin binary array
 * @return integer number
 */
int arr_to_int(int *bin);

int main(){
    //get base number
    int n=0;
    printf("Enter a number: ");
    scanf("%d",&n);

    //get exponent number
    int e=0;
    printf("Enter exponent: ");
    scanf("%d",&e);

    //get modulus number
    int m=0;
    printf("Enter modulus: ");
    scanf("%d",&m);

    //communicate choices to user
    printf("\n%d ^ %d mod %d\n",n,e,m);


    //Step 1: find the binary representation of e
    int *p=dec_to_bin(e);
    int e_bin=arr_to_int(p);

    printf("\n%d(10) is %d(2)\nBin Len = %d\n\n",e,e_bin,l);

    //Step 2: find the way to calculate 2nd number of e_bin
    //if 0 then square 'x'
    //if 1 then square 'x' AND multiply by n
    int x=n;            //base number that will change every step
    int k=0;            //multiplication result from which to get the modulus
    int current_bin;    //current binary number to being calculated

    for(current_bin=1; current_bin<l; current_bin++){
        //If the current check number is 0, then SQUARE
        if(*(p+current_bin)==0){
            k=x*x;
            x=k%m;
        }
        if(*(p+current_bin)==1){
            k=x*x;
            x=k%m;

            k=x*n;
            x=k%m;
        }
        printf("x:%d\n",x);
    }

    printf("%d ^ %d mod %d = %d\n",n,e,m,x);

    return 0;
}

int arr_to_int(int *bin){
    int n=0;
    for (int i=0; i<l; i++)
        n+=bin[i]*pow(10,i);
    return n;
}

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