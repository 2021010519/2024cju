#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ���� ������ ����
typedef enum {
    KOREAN,
    MATH,
    ENGLISH,
    SUBJECT_COUNT
} Subject;

// �л� ���� ����ü ����
typedef struct {
    char name[50];
    int nId;
    int nScores[SUBJECT_COUNT];
    double dAverage;
    int nClassRank;
    int nOverallRank;
} Student;

// �Լ� ����
void loadStudents(FILE* file, Student students[], int* nStudentCount);
void calculateAverage(Student students[], int nStudentCount);
void calculateRanks(Student students[], int nStudentCount);
void saveResults(const char* fileName, Student students[], int nStudentCount);
void saveClassSummary(const char* fileName, Student students1[], int nCount1, Student students2[], int nCount2);

int main() {
    Student students1[100], students2[100];
    int nCount1 = 0, nCount2 = 0;

    // ���� ������ ����
    FILE* file1;
    FILE* file2;

    if (fopen_s(&file1, "students_1.txt", "r") != 0) {
        perror("students_1.txt ���� ����");
        exit(1);
    }

    if (fopen_s(&file2, "students_2.txt", "r") != 0) {
        perror("students_2.txt ���� ����");
        fclose(file1);
        exit(1);
    }

    // �л� ���� ���� �ε�
    loadStudents(file1, students1, &nCount1);
    loadStudents(file2, students2, &nCount2);

    fclose(file1);
    fclose(file2);

    // ��� �� ��� ���
    calculateAverage(students1, nCount1);
    calculateAverage(students2, nCount2);
    calculateRanks(students1, nCount1);
    calculateRanks(students2, nCount2);

    // ���� ����
    saveResults("students_1_results.txt", students1, nCount1);
    saveResults("students_2_results.txt", students2, nCount2);
    saveClassSummary("class_results.txt", students1, nCount1, students2, nCount2);

    printf("��� ������ ���������� �����Ǿ����ϴ�.\n");
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
        perror("���� ���� ����");
        exit(1);
    }

    for (int i = 0; i < nStudentCount; i++) {
        fprintf(file, "�й�: %d\n�̸�: %s\n����: %d\n����: %d\n����: %d\n���: %.2f\n�й� ���: %d\n\n",
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
        perror("���� ���� ����");
        exit(1);
    }

    double dSum1 = 0, dSum2 = 0;
    for (int i = 0; i < nCount1; i++) {
        dSum1 += students1[i].dAverage;
    }
    for (int i = 0; i < nCount2; i++) {
        dSum2 += students2[i].dAverage;
    }

    fprintf(file, "�й� 1 ���: %.2f\n", nCount1 > 0 ? dSum1 / nCount1 : 0);
    fprintf(file, "�й� 2 ���: %.2f\n", nCount2 > 0 ? dSum2 / nCount2 : 0);
    fprintf(file, "��ü ���: %.2f\n", (nCount1 + nCount2) > 0 ? (dSum1 + dSum2) / (nCount1 + nCount2) : 0);

    fclose(file);
}
