#include <stdio.h>
#include <string.h>

struct schedule {
    int year;
    int month;
    int day;
    int hour;
    char title[100];
};

/* スケジュールの年を強制的に2年進める */
void update2years(struct schedule* target) {
    target->year = target->year + 2;
}

void printSchedule(struct schedule* data) {
    printf("year:%04d, month:%02d day:%02d hour:%02d title:%s\n",
           data->year, data->month, data->day, data->hour, data->title);
}

int main() {
    struct schedule exam;

    exam.year  = 2006;
    exam.month = 10;
    exam.day   = 30;
    exam.hour  = 10;
    strcpy(exam.title, "ハロウィン");

    printSchedule(&exam);

    update2years(&exam);

    printSchedule(&exam);

    return 0;
}
