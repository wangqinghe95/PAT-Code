/**/
#include<cstdio>
const long long G = 29 * 17;
const long long S = 29;

int main()
{
    long long Sickle = 0;
    long long Galleon = 0;
    long long Kunts = 0;

    long long tempSick, tempGall, tempKun;
    scanf("%ld.%ld.%ld", &Galleon, &Sickle, &Kunts);
    scanf("%ld.%ld.%ld", &tempGall, &tempSick, &tempKun);

    long long sum = (tempGall + Galleon) * G + (tempSick + Sickle) * S + Kunts + tempKun;
    printf("%d.%d.%d", sum/G, sum%G/S, sum%S);
    return 0;
}