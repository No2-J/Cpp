#include "MonsterWorld04.h"
#include "Editor.h"

void tstMonsterWorld() {
	MonsterWorld world(15, 10, 100);
	world.run(50);
}

void tstEditor() {
	Editor editor(50, 25);
	editor.run();
}

int main() {
	//tstEditor();
	tstMonsterWorld();
	return 0;
}