#include "matrix.h"
#include "vector.h"
#include "MonsterWorld2.h"

void tstMonsterWorld() {
	MonsterWorld game(100, 10, 20);
	game.play(10);
}
void tstMatrix() {}
void tstVector() {
	srand(time(0));
	Vector v1(3), v2(3);
	v1.setRand();
	v2.setRand();
	v1.print("v1");
	v2.print("v2");
	cout << "Length of v1 : " << v1.length() << endl;
	cout << "Dot product v1.v2 : " << v1.dot(v2) << endl;
	Vector v3 = v1.cross(v2);
	cout << "v1 x v2 ";
	v3.print("v1 x v2");
	/*Vector v4(10);
	Vector v5 = v4;
	v4.print("v4");
	v5.print("v5");
	v5.setRand();
	v4.print("v4");
	v5.print("v5");*/
}

int main() {
	tstVector();
	return 0;
}