import time

def main():
    for i in range(5):
        process_data(i)

def process_data(index):
    print(f"Processing data at index {index}")
    calculate_squares(index)
    time.sleep(0.1)
    perform_complex_computation(index)

def calculate_squares(index):
    squares = [i**2 for i in range(index * 1000)]

def perform_complex_computation(index):
    for _ in range(1000):
        result = 0
        for j in range(index * 500):
            result += j

if __name__ == "__main__":
    main()