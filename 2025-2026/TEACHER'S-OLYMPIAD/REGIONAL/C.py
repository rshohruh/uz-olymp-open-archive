def solve(a, b):
    s1=[]
    s2=[]
    s3=[]
    d=[]
    k=0
    p=1
    # a,b=map(int, input().split())
    for i in range(b):
        c,d=map(str, input().split())
        s1.append(c)
        s2.append(d)
    s1.append(' ')
    for i in range(b):
        if s2[i]=='FB':
            k=k+25
        elif s2[i]=='SQ':
            k=k+30
        elif s2[i]=='MS':
            k=k+50
        elif s2[i]=='SO':
            k=k+60
        elif s2[i]=='GS':
            k=k+75
        elif s2[i]=='TJ':
            k=k+80
        for j in range(i+1,b):
            if s1[i]==s1[j]:
                if s2[j]=='FB':
                    k=k+25
                elif s2[j]=='SQ':
                    k=k+30
                elif s2[j]=='MS':
                    k=k+50
                elif s2[j]=='SO':
                    k=k+60
                elif s2[j]=='GS':
                    k=k+75
                elif s2[j]=='TJ':
                    k=k+80
        if k>=100:
            s3.append(s1[i])
            p=0
        

        k=0
    st = set()
    s4 = []
    for i in range(len(s3)):
            if s3[i] not in st:
                s4.append(s3[i])
            st.add(s3[i])
    if p==1:
        print(a,'hafta Hech kimning telefoni olib qo\'yilmadi', sep='-')
    else:
        print(a,'hafta', sep="-", end = " ")
        print(*s4, sep=", ")

while True:
    n, m = 0, 0
    try:
        n, m = map(int, input().split())
    except:
        exit(0)
    
    solve(n, m)