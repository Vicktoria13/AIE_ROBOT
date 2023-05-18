#include "ArmeSolo.hpp"


/**
 * @brief Constructeur d'une nouvelle arme : a partir des infos initiales du joueur
 * 
 * @param posi_x 
 * @param posi_y 
 * @param angle 
 */
ArmeSolo::ArmeSolo(int posi_x, int posi_y, int angle){
    this->nb_munitions = 10;

    this->pos_x = posi_x;
    this->pos_y = posi_y;
    this->angle = angle;
}


~ArmeSolo::ArmeSolo(){
    std::cout<<"destruction de l'arme"<<std::endl;    
}
