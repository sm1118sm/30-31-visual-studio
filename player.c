#include <stdio.h>
#include "player.h"

// 전역 변수 선언
int level[300];
char name[300][17];

void input_players(int p) {
    for (int i = 0; i < p; i++) {
        scanf_s("%d %s", &level[i], name[i], 17);  // 플레이어 레벨과 이름 입력
    }
}
