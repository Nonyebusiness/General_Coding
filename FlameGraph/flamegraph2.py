import sys

def prepare_input(input_filename):
    with open(input_filename, 'r') as f:
        lines = f.readlines()

    # extract system call names and create flamegraph input
    flamegraph_input = '\n'.join(f"{line.strip().split(' ')[-1]} 1" for line in lines)

    return flamegraph_input

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: python script.py input.txt output.txt")
        sys.exit(1)

    input_filename = sys.argv[1]
    output_filename = sys.argv[2]

    flamegraph_input = prepare_input(input_filename)

    # write flamegraph input to the specified output file
    with open(output_filename, 'w') as output_file:
        output_file.write(flamegraph_input)

    print(f"Flamegraph input written to {output_filename}")
