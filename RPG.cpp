#include <iostream>
#include <time.h>
#include <cstdlib>
#include <cstring>

using namespace std;
int key[21];
int i = 0;
enum MAIN_MENU
{
	MM_NONE,
	MM_MAP,
	MM_STORE,
	MM_INVENTORY,
	MM_EXIT
};

enum MAP_TYPE
{
	MT_NONE,
	MT_EASY,
	MT_NORMAL,
	MT_HARD,
	MT_BACK
};

enum JOB
{
	JOB_NONE,
	JOB_KNIGHT,
	JOB_ARCHER,
	JOB_WIZARD,
	JOB_END
};

enum BATTLE
{
	BATTLE_NONE,
	BATTLE_ATTACK,
	BATTLE_BACK
};

enum ITEM_TYPE
{
	IT_NONE,
	IT_WEAPON,
	IT_ARMOR,
	IT_BACK
};

enum ITEM_ATTACK_TYPE
{
	IAT_NONE,
	IAT_WOODSWORD,
	IAT_STONESWORD,
	IAT_EXCALIBUR,
	IAT_BACK
};

enum STORE_MENU
{
	SM_NONE,
	SM_WEAPON,
	SM_ARMOR,
	SM_BACK
};

#define NAME_SIZE 32
#define ITEM_DESC_LENGTH 512
#define INVENTORY_MAX 20
#define STORE_WEAPON_MAX 3
#define STORE_ARMOR_MAX 3

struct _tagItem
{
	char	strName[NAME_SIZE];
	char	strTypeName[NAME_SIZE];
	ITEM_TYPE	eType;
	int		iMin;
	int		iMax;
	int		iPrice;
	int		iSell;
	char	strDesc[ITEM_DESC_LENGTH];
};

struct _tagInventory
{
	_tagItem    tItem[INVENTORY_MAX];
	int			iItemCount;
	int			iGold;
};

struct _tagPlayer
{
	char	strName[NAME_SIZE];
	char	strJobName[NAME_SIZE];
	JOB		eJob;
	int		iAttackMin;
	int		iAttackMax;
	int		iArmorMin;
	int		iArmorMax;
	int		iHP;
	int		iHPMax;
	int		iMP;
	int		iMPMax;
	int		iExp;
	int		iLevel;
	_tagInventory tInventory;
};
_tagPlayer	tPlayer = {};
struct _tagMonster
{
	char strName[NAME_SIZE];
	int		iAttackMin;
	int		iAttackMax;
	int		iArmorMin;
	int		iArmorMax;
	int		iHP;
	int		iHPMax;
	int		iMP;
	int		iMPMax;
	int		iLevel;
	int		iExp;
	int		iGoldMin;
	int		iGoldMax;
};

void Secret_Command(int a)
{
	int token = 0;
	key[i++] = a;
	if (i >= 20) {
		cout << "======================CheatMode======================" << endl;
		if ((key[1]) == key[4] && key[5] == 118)
			token++;
		if (key[6] == 162 && key[18] == 168)
			token++;
		if ((((key[0] % 100) - 6)) == key[10])
			token++;
		if ((key[2] % 100) == 34)
			token++;
		if (((key[2] + key[6]) * 2) == 592)
			token++;
		if (((key[4] % 100) == 30))
			token++;
		if (key[5] < key[6] && key[5] < key[11])
			token++;
		if (((key[7] % 100) == 74))
			token++;
		if (key[8] == key[18] && key[9] == key[4])
			token++;
		if (key[9] > key[10] && key[0] < key[1])
			token++;
		if ((key[10] % 100) == 80)
			token++;
		if ((key[11]) == key[12])
			token++;
		if (((key[12] + key[1]) * 2) == 528)
			token++;
		if (key[13] > key[18] && key[2] > key[0])
			token++;
		if ((key[15] % 100) == 48)
			token++;
		if (((key[15] + key[16] * 2 - key[17])) == 226)
			token++;
		if ((((key[15] + key[14]) / 2)) == 148)
			token++;
		if (key[19]<key[0] && key[15] > key[16])
			token++;
		if (((key[17] % 100) == 78))
			token++;
		if ((key[16] * key[5] / 4) == 2301)
			token++;
		if ((key[3] + key[10] + key[8]) == 406)
			token++;
		if (key[20] + key[15] == 154 && key[19] == key[20])
			token++;
		if (key[7] > key[8] && key[15] > key[16])
			token++;
		if (key[15]<key[7] && key[14]>key[0])
			token++;
		if ((key[12] + key[13] + key[14]) == 454)
			token++;
	}
	if (token == 25)
	{

		tPlayer.tInventory.iGold = 999999;
		system("pause");

	}


}

int main()
{
	srand((unsigned int)time(0));

	// 게임을 시작할때 플레이어 정보를 설정하게 한다.

	//input player name
	cout << "name : ";
	cin.getline(tPlayer.strName, NAME_SIZE - 1);

	int iJob = JOB_NONE;
	while (iJob == JOB_NONE)
	{
		system("cls");
		cout << "1. Knight" << endl;
		cout << "2. Archer" << endl;
		cout << "3. Wizard" << endl;
		cout << "Choose : ";
		cin >> iJob;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}

		else if (iJob <= JOB_NONE || iJob >= JOB_END)
		{
			iJob = JOB_NONE;
		}

		tPlayer.iLevel = 1;
		tPlayer.iExp = 0;
		tPlayer.eJob = (JOB)iJob;
		tPlayer.tInventory.iGold = 10000;
		tPlayer.tInventory.iItemCount = 0;

		switch (tPlayer.eJob)
		{
		case JOB_KNIGHT:
			strcpy(tPlayer.strJobName, "Knight");
			tPlayer.iAttackMin = 5;
			tPlayer.iAttackMax = 10;
			tPlayer.iArmorMin = 15;
			tPlayer.iArmorMax = 20;
			tPlayer.iHPMax = 500;
			tPlayer.iHP = 500;
			tPlayer.iMP = 100;
			tPlayer.iMPMax = 100;
			break;

		case JOB_ARCHER:
			strcpy(tPlayer.strJobName, "Archer");
			tPlayer.iAttackMin = 10;
			tPlayer.iAttackMax = 15;
			tPlayer.iArmorMin = 10;
			tPlayer.iArmorMax = 15;
			tPlayer.iHPMax = 400;
			tPlayer.iHP = 400;
			tPlayer.iMP = 200;
			tPlayer.iMPMax = 200;
			break;

		case JOB_WIZARD:
			strcpy(tPlayer.strJobName, "Wizard");
			tPlayer.iAttackMin = 15;
			tPlayer.iAttackMax = 20;
			tPlayer.iArmorMin = 5;
			tPlayer.iArmorMax = 10;
			tPlayer.iHPMax = 300;
			tPlayer.iHP = 300;
			tPlayer.iMP = 300;
			tPlayer.iMPMax = 300;
			break;
		}
	}

	// create monster
	_tagMonster		tMonsterArr[MT_BACK - 1] = {};

	// Goblen
	strcpy(tMonsterArr[0].strName, "Goblen");
	tMonsterArr[0].iAttackMin = 20;
	tMonsterArr[0].iAttackMax = 30;
	tMonsterArr[0].iArmorMin = 2;
	tMonsterArr[0].iArmorMax = 5;
	tMonsterArr[0].iHP = 100;
	tMonsterArr[0].iHPMax = 100;
	tMonsterArr[0].iMP = 10;
	tMonsterArr[0].iMPMax = 10;
	tMonsterArr[0].iLevel = 1;
	tMonsterArr[0].iExp = 1000;
	tMonsterArr[0].iGoldMin = 500;
	tMonsterArr[0].iGoldMax = 1500;

	// Throll
	strcpy(tMonsterArr[1].strName, "Throll");
	tMonsterArr[1].iAttackMin = 80;
	tMonsterArr[1].iAttackMax = 130;
	tMonsterArr[1].iArmorMin = 60;
	tMonsterArr[1].iArmorMax = 90;
	tMonsterArr[1].iHP = 2000;
	tMonsterArr[1].iHPMax = 2000;
	tMonsterArr[1].iMP = 100;
	tMonsterArr[1].iMPMax = 100;
	tMonsterArr[1].iLevel = 5;
	tMonsterArr[1].iExp = 7000;
	tMonsterArr[1].iGoldMin = 6000;
	tMonsterArr[1].iGoldMax = 8000;

	//Demon King
	strcpy(tMonsterArr[2].strName, "DemonKing");
	tMonsterArr[2].iAttackMin = 99999;
	tMonsterArr[2].iAttackMax = 99999;
	tMonsterArr[2].iArmorMin = 99999;
	tMonsterArr[2].iArmorMax = 99999;
	tMonsterArr[2].iHP = 99999;
	tMonsterArr[2].iHPMax = 99999;
	tMonsterArr[2].iMP = 99999;
	tMonsterArr[2].iMPMax = 99999;
	tMonsterArr[2].iLevel = 999;
	tMonsterArr[2].iExp = 99999;
	tMonsterArr[2].iGoldMin = 99999;
	tMonsterArr[2].iGoldMax = 99999;

	// 상점에서 판매할 아이템 목록 생성한다.
	_tagItem	tStoreWeapon[STORE_WEAPON_MAX] = {};
	_tagItem	tStoreArmor[STORE_ARMOR_MAX] = {};

	// 각 아이템 정보들을 설정해준다.

	//wooden sword
	strcpy(tStoreWeapon[0].strName, "wooden sword");
	strcpy(tStoreWeapon[0].strTypeName, "weapon");
	tStoreWeapon[0].eType = (ITEM_TYPE)1;
	tStoreWeapon[0].iMin = 20;
	tStoreWeapon[0].iMax = 40;
	tStoreWeapon[0].iPrice = 10000;
	tStoreWeapon[0].iSell = 4000;
	strcpy(tStoreWeapon[0].strDesc, "sword made of wooden");

	//stone sword 
	strcpy(tStoreWeapon[1].strName, "stone sword");
	strcpy(tStoreWeapon[1].strTypeName, "weapon");
	tStoreWeapon[1].eType = (ITEM_TYPE)2;
	tStoreWeapon[1].iMin = 80;
	tStoreWeapon[1].iMax = 100;
	tStoreWeapon[1].iPrice = 1000;
	tStoreWeapon[1].iSell = 40000;
	strcpy(tStoreWeapon[1].strDesc, "sword made of stone");

	//Excalibur
	strcpy(tStoreWeapon[2].strName, "Excalibur");
	strcpy(tStoreWeapon[2].strTypeName, "weapon");
	tStoreWeapon[2].eType = (ITEM_TYPE)3;
	tStoreWeapon[2].iMin = 999999;
	tStoreWeapon[2].iMax = 999999;
	tStoreWeapon[2].iPrice = 999999;
	tStoreWeapon[2].iSell = 1;
	strcpy(tStoreWeapon[1].strDesc, "It is the only weapon that can defeat the demon king");
	while (true)
	{
		system("cls");
		cout << "******************************* Roby ***************************" << endl;
		cout << "1. map" << endl;
		cout << "2. store" << endl;
		cout << "3. bag" << endl;
		cout << "4. end" << endl;
		cout << "menu : " << endl;
		int iMenu;
		cin >> iMenu;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}

		if (iMenu == MM_EXIT)
		{
			break;
		}

		switch (iMenu)
		{
		case MM_MAP:
			while (true)
			{
				system("cls");
				cout << "******************************* map ***************************" << endl;
				cout << "1. easy" << endl;
				cout << "2. normal" << endl;
				cout << "3. hard" << endl;
				cout << "4. back" << endl;
				cout << "choose map : ";
				cin >> iMenu;

				if (cin.fail())
				{
					cin.clear();
					cin.ignore(1024, '\n');
					continue;
				}

				// 이 if문에 속한 break는 맵 메뉴를 돌려주기 위한 while에 속해 있으므로
				// 이 while문을 빠져나간다.
				if (iMenu == MT_BACK)
				{
					break;
				}

				// 선택한 메뉴에서 1을 빼주면 몬스터 배열의 인덱스가 된다.
				// 그렇게 해서 해당 맵의 몬스터를 생성해준다.
				_tagMonster tMonster = tMonsterArr[iMenu - 1];

				while (true)
				{
					system("cls");
					switch (iMenu)
					{
					case MT_EASY:
						cout << "******************************* Easy ***************************" << endl;
						break;
					case MT_NORMAL:
						cout << "******************************* Normal ***************************" << endl;
						break;
					case MT_HARD:
						cout << "******************************* Hard ***************************" << endl;
						break;
					}

					// 플레이어 정보를 출력한다.
					cout << "====================== Player ======================" << endl;
					cout << "name : " << tPlayer.strName << "\tJob : " <<
						tPlayer.strJobName << endl;
					cout << "level : " << tPlayer.iLevel << "\t Exp : " <<
						tPlayer.iExp << endl;
					cout << "AttackPoint : " << tPlayer.iAttackMin << " - " <<
						tPlayer.iAttackMax << "\tGuardPoint : " << tPlayer.iArmorMin <<
						" - " << tPlayer.iArmorMax << endl;
					cout << "HP : " << tPlayer.iHP << " / " << tPlayer.iHPMax <<
						"\tMP : " << tPlayer.iMP << " / " << tPlayer.iMPMax << endl;
					cout << "Gold : " << tPlayer.tInventory.iGold << " Gold" << endl;

					// 몬스터 정보 출력
					cout << "====================== Monster ======================" << endl;
					cout << "name : " << tMonster.strName << "\tlevel : " <<
						tMonster.iLevel << endl;
					cout << "AttackPoint : " << tMonster.iAttackMin << " - " <<
						tMonster.iAttackMax << "\tGuardPoint : " << tMonster.iArmorMin <<
						" - " << tMonster.iArmorMax << endl;
					cout << "HP : " << tMonster.iHP << " / " << tMonster.iHPMax <<
						"\tMP : " << tMonster.iMP << " / " << tMonster.iMPMax << endl;
					cout << "Gain Exp : " << tMonster.iExp << " Exp" << "\tGain gold : " <<
						tMonster.iGoldMin << " - " << tMonster.iGoldMax << endl;

					cout << "1. Attack" << endl;
					cout << "2. Run" << endl;
					cout << "Choose : ";
					cin >> iMenu;

					if (cin.fail())
					{
						cin.clear();
						cin.ignore(1024, '\n');
						continue;
					}

					else if (iMenu == BATTLE_BACK)
					{
						tPlayer.iHP = tPlayer.iHPMax;
						tPlayer.iMP = tPlayer.iMPMax;
						tMonster.iHP = tMonster.iHPMax;
						tMonster.iMP = tMonster.iMPMax;
						break;
					}

					switch (iMenu)
					{
					case BATTLE_ATTACK:
					{
						int iAttack = rand() % (tPlayer.iAttackMax - tPlayer.iAttackMin + 1) +
							tPlayer.iAttackMin;
						int iArmor = rand() % (tMonster.iArmorMax - tMonster.iArmorMin + 1) +
							tMonster.iArmorMin;

						int iDamage = iAttack - iArmor;
						iDamage = iDamage < 1 ? 1 : iDamage;

						tMonster.iHP -= iDamage;

						cout << tPlayer.strName << " deals " << iDamage <<
							 " damage to a " << tMonster.strName << endl;


						// 몬스터가 죽었을 경우 처리
						if (tMonster.iHP <= 0)
						{
							cout << tMonster.strName << " The monster is dead. " << endl;

							tPlayer.iExp += tMonster.iExp;
							int iGold = (rand() % (tMonster.iGoldMax - tMonster.iGoldMin + 1) +
								tMonster.iGoldMin);
							tPlayer.tInventory.iGold += iGold;

							cout << tMonster.iExp << " Gain Exp" << endl;
							cout << iGold << " Gain Gold" << endl;
							if (tMonster.iLevel == 999)
							{
								cout << "=======Ending========" << endl << endl;
								int j = 0;
								for (j = 0; j < 21; j++)
								{
									int akey = (key[j] + 60) / 2;
									char ckey = static_cast<char>(akey);
									cout << ckey;

								}
								cout << endl;
								cout << "=====================" << endl << endl;
								system("pause");
								return 0;
							}
							tPlayer.iHP = tPlayer.iHPMax;
							tPlayer.iMP = tPlayer.iMPMax;
							tMonster.iHP = tMonster.iHPMax;
							tMonster.iMP = tMonster.iMPMax;

							system("pause");
							break;
						}
						// 몬스터가 살아있다면 플레이어를 attack한다
						iAttack = rand() % (tMonster.iAttackMax - tMonster.iAttackMin + 1) +
							tMonster.iAttackMin;
						iArmor = rand() % (tPlayer.iArmorMax - tPlayer.iArmorMin + 1) +
							tPlayer.iArmorMin;

						iDamage = iAttack - iArmor;
						iDamage = iDamage < 1 ? 1 : iDamage;

						// 플레이어의 HP를 감소시킨다.
						tPlayer.iHP -= iDamage;

						cout << tMonster.strName << " deals " << iDamage <<
						 " damage to a " << tPlayer.strName << endl;




						// 플레이어가 죽었을 경우
						if (tPlayer.iHP <= 0)
						{
							cout << tPlayer.strName << " Player is dead." << endl;

							int iExp = tPlayer.iExp * 0.1f;
							int iGold = tPlayer.tInventory.iGold * 0.1f;

							tPlayer.iExp -= iExp;
							tPlayer.tInventory.iGold -= iGold;

							cout << iExp << " Lose Exp" << endl;
							cout << iGold << " Lose Gold" << endl;

							// 플레이어의 HP와 MP를 회복한다.
							tPlayer.iHP = tPlayer.iHPMax;
							tPlayer.iMP = tPlayer.iMPMax;
							tMonster.iHP = tMonster.iHPMax;
							tMonster.iMP = tMonster.iMPMax;
						}

						system("pause");
					}
					break;
					}

				}
			}

			break;
		case MM_STORE:
			while (true)
			{
				system("cls");
				cout << "******************************* Shop ***************************" << endl;
				cout << "1. WeaponShop" << endl;
				cout << "2. Armor Shop" << endl;
				cout << "3. Back" << endl;
				cout << "Choose : ";
				cin >> iMenu;

				if (cin.fail())
				{
					cin.clear();
					cin.ignore(1024, '\n');
					continue;
				}

				else if (iMenu == SM_BACK)
					break;

				switch (iMenu)//WeaponStore
				{
				case SM_WEAPON:
					while (true)
					{
						system("cls");

						cout << "******************************* Weapon Shop ***************************" << endl;
						// Sell List
						cout << "1. Wooden sword " << tStoreWeapon[0].iPrice << "(gold) AttackPoint: " << tStoreWeapon[0].iMin << endl;
						cout << "2. Stone sword " << tStoreWeapon[1].iPrice << "(gold) AttackPoint: " << tStoreWeapon[1].iMin << endl;
						cout << "3. Excalibur " << tStoreWeapon[2].iPrice << "(gold) AttackPoint: " << tStoreWeapon[2].iMin << endl;
						cout << "4. Back" << endl << endl;
						cout << "Money: " << tPlayer.tInventory.iGold << "(gold)" << endl;
						cout << "Choose Item : ";
						cin >> iMenu;
						Secret_Command(iMenu);//comand
						if (cin.fail())
						{
							cin.clear();
							cin.ignore(1024, '\n');
							continue;
						}

						else if (iMenu == IAT_BACK)
							break;

						switch (iMenu)
						{
						case IAT_WOODSWORD:
						{
							if (tPlayer.tInventory.iItemCount >= 20)
							{
								cout << "The bag is full" << endl;
								system("pause");
								break;
							}
							else if (tPlayer.tInventory.iGold < tStoreWeapon[iMenu - 1].iPrice)
							{
								cout << "I'm short on money." << endl;
								system("pause");
								break;
							}
							else
							{
								strcpy(tPlayer.tInventory.tItem[tPlayer.tInventory.iItemCount].strName, "Wooden sword");
								tPlayer.tInventory.iItemCount++;
								tPlayer.iAttackMin += tStoreWeapon[iMenu - 1].iMin;
								tPlayer.iAttackMax += tStoreWeapon[iMenu - 1].iMax;
								tPlayer.tInventory.iGold -= tStoreWeapon[iMenu - 1].iPrice;
								cout << "Buy Successed" << endl;

								system("pause");
							}
							break;
						}
						case IAT_STONESWORD:
						{
							if (tPlayer.tInventory.iItemCount >= 20)
							{
								cout << "The bag is full" << endl;
								system("pause");
								break;
							}
							else if (tPlayer.tInventory.iGold < tStoreWeapon[iMenu - 1].iPrice)
							{
								cout << "I'm short on money" << endl;
								system("pause");
								break;
							}
							else
							{
								strcpy(tPlayer.tInventory.tItem[tPlayer.tInventory.iItemCount].strName, "Stone sword");
								tPlayer.tInventory.iItemCount++;
								tPlayer.iAttackMin += tStoreWeapon[iMenu - 1].iMin;
								tPlayer.iAttackMax += tStoreWeapon[iMenu - 1].iMax;
								tPlayer.tInventory.iGold -= tStoreWeapon[iMenu - 1].iPrice;
								cout << "Buy Success" << endl;
								system("pause");
							}
							break;
						}
						case IAT_EXCALIBUR:
						{
							if (tPlayer.tInventory.iItemCount >= 20)
							{
								cout << "The bag is full" << endl;
								system("pause");
								break;
							}
							else if (tPlayer.tInventory.iGold < tStoreWeapon[iMenu - 1].iPrice)
							{
								cout << "I'm short on money" << endl;
								system("pause");
								break;
							}
							else
							{
								strcpy(tPlayer.tInventory.tItem[tPlayer.tInventory.iItemCount].strName, "Excar");
								tPlayer.tInventory.iItemCount++;
								tPlayer.iAttackMin += tStoreWeapon[iMenu - 1].iMin;
								tPlayer.iAttackMax += tStoreWeapon[iMenu - 1].iMax;
								tPlayer.tInventory.iGold -= tStoreWeapon[iMenu - 1].iPrice;
								if (tPlayer.tInventory.iGold < 0)
								{
									cout << "Bug Player!!!!!!!!" << endl;
									system("pause");
									return 0;
								}
								cout << "Buy Success" << endl;
								system("pause");
							}
							break;
						}
						}
					}
					break;
				case SM_ARMOR:
					break;
				}
			}
			break;
		case MM_INVENTORY:
			system("cls");
			cout << "******************************* Bag ***************************" << endl;
			cout << tPlayer.tInventory.iItemCount << endl;
			for (int i = 0; i < tPlayer.tInventory.iItemCount; i++) {
				cout << tPlayer.tInventory.tItem[i].strName << endl;
			}
			system("pause");
			break;
		default:
			cout << "Wrong Choice" << endl;
			break;
		}
	}

	return 0;
}
