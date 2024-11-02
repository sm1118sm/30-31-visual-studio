#include <stdio.h>
#include <string.h>
#include "player.h"
#include "room.h"

// 전역 변수 정의
int room[300][300];              // 방 배열
int room_size[300] = { 0 };       // 각 방의 플레이어 수
int room_count = 0;              // 방 개수 초기화

void assign_rooms(int p, int m) {
    for (int i = 0; i < p; i++) {
        int placed = 0;

        // 기존 방에 플레이어 배치
        for (int j = 0; j < room_count; j++) {
            if (room_size[j] < m && level[room[j][0]] - 10 <= level[i] && level[i] <= level[room[j][0]] + 10) {
                room[j][room_size[j]++] = i; // 플레이어 인덱스 추가
                placed = 1;
                break; // 방에 배치 완료 후 다음 플레이어로 이동
            }
        }

        // 입장 가능한 방이 없을 경우 새로운 방 생성
        if (!placed && room_count < 300) {
            room[room_count][0] = i; // 새 방의 첫 번째 플레이어 인덱스
            room_size[room_count++] = 1; // 새 방의 플레이어 수 초기화
        }
    }
}

// 방 정보 출력
void print_rooms(int m) {
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
