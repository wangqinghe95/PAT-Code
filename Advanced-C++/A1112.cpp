#include <iostream>
#include <cstring>

const int maxn = 1110;

int hashtable[130] = {0};

int main()
{
    int k;
    scanf("%d%*c", &k);

    char str[maxn] = {0};
    scanf("%s", str);

    int len = strlen(str);
    int index = 0;
    while (index < len)
    {
        int cnt = 1;
        char c = str[index++];
        while (index < len && str[index] == c)
        {
            cnt++;
            index++;
        }

        if(cnt % k != 0) { // broken key
            hashtable[c] = 1;
        }
    }
    
    index = 0;
    for(int i = 0; i < len; ++i) {
        if(hashtable[str[i]] == 0) {
            printf("%c", str[i]);
            hashtable[str[i]] = -1;
        }
    }

    printf("\n");
    while (index < len)
    {
        printf("%c", str[index]);
        if(hashtable[str[index]] == -1) {
            index+=k;
        }
        else {
            index++;
        }
    }

    printf("\n");
    
    return 0;
}