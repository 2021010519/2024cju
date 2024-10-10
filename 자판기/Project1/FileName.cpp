#include <stdio.h>

// 가정, 10원짜리 및 50원 짜리는 인식 안함, 자판기는 지폐만 동전과 지폐만 되기 때문에 10486원 같이 지폐와 동전으로 측정할 수 없는 값 입력 불가능//
int main(void)
{
	int res;
	int ch; //cash의 줄은말 투입값//
	int pay; //지불값 영어로//
	int rm; //remainder 줄임말//

	printf("input Investment amount and Price of goods");
	scanf_s("%d%d", &ch, &pay);
	if (pay < ch) {
		
		rm = ch - pay;
		//잔돈= 물건값-투입값//
		printf("천원 %d장\n", rm / 1000);

		rm = rm % 1000;

		printf("500원 %d장\n", rm / 500);

		rm = rm % 500;
		printf("100원 %d장\n", rm / 100);

		rm = rm % 100;
		
	}
	else {
		printf("잔액이 부족합니다.");
	}
	return 0;
	

}