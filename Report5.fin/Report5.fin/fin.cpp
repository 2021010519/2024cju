#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 과목 열거형 정의
typedef enum {
    KOREAN,
    MATH,
    ENGLISH,
    SUBJECT_COUNT
} Subject;

// 학생 정보 구조체 정의
typedef struct {
    char name[50];
    int nId;
    int nScores[SUBJECT_COUNT];
    double dAverage;
    int nClassRank;
    int nOverallRank;
} Student;

// 함수 선언
void loadStudents(FILE* file, Student students[], int* nStudentCount);
void calculateAverage(Student students[], int nStudentCount);
void calculateRanks(Student students[], int nStudentCount);
void saveResults(const char* fileName, Student students[], int nStudentCount);
void saveClassSummary(const char* fileName, Student students1[], int nCount1, Student students2[], int nCount2);

int main() {
    Student students1[100], students2[100];
    int nCount1 = 0, nCount2 = 0;

    // 파일 포인터 생성
    FILE* file1;
    FILE* file2;

    if (fopen_s(&file1, "students_1.txt", "r") != 0) {
        perror("students_1.txt 열기 실패");
        exit(1);
    }

    if (fopen_s(&file2, "students_2.txt", "r") != 0) {
        perror("students_2.txt 열기 실패");
        fclose(file1);
        exit(1);
    }

    // 학생 정보 파일 로드
    loadStudents(file1, students1, &nCount1);
    loadStudents(file2, students2, &nCount2);

    fclose(file1);
    fclose(file2);

    // 평균 및 등수 계산
    calculateAverage(students1, nCount1);
    calculateAverage(students2, nCount2);
    calculateRanks(students1, nCount1);
    calculateRanks(students2, nCount2);

    // 파일 저장
    saveResults("students_1_results.txt", students1, nCount1);
    saveResults("students_2_results.txt", students2, nCount2);
    saveClassSummary("class_results.txt", students1, nCount1, students2, nCount2);

    printf("결과 파일이 성공적으로 생성되었습니다.\n");
    return 0;
}

void loadStudents(FILE* file, Student students[], int* nStudentCount) {
    while (fscanf_s(file, "%49s %d %d %d %d",
        students[*nStudentCount].name, (unsigned)_countof(students[*nStudentCount].name),
        &students[*nStudentCount].nId,
        &students[*nStudentCount].nScores[KOREAN],
        &students[*nStudentCount].nScores[MATH],
        &students[*nStudentCount].nScores[ENGLISH]) == 5) {
        (*nStudentCount)++;
    }
}

void calculateAverage(Student students[], int nStudentCount) {
    for (int i = 0; i < nStudentCount; i++) {
        int nTotal = 0;
        for (int j = 0; j < SUBJECT_COUNT; j++) {
            nTotal += students[i].nScores[j];
        }
        students[i].dAverage = nTotal / (double)SUBJECT_COUNT;
    }
}

void calculateRanks(Student students[], int nStudentCount) {
    for (int i = 0; i < nStudentCount; i++) {
        int nRank = 1;
        for (int j = 0; j < nStudentCount; j++) {
            if (students[j].dAverage > students[i].dAverage) {
                nRank++;
            }
        }
        students[i].nClassRank = nRank;
    }
}

void saveResults(const char* fileName, Student students[], int nStudentCount) {
    FILE* file;
    if (fopen_s(&file, fileName, "w") != 0) {
        perror("파일 쓰기 실패");
        exit(1);
    }

    for (int i = 0; i < nStudentCount; i++) {
        fprintf(file, "학번: %d\n이름: %s\n국어: %d\n수학: %d\n영어: %d\n평균: %.2f\n분반 등수: %d\n\n",
            students[i].nId,
            students[i].name,
            students[i].nScores[KOREAN],
            students[i].nScores[MATH],
            students[i].nScores[ENGLISH],
            students[i].dAverage,
            students[i].nClassRank);
    }

    fclose(file);
}

void saveClassSummary(const char* fileName, Student students1[], int nCount1, Student students2[], int nCount2) {
    FILE* file;
    if (fopen_s(&file, fileName, "w") != 0) {
        perror("파일 쓰기 실패");
        exit(1);
    }

    double dSum1 = 0, dSum2 = 0;
    for (int i = 0; i < nCount1; i++) {
        dSum1 += students1[i].dAverage;
    }
    for (int i = 0; i < nCount2; i++) {
        dSum2 += students2[i].dAverage;
    }

    fprintf(file, "분반 1 평균: %.2f\n", nCount1 > 0 ? dSum1 / nCount1 : 0);
    fprintf(file, "분반 2 평균: %.2f\n", nCount2 > 0 ? dSum2 / nCount2 : 0);
    fprintf(file, "전체 평균: %.2f\n", (nCount1 + nCount2) > 0 ? (dSum1 + dSum2) / (nCount1 + nCount2) : 0);

    fclose(file);
}
