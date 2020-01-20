#include "jetSki.h"

jetSki::jetSki():Body(Vec3(0.0f, 5.0f, 0.0f), Vec3(0.0f, 0.0f, 0.0f), Vec3(2.5f, 0.0f, 0.0f), 200.0f) {
	printf("hello from the jetSki constructor\n");

}

jetSki::~jetSki() {}
