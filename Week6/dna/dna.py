import csv
import sys


def main():

    # TODO: Check for command-line usage

    if len(sys.argv) != 3:
        sys.exit("Error occured")

    # TODO: Read database file into a variable

    with open(sys.argv[1], "r") as file:
        reader = csv.DictReader(file)
        database = [row for row in reader]

    # print("00000000")
    # print (reader)
    # print("11111111111")
    # print(database)
    # print("22222222")

    # the line babove is fastets and equivalent to :
    # database []  // create a new dictionary
    # for row in reader:  // pass through the list of dictionaries in the reader (dict1 = person, dict2 = STR1, dict3 = STR2 ...)
    # database.append(row)  // now, we have a variable database wich is a dictionary of list of dictionnaries.
    # ex : Key : Row1 -> value : dict1 (person : key=name, value=Albus), dict2 (Sequence 1: key=AGATC, value=15)  etc.

    # in other words: the ouputs are :
    # csv file = name,AGATC,AATG,TATC
    # reader = temporary file that should contains those informations like a dictionary ({name: Alice, AGATC: 2, AATG: 8, TATC: 3}, {name: Bob, AGATC: 4, AATG: 1, TATC: 5}, {name: Charlie, AGATC: 3, AATG: 2, TATC: 5})
    # database (is a list of persons === list of dictionaries) = [{name: Alice, AGATC: 2, AATG: 8, TATC: 3}, {name: Bob, AGATC: 4, AATG: 1, TATC: 5}, {name: Charlie, AGATC: 3, AATG: 2, TATC: 5}]
    # index or position of the list        =                   0                                             1                                             2

    # TODO: Read DNA sequence file into a variable

    with open(sys.argv[2], "r") as file_DNA:
        DNA_seq = file_DNA.read()

    # TODO: Find longest match of each STR in DNA sequence

    # extract the keys of the database list that contains the STR, on the firts line of the file ie: the header on position row = 0 (ex for small.scv : [name, AGAT, AATG, TATC]),
    # ignoring the key : name in the first position : 0 of the list

    subseq = list(database[0].keys())[1:]
    # print(subseq) = all the STR we want to find in the sequence analyzed.

    STR_count = dict()
    for STR in subseq:
        STR_count[STR] = longest_match(DNA_seq, STR)
        # STR_count is a dictionary of : keys : STR and values : number of occurence of the STR considerated in the DNA_seq file
        # print(STR_count)

    # TODO: Check database for matching profiles

    # compare each STR of each person from the database with the list STR_count
    # first, access to a person, using his name in the database

    for person in database:
        match = 0
        for STR in subseq:
            if int(person[STR]) == STR_count[STR]:  # compare the occurence of the STR considareted, in the person database and in the STR_count
                match += 1
        if match == len(subseq):  # meaning all the STR with their occurencies in the database are in the sequence with the same occurencies
            print(person["name"])
            return
    print("No match")


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


main()
