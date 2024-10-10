#include <stdio.h>

int main() 
{
    double ro;//roll의 앞글자를 따옴//
    double ph;//원래 pt로 하려했으나 플레티넘이라는 약자가 있음으로 ph로함//
    double yw;//yw로 간추려서씀//

    printf("Input roll/pitch/yaw angle: ");
    //값을 입력받음//
    scanf_s("%lf %lf %lf",&ro, &ph, &yw);
    //각도는 소수점까지 사용하기에실수로 받음//
    ro -= 360 * int(ro / 360);
    ph -= 360 * int(ph / 360);
    yw -= 360 * int(yw / 360);
    //값을 정수화한 후 360로 나누어 원래 값에 빼줌 -> 0~360로 주기화 함//
    ro = (ro > 180) ? ro -360 : ro;
    ph = (ph > 180) ? ph -360 : ph;
    yw = (yw > 180) ? yw -360 : yw;
    //180도가 넘어간다면 -360을 해주어 0~360을 -180~180으로 범위를 바꿈//




    printf("%.1lf %.1lf %.1lf", ro, ph, yw);
    //보기 편하게 소수점 한자리 아래로는 다 날려버림//

    return 0;
}