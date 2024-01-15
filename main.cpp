/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parinder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 01:07:40 by parinder          #+#    #+#             */
/*   Updated: 2024/01/15 02:17:37 by parinder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#define RED		"\033[0;31m"
#define ORANGE	"\033[1;33m"
#define GREEN	"\033[1;32m"
#define RESET	"\033[0m"

static void	ft_start(int fd[2], int *recording)
{
	if (*recording)
	{
		std::cout << ORANGE << "record already started !" << RESET << std::endl;
		return ;
	}
	*recording = 1;
	std::cout << GREEN << "recording !" << RESET << std::endl;
}

static void	ft_stop(int fd[2], int *recording)
{
	if (!*recording)
	{
		std::cout << ORANGE << "record already stopped !" << RESET << std::endl;
		return ;
	}
	*recording = 0;
	std::cout << GREEN << "stoping record !" << RESET << std::endl;
}

static void	ft_save(int fd[2], int *recording)
{
	if (!*recording)
	{
		std::cout << ORANGE << "cannot save an empty record !" << RESET << std::endl;
		return ;
	}
	ft_stop(recording);
	std::cout << GREEN << "record saved !" << RESET << std::endl;
}

static void	ft_print(int fd[2], int *recording)
{
	if (!*recording)
	{
		std::cout << ORANGE << "cannot print an empty record !" << RESET << std::endl;
		return ;
	}
	ft_stop(recording);
	std::cout << GREEN << "record printed !" << RESET << std::endl;
}

int	main(void)
{
	std::string	str;
	int			recording = 0;
	int			fd[2];

	while (std::cin)
	{
		std::cout << ">";
		std::getline(std::cin, str);
		if (str == "exit")
		{
			if (recording)
				ft_stop(fd, &recording);
			std::cout << RED << "leaving !" << RESET << std::endl;
			return (0);
		}
		else if (str == "start")
			ft_start(fd, &recording);
		else if (str == "print")
			ft_save(fd, &recording);
		else if (str == "save")
			ft_save(fd, &recording);
		else if (str == "stop")
			ft_stop(fd, &recording);
	}
	std::cout << std::endl << RED << "leaving !" << RESET << std::endl;
	return (0);
}
