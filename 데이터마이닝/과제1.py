'''
������ : ������ ���̴�(SW)
�� �� : 1�й�
������ : �ڿ�� ������
�̸� : �ּ���
������ : 2024.03.11

����1
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


#����� �� ��ǥ�� ����ڷκ��� �Է� �޴´ٰ� �����Ͽ����ϴ�
firstInput = input("ù ��° ��ǥ�� �Է��Ͻÿ�(�������� x, y ����): ")
secondInput = input("�� ��° ��ǥ�� �Է��Ͻÿ�(�������� x, y ����): ")

x1 = int(firstInput.split(" ")[0])
y1 = int(firstInput.split(" ")[1])
x2 = int(secondInput.split(" ")[0])
y2 = int(secondInput.split(" ")[1])

#������ ������ �Լ�
findLine(x1, y1, x2, y2)