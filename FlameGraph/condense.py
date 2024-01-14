import os

def concatenate_files(folder_path, output_filename):
    with open(output_filename, 'w') as output_file:
        files_in_folder = os.listdir(folder_path)
        for file_name in files_in_folder:
            if file_name.endswith(".py"):
                continue  # Skip Python files
            file_path = os.path.join(folder_path, file_name)
            with open(file_path, 'r') as input_file:
                content = input_file.read()
                output_file.write(content + '\n')

if __name__ == "__main__":
    folder_path = "/workspaces/General_Coding/FlameGraph/emp1"
    output_filename = "combined_output2.txt"

    concatenate_files(folder_path, output_filename)
    print(f"All files in {folder_path} (excluding .py files) are concatenated into {output_filename}.")
