#pragma once
#ifndef ENTITY_H
#define ENTITY_H

/*I was intended to do a template, later on I will realize this should only
contain value rather than any other data type*/
/*Wrong, double data type can apply here too.
So, T can be int or double*/
template <class T>
class Entity
{
public:
	Entity();
	Entity(T, T, T);
	~Entity();
	
	void addHealth(T);
	void multHeath(T);
	void setHealth(T);
	T getHealth();
	T getDamage();
//	T getShield();

private:
	T Health;
	T Shield;
};

template <class T>
Entity<T>::Entity()
{
	Health = 0;
	Damage = 0;
	Shield = 0;
}

template <class T>
Entity<T>::Entity(T health, T damage, T shield)
{
	Health = health;
	Damage = damage;
	Shield = shield;
}

template <class T>
Entity<T>::~Entity()
{
	Health = 0;
	Damage = 0;
	Shield = 0;
}

//To add or minus armour effect or magic effect on the entity.
template <class T>
void Entity<T>::addHealth(T health_effect)
{
	Heath += health_effect;
}

//to multiple or divide health based on the different effect.
template <class T>
void Entity<T>::multHeath(T health_effect)
{
	Heath *= health_effect;
}

template <class T>
void Entity<T>::setHealth(T health)
{
	Health = health;
}

/*template <class T>
void Entity<T>::setDamage(T damage)
{
	Damage = damage;
}
template <class T>
void Entity<T>::setShield(T shield)
{
	Shield = shield;
}*/


template <class T>
T Entity<T>::getHealth()
{
	return Health;
}

template <class T>
T Entity<T>::getDamage()
{
	return Damage;
}

/*template <class T>
T Entity<T>::getShield()
{
	return Shield;
}*/

#endif