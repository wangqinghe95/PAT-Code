/**
 * +1.00E+3     1000
 * -1.00E+3     -1000
 * 
 * +1.24E+3     1240
 * +1.24E-3     0.00124
 * 
 * -1.24E+3     -1240
 * -1.24E-3     -0.00124
 * 
 * +0.1E-2      0.001 
 * 
 * 因为用了fgets，他会把数据最后的'\n'也给存储进来，所有需要-1
 * */
#include<cstdio>
#include<cstring>

const int maxn = 20;

int main()
{
    char str[maxn] = {0};
    fgets(str, maxn, stdin);
    //gets(str);

    int pos = 0;
    int len = strlen(str);

    if (str[0] == '-')
    {
        printf("-");
    }
    
    while(str[pos] != 'E')
    {
        pos++;
    }

    int exp = 0;
    for (int i = pos+2; i < len; i++)
    {
        exp = exp * 10 + (str[i] - '0');
    }

    if (0 == exp)
    {
        for (int i = 1; i < pos; i++)
        {
            printf("%c", str[i]);
        }
        return 0;
    }

    if (str[pos+1] == '-')
    {
        printf("0.");
        for (int i = 0; i < exp - 1; i++)
        {
            printf("0");
        }
        for(int i = 1; i < pos; i++)
        {
            if (str[i] == '.')
            {
                continue;
            }
            printf("%c", str[i]);
        }
    }
    else
    {
        for (int i = 1; i < pos; i++)
        {
            if(str[i] == '.')
            {
                continue;
            }
            printf("%c", str[i]);
            if(i == exp + 2 && exp != pos - 3)  //exp+2表示数组下标走到了'E'处
            {
                printf(".");
            }
        }
        for (int i = 0; i < exp - (pos - 3); i++)
        {
            printf("0");
        }
    }

    return 0;
    
}
 