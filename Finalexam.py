import turtle as t      #turtle 모듈 사용
import random           #random 모듈 사용
import time             #time 모듈 사용

#2*2 터틀 객체 생성
def level_1():   
    position_x = [-250, 250]     # 2*2 터틀 객체의 x좌표
    position_y = [-300, 100]     # 2*2 터틀 객체의 y좌표

    for i in range(2):              #2*2(4개 좌표) 좌표를 얻기 위한 이중 for 문
        for j in range(2):
            size1_turtle = t.Turtle()   #size1_turtle 객체 생성      
            size1_turtle.pencolor("black")  #배경색과 같은 black
            size1_turtle.speed(0)       #속도는 최대속도
            size1_turtle.up()       #펜 이동 시 그리지 않음
            size1_turtle.goto(position_x[i], position_y[j])  #생성한 (x, y)좌표로 이동
            turtles.append(size1_turtle)    #turtles list에 size1_turtle 추가

#4*4 터틀 객체 생성
def level_2():
    position_x = [-400, -150, 100, 350]     # 4*4 터틀 객체의 x좌표
    position_y = [-400, -170, 30, 260]      # 4*4 터틀 객체의 y좌표

    for i in range(4):                  #4*4(16개 좌표) 좌표를 얻기 위한 이중 for 문
        for j in range(4):
            size1_turtle = t.Turtle()     #size1_turtle 객체 생성
            size1_turtle.pencolor("black")     #배경색과 같은 black
            size1_turtle.speed(0)       #속도는 최대속도
            size1_turtle.up()       #펜 이동 시 그리지 않음
            size1_turtle.goto(position_x[i], position_y[j])  #생성한 (x, y)좌표로 이동
            turtles.append(size1_turtle)     #turtles list에 size1_turtle 추가
            
#6*6 터틀 객체 생성  
def level_3():
    position_x = [-400, -240, -80, 80, 240, 400]    # 6*6 터틀 객체의 x좌표
    position_y = [-400, -260, -120, 20, 160, 300]   # 6*6 터틀 객체의 y좌표

    for i in range(6):                    #6*6(36개 좌표) 좌표를 얻기 위한 이중 for 문
        for j in range(6):
            size1_turtle = t.Turtle()       #size1_turtle
            size1_turtle.pencolor("black")    #배경색과 같은 black
            size1_turtle.speed(0)        #속도는 최대속도
            size1_turtle.up()        #펜 이동 시 그리지 않음
            size1_turtle.goto(position_x[i], position_y[j]) #생성한 (x, y)좌표로 이동
            turtles.append(size1_turtle)    #turtles list에 size1_turtle 추가


#카드를 보여주고 다시 뒤집는 함수
def fruit_img():
    global turtles   #전역 list turtles 사용
    global fimg_game_list   #전역 list fig_game_list turtles 사용
    global default_fimg    #전역 변수 default_fimg 사용
    
    default_fimg = "fruit/default.gif" #default 이미지 경로 작성 
    t.addshape(default_fimg)    #default_fimg 이미지를 addshape으로 추가
       
    fimg_list = []      #내가 가진 과일 이미지를 저장할 list 생성
    for i in range(18):      #18번 반복(18개의 이미지 저장)
        fimg = f"fruit/img{i}.gif"  #과일 이미지 경로 작성
        t.addshape(fimg)        #fimg 이미지를 addshape으로 추가
        fimg_list.append(fimg)  #fimg_list에 fimg 이미지 추가
        
    if (level == 1):    #level 1단계를 선택했다면
        fimg_game_list = random.sample(fimg_list, 2)    # fimg_game_list에 fimg_list에 있는 이미지 2개를 랜덤하게 삽입
        for i in range(2):      #2회 반복
            fimg_game_list.append(fimg_game_list[i])    #같은 이미지가 2개 필요하므로 fimg_gmae_list의 요소를 한 번 더 추가
        random.shuffle(fimg_game_list)      #fimg_game_list 안에 있는 요소를 랜덤하게 셔플
        for i in range(4): #2*2이므로 4개의 이미지 추가(반복)      
            turtles[i].shape(fimg_game_list[i])    #turtles의 요소마다 fimg_game_list 요소로 shape 정해줌
        time.sleep(3)   #이미지를 3초만 보여줌
        #그림 뒤집기
        for i in range(4):  #2*2이므로 4개의 이미지 추가    
            turtles[i].shape(default_fimg)      #turtles의 요소마다 default_fimg로 shape 정해줌
    
    elif (level == 2):    #level 2단계를 선택했다면
        fimg_game_list = random.sample(fimg_list, 8)    # fimg_game_list에 fimg_list에 있는 이미지 8개를 랜덤하게 삽입
        for i in range(8):  #8회 반복
            fimg_game_list.append(fimg_game_list[i])    #같은 이미지가 2개 필요하므로 fimg_gmae_list의 요소를 한 번 더 추가
        random.shuffle(fimg_game_list)      #fimg_game_list 안에 있는 요소를 랜덤하게 셔플
        for i in range(16):    #4*4이므로 16개의 이미지 추가(반복)    
            turtles[i].shape(fimg_game_list[i])     #turtles의 요소마다 fimg_game_list 요소로 shape 정해줌
        time.sleep(5)   #이미지를 5초만 보여줌
        #그림 뒤집기
        for i in range(16):   #4*4이므로 16개의 이미지 추가     
            turtles[i].shape(default_fimg)      #turtles의 요소마다 default_fimg로 shape 정해줌

           
    elif (level == 3):    #level 3단계를 선택했다면
        fimg_game_list = random.sample(fimg_list, 18)   # fimg_game_list에 fimg_list에 있는 이미지 18개를 랜덤하게 삽입
        for i in range(18):   #18회 반복
            fimg_game_list.append(fimg_game_list[i])     #같은 이미지가 2개 필요하므로 fimg_gmae_list의 요소를 한 번 더 추가
        random.shuffle(fimg_game_list)          #fimg_game_list 안에 있는 요소를 랜덤하게 셔플
        for i in range(36):     #6*6이므로 36개의 이미지 추가(반복)   
            turtles[i].addshape(fimg_game_list[i])   #turtles의 요소마다 fimg_game_list 요소로 shape 정해줌
        time.sleep(10)    #이미지를 10초만 보여줌
        #그림 뒤집기
        for i in range(36):  #6*6이므로 36개의 이미지 추가     
            turtles[i].shape(default_fimg)      #turtles의 요소마다 default_fimg로 shape 정해줌
            
#점수 업데이트 표시 
def score_update(n):
    score_turtle.clear()    #score_turtle 창에 출력된 것 모두 지움
    #정답/오답, 점수, 시도횟수 출력
    score_turtle.write(f"{n}       {score}점/{attempt}번 시도", False, "center", ("NanumGothic", 10, "bold"))

#결과 업데이트 표시    
def result(n):
    t.goto(0,-60)   #(0, -60)으로 이동
    #결과값 출력
    t.write(f"{n}", False, "center", ("NanumGothic", 30, "bold"))
    

#클릭한 좌표값과 어떤 turtle이 가까운지 맞추는 함수
def find_card(x, y):
    global level       #전역 변수 level 사용
    min_idx = 0        #클릭한 좌표값과 이미지 사이의 거리가 최소일 때 turtles의 인덱스
    min_dis = 100      #임의로 정의한 최소 거리 min_dis
    
    if (level == 1):    #level이 1이라면
        for i in range(4):      #이미지가 4개 이므로 4회 반복
            distance = turtles[i].distance(x, y)   #turtles의 요소와 클릭한 (x, y)좌표 사이의 거리
            #클릭한 좌표값과 turtle 사이의 거리가 최솟 거리값보다 작다면
            if distance < min_dis:  
                min_dis = distance    #최소 거리값 갱신
                min_idx = i     #거리가 최소 거리값 min_idx보다 작을 때 min_idx에 인덱스 i 대입
        return min_idx     #거리가 최소일 때 turtles의 인덱스 값 반환//실제로 클릭한 이미지의 인덱스값
        
    elif(level == 2):   #level이 2라면
        for i in range(16):      #이미지가 16개 이므로 16회 반복 
            distance = turtles[i].distance(x, y)    #turtles의 요소와 클릭한 (x, y)좌표 사이의 거리
            #클릭한 좌표값과 turtle 사이의 거리가 최솟 거리값보다 작다면
            if distance < min_dis:
                min_dis = distance   #최소 거리값 갱신
                min_idx = i     #거리가 최솟 거리값 min_dis보다 작을 때 min_idx에 인덱스 i 대입
        return min_idx     #거리가 최소일 때 turtles의 인덱스 값 반환//실제로 클릭한 이미지의 인덱스값
    
    elif(level == 3):   #level이 3이라면
        for i in range(36):         #이미지가 36개 이므로 36회 반복    
            distance = turtles[i].distance(x, y)    #turtles의 요소와 클릭한 (x, y)좌표 사이의 거리
            #클릭한 좌표값과 turtle 사이의 거리가 최솟 거리값보다 작다면
            if distance < min_dis:
                min_dis = distance   #최소 거리값 갱신
                min_idx = i     #거리가 최솟 거리값 min_dis보다 작을 때 min_idx에 인덱스 i 대입
        return min_idx     #거리가 최소일 때 turtles의 인덱스 값 반환//실제로 클릭한 이미지의 인덱스값
        

def play(x, y):
    #전역 변수 click_num, score, attemp, first_pick, second_pick 사용
    global click_num      
    global score
    global attempt
    global first_pick
    global second_pick

    #level이 1이라면    
    if (level == 1) :  
        if attempt == 3:        #시도 횟수는 3회로 제한
            result("Game Over")     #3회를 넘기면 result("Game Over") 함수 호출
        else :                  #시도 횟수가 3회가 아닌 경우
            click_num = click_num + 1   #클릭 때마다 클릭 횟수 증가
            #클릭 이미지 찾기
            card_index = find_card(x, y)    #find_card(x, y) 함수의 결과를 card_index에 삽입//클릭한 이미지의 인덱스값 저장
            turtles[card_index].shape(fimg_game_list[card_index]) #클릭한 이미지 값을 보여줌

            #첫 번째 클릭 시
            if click_num == 1:
                first_pick = card_index      
            #두 번째 클릭 시
            elif click_num == 2:
                second_pick = card_index
                click_num = 0       #click_num 초기화
                attempt = attempt + 1    #이미지를 두 개 클릭했으므로 시도횟수 1개 증가
                
                #첫 번째 클릭한 이미지의 경로와 두 번째 클릭한 이미지의 경로가 같다면
                if fimg_game_list[first_pick] == fimg_game_list[second_pick]:
                    #정답처리
                    score += 1
                    score_update("정답")      #score_update("정답")함수 호출
                    if score == 2:  #정답을 모두 맞췄다면
                        result("Success!")      #Success! 출력
                else:
                    #오답처리
                    score_update("오답")      #score_update("오답")함수 호출
                    turtles[first_pick].shape(default_fimg)     #첫 번째 클릭한 이미지를 기본이미지로 바꿈
                    turtles[second_pick].shape(default_fimg)     #두 번째 클릭한 이미지를 기본이미지로 바꿈
            
    #level이 2이라면   
    elif (level == 2): 
        if attempt == 12:        #시도 횟수는 12회로 제한
            result("Game Over")     #12회를 넘기면 result("Game Over") 함수 호출
        else :               #시도 횟수가 12회가 아닌 경우
            click_num = click_num + 1   #클릭 때마다 클릭 횟수 증가
            #클릭 이미지 찾기
            card_index = find_card(x, y)    #find_card(x, y) 함수의 결과를 card_index에 삽입//클릭한 이미지의 인덱스값 저장
            turtles[card_index].shape(fimg_game_list[card_index]) #클릭한 이미지 값을 보여줌

            #첫 번째 클릭 시
            if click_num == 1:
                first_pick = card_index
            #두 번째 클릭 시
            elif click_num == 2:
                second_pick = card_index
                click_num = 0       #click_num 초기화
                attempt = attempt + 1    #이미지를 두 개 클릭했으므로 시도횟수 1개 증가

                #첫 번째 클릭한 이미지의 경로와 두 번째 클릭한 이미지의 경로가 같다면
                if fimg_game_list[first_pick] == fimg_game_list[second_pick]:
                    #정답처리
                    score += 1
                    score_update("정답")      #score_update("정답")함수 호출
                    if score == 8:      #정답을 모두 맞췄다면
                        result("Success!")      #Success! 출력
                else:
                    #오답처리
                    score_update("오답")      #score_update("오답")함수 호출
                    turtles[first_pick].shape(default_fimg)     #첫 번째 클릭한 이미지를 기본이미지로 바꿈
                    turtles[second_pick].shape(default_fimg)     #두 번째 클릭한 이미지를 기본이미지로 바꿈
    #level이 3이라면     
    elif(level == 3):
        if attempt == 25:        #시도 횟수는 25회로 제한
            result("Game Over")     #25회를 넘기면 result("Game Over") 함수 호출
        else :               #시도 횟수가 25회가 아닌 경우
            click_num = click_num + 1   #클릭 때마다 클릭 횟수 증가
            #클릭된 이미지 찾기
            card_index = find_card(x, y)    #find_card(x, y) 함수의 결과를 card_index에 삽입//클릭한 이미지의 인덱스값 저장
            turtles[card_index].shape(fimg_game_list[card_index]) #클릭한 이미지 값을 보여줌

            #첫 번째 클릭 시
            if click_num == 1:
                first_pick = card_index
            #두 번째 클릭 시
            elif click_num == 2:
                second_pick = card_index
                click_num = 0       #click_num 초기화
                attempt = attempt + 1    #이미지를 두 개 클릭했으므로 시도횟수 1개 증가

                if fimg_game_list[first_pick] == fimg_game_list[second_pick]:
                    #정답처리
                    score += 1
                    score_update("정답")      #score_update("정답")함수 호출
                    if score == 18:      #정답을 모두 맞췄다면
                        result("Success!")      #Success! 출력
                else:
                    #오답처리
                    score_update("오답")      #score_update("오답")함수 호출
                    turtles[first_pick].shape(default_fimg)     #첫 번째 클릭한 이미지를 기본이미지로 바꿈
                    turtles[second_pick].shape(default_fimg)     # 번째 클릭한 이미지를 기본이미지로 바꿈
            

#첫 시작 화면 생성
t.title("기억력 test")   #창 이름-기억력 test 작성
t.bgcolor("black")       #창 배경화면 색을 검정색 바꾼다
t.setup(1000, 1000)      #그래픽 창 크기를 지정
t.ht()                   #거북이를 숨김
t.up()                   #펜을 올려 이동하면서 선을 그리지 않는다 
t.goto(0,400)               # (0, 400)으로 이동
t.pencolor("white")         # 펜색깔 white로 설정
t.write("카드 매칭 게임", False, "center", ("NanumGothic", 40, "bold")) # 카드 매칭 게임 문자 출력


#level 설정
level_input = t.textinput("", "몇 단계를 원하시나요?(1: 2*2  2: 4*4   3: 6*6)") #사용자 입력 창 만들기 
level = int(level_input)   #입력받은 문자열을 정수형으로 변환

#변수 생성
click_num = 0 #클릭 횟수
score = 0 #점수
attempt = 0 #시도 횟수
first_pick = "" #첫 번째 이미지 선택
second_pick = "" #두 번째 이미지 선택

#점수 펜 객체 생성
score_turtle = t.Turtle()   #score_turtle 객체 생성
score_turtle.penup()        #score_turtle의 펜을 올려 이동하면서 선을 그리지 않음
score_turtle.ht()           #score_turtle의 거북이를 숨김
score_turtle.goto(0, 380)   #(0, 380)으로 이동
score_turtle.pencolor("yellow")     #pen 색깔을 yellow


turtles = []    #전역 리스트 turtles 생성
fimg_game_list = []     #전역 리스트 fimg_game_list 생성

#선택한 level에 따라 실행하는 문장 다름(2*2, 4*4, 6*6)
if level == 1:      #level이 1이라면
    level_1()       #2*2 터틀 객체 생성 함수
    fruit_img()     #카드 보여주고 다시 뒤집는 함수
    t.onscreenclick(play)    #화면을 클릭했을 때 play함수 실행

elif level == 2:    #level이 2이라면
    level_2()       #4*4 터틀 객체 생성 함수
    fruit_img()     #카드 보여주고 다시 뒤집는 함수
    t.onscreenclick(play)    #화면을 클릭했을 때 play함수 실행
    
elif level == 3:    #level이 3이라면
    level_3()       #6*6 터틀 객체 생성 함수
    fruit_img()     #카드 보여주고 다시 뒤집는 함수
    t.onscreenclick(play)   #화면을 클릭했을 때 play함수 실행        
