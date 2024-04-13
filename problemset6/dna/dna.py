import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        print("Usage: python dna.py databases/database.csv sequences/sequence.txt")
        exit(1)

    # TODO: Read database file into a variable
    rows  = []
    with open(sys.argv[1]) as file:
        reader = csv.DictReader(file)
        for row in reader:
            rows.append(row)  
    file.close()
    
    # TODO: Read DNA sequence file into a variable
    f = open(sys.argv[2], "r")
    dna = f.read()
    f.close()

    # TODO: Find longest match of each STR in DNA sequence
    header = header_extractor()
    numOfString = {}
    for element in header:
        temp = longest_match(dna, element)
        numOfString[element] = temp
    
    amounts = []
    for i in numOfString:
        amounts.append(numOfString[i])

    # TODO: Check database for matching profiles
    for row in rows:
        person = row.pop("name")

        temp = []
        for element in row:
            row.update({element: int(row[element])})
            temp.append(row[element]) 

        if temp == amounts:
            print(person)
            return
    else:
        print("No match")
    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1
            
            # If there is no match in the substring
            else:
                break
        
        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run

def header_extractor():
    f = open(sys.argv[1], "r")
    header = f.readline()
    header = list(header.split(","))
    del header[0]
    last = header.pop(len(header) - 1)
    last = last[:-1]
    header.append(last)
    f.close()
    return header

main()
