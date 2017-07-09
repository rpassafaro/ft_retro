/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 13:51:25 by jkalia            #+#    #+#             */
/*   Updated: 2017/07/09 15:05:47 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bullet.class.hpp"

Bullet::Bullet() {
  this->_state = false;
  this->_image = new char[1];
  strcpy(this->_image, "#");
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
  if (this->_h <= 0) {
    this->_state = false;
  }
}

Bullet::~Bullet() { delete this->_image; }

bool Bullet::getstate() const { return this->_state; }
