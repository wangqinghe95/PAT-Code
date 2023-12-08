#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 82;

int main()
{
    char original_str[MAXN] = {0};
    char typed_out_str[MAXN] = {0};

    fgets(original_str, MAXN, stdin);
    fgets(typed_out_str, MAXN, stdin);

    int len_origin = strlen(original_str);
    int len_typeout = strlen(typed_out_str);

    int hash[40] = {0};
    for(int i = 0; i < len_typeout; ++i) {
        char ch = typed_out_str[i];
        if(ch >= '0' && ch <= '9') {
            hash[ch - '0'] = 1;
        }
        else if (ch >= 'a' && ch <= 'z') {
            hash[ch - 'a' + 10] = 1;
        }
        else if (ch >= 'A' && ch <= 'Z'){
            hash[ch - 'A' + 10] = 1;
        }
        else if(ch == '_'){
            hash[39] = 1;
        }
        else {

        }
    }

    for(int i = 0; i < len_origin; ++i) {
        char ch = original_str[i];
        if(ch >= '0' && ch <= '9') {
            if(hash[ch - '0'] != 1){
                printf("%c",ch);
                hash[ch - '0'] = 1;
            }
        }
        else if (ch >= 'a' && ch <= 'z') {
            if(hash[ch - 'a' + 10] != 1){
                printf("%c", ch-'a'+'A');
                hash[ch - 'a' + 10] = 1;
            }
        }
        else if (ch >= 'A' && ch <= 'Z'){
            if(hash[ch - 'A' + 10] != 1){
                printf("%c",ch);
                hash[ch - 'A' + 10] = 1;
            }
        }
        else if(ch == '_'){
            if(hash[39] != 1) {
                printf("%c", ch);
                hash[39] = 1;
            }
        }
        else {

        }
    }


}