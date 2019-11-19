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


attributes_t Mei = {
    .name = "Mei",
    .i_hp = 100,
    .hp = 100,
    .i_atk = 26,
    .atk = 26,
    .i_p_def = 6,//减法减免物伤
    .p_def = 6,
    .i_e_def = 1,
    .e_def = 1,//受到100%元素伤害
    .avoid = 100,//100%被击中
    .speed = 4,
    .physical_injury = 0,
    .elemental_injury = 0,
    .abnormal = "",
    .weak = -1,
};

attributes_t Kiana = {
    .name = "Kiana",
    
    .i_hp = 120,
    .hp = 120,
    
    .i_atk = 23,
    .atk = 23,
    .i_p_def = 11,
    .p_def = 11,
    .i_e_def = 1,
    .e_def = 1,//受到100%元素伤害
    .avoid = 100,//100%被击中
    .speed = 3,
    .physical_injury = 0,
    .elemental_injury = 0,
    .abnormal = "",
    .weak = -1,
};

attributes_t Bronya = {
    .name = "Bronya",
    .i_hp = 100,
    .hp = 100,
    .i_atk = 26,
    .atk = 26,
    .i_p_def = 8,
    .p_def = 8,
    .i_e_def = 1,
    .e_def = 1,//受到100%元素伤害
    
    .avoid = 85,//85%被击中
    
    .speed = 1,
    .physical_injury = 0,
    .elemental_injury = 0,
    .abnormal = "",
    .weak = -1,
};

attributes_t Himeko = {
    .name = "Himeko",
    .i_hp = 100,
    .hp = 100,
    .i_atk = 24,
    .atk = 24,
    .i_p_def = 10,
    .p_def = 10,
    .i_e_def = 1,
    .e_def = 1,//受到100%元素伤害
    .avoid = 100,//100%被击中
    .speed = 1,
    .physical_injury = 0,
    .elemental_injury = 0,
    .abnormal = "",
    .weak = -1,
};

attributes_t Teriri = {
    .name = "Teriri",
    .i_hp = 100,
    .hp = 100,
    .i_atk = 24,
    .atk = 24,
    .i_p_def = 8,
    .p_def = 8,
    
    .i_e_def = 0.5,
    .e_def = 0.5,//受到50%元素伤害
    
    .avoid = 100,//100%被击中
    .speed = 2,
    .physical_injury = 0,
    .elemental_injury = 0,
    .abnormal = "",
    .weak = -1,
};

attributes_t Fuhua = {
    .name = "Fuhua",
    .i_hp = 100,
    .hp = 100,
    .i_atk = 27,
    .atk = 27,
    .i_p_def = 8,
    .p_def = 8,
    .i_e_def = 1,
    .e_def = 1,//受到100%元素伤害
    .avoid = 100,//100%被击中
    .speed = 6,
    .physical_injury = 0,
    .elemental_injury = 0,
    .abnormal = "",
    .weak = -1,
};

attributes_t Kallen = {
    .name = "Kallen",
    .i_hp = 100,
    .hp = 100,
    .i_atk = 26,
    .atk = 26,
    .i_p_def = 6,
    .p_def = 6,
    .i_e_def = 1,
    .e_def = 1,//受到100%元素伤害
    .avoid = 100,//100%被击中
    .speed = 6,
    .physical_injury = 0,
    .elemental_injury = 0,
    .abnormal = "",
    .weak = -1,
};

attributes_t Sakura = {
    .name = "Sakura",
    .i_hp = 100,
    .hp = 100,
    .i_atk = 28,
    .atk = 28,
    .i_p_def = 7,
    .p_def = 7,
    .i_e_def = 1,
    .e_def = 1,//受到100%元素伤害
    .avoid = 100,//100%被击中
    .speed = 5,
    .physical_injury = 0,
    .elemental_injury = 0,
    .abnormal = "",
    .weak = -1,
};

attributes_t Rita = {
    .name = "Rita",
    .i_hp = 100,
    .hp = 100,
    .i_atk = 26,
    .atk = 26,
    .i_p_def = 8,
    .p_def = 8,
    .i_e_def = 1,
    .e_def = 1,//受到100%元素伤害
    .avoid = 100,//100%被击中
    .speed = 4,
    .physical_injury = 0,
    .elemental_injury = 0,
    .abnormal = "",
    .weak = -1,
};

attributes_t Rozaliya = {
    .name = "Rozaliya",
    .i_hp = 100,
    .hp = 100,
    .i_atk = 30,
    .atk = 30,
    .i_p_def = 4,
    .p_def = 4,
    .i_e_def = 1,
    .e_def = 1,//受到100%元素伤害
    .avoid = 100,//100%被击中
    .speed = 5,
    .physical_injury = 0,
    .elemental_injury = 0,
    .abnormal = "",
    .weak = -1,
};

attributes_t Liliya = {
    .name = "Liliya",
    .i_hp = 100,
    .hp = 100,
    .i_atk = 20,
    .atk = 20,
    .i_p_def = 11,
    .p_def = 11,
    .i_e_def = 1,
    .e_def = 1,//受到100%元素伤害
    .avoid = 100,//100%被击中
    .speed = 5,
    .physical_injury = 0,
    .elemental_injury = 0,
    .abnormal = "",
    .weak = -1,
};

attributes_t Seele = {
    .name = "Seele",
    .i_hp = 100,
    .hp = 100,
    .i_atk = 23,
    .atk = 23,
    .i_p_def = 10,
    .p_def = 10,
    .i_e_def = 1,
    .e_def = 1,//受到100%元素伤害
    .avoid = 100,//100%被击中
    .speed = 6,
    .physical_injury = 0,
    .elemental_injury = 0,
    .abnormal = "",
    .weak = -1,
};


attributes_t* characters(char* character) {
    if (strcmp("mei",character)==0) {
        return &Mei;
    }
    else if (strcmp("kiana",character)==0) {
        return &Kiana;
    }
    else if (strcmp("bronya",character)==0) {
        return &Bronya;
    }
    else if (strcmp("himeko",character)==0) {
        return &Himeko;
    }
    else if (strcmp("teriri",character)==0) {
        return &Teriri;
    }
    else if (strcmp("fuhua",character)==0) {
        return &Fuhua;
    }
    else if (strcmp("kallen",character)==0) {
        return &Kallen;
    }
    else if (strcmp("sakura",character)==0) {
        return &Sakura;
    }
    else if (strcmp("rita",character)==0) {
        return &Rita;
    }
    else if (strcmp("rozaliya",character)==0) {
        return &Rozaliya;
    }
    else if (strcmp("liliya",character)==0) {
        return &Liliya;
    }
    else if (strcmp("seele",character)==0) {
        return &Seele;
    }
    else {
        return NULL;
    }
}


void normal_attack(attributes_t* attacker, attributes_t* victim, char* report) {
    char record[1000];
    if (attacker->atk > victim->p_def) {//判定攻击是否高于防御力
        victim->physical_injury += attacker->atk - victim->p_def;//平a
        sprintf(record, "%s平a，%s即将受到%d伤害\n",attacker->name, victim->name, attacker->atk - victim->p_def);
        AaddB(report, record);        
    }
    else {
        sprintf(record, "%s平a，%s受到0点伤害\n",attacker->name, victim->name);
        AaddB(report, record);
        
    }
    
}

//skill functions
void mei_attack(attributes_t* attacker, attributes_t* victim, char* report) {
    char record[1000];
    if (attacker->weak == 0) {//判断是否被虚弱
        attacker->atk += 15;
        attacker->weak = -1;//进入健康状态
        sprintf(record, "%s解除了虚弱状态，攻击力恢复了\n",attacker->name);
        AaddB(report, record);
    }
    else if (attacker->weak>0) {
        attacker->weak--;
        sprintf(record, "%s处于虚弱状态，攻击力下降\n",attacker->name);
        AaddB(report, record);
    }
    if (strcmp(attacker->abnormal, "rest")!=0) {
        if (strcmp(attacker->abnormal, "skill_skip")!=0) {
            normal_attack(attacker, victim, report);
            victim->elemental_injury += 5;//被动每次附伤
            //printf("%s对%s额外造成了5点元素伤害\n", attacker->name, victim->name);
            sprintf(record, "%s即将对%s额外造成5点元素伤害\n", attacker->name, victim->name);
            AaddB(report, record);
            
            if (possibility(30)) {//被动每次30%概率附伤，跳回合
                victim->elemental_injury += 15 * victim->e_def;
                //printf("%s对%s额外造成了15点元素伤害\n", attacker->name, victim->name);
                sprintf(record, "%s即将对%s额外造成15点元素伤害\n", attacker->name, victim->name);
                
                AaddB(report, record);
                
                victim->abnormal = "skill_skip";
                //printf("%s被沉默了\n", victim->name);//如果要改进的话需sprintf然后defend判定结束后再printf
                sprintf(record, "%s被沉默了\n", victim->name);
                AaddB(report, record);
                
            }
        }
        else {//被沉默
            attacker->abnormal = "";//清除沉默异常状态
            normal_attack(attacker, victim, report);
            victim->elemental_injury += 5;//被动每次附伤
            //printf("%s对%s额外造成了5点元素伤害\n", attacker->name, victim->name);
            sprintf(record, "%s即将对%s额外造成5点元素伤害\n", attacker->name, victim->name);
            AaddB(report, record);
        }
    }
    else {
        attacker->abnormal = "";//清除rest异常状态
    }
    
    
    
    
}
void kiana_attack(attributes_t* attacker, attributes_t* victim, char* report){
    char record[10000];
    if (attacker->weak == 0) {//判断是否被虚弱
        attacker->atk += 15;
        attacker->weak = -1;//进入健康状态
        sprintf(record, "%s解除了虚弱状态，攻击力恢复了\n",attacker->name);
        AaddB(report, record);
    }
    else if (attacker->weak>0) {
        attacker->weak--;
        sprintf(record, "%s处于虚弱状态，攻击力下降\n",attacker->name);
        AaddB(report, record);
    }
    if (strcmp(attacker->abnormal, "rest")!=0) {
        if (strcmp(attacker->abnormal, "skill_skip")!=0) {
            if (attacker->current_round % 3 == 0) {
                if (12 > victim->p_def) {
                    victim->physical_injury += 8 * (12 - victim->p_def);
                    //printf("kiana unique skill!\n%s受到了%d点伤害\n",victim->name,victim->physical_injury);
                    sprintf(record, "kiana unique skill!\n%s即将受到%d点伤害\n",victim->name,victim->physical_injury);
                    AaddB(report, record);
                }
                else {
                    sprintf(record, "kiana unique skill!\n%s受到0点伤害\n",victim->name);
                    AaddB(report, record);
                }
                
            }
            else {
                normal_attack(attacker, victim, report);
            }
        }
        else {
            attacker->abnormal = "";//清除沉默异常状态
            normal_attack(attacker, victim, report);
        }
    }
    else {
        attacker->abnormal = "";//清除rest异常状态
    }
    
}
void bronya_attack(attributes_t* attacker, attributes_t* victim, char* report) {
    char record[1000];
    if (attacker->weak == 0) {//判断是否被虚弱
        attacker->atk += 15;
        attacker->weak = -1;//进入健康状态
        sprintf(record, "%s解除了虚弱状态，攻击力恢复了\n",attacker->name);
        AaddB(report, record);
    }
    else if (attacker->weak>0) {
        attacker->weak--;
        sprintf(record, "%s处于虚弱状态，攻击力下降\n",attacker->name);
        AaddB(report, record);
    }
    if (strcmp(attacker->abnormal, "rest")!=0) {
        if (strcmp(attacker->abnormal, "skill_skip")!=0) {
            if (attacker->current_round % 3 == 0) {
                int hurt = 0;
                hurt = rand()%100+1 - victim->p_def;
                if (hurt > 0) {
                    victim->physical_injury += hurt;
                    sprintf(record, "Bronya unique skill!\n%s即将受到%d点伤害\n",victim->name,victim->physical_injury);
                    AaddB(report, record);
                }
                else {
                    sprintf(record, "Bronya unique skill!\n%s受到0点伤害\n",victim->name);
                    AaddB(report, record);
                }
                
                
            }
            else {
                normal_attack(attacker, victim, report);
            }
        }
        else {
            attacker->abnormal = "";//清除沉默异常状态
            normal_attack(attacker, victim, report);
        }
    }
    else {
        attacker->abnormal = "";//清除rest异常状态
    }
    
};

void himeko_attack(attributes_t* attacker, attributes_t* victim, char* report){
    char record[1000];
    if (attacker->weak == 0) {//判断是否被虚弱
        attacker->atk += 15;
        attacker->weak = -1;//进入健康状态
        sprintf(record, "%s解除了虚弱状态，攻击力恢复了\n",attacker->name);
        AaddB(report, record);
    }
    else if (attacker->weak>0) {
        attacker->weak--;
        sprintf(record, "%s处于虚弱状态，攻击力下降\n",attacker->name);
        AaddB(report, record);
    }
    if (attacker->hp < 40) {
        if (attacker->up == 0) {//判定已启动强化
            attacker->up = 1;
            attacker->atk += 12;
            attacker->p_def += 5;
            sprintf(record, "%s攻防已上升\n",attacker->name);
            AaddB(report, record);
        }
        
    }
    
    if (attacker->unique_skill == 1) {
        attacker->unique_skill = 0;//清除蓄力状态
        if (strcmp(attacker->abnormal, "rest")!=0) {
            int hurt1 = 0, hurt2 = 0;
            hurt1 = attacker->atk - victim->p_def;
            hurt2 = (attacker->atk * 2) * victim->e_def;
            victim->physical_injury += hurt1;//平a
            victim->elemental_injury += hurt2;
            sprintf(record, "%s平a，%s即将受到%d+%d伤害\n",attacker->name, victim->name, hurt1, hurt2);//
            AaddB(report, record);
            
            
        }
        else {
            attacker->abnormal = "";//清除rest异常状态
        }
    }
    else if(attacker->unique_skill == 0) {
        if (strcmp(attacker->abnormal, "rest")!=0) {
            if (strcmp(attacker->abnormal, "skill_skip")!=0) {
                if (possibility(30)) {
                    attacker->unique_skill = 1;
                    sprintf(record, "姬子开始蓄力了\n");//
                    AaddB(report, record);
                }
                else {
                    normal_attack(attacker, victim, report);
                }
            }
            else {
                attacker->abnormal = "";//清除沉默异常状态
                normal_attack(attacker, victim, report);
            }
        }
        else {
            attacker->abnormal = "";//清除rest异常状态
        }
    }
    
    
}

void teriri_attack(attributes_t* attacker, attributes_t* victim, char* report) {
    char record[1000];
    if (attacker->weak == 0) {//判断是否被虚弱
        attacker->atk += 15;
        attacker->weak = -1;//进入健康状态
        sprintf(record, "%s解除了虚弱状态，攻击力恢复了\n",attacker->name);
        AaddB(report, record);
    }
    else if (attacker->weak>0) {
        attacker->weak--;
        sprintf(record, "%s处于虚弱状态，攻击力下降\n",attacker->name);
        AaddB(report, record);
    }
    if (strcmp(attacker->abnormal, "rest")!=0) {
        if (strcmp(attacker->abnormal, "skill_skip")!=0) {
            if (attacker->current_round % 2 == 0) {
                
                victim->elemental_injury += (rand()%16+1) * 4;
                sprintf(record, "Teriri unique skill!\n%s即将受到%d点元素伤害\n",victim->name,victim->elemental_injury);
                AaddB(report, record);
                
            }
            else {
                normal_attack(attacker, victim, report);
            }
        }
        else {
            attacker->abnormal = "";//清除沉默异常状态
            normal_attack(attacker, victim, report);
        }
    }
    else {
        attacker->abnormal = "";//清除rest异常状态
    }
}

void fuhua_attack(attributes_t* attacker, attributes_t* victim, char* report) {
    char record[1000];
    if (attacker->weak == 0) {//脱离虚弱状态攻击加回15
        attacker->atk += 15;
        attacker->weak = -1;//进入健康状态
        sprintf(record, "%s解除了虚弱状态，攻击力恢复了\n",attacker->name);
        AaddB(report, record);
    }
    else if (attacker->weak>0) {//处于虚弱状态
        attacker->weak--;
        sprintf(record, "%s处于虚弱状态，攻击力下降\n",attacker->name);
        AaddB(report, record);
    }
    if (strcmp(attacker->abnormal, "rest")!=0) {
        if (strcmp(attacker->abnormal, "skill_skip")!=0) {
            if (attacker->current_round % 3 == 0) {
                
                victim->elemental_injury += rand()%21+10;
                sprintf(record, "Fuhua unique skill!\n%s即将受到%d点元素伤害\n",victim->name,victim->elemental_injury);
                AaddB(report, record);
                
            }
            else {
                normal_attack(attacker, victim, report);
            }
        }
        else {
            attacker->abnormal = "";//清除沉默异常状态
            normal_attack(attacker, victim, report);
        }
    }
    else {
        attacker->abnormal = "";//清除rest异常状态
    }
}

void kallen_attack(attributes_t* attacker, attributes_t* victim, char* report) {
    char record[1000];
    if (attacker->weak == 0) {//判断是否被虚弱
        attacker->atk += 15;
        sprintf(record, "%s解除了虚弱状态，攻击力恢复了\n",attacker->name);
        AaddB(report, record);
        
        
    }
    else if (attacker->weak>0) {
        attacker->weak--;
        sprintf(record, "%s处于虚弱状态，攻击力下降\n",attacker->name);
        AaddB(report, record);
        
        
    }
    if (strcmp(attacker->abnormal, "rest")!=0) {
        if (possibility(5)) {
            attacker->win = 1;
            victim->win = 0;
            sprintf(record, "卡莲unique skill! 直接获胜\n");
            AaddB(report, record);
            
            
        }
        else if (strcmp(attacker->abnormal, "skill_skip")!=0) {
            normal_attack(attacker, victim, report);
            if (possibility(30)) {
                if (victim->weak == -1) {
                    victim->atk -= 15;
                    victim->weak = 2;
                    sprintf(record, "%s被虚弱了\n", victim->name);
                    AaddB(report, record);
                }
                else if (victim->weak >=0 && victim->weak <=2) {
                    victim->weak = 2;
                    sprintf(record, "%s虚弱延时\n", victim->name);
                    AaddB(report, record);
                }
                else {
                    printf("卡莲虚弱状态施加异常\n");
                    exit(1);
                }
            }
        }
        else {
            attacker->abnormal = "";//清除沉默异常状态
            normal_attack(attacker, victim, report);
        }
    }
    else {
        attacker->abnormal = "";//清除rest异常状态
    }
}

void sakura_attack(attributes_t* attacker, attributes_t* victim, char* report) {
    char record[1000];
    if (attacker->weak == 0) {//判断是否被虚弱
        attacker->atk += 15;
        attacker->weak = -1;//进入健康状态
        sprintf(record, "%s解除了虚弱状态，攻击力恢复了\n",attacker->name);
        AaddB(report, record);
    }
    else if (attacker->weak>0) {
        attacker->weak--;
        sprintf(record, "%s处于虚弱状态，攻击力下降\n",attacker->name);
        AaddB(report, record);
    }
    if (strcmp(attacker->abnormal, "rest")!=0) {
        if (strcmp(attacker->abnormal, "skill_skip")!=0) {
            if (possibility(25)) {
                sprintf(record, "%s unique skill! 造成双倍伤害\n",attacker->name);
                AaddB(report, record);
                if (attacker->atk > victim->p_def) {//判定攻击是否高于防御力
                    int hurt = 0;
                    hurt = (attacker->atk - victim->p_def) * 2;
                    victim->physical_injury += hurt;//平a
                    sprintf(record, "%s平a，%s即将受到%d伤害\n",attacker->name, victim->name, hurt);
                    AaddB(report, record);
                }
                else {
                    sprintf(record, "%s平a，%s受到0点伤害\n",attacker->name, victim->name);
                    AaddB(report, record);
                }
            }
            else {
                normal_attack(attacker, victim, report);
            }
            
        }
        else {
            attacker->abnormal = "";//清除沉默异常状态
            normal_attack(attacker, victim, report);
        }
        
        if (possibility(25)) {
            victim->fire = 3;
            sprintf(record, "%s点燃了对手\n",attacker->name);
            AaddB(report, record);
        }
        
    }
    else {
        attacker->abnormal = "";//清除rest异常状态
    }
    
}

void rita_attack(attributes_t* attacker, attributes_t* victim, char* report) {
    char record[10000];
    if (attacker->weak == 0) {//判断是否被虚弱
        attacker->atk += 15;
        attacker->weak = -1;//进入健康状态
        sprintf(record, "%s解除了虚弱状态，攻击力恢复了\n",attacker->name);
        AaddB(report, record);
    }
    else if (attacker->weak>0) {
        attacker->weak--;
        sprintf(record, "%s处于虚弱状态，攻击力下降\n",attacker->name);
        AaddB(report, record);
    }
    if (strcmp(attacker->abnormal, "rest")!=0) {
        if (strcmp(attacker->abnormal, "skill_skip")!=0) {
            if(possibility(30)){
                attacker->unique_skill = 1;
                //sprintf(record, "%s发动被动技能\n",attacker->name);
                //AaddB(report, record);
            }
            if(possibility(20)){
                victim->abnormal = "rest";
                sprintf(record, "%s unique skill!%s无法攻击一回合\n",attacker->name, victim->name);
                AaddB(report, record);
            }
            normal_attack(attacker, victim, report);
        }
        else {
            attacker->abnormal = "";//清除沉默异常状态
            if(possibility(30)){
                attacker->unique_skill = 1;
                sprintf(record, "%s发动被动技能\n",attacker->name);
                AaddB(report, record);
            }
            normal_attack(attacker, victim, report);
        }
        
    }
    else {
        attacker->abnormal = "";//清除rest异常状态
    }
}


void rozaliya_attack(attributes_t* attacker, attributes_t* victim, char* report) {
    char record[10000];
    double hurt_coeffifient = 1;
    if (attacker->unique_skill == 1) {
        hurt_coeffifient = 1.5;
    }
    else if (attacker->unique_skill == -1){
        hurt_coeffifient = 0.5;
    }
    else if (attacker->unique_skill == 0){
        hurt_coeffifient = 1;
    }
    if (attacker->weak == 0) {//判断是否被虚弱
        attacker->atk += 15;
        attacker->weak = -1;//进入健康状态
        sprintf(record, "%s解除了虚弱状态，攻击力恢复了\n",attacker->name);
        AaddB(report, record);
    }
    else if (attacker->weak>0) {
        attacker->weak--;
        sprintf(record, "%s处于虚弱状态，攻击力下降\n",attacker->name);
        AaddB(report, record);
    }
    if (strcmp(attacker->abnormal, "rest")!=0) {
        
        
        
        if (strcmp(attacker->abnormal, "skill_skip")!=0) {
            
            if (attacker->current_round % 3 == 0) {
                attacker->abnormal = "rest";
                if (15 > victim->p_def) {
                    victim->physical_injury += 10 * (15 - victim->p_def) * hurt_coeffifient;
                    //printf("kiana unique skill!\n%s受到了%d点伤害\n",victim->name,victim->physical_injury);
                    sprintf(record, "Rozaliya unique skill!\n%s即将受到%d点伤害\n",victim->name,victim->physical_injury);
                    AaddB(report, record);
                }
                else {
                    sprintf(record, "Rozaliya unique skill!\n%s受到0点伤害\n",victim->name);
                    AaddB(report, record);
                }
                
            }
            else {
                if (attacker->atk > victim->p_def) {//判定攻击是否高于防御力
                    victim->physical_injury += (attacker->atk - victim->p_def) * hurt_coeffifient;//平a
                    sprintf(record, "%s平a，%s即将受到%.01f伤害\n",attacker->name, victim->name, (attacker->atk - victim->p_def)*hurt_coeffifient);
                    AaddB(report, record);
                }
                else {
                    sprintf(record, "%s平a，%s受到0点伤害\n",attacker->name, victim->name);
                    AaddB(report, record);
                    
                }
            }
        }
        else {
            attacker->abnormal = "";//清除沉默异常状态
            normal_attack(attacker, victim, report);
        }
        
        if (possibility(30)) {
            attacker->unique_skill = 1;
            sprintf(record, "Rozaliya下回合将增加50%%额外伤害\n");
            AaddB(report, record);
            
        }
        else if (rand()%70<30) {
            attacker->unique_skill = -1;
            sprintf(record, "Rozaliya下回合将减少50%%伤害\n");
            AaddB(report, record);
        }
        else {
            attacker->unique_skill = 0;
        }
        
        
    }
    else {
        attacker->abnormal = "";//清除rest异常状态
    }
}

void liliya_attack(attributes_t* attacker, attributes_t* victim, char* report) {
    char record[10000];
    
    if (attacker->current_round % 7 == 0) {
        attacker->win = 1;
        victim->win = 0;
        sprintf(record, "%s第七回合，莉莉娅胜利\n",attacker->name);
        AaddB(report, record);
    }
    else {
        if (attacker->weak == 0) {//判断是否被虚弱
            attacker->atk += 15;
            attacker->weak = -1;//进入健康状态
            sprintf(record, "%s解除了虚弱状态，攻击力恢复了\n",attacker->name);
            AaddB(report, record);
        }
        else if (attacker->weak>0) {
            attacker->weak--;
            sprintf(record, "%s处于虚弱状态，攻击力下降\n",attacker->name);
            AaddB(report, record);
        }
        if (strcmp(attacker->abnormal, "rest")!=0) {
            normal_attack(attacker, victim, report);
        }
        else {
            attacker->abnormal = "";//清除rest异常状态
        }
    }

}

void seele_attack(attributes_t* attacker, attributes_t* victim, char* report) {
    char record[10000];
    attacker->hp+=7;
    sprintf(record, "%s恢复了7点生命\n",attacker->name);
    AaddB(report, record);
    if (attacker->hp>100){
        attacker->hp = 100;
    }
    
    if (attacker->weak == 0) {//判断是否被虚弱
        attacker->atk += 15;
        attacker->weak = -1;//进入健康状态
        sprintf(record, "%s解除了虚弱状态，攻击力恢复了\n",attacker->name);
        AaddB(report, record);
    }
    else if (attacker->weak>0) {
        attacker->weak--;
        sprintf(record, "%s处于虚弱状态，攻击力下降\n",attacker->name);
        AaddB(report, record);
    }
    if (strcmp(attacker->abnormal, "rest")!=0) {
        if (strcmp(attacker->abnormal, "skill_skip")!=0) {
            if (attacker->current_round % 4 == 0) {
                sprintf(record, "%s unique skill!\n",attacker->name);
                AaddB(report, record);
                if (possibility(25)){
                    victim->physical_injury+=100-victim->p_def;
                    sprintf(record, "%s即将受到%d点伤害\n",victim->name, victim->physical_injury);
                    AaddB(report, record);
                    
                }
                else {
                    sprintf(record, "%s没有命中\n",attacker->name);
                    AaddB(report, record);
                }
                
            }
            else {
                normal_attack(attacker, victim, report);
            }
        }
        else {
            attacker->abnormal = "";//清除沉默异常状态
            normal_attack(attacker, victim, report);
        }
    }
    else {
        attacker->abnormal = "";//清除rest异常状态
    }
}

/*
void mei_defend(attributes_t* attacker, attributes_t* victim, char* report) {
    char record[1000];
    victim->hp -= victim->physical_injury + victim->elemental_injury;
    //printf("mei当前hp%d\n",victim->hp);
    sprintf(record, "mei当前hp%d\n",victim->hp);
    AaddB(report, record);
    if (victim->hp <= 0) {//检验是否战败
        //printf("%s获胜\n",attacker->name);
        sprintf(record, "%s获胜\n",attacker->name);
        AaddB(report, record);
        
        victim->hp = 0;
    }
    victim->physical_injury = 0;
    victim->elemental_injury = 0;//重置累计伤害
}

void kiana_defend(attributes_t* attacker, attributes_t* victim, char* report) {//kiana无防御技能，直接结算
    char record[1000];
    
    victim->hp -= victim->physical_injury + victim->elemental_injury;
    //printf("kiana当前hp%d\n",victim->hp);
    sprintf(record, "kiana当前hp%d\n",victim->hp);
    AaddB(report, record);
    
    if (victim->hp <= 0) {//检验是否战败
        //printf("%s获胜\n\n\n\n",attacker->name);
        sprintf(record, "%s获胜\n\n\n\n",attacker->name);
        AaddB(report, record);
        victim->hp = 0;
    }
    victim->physical_injury = 0;
    victim->elemental_injury = 0;//重置累计伤害
}
*/

/*
 void bronya_defend(attributes_t* attacker, attributes_t* victim, char* report);
 */
 
void himeko_defend(attributes_t* attacker, attributes_t* victim, char* report) {
    char record[1000];
    
    if (attacker->win == 0 && victim->win ==0) {
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
        
        if (victim->fire != 0) {//计算点燃
            victim->hp -= 5 * victim->e_def;
            victim->fire--;
            sprintf(record, "%s受到5点点燃伤害，当前hp%d\n",victim->name, victim->hp);
            AaddB(report, record);
        }
        if (victim->hp <= 0) {//检验是否战败
            //printf("%s获胜\n\n\n\n",attacker->name);
            sprintf(record, "%s获胜\n\n\n\n",attacker->name);
            AaddB(report, record);
            victim->win = 0;
            attacker->win = 1;
        }
        else {
            if (victim->hp < 40) {
                if (victim->up == 0) {//判定已启动强化
                    victim->up = 1;
                    victim->atk += 12;
                    victim->p_def += 5;
                    sprintf(record, "%s攻防已上升\n",victim->name);
                    AaddB(report, record);
                }
                
            }
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
/*
 
void teriri_defend(attributes_t* attacker, attributes_t* victim, char* report);
 
*/
void fuhua_defend(attributes_t* attacker, attributes_t* victim, char* report){
    
    char record[1000];
    
    if (attacker->win == 0 && victim->win ==0) {
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
        
        if (victim->fire != 0) {//计算点燃
            int fire_hurt = 0;
            fire_hurt = 5 * victim->e_def;
            victim->hp -= fire_hurt;
            victim->fire--;
            sprintf(record, "%s受到%d点点燃伤害，当前hp%d\n",victim->name, fire_hurt, victim->hp);
            AaddB(report, record);
        }
        
        if (victim->hp <= 0) {//检验是否战败
            if (victim->unique_skill == 0) {
                victim->unique_skill = attacker->current_round;
                victim->hp = 1;
                victim->e_def = 0;
                sprintf(record, "符华本回合不会倒下\n符华获得元素伤害免疫\n");
                AaddB(report, record);
            }
            else {
                //printf("%s获胜\n\n\n\n",attacker->name);
                sprintf(record, "%s获胜\n\n\n\n",attacker->name);
                AaddB(report, record);
                victim->win = 0;
                attacker->win = 1;
            }
            
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
 
 
/*
void kallen_defend(attributes_t* attacker, attributes_t* victim, char* report);
void sakura_defend(attributes_t* attacker, attributes_t* victim, char* report);
void rita_defend(attributes_t* attacker, attributes_t* victim, char* report);
void rozaliya_defend(attributes_t* attacker, attributes_t* victim, char* report);
*/
 
 
void liliya_defend(attributes_t* attacker, attributes_t* victim, char* report) {
    
    char record[1000];
    int hurt;
    hurt = victim->physical_injury + victim->elemental_injury;
    
    if (attacker->win == 0 && victim->win == 0) {
        if (possibility(15) && hurt > 0) {//触发防反
            if (strcmp(attacker->name,"Fuhua")==0) {//对手是符华
                if (attacker->unique_skill == victim->current_round) {//符华锁血
                    sprintf(record, "符华免疫本次伤害\n");
                    AaddB(report, record);
                }
                else {
                    if (attacker->hp < hurt) {
                        attacker->unique_skill = victim->current_round;
                        attacker->hp = 1;
                        attacker->e_def = 0;
                        sprintf(record, "符华本回合不会倒下\n符华获得元素伤害免疫\n");
                        AaddB(report, record);
                    }
                    else {
                        attacker->hp -= hurt;
                        sprintf(record, "liliya弹反,%s受到%d点伤害\n%s当前hp%d\n",attacker->name, hurt,attacker->name, attacker->hp);
                        AaddB(report, record);
                    }
                }
            }
            else {
                attacker->hp -= hurt;
                sprintf(record, "liliya弹反,%s受到%d点伤害\n%s当前hp%d\n",attacker->name, hurt,attacker->name, attacker->hp);
                AaddB(report, record);
                if (attacker->hp < 0) {
                    victim->win = 1;
                    attacker->win = 0;
                    sprintf(record, "liliya获胜\n");
                    AaddB(report, record);
                }
            }
            
        }
        else {
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
        
        
        if (victim->fire != 0) {//计算点燃
            victim->hp -= 5 * victim->e_def;
            victim->fire--;
            sprintf(record, "%s受到5点点燃伤害，当前hp%d\n",victim->name, victim->hp);
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
 
 
/*
void seele_defend(attributes_t* attacker, attributes_t* victim, char* report);
*/
