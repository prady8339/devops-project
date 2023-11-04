from queue import Queue

def solve(web_pages, curr_page, goal_page):
    q = Queue()
    visited = [False] * len(web_pages)
    q.put((curr_page, 0))
    visited[curr_page] = True
    while not q.empty():
        page, steps = q.get()
        if page == goal_page:
            return steps
        for next_page in web_pages[page]:
            if not visited[next_page]:
                q.put((next_page, steps + 1))
                visited[next_page] = True
    return -1

if _name_ == "_main_":
    n = int(input())
    web_pages = []
    for i in range(n):
        temp = []
        str = input()
        curr_num = ""
        idx = 0
        while idx < len(str):
            if str[idx] == ' ':
                temp.append(int(curr_num) - 1)
                curr_num = ""
            else:
                curr_num += str[idx]
            idx += 1
        if curr_num:
            temp.append(int(curr_num) - 1)
        web_pages.append(temp)
    curr_page, goal_page = map(int, input().split())
    print(solve(web_pages, curr_page - 1, goal_page - 1))