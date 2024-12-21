#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define nCLASSES 2 // ���� �� //
#define nSTUDENTS 10 // �л� �� //
#define nSUBJECTS 3 // ���� �� (����, ����, ����) //

// ���� ������ ���� //
typedef enum
{
    nKOREAN,
    nMATH,
    nENGLISH
} nSubject;

// �л� ����ü ���� //
typedef struct
{
    char nName[50]; // �̸� ���� //
    int nID; // �й� ���� //
    int nScores[nSUBJECTS]; // ���� ���� ���� //
    double dAverage; // ��� ���� ���� //
    int nClass_Rank; // �й� ��� ���� //
    int nOverall_Rank; // ��ü ��� ���� //
} nStudent;

// �л� ������ ���Ͽ��� �б� //
void nLoad_Students_From_File(const char* nFile_Name, nStudent nStudents[nSTUDENTS], int* nStudent_Count)
{
    FILE* nFile;

    if (fopen_s(&nFile, nFile_Name, "r") != 0)
    {
        perror("���� ���� ����");
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
            break; // �ִ� �л� �� ���� //
    }

    fclose(nFile);
}

// ��� ��� �Լ� //
void nCalculate_Averages(nStudent nStudents[nCLASSES][nSTUDENTS], int nStudent_Counts[], double dClass_Avg[], double* dOverall_Avg)
{
    double dTotal_Sum = 0; // ��ü �հ� //
    int nTotal_Students = 0; // ��ü �л� �� //

    for (int i = 0; i < nCLASSES; i++) // �� �ݿ� ���� �ݺ� //
    {
        double dClass_Sum = 0; // �ݺ� �հ� //
        for (int j = 0; j < nStudent_Counts[i]; j++) // �� �л��� ���� �ݺ� //
        {
            int nStudent_Sum = 0; // �л� ���� �հ� //
            for (int k = 0; k < nSUBJECTS; k++) // �� ���� ���� �ݺ� //
            {
                nStudent_Sum += nStudents[i][j].nScores[k]; // ���� �ջ� //
            }
            nStudents[i][j].dAverage = nStudent_Sum / (double)nSUBJECTS; // �л� ��� ��� //
            dClass_Sum += nStudents[i][j].dAverage; // �� ��տ� �߰� //
        }
        dClass_Avg[i] = dClass_Sum / nStudent_Counts[i]; // �� ��� ��� //
        dTotal_Sum += dClass_Sum; // ��ü �հ� �߰� //
        nTotal_Students += nStudent_Counts[i]; // ��ü �л� �� �߰� //
    }

    *dOverall_Avg = dTotal_Sum / nTotal_Students; // ��ü ��� ��� //
}

// ��� ��� �Լ� //
void nCalculate_Ranks(nStudent nStudents[nCLASSES][nSTUDENTS], int nStudent_Counts[])
{
    // �й� ��� ��� //
    for (int i = 0; i < nCLASSES; i++)
    {
        for (int j = 0; j < nStudent_Counts[i]; j++)
        {
            int nRank = 1; // �ʱ� ��� ���� //
            for (int k = 0; k < nStudent_Counts[i]; k++)
            {
                if (nStudents[i][k].dAverage > nStudents[i][j].dAverage)
                {
                    nRank++; // �� ���� ������ ������ ��� ���� //
                }
            }
            nStudents[i][j].nClass_Rank = nRank; // �й� ��� ���� //
        }
    }

    // ��ü ��� ��� //
    nStudent nAll_Students[nCLASSES * nSTUDENTS]; // ��ü �л� �迭 //
    int nTotal_Students = 0; // ��ü �л� �� �ʱ�ȭ //
    for (int i = 0; i < nCLASSES; i++)
    {
        for (int j = 0; j < nStudent_Counts[i]; j++)
        {
            nAll_Students[nTotal_Students++] = nStudents[i][j]; // ��� �л� �߰� //
        }
    }

    for (int i = 0; i < nTotal_Students; i++)
    {
        int nRank = 1; // �ʱ� ��� ���� //
        for (int j = 0; j < nTotal_Students; j++)
        {
            if (nAll_Students[j].dAverage > nAll_Students[i].dAverage)
            {
                nRank++; // �� ���� ������ ������ ��� ���� //
            }
        }
        nAll_Students[i].nOverall_Rank = nRank; // ��ü ��� ���� //
    }

    // ��ü ����� ���� �迭�� ���� //
    for (int i = 0; i < nCLASSES; i++)
    {
        for (int j = 0; j < nStudent_Counts[i]; j++)
        {
            for (int k = 0; k < nTotal_Students; k++)
            {
                if (nStudents[i][j].nID == nAll_Students[k].nID)
                {
                    nStudents[i][j].nOverall_Rank = nAll_Students[k].nOverall_Rank; // ��ü ��� ���� //
                    break;
                }
            }
        }
    }
}

void nSave_Results(const char* nFile_Name, nStudent nStudents[nSTUDENTS], int nStudent_Count)
{
    FILE* nFile;
    if (fopen_s(&nFile, nFile_Name, "w") != 0) //��� ���� ����� �Լ� //
    {
        perror("��� ���� ���� ����");
        exit(1);
    }

    for (int i = 0; i < nStudent_Count; i++)
    {
        fprintf(nFile, "�й�: %d\n", nStudents[i].nID);
        fprintf(nFile, "�̸�: %s\n", nStudents[i].nName);
        fprintf(nFile, "����: %d\n", nStudents[i].nScores[nKOREAN]);
        fprintf(nFile, "����: %d\n", nStudents[i].nScores[nMATH]);
        fprintf(nFile, "����: %d\n", nStudents[i].nScores[nENGLISH]);
        fprintf(nFile, "���: %.2f\n", nStudents[i].dAverage);
        fprintf(nFile, "�й� ���: %d\n", nStudents[i].nClass_Rank);
        fprintf(nFile, "��ü ���: %d\n\n", nStudents[i].nOverall_Rank);
    }
    fclose(nFile);
}

void nSave_Class_Results(const char* nFile_Name, double dClass_Avg[], double dOverall_Avg)
{
    FILE* nFile;
    if (fopen_s(&nFile, nFile_Name, "w") != 0)
    {
        perror("��� ���� ���� ����");
        exit(1);
    }

    fprintf(nFile, "�й� 1 ���: %.2f\n", dClass_Avg[0]);
    fprintf(nFile, "�й� 2 ���: %.2f\n", dClass_Avg[1]);
    fprintf(nFile, "��ü ���: %.2f\n", dOverall_Avg);
    fclose(nFile);
}

int main()
{
    nStudent nStudents[nCLASSES][nSTUDENTS];
    int nStudent_Counts[nCLASSES] = { 0 }; // �� ���� �л� �� //
    double dClass_Avg[nCLASSES] = { 0 }; // �ݺ� ��� //
    double dOverall_Avg = 0; // ��ü ��� //

    // �л� ������ ���Ͽ��� �б� //
    nLoad_Students_From_File("students_1.txt", nStudents[0], &nStudent_Counts[0]);
    nLoad_Students_From_File("students_2.txt", nStudents[1], &nStudent_Counts[1]);

    // ��� �� ��� ��� //
    nCalculate_Averages(nStudents, nStudent_Counts, dClass_Avg, &dOverall_Avg);
    nCalculate_Ranks(nStudents, nStudent_Counts);

    // ��� ���� ���� //
    nSave_Results("students_1_results.txt", nStudents[0], nStudent_Counts[0]);
    nSave_Results("students_2_results.txt", nStudents[1], nStudent_Counts[1]);
    nSave_Class_Results("class_results.txt", dClass_Avg, dOverall_Avg);

    printf("��� ������ ���������� �����Ǿ����ϴ�.\n");

    return 0; // ���α׷� ���� //
}
