var computorv1 = {
	equation: {
		"0" : "+0",
		"1" : "+0",
		"2" : "+0"
	},
	Shell: {
		init: function()
		{
			console.log(
				"%ccomputorv1" + "%c by ahabachi",
				"color: #2196F3; font-size: 5vw; font-weight: bold;",
				"color: green; font-size: 16px; font-style: italic;"
			);
		},
		loop: function()
		{

		}
	},
	isdigit: function (c)
	{
		return (("0".charCodeAt(0) <= c.charCodeAt(0)) && (c.charCodeAt(0) <= "9".charCodeAt(0)));
	},
	isalpha: function (c)
	{
		return (
			(("A".charCodeAt(0) <= c.charCodeAt(0)) && (c.charCodeAt(0) <= "Z".charCodeAt(0))) ||
			(("a".charCodeAt(0) <= c.charCodeAt(0)) && (c.charCodeAt(0) <= "z".charCodeAt(0)))
		);
	},
	parseEquation: function (s)
	{
		let i        = 0;
		let sign     = "";
		let base     = "";
		let name     = "";
		let exponent = "";

		for (var side = 0; side < 2; side++)
		{
			while ((i < s.length) && (s[i] == ' '))
			{
				i = i + 1;
			}
			if (i >= s.length)
			{
				return (i);
			}
			sign = "+";
			while (i < s.length)
			{
				if ((s[i] == '-') || (s[i] == '+'))
				{
					sign = s[i];
					i = i + 1;
				}
				while ((i < s.length) && (s[i] == ' '))
				{
					i = i + 1;
				}
				if ((i < s.length) && (computorv1.isdigit(s[i]) == false) && (computorv1.isalpha(s[i]) == false))
				{
					return (i);
				}
				base     = "1"
				exponent = "0";
				if ((i < s.length) && (computorv1.isdigit(s[i])))
				{
					base = ""
					while ((i < s.length) && (computorv1.isdigit(s[i])))
					{
						if (base == "0")
						{
							// case: 01, 00, 02, ...
							return (i);
						}
						base = base + s[i];
						i = i + 1
					}
					if ((i < s.length) && (s[i] == '.'))
					{
						i = i + 1;
						base = base + '.';
						if ((i >= s.length) || (computorv1.isdigit(s[i]) == false))
						{
							return (i);
						}
						while ((i < s.length) && (computorv1.isdigit(s[i])))
						{
							base = base + s[i];
							i = i + 1
						}
					}
				}
				if ((i < s.length) && (s[i] == ' '))
				{
					while ((i < s.length) && (s[i] == ' '))
					{
						i = i + 1;
					}
					if ((i < s.length) && (computorv1.isalpha(s[i]) == true))
					{
						// 8 X
						// sould be: 8X
						return (i);
					}
				}
				while ((i < s.length) && (s[i] == ' '))
				{
					i = i + 1;
				}
				if ((i < s.length) && ((s[i] == '*') || (computorv1.isalpha(s[i]) == true)))
				{
					if (s[i] == '*')
					{
						i = i + 1;
					}
					while ((i < s.length) && (s[i] == ' '))
					{
						i = i + 1;
					}
					if ((i >= s.length) || (computorv1.isalpha(s[i]) == false))
					{
						return (i);
					}
					let v = "";
					while ((i < s.length) && (computorv1.isalpha(s[i]) == true))
					{
						v = v + s[i];
						i = i + 1;
					}
					if (name == "")
					{
						name = v;
					}
					if (name != v)
					{
						return (i - 1);
					}
					exponent = "1";
					if ((i < s.length) && (s[i] == '^'))
					{
						i = i + 1;
						if ((i >= s.length) || (computorv1.isdigit(s[i]) == false))
						{
							return (i);
						}
						exponent = s[i];
						if ((parseInt(exponent) < 0) || (parseInt(exponent) > 2))
						{
							return (i);
						}
						i = i + 1
					}
				}
				if (side != 0)
				{
					if (sign == '-')
					{
						sign = '+';
					}
					else if (sign == '+')
					{
						sign = '-';
					}
				}
				base = sign + base;
				if (computorv1.equation.hasOwnProperty(exponent))
				{
					computorv1.equation[exponent] += base;
				}
				else
				{
					computorv1.equation[exponent] = base;
				}


				// console.log("base    : " + base);
				// console.log("exponent: " + parseFloat(exponent));
				// console.log(computorv1.equation);
				// console.log("- - - - - - - - - - - - - - -");

				while ((i < s.length) && (s[i] == ' '))
				{
					i = i + 1;
				}

				if ((i < s.length) && (s[i] == '='))
				{
					if (side != 0)
					{
						return (i);
					}
					i = i + 1;
					break ;
				}
				if ((i < s.length) && (s[i] != '+') && (s[i] != '-'))
				{
					return (i);
				}
			}
		}
		return (-1);
	}
};

computorv1.main = function()
{
	var equation = " 8X  + 0 * X + 4 * X^2   = 9.3 * X^2 + 9 * X^0 ";
	// var equation = " x=x + 1";

	let errval = computorv1.parseEquation(equation);
	if (errval != -1)
	{
		let errmsg = "";
		for (var i = 0; i < errval; i++)
		{
			errmsg += " ";
		}
		console.log(equation);
		console.log(errmsg + "^");
		console.log(errmsg + "^");
	}
	const exponents = Object.keys(computorv1.equation).sort();
	for (let i = 0; i < exponents.length; i++)
	{
		exponent = exponents[i];
		let base = eval("0" + computorv1.equation[exponent]);
		if (base == 0)
		{
			continue ;
		}
		console.log(base);
	}



	// computorv1.Shell.init();

	// 8 * X
	// 8 X
	// 8 + X

	
	// computorv1.reduce(" 11111111.33333 * X^0 + 4 * X^1 - 9.3 * X^2 = 1 * X^0");
};
computorv1.main();

/*
$>./computor "5 * X^0 + 4 * X^1 - 9.3 * X^2 = 1 * X^0"
Reduced form: 4 * X^0 + 4 * X^1 - 9.3 * X^2 = 0
Polynomial degree: 2
Discriminant is strictly positive, the two solutions are:
0.905239
-0.475131
$>./computor "5 * X^0 + 4 * X^1 = 4 * X^0"
Reduced form: 1 * X^0 + 4 * X^1 = 0
Polynomial degree: 1
The solution is:
-0.25
./computor "8 * X^0 - 6 * X^1 + 0 * X^2 - 5.6 * X^3 = 3 * X^0"
Reduced form: 5 * X^0 - 6 * X^1 + 0 * X^2 - 5.6 * X^3 = 0
Polynomial degree: 3
The polynomial degree is strictly greater than 2, I can't solve.
*/
