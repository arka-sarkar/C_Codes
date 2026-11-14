#include<stdarg.h>
#include<unistd.h>

static int str_len(const char *s) {
    int length = 0;
    for(;*s;s++, length++);
    return length;
}

static void put_char(char c) {
    write(1, &c, 1);
}

static void put_str(const char *s) {
    if(!s) s = "(null)";

    write(1, s, str_len(s));
}

static void put_int(int n) {
    char buf[12];
    int i=11;
    unsigned int u = (n<0)?-(unsigned)n:n;
    buf[i] = '\0';
    if(u==0) buf[--i]='0';
    while(u) {
        buf[--i] = (u%10)+'0';
        u/=10;
    }
    if(n<0) buf[--i]='-';
    write(1, buf+i, 11-i);
}

static void put_uint(unsigned long long u) {
    char buf[21];
    int i = 20;
    buf[i] = '\0';
    if (u == 0) buf[--i] = '0';
    while (u) { buf[--i] = '0' + u % 10; u /= 10; }
    write(1, buf + i, 20 - i);
}

static void put_double(double d) {
    if(d != d) { put_str("nan"); return; }
    if(d < 0) { put_char('-'); d=-d; }
    if(d > 1e13) { put_str("inf"); return; }

    unsigned long long scaled = (unsigned long long)(d*1000000.0 + 0.5);
    unsigned long long ip = scaled/1000000;
    unsigned long long fp = scaled%1000000;

    put_uint(ip);
    put_char('.');

    for (unsigned long long div = 100000; div > 0; div /= 10) put_char('0' + (fp / div) % 10);
}

void minprintf(const char* fmt, ...) {
    va_list ap;
    const char *p;
    const char *sval;
    int ival;
    double dval;

    va_start(ap, fmt);

    for(p=fmt; *p; p++) {
        if(*p != '%') {
            put_char(*p);
            continue;
        }
        // If the character is '%'
        p++;
        switch(*p) {
            case 'd':
                ival = va_arg(ap, int);
                put_int(ival);
                break;
            
            case 'f':
                dval = va_arg(ap, double);
                put_double(dval);
                break;
            
            case 's':
                sval = va_arg(ap, const char*);
                if(sval != NULL) put_str(sval);
                break;
            
            case '%':
                put_char('%');
                break;
            
            default:
                put_char('%');
                put_char(*p);
                break;
        }
    }
    va_end(ap);
}

int main() {
    int n=38787;
    double a=3.4;
    const char *s = "C++";
    put_str("Int: %d, Double: %f, String: %s, Percent: %%, Invalid escape character: %g\n");
    minprintf("Int: %d, Double: %f, String: %s, Percent: %%, Invalid escape character: %g\n", n, a, s);
    return 0;
}