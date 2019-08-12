#include <stdio.h>
#include <string.h>

struct schedule {
    int year;
    int month;
    int day;
    int hour;
    char title[100];
};

int main() {
    struct schedule schedules[3];

    struct schedule guidance = {2008, 4, 11, 10, "講義ガイダンス"};
    schedules[0] = guidance;

    schedules[1].year  = 2008;
    schedules[1].month = 7;
    schedules[1].day   = 14;
    schedules[1].hour  = 15;
    strcpy(schedules[1].title, "ゼミ"); //文字列はchar型の配列なので一文字ずつ代入するのは手間


    for (int i = 0; i < 2; i = i + 1)
    {
        printf("%04d/%02d/%02d %02d:00 %s\n",
               schedules[i].year, schedules[i].month, schedules[i].day, schedules[i].hour,
               schedules[i].title);
    }
    return 0;
}
