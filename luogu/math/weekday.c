/* C | math: weekday. */
const char* weekday(int year,int month, int day) {
    const char *weekdays[] = {"Sunday", 
        "Monday", "Tuesday", "Wednesday", 
        "Thursday", "Friday", "Saturday", };
    static int m[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    m[1] = leap(year)? 29 : 28;
    int sum_days = day;
    for (int i=0,*p=m;i<month-1;i++) 
        sum_days += *(p++);
//    printf("%d\n",sum_days);
    for (int i=1;i<year;i++)
        sum_days += leap(i)? 366 : 365;
//    printf("%d\n",sum_days);    
    return weekdays[sum_days % 7];
}
//leap 是判断闰年函数 
