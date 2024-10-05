int computorv2_copy_variable(t_statment *st, char *str)
{
	int i = 0;
	while ((computorv2_next(st) == '_') || isalpha(computorv2_next(st)) || isdigit(computorv2_next(st)))
	{
		if (i >= COMPUTORV2_MAX_VARLEN)
		{
			return (COMPUTORV2_ERROR);
		}
		str[i] = computorv2_next(st);
		computorv2_move(st);
		i++;
	}
	str[i] = 0;
	return (COMPUTORV2_SUCCESS);
}