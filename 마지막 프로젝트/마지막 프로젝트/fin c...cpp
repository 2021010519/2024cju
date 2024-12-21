#include <stdio.h> // �̻��ü ���� ������ ���ϴ� �Լ� //
#include <math.h> //���翡���� PV=nRT���� PV=mRT�� �� ���� ����Ͽ� ���ڸ� ���ϴ� �Լ��� ���� //
//��빮 ����ü, �迭�� ������, case��, if��, for��, �Լ� ��� ��. //

#define R_WATER_VAPOR 461.5 // ������ ��ü ��� (J/(kg*K))
#define R_NITROGEN 296.8     // ���� ��ü ��� (J/(kg*K))
#define R_AIR 287.0          // ���� ��ü ��� (J/(kg*K))

// �̻� ��ü ���¸� �����ϴ� ����ü ���� //
typedef struct
{
    double dPressure;     // �з� kPa)//
    double dVolume;       // ���� (m^3)//
    double dTemperature;  // �µ� (K)//
    double dMass;         // ���� (kg)//
} Gas_State;

// �̻� ��ü ���¿��� ������ ���� ����ϴ� �Լ� //
double dCalculate_Missing_Value(Gas_State* state, double dR, int nMissing_Index) 
{
    switch (nMissing_Index)
    {
    case 1: // �з� ���//
        state->dPressure = (state->dMass * dR * state->dTemperature) / state->dVolume;
        return state->dPressure;
    case 2: // ���� ���//
        state->dVolume = (state->dMass * dR * state->dTemperature) / state->dPressure;
        return state->dVolume;
    case 3: // �µ� ���//
        state->dTemperature = (state->dPressure * state->dVolume) / (state->dMass * dR);
        return state->dTemperature;
    case 4: // ���� ���//
        state->dMass = (state->dPressure * state->dVolume) / (dR * state->dTemperature);
        return state->dMass;
    default:
        printf("�߸��� �����Դϴ�.\n");
        return -1;
    }
}

int main() 
{
    Gas_State state = {}; // ����ü �ʱ�ȭ //
    double* dValues[4] = { &state.dPressure, &state.dVolume, &state.dTemperature, &state.dMass }; // ���°��� ���� ������ �迭 //
    int nMissing_Index; // ����ϰ��� �ϴ� ���·� //
    double dR; // ���õ� ��ü�� ��ü ���//
    int nGas_Type; // ����� ������ ��ü ���� //

    // ��ü ���� ����, ������ ����� 3���� ��ü�� ���� R���� �䱸�ϱ⿡ 3������ ���� //
    printf("����ϰ��� �ϴ� ������ ��ü�� ����ּ���. :\n"); 
    printf("1. ������\n2. ����\n3. ����\n");
    printf("�Է�: ");
    scanf_s("%d", &nGas_Type);

    // ���õ� ��ü�� ���� ��ü ����� ���� //  
    switch (nGas_Type) 
    {
    case 1:
        dR = R_WATER_VAPOR;
        break;
    case 2:
        dR = R_NITROGEN;
        break;
    case 3:
        dR = R_AIR;
        break;
    default:
        printf("�߸��� ��ü �����Դϴ�. ���α׷��� �����մϴ�.\n");
        return 1;
    }

    // ����ϰ��� �ϴ� ���·� ���� ��û �׿� ���缭 ��� �Լ� ¥�� //
    printf("����ϰ��� �ϴ� ���·��� �����ϼ���:\n");
    printf("1. �з� (Pa)\n2. ���� (m^3)\n3. �µ� (K)\n4. ���� (kg)\n");
    printf("�Է�: ");
    scanf_s("%d", &nMissing_Index);

    if (nMissing_Index < 1 || nMissing_Index > 4) // 1~3�Է� �������� ����//
    {
        printf("�߸��� �Է��Դϴ�.\n");
        return 1;
    }

    // ������ ���·� �� �Է� //
    for (int i = 0; i < 4; i++) 
    {
        if (i + 1 == nMissing_Index) continue; // ����ؾ� �ϴ� ���·� ���� �Է¹��� ����//

        printf("%s�� �Է��ϼ���: ", i == 0 ? "�з� (Pa)" : i == 1 ? "���� (m^3)" : i == 2 ? "�µ� (K)" : "���� (kg)");
        scanf_s("%lf", dValues[i]);
    }

    // ��� �Լ� ���//
    double dResult = dCalculate_Missing_Value(&state, dR, nMissing_Index);
    if (dResult != -1) 
    {
        printf("\n��� ���:\n");
        printf("%s: %.2lf\n", nMissing_Index == 1 ? "�з� (Pa)" : nMissing_Index == 2 ? "���� (m^3)" : nMissing_Index == 3 ? "�µ� (K)" : "���� (kg)", dResult);
    }

    return 0;
}
