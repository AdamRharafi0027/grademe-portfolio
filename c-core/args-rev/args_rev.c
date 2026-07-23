#include <unistd.h>

int	main(int argc, char **argv)
{
	
    int i;

    int end = argc - 1;
    if (argc <= 1)
    {
        return (0);
    }
i = 0;
    while (argv[end][i] && end > 0)
    {
        i = 0;
        while (argv[end][i])
        {
            write(1,&argv[end][i],1);
            i++;
        }
        write(1,"\n",1);
        end--;
        
    }
     
	return (0);
}
