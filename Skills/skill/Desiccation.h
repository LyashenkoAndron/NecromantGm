/**
 * Project Untitled
 */


#ifndef _DESICCATION_H
#define _DESICCATION_H

#include "../Skill.h"


class Desiccation: public Skill {
public: 
    
void AddHealth();
    
void AddInteligence();
    
void Desicate();
private: 
    int ApplicationRad;
};

#endif //_DESICCATION_H