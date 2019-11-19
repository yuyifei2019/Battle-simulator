//
//  characters.c
//  战斗模拟器
//
//  Created by f on 2019/8/5.
//  Copyright © 2019 F's Studio. All rights reserved.
//

#include <assert.h> /* assert() */
#include <ctype.h> /* islower(), toupper() */
#include <stdio.h> /* printf(), scanf() */
#include <stdlib.h> /* rand(), EXIT_SUCCESS */
#include <time.h> /* clock_t, clock() */
#include <string.h>
#include "header.h"

long int month_day(long int year, long int yearday, long int* month, long int* day) {
    int i;
    int leap_year[13] = {0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366};
    int ord_year[13] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
    
    if (year < 0 || yearday < 0 || yearday > 366) {
        printf("Wrong date\n");
        exit(1);
    }
    
    if (year % 4 == 0 && !(year % 100 == 0 && year % 400 != 0)) {
        if (yearday > 366) {
            printf("Wrong date\n");
            exit(1);
        }
        for (i = 0; i < 13; i++){
            if (yearday > leap_year[i] && yearday <= leap_year[i+1]) {
                *month = i + 1;
                *day = yearday - leap_year[i];
            }
        }
    }
    else {
        if (yearday > 365) {
            printf("Wrong date\n");
            exit(1);
        }
        for (i = 0; i < 13; i++){
            if (yearday > ord_year[i] && yearday <= ord_year[i+1]) {
                *month = i + 1;
                *day = yearday - ord_year[i];
            }
        }
    }
    
    return 1;
}

void current_time(void) {
    long int four_year = 365*4 + 1, n_four_year = 0, year = 0, month = 0, day = 0, hour = 0, minute = 0, second = 0, t = 0;
    
    t = time(0);
    
    second = t % 60;
    t = t / 60;//rest total minutes
    
    minute = t % 60;
    t = t / 60;//rest total minutes
    
    hour = t % 24 + 8;//GMT+8:00
    day = t / 24;//rest total days
    
    n_four_year = day / four_year;
    day = day % four_year + 1;//attention!!! attention!!! add one day
    
    if (day >= 0 && day < 365) {
        //printf("1 %ld %ld\n", year, day);
        year = 1970 + 4 * n_four_year;
        month_day(year, day, &month, &day);
    }
    else if (day >= 365 && day < 2 * 365) {
        day = day - 365;
        //printf("2 %ld %ld\n", year, day);
        year = 1970 + 4 * n_four_year + 1;
        month_day(year, day, &month, &day);
    }
    else if (day >= 2 * 365 && day < 3 * 365 + 1) {//leap year
        day = (t - 365*2);
        //printf("3 %ld %ld\n", year, day);
        year = 1970 + 4 * n_four_year + 2;
        month_day(year, day, &month, &day);
    }
    printf("%02ld/%02ld/%04ld\n", month, day, year);
    printf("%02ld:%02ld:%02ld\n", hour, minute, second);
    
}


int possibility(int percentage) {
    int dice;
    dice = rand()%100+1;
    if (dice<=percentage) {
        return 1;
    }
    else {
        return 0;
    }
}

void AaddB(char* A, char* B) {
    char *a = A;
    char *b = B;
    
    while(*a)   // till it doesn't point to NULL-till string is not empty
    {
        a++;    // point to the next letter of the string
    }
    while(*b)   // till second string is not empty
    {
        
        //printf("a %p b %p    %d      @a%c\n", a, b, i, *a);
        *a = *b;
        b++;
        a++;
    }
    *a = '\0';
}
