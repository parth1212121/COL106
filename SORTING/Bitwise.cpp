#include<iostream>
using namespace std;

int main(){

    int x,y,z;
    x=0xF0;
    y=0x8D;
    z=x&y;
    printf("vallue of x is %d %X %o\n",x,x,x);
    printf("vallue of y is %d %X %o\n",y,y,y);
    printf("vallue of z is %d %X %o\n",z,z,z);
    z=(x>>2);
    printf("vallue of z is %d %X %o\n",z,z,z);
    z=(y<<1);

     printf("vallue of z is %d %X %o\n",z,z,z);

     z=(x>>2)|(y<<1);
     printf("vallue of z is %d %X %o\n",z,z,z);

    return 0;
}