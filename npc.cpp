#include "npc.hpp"
#include "Character.hpp"

void npc::onDealDamage(Character target, int damage){
    target.onTakeDamage(damage);
}