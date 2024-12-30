import sys

#Get the input text
text: list = sys.argv[1].split()
output: str = ""

#Get length of each word
for e in text:
    output += str(len(e))
    output += " "

#Print answer to standard output
print(output)