#include "MonsterWorld01.h"

int main() {
	SetConsoleOutputCP(CP_UTF8);
	MonsterWorld world(200); //200 : turns ���԰�, �ϼ� ����
	world.play(10); //10 : wait ���� ��

	return 0;
}