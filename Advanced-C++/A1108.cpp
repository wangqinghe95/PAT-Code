#include <string>
#include <iostream>
#include <regex>

using namespace std;

/**
 * 使用正则表达式来判断浮点数的字符串是否合法：[-1000,1000],两位小数
 * 第四个测试点未过
*/
namespace Solution_Regex
{
    bool getlegalDouble(const string& str)
    {
        // regex pattern("^[+-]?\\d+(\\.\\d{1,2})?");
        regex pattern("^[-+]?([0-9][0-9]{0,2}(\\.\\d{1,2})?|1000(\\.0{1,2})?|0(\\.\\d{1,2})?)$");
        return regex_match(str, pattern);
    }
    void Solution()
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
    }
}


/**
 * 巧用 sscanf 和 sprintf 函数将一个字符串的浮点数另存储到 double 类型中
 * sscanf() 从一个字符串中读取格式化数据
 *  int sscanf(const char *str, const char *format, ...);
 *      [in] str: C 字符串，读取的数据源
 *      [in] format: 读取数据时的格式
 *      [in] ... : 数据保存的目的地，和格式对应的数据地址
 * sprintf() 将格式化的输出存储到字符串中
 *  int sprintf(char *str, const char *format, ...);
 *      [in] str: 保存数据的字符串
 *      [in] format: 保存数据的格式
 *      [in] ... : 数据来源，和保存的数据格式对应
*/
namespace Solution_Sscanf
{
    void Solution()
    {
        int n;
        scanf("%d%*c", &n);
        double sum = 0.0;
        int cnt = 0;

        while (n--)
        {
            char str1[64], str2[64];
            double temp = 0.0;
            scanf("%s", str1);
            sscanf(str1, "%lf", &temp);
            sprintf(str2, "%.2f", temp);

            bool flag = true;
            for(int i = 0; i < strlen(str1); ++i) {
                if(str1[i] != str2[i]) {
                    flag = false;
                    break;
                }
            }

            if(flag && temp <= 1000 && temp >= -1000) {
                sum += temp;
                cnt++;
            }
            else {
                printf("ERROR: %s is not a legal number\n", str1);                
            }
        }

        if(cnt == 0) {
            printf("The average of 0 numbers is Undefined\n");       
        }
        else if (cnt == 1) {
            printf("The average of 1 number is %.2f\n", sum);
        }
        else {
            printf("The average of %d numbers is %.2f\n", cnt, sum/cnt);
        } 
    }
}

/**
 * 一个 [-1000,1000] 且有效小数位为 2 位的浮点数有哪些状态
 * 开始状态，数字开始状态，小数点状态，小数点前状态，小数点后状态，错误状态
 * 
 * 第四个测试点依旧没过
*/
namespace Solution_StateMachine
{
    enum class ParserState
    {
        Begin = 0,
        Char_Number_Begin,
        Char_Number_Point,
        Number_Before_Point,
        Number_After_Point,
        End,

        Error
    };

    bool getFloatValid(const string& str)
    {
        ParserState state = ParserState::Begin;

        auto now = str.begin();
        int count_decimal = 0;
        while (state != ParserState::Error && now != str.end())
        {
            char ch_now = *now;
            auto next = now++;

            switch (state)
            {
            case ParserState::Begin:
            {
                if(ch_now == '-') {
                    state = ParserState::Char_Number_Begin;
                }
                else if(ch_now >= '0' && ch_now <= '9') {
                    state = ParserState::Char_Number_Begin;
                    now--;
                }
                else {
                    state = ParserState::Error;
                }
                break;
            }
            case ParserState::Char_Number_Begin:
            {
                if(ch_now == '0') {
                    state = ParserState::Char_Number_Point;
                }
                else if(ch_now >= '1' && ch_now <= '9'){
                    state = ParserState::Number_Before_Point;
                }
                else {
                    state = ParserState::Error;
                }
                break;
            }
            case ParserState::Char_Number_Point:
            {
                if(ch_now == '.') {
                    state = ParserState::Number_After_Point;
                    count_decimal = 0;
                }
                else {
                    state = ParserState::Error;
                }
                break;
            }
            case ParserState::Number_Before_Point:
            {
                if(ch_now >= '0' && ch_now <= '9') {
                    // valid and nothing to do
                }
                else if(ch_now == '.'){
                    state = ParserState::Char_Number_Point;
                    now--;
                }
                else {
                    state = ParserState::Error;
                }
                break;
            }
            case ParserState::Number_After_Point:
            {
                if(ch_now >= '0' && ch_now <= '9') {
                    count_decimal++;
                    if(count_decimal > 2) {
                        state = ParserState::Error;
                    }
                }
                else {
                    state = ParserState::Error;
                }
                break;
            }
            default:
                break;
            }
        }
        
        /*测试点 3 也过不去*/
        /*
        if(state != ParserState::Number_After_Point && state != ParserState::Number_Before_Point) {
            return false;
        }
        */

        if(state == ParserState::Error) {
            return false;
        }

        return true;
    }

    void Solution()
    {
        int n;
        scanf("%d%*c", &n);
        double sum = 0.0;
        int cnt = 0;

        while (n--)
        {
            char str[50] = {0};
            scanf("%s", str);
            if(getFloatValid(str) == false) {
                printf("ERROR: %s is not a legal number\n", str);
                continue;
            }
            
            double x = stod(str);
            if(x >= 1000 || x <= -1000) {
                printf("ERROR: %s is not a legal number\n", str);
                continue;
            }

            sum += x;
            cnt++;
        }

        if(cnt == 0) {
            printf("The average of 0 numbers is Undefined\n");       
        }
        else if (cnt == 1) {
            printf("The average of 1 number is %.2f\n", sum);
        }
        else {
            printf("The average of %d numbers is %.2f\n", cnt, sum/cnt);
        }        
    }
}

int main()
{
    // Solution_Regex::Solution();
    // Solution_Sscanf::Solution();
    Solution_StateMachine::Solution();
    return 0;
}