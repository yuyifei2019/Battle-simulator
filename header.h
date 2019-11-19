//
//  attributes.h
//  战斗模拟器
//
//  Created by f on 2019/8/5.
//  Copyright © 2019 F's Studio. All rights reserved.
//

#ifndef attributes_h
#define attributes_h

#define max_input 30
void illustration(void);
//struct attributes;


typedef struct attributes {
    int i_hp, hp, i_atk, atk, i_p_def, p_def, avoid, speed, unique_skill, current_round, physical_injury, elemental_injury, fire, weak, win, up;
    double i_e_def, e_def;
    char *state, *name, *abnormal;
} attributes_t;

typedef struct battle_info {
    attributes_t *fighter1, *fighter2;
    int simulated_times;
} battle_info_t;

void normal_attack(attributes_t* attacker, attributes_t* victim, char* report);
void normal_defend(attributes_t* attacker, attributes_t* victim, char* report);


void fight(void);
battle_info_t* check_input(void);

attributes_t* characters(char* character);

void round_fight(attributes_t* fighter1, attributes_t* fighter2, int round, char* report);
void attack(attributes_t* attacker, attributes_t* victim, char* Report);
void defend(attributes_t* attacker, attributes_t* victim, char* report);
void reset(attributes_t* attacker);
//skill functions
void mei_attack(attributes_t* attacker, attributes_t* victim, char* report);
void kiana_attack(attributes_t* attacker, attributes_t* victim, char* report);
void bronya_attack(attributes_t* attacker, attributes_t* victim, char* report);
void himeko_attack(attributes_t* attacker, attributes_t* victim, char* report);
void teriri_attack(attributes_t* attacker, attributes_t* victim, char* report);
void fuhua_attack(attributes_t* attacker, attributes_t* victim, char* report);
void kallen_attack(attributes_t* attacker, attributes_t* victim, char* report);
void sakura_attack(attributes_t* attacker, attributes_t* victim, char* report);
void rita_attack(attributes_t* attacker, attributes_t* victim, char* report);
void rozaliya_attack(attributes_t* attacker, attributes_t* victim, char* report);
void liliya_attack(attributes_t* attacker, attributes_t* victim, char* report);
void seele_attack(attributes_t* attacker, attributes_t* victim, char* report);

//void mei_defend(attributes_t* attacker, attributes_t* victim, char* report);
//void kiana_defend(attributes_t* attacker, attributes_t* victim, char* report);
//void bronya_defend(attributes_t* attacker, attributes_t* victim, char* report);
void himeko_defend(attributes_t* attacker, attributes_t* victim, char* report);
//void teriri_defend(attributes_t* attacker, attributes_t* victim, char* report);
void fuhua_defend(attributes_t* attacker, attributes_t* victim, char* report);
//void kallen_defend(attributes_t* attacker, attributes_t* victim, char* report);
//void sakura_defend(attributes_t* attacker, attributes_t* victim, char* report);
//void rita_defend(attributes_t* attacker, attributes_t* victim, char* report);
//void rozaliya_defend(attributes_t* attacker, attributes_t* victim, char* report);
void liliya_defend(attributes_t* attacker, attributes_t* victim, char* report);
//void seele_defend(attributes_t* attacker, attributes_t* victim, char* report);


int possibility(int percentage);

void current_time(void);

long int month_day(long int year, long int yearday, long int *month, long int *day);



void output_result(char* report);


void AaddB(char* A, char* B);

#endif /* attributes_h */


