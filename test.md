#### 42Seoul_Factorization_Event

* DESCRIPTION
```
어떤 숫자 하나를 명령어 라인 인자로 입력하면 해당 숫자를 소인수 분해해서, 결과적으로 나오는 소수들을 작은 수에서 큰 수의 순서대로 딱 한번씩만 차례로 출력하는 프로그램 짜기입니다. 입력으로 들어가는 수는 1보다 큰 32bit unsigned integer (즉 2 부터 2^32 -1 까지)만 허용, 그 밖의 입력에 대해서는 에러메시지 출력. 참 쉽죠?
```

* TEST1 - 기본 입력
<img width="535" alt="fact1" src="https://user-images.githubusercontent.com/20695892/78258695-8f3c5100-7536-11ea-83d2-b0e52c8f4320.PNG">

* TEST2 - 특수 입력에 따른 정상출력/예외처리
<img width="526" alt="fact2" src="https://user-images.githubusercontent.com/20695892/78258707-95323200-7536-11ea-9511-9da6a651c3e6.PNG">

* TEST3 - 입력 개수에 따른 예외처리
<img width="547" alt="fact3" src="https://user-images.githubusercontent.com/20695892/78258709-96635f00-7536-11ea-958e-9f4063daf03b.PNG">

* 예외 케이스
```
argument count가 2개 미만/초과인 예외 케이스
input이 음수, 0, 1이거나, UINT_MAX(2^32-1) 초과 케이스
input에 숫자가 아닌 다른 문자가 들어간 케이스
```
