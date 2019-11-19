//
//  main.c
//  战斗模拟器
//
//  Created by f on 2019/7/13.
//  Copyright © 2019 F's Studio. All rights reserved.
//
#include <assert.h> /* assert() */
#include <ctype.h> /* islower(), toupper() */
#include <stdio.h> /* printf(), scanf() */
#include <stdlib.h> /* rand(), EXIT_SUCCESS */
#include <time.h> /* clock_t, clock() */
#include <string.h>
#include "header.h"


int main(int argc, const char * argv[]) {
    srand((unsigned)time(NULL));
    
    current_time();
    illustration();
    fight();
    
    return 0;

}
