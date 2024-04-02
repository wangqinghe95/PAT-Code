#include <cstdio>
#include <cstring>

const int maxn = 1100;

bool isPalindrome(const char* result) 
{
    int len = strlen(result);
    for(int i = 0; i < len/2; ++i) {
        if(result[i] != result[len-i-1]) {
            return false;
        }
    }
    return true;
}

int main()
{
    char str[maxn] = {0};
    scanf("%s", str);

    if(isPalindrome(str)) {
        printf("%s is a palindromic number.\n", str);
        return;
    }

    int cnt = 10;

    do
    {
        char str_reverse[maxn] = {0};
        int len = strlen(str);
        for(int i = 0; i < len; ++i) {
            str_reverse[i] = str[len-i-1];
        }

        char result[maxn] = {0};
        int carry = 0;
        for(int i = 0; i < len; ++i) {
            int temp = (str[len-i-1] - '0') + (str_reverse[len-i-1] - '0') + carry;
            carry = temp / 10;
            temp %= 10;
            result[i] = temp + '0'; 
        }

        if (carry > 0) {
            result[len++] = carry + '0';
        }

        printf("%s + %s = ", str, str_reverse);
        if(isPalindrome(result) == true) {
            printf("%s\n", result);
            printf("%s is a palindromic number.\n", result);
            break;
        }
        else {
            for(int i = 0; i < len; ++i) {
                str[i] = result[len-i-1];
            }
            printf("%s\n", str);
        }

    } while (--cnt > 0);
    
    if(0 == cnt) {
        printf("Not found in 10 iterations.\n");
    }
    
    return 0;
}
