#include<cstdio>
#include<cstring>
const int maxn = 100;

char week[10][5] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

int main()
{
    char str1[maxn] = {0}; 
    char str2[maxn] = {0};
    char str3[maxn] = {0};
    char str4[maxn] = {0};

    fgets(str1, maxn, stdin);
    fgets(str2, maxn, stdin);
    fgets(str3, maxn, stdin);
    fgets(str4, maxn, stdin);

    int i = 0;
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int len3 = strlen(str3);
    int len4 = strlen(str4);
    for (; i < len1 && i < len2; i++)
    {
        if (str1[i] == str2[i] && str1[i] >= 'A' && str1[i] <= 'G')
        {
            printf("%s ", week[str1[i] - 'A']);
            break;
        }
    }

    for(i = i + 1; i < len1 && i < len2 ; i++)
    {
        if (str1[i] == str2[i])
        {
            if (str1[i] >= '0' &&str1[i] <= '9')
            {
                printf("%02d:", str1[i] - '0');
                break;
            }
            else if (str1[i] >= 'A' && str1[i] <= 'N')
            {
                printf("%d:", str1[i] - 'A' + 10);
                break;
            }
            
        }
    }

    for (i = 0; i < len3 && i < len4; i++)
    {
        if (str3[i] == str4[i])
        {
            if (( str3[i] >= 'a' && str3[i] <= 'z') ||  (str3[i] >= 'A' && str3[i] <= 'Z'))
            {
                printf("%02d", i);
                break;
            }
        }
    }

    return 0;
}