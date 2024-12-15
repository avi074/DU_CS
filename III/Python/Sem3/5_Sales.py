def sales_review(spw:list):
    spm = sum(spw)
    commision = 0
    remark = ""

    if spm >= 50000:
        commision = 0.05*spm
    
    if spm >= 80000:
        remark = "Excellent"
    elif spm >= 60000 and spm < 80000:
        remark = "Good"
    elif spm >= 40000 and spm < 60000:
        remark = "Average"
    else:
        remark = "Work Hard"
    
    return spm,commision,remark

print("Enter your sales per week of a month : ")
a = []
for i in range(4):
    a.append(int(input("Week "+str(i+1)+" : ")))
print("Your sales review (Sales/Month, Commision, Remark) : ",end = "")
print(sales_review(a))