money = int(input())

money = 1000 - money

li = [500, 100, 50, 10, 5, 1]
count = 0
for i in li:
    if money >= i:
        while money>=i:
            money -= i
            count += 1

print(count)