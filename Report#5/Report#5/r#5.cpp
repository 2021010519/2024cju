#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define nCLASSES 2 // 반의 수 //
#define nSTUDENTS 10 // 학생 수 //
#define nSUBJECTS 3 // 과목 수 (국어, 수학, 영어) //

// 과목 열거형 정의 //
typedef enum
{
    nKOREAN,
    nMATH,
    nENGLISH
} nSubject;

// 학생 구조체 정의 //
typedef struct
{
    char nName[50]; // 이름 저장 //
    int nID; // 학번 저장 //
    int nScores[nSUBJECTS]; // 과목별 점수 저장 //
    double dAverage; // 평균 점수 저장 //
    int nClass_Rank; // 분반 등수 저장 //
    int nOverall_Rank; // 전체 등수 저장 //
} nStudent;

// 학생 데이터 파일에서 읽기 //
void nLoad_Students_From_File(const char* nFile_Name, nStudent nStudents[nSTUDENTS], int* nStudent_Count)
{
    FILE* nFile;

    if (fopen_s(&nFile, nFile_Name, "r") != 0)
    {
        perror("파일 열기 실패");
        exit(1);
    }

    *nStudent_Count = 0;
    while (fscanf_s(nFile, "%49s %d %d %d %d",
        nStudents[*nStudent_Count].nName, (unsigned)_countof(nStudents[*nStudent_Count].nName),
        &nStudents[*nStudent_Count].nID,
        &nStudents[*nStudent_Count].nScores[nKOREAN],
        &nStudents[*nStudent_Count].nScores[nMATH],
        &nStudents[*nStudent_Count].nScores[nENGLISH]) == 5)
    {
        (*nStudent_Count)++;
        if (*nStudent_Count >= nSTUDENTS)
            break; // 최대 학생 수 제한 //
    }

    fclose(nFile);
}

// 평균 계산 함수 //
void nCalculate_Averages(nStudent nStudents[nCLASSES][nSTUDENTS], int nStudent_Counts[], double dClass_Avg[], double* dOverall_Avg)
{
    double dTotal_Sum = 0; // 전체 합계 //
    int nTotal_Students = 0; // 전체 학생 수 //

    for (int i = 0; i < nCLASSES; i++) // 각 반에 대해 반복 //
    {
        double dClass_Sum = 0; // 반별 합계 //
        for (int j = 0; j < nStudent_Counts[i]; j++) // 각 학생에 대해 반복 //
        {
            int nStudent_Sum = 0; // 학생 점수 합계 //
            for (int k = 0; k < nSUBJECTS; k++) // 각 과목에 대해 반복 //
            {
                nStudent_Sum += nStudents[i][j].nScores[k]; // 점수 합산 //
            }
            nStudents[i][j].dAverage = nStudent_Sum / (double)nSUBJECTS; // 학생 평균 계산 //
            dClass_Sum += nStudents[i][j].dAverage; // 반 평균에 추가 //
        }
        dClass_Avg[i] = dClass_Sum / nStudent_Counts[i]; // 반 평균 계산 //
        dTotal_Sum += dClass_Sum; // 전체 합계 추가 //
        nTotal_Students += nStudent_Counts[i]; // 전체 학생 수 추가 //
    }

    *dOverall_Avg = dTotal_Sum / nTotal_Students; // 전체 평균 계산 //
}

// 등수 계산 함수 //
void nCalculate_Ranks(nStudent nStudents[nCLASSES][nSTUDENTS], int nStudent_Counts[])
{
    // 분반 등수 계산 //
    for (int i = 0; i < nCLASSES; i++)
    {
        for (int j = 0; j < nStudent_Counts[i]; j++)
        {
            int nRank = 1; // 초기 등수 설정 //
            for (int k = 0; k < nStudent_Counts[i]; k++)
            {
                if (nStudents[i][k].dAverage > nStudents[i][j].dAverage)
                {
                    nRank++; // 더 높은 점수가 있으면 등수 증가 //
                }
            }
            nStudents[i][j].nClass_Rank = nRank; // 분반 등수 저장 //
        }
    }

    // 전체 등수 계산 //
    nStudent nAll_Students[nCLASSES * nSTUDENTS]; // 전체 학생 배열 //
    int nTotal_Students = 0; // 전체 학생 수 초기화 //
    for (int i = 0; i < nCLASSES; i++)
    {
        for (int j = 0; j < nStudent_Counts[i]; j++)
        {
            nAll_Students[nTotal_Students++] = nStudents[i][j]; // 모든 학생 추가 //
        }
    }

    for (int i = 0; i < nTotal_Students; i++)
    {
        int nRank = 1; // 초기 등수 설정 //
        for (int j = 0; j < nTotal_Students; j++)
        {
            if (nAll_Students[j].dAverage > nAll_Students[i].dAverage)
            {
                nRank++; // 더 높은 점수가 있으면 등수 증가 //
            }
        }
        nAll_Students[i].nOverall_Rank = nRank; // 전체 등수 저장 //
    }

    // 전체 등수를 원래 배열에 매핑 //
    for (int i = 0; i < nCLASSES; i++)
    {
        for (int j = 0; j < nStudent_Counts[i]; j++)
        {
            for (int k = 0; k < nTotal_Students; k++)
            {
                if (nStudents[i][j].nID == nAll_Students[k].nID)
                {
                    nStudents[i][j].nOverall_Rank = nAll_Students[k].nOverall_Rank; // 전체 등수 매핑 //
                    break;
                }
            }
        }
    }
}

void nSave_Results(const char* nFile_Name, nStudent nStudents[nSTUDENTS], int nStudent_Count)
{
    FILE* nFile;
    if (fopen_s(&nFile, nFile_Name, "w") != 0) //결과 파일 만들는 함수 //
    {
        perror("결과 파일 열기 실패");
        exit(1);
    }

    for (int i = 0; i < nStudent_Count; i++)
    {
        fprintf(nFile, "학번: %d\n", nStudents[i].nID);
        fprintf(nFile, "이름: %s\n", nStudents[i].nName);
        fprintf(nFile, "국어: %d\n", nStudents[i].nScores[nKOREAN]);
        fprintf(nFile, "수학: %d\n", nStudents[i].nScores[nMATH]);
        fprintf(nFile, "영어: %d\n", nStudents[i].nScores[nENGLISH]);
        fprintf(nFile, "평균: %.2f\n", nStudents[i].dAverage);
        fprintf(nFile, "분반 등수: %d\n", nStudents[i].nClass_Rank);
        fprintf(nFile, "전체 등수: %d\n\n", nStudents[i].nOverall_Rank);
    }
    fclose(nFile);
}

void nSave_Class_Results(const char* nFile_Name, double dClass_Avg[], double dOverall_Avg)
{
    FILE* nFile;
    if (fopen_s(&nFile, nFile_Name, "w") != 0)
    {
        perror("결과 파일 열기 실패");
        exit(1);
    }

    fprintf(nFile, "분반 1 평균: %.2f\n", dClass_Avg[0]);
    fprintf(nFile, "분반 2 평균: %.2f\n", dClass_Avg[1]);
    fprintf(nFile, "전체 평균: %.2f\n", dOverall_Avg);
    fclose(nFile);
}

int main()
{
    nStudent nStudents[nCLASSES][nSTUDENTS];
    int nStudent_Counts[nCLASSES] = { 0 }; // 각 반의 학생 수 //
    double dClass_Avg[nCLASSES] = { 0 }; // 반별 평균 //
    double dOverall_Avg = 0; // 전체 평균 //

    // 학생 데이터 파일에서 읽기 //
    nLoad_Students_From_File("students_1.txt", nStudents[0], &nStudent_Counts[0]);
    nLoad_Students_From_File("students_2.txt", nStudents[1], &nStudent_Counts[1]);

    // 평균 및 등수 계산 //
    nCalculate_Averages(nStudents, nStudent_Counts, dClass_Avg, &dOverall_Avg);
    nCalculate_Ranks(nStudents, nStudent_Counts);

    // 결과 파일 저장 //
    nSave_Results("students_1_results.txt", nStudents[0], nStudent_Counts[0]);
    nSave_Results("students_2_results.txt", nStudents[1], nStudent_Counts[1]);
    nSave_Class_Results("class_results.txt", dClass_Avg, dOverall_Avg);

    printf("결과 파일이 성공적으로 생성되었습니다.\n");

    return 0; // 프로그램 종료 //
}
