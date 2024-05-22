#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h> //문자열 관련 함수 쓰기 위한 헤더 파일
#include <time.h>

char my_name[10]; //사용자의 이름 저장하는 변수
char your_name[10]; //상대방의 이름 저장하는 변수
char my_character[10], your_character[10]; // 나의 캐릭터 이름, 상대방의 캐릭터 이름
char character[4][10] = { "피츄", "이상해씨", "파이리", "꼬부기" }; //캐릭터 이름 저장
char next1, next2; // enter키 누르면 다음 대화창 뜨도록 만드는 변수
int turn;  //내 턴과 상대방 턴을 알려주는 변수
int menu_choice;  //menu 선택(1번. 모험하기 or 2번. 다른 사람과 대결)
int my_HP = 250, your_HP = 250; // 나의 체력(HP), 상대방의 체력(HP)-체력이 0이면 지는 것 
int HP;
int my_status, your_status;  // 나의 상태, 상대방의 상태
int status = 0;
int my_defense, your_defense;  //나의 방어, 상대방의 방어
int defense;
char turn_character[10];  
int my_skill1, my_skill2, my_skill3, my_skill4, my_heal;  //내 기술 횟수 저장
int your_skill1, your_skill2, your_skill3, your_skill4, your_heal;  //상대방의 기술 횟수 저장
int skill1, skill2, skill3, skill4, heal;  
int pitchu_skill_count[5] = { 5,5,2,1,1 };
int seed_skill_count[5] = { 5,5,2,1,1 };
int piri_skill_count[5] = { 5,1,2,1,1 };
int kobuk_skill_count[5] = { 5,5,2,1,1 };

void my_name_func(void);
void your_name_func(void);
void computer_name_func(void);
void my_character_func(void);
void computer_character_func(void);
void your_character_func(void);
void first_menu(void);
void adventure(void);
void match(void);
void battle(void);
void my_skill_count(void);
void your_skill_count(void);
void pick_my_turn(void);
void pick_your_turn(void);
void pitchu_turn(void);
void seed_turn(void);
void piri_turn(void);
void kobuk_turn(void);
void turn_mory_skill(void);
void save_mory_skill(void);
void turn_mory_status(void);
void save_mory_status(void);
void current_status(void);
void save_current_status(void);
void turn_mory_defense(void);
void save_mory_defense(void);
void turn_mory_HP(void);
void save_mory_HP(void);
void resave_mory_HP(void);
void recover_mory_HP(void);
void turn_mory_character(void);

void p1();
void p2();
void p3();
void p4();
void s1();
void s2();
void s3();
void s4();
void l1();
void l2();
void l3();
void l4();
void k1();
void k2();
void k3();
void k4();

int main(void)
{	
	first_menu();
	while (1) {
		printf("1. 모험하기  2. 다른 사용자와의 대결\n");
		printf("어떤 것을 선택하시겠습니까?: ");
		scanf("%d", &menu_choice);
		scanf("%c%c", &next1, &next2);

		if (menu_choice == 1) {
			printf("모험하기를 선택하셨습니다!\n");
			scanf("%c", &next1);
			adventure();
			break;
		}
		else if (menu_choice == 2) {
			printf("다른 사용자와의 대결을 선택하셨습니다!\n");
			scanf("%c", &next1);
			match();
			break;
		}
		else {
			printf("메뉴를 다시 선택하세요!\n");
			scanf("%c", &next1);
		}
	}
	return 0;
}

void first_menu(void) {
	printf("                                                                               ########   \n");
	printf("                                                                               #          \n");
	printf("#########  #######   # #    #######     #      #######   #    #      #   # #   ########   \n");
	printf("   # #          ##   # #    #     #    # #     #         #    #      #   # #   #          \n");
	printf("   # #     ########### #    #     #   ##  ##   ######  ###    ########   # #   ########   \n");
	printf("########        ##   # #    #######  ##    ##  #         #    #      #   ###              \n");
	printf("    #           ##   # #       #               #######   #    ########   # #  ########### \n");
	printf("    #                ##     #######                      #               # #              \n"); 
	printf("#########         ##   ##   #        ##########          #               # #   #########  \n");
	printf("                 ##     ##  ########                     #               # #           #  \n");
	printf("                                                                               #########  \n");
	printf("                                                                               #          \n");
	printf("                                                                               #########  \n");
	printf("\n\n");
	printf("@@@@   텍스트를 넘기려면 엔터키로(엔터키 두 번 눌러야 할 때도 있음)\n");
	scanf("%c", &next1);
}

void adventure(void) {
	my_name_func();
	computer_name_func();
	strncpy(my_character, character[0], sizeof(character[0]));
	computer_character_func();
	printf("야생의 %s가 나타났다!\n", your_character);
	scanf("%c", &next1);
	printf("나와라 %s!\n", my_character);
	scanf("%c", &next1);
	printf("\n%s의 체력 : %d/250     %s의 체력 : %d/250\n\n", my_character, my_HP, your_character, your_HP);
	scanf("%c", &next1);
	battle();
}

void match(void) {
	my_name_func();
	my_character_func();
	your_name_func();
	your_character_func();
	printf("나: %s\tvs\t상대방: %s\t대결!\n", my_character, your_character);
	scanf("%c", &next1);
	printf("나와라 %s!\n", my_character);
	scanf("%c", &next1);
	printf("\n%s의 체력 : %d/250     %s의 체력 : %d/250\n\n", my_character, my_HP, your_character, your_HP);
	scanf("%c", &next1);
	battle();
}

void my_name_func(void) {
	int name;
	char no_name[] = "이름 없음";
	
	while (1) {

		printf("사용자의 이름을 입력하시겠습니까? [1. YES  2.NO]  : ");
		scanf("%d", &name);

		if (name == 1) {
			printf("당신의 이름은 무엇입니까?: ");
			scanf("%s", my_name);
			printf("[%s]님! 환영합니다!\n", my_name);
			scanf("%c%c", &next1, &next2);
			break;
		}
		else if (name == 2) {
			
			strncpy(my_name, no_name, sizeof(no_name));
			printf("[%s]님! 환영합니다!\n", my_name);
			scanf("%c%c", &next1, &next2);
			break;
		}
		else {
			printf("메뉴를 잘못 선택하셨습니다! 다시 골라주세요!\n");
			scanf("%c%c", &next1, &next2);
		}
	}
}

void your_name_func(void) {
	int name;
	char no_name[] = "이름 없음";

	while (1) {

		printf("사용자2의 이름을 입력하시겠습니까? [1. YES  2.NO]  : ");
		scanf("%d", &name);

		if (name == 1) {
			printf("당신의 이름은 무엇입니까?: ");
			scanf("%s", your_name);
			printf("[%s]님! 환영합니다!\n", your_name);
			scanf("%c%c", &next1, &next2);
			break;
		}
		else if (name == 2) {
			strncpy(your_name, no_name, sizeof(no_name));
			printf("[%s]님! 환영합니다!\n", your_name);
			scanf("%c%c", &next1, &next2);
			break;
		}
		else {
			printf("메뉴를 잘못 선택하셨습니다! 다시 골라주세요!\n");
			scanf("%c%c", &next1, &next2);
		}
	}
}

void computer_name_func(void) {
	strncpy(your_name, "computer", sizeof("computer"));
}

void my_character_func(void) {
	int choice;

	while (1) {
		printf("1. 피츄 2. 이상해씨 3. 파이리 4. 꼬부기\n");
		printf("[%s]님의 파트너를 선택하세요 : ", my_name);
		scanf("%d", &choice);

		if (choice == 1) {
			printf("[%s]님의 파트너로 %s를 선택하셨습니다!\n", my_name, character[0]);
			strncpy(my_character, character[0], sizeof(character[0]));
			break;
		}
		else if (choice == 2) {
			printf("[%s]님의 파트너로 %s를 선택하셨습니다!\n", my_name, character[1]);
			strncpy(my_character, character[1], sizeof(character[1]));
			break;
		}
		else if (choice == 3) {
			printf("[%s]님의 파트너로 %s를 선택하셨습니다!\n", my_name, character[2]);
			strncpy(my_character, character[2], sizeof(character[2]));
			break;
		}
		else if (choice == 4) {
			printf("[%s]님의 파트너로 %s를 선택하셨습니다!\n", my_name, character[3]);
			strncpy(my_character, character[3], sizeof(character[3]));
			break;
		}
		else {
			printf("파트너를 다시 선택해주세요!\n");
			scanf("%c%c", &next1, &next2);
		}
	}
	scanf("%c%c", &next1, &next2);
}


void computer_character_func(void) {  
	srand((unsigned)time(NULL));
	int x = rand() % 4;

	if (x == 0) {
		strncpy(your_character, character[0], sizeof(character[0]));
	}
	else if (x == 1) {
		strncpy(your_character, character[1], sizeof(character[1]));
	}
	else if (x == 2) {
		strncpy(your_character, character[2], sizeof(character[2]));
	}
	else if (x == 3) {
		strncpy(your_character, character[3], sizeof(character[3]));
	}
}

void your_character_func(void) {
	int choice;

	while (1) {
		printf("1. 피츄 2. 이상해씨 3. 파이리 4. 꼬부기\n");
		printf("[%s]님의 파트너를 선택하세요: ", your_name);
		scanf_s("%d", &choice);

		if (choice == 1) {
			printf("[%s]님의 파트너로 %s를 선택하셨습니다!\n", your_name, character[0]);
			strncpy(your_character, character[0], sizeof(character[0]));
			break;
		}
		else if (choice == 2) {
			printf("[%s]님의 파트너로 %s를 선택하셨습니다!\n", your_name, character[1]);
			strncpy(your_character, character[1], sizeof(character[1]));
			break;
		}
		else if (choice == 3) {
			printf("[%s]님의 파트너로 %s를 선택하셨습니다!\n", your_name, character[2]);
			strncpy(your_character, character[2], sizeof(character[2]));
			break;
		}
		else if (choice == 4) {
			printf("[%s]님의 파트너로 %s를 선택하셨습니다!\n", your_name, character[3]);
			strncpy(your_character, character[3], sizeof(character[3]));
			break;
		}
		else {
			printf("파트너를 다시 선택해주세요!\n");
			scanf("%c%c", &next1, &next2);
		}
	}
	scanf("%c%c", &next1, &next2);
}

void battle(void) {
	my_skill_count();
	your_skill_count();

	while (1) {
		turn = 0;
		if (your_defense == 1) {
			printf("상대방이 방어 기술을 사용하여 다음 턴으로 넘어간다\n");
			scanf("%c", &next1);
			your_defense = 0;
		}
		else {
			pick_my_turn();
			printf("%s의 체력 : %d/250     %s의 체력 : %d/250\n", my_character, my_HP, your_character, your_HP);
			scanf("%c", &next1);
			if (my_HP <= 0) {
				printf("%s가 쓰러졌다.\n %s의 승리!\n", my_character, your_character);
				scanf("%c", &next1);
				printf("%s님이 승리하셨습니다.", your_name);
				break;
			}
			else if (your_HP <= 0) {
				printf("%s가 쓰러졌다.\n %s의 승리!\n", your_character, my_character);
				scanf("%c", &next1);
				printf("%s님이 승리하셨습니다.", my_name);
				break;
			}
			else if (my_skill1 == 0 && my_skill2 == 0 && my_skill3 == 0 && my_skill4 == 0) //더 이상 기술을 쓸 수 없을 때
			{
				printf("%s는 더 이상 기술을 쓸 수 없다!\n%s의 승리!\n", my_character, your_character);
				scanf("%c", &next1);
				printf("%s님이 승리하셨습니다.", your_name);
				break;
			}
		}
		turn = 1;
		if (my_defense == 1) {
			printf("나의 방어 사용으로 다음 턴으로 넘어간다\n");
			scanf("%c", &next1);
			my_defense = 0;
		}
		else {
			pick_your_turn();
			printf("%s의 체력:%d/250     %s의 체력:%d/250\n", my_character, my_HP, your_character, your_HP);
			scanf("%c", &next1);
			if (my_HP <= 0)
			{
				printf("%s가 쓰러졌다\n%s의 승리!\n", my_character, your_character);
				scanf("%c", &next1);
				printf("%s님이 승리하셨습니다.", your_name);
				break;
			}
			else if (your_HP <= 0)
			{
				("%s가 쓰러졌다\n%s의 승리!\n", your_character, my_character);
				scanf("%c", &next1);
				printf("%s님이 승리하셨습니다.", my_name);
				break;
			}
			else if (your_skill1 == 0 && your_skill2 == 0 && your_skill3 == 0 && your_skill4 == 0) //더 이상 기술을 쓸 수 없을 때
			{
				printf("%s는 더 이상 기술을 쓸 수 없다!\n%s의 승리!\n", your_character, my_character);
				scanf("%c", &next1);
				printf("%s님이 승리하셨습니다.", my_name);
				break;
			}
		}	
	}
}

void my_skill_count(void) {
	if (strcmp(my_character, "피츄") == 0) {
		my_skill1 = pitchu_skill_count[0];
		my_skill2 = pitchu_skill_count[1];
		my_skill3 = pitchu_skill_count[2];
		my_skill4 = pitchu_skill_count[3];
		my_heal = pitchu_skill_count[4];
	}
	else if (strcmp(my_character, "이상해씨") == 0) {
		my_skill1 = seed_skill_count[0];
		my_skill2 = seed_skill_count[1];
		my_skill3 = seed_skill_count[2];
		my_skill4 = seed_skill_count[3];
		my_heal = seed_skill_count[4];
	}
	else if (strcmp(my_character, "파이리") == 0) {
		my_skill1 = piri_skill_count[0];
		my_skill2 = piri_skill_count[1];
		my_skill3 = piri_skill_count[2];
		my_skill4 = piri_skill_count[3];
		my_heal = piri_skill_count[4];
	}
	else {
		my_skill1 = kobuk_skill_count[0];
		my_skill2 = kobuk_skill_count[1];
		my_skill3 = kobuk_skill_count[2];
		my_skill4 = kobuk_skill_count[3];
		my_heal = kobuk_skill_count[4];
	}
}

void your_skill_count(void) {
	if (strcmp(your_character, "피츄") == 0) {
		your_skill1 = pitchu_skill_count[0];
		your_skill2 = pitchu_skill_count[1];
		your_skill3 = pitchu_skill_count[2];
		your_skill4 = pitchu_skill_count[3];
		your_heal = pitchu_skill_count[4];
	}
	else if (strcmp(your_character, "이상해씨") == 0) {
		your_skill1 = seed_skill_count[0];
		your_skill2 = seed_skill_count[1];
		your_skill3 = seed_skill_count[2];
		your_skill4 = seed_skill_count[3];
		your_heal = seed_skill_count[4];
	}
	else if (strcmp(your_character, "파이리") == 0) {
		your_skill1 = piri_skill_count[0];
		your_skill2 = piri_skill_count[1];
		your_skill3 = piri_skill_count[2];
		your_skill4 = piri_skill_count[3];
		your_heal = piri_skill_count[4];
	}
	else {
		your_skill1 = kobuk_skill_count[0];
		your_skill2 = kobuk_skill_count[1];
		your_skill3 = kobuk_skill_count[2];
		your_skill4 = kobuk_skill_count[3];
		your_heal = kobuk_skill_count[4];
	}
}

void pick_my_turn(void) {
	if (strcmp(my_character, "피츄") == 0) {
		pitchu_turn();
	}
	else if (strcmp(my_character, "이상해씨") == 0) {
		seed_turn();
	}
	else if (strcmp(my_character, "파이리") == 0) {
		piri_turn();
	}
	else {
		kobuk_turn();
	}
}

void pick_your_turn(void) {
	if (strcmp(your_character, "피츄") == 0) {
		pitchu_turn();
	}
	else if (strcmp(your_character, "이상해씨") == 0) {
		seed_turn();
	}
	else if (strcmp(your_character, "파이리") == 0) {
		piri_turn();
	}
	else {
		kobuk_turn();
	}
}

void pitchu_turn(void) {
	int i, k, skill = 0;
	int random;
	srand((unsigned)time(NULL));
	random = rand() % 4;

	turn_mory_skill();
	turn_mory_HP();
	current_status();
	
	if (menu_choice == 1 && turn == 1) {
		if (status == 1) {
			if (heal == 0) {
				printf("치료약을 모두 사용해 더 이상 쓸 수 없습니다!\n");
				scanf("%c", &next1);
				printf("%s가 쓰러졌다\n%s의 승리!\n", your_character, my_character);
				scanf("%c", &next1);
				printf("%s님이 승리하셨습니다.", my_name);
				exit(0);
			}
			else {
				printf("치료약을 사용하여 이상 상태(화상, 마비)를 치료하였다!\n");
				scanf("%c", &next1);
				printf("상태 이상 회복!\n");
				scanf("%c", &next1);
				status = 0;
				heal--;
				save_current_status();
			}
		}
		else {
			if (random == 0) {
				if (skill1 == 0) {
					pitchu_turn();
				}
				else {
					p1();
					skill1--;
				}
			}
			else if (random == 1) {
				if (skill2 == 0) {
					pitchu_turn();
				}
				else {
					p2();
					skill2--;
				}
			}
			else if (random == 2) {
				if (skill3 == 0) {
					pitchu_turn();
				}
				else {
					p3();
					skill3--;
				}
			}
			else {
				if(skill4 == 0){
					pitchu_turn();
				}
				else {
					p4();
					skill4--;
				}
			}
		}
	}
	else {
		printf("1. 기술을 쓴다\n2. 치료약을 쓴다\n3. 기술 정보를 확인한다\n\n피츄는 무엇을 할까?: ");
		scanf("%d", &i);
		printf("\n");
		scanf("%c", &next1);

		if (status == 1) {
			if (i == 1) {
				printf("이상 상태(화상, 마비 등)로 인해 스킬 사용이 불가하다\n");
				printf("치료약을 쓰면 이상 상태에서 벗어날 수 있다\n");
				scanf("%c", &next1);
				pitchu_turn();
			}
			else if (i == 2) {
				if (heal == 0) {
					printf("치료약을 모두 사용해 더 이상 쓸 수 없습니다!");
					scanf("%c", &next1);
					if (turn == 0) {
						printf("%s가 쓰러졌다\n%s의 승리!\n", my_character, your_character);
						scanf("%c", &next1);
						printf("%s님이 승리하셨습니다.", your_name);
						exit(0);
					}
					else {
						printf("%s가 쓰러졌다\n%s의 승리!\n", your_character, my_character);
						scanf("%c", &next1);
						printf("%s님이 승리하셨습니다.", my_name);
						exit(0);
					}
				}
				else {
					printf("치료약을 사용하여 이상 상태(화상, 마비)를 치료하였다!\n");
					scanf("%c", &next1);
					printf("상태 이상 회복!\n");
					scanf("%c", &next1);
					status = 0;
					heal--;
					save_current_status();
				}
			}
			else if( i == 3) {
				printf("기술 정보 확인!\n");
				printf("1. 박치기: 머리를 내밀고 무작정 돌진하여 공격한다. 가끔 풀죽게 만든다. 나무를 흔들어 포켓몬을 떨어뜨릴 수도 있다.\n\n");
				printf("2. 번개펀치:전격을 담은 펀치로 상대를 공격한다. 50%% 확률로 상대 포켓몬을 화상입힐 수 있다.\n\n");
				printf("3. 볼 부비부비 :전기가 흐르는 볼을 비벼서 공격한다.  랜덤으로 연속 공격이 가능하다. \n\n");
				printf("4. 10만볼트: 강한 전격을 상대에게 날려서 공격한다. 상대를 90%% 확률로 마비시킬 수 있다.\n\n");
				printf("메인 화면으로 돌아간다...\n");
				scanf("%c", &next1);
				pitchu_turn();
			}
			else {
				pitchu_turn();
			}
		}
		else {
			if (i == 1) {
				printf("기술 시전!\n");
				scanf("%c", &next1);
				printf("1. 박치기(pp %d/5)\n2. 번개펀치(pp %d/5)\n3. 볼 부비부비(pp %d/2)\n4. 10만볼트(pp %d/1)\n", skill1, skill2, skill3, skill4);
				printf("뒤로 가시려면 1~4이외의 숫자를 입력하세요\n");
				printf("어떤 기술을 사용할까?: ");
				scanf("%d", &skill);
				printf("\n");
				scanf("%c", &next1);

				if (skill == 1) {
					if (skill1 == 0) {
						printf("이 스킬은 더 이상 쓸 수 없습니다!(스킬 소진)\n");
						scanf("%c", &next1);
						pitchu_turn();
					}
					else {
						p1();
						skill1--;
					}
				}
				else if (skill == 2) {
					if (skill2 == 0) {
						printf("이 스킬은 더 이상 쓸 수 없습니다!(스킬 소진)\n");
						scanf("%c", &next1);
						pitchu_turn();
					}
					else {
						p2();
						skill2--;
					}
				}
				else if (skill == 3) {
					if (skill3 == 0) {
						printf("이 스킬은 더 이상 쓸 수 없습니다!(스킬 소진)\n");
						scanf("%c", &next1);
						pitchu_turn();
					}
					else {
						p3();
						skill3--;
					}
				}
				else if (skill == 4) {
					if (skill4 == 0) {
						printf("이 스킬은 더 이상 쓸 수 없습니다!(스킬 소진)\n");
						scanf("%c", &next1);
						pitchu_turn();
					}
					else {
						p4();
						skill4--;
					}
				}
			}
			else if (i == 2) {
				printf("상처약(%d/1개)\n", heal);
				printf("뒤로 가시려면 1이외의 문자나 숫자를 입력해 잘못된 입력을 하세요\n");
				scanf("%d", &k);
				if (k == 1) {
					if (heal == 0) {
						printf("치료약을 모두 사용해 더 이상 쓸 수 없습니다!\n");
						pitchu_turn();
					}
					else {
						printf("상처약을 사용했다!\n");
						scanf("%c", &next1);
						status = 0;
						heal--;
						save_current_status();
					}
				}
				else {
					printf("잘못 입력하셨습니다!\n");
					scanf("%c", &next1);
					pitchu_turn();
				}
			}
			else if( i == 3) {
				printf("기술 정보 확인!\n");
				printf("1. 박치기: 머리를 내밀고 무작정 돌진하여 공격한다. 가끔 풀죽게 만든다. 나무를 흔들어 포켓몬을 떨어뜨릴 수도 있다.\n\n");
				printf("2. 번개펀치:전격을 담은 펀치로 상대를 공격한다. 50%% 확률로 상대 포켓몬을 화상입힐 수 있다.\n\n");
				printf("3. 볼 부비부비 :전기가 흐르는 볼을 비벼서 공격한다.  랜덤으로 연속 공격이 가능하다. \n\n");
				printf("4. 10만볼트: 강한 전격을 상대에게 날려서 공격한다. 상대를 90%% 확률로 마비시킬 수 있다.\n\n");
				printf("메인 화면으로 돌아간다...\n");
				scanf("%c", &next1);
				pitchu_turn();
			}
			else {
				pitchu_turn();
			}
		}
	}
	save_mory_skill();
	save_mory_HP();
}

void seed_turn(void) {
	int i, k, skill = 0;
	int random = 0;

	turn_mory_skill();
	turn_mory_HP();
	current_status();

	if (menu_choice == 1 && turn == 1) {
		srand((unsigned)time(NULL));
		random = rand() % 4;

		if (status == 1) {
			if (heal == 0) {
				printf("치료약을 모두 사용해 더 이상 쓸 수 없습니다!\n");
				scanf("%c", &next1);
				printf("%s가 쓰러졌다\n%s의 승리!\n", your_character, my_character);
				scanf("%c", &next1);
				printf("%s님이 승리하셨습니다.", my_name);
				exit(0);
			}
			else {
				printf("치료약을 사용하여 이상 상태(화상, 마비)를 치료하였다!\n");
				scanf("%c", &next1);
				printf("상태 이상 회복!\n");
				scanf("%c", &next1);
				status = 0;
				heal--;
				save_current_status();
			}
		}
		else {
			if (random == 0) {
				if (skill1 == 0) {
					seed_turn();
				}
				else {
					s1();
					skill1--;
				}
			}
			else if (random == 1) {
				if (skill2 == 0) {
					seed_turn();
				}
				else {
					s2();
					skill2--;
				}
			}
			else if (random == 2) {
				if (skill3 == 0) {
					seed_turn();
				}
				else {
					s3();
					skill3--;
				}
			}
			else if (random == 3) {
				if (skill4 == 0) {
					seed_turn();
				}
				else {
					s4();
					skill4--;
				}
			}
		}
	}
	else {
		printf("1. 기술을 쓴다\n2. 치료약을 쓴다\n3. 기술 정보를 확인한다\n\n이상해씨는 무엇을 할까?: ");
		scanf("%d", &i);
		printf("\n");
		scanf("%c", &next1);

		if (status == 1) {
			if (i == 1) {
				printf("이상 상태(화상, 마비 등)로 인해 스킬 사용이 불가하다\n");
				printf("치료약을 쓰면 이상 상태에서 벗어날 수 있다\n");
				scanf("%c", &next1);
				seed_turn();
			}
			else if( i == 2 ) {
				if (heal == 0) {
					printf("치료약을 모두 사용해 더 이상 쓸 수 없습니다!\n");
					scanf("%c", &next1);
					if (turn == 0) {
						printf("%s가 쓰러졌다\n%s의 승리!\n", my_character, your_character);
						scanf("%c", &next1);
						printf("%s님이 승리하셨습니다.", your_name);
						exit(0);
					}
					else {
						printf("%s가 쓰러졌다\n%s의 승리!\n", your_character, my_character);
						scanf("%c", &next1);
						printf("%s님이 승리하셨습니다.", my_name);
						exit(0);
					}
				}
				else {
					printf("치료약을 사용하여 이상 상태(화상, 마비)를 치료하였다!\n");
					scanf("%c", &next1);
					printf("상태 이상 회복!\n");
					scanf("%c", &next1);
					status = 0;
					heal--;
					save_current_status();
				}
			}
			else if (i == 3) {
				printf("기술 정보 확인!\n");
				scanf("%c", &next1);
				printf("1. 풀묶기: 풀을 휘감아서 상대를 쓰러뜨린다. 상대가 무거울수록 위력이 올라간다.\n\n");
				printf("2. 덩쿨채찍: 채찍처럼 휘어지는 가늘고 긴 덩굴로 상대를 힘껏 쳐서 공격한다. \n\n");
				printf("3. 잎날가르기:연속으로 잎사귀를 날려 상대를 베어 공격한다. 급소에 맞을 확률이 높다.\n\n");
				printf("4. 광합성: 자신의 HP를 회복한다. 날씨에 따라 회복량이 변한다.\n\n");
				printf("메인 화면으로 돌아간다....\n");
				scanf("%c", &next1);
				seed_turn();
			}
			else {
				seed_turn();
			}
		}
		else {
			if (i == 1) {
				printf("기술 시전!\n");
				scanf("%c", &next1);
				printf("1. 풀묶기(pp %d/5)\n2. 덩쿨채찍(pp %d/5)\n3. 잎날가르기(pp %d/2)\n4. 광합성(pp %d/1)\n", skill1, skill2, skill3, skill4);
				printf("뒤로 가시려면 1~4이외의 숫자를 입력하세요\n");
				printf("어떤 기술을 사용할까?: ");
				scanf("%d", &skill);
				printf("\n");
				scanf("%c", &next1);

				if (skill == 1) {
					if (skill1 == 0) {
						printf("이 스킬은 더 이상 쓸 수 없습니다!(스킬 소진)\n");
						scanf("%c", &next1);
						seed_turn();
					}
					else {
						s1();
						skill1--;
					}
				}
				else if (skill == 2) {
					if (skill2 == 0) {
						printf("이 스킬은 더 이상 쓸 수 없습니다!(스킬 소진)\n");
						scanf("%c", &next1);
						seed_turn();
					}
					else {
						s2();
						skill2--;
					}
				}
				else if (skill == 3) {
					if (skill3 == 0) {
						printf("이 스킬은 더 이상 쓸 수 없습니다!(스킬 소진)\n");
						scanf("%c", &next1);
						seed_turn();
					}
					else {
						s3();
						skill3--;
					}
				}
				else if (skill == 4) {
					if (skill4 == 0) {
						printf("이 스킬은 더 이상 쓸 수 없습니다!(스킬 소진)\n");
						scanf("%c", &next1);
						seed_turn();
					}
					else {
						s4();
						skill4--;
					}
				}
			}
			else if (i == 2) {

				printf("상처약(%d/1개)\n", heal);
				printf("뒤로 가시려면 1이외의 문자나 숫자를 입력해 잘못된 입력을 하세요\n");
				scanf("%d", &k);
				if (k == 1) {
					if (heal == 0) {
						printf("치료약을 모두 사용해 더 이상 쓸 수 없습니다!");
						scanf("%c", &next1);
						seed_turn();
					}
					else {
						printf("상처약을 사용했다!\n");
						scanf("%c", &next1);
						status = 0;
						heal--;
						save_current_status();
					}
				}
				else {
					printf("잘못 입력하셨습니다!\n");
					scanf("%c", &next1);
					seed_turn();
				}
			}
			else if (i == 3) {
				printf("기술 정보 확인!\n");
				scanf("%c", &next1);
				printf("1. 풀묶기: 풀을 휘감아서 상대를 쓰러뜨린다. 상대가 무거울수록 위력이 올라간다.\n\n");
				printf("2. 덩쿨채찍: 채찍처럼 휘어지는 가늘고 긴 덩굴로 상대를 힘껏 쳐서 공격한다. \n\n");
				printf("3. 잎날가르기:연속으로 잎사귀를 날려 상대를 베어 공격한다. 급소에 맞을 확률이 높다.\n\n");
				printf("4. 광합성: 자신의 HP를 회복한다. 날씨에 따라 회복량이 변한다.\n\n");
				printf("메인 화면으로 돌아간다....\n");
				scanf("%c", &next1);
				seed_turn();
			}
			else {
				seed_turn();
			}
		}
	}
	save_mory_skill();
	if (skill != 4 && random != 3)
		save_mory_HP();
}

void piri_turn(void) {
	int i, k, j, skill = 0;
	int random;

	srand((unsigned)time(NULL));
	random = rand() % 4;

	turn_mory_skill();
	turn_mory_HP();
	current_status();

	if (menu_choice == 1 && turn == 1) {
		if (status == 1) {
			if (skill4 == 0 && heal == 0) {
				printf("치료약을 모두 사용해 더 이상 쓸 수 없습니다!\n");
				scanf("%c", &next1);
				printf("%s가 쓰러졌다\n%s의 승리!\n", your_character, my_character);
				scanf("%c", &next1);
				printf("%s님이 승리하셨습니다.", my_name);
				exit(0);
			}
			else if (skill4 == 0 && heal != 0){
				printf("치료약을 사용하여 이상 상태(화상, 마비)를 치료하였다!\n");
				scanf("%c", &next1);
				printf("상태 이상 회복!\n");
				scanf("%c", &next1);
				status = 0;
				heal--;
				save_current_status();
			}
			else {
				l4();
				skill4--;
			}
		}
		else {
			if (random == 0) {
				if (skill1 == 0) {
					piri_turn();
				}
				else {
					l1();
					skill1--;
				}
			}
			else if (random == 1) {
				if (skill2 == 0) {
					piri_turn();
				}
				else {
					l2();
					skill2--;
				}
			}
			else if (random == 2) {
				if (skill3 == 0) {
					piri_turn();
				}
				else {
					l3();
					skill3--;
				}
			}
			else {
				if (skill4 == 0) {
					piri_turn();
				}
				else {
					l4();
					skill4--;
				}
			}
		}
	}

	else {
		printf("1. 기술을 쓴다\n2. 치료약을 쓴다\n3. 기술 정보를 확인한다\n\n파이리는 무엇을 할까?: ");
		scanf("%d", &i);
		printf("\n");
		scanf("%c", &next1);

		if (status == 1) {
			if (i == 1) {
				printf("이상 상태(화상, 마비 등)로 인해 객기만 사용 가능하다\n");
				printf("객기를 사용하려면 1을 입력하라(메뉴창으로 돌아가기: 1 이외의 수 입력)");
				scanf("%d", &j);
				if (j == 1) {
					if (skill4 == 0) {
						printf("객기를 모두 사용하여 스킬 사용이 불가하다!\n");
						scanf("%c", &next1);
						piri_turn();
					}
					else {
						l4();
						skill4--;
					}
				}
				else {
					piri_turn();
				}
			}
			else if (i == 2) {
				if (heal == 0) {
					printf("치료약을 모두 사용해 더 이상 쓸 수 없습니다!\n");
					scanf("%c", &next1);
					if (turn == 0) {
						printf("%s가 쓰러졌다\n%s의 승리!\n", my_character, your_character);
						scanf("%c", &next1);
						printf("%s님이 승리하셨습니다.", your_name);
						exit(0);
					}
					else {
						printf("%s가 쓰러졌다\n%s의 승리!\n", your_character, my_character);
						scanf("%c", &next1);
						printf("%s님이 승리하셨습니다.", my_name);
						exit(0);
					}
				}
				else {
					printf("치료약을 사용하여 이상 상태(화상, 마비)를 치료하였다!\n");
					scanf("%c", &next1);
					printf("상태 이상 회복!\n");
					scanf("%c", &next1);
					status = 0;
					heal--;
					save_current_status();
				}
			}
			else if (i == 3) {
				printf("기술 정보 확인!\n");
				printf("1. 불대문자: 큰 대자의 불꽃으로 상대를 불태운다, 30퍼센트 확률로 화상상태로 만든다.\n\n");
				printf("2. 철판방패: 60퍼센트 확률로 상대방을 공격하고 상대방의 다음 공격을 방어한다\n\n");
				printf("3. 회오리문자: 불꽃 속에 5턴 동안 상대를 가두어 공격한다\n\n");
				printf("4. 객기: 자신이 독, 마비, 화상 상태일 때 날리면 기술의 위력이 2배가 된다.\n\n");
				printf("메인 화면으로 돌아간다...\n");
				scanf("%c", &next1);
				piri_turn();
			}
			else {
				piri_turn();
			}
		}
		else {
			if (i == 1) {
				printf("기술 시전!\n");
				scanf("%c", &next1);
				printf("1. 불대문자(pp %d/5)\n2. 방어(pp %d/1)\n3. 회오리 문자(pp %d/2)\n4. 객기(pp %d/1)\n", skill1, skill2, skill3, skill4);
				printf("뒤로 가시려면 1~4이외의 숫자를 입력하세요\n");
				printf("어떤 기술을 사용할까?: ");
				scanf("%d", &skill);
				printf("\n");
				scanf("%c", &next1);
				if (skill == 1) {
					if (skill1 == 0) {
						printf("이 스킬은 더 이상 쓸 수 없습니다!(스킬 소진)\n");
						scanf("%c", &next1);
						piri_turn();
					}
					else {
						l1();
						skill1--;
					}
				}
				else if (skill == 2) {
					if (skill2 == 0) {
						printf("이 스킬은 더 이상 쓸 수 없습니다!(스킬 소진)\n");
						scanf("%c", &next1);
						piri_turn();
					}
					else {
						l2();
						skill2--;
					}
				}
				else if (skill == 3) {
					if (skill3 == 0) {
						printf("이 스킬은 더 이상 쓸 수 없습니다!(스킬 소진)\n");
						scanf("%c", &next1);
						piri_turn();
					}
					else {
						l3();
						skill3--;
					}
				}
				else if (skill == 4) {
					if (skill4 == 0) {
						printf("이 스킬은 더 이상 쓸 수 없습니다!(스킬 소진)\n");
						scanf("%c", &next1);
						piri_turn();
					}
					else {
						l4();
						skill4--;
					}
				}
			}
			else if (i == 2) {
				printf("상처약(%d/1개)\n", heal);
				printf("뒤로 가시려면 1이외의 문자나 숫자를 입력해 잘못된 입력을 하세요\n");
				scanf("%d", &k);
				if (k == 1) {
					if (heal == 0) {
						printf("치료약을 모두 사용해 더 이상 쓸 수 없습니다!");
						scanf("%c", &next1);
						piri_turn();
					}
					else {
						printf("상처약을 사용했다!\n");
						scanf("%c", &next1);
						status = 0;
						heal--;
						save_current_status();
					}
				}
				else {
					printf("잘못 입력하셨습니다!\n");
					scanf("%c", &next1);
					piri_turn();
				}
			}
			else if (i == 3) {
				printf("기술 정보 확인!\n");
				printf("1. 불대문자: 큰 대자의 불꽃으로 상대를 불태운다, 30퍼센트 확률로 화상상태로 만든다.\n\n");
				printf("2. 철판방패: 60퍼센트 확률로 상대방을 공격하고 상대방의 다음 공격은 방어한다\n\n");
				printf("3. 회오리문자: 불꽃 속에 5턴 동안 상대를 가두어 공격한다\n\n");
				printf("4. 객기: 자신이 독, 마비, 화상 상태일 때 날리면 기술의 위력이 2배가 된다.\n\n");
				printf("메인 화면으로 돌아간다...\n");
				scanf("%c", &next1);
				piri_turn();
			}
			else {
				piri_turn();
			}
		}
	}
	save_mory_skill();
	save_mory_HP();
}

void kobuk_turn(void) {
	int i, k, skill = 0;
	int random;

	srand((unsigned)time(NULL));
	random = rand() % 4;

	turn_mory_skill();
	turn_mory_HP();
	current_status();

	if (menu_choice == 1 && turn == 1) {
		if (status == 1) {
			if (heal == 0) {
				printf("치료약을 모두 사용해 더 이상 쓸 수 없습니다!");
				scanf("%c", &next1);
				printf("%s가 쓰러졌다\n%s의 승리!\n", your_character, my_character);
				scanf("%c", &next1);
				printf("%s님이 승리하셨습니다.", my_name);
				exit(0);
			}
			else {
				printf("치료약을 사용하여 이상 상태(화상, 마비)를 치료하였다!\n");
				scanf("%c", &next1);
				printf("상태 이상 회복!\n");
				scanf("%c", &next1);
				status = 0;
				heal--;
				save_current_status();
			}
		}
		else {
			if (random == 0) {
				if (skill1 == 0) {
					kobuk_turn();
				}
				else {
					k1();
					skill1--;
				}
			}
			else if (random == 1) {
				if (skill2 == 0) {
					kobuk_turn();
				}
				else {
					k2();
					skill2--;
				}
			}
			else if (random == 2) {
				if (skill3 == 0) {
					kobuk_turn();
				}
				else {
					k3();
					skill3--;
				}
			}
			else {
				if (skill4 == 0) {
					kobuk_turn();
				}
				else {
					k4();
					skill4--;
				}
			}	
		}
	}
	else {
		printf("1. 기술을 쓴다\n2. 치료약을 쓴다\n3. 기술 정보를 확인한다\n\n꼬부기는 무엇을 할까?: ");
		scanf("%d", &i);
		printf("\n");
		scanf("%c", &next1);

		if (status == 1) {
			if (i == 1) {
				printf("이상 상태(화상, 마비 등)로 인해 스킬 사용이 불가하다\n");
				printf("치료약을 쓰면 이상 상태에서 벗어날 수 있다\n");
				scanf("%c", &next1);
				kobuk_turn();
			}
			else if(i == 2){
				if (heal == 0) {
					printf("치료약을 모두 사용해 더 이상 쓸 수 없습니다!\n");
					scanf("%c", &next1);
					if (turn == 0) {
						printf("%s가 쓰러졌다\n%s의 승리!\n", my_character, your_character);
						scanf("%c", &next1);
						printf("%s님이 승리하셨습니다.", your_name);
						exit(0);
					}
					else {
						printf("%s가 쓰러졌다\n%s의 승리!\n", your_character, my_character);
						scanf("%c", &next1);
						printf("%s님이 승리하셨습니다.", my_name);
						exit(0);
					}
				}
				else {
					printf("치료약을 사용하여 이상 상태(화상, 마비)를 치료하였다!\n");
					scanf("%c", &next1);
					printf("상태 이상 회복!\n");
					scanf("%c", &next1);
					status = 0;
					heal--;
					save_current_status();
				}
			}
			else if (i == 3) {
				printf("기술 정보 확인!\n");
				printf("1. 아쿠아테일: 세차게 날뛰는 거친 파도와 같이 큰 꼬리를 흔들어서 공격한다.\n\n");
				printf("2. 소금물: 상대가 HP의 절반 정도 상처를 입고 있으면 기술의 위력이 2배가 된다.\n\n");
				printf("3. 열탕: 뜨겁게 끓어오르는 물을 상대에게 발사해서 공격한다. 50%% 확률로 화상 상태로 만들 때가 있다.\n\n");
				printf("4. 비바라기:5턴 동안 비를 내리게 하여 물타입 기술의 위력을 올린다..\n\n");
				printf("메인 화면으로 돌아간다...\n");
				scanf("%c", &next1);
				kobuk_turn();
			}
			else {
				kobuk_turn();
			}
		}
		else {
			if (i == 1) {
				printf("기술 시전!\n");
				scanf("%c", &next1);
				printf("1. 아쿠아테일(pp %d/5)\n2. 소금물(pp %d/5)\n3. 열탕(pp %d/2)\n4. 비바라기(pp %d/1)\n", skill1, skill2, skill3, skill4);
				printf("뒤로 가시려면 1~4이외의 숫자를 입력하세요\n");
				printf("어떤 기술을 사용할까?: ");
				scanf("%d", &skill);
				printf("\n");
				scanf("%c", &next1);


				if (skill == 1) {
					if (skill1 == 0) {
						printf("이 스킬은 더 이상 쓸 수 없습니다!(스킬 소진)\n");
						scanf("%c", &next1);
						kobuk_turn();
					}
					else {
						k1();
						skill1--;
					}
				}
				else if (skill == 2) {
					if (skill2 == 0) {
						printf("이 스킬은 더 이상 쓸 수 없습니다!(스킬 소진)\n");
						scanf("%c", &next1);
						kobuk_turn();
					}
					else {
						k2();
						skill2--;
					}
				}
				else if (skill == 3) {
					if (skill3 == 0) {
						printf("이 스킬은 더 이상 쓸 수 없습니다!(스킬 소진)\n");
						scanf("%c", &next1);
						kobuk_turn();
					}
					else {
						k3();
						skill3--;
					}
				}
				else if (skill == 4) {
					if (skill4 == 0) {
						printf("이 스킬은 더 이상 쓸 수 없습니다!(스킬 소진)\n");
						scanf("%c", &next1);
						kobuk_turn();
					}
					else {
						k4();
						skill4--;
					}
				}
			}
			else if (i == 2) {
				printf("상처약(%d/1개)\n", heal);
				printf("뒤로 가시려면 1이외의 문자나 숫자를 입력해 잘못된 입력을 하세요\n");
				scanf("%d", &k);
				if (k == 1) {
					if (heal == 0) {
						printf("치료약을 모두 사용해 더 이상 쓸 수 없습니다!");
						scanf("%c", &next1);
						kobuk_turn();
					}
					else {
						printf("상처약을 사용했다!\n");
						status = 0;
						heal--;
						scanf("%c", &next1);
						save_current_status();
					}
				}
				else {
					printf("잘못 입력하셨습니다!\n");
					scanf("%c", &next1);
					kobuk_turn();
				}
			}
			else if(i==3){
				printf("기술 정보 확인!\n");
				printf("1. 아쿠아테일: 세차게 날뛰는 거친 파도와 같이 큰 꼬리를 흔들어서 공격한다.\n\n");
				printf("2. 소금물: 상대가 HP의 절반 정도 상처를 입고 있으면 기술의 위력이 2배가 된다.\n\n");
				printf("3. 열탕: 뜨겁게 끓어오르는 물을 상대에게 발사해서 공격한다. 50%% 확률로 화상 상태로 만들 때가 있다.\n\n");
				printf("4. 비바라기:5턴 동안 비를 내리게 하여 물타입 기술의 위력을 올린다..\n\n");
				printf("메인 화면으로 돌아간다...\n");
				scanf("%c", &next1);
				kobuk_turn();
			}
			else {
				kobuk_turn();
			}
		}
	}
	save_mory_skill();
	save_mory_HP();
}

void p1() //피츄의 박치기
{
	int damage, percentage;

	printf("피츄의 박치기 공격!\n");
	scanf("%c", &next1);

	damage = 30;
	percentage = 1 + rand() % 100;

	turn_mory_character();

	if (percentage <= 80) //80%
	{
		printf("%s는(은) %d의 데미지를 입었다!\n", turn_character, damage);
		scanf("%c", &next1);
		HP -= damage;
	}
	else
	{
		printf("그러나 빗나갔다!\n");
		scanf("%c", &next1);
	}
}

void p2() //피츄의 번개펀치
{
	int damage, percentage, burns_percentage;

	printf("피츄의 번개펀치 공격!\n");
	scanf("%c", &next1);

	percentage = 1 + rand() % 100;
	burns_percentage = 1 + rand() % 100;
	damage = 40;

	turn_mory_character();
	turn_mory_status();

	if (percentage <= 80) //80%
	{
		printf("%s는(은) %d의 데미지를 입었다!\n", turn_character, damage);
		scanf("%c", &next1);
		HP -= damage;
		if (burns_percentage <= 50) {
			printf("%s는(은) 화상에 걸렸다!\n", turn_character);
			status = 1;
		}
	}
	else
	{
		printf("그러나 빗나갔다!\n");
		scanf("%c", &next1);
	}
	save_mory_status();
}

void p3() //볼 부비부비
{
	int damage, percentage, num, total_damage;

	printf("피츄의 볼 부비부비 공격!\n");
	scanf("%c", &next1);

	srand((unsigned)time(NULL));

	damage = 15;
	percentage = 1 + rand() % 65; //65%의 확률
	num = rand() % 3 + 2; //2~4번 랜덤

	turn_mory_character();

	if (percentage <= 65)
	{
		total_damage = damage * num;
		printf("%s는(은) %d의 데미지를 입었다!\n", turn_character, total_damage);
		scanf("%c", &next1);
		HP -= total_damage;
	}
	else
	{
		printf("그러나 빗나갔다!\n");
		scanf("%c", &next1);
	}
}

void p4() //10만볼트
{
	int damage, percentage, paralysis_percentage;

	printf("피츄의 10만 볼트 공격!\n");
	scanf("%c", &next1);

	damage = 50;
	percentage = 1 + rand() % 100;
	paralysis_percentage = 1 + rand() % 100;

	turn_mory_character();
	turn_mory_status();

	if (percentage <= 90) //90%
	{
		printf("%s는(은) %d의 데미지를 입었다!\n", turn_character, damage);
		scanf("%c", &next1);
		HP -= damage;
		if (paralysis_percentage <= 90) //마비확률 80%
		{
			printf("%s는(은) 마비에 걸렸다!\n", turn_character);
			scanf("%c", &next1);
			status = 1;
		}
	}
	else
	{
		printf("그러나 빗나갔다!\n");
		scanf("%c", &next1);
	}
	save_mory_status();
}

void s1() //이상해씨의 풀묶기
{
	int damage, percentage;
	printf("이상해씨의 풀묶기 공격!\n");
	scanf("%c", &next1);

	damage = 40;
	percentage = 1 + rand() % 100;

	turn_mory_character();

	if (percentage <= 80) //80%
	{
		printf("%s는(은) %d의 데미지를 입었다!\n", turn_character, damage);
		scanf("%c", &next1);
		HP -= damage;
	}
	else
	{
		printf("그러나 빗나갔다!\n");
		scanf("%c", &next1);
	}
}

void s2() //이상해씨의 덩굴 채찍
{
	int damage, percentage;

	printf("이상해씨의 덩굴 채찍 공격!\n");
	scanf("%c", &next1);

	damage = 30;
	percentage = 1 + rand() % 100;

	turn_mory_character();

	if (percentage <= 80) //80%
	{
		printf("%s는(은) %d의 데미지를 입었다!\n", turn_character, damage);
		scanf("%c", &next1);
		HP -= damage;
	}
	else
	{
		printf("그러나 빗나갔다!\n");
		scanf("%c", &next1);
	}
}

void s3() //이상해풀의 연속 잎날가르기
{
	int damage, percentage, i;

	printf("이상해풀의 연속 잎날가르기!\n");
	scanf("%c", &next1);

	turn_mory_character();

	for (i = 1; i <= 5; i++)
	{
		percentage = 1 + rand() % 100;
		if (percentage <= 55)  //55%의 확률
		{
			printf("%d회차 성공!\n", i);
			damage = 10 + rand() % 6; //10~16
			printf("%s는(은) %d의 데미지를 입었다!\n", turn_character, damage);
			HP -= damage;
		}
		else {
			printf("%d회차 실패!\n", i);

		}
		printf("\n");
	}
}

void s4() //이상해풀의 광합성
{
	int recover, percentage, weather;

	printf("이상해씨의 광합성!\n");
	scanf("%c", &next1);
	percentage = 1 + rand() % 100;
	weather = rand() % 3 + 1;

	turn_mory_character();
	recover_mory_HP();

	if (percentage <= 90) //90%
	{
		if (weather == 1)
		{
			printf("날씨는 평상시와 같다!\n");
			recover = 50;
		}
		else if (weather == 2)
		{
			printf("날씨는 쾌청하다! 회복 효과가 더 좋아졌다.\n");
			recover = 100;
		}
		else
		{
			printf("날씨가 흐리다.\n");
			recover = 25;
		}
		printf("이상해씨는 %d만큼의 체력을 회복했다!\n", recover);
		scanf("%c", &next1);
		HP += recover;
		if (HP > 250) 
			HP = 250;
	}
	else
	{
		printf("그러나 실패했다!\n");
		scanf("%c", &next1);
	}
	resave_mory_HP();
}

void l1() //파이리의 불대문자
{
	int damage, percentage, burns_percentage;
	printf("파이리의 불대문자 공격!\n");
	scanf("%c", &next1);

	damage = 40;
	percentage = 1 + rand() % 100;
	burns_percentage = 1 + rand() % 100;

	turn_mory_character();
	turn_mory_status();

	if (percentage <= 90) //90%
	{
		printf("%s는(은) %d의 데미지를 입었다!\n", turn_character, damage);
		scanf("%c", &next1);
		HP -= damage;
		if (burns_percentage <= 30) //화상 확률 30%
		{
			printf("%s는(은) 화상에 걸렸다!\n", turn_character);
			scanf("%c", &next1);
			status = 1;
		}
	}
	else
	{
		printf("그러나 빗나갔다!\n");
		scanf("%c", &next1);
	}
	save_mory_status();
}

void l2() //파이리의 철판방패
{
	int damage, percentage;
	printf("파이리의 철판방패!\n");
	scanf("%c", &next1);

	damage = 30;
	percentage = 1 + rand() % 100;

	turn_mory_character();

	if (percentage <= 60) //60%
	{
		printf("%s는(은) %d의 데미지를 입었다!\n", turn_character, damage);
		scanf("%c", &next1);
		HP -= damage;
	}
	else
	{
		printf("공격에는 실패했다!\n");
		scanf("%c", &next1);
	}
	turn_mory_defense();
	printf("그러나 파이리는 바로 다음 상대의 공격을 막을 수 있다!\n"); //철판 방패: damage 깎는 것에 실패해도 방어기술은 항상 사용 가능
	scanf("%c", &next1);
	defense = 1;
	save_mory_defense();
}

void l3() //파이리의 회오리문자
{
	int damage[5];
	int percentage;
	int damage_total = 0;
	int i, combo = 0;

	printf("파이리의 회오리문자 공격!\n");
	scanf("%c", &next1);

	percentage = 1 + rand() % 100;

	turn_mory_character();

	for (i = 0; i < 5; i++)
	{
		if (percentage <= (85 - i * 5))
		{
			damage[i] = 1;
			combo = 13 + i;
			damage_total += damage[i] * combo;
		}
		else
		{	
			damage[i] = 0;
			break;
		}
	}
	printf("%d회 콤보 공격 성공!\n", i);
	printf("%s는 %d의 데미지를 입었다!\n", turn_character, damage_total);
	scanf("%c", &next1);
	HP -= damage_total;
}

void l4() //파이리의 객기(자신의 상태가 마비, 화상 상태일 때 기술의 위력이 2배)
{
	int damage, percentage;
	printf("파이리의 객기 공격!\n");
	scanf("%c", &next1);

	damage = 40;
	percentage = 1 + rand() % 100;

	turn_mory_character();

	if (percentage <= 80)
	{
		if (status == 0)
		{
			printf("%s는 %d의 데미지를 입었다!\n", turn_character, damage);
			scanf("%c", &next1);
			HP -= damage;
		}
		else
		{
			printf("%s는 %d의 데미지를 입었다!\n", turn_character, damage * 2);
			scanf("%c", &next1);
			HP -= damage * 2;
		}
	}
	else
	{
		printf("그러나 빗나갔다!\n");
		scanf("%c", &next1);
	}

}

void k1() //꼬부기의 아쿠아테일
{
	int damage, percentage;
	printf("꼬부기의 아쿠아테일 공격!\n");
	scanf("%c", &next1);

	damage = 40;
	percentage = 1 + rand() % 100;

	turn_mory_character();

	if (percentage <= 90) //90%
	{
		printf("%s는(은) %d의 데미지를 입었다!\n", turn_character, damage);
		scanf("%c", &next1);
		HP -= damage;
	}
	else
	{
		printf("그러나 빗나갔다!\n");
		scanf("%c", &next1);
	}
}

void k2() //꼬부기의 소금물
{
	int damage, percentage;
	printf("꼬부기의 소금물 공격!\n");
	scanf("%c", &next1);

	damage = 30;
	percentage = 1 + rand() % 100;

	turn_mory_character();

	if (percentage <= 80) //80%
	{
		if (HP <= 125)
		{
			printf("%s는 %d의 데미지를 입었다!\n", turn_character, damage * 2);
			scanf("%c", &next1);
			HP -= damage * 2;
		}
		else
		{
			printf("%s는 %d의 데미지를 입었다!\n", turn_character, damage);
			scanf("%c", &next1);
			HP -= damage;
		}
	}
	else
	{
		printf("그러나 빗나갔다!\n");
		scanf("%c", &next1);
	}
}

void k3() //열탕
{
	int damage, percentage, burns_percentage;
	printf("꼬부기의 열탕 공격!\n");
	scanf("%c", &next1);

	damage = 30;
	percentage = 1 + rand() % 100;
	burns_percentage = 1 + rand() % 100;

	turn_mory_character();
	turn_mory_status();

	if (percentage <= 90) //90%
	{
		printf("%s는(은) %d의 데미지를 입었다!\n", turn_character, damage);
		scanf("%c", &next1);
		HP -= damage;
		if (burns_percentage <= 50) //화상 확률 50%
		{
			printf("%s는(은) 화상에 걸렸다!\n", turn_character);
			scanf("%c", &next1);
			status = 1;
		}
	}
	else
	{
		printf("그러나 빗나갔다!\n");
		scanf("%c", &next1);
	}
	save_mory_status();
}

void k4() //비 바라기
{
	int damage[5];
	int percentage;
	int damage_total = 0;
	int i, combo = 0;

	printf("꼬부기의 비 바라기 공격!\n");
	scanf("%c", &next1);

	percentage = 1 + rand() % 100;

	turn_mory_character();

	for (i = 0; i < 5; i++)
	{
		if (percentage <= (80 - i * 10))
		{
			damage[i] = 1;
			combo = 15 + i;
			damage_total += damage[i] * combo;
		}
		else
		{
			damage[i] = 0;
			break;
		}
	}
	printf("%d회 콤보 공격 성공!\n", i);
	printf("%s는(은) 총 %d의 데미지를 입었다!\n", turn_character, damage_total);
	scanf("%c", &next1);
	HP -= damage_total;
}

void turn_mory_skill(void) {
	if (turn == 0) {
		skill1 = my_skill1;
		skill2 = my_skill2;
		skill3 = my_skill3;
		skill4 = my_skill4;
		heal = my_heal;
	}
	else {
		skill1 = your_skill1;
		skill2 = your_skill2;
		skill3 = your_skill3;
		skill4 = your_skill4;
		heal = your_heal;
	}
}

void save_mory_skill(void) {
	if (turn == 0) {
		my_skill1 = skill1;
		my_skill2 = skill2;
		my_skill3 = skill3;
		my_skill4 = skill4;
		my_heal = heal;
	}
	else {
		your_skill1 = skill1;
		your_skill2 = skill2;
		your_skill3 = skill3;
		your_skill4 = skill4;
		your_heal = heal;
	}
}

void turn_mory_status(void) {
	if (turn == 0)
		status = your_status;
	else
		status = my_status;
}

void save_mory_status(void) {
	if (turn == 0)
		your_status = status;
	else
		my_status = status;
}

void current_status(void) {
	if (turn == 0)
		status = my_status;
	else
		status = your_status;
}

void save_current_status(void) {
	if (turn == 0)
		my_status = status;
	else
		your_status = status;
}

void turn_mory_defense(void) {
	if (turn == 0)
		defense = my_defense;
	else
		defense = your_defense;
}

void save_mory_defense(void) {
	if (turn == 0)
		my_defense = defense;
	else
		your_defense = defense;
}

void turn_mory_HP(void) {
	if (turn == 0)
		HP = your_HP;
	else
		HP = my_HP;
}

void save_mory_HP(void) {
	if (turn == 0)
		your_HP = HP;
	else
		my_HP = HP;
}

void recover_mory_HP(void) {
	if (turn == 0)
		HP = my_HP;
	else
		HP = your_HP;
}

void resave_mory_HP(void) {
	if (turn == 0)
		my_HP = HP;
	else
		your_HP = HP;
}

void turn_mory_character(void) {
	if (turn == 0)
		strncpy(turn_character, your_character, sizeof(your_character));
	else
		strncpy(turn_character, my_character, sizeof(my_character));
}