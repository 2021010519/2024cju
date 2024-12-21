#include <stdio.h> // 이상기체 상태 방정식 구하는 함수 //
#include <math.h> //교재에서는 PV=nRT보단 PV=mRT를 더 많이 사용하여 후자를 구하는 함수로 만듬 //
//사용문 구조체, 배열과 포인터, case문, if문, for문, 함수 사용 함. //

#define R_WATER_VAPOR 461.5 // 수증기 기체 상수 (J/(kg*K))
#define R_NITROGEN 296.8     // 질소 기체 상수 (J/(kg*K))
#define R_AIR 287.0          // 공기 기체 상수 (J/(kg*K))

// 이상 기체 상태를 저장하는 구조체 정의 //
typedef struct
{
    double dPressure;     // 압력 kPa)//
    double dVolume;       // 부피 (m^3)//
    double dTemperature;  // 온도 (K)//
    double dMass;         // 질량 (kg)//
} Gas_State;

// 이상 기체 상태에서 누락된 값을 계산하는 함수 //
double dCalculate_Missing_Value(Gas_State* state, double dR, int nMissing_Index) 
{
    switch (nMissing_Index)
    {
    case 1: // 압력 계산//
        state->dPressure = (state->dMass * dR * state->dTemperature) / state->dVolume;
        return state->dPressure;
    case 2: // 부피 계산//
        state->dVolume = (state->dMass * dR * state->dTemperature) / state->dPressure;
        return state->dVolume;
    case 3: // 온도 계산//
        state->dTemperature = (state->dPressure * state->dVolume) / (state->dMass * dR);
        return state->dTemperature;
    case 4: // 질량 계산//
        state->dMass = (state->dPressure * state->dVolume) / (dR * state->dTemperature);
        return state->dMass;
    default:
        printf("잘못된 선택입니다.\n");
        return -1;
    }
}

int main() 
{
    Gas_State state = {}; // 구조체 초기화 //
    double* dValues[4] = { &state.dPressure, &state.dVolume, &state.dTemperature, &state.dMass }; // 상태값에 대한 포인터 배열 //
    int nMissing_Index; // 계산하고자 하는 상태량 //
    double dR; // 선택된 기체의 기체 상수//
    int nGas_Type; // 사용자 선택한 기체 종류 //

    // 기체 종류 선택, 열역학 교재는 3가지 기체에 대한 R값만 요구하기에 3가지만 설정 //
    printf("계산하고자 하는 문제의 기체를 골라주세요. :\n"); 
    printf("1. 수증기\n2. 질소\n3. 공기\n");
    printf("입력: ");
    scanf_s("%d", &nGas_Type);

    // 선택된 기체에 따라 기체 상수를 설정 //  
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
        printf("잘못된 기체 종류입니다. 프로그램을 종료합니다.\n");
        return 1;
    }

    // 계산하고자 하는 상태량 선택 요청 그에 맞춰서 계산 함수 짜기 //
    printf("계산하고자 하는 상태량을 선택하세요:\n");
    printf("1. 압력 (Pa)\n2. 부피 (m^3)\n3. 온도 (K)\n4. 질량 (kg)\n");
    printf("입력: ");
    scanf_s("%d", &nMissing_Index);

    if (nMissing_Index < 1 || nMissing_Index > 4) // 1~3입력 안했으면 오류//
    {
        printf("잘못된 입력입니다.\n");
        return 1;
    }

    // 나머지 상태량 값 입력 //
    for (int i = 0; i < 4; i++) 
    {
        if (i + 1 == nMissing_Index) continue; // 계산해야 하는 상태량 값은 입력받지 않음//

        printf("%s를 입력하세요: ", i == 0 ? "압력 (Pa)" : i == 1 ? "부피 (m^3)" : i == 2 ? "온도 (K)" : "질량 (kg)");
        scanf_s("%lf", dValues[i]);
    }

    // 계산 함수 사용//
    double dResult = dCalculate_Missing_Value(&state, dR, nMissing_Index);
    if (dResult != -1) 
    {
        printf("\n계산 결과:\n");
        printf("%s: %.2lf\n", nMissing_Index == 1 ? "압력 (Pa)" : nMissing_Index == 2 ? "부피 (m^3)" : nMissing_Index == 3 ? "온도 (K)" : "질량 (kg)", dResult);
    }

    return 0;
}
