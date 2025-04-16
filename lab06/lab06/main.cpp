#include "MonsterWorld01.h"

int main() {
	SetConsoleOutputCP(CP_UTF8);
	MonsterWorld world(200); //200 : turns 대입값, 턴수 설정
	world.play(10); //10 : wait 대입 값

	return 0;
}