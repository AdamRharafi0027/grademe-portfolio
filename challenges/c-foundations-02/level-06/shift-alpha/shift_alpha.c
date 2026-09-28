#include <unistd.h>

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
    if (argc == 2)
    {
        size_t i = 0;
        char c;
        while (argv[1][i])
        {
            c = argv[1][i];
            if (c == 'z')
                write(1,"a",1);
            else if (c == 'Z')
                write(1,"A",1);
            else if((c >= 'a' && c <= 'y' )||( c >= 'A' && c <= 'Y')) {
                c+=1;
                write(1,&c,1);
            } 
            else if (c == 32)write(1,&c,1);
            else write(1,&c,1);
            i++;
        }
        write(1,"\n",1);
        return (0);
    }
    write(1,"wrong number of arguments\n",26);
	return (0);
}
