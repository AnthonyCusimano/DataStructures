#ifndef PLAYABLE_CHARACTER_H
#define PLAYABLE_CHARACTER_H

#include "GenericCharacter.h"

class PlayableCharacter : public GenericCharacter {

	friend class CharacterStatRetriever;

public:

	/**
	
	*/
	PlayableCharacter(CHARACTER_NAME_ID_ENUM const _ID);

	/**
	
	*/
	PlayableCharacter();

	void SetCharacteristics(CHARACTER_NAME_ID_ENUM const _ID);

	/**
	
	*/
	~PlayableCharacter();

private:

	//exp points to next level
	unsigned char currentLevelExperience;

	//number of levels stored
	unsigned char storedLevels;

};

#endif