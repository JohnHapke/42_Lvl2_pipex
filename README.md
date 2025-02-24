# 42_pipex

## Purpose
The purpose of the Pipex project is to create a command-line program in C that replicates the behavior of shell pipes. It connects two commands by redirecting the output of the first command as the input to the second command, reading from an input file and writing the final result to an output file.

## Explanation of Behavior
Pipex emulates the shell pipeline feature (e.g., `< infile cmd1 | cmd2 > outfile`). The program takes four main arguments: an input file, two commands, and an output file. It uses system calls like `fork()`, `pipe()`, `dup2()`, and `execve()` to:
- Read from the input file.
- Execute the first command in a child process, redirecting its output to a pipe.
- Pass the pipe’s output as input to the second command in the parent process.
- Write the final output to the specified output file.

The program manages file descriptors and ensures proper process communication. If an error occurs (e.g., invalid file or command), it exits with an appropriate error code.

## How It Works
1. **Initialization**: The program receives arguments: `file1 cmd1 cmd2 file2`.
2. **Pipe Creation**: A pipe is created with two ends (`fd[0]` for reading, `fd[1]` for writing).
3. **Child Process**:
   - Opens the input file.
   - Redirects `stdout` to the pipe’s write end (`fd[1]`) using `dup2()`.
   - Redirects the input file to `stdin`.
   - Executes `cmd1` with `execve()`, writing its output to the pipe.
4. **Parent Process**:
   - Waits for the child to finish.
   - Opens the output file.
   - Redirects `stdin` to the pipe’s read end (`fd[0]`).
   - Redirects `stdout` to the output file.
   - Executes `cmd2`, processing the piped input and writing to the output file.
5. **Cleanup**: Closes unused file descriptors and exits successfully if no errors occur.

## Bonus Features
The bonus version extends the mandatory functionality:
- **Multiple Pipes**: Supports more than two commands (e.g., `cmd1 | cmd2 | cmd3`), chaining multiple processes.
- **Here-Doc Support**: Handles the `here_doc` feature with `<< limiter`, reading input from the user until a specified limiter is entered, replacing the input file.
- **Append Mode**: Supports `>>` for appending to the output file instead of overwriting it with `>`.

## Allowed Functions
- `malloc`
- `free`
- `fork`
- `pipe`
- `dup2`
- `execve`
- `open`
- `close`
- `read`
- `write`
- `wait` / `waitpid`
- `access`
- `unlink`

## Compilation and Usage
- **Compile**: Use `make` to build the mandatory version or `make bonus` for the bonus version.
- **Mandatory Execution**: `./pipex file1 "cmd1" "cmd2" file2`
  - Equivalent to shell: `< file1 cmd1 | cmd2 > file2`
- **Bonus Execution**: `./pipex file1 "cmd1" "cmd2" "cmd3" ... file2`
  - Equivalent to: `< file1 cmd1 | cmd2 | cmd3 > file2`
- **Here-Doc Bonus**: `./pipex here_doc limiter "cmd1" "cmd2" file2`
  - Reads input until `limiter`, then processes it through the commands.

## Memory Leaks Test
To check for memory leaks, run:
```
valgrind --leak-check=full --trace-children=yes ./pipex file1 "cmd1" "cmd2" file2
```
This ensures the program properly manages memory across child processes.

## Key Concepts
- **Subprocesses**: Uses `fork()` to create separate processes for each command.
- **Pipes**: Employs `pipe()` for inter-process communication.
- **Redirection**: Utilizes `dup2()` to redirect input/output between files and pipes.
- **Command Execution**: Leverages `execve()` to replace process images with command executions.

## Grade
tbd

#### Used Tests
pipex-tester: https://github.com/vfurmane/pipex-tester
