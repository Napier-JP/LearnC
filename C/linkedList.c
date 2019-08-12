#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct schedule {
  int year;              /* 年 */
  int month;             /* 月 */
  int day;               /* 日 */
  int hour;              /* 時 */
  char title[100];       /* 表題 */
  struct schedule* next; /* 次の要素 */
};

/* リストに要素を追加する */
struct schedule* append(struct schedule* list,
                          int y, int m, int d, int h, char t[]) {
    /* 新しい要素を作成 */
    struct schedule* node = (struct schedule*)malloc(sizeof(struct schedule));
    node->year = y;
    node->month = m;
    node->day = d;
    node->hour = h;
    strcpy(node->title, t);

    /* 次の要素がないことを示すために NULL を代入 */
    node->next = NULL;

    if (list == NULL) {
        /* リストが空の場合は特別扱いする */
        return node;
    }
    else {
        /* リストの末尾の要素を探す */
        struct schedule* p = list;
        while (p->next != NULL) {
            p = p->next;
        }
        /* ここで変数 p は末尾の要素をさす */
        p->next = node;
        return list;
    }
}

int main() {
    struct schedule* list = NULL;
    list = append(list, 2009, 1, 1, 0, "元旦");
    list = append(list, 2009, 12, 24, 0, "Xmas");
    struct schedule real = *list;

    printf("%d/%d/%d %d:00 %s\n", list->year, list->month, list->day, list->hour, list->title);
    // 2009-1-1 元旦
    printf("%d/%d/%d %d:00 %s\n", list->next->year, list->next->month, list->next->day, list->next->hour, list->next->title);
    // 2009-12-24 Xmas
    printf("%d/%d/%d %d:00 %s\n", real.year, real.month, real.day, real.hour, real.title);
    // 2009-1-1 元旦

    list->year = 2020;

    printf("%d/%d/%d %d:00 %s\n", list->year, list->month, list->day, list->hour, list->title);
    // 2020-1-1 元旦
    printf("%d/%d/%d %d:00 %s\n", real.year, real.month, real.day, real.hour, real.title); // real is printed copy, not mirrored one
    // 2009-1-1 元旦
    return 0;
}
