#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h> //���ڿ� ���� �Լ� ���� ���� ��� ����
#include <time.h>

char my_name[10]; //������� �̸� �����ϴ� ����
char your_name[10]; //������ �̸� �����ϴ� ����
char my_character[10], your_character[10]; // ���� ĳ���� �̸�, ������ ĳ���� �̸�
char character[4][10] = { "����", "�̻��ؾ�", "���̸�", "���α�" }; //ĳ���� �̸� ����
char next1, next2; // enterŰ ������ ���� ��ȭâ �ߵ��� ����� ����
int turn;  //�� �ϰ� ���� ���� �˷��ִ� ����
int menu_choice;  //menu ����(1��. �����ϱ� or 2��. �ٸ� ����� ���)
int my_HP = 250, your_HP = 250; // ���� ü��(HP), ������ ü��(HP)-ü���� 0�̸� ���� �� 
int HP;
int my_status, your_status;  // ���� ����, ������ ����
int status = 0;
int my_defense, your_defense;  //���� ���, ������ ���
int defense;
char turn_character[10];  
int my_skill1, my_skill2, my_skill3, my_skill4, my_heal;  //�� ��� Ƚ�� ����
int your_skill1, your_skill2, your_skill3, your_skill4, your_heal;  //������ ��� Ƚ�� ����
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
		printf("1. �����ϱ�  2. �ٸ� ����ڿ��� ���\n");
		printf("� ���� �����Ͻðڽ��ϱ�?: ");
		scanf("%d", &menu_choice);
		scanf("%c%c", &next1, &next2);

		if (menu_choice == 1) {
			printf("�����ϱ⸦ �����ϼ̽��ϴ�!\n");
			scanf("%c", &next1);
			adventure();
			break;
		}
		else if (menu_choice == 2) {
			printf("�ٸ� ����ڿ��� ����� �����ϼ̽��ϴ�!\n");
			scanf("%c", &next1);
			match();
			break;
		}
		else {
			printf("�޴��� �ٽ� �����ϼ���!\n");
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
	printf("@@@@   �ؽ�Ʈ�� �ѱ���� ����Ű��(����Ű �� �� ������ �� ���� ����)\n");
	scanf("%c", &next1);
}

void adventure(void) {
	my_name_func();
	computer_name_func();
	strncpy(my_character, character[0], sizeof(character[0]));
	computer_character_func();
	printf("�߻��� %s�� ��Ÿ����!\n", your_character);
	scanf("%c", &next1);
	printf("���Ͷ� %s!\n", my_character);
	scanf("%c", &next1);
	printf("\n%s�� ü�� : %d/250     %s�� ü�� : %d/250\n\n", my_character, my_HP, your_character, your_HP);
	scanf("%c", &next1);
	battle();
}

void match(void) {
	my_name_func();
	my_character_func();
	your_name_func();
	your_character_func();
	printf("��: %s\tvs\t����: %s\t���!\n", my_character, your_character);
	scanf("%c", &next1);
	printf("���Ͷ� %s!\n", my_character);
	scanf("%c", &next1);
	printf("\n%s�� ü�� : %d/250     %s�� ü�� : %d/250\n\n", my_character, my_HP, your_character, your_HP);
	scanf("%c", &next1);
	battle();
}

void my_name_func(void) {
	int name;
	char no_name[] = "�̸� ����";
	
	while (1) {

		printf("������� �̸��� �Է��Ͻðڽ��ϱ�? [1. YES  2.NO]  : ");
		scanf("%d", &name);

		if (name == 1) {
			printf("����� �̸��� �����Դϱ�?: ");
			scanf("%s", my_name);
			printf("[%s]��! ȯ���մϴ�!\n", my_name);
			scanf("%c%c", &next1, &next2);
			break;
		}
		else if (name == 2) {
			
			strncpy(my_name, no_name, sizeof(no_name));
			printf("[%s]��! ȯ���մϴ�!\n", my_name);
			scanf("%c%c", &next1, &next2);
			break;
		}
		else {
			printf("�޴��� �߸� �����ϼ̽��ϴ�! �ٽ� ����ּ���!\n");
			scanf("%c%c", &next1, &next2);
		}
	}
}

void your_name_func(void) {
	int name;
	char no_name[] = "�̸� ����";

	while (1) {

		printf("�����2�� �̸��� �Է��Ͻðڽ��ϱ�? [1. YES  2.NO]  : ");
		scanf("%d", &name);

		if (name == 1) {
			printf("����� �̸��� �����Դϱ�?: ");
			scanf("%s", your_name);
			printf("[%s]��! ȯ���մϴ�!\n", your_name);
			scanf("%c%c", &next1, &next2);
			break;
		}
		else if (name == 2) {
			strncpy(your_name, no_name, sizeof(no_name));
			printf("[%s]��! ȯ���մϴ�!\n", your_name);
			scanf("%c%c", &next1, &next2);
			break;
		}
		else {
			printf("�޴��� �߸� �����ϼ̽��ϴ�! �ٽ� ����ּ���!\n");
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
		printf("1. ���� 2. �̻��ؾ� 3. ���̸� 4. ���α�\n");
		printf("[%s]���� ��Ʈ�ʸ� �����ϼ��� : ", my_name);
		scanf("%d", &choice);

		if (choice == 1) {
			printf("[%s]���� ��Ʈ�ʷ� %s�� �����ϼ̽��ϴ�!\n", my_name, character[0]);
			strncpy(my_character, character[0], sizeof(character[0]));
			break;
		}
		else if (choice == 2) {
			printf("[%s]���� ��Ʈ�ʷ� %s�� �����ϼ̽��ϴ�!\n", my_name, character[1]);
			strncpy(my_character, character[1], sizeof(character[1]));
			break;
		}
		else if (choice == 3) {
			printf("[%s]���� ��Ʈ�ʷ� %s�� �����ϼ̽��ϴ�!\n", my_name, character[2]);
			strncpy(my_character, character[2], sizeof(character[2]));
			break;
		}
		else if (choice == 4) {
			printf("[%s]���� ��Ʈ�ʷ� %s�� �����ϼ̽��ϴ�!\n", my_name, character[3]);
			strncpy(my_character, character[3], sizeof(character[3]));
			break;
		}
		else {
			printf("��Ʈ�ʸ� �ٽ� �������ּ���!\n");
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
		printf("1. ���� 2. �̻��ؾ� 3. ���̸� 4. ���α�\n");
		printf("[%s]���� ��Ʈ�ʸ� �����ϼ���: ", your_name);
		scanf_s("%d", &choice);

		if (choice == 1) {
			printf("[%s]���� ��Ʈ�ʷ� %s�� �����ϼ̽��ϴ�!\n", your_name, character[0]);
			strncpy(your_character, character[0], sizeof(character[0]));
			break;
		}
		else if (choice == 2) {
			printf("[%s]���� ��Ʈ�ʷ� %s�� �����ϼ̽��ϴ�!\n", your_name, character[1]);
			strncpy(your_character, character[1], sizeof(character[1]));
			break;
		}
		else if (choice == 3) {
			printf("[%s]���� ��Ʈ�ʷ� %s�� �����ϼ̽��ϴ�!\n", your_name, character[2]);
			strncpy(your_character, character[2], sizeof(character[2]));
			break;
		}
		else if (choice == 4) {
			printf("[%s]���� ��Ʈ�ʷ� %s�� �����ϼ̽��ϴ�!\n", your_name, character[3]);
			strncpy(your_character, character[3], sizeof(character[3]));
			break;
		}
		else {
			printf("��Ʈ�ʸ� �ٽ� �������ּ���!\n");
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
			printf("������ ��� ����� ����Ͽ� ���� ������ �Ѿ��\n");
			scanf("%c", &next1);
			your_defense = 0;
		}
		else {
			pick_my_turn();
			printf("%s�� ü�� : %d/250     %s�� ü�� : %d/250\n", my_character, my_HP, your_character, your_HP);
			scanf("%c", &next1);
			if (my_HP <= 0) {
				printf("%s�� ��������.\n %s�� �¸�!\n", my_character, your_character);
				scanf("%c", &next1);
				printf("%s���� �¸��ϼ̽��ϴ�.", your_name);
				break;
			}
			else if (your_HP <= 0) {
				printf("%s�� ��������.\n %s�� �¸�!\n", your_character, my_character);
				scanf("%c", &next1);
				printf("%s���� �¸��ϼ̽��ϴ�.", my_name);
				break;
			}
			else if (my_skill1 == 0 && my_skill2 == 0 && my_skill3 == 0 && my_skill4 == 0) //�� �̻� ����� �� �� ���� ��
			{
				printf("%s�� �� �̻� ����� �� �� ����!\n%s�� �¸�!\n", my_character, your_character);
				scanf("%c", &next1);
				printf("%s���� �¸��ϼ̽��ϴ�.", your_name);
				break;
			}
		}
		turn = 1;
		if (my_defense == 1) {
			printf("���� ��� ������� ���� ������ �Ѿ��\n");
			scanf("%c", &next1);
			my_defense = 0;
		}
		else {
			pick_your_turn();
			printf("%s�� ü��:%d/250     %s�� ü��:%d/250\n", my_character, my_HP, your_character, your_HP);
			scanf("%c", &next1);
			if (my_HP <= 0)
			{
				printf("%s�� ��������\n%s�� �¸�!\n", my_character, your_character);
				scanf("%c", &next1);
				printf("%s���� �¸��ϼ̽��ϴ�.", your_name);
				break;
			}
			else if (your_HP <= 0)
			{
				("%s�� ��������\n%s�� �¸�!\n", your_character, my_character);
				scanf("%c", &next1);
				printf("%s���� �¸��ϼ̽��ϴ�.", my_name);
				break;
			}
			else if (your_skill1 == 0 && your_skill2 == 0 && your_skill3 == 0 && your_skill4 == 0) //�� �̻� ����� �� �� ���� ��
			{
				printf("%s�� �� �̻� ����� �� �� ����!\n%s�� �¸�!\n", your_character, my_character);
				scanf("%c", &next1);
				printf("%s���� �¸��ϼ̽��ϴ�.", my_name);
				break;
			}
		}	
	}
}

void my_skill_count(void) {
	if (strcmp(my_character, "����") == 0) {
		my_skill1 = pitchu_skill_count[0];
		my_skill2 = pitchu_skill_count[1];
		my_skill3 = pitchu_skill_count[2];
		my_skill4 = pitchu_skill_count[3];
		my_heal = pitchu_skill_count[4];
	}
	else if (strcmp(my_character, "�̻��ؾ�") == 0) {
		my_skill1 = seed_skill_count[0];
		my_skill2 = seed_skill_count[1];
		my_skill3 = seed_skill_count[2];
		my_skill4 = seed_skill_count[3];
		my_heal = seed_skill_count[4];
	}
	else if (strcmp(my_character, "���̸�") == 0) {
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
	if (strcmp(your_character, "����") == 0) {
		your_skill1 = pitchu_skill_count[0];
		your_skill2 = pitchu_skill_count[1];
		your_skill3 = pitchu_skill_count[2];
		your_skill4 = pitchu_skill_count[3];
		your_heal = pitchu_skill_count[4];
	}
	else if (strcmp(your_character, "�̻��ؾ�") == 0) {
		your_skill1 = seed_skill_count[0];
		your_skill2 = seed_skill_count[1];
		your_skill3 = seed_skill_count[2];
		your_skill4 = seed_skill_count[3];
		your_heal = seed_skill_count[4];
	}
	else if (strcmp(your_character, "���̸�") == 0) {
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
	if (strcmp(my_character, "����") == 0) {
		pitchu_turn();
	}
	else if (strcmp(my_character, "�̻��ؾ�") == 0) {
		seed_turn();
	}
	else if (strcmp(my_character, "���̸�") == 0) {
		piri_turn();
	}
	else {
		kobuk_turn();
	}
}

void pick_your_turn(void) {
	if (strcmp(your_character, "����") == 0) {
		pitchu_turn();
	}
	else if (strcmp(your_character, "�̻��ؾ�") == 0) {
		seed_turn();
	}
	else if (strcmp(your_character, "���̸�") == 0) {
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
				printf("ġ����� ��� ����� �� �̻� �� �� �����ϴ�!\n");
				scanf("%c", &next1);
				printf("%s�� ��������\n%s�� �¸�!\n", your_character, my_character);
				scanf("%c", &next1);
				printf("%s���� �¸��ϼ̽��ϴ�.", my_name);
				exit(0);
			}
			else {
				printf("ġ����� ����Ͽ� �̻� ����(ȭ��, ����)�� ġ���Ͽ���!\n");
				scanf("%c", &next1);
				printf("���� �̻� ȸ��!\n");
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
		printf("1. ����� ����\n2. ġ����� ����\n3. ��� ������ Ȯ���Ѵ�\n\n����� ������ �ұ�?: ");
		scanf("%d", &i);
		printf("\n");
		scanf("%c", &next1);

		if (status == 1) {
			if (i == 1) {
				printf("�̻� ����(ȭ��, ���� ��)�� ���� ��ų ����� �Ұ��ϴ�\n");
				printf("ġ����� ���� �̻� ���¿��� ��� �� �ִ�\n");
				scanf("%c", &next1);
				pitchu_turn();
			}
			else if (i == 2) {
				if (heal == 0) {
					printf("ġ����� ��� ����� �� �̻� �� �� �����ϴ�!");
					scanf("%c", &next1);
					if (turn == 0) {
						printf("%s�� ��������\n%s�� �¸�!\n", my_character, your_character);
						scanf("%c", &next1);
						printf("%s���� �¸��ϼ̽��ϴ�.", your_name);
						exit(0);
					}
					else {
						printf("%s�� ��������\n%s�� �¸�!\n", your_character, my_character);
						scanf("%c", &next1);
						printf("%s���� �¸��ϼ̽��ϴ�.", my_name);
						exit(0);
					}
				}
				else {
					printf("ġ����� ����Ͽ� �̻� ����(ȭ��, ����)�� ġ���Ͽ���!\n");
					scanf("%c", &next1);
					printf("���� �̻� ȸ��!\n");
					scanf("%c", &next1);
					status = 0;
					heal--;
					save_current_status();
				}
			}
			else if( i == 3) {
				printf("��� ���� Ȯ��!\n");
				printf("1. ��ġ��: �Ӹ��� ���а� ������ �����Ͽ� �����Ѵ�. ���� Ǯ�װ� �����. ������ ���� ���ϸ��� ����߸� ���� �ִ�.\n\n");
				printf("2. ������ġ:������ ���� ��ġ�� ��븦 �����Ѵ�. 50%% Ȯ���� ��� ���ϸ��� ȭ������ �� �ִ�.\n\n");
				printf("3. �� �κ�κ� :���Ⱑ �帣�� ���� �񺭼� �����Ѵ�.  �������� ���� ������ �����ϴ�. \n\n");
				printf("4. 10����Ʈ: ���� ������ ��뿡�� ������ �����Ѵ�. ��븦 90%% Ȯ���� �����ų �� �ִ�.\n\n");
				printf("���� ȭ������ ���ư���...\n");
				scanf("%c", &next1);
				pitchu_turn();
			}
			else {
				pitchu_turn();
			}
		}
		else {
			if (i == 1) {
				printf("��� ����!\n");
				scanf("%c", &next1);
				printf("1. ��ġ��(pp %d/5)\n2. ������ġ(pp %d/5)\n3. �� �κ�κ�(pp %d/2)\n4. 10����Ʈ(pp %d/1)\n", skill1, skill2, skill3, skill4);
				printf("�ڷ� ���÷��� 1~4�̿��� ���ڸ� �Է��ϼ���\n");
				printf("� ����� ����ұ�?: ");
				scanf("%d", &skill);
				printf("\n");
				scanf("%c", &next1);

				if (skill == 1) {
					if (skill1 == 0) {
						printf("�� ��ų�� �� �̻� �� �� �����ϴ�!(��ų ����)\n");
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
						printf("�� ��ų�� �� �̻� �� �� �����ϴ�!(��ų ����)\n");
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
						printf("�� ��ų�� �� �̻� �� �� �����ϴ�!(��ų ����)\n");
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
						printf("�� ��ų�� �� �̻� �� �� �����ϴ�!(��ų ����)\n");
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
				printf("��ó��(%d/1��)\n", heal);
				printf("�ڷ� ���÷��� 1�̿��� ���ڳ� ���ڸ� �Է��� �߸��� �Է��� �ϼ���\n");
				scanf("%d", &k);
				if (k == 1) {
					if (heal == 0) {
						printf("ġ����� ��� ����� �� �̻� �� �� �����ϴ�!\n");
						pitchu_turn();
					}
					else {
						printf("��ó���� ����ߴ�!\n");
						scanf("%c", &next1);
						status = 0;
						heal--;
						save_current_status();
					}
				}
				else {
					printf("�߸� �Է��ϼ̽��ϴ�!\n");
					scanf("%c", &next1);
					pitchu_turn();
				}
			}
			else if( i == 3) {
				printf("��� ���� Ȯ��!\n");
				printf("1. ��ġ��: �Ӹ��� ���а� ������ �����Ͽ� �����Ѵ�. ���� Ǯ�װ� �����. ������ ���� ���ϸ��� ����߸� ���� �ִ�.\n\n");
				printf("2. ������ġ:������ ���� ��ġ�� ��븦 �����Ѵ�. 50%% Ȯ���� ��� ���ϸ��� ȭ������ �� �ִ�.\n\n");
				printf("3. �� �κ�κ� :���Ⱑ �帣�� ���� �񺭼� �����Ѵ�.  �������� ���� ������ �����ϴ�. \n\n");
				printf("4. 10����Ʈ: ���� ������ ��뿡�� ������ �����Ѵ�. ��븦 90%% Ȯ���� �����ų �� �ִ�.\n\n");
				printf("���� ȭ������ ���ư���...\n");
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
				printf("ġ����� ��� ����� �� �̻� �� �� �����ϴ�!\n");
				scanf("%c", &next1);
				printf("%s�� ��������\n%s�� �¸�!\n", your_character, my_character);
				scanf("%c", &next1);
				printf("%s���� �¸��ϼ̽��ϴ�.", my_name);
				exit(0);
			}
			else {
				printf("ġ����� ����Ͽ� �̻� ����(ȭ��, ����)�� ġ���Ͽ���!\n");
				scanf("%c", &next1);
				printf("���� �̻� ȸ��!\n");
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
		printf("1. ����� ����\n2. ġ����� ����\n3. ��� ������ Ȯ���Ѵ�\n\n�̻��ؾ��� ������ �ұ�?: ");
		scanf("%d", &i);
		printf("\n");
		scanf("%c", &next1);

		if (status == 1) {
			if (i == 1) {
				printf("�̻� ����(ȭ��, ���� ��)�� ���� ��ų ����� �Ұ��ϴ�\n");
				printf("ġ����� ���� �̻� ���¿��� ��� �� �ִ�\n");
				scanf("%c", &next1);
				seed_turn();
			}
			else if( i == 2 ) {
				if (heal == 0) {
					printf("ġ����� ��� ����� �� �̻� �� �� �����ϴ�!\n");
					scanf("%c", &next1);
					if (turn == 0) {
						printf("%s�� ��������\n%s�� �¸�!\n", my_character, your_character);
						scanf("%c", &next1);
						printf("%s���� �¸��ϼ̽��ϴ�.", your_name);
						exit(0);
					}
					else {
						printf("%s�� ��������\n%s�� �¸�!\n", your_character, my_character);
						scanf("%c", &next1);
						printf("%s���� �¸��ϼ̽��ϴ�.", my_name);
						exit(0);
					}
				}
				else {
					printf("ġ����� ����Ͽ� �̻� ����(ȭ��, ����)�� ġ���Ͽ���!\n");
					scanf("%c", &next1);
					printf("���� �̻� ȸ��!\n");
					scanf("%c", &next1);
					status = 0;
					heal--;
					save_current_status();
				}
			}
			else if (i == 3) {
				printf("��� ���� Ȯ��!\n");
				scanf("%c", &next1);
				printf("1. Ǯ����: Ǯ�� �ְ��Ƽ� ��븦 �����߸���. ��밡 ���ſ���� ������ �ö󰣴�.\n\n");
				printf("2. ����ä��: ä��ó�� �־����� ���ð� �� ������ ��븦 ���� �ļ� �����Ѵ�. \n\n");
				printf("3. �ٳ�������:�������� �ٻ�͸� ���� ��븦 ���� �����Ѵ�. �޼ҿ� ���� Ȯ���� ����.\n\n");
				printf("4. ���ռ�: �ڽ��� HP�� ȸ���Ѵ�. ������ ���� ȸ������ ���Ѵ�.\n\n");
				printf("���� ȭ������ ���ư���....\n");
				scanf("%c", &next1);
				seed_turn();
			}
			else {
				seed_turn();
			}
		}
		else {
			if (i == 1) {
				printf("��� ����!\n");
				scanf("%c", &next1);
				printf("1. Ǯ����(pp %d/5)\n2. ����ä��(pp %d/5)\n3. �ٳ�������(pp %d/2)\n4. ���ռ�(pp %d/1)\n", skill1, skill2, skill3, skill4);
				printf("�ڷ� ���÷��� 1~4�̿��� ���ڸ� �Է��ϼ���\n");
				printf("� ����� ����ұ�?: ");
				scanf("%d", &skill);
				printf("\n");
				scanf("%c", &next1);

				if (skill == 1) {
					if (skill1 == 0) {
						printf("�� ��ų�� �� �̻� �� �� �����ϴ�!(��ų ����)\n");
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
						printf("�� ��ų�� �� �̻� �� �� �����ϴ�!(��ų ����)\n");
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
						printf("�� ��ų�� �� �̻� �� �� �����ϴ�!(��ų ����)\n");
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
						printf("�� ��ų�� �� �̻� �� �� �����ϴ�!(��ų ����)\n");
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

				printf("��ó��(%d/1��)\n", heal);
				printf("�ڷ� ���÷��� 1�̿��� ���ڳ� ���ڸ� �Է��� �߸��� �Է��� �ϼ���\n");
				scanf("%d", &k);
				if (k == 1) {
					if (heal == 0) {
						printf("ġ����� ��� ����� �� �̻� �� �� �����ϴ�!");
						scanf("%c", &next1);
						seed_turn();
					}
					else {
						printf("��ó���� ����ߴ�!\n");
						scanf("%c", &next1);
						status = 0;
						heal--;
						save_current_status();
					}
				}
				else {
					printf("�߸� �Է��ϼ̽��ϴ�!\n");
					scanf("%c", &next1);
					seed_turn();
				}
			}
			else if (i == 3) {
				printf("��� ���� Ȯ��!\n");
				scanf("%c", &next1);
				printf("1. Ǯ����: Ǯ�� �ְ��Ƽ� ��븦 �����߸���. ��밡 ���ſ���� ������ �ö󰣴�.\n\n");
				printf("2. ����ä��: ä��ó�� �־����� ���ð� �� ������ ��븦 ���� �ļ� �����Ѵ�. \n\n");
				printf("3. �ٳ�������:�������� �ٻ�͸� ���� ��븦 ���� �����Ѵ�. �޼ҿ� ���� Ȯ���� ����.\n\n");
				printf("4. ���ռ�: �ڽ��� HP�� ȸ���Ѵ�. ������ ���� ȸ������ ���Ѵ�.\n\n");
				printf("���� ȭ������ ���ư���....\n");
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
				printf("ġ����� ��� ����� �� �̻� �� �� �����ϴ�!\n");
				scanf("%c", &next1);
				printf("%s�� ��������\n%s�� �¸�!\n", your_character, my_character);
				scanf("%c", &next1);
				printf("%s���� �¸��ϼ̽��ϴ�.", my_name);
				exit(0);
			}
			else if (skill4 == 0 && heal != 0){
				printf("ġ����� ����Ͽ� �̻� ����(ȭ��, ����)�� ġ���Ͽ���!\n");
				scanf("%c", &next1);
				printf("���� �̻� ȸ��!\n");
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
		printf("1. ����� ����\n2. ġ����� ����\n3. ��� ������ Ȯ���Ѵ�\n\n���̸��� ������ �ұ�?: ");
		scanf("%d", &i);
		printf("\n");
		scanf("%c", &next1);

		if (status == 1) {
			if (i == 1) {
				printf("�̻� ����(ȭ��, ���� ��)�� ���� ���⸸ ��� �����ϴ�\n");
				printf("���⸦ ����Ϸ��� 1�� �Է��϶�(�޴�â���� ���ư���: 1 �̿��� �� �Է�)");
				scanf("%d", &j);
				if (j == 1) {
					if (skill4 == 0) {
						printf("���⸦ ��� ����Ͽ� ��ų ����� �Ұ��ϴ�!\n");
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
					printf("ġ����� ��� ����� �� �̻� �� �� �����ϴ�!\n");
					scanf("%c", &next1);
					if (turn == 0) {
						printf("%s�� ��������\n%s�� �¸�!\n", my_character, your_character);
						scanf("%c", &next1);
						printf("%s���� �¸��ϼ̽��ϴ�.", your_name);
						exit(0);
					}
					else {
						printf("%s�� ��������\n%s�� �¸�!\n", your_character, my_character);
						scanf("%c", &next1);
						printf("%s���� �¸��ϼ̽��ϴ�.", my_name);
						exit(0);
					}
				}
				else {
					printf("ġ����� ����Ͽ� �̻� ����(ȭ��, ����)�� ġ���Ͽ���!\n");
					scanf("%c", &next1);
					printf("���� �̻� ȸ��!\n");
					scanf("%c", &next1);
					status = 0;
					heal--;
					save_current_status();
				}
			}
			else if (i == 3) {
				printf("��� ���� Ȯ��!\n");
				printf("1. �Ҵ빮��: ū ������ �Ҳ����� ��븦 ���¿��, 30�ۼ�Ʈ Ȯ���� ȭ����·� �����.\n\n");
				printf("2. ö�ǹ���: 60�ۼ�Ʈ Ȯ���� ������ �����ϰ� ������ ���� ������ ����Ѵ�\n\n");
				printf("3. ȸ��������: �Ҳ� �ӿ� 5�� ���� ��븦 ���ξ� �����Ѵ�\n\n");
				printf("4. ����: �ڽ��� ��, ����, ȭ�� ������ �� ������ ����� ������ 2�谡 �ȴ�.\n\n");
				printf("���� ȭ������ ���ư���...\n");
				scanf("%c", &next1);
				piri_turn();
			}
			else {
				piri_turn();
			}
		}
		else {
			if (i == 1) {
				printf("��� ����!\n");
				scanf("%c", &next1);
				printf("1. �Ҵ빮��(pp %d/5)\n2. ���(pp %d/1)\n3. ȸ���� ����(pp %d/2)\n4. ����(pp %d/1)\n", skill1, skill2, skill3, skill4);
				printf("�ڷ� ���÷��� 1~4�̿��� ���ڸ� �Է��ϼ���\n");
				printf("� ����� ����ұ�?: ");
				scanf("%d", &skill);
				printf("\n");
				scanf("%c", &next1);
				if (skill == 1) {
					if (skill1 == 0) {
						printf("�� ��ų�� �� �̻� �� �� �����ϴ�!(��ų ����)\n");
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
						printf("�� ��ų�� �� �̻� �� �� �����ϴ�!(��ų ����)\n");
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
						printf("�� ��ų�� �� �̻� �� �� �����ϴ�!(��ų ����)\n");
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
						printf("�� ��ų�� �� �̻� �� �� �����ϴ�!(��ų ����)\n");
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
				printf("��ó��(%d/1��)\n", heal);
				printf("�ڷ� ���÷��� 1�̿��� ���ڳ� ���ڸ� �Է��� �߸��� �Է��� �ϼ���\n");
				scanf("%d", &k);
				if (k == 1) {
					if (heal == 0) {
						printf("ġ����� ��� ����� �� �̻� �� �� �����ϴ�!");
						scanf("%c", &next1);
						piri_turn();
					}
					else {
						printf("��ó���� ����ߴ�!\n");
						scanf("%c", &next1);
						status = 0;
						heal--;
						save_current_status();
					}
				}
				else {
					printf("�߸� �Է��ϼ̽��ϴ�!\n");
					scanf("%c", &next1);
					piri_turn();
				}
			}
			else if (i == 3) {
				printf("��� ���� Ȯ��!\n");
				printf("1. �Ҵ빮��: ū ������ �Ҳ����� ��븦 ���¿��, 30�ۼ�Ʈ Ȯ���� ȭ����·� �����.\n\n");
				printf("2. ö�ǹ���: 60�ۼ�Ʈ Ȯ���� ������ �����ϰ� ������ ���� ������ ����Ѵ�\n\n");
				printf("3. ȸ��������: �Ҳ� �ӿ� 5�� ���� ��븦 ���ξ� �����Ѵ�\n\n");
				printf("4. ����: �ڽ��� ��, ����, ȭ�� ������ �� ������ ����� ������ 2�谡 �ȴ�.\n\n");
				printf("���� ȭ������ ���ư���...\n");
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
				printf("ġ����� ��� ����� �� �̻� �� �� �����ϴ�!");
				scanf("%c", &next1);
				printf("%s�� ��������\n%s�� �¸�!\n", your_character, my_character);
				scanf("%c", &next1);
				printf("%s���� �¸��ϼ̽��ϴ�.", my_name);
				exit(0);
			}
			else {
				printf("ġ����� ����Ͽ� �̻� ����(ȭ��, ����)�� ġ���Ͽ���!\n");
				scanf("%c", &next1);
				printf("���� �̻� ȸ��!\n");
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
		printf("1. ����� ����\n2. ġ����� ����\n3. ��� ������ Ȯ���Ѵ�\n\n���α�� ������ �ұ�?: ");
		scanf("%d", &i);
		printf("\n");
		scanf("%c", &next1);

		if (status == 1) {
			if (i == 1) {
				printf("�̻� ����(ȭ��, ���� ��)�� ���� ��ų ����� �Ұ��ϴ�\n");
				printf("ġ����� ���� �̻� ���¿��� ��� �� �ִ�\n");
				scanf("%c", &next1);
				kobuk_turn();
			}
			else if(i == 2){
				if (heal == 0) {
					printf("ġ����� ��� ����� �� �̻� �� �� �����ϴ�!\n");
					scanf("%c", &next1);
					if (turn == 0) {
						printf("%s�� ��������\n%s�� �¸�!\n", my_character, your_character);
						scanf("%c", &next1);
						printf("%s���� �¸��ϼ̽��ϴ�.", your_name);
						exit(0);
					}
					else {
						printf("%s�� ��������\n%s�� �¸�!\n", your_character, my_character);
						scanf("%c", &next1);
						printf("%s���� �¸��ϼ̽��ϴ�.", my_name);
						exit(0);
					}
				}
				else {
					printf("ġ����� ����Ͽ� �̻� ����(ȭ��, ����)�� ġ���Ͽ���!\n");
					scanf("%c", &next1);
					printf("���� �̻� ȸ��!\n");
					scanf("%c", &next1);
					status = 0;
					heal--;
					save_current_status();
				}
			}
			else if (i == 3) {
				printf("��� ���� Ȯ��!\n");
				printf("1. ���������: ������ ���ٴ� ��ģ �ĵ��� ���� ū ������ ��� �����Ѵ�.\n\n");
				printf("2. �ұݹ�: ��밡 HP�� ���� ���� ��ó�� �԰� ������ ����� ������ 2�谡 �ȴ�.\n\n");
				printf("3. ����: �̰߰� ��������� ���� ��뿡�� �߻��ؼ� �����Ѵ�. 50%% Ȯ���� ȭ�� ���·� ���� ���� �ִ�.\n\n");
				printf("4. ��ٶ��:5�� ���� �� ������ �Ͽ� ��Ÿ�� ����� ������ �ø���..\n\n");
				printf("���� ȭ������ ���ư���...\n");
				scanf("%c", &next1);
				kobuk_turn();
			}
			else {
				kobuk_turn();
			}
		}
		else {
			if (i == 1) {
				printf("��� ����!\n");
				scanf("%c", &next1);
				printf("1. ���������(pp %d/5)\n2. �ұݹ�(pp %d/5)\n3. ����(pp %d/2)\n4. ��ٶ��(pp %d/1)\n", skill1, skill2, skill3, skill4);
				printf("�ڷ� ���÷��� 1~4�̿��� ���ڸ� �Է��ϼ���\n");
				printf("� ����� ����ұ�?: ");
				scanf("%d", &skill);
				printf("\n");
				scanf("%c", &next1);


				if (skill == 1) {
					if (skill1 == 0) {
						printf("�� ��ų�� �� �̻� �� �� �����ϴ�!(��ų ����)\n");
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
						printf("�� ��ų�� �� �̻� �� �� �����ϴ�!(��ų ����)\n");
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
						printf("�� ��ų�� �� �̻� �� �� �����ϴ�!(��ų ����)\n");
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
						printf("�� ��ų�� �� �̻� �� �� �����ϴ�!(��ų ����)\n");
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
				printf("��ó��(%d/1��)\n", heal);
				printf("�ڷ� ���÷��� 1�̿��� ���ڳ� ���ڸ� �Է��� �߸��� �Է��� �ϼ���\n");
				scanf("%d", &k);
				if (k == 1) {
					if (heal == 0) {
						printf("ġ����� ��� ����� �� �̻� �� �� �����ϴ�!");
						scanf("%c", &next1);
						kobuk_turn();
					}
					else {
						printf("��ó���� ����ߴ�!\n");
						status = 0;
						heal--;
						scanf("%c", &next1);
						save_current_status();
					}
				}
				else {
					printf("�߸� �Է��ϼ̽��ϴ�!\n");
					scanf("%c", &next1);
					kobuk_turn();
				}
			}
			else if(i==3){
				printf("��� ���� Ȯ��!\n");
				printf("1. ���������: ������ ���ٴ� ��ģ �ĵ��� ���� ū ������ ��� �����Ѵ�.\n\n");
				printf("2. �ұݹ�: ��밡 HP�� ���� ���� ��ó�� �԰� ������ ����� ������ 2�谡 �ȴ�.\n\n");
				printf("3. ����: �̰߰� ��������� ���� ��뿡�� �߻��ؼ� �����Ѵ�. 50%% Ȯ���� ȭ�� ���·� ���� ���� �ִ�.\n\n");
				printf("4. ��ٶ��:5�� ���� �� ������ �Ͽ� ��Ÿ�� ����� ������ �ø���..\n\n");
				printf("���� ȭ������ ���ư���...\n");
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

void p1() //������ ��ġ��
{
	int damage, percentage;

	printf("������ ��ġ�� ����!\n");
	scanf("%c", &next1);

	damage = 30;
	percentage = 1 + rand() % 100;

	turn_mory_character();

	if (percentage <= 80) //80%
	{
		printf("%s��(��) %d�� �������� �Ծ���!\n", turn_character, damage);
		scanf("%c", &next1);
		HP -= damage;
	}
	else
	{
		printf("�׷��� ��������!\n");
		scanf("%c", &next1);
	}
}

void p2() //������ ������ġ
{
	int damage, percentage, burns_percentage;

	printf("������ ������ġ ����!\n");
	scanf("%c", &next1);

	percentage = 1 + rand() % 100;
	burns_percentage = 1 + rand() % 100;
	damage = 40;

	turn_mory_character();
	turn_mory_status();

	if (percentage <= 80) //80%
	{
		printf("%s��(��) %d�� �������� �Ծ���!\n", turn_character, damage);
		scanf("%c", &next1);
		HP -= damage;
		if (burns_percentage <= 50) {
			printf("%s��(��) ȭ�� �ɷȴ�!\n", turn_character);
			status = 1;
		}
	}
	else
	{
		printf("�׷��� ��������!\n");
		scanf("%c", &next1);
	}
	save_mory_status();
}

void p3() //�� �κ�κ�
{
	int damage, percentage, num, total_damage;

	printf("������ �� �κ�κ� ����!\n");
	scanf("%c", &next1);

	srand((unsigned)time(NULL));

	damage = 15;
	percentage = 1 + rand() % 65; //65%�� Ȯ��
	num = rand() % 3 + 2; //2~4�� ����

	turn_mory_character();

	if (percentage <= 65)
	{
		total_damage = damage * num;
		printf("%s��(��) %d�� �������� �Ծ���!\n", turn_character, total_damage);
		scanf("%c", &next1);
		HP -= total_damage;
	}
	else
	{
		printf("�׷��� ��������!\n");
		scanf("%c", &next1);
	}
}

void p4() //10����Ʈ
{
	int damage, percentage, paralysis_percentage;

	printf("������ 10�� ��Ʈ ����!\n");
	scanf("%c", &next1);

	damage = 50;
	percentage = 1 + rand() % 100;
	paralysis_percentage = 1 + rand() % 100;

	turn_mory_character();
	turn_mory_status();

	if (percentage <= 90) //90%
	{
		printf("%s��(��) %d�� �������� �Ծ���!\n", turn_character, damage);
		scanf("%c", &next1);
		HP -= damage;
		if (paralysis_percentage <= 90) //����Ȯ�� 80%
		{
			printf("%s��(��) ���� �ɷȴ�!\n", turn_character);
			scanf("%c", &next1);
			status = 1;
		}
	}
	else
	{
		printf("�׷��� ��������!\n");
		scanf("%c", &next1);
	}
	save_mory_status();
}

void s1() //�̻��ؾ��� Ǯ����
{
	int damage, percentage;
	printf("�̻��ؾ��� Ǯ���� ����!\n");
	scanf("%c", &next1);

	damage = 40;
	percentage = 1 + rand() % 100;

	turn_mory_character();

	if (percentage <= 80) //80%
	{
		printf("%s��(��) %d�� �������� �Ծ���!\n", turn_character, damage);
		scanf("%c", &next1);
		HP -= damage;
	}
	else
	{
		printf("�׷��� ��������!\n");
		scanf("%c", &next1);
	}
}

void s2() //�̻��ؾ��� ���� ä��
{
	int damage, percentage;

	printf("�̻��ؾ��� ���� ä�� ����!\n");
	scanf("%c", &next1);

	damage = 30;
	percentage = 1 + rand() % 100;

	turn_mory_character();

	if (percentage <= 80) //80%
	{
		printf("%s��(��) %d�� �������� �Ծ���!\n", turn_character, damage);
		scanf("%c", &next1);
		HP -= damage;
	}
	else
	{
		printf("�׷��� ��������!\n");
		scanf("%c", &next1);
	}
}

void s3() //�̻���Ǯ�� ���� �ٳ�������
{
	int damage, percentage, i;

	printf("�̻���Ǯ�� ���� �ٳ�������!\n");
	scanf("%c", &next1);

	turn_mory_character();

	for (i = 1; i <= 5; i++)
	{
		percentage = 1 + rand() % 100;
		if (percentage <= 55)  //55%�� Ȯ��
		{
			printf("%dȸ�� ����!\n", i);
			damage = 10 + rand() % 6; //10~16
			printf("%s��(��) %d�� �������� �Ծ���!\n", turn_character, damage);
			HP -= damage;
		}
		else {
			printf("%dȸ�� ����!\n", i);

		}
		printf("\n");
	}
}

void s4() //�̻���Ǯ�� ���ռ�
{
	int recover, percentage, weather;

	printf("�̻��ؾ��� ���ռ�!\n");
	scanf("%c", &next1);
	percentage = 1 + rand() % 100;
	weather = rand() % 3 + 1;

	turn_mory_character();
	recover_mory_HP();

	if (percentage <= 90) //90%
	{
		if (weather == 1)
		{
			printf("������ ���ÿ� ����!\n");
			recover = 50;
		}
		else if (weather == 2)
		{
			printf("������ ��û�ϴ�! ȸ�� ȿ���� �� ��������.\n");
			recover = 100;
		}
		else
		{
			printf("������ �帮��.\n");
			recover = 25;
		}
		printf("�̻��ؾ��� %d��ŭ�� ü���� ȸ���ߴ�!\n", recover);
		scanf("%c", &next1);
		HP += recover;
		if (HP > 250) 
			HP = 250;
	}
	else
	{
		printf("�׷��� �����ߴ�!\n");
		scanf("%c", &next1);
	}
	resave_mory_HP();
}

void l1() //���̸��� �Ҵ빮��
{
	int damage, percentage, burns_percentage;
	printf("���̸��� �Ҵ빮�� ����!\n");
	scanf("%c", &next1);

	damage = 40;
	percentage = 1 + rand() % 100;
	burns_percentage = 1 + rand() % 100;

	turn_mory_character();
	turn_mory_status();

	if (percentage <= 90) //90%
	{
		printf("%s��(��) %d�� �������� �Ծ���!\n", turn_character, damage);
		scanf("%c", &next1);
		HP -= damage;
		if (burns_percentage <= 30) //ȭ�� Ȯ�� 30%
		{
			printf("%s��(��) ȭ�� �ɷȴ�!\n", turn_character);
			scanf("%c", &next1);
			status = 1;
		}
	}
	else
	{
		printf("�׷��� ��������!\n");
		scanf("%c", &next1);
	}
	save_mory_status();
}

void l2() //���̸��� ö�ǹ���
{
	int damage, percentage;
	printf("���̸��� ö�ǹ���!\n");
	scanf("%c", &next1);

	damage = 30;
	percentage = 1 + rand() % 100;

	turn_mory_character();

	if (percentage <= 60) //60%
	{
		printf("%s��(��) %d�� �������� �Ծ���!\n", turn_character, damage);
		scanf("%c", &next1);
		HP -= damage;
	}
	else
	{
		printf("���ݿ��� �����ߴ�!\n");
		scanf("%c", &next1);
	}
	turn_mory_defense();
	printf("�׷��� ���̸��� �ٷ� ���� ����� ������ ���� �� �ִ�!\n"); //ö�� ����: damage ��� �Ϳ� �����ص� ������� �׻� ��� ����
	scanf("%c", &next1);
	defense = 1;
	save_mory_defense();
}

void l3() //���̸��� ȸ��������
{
	int damage[5];
	int percentage;
	int damage_total = 0;
	int i, combo = 0;

	printf("���̸��� ȸ�������� ����!\n");
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
	printf("%dȸ �޺� ���� ����!\n", i);
	printf("%s�� %d�� �������� �Ծ���!\n", turn_character, damage_total);
	scanf("%c", &next1);
	HP -= damage_total;
}

void l4() //���̸��� ����(�ڽ��� ���°� ����, ȭ�� ������ �� ����� ������ 2��)
{
	int damage, percentage;
	printf("���̸��� ���� ����!\n");
	scanf("%c", &next1);

	damage = 40;
	percentage = 1 + rand() % 100;

	turn_mory_character();

	if (percentage <= 80)
	{
		if (status == 0)
		{
			printf("%s�� %d�� �������� �Ծ���!\n", turn_character, damage);
			scanf("%c", &next1);
			HP -= damage;
		}
		else
		{
			printf("%s�� %d�� �������� �Ծ���!\n", turn_character, damage * 2);
			scanf("%c", &next1);
			HP -= damage * 2;
		}
	}
	else
	{
		printf("�׷��� ��������!\n");
		scanf("%c", &next1);
	}

}

void k1() //���α��� ���������
{
	int damage, percentage;
	printf("���α��� ��������� ����!\n");
	scanf("%c", &next1);

	damage = 40;
	percentage = 1 + rand() % 100;

	turn_mory_character();

	if (percentage <= 90) //90%
	{
		printf("%s��(��) %d�� �������� �Ծ���!\n", turn_character, damage);
		scanf("%c", &next1);
		HP -= damage;
	}
	else
	{
		printf("�׷��� ��������!\n");
		scanf("%c", &next1);
	}
}

void k2() //���α��� �ұݹ�
{
	int damage, percentage;
	printf("���α��� �ұݹ� ����!\n");
	scanf("%c", &next1);

	damage = 30;
	percentage = 1 + rand() % 100;

	turn_mory_character();

	if (percentage <= 80) //80%
	{
		if (HP <= 125)
		{
			printf("%s�� %d�� �������� �Ծ���!\n", turn_character, damage * 2);
			scanf("%c", &next1);
			HP -= damage * 2;
		}
		else
		{
			printf("%s�� %d�� �������� �Ծ���!\n", turn_character, damage);
			scanf("%c", &next1);
			HP -= damage;
		}
	}
	else
	{
		printf("�׷��� ��������!\n");
		scanf("%c", &next1);
	}
}

void k3() //����
{
	int damage, percentage, burns_percentage;
	printf("���α��� ���� ����!\n");
	scanf("%c", &next1);

	damage = 30;
	percentage = 1 + rand() % 100;
	burns_percentage = 1 + rand() % 100;

	turn_mory_character();
	turn_mory_status();

	if (percentage <= 90) //90%
	{
		printf("%s��(��) %d�� �������� �Ծ���!\n", turn_character, damage);
		scanf("%c", &next1);
		HP -= damage;
		if (burns_percentage <= 50) //ȭ�� Ȯ�� 50%
		{
			printf("%s��(��) ȭ�� �ɷȴ�!\n", turn_character);
			scanf("%c", &next1);
			status = 1;
		}
	}
	else
	{
		printf("�׷��� ��������!\n");
		scanf("%c", &next1);
	}
	save_mory_status();
}

void k4() //�� �ٶ��
{
	int damage[5];
	int percentage;
	int damage_total = 0;
	int i, combo = 0;

	printf("���α��� �� �ٶ�� ����!\n");
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
	printf("%dȸ �޺� ���� ����!\n", i);
	printf("%s��(��) �� %d�� �������� �Ծ���!\n", turn_character, damage_total);
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