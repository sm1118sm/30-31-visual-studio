#include <stdio.h>
#include <string.h>

// 전역 변수 선언
int level[300];
char name[300][17];
int room[300][300];  // 최대 플레이어 수만큼의 방을 생성
int room_size[300] = { 0 };     // 각 방의 플레이어 수

// 입력 함수
void input_players(int p) {
    for (int i = 0; i < p; i++) {
        scanf_s("%d %s", &level[i], name[i], 17);  // 입력 시 크기 추가
    }
}

// 플레이어 매칭 및 방 할당 함수
int assign_rooms(int p, int m) {
    int room_count = 0;

    for (int i = 0; i < p; i++) {
        int placed = 0;

        for (int j = 0; j < room_count; j++) {
            // 방에 자리가 있고, 레벨 차이가 ±10 이내일 때
            if (room_size[j] < m && level[room[j][0]] - 10 <= level[i] && level[i] <= level[room[j][0]] + 10) {
                room[j][room_size[j]++] = i;  // 플레이어 인덱스 추가
                placed = 1;
                break;  // 방에 배치 완료, 다음 플레이어로 이동
            }
        }

        // 입장 가능한 방이 없을 경우 새로운 방을 생성
        if (!placed && room_count < 300) {
            room[room_count][0] = i;  // 새 방의 첫 번째 플레이어 인덱스
            room_size[room_count++] = 1;  // 새 방의 플레이어 수 초기화
        }
    }
    return room_count;  // 방 개수 반환
}

// 방 정보 정렬 및 출력 함수
void print_rooms(int room_count, int m) {
    for (int i = 0; i < room_count; i++) {
        if (room_size[i] == m) {
            printf("Started!\n");
        }
        else {
            printf("Waiting!\n");
        }

        // 닉네임을 사전순으로 정렬 (삽입 정렬 사용)
        for (int j = 1; j < room_size[i]; j++) {
            for (int k = j; k > 0 && strcmp(name[room[i][k - 1]], name[room[i][k]]) > 0; k--) {
                // 플레이어 인덱스 교환
                int temp = room[i][k];
                room[i][k] = room[i][k - 1];
                room[i][k - 1] = temp;
            }
        }

        // 방에 있는 플레이어 정보를 출력
        for (int j = 0; j < room_size[i]; j++) {
            int player_index = room[i][j];
            printf("%d %s\n", level[player_index], name[player_index]);
        }
    }
}

int main() {
    int p, m;

    // 플레이어 수와 최대 룸 크기 입력
    scanf_s("%d %d", &p, &m);

    // 플레이어 정보 입력
    input_players(p);

    // 방 할당 및 매칭 처리
    int room_count = assign_rooms(p, m);

    // 결과 출력
    print_rooms(room_count, m);

    return 0;
}
