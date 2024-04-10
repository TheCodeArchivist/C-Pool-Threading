#ifndef UnsintPrint
#define UnsintPrint
    void print_unsint(int num) {
        if (num > 9)
            print_unsint(num / 10);
        putchar('0' + (num % 10));
    }
#endif

#ifndef SintPrint
#define SintPrint
    void print_signedint(int num) {
        if (num < 0) {
            putchar('-');
            num = num*-1;
        }
        if (num > 9)
            print_signedint(num / 10);
        putchar('0' + (num % 10));
    }
#endif

#ifndef My_StrLen
#define My_StrLen
    int my_strlen(char* string) {
        int i=0;
        while (string[i] != '\0')
            i++;
        return i;
    }
#endif

#ifndef GetNumber
#define GetNumber
    int get_number(char* string)
    {
        int output = 0;
        int way = 0;
        if (string[0] == '-') way = 1;
        for (int i = 0; string[i] != '\0'; i++)
            if (string[i] >= '0' && string[i] <= '9')
                output = output * 10 + (string[i] - '0');
        if (way == 1) output = 0 - output;
        return output;
    }
#endif

#ifndef MyPow
#define MyPow
    int my_pow(int x, int n) {
        int num = x;
        int i = 0;
        for (i = 0; i < n; i++) {
            num = num * x;
        }
        return num;
    }
#endif

#ifndef GetFloat
#define GetFloat
    float get_float(char* string) {
        float output = 0;
        int under_zero = 0;
        int under_zero_len = 0;
        int way = 0;
        int float_mode = 0;
        if (string[0] == '-')
            way = 1;
        int i = 0;
        for (i = 0; string[i] != '\0'; i++) {
            if (string[i] == '.')
                float_mode = 1;
            if (float_mode == 0 && (string[i] >= '0' && string[i] <= '9'))
                output = output * 10 + (string[i] - '0');
            if (float_mode == 1 && (string[i] >= '0' && string[i] <= '9')) {
                under_zero = under_zero * 10 + (string[i] - '0');
                under_zero_len++;
            }
        }
        output = output + (float) under_zero / my_pow(10,under_zero_len - 1);
        if (way == 1) output = 0 - output;
        return output;
    }
#endif

#ifndef MyPrint
#define MyPrint
    int my_print(char* string, char endline) {
        for (int i = 0; string[i] != '\0'; i++) {
            if (string[i] == '\\') {
                i++;
                if (string[i] == 'n')
                    putchar('n');
            } else
                putchar(string[i]);
        }
        putchar(endline);
    }
#endif

#ifndef CheckArgs
#define CheckArgs
    void check_arguments(int argc, int min) {
        if (argc < min + 1) {
            my_print("ERROR! Not enough arguments (", 0);
            print_unsint(argc - 1);
            my_print(" provided - ", 0);
            print_unsint(min);
            my_print(" minimum needed)\n", 0);
            exit(1);
        }
        if (argc > min + 1) {
            my_print("ERROR! Too much arguments (", 0);
            print_unsint(argc - 1);
            my_print(" provided - ", 0);
            print_unsint(min);
            my_print(" maximum allowed)\n", 0);
            exit(1);
        }
    }
#endif