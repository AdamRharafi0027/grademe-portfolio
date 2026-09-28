#include <unistd.h>

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
    if (argc == 2)
    {
        int count = 0;
        int i = 0;
        while (argv[1][i])
        {
            if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
                count = argv[1][i] - 'a';
            else if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
                count = argv[1][i] - 'A';
            else count = 1;
            while (count > 0)
            {
                write(1,&argv[1][i],1);
                count--;
            }
            i++;
        }
        write(1,"\n",1);
        return(0);
    }
    write(1,"wrong number of arguments\n",26);
	return (0);
}