#include "shell.h"

/**
 * initialize_ - starting point
 * @current_cmd: verify current token
 * @cmd_type: token to pass
 */
void initialize_(char **current_cmd, int cmd_type)
{
	pid_t PID;

	if (cmd_type == EXT_CMD || cmd_type == PATH_CMD)
	{
		PID = fork();
		if (PID == 0)
			exec_cmd(current_cmd, cmd_type);
		else
		{
			waitpid(PID, &status, 0);
			status >>= 8;
		}
	}
	else
		exec_cmd(current_cmd, cmd_type);
}

