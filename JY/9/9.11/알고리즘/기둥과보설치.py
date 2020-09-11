def solution(n, build_frame):
    ans = []
    row = set()
    col = set()
    def check():
        for i in row:
            x, y = map(int, i.split())
            if f'{x-1} {y}' in row and f'{x+1} {y}' in row:
                continue
            elif f'{x} {y-1}' in col or f'{x+1} {y-1}' in col:
                continue
            else:
                return False
        for i in col:
            x, y = map(int, i.split())
            if f'{x} {y}' in row or f'{x-1} {y}' in row:
                continue
            elif f'{x} {y-1}' in col:
                continue
            elif y==0:
                continue
            
            else:
                return False
        return True          
    
    def build(x, y, a, b):
        if a==0:
            if b==1:
                col.add(f'{x} {y}')
                if not check():
                    col.remove(f'{x} {y}')
            if b==0:
                col.remove(f'{x} {y}')
                if not check():
                    col.add(f'{x} {y}')   
                
        if a==1:
            if b==1:
                row.add(f'{x} {y}')
                if not check():
                    row.remove(f'{x} {y}')
            if b==0:
                row.remove(f'{x} {y}')
                if not check():
                    row.add(f'{x} {y}')
        
    for x, y, a, b in build_frame:
        build(x, y, a, b)
    print(col, row)
    for i in col:
        x, y = map(int, i.split())
        ans.append([x,y,0])
    for i in row:
        x, y = map(int, i.split())
        ans.append([x,y,1])
    ans.sort(key=lambda x:x[2])
    ans.sort(key=lambda x:x[1])
    ans.sort(key=lambda x:x[0])
    return ans