# 321
print(set(input()))

# 322
lst1= ['id', 'color', 'type']; lst2 = [100, 'red', 1]
print( dict(zip(lst1,lst2)) )




###########################################################




# 411
a = input("문자열1 : ")
b = input("문자열2 : ")
if a < b:
    print("True")
else:
    print("False")

# 412
if [0]:
    print("True", end=" ")
else:
    print("False", end=" ")

if {0}:
    print("True", end=" ")
else:
    print("False", end=" ")

if -1:
    print("True", end=" ")
else:
    print("False", end=" ")

if 0.01:
    print("True", end=" ")
else:
    print("False", end=" ")
print()

# 413
num = int(input("정수를 입력: "))
if (num % 2 == 0) and (num % 5 == 0):
    print(f'{num}은(는) 짝수이면서 5의 배수이다.')
else:
    print(f'{num}은(는) 짝수 또는 5의 배수가 아니다.')

# 422
grade = int(input("성적: "))
if grade >= 80:
    print(150000)
else:
    print(100000)




###########################################################



# 4241
age = int(input('your age : '))
if age<= 7 or age>=65:
    en_fee = 0
elif 8 <= age <= 19:
    en_fee = 300
else :
    en_fee = 500
print(f'나이: {age} 입장료: {en_fee}원')

# 4242
score = float(input("학점은? "))
grade = 'A'
if score < 2.0:
    grade = 'D'
elif score < 3.0:
    grade = 'C'
elif score < 4.0:
    grade = 'B'

print(f'학점: {score}, 등급: {grade}')

# 15~20세 미만 청소년 확인
birthYear = input("태어난 년도를 입력하세요(YYYY) : ")
if len(birthYear) != 4:
    print("잘못 입력했습니다. 네 자리로 입력하세요!!")
else:
    age = 2021 - int(birthYear)
    print(f'당신의 나이는 {age}세 입니다.')
    if 15 <= age < 20:
        print('당신은 청소년이군요!!')
    else:
        print('당신은 청소년이 아닙니다!')

# 주차료 계산
is_small_car = input("경차이면 'y 또는 Y' 입력 : ")
print()
is_small_car = is_small_car.upper()
if is_small_car != 'Y':
    is_small_car = 'N'

park_time = int(input("주차시간 입력(분단위) : "))
print()

expense = 0
if park_time <= 10:
    expense = 0
elif park_time <= 30:
    expense = 500
else:
    expense = 500 + ((park_time-30) // 10 * 200)

if is_small_car == 'Y':
    expense /= 2

print(f'경차 : {is_small_car}')
print(f'주차시간 : {park_time}분')
print(f'주차요금 : {expense}원')

# 실습 5111
x = [i for i in range(1, 21)]
for xe in x:
    if xe % 2 != 0:
        print(xe)

# 실습 5112
fruit = ['apple', 'cherry', 'banana']
for f in fruit:
    print(f'{f} : {len(f)}')

# 실습 512-1
n = int(input('수입력: '))
L = list(range(1, n + 1, 2))
for i in L :
    print(i, end=' ')

# 실습 512-2
L = [chr(a + 97) for a in range(26)]
for n in L:
    if ord(n) % 2 != 0:
        print(f'{n} : {ord(n)}')

# 실습 513
for n in range(10):
    print(n, end=' ')
    [print('*',end='') for j in range(11)]
    print( )

# 실습 513 응용
for j in range(1, 10):
    for k in range(j):
        print('*', end='')
    for k in range(10 - j):
        print(' ', end='')

    for k in range(10 - j):
        print('*', end='')
    for k in range(j):
        print(' ', end='')
    print()




###########################################################



# 514
dan = int(input('정수입력: '))
print(f'입력한 단 : {dan}')
for i in range(1,10):
    print(dan, '*',i, '=', dan*i)
print()

# 514-1
dan = int(input("정수입력:"))
print("{0:=<40}".format(f"{dan} 단 출력 "))
for i in range(1, 10):
    if i % 3 == 0 :
        print(f"{dan} * {i} = {dan * i}")
    else :
        print(f"{dan} * {i} = {dan * i}", end='\t')

# 514-2
for i in range(1, 10):
    for j in range(2, 10):
        str = f'{i} * {j} = {i * j}'
        print(f'{str:15}', end='')
    print()

print("===========================================")
for i in range(2, 10):
    for j in range(1, 10):
        str = f'{i} * {j} = {i * j}'
        print(f'{str:15}', end='')
    print()

# 515-1
star = 1 # 별의 수 초기화
blank = 5 # 공백의 수 초기화
line = 6 # 별을 출력할 라인의 수
for _ in range(line):
    for _ in range(blank):
        print("\u3000", end = "")
    blank = blank - 1

    for _ in range(star):
        print("\u2605", end = "")
    star = star + 2
    print()

# 515-2
n = int( input('양의 홀수 입력: ') )
center = int(n/2)
for i in range(center+1):
    for k in range(center-i):
        print(' ', end='')
    for k in range(2*i+1):
        print('*', end='')
    print()

# 515-31
num=int(input('정수입력: ' ))
print()
for n in range(1,num+1) :
    if n==1: print(n)
    else :
        for k in range(1,n+1):
            print('*', end='')
        print(n, end='')
        print()

# 515-32
num=int(input('정수입력: ' ))
print()
for n in range(num+1) :
    if n == 0:
        print(n)
    else:
        for k in range(1,n+1):
            print('*', end='')
        print(n, end='')
        print()

# 515-33
num=int(input('정수입력: ' ))
print()
for n in range(num, 0, -1) :
    if n == 1:
        print(n)
    else:
        for k in range(n-1):
            print('*', end='')
        print(n, end='')
        print()

# 516
fruits = ['apple', 'orange', 'peach', 'pineapple', 'melon', 'grape', 'orientalmelon', 'avocado']
dic = dict()
for fruit in fruits:
    li = dic.get(fruit[0], [])
    li.append(fruit)
    dic[fruit[0]] = li

for key, value in dic.items():
    print(f'{key} : {value}')




###########################################################



# 521-1
n = int(input())
i = 0
while i <= n:
    if i % 2 == 0:
        print(i, end=" ")

    i += 1
print()

# 521-1
n = int(input())
i = 0
while i <= n:
    if i % 2 == 0 and i % 3 == 0:
        print(i, end=" ")

    i += 1
print()

# 521-3
d = int(input('십진수 정수: '))
b = [] ; d1 = d ; m = d
while True:
    d, m = divmod(d, 2)
    b.insert(0, m)
    if d == 0:
        break
    print(f'십진수 {d1} = 몫 {d}, 나머지 {b}')
print(f'십진수 {d1} = 이진수 {b}')

# 523
i=0
while i < 5:
    j=0
    while j < 10:
        print('*', end='')
        j += 1
    print()
    i += 1

# 523-1
n = int(input("별 수 입력: "))

i = n
while i > 0:
    print("*" * i)
    i -= 1

# 523-2
n = int(input("별 수 입력: "))

i = 1
while i <= n:
    print(i, end="")
    print("*" * i)
    i += 1
print()

i = n
while i > 0:
    print(i, end="")
    print("*" * i)
    i -= 1

# 523-3
n = int(input("별 수 입력: "))

i = n
while i > 0:
    print(i, end="")
    print("*" * i)
    i -= 1
print()

i = 1
while i <= n:
    print(i, end="")
    print("*" * i)
    i += 1

# break
sum, i = 0, 1
while i <= 100:
    sum += i
    if sum >= 1000:
        break
    i += 1
print("1~100의 합계를 최초로 1000이 넘게 하는 숫자 :", i)

# 4
i = 500
cnt = 0
while i <= 1000:
    j = 2
    prime = True
    while j < i:
        if i % j == 0:
            prime = False
            break

        j += 1

    if prime:
        print(i)
        cnt += 1

    i += 1
print(f'소수 개수: {cnt}')

# 10
nRow=2; nCol=3; mid = int( (nRow-1)/2 )
a = [[1,2,3],[4,5,6]]; b = [[1,1,1],[2,2,2]]; c = [[0,0,0],[0,0,0]]

for row in range(nRow):
    for col in range(nCol):
        c[row][col] = a[row][col] + b[row][col]

for row in range(nRow):
    for col in range(nCol):
        print(c[row][col], end=" ")
    print()



###########################################################



import random

# random(), continue
numLst = []
sum=0
while len(numLst) < 10:
    num = random.randint(1, 100)
    if num in numLst:
        continue
    numLst.append(num)
    sum += num

numLst.sort()
print("numLst =", numLst)
print("numLst의 합은 =", sum)

# 가위바위보 게임
def get_kor(n):
    if n == 1:
        return "가위"
    elif n == 2:
        return "바위"
    else:
        return "보"

draw = 0
win = 0
lose = 0
while True:
    user = input("1~3 사이의 숫자를 입력하세요 (종료: Q 또는 q) : ")
    if user == 'Q' or user == 'q':
        print(f'{draw}무:{win}승:{lose}패')
        break

    user = int(user)
    if user < 1 or user > 3:
        print("숫자를 잘못입력했습니다!!")
        continue

    computer = random.randint(1, 3)
    result = (3 + user - computer) % 3
    print(f'user({get_kor(user)}) : computer({get_kor(computer)}) -> ', end="")
    if result == 0:
        print("무승부")
        draw += 1
    elif result == 1:
        print("user 승")
        win += 1
    else:
        print("computer 승")
        lose += 1

# 6211
def star():
    n = 0
    while n < 10:
        print('*', end='')
        n += 1
    print()
star()

# 6212
def greetName( name ):
    print('How are you?', name)
greetName('Michael')

# 6213
def greetName(name):
    print('How are you?', name)

n = input('이름입력: ')
greetName(n)

# 6221
def add2(a,b):
    return a+b

x=float(input('실수 입력: '))
y=float(input('실수 입력: '))
print( x, '+', y, '=', add2(x, y))



###########################################################



# 6222
def tupleMax(t):
    return max(t)

tup = (2.3, 5.6, 7.5)
print(tupleMax(tup))

# 6223-1
def sum(a, b):
    s = 0
    for i in range(a, b + 1):
        s += i
    return s

a = int(input("작은 수 입력: "))
b = int(input("큰 수 입력: "))
print(sum(a, b))

# 6223-2
def li(a, b):
    li = []
    for i in range(a, b + 1):
        if i % 2 == 0 and i % 7 == 0:
            li.append(i)
    return li

def sum(a, b):
    s = 0
    for i in range(a, b + 1):
        if i % 2 == 0 and i % 7 == 0:
            s += i
    return s

a = int(input("작은 수 입력: "))
b = int(input("큰 수 입력: "))
print(f'{a}부터 {b}까지의 짝수이고 7의배수: {li(a, b)}')
print(f'{a}부터 {b}까지의 짝수이고 7의배수 합: {sum(a, b)}')

# 6224
def prime(a, b):
    li = []
    for i in range(a, b + 1):
        isPrime = True
        for j in range(2, i):
            if i % j == 0:
                isPrime = False
                break

        if isPrime:
            li.append(i)
    return li

a = int(input("작은 수 입력: "))
b = int(input("큰 수 입력: "))
li = prime(a, b)
print('갯수: ', len(li))
print('소수: ', li)

# 6224
import math
def circleLine(r):
    return (r + r) * math.pi

def circleArea(r):
    return r ** 2 * math.pi

radius = float(input("반지름: "))
print(f'반지름이 {radius}인 원의 둘레는 {circleLine(radius)}이다.')
print(f'반지름이 {radius}인 원의 넓이는 {circleArea(radius)}이다.')

# 631
def factorial(n):
    if n==0:
        return 1
    else:
        return n * factorial(n-1)
a = int(input('정수 입력: '))
print( a,'! =',factorial(a) )

# 632
def sumRecursive(a, b):
    if a == b:
        return a
    else:
        return a + sumRecursive(a + 1, b)

a = int(input("작은 수 입력: "))
b = int(input("큰 수 입력: "))
print('1부터 100까지의 합:', sumRecursive(a, b))

# 10
fibos = [1, 1]
def fibo(n):
    for i in range(0, n + 1):
        if i < len(fibos):
            print(f'F {i} = {fibos[i]}')
        else:
            fibos.append(fibos[i - 1] + fibos[i - 2])
            print(f'F {i} = {fibos[i]}')

n = int(input("정수 입력: "))
fibo(n)



###########################################################



# 641
def areaRectangle(w = 1, h = 1):
    return w * h
print(areaRectangle(5, 6))

# 642
def sumRange(a = 1, b = 100):
    s = 0
    if b == 100 and a != 1:
        for i in range(1, a + 1):
            s += i
    else:
        for i in range(a, b + 1):
            s += i
    return s
print(sumRange())

# 651
# hello.py
def greetName(name):
    print('How are you?', name)

# exam.py
import hello
name = input('이름 입력: ')
hello.greetName(name)

# 652
import itertools as itl
a = list(itl.repeat([1, 3, 5], 2))
print(a)


# 653
from math import sqrt
print(sqrt(2))



##########################################################



import math
import random
import time

# 911
x = float(input('1번째 수 입력: '))
y = float(input('2번째 수 입력: '))
print(f'{x}의 {y} 제곱은 {pow(x,y)}')

# 912-1
lst = []
for i in range(15):
    a = random.randint(1, 9)
    lst.append(a)

print('임의의 난수 리스트 ====')
print(lst)

elements = list(set(lst))
print('리스트 요소 ====')
print(elements)

tps = []
cnt = [0] * 10
for l in lst:
    cnt[l] += 1

for i in range(10):
    if cnt[i] == 0:
        continue

    tps.append((i, cnt[i]))
print(tps)

# 912-2
start = time.time()

lst = []
for i in range(15):
    a = random.randint(1, 9)
    lst.append(a)

print('임의의 난수 리스트 ====')
print(lst)

lst.sort()
print('정렬된 리스트 ====')
print(lst)

print(f'최고값: {lst[-1]}')
print(f'최저값: {lst[0]}')

end = time.time()
print(f'실행시간 : {end - start}')

922
x = float(input('실수입력 : '))
print(f'{x}의 제곱근 : {math.sqrt(x)}')

# 923
a = int(input("각도 입력: "))
print(f'sin({a}) = {math.sin(a)}')

# 924
r = float(input("반지름 입력: "))
print(f'반지름 {r} 원 면적: {r * r * math.pi}')




############################################################



# 실습문제
from time import localtime, strftime

local_time = localtime()
curr_time = strftime('%Y-%m-%d %H:%M:%S')
print(curr_time)
curr_time = strftime('%m/%d/%y %H:%M:%S')
print(curr_time)

# 실습문제
from time import localtime, strftime
weekdays = ['월요일','화요일','수요일','목요일','금요일','토요일','일요일']
today = localtime().tm_mday
week = weekdays[localtime().tm_wday]
print('[%s] 오늘은 [%s]입니다.'%(today,week))

# 실습 931
from time import localtime, strftime
print(strftime('%Y 년 %m 월 %d 일'))

# 실습 932
from time import localtime, strftime
print(strftime('%a %b %d %H:%M:%S %Y'))
print(strftime('%Y-%m-%d'))

# 실습 933
from time import localtime, strftime
print(strftime('%H시 %M분 %S초'))

# 과제
from time import localtime, strftime, time
import random

line_search_average_attempt = 0.0
line_search_average_time = 0.0
bin_search_average_attempt = 0.0
bin_search_average_time = 0.0

def LineSearch(data, key):
    global line_search_average_attempt, line_search_average_time

    start = time()

    found_idx = -1
    for i in range(len(data)):
        line_search_average_attempt += 1
        if data[i] == key:
            found_idx = i
            break

    print(f'순차 = {found_idx} : {data}')

    stop = time()
    line_search_average_time += stop - start

def BinSearch(data, key):
    global bin_search_average_attempt, bin_search_average_time

    start = time()

    found_idx = -1
    low, high = 0, len(data) - 1
    while low <= high:
        bin_search_average_attempt += 1
        mid = (low + high) // 2

        if data[mid] == key:
            found_idx = mid
            break
        elif data[mid] < key:
            low = mid + 1
        else:
            high = mid - 1

    print(f'이진 = {found_idx} : {data}')

    stop = time()
    bin_search_average_time += stop - start

def createData():
    data = []
    for _ in range(30):
        data.append(random.randint(1, 50))
    return data


for _ in range(10):
    data = createData()
    key = int(input("키정수: "))

    LineSearch(data, key)
    BinSearch(sorted(data), key)

print(f'순차평균시간: {line_search_average_time/10}, 평균횟수: {line_search_average_attempt/10}')
print(f'이진평균시간: {bin_search_average_time/10}, 평균횟수: {bin_search_average_attempt/10}')



####################################################



# 실습 문제
import turtle as t
r = 20
for _ in range(5):
    t.circle(r)
    r += 10
for _ in range(5):
    r -= 10
    t.circle(-r, 360, 6)
t.done()

# 실습 문제
import turtle as t
colors = ['red','orange','yellow','green','blue','navy','purple']
r = 10
t.pensize(5)
for i in range(7):
    t.pencolor(colors[i])
    t.circle(r)
    # t.goto(r,-(r+20))
    r += 20
t.done()

# 실습 문제
import turtle as t
t.shape("turtle")
t.bgcolor('lightcyan')
colors = ['orange','purple','yellow','green','blue', 'red','cyan']
r = 100
for i in range(7):
    t.begin_fill()
    t.color(colors[i])
    t.circle(r)
    t.end_fill()
    r -= 20
t.done()

# 실습 문제
import turtle as t
t.title('원 그리기')
t.shape('turtle')
t.color('blue')
r = 20
for _ in range(5):
    t.circle(r)
    r=r+20
for _ in range(5):
    r=r-20
    t.circle(-r)
t.done()

# 실습 문제
import turtle as t
t.title('원 그리기')
t.shape('turtle')
t.color('red')
for _ in range(36):
    t.circle(100)
    t.left(10)
t.done()

# 실습 941-1
import turtle as t
t.color('red')
t.circle(50)
t.color('blue')
t.forward(50)
t.left(90)
t.forward(100)
t.left(90)
t.forward(100)
t.left(90)
t.forward(100)
t.left(90)
t.forward(50)
t.done()

# # 실습 941-2
import turtle as t
import math
t.color('red')
r = 0
for _ in range(3):
    r += 20
    t.circle(r)

t.left(45)
t.color('blue')
for _ in range(3):
    l = math.sqrt((r * 2)**2 / 2)
    for _ in range(4):
        t.forward(l)
        t.left(90)
    r -= 20
t.done()

# 실습 941-3
import turtle as t
t.shape('turtle')
r = 100

t.color('blue')
t.circle(r)
t.color('red')
t.pensize(3)
for _ in range(4):
    t.forward(r * 2)
    t.left(90)
t.done()

# 실습 942
import turtle as t
t.color('red')

l = 1
for _ in range(50):
    t.forward(l)
    t.left(90)
    l += 2

t.begin_fill()
t.left(45)
t.forward(10)
t.left(90)
t.forward(10)
t.end_fill()

t.done()

# # 실습 951
# import turtle as t
import random

def move(x, y):
    angle = random.randint(0, 360)
    distance = random.randint(10, 70)
    t.left(angle)
    t.forward(distance)

t.shape('turtle')
t.goto(0,0)
t.forward(10)
while True:
    t.onclick(move)

# 실습 952
import turtle as t
def move_forward():
    t.forward(50)

def rotate_left():
    t.left(90)

scr = t.Screen(); scr.setup(400,250)
scr.onkey(move_forward, "Up")
scr.onkey(rotate_left, "Left")
scr.listen()



####################################################################



# 실습 71
with open('name.txt', 'w') as f:
    f.write('권순찬 182575 소프트웨어공학과')
with open('name.txt', 'r') as f:
    print(f.readline())

# 실습 721
file = input('파일 이름 입력: ')
with open(file, 'r') as f:
    print(f.read())

# 실습 722
src = input("원본 파일 이름: ")
target = input("복사할 파일의 이름: ")
fin = open(src, 'r'); s=fin.read(); fin.close
fout = open(target, 'w'); fout.write(s); fout.close()