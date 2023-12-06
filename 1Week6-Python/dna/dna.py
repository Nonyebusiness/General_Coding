import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        print("no file typed into commandline argument")
        sys.exit(1)


    # TODO: Read database file into a variable
    with open (sys.argv[1], 'r') as file:

        reader = csv.DictReader(file)

        dna_list= list(reader)


    # TODO: Read DNA sequence file into a variable

    with open(sys.argv[2], 'r') as file:
        dna_sequence = file.read()

        # TODO: Find longest match of each STR in DNA sequence
        matches = {}

        for person in dna_list:
            for str_name, str_count in person.items():
                if str_name != 'name':
                    str_count = int(str_count)
                    longest_dna = longest_match(dna_sequence, str_name)
                    matches[str_name] = longest_dna



        if longest_dna is None:
            print("No matches found")
    # TODO: Check database for matching profiles

    for person in dna_list:
        is_match = True
        for str_name, str_count in person.items():
            if str_name != 'name':
                str_count = int(str_count)
                if matches[str_name] != str_count:
                    is_match = False
                    break
        if is_match:
            print(person['name'])
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
