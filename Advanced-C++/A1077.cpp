/*
notorious   臭名昭著的
题意：
一个人说话最后部分会被人认作为是个人特点去区分一个人。
给几个句子，来找出这几个句子最后部分是否有相同部分
如果有，找出并输出
没有输出 nai

解题思路：
将输入的字符串倒序存储在一个二维字符数组中
然后第一串字符的从头开始的各个字符，依次和下面字符比下去
如果有一个匹配不上，就可以中断退出
*/

#include<cstdio>
#include<cstring>

const int maxn = 300;   //the max length of sentence

int main()
{
    char s[100][maxn];   //
    int n;
    scanf("%d\n", &n);

    int minLen = maxn;

    for (int i = 0; i < n; i++)
    {
        fgets(s[i], maxn, stdin);
        int len = strlen(s[i]) - 1; 
        if (len < minLen)       //找出输入字符串中最长的值
        {
            minLen = len;
        }

        for (int j = 0; j < len / 2; j++)   //置反字符串，从字符串长度倒数第二个开始（最后一个是'\n'）
        {
            char tmp = s[i][j];
            s[i][j] = s[i][len - j - 1];
            s[i][len - j - 1] = tmp;
        }
    }

    int ans = 0;
    for (int i = 0; i < minLen; i++)
    {
        bool same = true;
        char c = s[0][i];       //取第一次字符串的各个元素
        for (int j = 1; j < n; j++)     //和其余的字符串相同位置比较
        {
            if (c != s[j][i])           //有一个不同就退出，并置false
            {
                same = false;
                break;
            }           
        }
        if (same)
        {
            ans++;
        }
        else
        {
            break;
        } 
    }

    if (ans)
    {
        for (int i = ans - 1; i >= 0; i--)
        {
            printf("%c", s[0][i]);
        }
    }
    else
    {
        printf("nai");
    }

    return 0;
    
}