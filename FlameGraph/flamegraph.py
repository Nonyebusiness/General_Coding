import sys

def prepare_input(input_filename):
    with open(input_filename, 'r') as f:
        lines = f.readlines()

    # extract system call names and create flamegraph input
    flamegraph_input = '\n'.join(f"{line.strip().split(' ')[-1]} 1" for line in lines)

    return flamegraph_input

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python script.py input.txt")
        sys.exit(1)

    input_filename = sys.argv[1]

    flamegraph_input = prepare_input(input_filename)

    # print flamegraph input to the console
    print(flamegraph_input)