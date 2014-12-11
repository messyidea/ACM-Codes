n = input()
ans = 1
cnt = 1
cnt2 = 2
res = cnt;
while n > res:
    cnt += cnt2
    res += cnt
    cnt2 += 1;
    if(n >= res):
        ans += 1
print(ans)
