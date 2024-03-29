/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 13:51:25 by jkalia            #+#    #+#             */
/*   Updated: 2017/07/09 19:31:07 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bullet.class.hpp"

Bullet::Bullet() {
  this->_state = false;
  this->_image = new char[1];
  strcpy(this->_image, "#");
}

Bullet::Bullet(const Bullet &src) { *this = src; }
Bullet &Bullet::operator=(const Bullet &src) {
  _h = src._h;
  _w = src._w;
  _velocity = src._velocity;
  _score = src._score;
  _image = src._image;
  _state = src._state;
  return *this;
}

void Bullet::Fire(int _inh, int _inw) {
  if (this->_state == true) return;
  this->_state = true;
  this->_w = _inw;
  this->_h = _inh;
  this->_velocity = .5;
}

void Bullet::Action() {
  if (this->_state == false) return;
  this->_h -= this->_velocity;
  if (this->_h <= 5) {
    this->_state = false;
  }
}

Bullet::~Bullet() { delete this->_image; }
