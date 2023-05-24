#include "main.h"

int main()
{
	ssize_t len = 0;
	size_t size = 0;
	char *buffer = NULL, *result, *pathname, **argv;
	path_name *head = '\0';
	void (*fptr)(char **);

	signal(SIGINT, ctrl_chk);
	while (len != EOF)
	{
		_isatty();
		len = getline(&buffer, &size, stdin);
		_EOF(len, buffer);
		argv = str_split(buffer, "\n");

		if (argv == NULL || argv[0] == NULL)
			_exec(argv);
		else
		{
			result = _getenv("PATH");
			head = path_link(result);
			pathname = find_path(head, argv[0]);
			fptr = inbuilt(argv);

			if (fptr)
			{
				free(buffer);
				fptr(argv);
			}
			else if (!pathname)
				_exec(argv);
			else if (pathname)
			{
				free(argv[0]);
				argv[0] = pathname;
				_exec(argv);
			}
		}
	}
	_freelist(head);
	free_argv(argv);
	free(buffer);
	return (0);
}
