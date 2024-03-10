'''
교과목 : 데이터 마이닝(SW)
분 반 : 1분반
교수님 : 박용범 교수님
이름 : 최서영
제출일 : 2024.03.11

과제1
'''

def findLine(x1, y1, x2, y2):
    m = (y2 - y1)/(x2 - x1)
    a = -m * x1 + y1

    if(a > 0):
        print("y = ", m , "x + ", a)
    elif(a == 0):
        print("y = ",m ,"x")
    else:
        print("y = ", m , "x -", abs(a))


#평면의 두 좌표는 사용자로부터 입력 받는다고 가정하였습니다
firstInput = input("첫 번째 좌표를 입력하시요(공백으로 x, y 구분): ")
secondInput = input("두 번째 좌표를 입력하시오(공백으로 x, y 구분): ")

x1 = int(firstInput.split(" ")[0])
y1 = int(firstInput.split(" ")[1])
x2 = int(secondInput.split(" ")[0])
y2 = int(secondInput.split(" ")[1])

#직선의 방정식 함수
findLine(x1, y1, x2, y2)