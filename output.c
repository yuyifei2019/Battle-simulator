//
//  output.c
//  战斗模拟器
//
//  Created by f on 2019/8/9.
//  Copyright © 2019 F's Studio. All rights reserved.
//

#include <assert.h> /* assert() */
#include <ctype.h> /* islower(), toupper() */
#include <stdio.h> /* printf(), scanf() */
#include <stdlib.h> /* rand(), EXIT_SUCCESS */
#include <time.h> /* clock_t, clock() */
#include <string.h>
#include "header.h"

void output_result(char* report) {
    FILE* fout=NULL;
    char file_name[30];
    int length = 0;
    
    while(report[length] != '\0'){
        length++;
    }
    
    sscanf(report, "%s", file_name);
    strcat(file_name, ".txt");
    fout = fopen(file_name, "a");
    //printf("%s\n",final_report);
    
    fwrite(report, 1, length + 1 , fout);
    //fprintf(fout, "%s", report);//全部打印还是只取开头？
    
    fclose(fout);
}
