/**
 * 第四个测试点没过
*/
#include <string>
#include <iostream>
#include <regex>

using namespace std;

bool getlegalDouble(const string& str)
{
    // regex pattern("^[+-]?\\d+(\\.\\d{1,2})?");
    regex pattern("^[-+]?([0-9][0-9]{0,2}(\\.\\d{1,2})?|1000(\\.0{1,2})?|0(\\.\\d{1,2})?)$");
    return regex_match(str, pattern);
}

int main()
{
    int n;
    scanf("%d%*c",&n);

    double result = 0.0;
    int count_legal = 0;
    while (n--)
    {
        // string str;
        // cin >> str;
        char str[50] = {0};
        scanf("%s", str);
        if(getlegalDouble(str) == true) {
            result += stod(str);
            count_legal++;
        }
        else {
            printf("ERROR: %s is not a legal number\n", str);
        }
    }

    if(count_legal > 1) {
        printf("The average of %d numbers is %.2f\n", count_legal, result/count_legal);
    }
    else if(count_legal == 1){
        printf("The average of 1 number is %.2f\n", result);
    }
    else if (count_legal == 0) {
        printf("The average of 0 numbers is Undefined\n");       
    }
    
    return 0;
}