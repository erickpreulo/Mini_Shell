// "ls | grep me > input | output"

// make_block("ls ", 0)
// make_block("| grep me ", 1)
// make_block("> input ", 2)
// make_block("| output", 3)

make_block(str, i) {
	block[i].cmd = first_word(str)
	block[i].path_cmd = test_access(block[i].cmd)
	block[i].type = get_separator(str)
	block[i].argv = take_argv(str, ' ') // ["ls", "file1 .txt", 0]
	str = "cat "file1 .txt""
}



cat < erick1.txt | grep a > erick2.txt > erick3.txt

/* PARSER */

struct ms

int fd_in = block[1].fd
int fd_out = block[4].fd
int last_block = 2
int pipes[100][2]
int current_pipe = 0;

struct block[i]
[0]                       [1]							[2]							[3]								 [4]
| cmd = "cat"			  | cmd = "erick1.txt"			| cmd = "grep"				| cmd = "erick2.txt"			 erick3.txt
| path_cmd = "bin/cat"    | path_cmd = 0				| path_cmd = "bin/grep"		| path_cmd = 0
| argv = ["cat", 0]		  | argv = 0					| argv = ["grep", "a", 0]	| argv = 0
| type = 'FIRST'		  | type = "INPUT_FILE"			| type = "PIPE"				| type = "OUTPUT_FILE"
| str = "cat"             | str = "erick1.txt"			| str = "grep a"			| str = "erick2.txt"
| fd = 0				  | fd = open_file_read(str)	| fd = 0					| fd = open_file_output(str, i) | fd = open_file_output(str, i)
														| is_last = 1												| is_last

open_file_output (str, i) {
	int fd = open(argv[i + 1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	ms-> fd_out = fd
	return ;
}

print_block(t_block *block) {
	printf(block->cmd)
	printf(block->path)
	printf(block->cmd)
	printf(block->cmd)
	printf(block->cmd)
}

/* EXECUTOR */

ft_execve(block[0])
{
	pid = fork()
	if (pid == 0)
	{
		if (type == FIRST && ms->fd_in != 0)
			dup2(ms->fd_in, 0)
		if (type== PIPE) {
			dup2(ms->pipe[current_pipe], 0)
		}
		
		if (block[i]->isLast) {
			dup2(ms->fd_out, 1)
		} else {
			dup2(pipe[ms->current_pipe++][0], 1)
		}
		execve(cat)
	}

}
-      <     cat  = is_first
0 || fd_in -------> pipe[0][1]

			grep
pipe[0][0] -------> pipe[1][1] 
                  
			cmd     -      >          >>       is_last
pipe[1][0] -------> 1 || fd_out || fd_append


enumerates: 

typedef enum
{
  FIRST
  PIPE
  FILE_IN
  FILE_OUT
  FILE_APPEND
} types_block;
