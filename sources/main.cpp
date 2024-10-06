/* **************************************************************************  */
/*                                                                             */
/*                                                         :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:    */
/*                                                    +:+ +:+         +:+      */
/*   By: ahabachi <abdelmathinhabachi@gmail.com>    +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+            */
/*   Created: 2024/08/19 17:40:12 by ahabachi          #+#    #+#              */
/*   Updated: 2024/09/24 06:34:37 by ahabachi         ###   ########.fr        */
/*                                                                             */
/* **************************************************************************  */
/*                                                                             */
/*                                                                             */
/*                                                                             */
/*    ██████╗ ██████╗ ███╗   ███╗██████╗ ██╗   ██╗████████╗ ██████╗ ██████╗    */
/*   ██╔════╝██╔═══██╗████╗ ████║██╔══██╗██║   ██║╚══██╔══╝██╔═══██╗██╔══██╗   */
/*   ██║     ██║   ██║██╔████╔██║██████╔╝██║   ██║   ██║   ██║   ██║██████╔╝   */
/*   ██║     ██║   ██║██║╚██╔╝██║██╔═══╝ ██║   ██║   ██║   ██║   ██║██╔══██╗   */
/*   ╚██████╗╚██████╔╝██║ ╚═╝ ██║██║     ╚██████╔╝   ██║   ╚██████╔╝██║  ██║   */
/*    ╚═════╝ ╚═════╝ ╚═╝     ╚═╝╚═╝      ╚═════╝    ╚═╝    ╚═════╝ ╚═╝  ╚═╝   */
/*                                                                             */
/*                                                                             */
/*                                                                             */
/*                                                                             */
/* **************************************************************************  */
/*                                                                             */
/*  █████████            ██████████         ██████████         ██████████      */
/*  ██     ██                    ██                 ██         ██      ██      */
/*         ██                    ██                 ██         ██      ██      */
/*         ██                    ██                 ██                 ██      */
/*         ██            ██████████         ██████████                 ██      */
/*         ██                    ██                 ██                 ██      */
/*         ██                    ██                 ██                 ██      */
/*         ██                    ██                 ██                 ██      */
/*      ████████         ██████████         ██████████                 ██      */
/*                                                                             */
/* **************************************************************************  */

#include "../include/Client.hpp"
#include "../include/Object.hpp"
#include "../include/Vector.hpp"
#include "../include/Matrix.hpp"
#include "../include/Complex.hpp"
#include "../include/statment.hpp"
#include "../include/Polynomial.hpp"
#include "../include/computorv2.hpp"
#include "../include/UsualFunction.hpp"
#include "../include/VirtualMachine.hpp"
#include "../include/IndependentVariable.hpp"
#include <exception>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, const char **argv)
{
	if (argc < 2)
	{
		computorv2::Client client = computorv2::Client();
		client.setFdIn(STDIN_FILENO);
		client.setFdOut(STDOUT_FILENO);
		client.setFdErr(STDOUT_FILENO);
		while ((client.connected()) && (client.read() > 0))
		{
			continue ;
		}
	}
	for (int i = 0; i < argc; i++)
	{
		const int fd = open(argv[i], O_RDONLY);
		if (fd < 0)
		{
			std::cerr << argv[0] << ": " << argv[i] << ": No such file or directory" << std::endl;
			continue ;
		}
		try
		{
			computorv2::Client client = computorv2::Client();
			client.setFdIn(fd);
			client.setFdOut(STDOUT_FILENO);
			client.setFdErr(STDOUT_FILENO);
			while ((client.connected()) && (client.read() > 0))
			{
				continue ;
			}
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		close(fd);
	}
	return (0);
}
