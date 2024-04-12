from sys import exit

def integerCheck(card):
    try:
        int(card)
        return True
    except ValueError:
        return False

def luhn(card, length):
    array = []
    for i in range(length):
        array.append(card[i])
        array[i] = int(array[i])
        
    doubled = []
    counter = length - 2
    while counter >= 0:
        doubled.append(array[counter] * 2)
        counter -= 2
            
    for i in range(len(doubled)):
        doubled[i] = doubled[i]
        if doubled[i] >= 10:
            num = str(doubled[i])
            for j in range(len(num)):
                doubled.append(int(num[j]))
    
    doubled.sort()
    new = []
    
    for i in range(len(doubled)):
        if doubled[i] < 10:
            new.append(doubled[i])
            
                
    num = 0
    for i in range(len(new)):
        num += new[i]
    
    counter2 = length - 1
    while counter2 >= 0:
        num += array[counter2]
        counter2 -= 2
    
    if num % 10 == 0:
        return True
    return False

def company(card, length):
    mastercard = [51, 52, 53, 54, 55]
    amex = [34, 37]
    visa = [4]
    
    if int(card[0]) in visa:
        if length == 13 or length == 16:
            return "visa"
    
    elif int(card[0] + card[1]) in mastercard:
        if length == 16:
            return "mastercard"
    
    elif int(card[0] + card[1]) in amex:
        if length == 15:
            return "amex"
    
    return "invalid"

def main():
    card = input("Enter card number: ")
    if integerCheck(card) == False:
        print("INVALID")
        exit(1)
        
    length = len(card)

    valid = luhn(card, length)

    if valid == True:
        comp = company(card, length)
        if comp == "visa":
            print("VISA")
        elif comp == "mastercard":
            print("MASTERCARD")
        elif comp == "amex":
            print("AMERICAN EXPRESS")
        else:
            print("INVALID")

    else:
        print("INVALID")
        
main()