#include<stdio.h>
#include<stdarg.h>
#include<limits.h>

int min(int count, ...){
    int min = INT_MAX;
    va_list args;
    va_start(args, count);
    int a;
    for (int i = 0; i < count; i++)
    {
        a = va_arg(args,int);
        if (a <= min) min = a;
    }
    
    va_end(args);
    return min;
}

int main()
{
    int x1, y1, x2, y2, x, y;
    if (scanf("(%d,%d) (%d,%d) (%d,%d)", &x1, &y1, &x2, &y2, &x, &y)!=6) return 1;
    int dist1 = x-x1;
    int dist2 = x2-x;
    int dist3 = y-y1;
    int dist4 = y2-y;
    if((x>x1 && x<x2) && (y>y1 && y<y2)) {
        printf("INSIDE %d\n", min(4, dist1, dist2, dist3, dist4));
    }
    else if(((x==x1||x==x2) && y>=y1 && y<=y2) || ((y==y1||y==y2) && x>=x1 && x<=x2)){
        printf("BOUNDARY 0\n");
    }
    else{
        int a,b;
        if(x < x1) a = -dist1;
        else if(x > x2) a = -dist2;
        else a = 0;
        
        if(y<y1) b = -dist3;
        else if(y>y2) b = -dist4;
        else b = 0;
        
        printf("OUTSIDE %d\n", a + b);
    }
    
    
    return 0;
}