//
//  functions.c
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


void illustration(void) {
    printf("崩三第一期夏活战斗模拟器\n");
    printf("请输入对战角色以及模拟次数(例如“mei kiana 1000”)\n");
    printf("参赛角色：\n芽衣 mei\n琪亚娜 kiana\n布洛妮娅 bronya\n姬子 himeko\n德丽莎 teriri\n符华 fuhua\n卡莲 kallen\n八重樱 sakura\n丽塔 rita\n萝莎莉娅 rozaliya\n莉莉娅 liliya\n希儿 seele\n");
}



battle_info_t* check_input(void) {
    battle_info_t* battle_info = malloc(2 * sizeof(attributes_t*) + sizeof(int));
    char input_info[max_input + 1], character1[9], character2[9];
    int simulated_times;
    
    fgets(input_info, max_input, stdin);
    while (1) {
        while(sscanf(input_info,"%s %s %d", character1, character2, &simulated_times) != 3){
            printf("Incorrect type or format, try again!\n");
            printf("请输入对战角色以及模拟次数(例如“mei kiana 1000”)\n");
            fgets(input_info, max_input, stdin);
            continue;// 1 check whether reading correct type
        }
        //printf("pass check 1\n");
        
        battle_info->simulated_times = simulated_times;
        battle_info->fighter1 = characters(character1);//check whether it works
        battle_info->fighter2 = characters(character2);
        if (battle_info->fighter1!=NULL && battle_info->fighter2!=NULL){
            //printf("pass check 2\n");
            if (battle_info->fighter1 == battle_info->fighter2) {
                printf("Cannot fight self, try again!\n");
                fgets(input_info, max_input, stdin);
                continue;// 3 check whether read same character
            }
            break;
        }
        else {
            printf("Invalid input, try again!\n");
            fgets(input_info, max_input, stdin);
            continue;// 2 check whether reading valid info
        }
    }
    //printf("pass check 3\n");
    printf("%s vs %s 模拟战开始\n", character1, character2);
    
    return battle_info;
}

void normal_defend(attributes_t* attacker, attributes_t* victim, char* report) {
    char record[1000];
    
    if (attacker->win == 0 && victim->win ==0) {
        if (possibility(victim->avoid)) {//s判定是否闪避直接攻击
            int rita_hurt = 0;
            rita_hurt = victim->physical_injury + victim->elemental_injury;
            victim->hp -= victim->physical_injury + victim->elemental_injury;
            //printf("kiana当前hp%d\n",victim->hp);
            sprintf(record, "%s当前hp%d\n",victim->name, victim->hp);
            AaddB(report, record);
            if(strcmp(attacker->name, "Rita")==0 && attacker->unique_skill == 1){
                attacker->hp+= rita_hurt ;
                sprintf(record, "%s回复了%d点hp\n",attacker->name, rita_hurt);
                AaddB(report, record);
            }
        }
        else {
            sprintf(record, "%s闪避了\n",victim->name);
            AaddB(report, record);
        }
        
        if (victim->fire != 0) {//计算点燃，间接伤害无法闪避
            int fire_hurt = 0;
            fire_hurt = 5 * victim->e_def;
            
            victim->hp -= fire_hurt;
            victim->fire--;
            sprintf(record, "%s受到%d点点燃伤害，当前hp%d\n",victim->name, fire_hurt, victim->hp);
            AaddB(report, record);
        }
        if (victim->hp <= 0) {//检验是否战败
            //printf("%s获胜\n\n\n\n",attacker->name);
            sprintf(record, "%s获胜\n\n\n\n",attacker->name);
            AaddB(report, record);
            victim->win = 0;
            attacker->win = 1;
        }
        victim->physical_injury = 0;
        victim->elemental_injury = 0;//重置累计伤害
    }
    else if (attacker->win == 1 && victim->win == 0) {
        sprintf(record, "%s获胜\n\n\n\n",attacker->name);
        AaddB(report, record);
    }
    else if (victim->win == 1 && attacker->win == 0) {
        sprintf(record, "%s获胜\n\n\n\n",victim->name);
        AaddB(report, record);
    }
}


void defend(attributes_t* attacker, attributes_t* victim, char* report) {
    /*if (strcmp(victim->name,"Mei")==0) {
        mei_defend(attacker, victim, report);
        
    }
    else if (strcmp(victim->name,"Kiana")==0) {
        kiana_defend(attacker, victim, report);
    }
    
    else if (strcmp(victim->name,"Bronya")==0) {
        bronya_defend(attacker, victim, report);
    }
     */
    //else
    if (strcmp(victim->name,"Himeko")==0) {
        himeko_defend(attacker, victim, report);
    }
    /*
    else if (strcmp(victim->name,"Teriri")==0) {
        teriri_defend(attacker, victim, report);
    }
    */
    else if (strcmp(victim->name,"Fuhua")==0) {
        fuhua_defend(attacker, victim, report);
    }
    /*
    else if (strcmp(victim->name,"Kallen")==0) {
        kallen_defend(attacker, victim, report);
    }
    else if (strcmp(victim->name,"Sakura")==0) {
        sakura_defend(attacker, victim, report);
    }
    else if (strcmp(victim->name,"Rita")==0) {
        rita_defend(attacker, victim, report);
    }
    else if (strcmp(victim->name,"Rozaliya")==0) {
        rozaliya_defend(attacker, victim, report);
    }
    */
    else if (strcmp(victim->name,"Liliya")==0) {
        liliya_defend(attacker, victim, report);
    }
    /*
    else if (strcmp(victim->name,"Seele")==0) {
        seele_defend(attacker, victim, report);
    }
    */
    else {
        normal_defend(attacker, victim, report);
    }
    
}

void attack(attributes_t* attacker, attributes_t* victim, char* Report) {
    char* report = Report;
    char hp_info[100];
    
    
    
    if (attacker->win == 0 && victim->win ==0) {//检验对手是否已战败
        
        //printf("%s %d\n",victim->name,victim->hp);
        sprintf(hp_info, "%s %d\n",victim->name,victim->hp);//显示对手hp
        AaddB(report, hp_info);
        
        /*
         if (strcmp(attacker->state, "skill_skip") != 0) {//是否被沉默
         
         }
         //计算普攻
         */
        
        if (strcmp(attacker->name,"Mei")==0) {
            mei_attack(attacker, victim, report);
        }
        else if (strcmp(attacker->name,"Kiana")==0) {
            kiana_attack(attacker, victim, report);
        }
        
        else if (strcmp(attacker->name,"Bronya")==0){
            bronya_attack(attacker, victim, report);
        }
        
        else if (strcmp(attacker->name,"Himeko")==0){
            himeko_attack(attacker, victim, report);
        }
        
        else if (strcmp(attacker->name,"Teriri")==0){
            teriri_attack(attacker, victim, report);
        }
        
        else if (strcmp(attacker->name,"Fuhua")==0){
            fuhua_attack(attacker, victim, report);
        }
        
        else if (strcmp(attacker->name,"Kallen")==0){
            kallen_attack(attacker, victim, report);
        }
        
        else if (strcmp(attacker->name,"Sakura")==0){
            sakura_attack(attacker, victim, report);
        }
        
        else if (strcmp(attacker->name,"Rita")==0){
            rita_attack(attacker, victim, report);
        }
        
        else if (strcmp(attacker->name,"Rozaliya")==0){
            rozaliya_attack(attacker, victim, report);
        }
        
        else if (strcmp(attacker->name,"Liliya")==0){
            liliya_attack(attacker, victim, report);
        }
        
        else if (strcmp(attacker->name,"Seele")==0){
            seele_attack(attacker, victim, report);
        }
        
        defend(attacker, victim, report);//结算攻击
    }
    
    
}


void round_fight(attributes_t* fighter1, attributes_t* fighter2, int round, char* report) {
    char* Report = report;
    fighter1->current_round = round;
    fighter2->current_round = round;//写入当前回合数
    
    if (strcmp(fighter1->state,"offensive")==0) {//判断状态
        attack(fighter1, fighter2, Report);
        attack(fighter2, fighter1, Report);
        //fighter1->state = "offensive";//回合结束重置状态
        //fighter2->state = "defensive";
    }
    else {
        attack(fighter2, fighter1, Report);
        attack(fighter1, fighter2, Report);
        //fighter2->state = "offensive";//回合结束重置状态
        //fighter1->state = "defensive";
    }
}

void reset(attributes_t* attacker) {
    attacker->hp = attacker->i_hp;
    attacker->atk = attacker->i_atk;
    attacker->p_def = attacker->i_p_def;
    attacker->e_def = attacker->i_e_def;
    attacker->unique_skill = 0;
    attacker->elemental_injury = 0;
    attacker->physical_injury = 0;
    attacker->abnormal = "";
    attacker->fire = 0;
    attacker->weak = -1;
    attacker->up = 0;
    attacker->win = 0;
}



void fight(void) {
    
    battle_info_t* battle_info;
    attributes_t* fighter1;
    attributes_t* fighter2;
    int attacker_win = 0, defender_win = 0;
    double attacker_win_rate = 0, defender_win_rate = 0;
    
    
    battle_info = check_input();
    fighter1 = battle_info->fighter1;
    fighter2 = battle_info->fighter2;
    
    
    /*
    printf("time%d\n", battle_info->simulated_times);
    printf("mei atk%d\n", fighter1->atk);
    printf("kiana atk%d\n", fighter2->atk);
     */
    //前半段检验是否正确读取战斗信息
    
    //加载对战角色
    reset(fighter1);//初始化状态
    reset(fighter2);
    
    for (int i = 0; i < battle_info->simulated_times; i++){
        char report[10000];
        strcpy(report, "");//每场比赛单独记录
        strcat(report, fighter1->name);
        strcat(report, "vs");
        strcat(report, fighter2->name);
        strcat(report, "\n");//记录比赛双方
        
        int round = 1;
        
        
        
        if (fighter1->speed > fighter2->speed) {
            fighter1->state="offensive";
            fighter2->state="defensive";
        }
        else if (fighter1->speed < fighter2->speed){
            fighter2->state="offensive";
            fighter1->state="defensive";
        }
        else if (fighter1->speed == fighter2->speed) {
            int coin;
            coin = rand() % 2;
            if (coin == 0) {
                fighter1->state="offensive";
                fighter2->state="defensive";
            }
            else if (coin == 1) {
                fighter2->state="offensive";
                fighter1->state="defensive";
            }
        }//判断先后手攻击并写入初始状态
        while (fighter1->win !=1 && fighter2->win != 1 ) {//一方胜出退出循环
            
            char round_info[30]="";
            //printf("\nround %d\n", round);
            sprintf(round_info, "\nround %d\n", round);//显示当前回合
            
            
            AaddB(report, round_info);
            round_fight(fighter1, fighter2, round, report);//重复回合制战斗
            round++;
        }
        if (fighter1->win == 1 && fighter2->win == 0) {
            attacker_win++;
        }
        else if (fighter1->win == 0 && fighter2->win == 1) {
            defender_win++;
        }
        
        
        reset(fighter1);
        reset(fighter2);
        
        output_result(report);
    }
    printf("模拟完毕，详细战斗记录参见自动生成的txt文件\n");
    free(battle_info);
    //printf("%d %d\n", attacker_win, defender_win);
    attacker_win_rate = 100 * (double)attacker_win / (attacker_win + defender_win);
    defender_win_rate = 100 * (double)defender_win / (attacker_win + defender_win);
    printf("%s胜率 %.02f%%\n", fighter1->name, attacker_win_rate);
    printf("%s胜率 %.02f%%\n", fighter2->name, defender_win_rate);
}

