#include "hpp/npc.hpp"
#include "hpp/Character.hpp"

void npc::onDealDamage(Character target, int damage){
    target.onTakeDamage(damage);
}