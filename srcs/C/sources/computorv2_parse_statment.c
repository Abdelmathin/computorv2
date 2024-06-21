int computorv2_parse_statment(t_statment *st)
{
	char function_name[COMPUTORV2_MAX_VARLEN];
	char variable_name[COMPUTORV2_MAX_VARLEN];

	computorv2_skip_spaces(st);
	int original_pos = computorv2_getpos(st);
	if ((computorv2_next(st) == '_') || isalpha(computorv2_next(st)))
	{
		if (computorv2_copy_variable(st, function_name) != COMPUTORV2_SUCCESS)
		{
			return (COMPUTORV2_ERROR);
		}
		computorv2_skip_spaces(st);
		if (computorv2_next(st) == '=')
		{
			computorv2_move(st);
			computorv2_skip_spaces(st);
			return (computorv2_assignment(st));
		}
		if (computorv2_next(st) == '(')
		{
			computorv2_move(st);
			computorv2_skip_spaces(st);
			if ((computorv2_next(st) == '_') || isalpha(computorv2_next(st)))
			{
				if (computorv2_copy_variable(st, variable_name) != COMPUTORV2_SUCCESS)
				{
					return (COMPUTORV2_ERROR);
				}
				computorv2_skip_spaces(st);
				if (computorv2_next(st) == ')')
				{
					computorv2_move(st);
					computorv2_skip_spaces(st);
					if (computorv2_next(st) == '=')
					{
						computorv2_move(st);
						computorv2_skip_spaces(st);
						return (computorv2_define_function(st, function_name, variable_name));
					}
				}
			}
		}
	}
	computorv2_setpos(st, original_pos);
	return (computorv2_assignment(st));
}