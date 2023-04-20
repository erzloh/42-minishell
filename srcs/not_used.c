// // NOT USED, NOT FINISHED
// // Update the value of i if there are whitespaces from str[i]
// void	skip_whitespaces(char *str, int *i)
// {
// 	if (!str)
// 		return ;
// 	while (str[*i] == ' ' || str[*i] == '\t')
// 	{
// 		(*i)++;
// 	}
// }

// // Counts the number of flags in a string argument
// int	get_flag_nb(char *arg)
// {
// 	int	i;
// 	int	flag_nb;

// 	i = 0;
// 	flag_nb = 0;
// 	if (!arg)
// 		return (-1);
// 	while (arg[i])
// 	{
// 		skip_whitespaces(arg, &i);
// 		if (arg[i] != '-')
// 			break ;
// 		else
// 		{
// 			flag_nb++;
// 			while ((arg[i] != ' ' && arg[i] != '\t') && arg[i])
// 				i++;
// 			if (!arg[i])
// 				break ;
// 		}
// 		i++;
// 	}
// 	return (flag_nb);
// }

// NOT FINISHED
// // Check if there are flags in the string and if so,
// // split each element into an string array
// char	**split_flags(char *arg)
// {
// 	char	**args;
// 	int		i;
// 	int		arg_nb;

// 	i = 0;
// 	arg_nb = get_flag_nb(arg);
// 	while (arg[i])
// 	{
// 		if (arg[i] == '-')
// 		{
// 			while ((arg[i + j] != ' ' || arg[i + j] != '\t') && arg[i + j])
// 				j++;
// 		}
// 		i++;
// 	}
// }