/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 18:08:05 by jkalia            #+#    #+#             */
/*   Updated: 2017/07/09 19:38:29 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.class.hpp"

Player::Player() {
  this->_score = 0;
  this->_maxwidth = 5;
  this->_image = new char[this->_maxwidth];
  strcpy(this->_image, "__^__");
  this->_h = (Env::_winh - 20);
  this->_w = (Env::_winw - 30) / 2;
  this->_bullet_index = 0;
  this->_charlie = new Bullet[BULLET_MAX];
}

Player::~Player() {
  delete[] this->_charlie;
  delete this->_image;
}

Player::Player(const Player &src) { *this = src; }
Player &Player::operator=(const Player &src) {
  _h = src._h;
  _w = src._w;
  _velocity = src._velocity;
  _score = src._score;
  _image = src._image;
  _state = src._state;
  return *this;
}

int Player::get_h() const { return this->_h; }

int Player::get_w() const { return this->_w; }

void Player::Fire() {
  if (this->_bullet_index == BULLET_MAX) this->_bullet_index = 0;
  this->_charlie[this->_bullet_index].Fire(this->_h, this->_w + 2);
  ++this->_bullet_index;
}

int Player::get_maxwidth() const { return this->_maxwidth; }

void Player::Action(int n) {
  int i = 0;
  if (n == KEY_DOWN && (Env::_winh > this->_h + 1)) this->_h += 1;
  if (n == KEY_UP && (5 < this->_h - 1)) this->_h -= 1;
  if (n == KEY_LEFT && (-1 < this->_w - 1)) this->_w -= 1;
  if (n == KEY_RIGHT && (Env::_winw > this->_w + 5)) this->_w += 1;
  if (n == ' ') {
    this->Fire();
  }
  while (i < BULLET_MAX) {
    this->_charlie[i].Action();
    ++i;
  }
}

void Player::IncrementScore() { ++this->_score; }

void Player::Print() {
  int i = 0;
  mvprintw(this->_h, this->_w, "%s", this->_image);
  while (i < BULLET_MAX) {
    if (this->_charlie[i].getstate() == true) _charlie[i].Print();
    ++i;
  }
}

void Player::CollisionCheck(E_Cluster &clust) {
  int i = 0;
  while (i < BULLET_MAX) {
    if (this->_charlie[i].getstate() == true)
      clust.BulletCollision(_charlie[i].get_h(), _charlie[i].get_w());
    ++i;
  }
}
