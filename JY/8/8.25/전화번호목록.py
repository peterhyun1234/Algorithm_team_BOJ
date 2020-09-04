def solution(phone_book):
    
    phone_book_dic = {i:None for i in phone_book}
    
    for i in phone_book:
        for j in range(len(i)):
            if i[:j] in phone_book_dic:
                return False
    
    return True