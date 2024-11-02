#include <stdio.h>
#include "player.h"
#include "room.h"

int main() {
    int p, m;

    // 플레이어 수와 최대 룸 크기 입력
    scanf_s("%d %d", &p, &m);

    // 플레이어 정보 입력
    input_players(p);

    // 방 할당 및 매칭 처리
    assign_rooms(p, m);

    // 결과 출력
    print_rooms(m);

    return 0;
}
