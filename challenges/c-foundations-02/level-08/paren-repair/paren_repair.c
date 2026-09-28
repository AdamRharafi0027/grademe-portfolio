#include <unistd.h>

#define MAX 1000
#define INF 1000000

static char	s[MAX + 1];
static char	out[MAX + 1];
static int	dp[MAX + 1][MAX + 1];
static int	len;

static int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

static int	cost(int pos, int balance)
{
	int	replace;
	int	keep;

	if (balance < 0 || balance > len)
		return (INF);
	if (pos == len)
	{
		if (balance == 0)
			return (0);
		return (INF);
	}
	if (dp[pos][balance] != -1)
		return (dp[pos][balance]);

	replace = 1 + cost(pos + 1, balance);
	keep = INF;

	if (s[pos] == '(')
		keep = cost(pos + 1, balance + 1);
	else if (balance > 0)
		keep = cost(pos + 1, balance - 1);

	dp[pos][balance] = min(replace, keep);
	return (dp[pos][balance]);
}

static void	print_result(void)
{
	write(1, out, len);
	write(1, "\n", 1);
}

static void	generate(int pos, int balance)
{
	int	best;

	if (pos == len)
	{
		if (balance == 0)
			print_result();
		return ;
	}

	best = cost(pos, balance);

	/*
	** First try replacing this parenthesis with a space.
	** This gives the required left-to-right ordering.
	*/
	if (1 + cost(pos + 1, balance) == best)
	{
		out[pos] = ' ';
		generate(pos + 1, balance);
		out[pos] = s[pos];
	}

	/*
	** Then try keeping the original parenthesis.
	*/
	if (s[pos] == '(')
	{
		if (cost(pos + 1, balance + 1) == best)
		{
			out[pos] = '(';
			generate(pos + 1, balance + 1);
		}
	}
	else if (s[pos] == ')' && balance > 0)
	{
		if (cost(pos + 1, balance - 1) == best)
		{
			out[pos] = ')';
			generate(pos + 1, balance - 1);
		}
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	int	balance;

	if (argc != 2)
		return (1);

	/* Copy and validate the argument. */
	len = 0;
	while (argv[1][len])
	{
		if (argv[1][len] != '(' && argv[1][len] != ')')
			return (1);
		if (len >= MAX)
			return (1);
		s[len] = argv[1][len];
		out[len] = argv[1][len];
		len++;
	}
	s[len] = '\0';
	out[len] = '\0';

	/* Check if already balanced. */
	balance = 0;
	i = 0;
	while (i < len)
	{
		if (s[i] == '(')
			balance++;
		else
		{
			balance--;
			if (balance < 0)
				break ;
		}
		i++;
	}

	if (i == len && balance == 0)
	{
		write(1, s, len);
		write(1, "\n", 1);
		return (0);
	}

	/* Initialize dynamic-programming table. */
	i = 0;
	while (i <= len)
	{
		j = 0;
		while (j <= len)
		{
			dp[i][j] = -1;
			j++;
		}
		i++;
	}

	/* Print every minimum-replacement solution. */
	generate(0, 0);

	return (0);
}
