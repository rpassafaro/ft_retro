/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Env.class.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 15:58:42 by jkalia            #+#    #+#             */
/*   Updated: 2017/07/08 18:51:31 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Env.class.hpp"
#include "Player.class.hpp"
#include "Enemy.class.hpp"

Env::EnvState Env::_envstate = Uninitialized;
Env::EnvState Env::GetEnvState() const { return _envstate; }
void		  Env::SetEnvState(EnvState &in) { _envstate = in; }

Env::Env() {}
Env::~Env() {}
Env::Env(const Env& src) { *this = src; }
Env& Env::operator=(const Env& env) {return *this;}

void Env::Start(void)
{
	if (_envstate != Uninitialized)
		return;
	EnvInit();
	GameLoop();
	if (_envstate == Exiting)
		EnvExit();
}

void Env::EnvInit()
{
	initscr();
	getmaxyx(stdscr, _winh, _winw);
	win = newwin(_winh, _winw, 0, winw);
	raw();
	keypad(stdscr, TRUE);
	noecho();
	_envstate = Playing;
	curs_set(0);
	nodelay(stdscr, TRUE);
}

void Env::EnvExit()
{
  endwin();
  exit(0);
}

void Env::GameLoop()
{
	int		ch;
	Player rob(winh, winw);
	mvprintw(10, 10, "Winh = %d", winh);
	mvprintw(20, 10, "Winw = %d", winw);
	Enemy  bob;
	while (1)
	{
		if ((ch = getch()) == ERR)
		{
//			rob.Print();
			bob.Print();
		}
		else {
			clear();
			rob.Action(ch);
		}
	}
}

