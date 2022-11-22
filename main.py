
words = ["Choose an option:\n", "1. octal to hex\n", "2. binary addition\n", "3. print HI\n", "4. count bits\n",
            "5. decimal to binary\n", "6. Zig-Zag bits\n", "7. exit\n"]

output = open("output.txt")
lines = output.readlines()
output.close()

yourOut = open("yourOutput.txt")
yourLines = yourOut.readlines()

inp = open("input.txt")
inputLines = inp.readlines()
j = 0

def fi(word, wordList):
    for w in wordList:
        if w == word:
            return False
    return True
i = 0
while i < len(lines):
    if fi(lines[i], words) == False:
        i += 1
        continue
    l = int(inputLines[j].strip("\n"))
    print("/************************************************/\n")
    if l == 1:
        # print(lines[i].split(":"))
        correct = ((lines[i].split(":")[1]).strip(" ")).strip("\n")
        check = ((yourLines[i].split(":")[1]).strip(" ")).strip("\n")
        q = inputLines[j + 1].strip("\n")
        print("test for Q1:")
        if correct != check:
            print("Error")
        print("input:", q)
        print("\nexpected: ", correct)
        print("\nGot:      ", check)
        j += 2
    if l == 2:
        correct = ((lines[i].split(":")[1]).strip(" ")).strip("\n")
        check = ((yourLines[i].split(":")[1]).strip(" ")).strip("\n")
        q = inputLines[j + 1].strip("\n")
        q2 = inputLines[j + 2].strip("\n")
        print("test for Q2:")
        if correct != check:
            print("Error")
        print("input:", q)
        print("      ", q2)
        print("\nexpected: ", correct)
        print("\nGot:      ", check)
        j += 3
    if l == 3:
        j += 2
        print("test for Q3:")
        trt2 = lines[i - 1]
        trt = lines[i]
        correct = ((lines[i].split(":")[1]).strip(" ")).strip("\n")
        check = ((yourLines[i].split(":")[1]).strip(" ")).strip("\n")
        print("Expected:")
        print(correct)
        k = i + 1
        while "#" in lines[k]:
            print(lines[k].strip("\n"))
            k += 1
        k = i + 1
        print("\nGot:     ")
        print(check)
        while "#" in yourLines[k]:
            print(yourLines[k].strip("\n"))
            k += 1
        i = k - 1
    if l == 4:
        correct = ((lines[i].split(":")[1]).strip(" ")).strip("\n")
        check = ((yourLines[i].split(":")[1]).strip(" ")).strip("\n")
        q = inputLines[j + 1].strip("\n")
        print(" test for Q4:")
        if correct != check:
            print("Error")
        print("input:", q)
        print("\nexpected: ", correct)
        print("\nGot:      ", check)
        j += 2
    if l == 5:
        correct = ((lines[i].split(":")[1]).strip(" ")).strip("\n")
        check = ((yourLines[i].split(":")[1]).strip(" ")).strip("\n")
        q = inputLines[j + 1].strip("\n")
        print(" test for Q5:")
        if correct != check:
            print("Error")
        print("input:", q)
        print("\nexpected: ", correct)
        print("\nGot:      ", check)
        j += 2
    if l == 6:
        correct = ((lines[i].split(":")[1]).strip(" ")).strip("\n")
        check = ((yourLines[i].split(":")[1]).strip(" ")).strip("\n")
        q = inputLines[j + 1].strip("\n")
        print(" test for Q6:")
        if correct != check:
            print("Error")
        print("input:", q)
        print("\nexpected: ", correct)
        print("\nGot:      ", check)
        j += 2
    if l == 7:
        break
    i += 1

